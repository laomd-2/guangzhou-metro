#include <QButtonGroup>
#include <QCompleter>
#include <QDir>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGridLayout>
#include <QSet>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/images/logo.png"));
    this->setWindowTitle("广州地铁");
    this->setFixedWidth(this->sizeHint().width());
    speech = new QTextToSpeech(this);
    speech->say("欢迎来到广州地铁");

    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize() {
    QSet<QString> allStations;
    QGridLayout *layout = new QGridLayout;
    int row = 0, col = 0;
    QDir dir("input/edges");
    for(const auto& file: dir.entryInfoList()) {
        if(file.isFile()) {
            QString line = file.baseName();
            metro.readLine(line);
            QPushButton *button = new QPushButton(line, ui->tab_2);
            connect(button, SIGNAL(clicked()), this, SLOT(showStations()));
            layout->addWidget(button, row, col);
            col = (col + 1) % 3;
            if(!col)    row++;

            for(const auto& s : metro.stationsInLine(line)) allStations.insert(s);
        }
    }

    QTextEdit *edit = new QTextEdit(ui->tab_2);
    edit->setReadOnly(true);
    connect(this, SIGNAL(showText(QString)), edit, SLOT(setText(QString)));
    QVBoxLayout* main_layout = new QVBoxLayout;
    main_layout->addLayout(layout);
    main_layout->addWidget(edit);
    ui->tab_2->setLayout(main_layout);

    QCompleter *completer = new QCompleter(allStations.toList());
    ui->src_lineEdit->setPlaceholderText("请输入起始站");
    ui->src_lineEdit->setCompleter(completer);
    ui->des_lineEdit->setPlaceholderText("请输入终点站");
    ui->des_lineEdit->setCompleter(completer);
}

void MainWindow::shanshuoPrint(const QStringList& v) {
    for(const auto& s : v) {
        ui->textEdit->append(s);
    }
}

void MainWindow::on_inquireButton_clicked()
{
    try {
        QString src = ui->src_lineEdit->text();
        QString des = ui->des_lineEdit->text();

        auto res = this->metro.findShortestPath(src, des, ui->rule_comboBox->currentIndex());

        std::map<QString, QString> danwei;
        danwei["距离"] = "公里";
        danwei["时间"] = "分钟";
        danwei["换乘"] = "次";

        auto path = res.first;
        double dis = res.second;
        QString tmp = ui->rule_comboBox->currentText().left(2);
        ui->textEdit->clear();
        ui->textEdit->append(tmp + ": " + QString::number(dis) + danwei[tmp]);
        ui->textEdit->append("");
        this->shanshuoPrint(path);
    }
    catch(std::exception&) {

    }
}

void MainWindow::showStations() {
    QString line = ((QPushButton*)sender())->text();
    auto stations = metro.stationsInLine(line);
    QString res;
    for(auto& s : stations) {
        res.append(s + "\n");
    }
    emit showText(res);
}
