#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextToSpeech>
#include "guangzhoumetro.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void shanshuoPrint(const QStringList&);
    void initialize();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void showText(QString);
private slots:
    void on_inquireButton_clicked();
    void showStations();
private:
    Ui::MainWindow *ui;
    QTextToSpeech* speech;
    GuangzhouMetro metro;
};

#endif // MAINWINDOW_H
