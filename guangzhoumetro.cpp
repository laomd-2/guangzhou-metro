#include <QFile>
#include <QTextStream>
#include <map>
#include "guangzhoumetro.h"

bool operator==(const WeightType& a, const WeightType& b) {
    return a.distance == b.distance
            && a.time == b.time
            && a.interchange == b.interchange;
}

void GuangzhouMetro::readLine(const QString &line) {
    QFile file("input/edges/" + line + ".txt");
    if(file.open(QIODevice::ReadOnly)) {
        QString station_a, station_b, aline;
        WeightType weight;

        QTextStream fin(&file);
        while (!(aline = fin.readLine()).isEmpty()) {
            QStringList tmp = aline.split(QRegExp("\\s"));
            station_a = tmp[0];
            station_b = tmp[1];
            weight.time = tmp[2].toDouble();
            weight.distance = tmp[3].toDouble();
            weight.interchange = 0;
            guangzhou_metro.insertEdge(station_a + "-" + line, station_b + "-" + line, weight);
            station_lines[station_a].push_back(line);
            station_lines[station_b].push_back(line);
            lines_stations[line].insert(station_a);
            lines_stations[line].insert(station_b);
        }
    }

    for(const auto& station : station_lines.keys()) {
        const auto& lines = station_lines[station];
        int s = lines.size();
        WeightType weight;
        weight.interchange = 1;
        for(int i = 0; i < s - 1; i++) {
            for(int j = i + 1; j < s; j++) {
                guangzhou_metro.insertEdge(station + "-" + lines[i], station + "-" + lines[j], weight);
            }
        }
    }
}

int GuangzhouMetro::numStations() const {
    return this->guangzhou_metro.numVertexes();
}

QSet<QString> GuangzhouMetro::stationsInLine(const QString &line) {
    return lines_stations[line];
}

void getPath(std::map<Station, Station>& precursor, const Station& des, QStringList& path) {
    if(!(precursor[des] == des)) {
        getPath(precursor, precursor.at(des), path);
    }
    path.push_back(des);
}
QStringList trim(QStringList path, double& dis) {
    if(path.size() > 2) {
        QString a = path.takeAt(0);
        QString sa = a.split('-')[0], sb = path.front().split('-')[0];
        if(sa != sb) {
            path.push_front(a);
        }
        else  {
            --dis;
        }
    }
    if(path.size() > 2) {
        QString a = path.takeAt(path.size() - 1);
        QString sa = a.split('-')[0], sb = path.back().split('-')[0];
        if(sa != sb) {
            path.push_back(a);
        }
        else {
            --dis;
        }
    }
    QStringList res_path;
    QString last;
    QMap<QString, QString> line_color;
    line_color["1号线"] = "yellow";
    line_color["2号线"] = line_color["8号线"] = line_color["APM线"] = "blue";
    line_color["3号线"] = line_color["3号线(北延段)"] = "orange";
    line_color["4号线"] = line_color["7号线"] = line_color["广佛线"] = "green";
    line_color["5号线"] = "red";
    line_color["6号线"] = "purple";

    for(const auto& p : path) {
        QStringList tmp = p.split('-');
        QString station = tmp[0], line = tmp[1];

        if(station == last) {
            res_path.back() += ("(转"+line+")");
        }
        else {
            res_path.push_back("<font color=" + line_color[line] + ">" + station + "</font>");
        }
        last = station;
    }
    return res_path;
}

std::pair<QStringList, double> GuangzhouMetro::findShortestPath(const Station& src, const Station& des, int index) {
    std::map<Station, Station> precursor;
    std::map<Station, double> distances;

    auto shortestPath_rule = [&](const Station& a, const Station& b) {
        switch (index) {
        case 0:
            return guangzhou_metro.getWeight(a, b).distance;
            break;
        case 1:
            return guangzhou_metro.getWeight(a, b).time;
            break;
        case 2:
            return double(guangzhou_metro.getWeight(a, b).interchange);
            break;
        default:
            break;
        }
        return 0.0;
    };

    if(station_lines.find(src) == station_lines.end() || station_lines.find(des) == station_lines.end())
        throw std::logic_error("the station is not in guangzhou metro");

    auto linesa = station_lines[src];
    auto linesb = station_lines[des];
    QString a = src + "-" + linesa.front(), b = des + "-" + linesb.front();

    guangzhou_metro.findShortestPath(a, b, shortestPath_rule, precursor, distances);
    QStringList path;
    getPath(precursor, b, path);
    double dis = distances[b];
    QStringList p = trim(path, dis);
    if(index != 2)  dis = distances[b];
    return std::make_pair(p, dis);
}
