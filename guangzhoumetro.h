#ifndef GUANGZHOUMETRO_H
#define GUANGZHOUMETRO_H
#include <QVector>
#include <QMap>
#include <QSet>
#include <QString>
#include "lgraph.h"

typedef QString Station;

struct WeightType
{
    double distance;
    double time;
    int interchange;
    WeightType() {
        distance = time = interchange = 0;
    }
};

bool operator==(const WeightType& a, const WeightType& b);

typedef UndirectedLGraph<QString, WeightType>::Edge Edge;

class GuangzhouMetro
{
public:
    void readLine(const QString&);
    std::pair<QStringList, double> findShortestPath(const QString&, const QString&, int);
    int numStations() const;
    QSet<QString> stationsInLine(const QString&);
private:
    QMap<QString, QStringList > station_lines;
    QMap<QString, QSet<QString> > lines_stations;
    UndirectedLGraph<Station, WeightType> guangzhou_metro;
};

#endif // GUANGZHOUMETRO_H
