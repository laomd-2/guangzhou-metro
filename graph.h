#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
using std::vector;

template<typename VertexType, typename WeightType>
class Graph
{
public:
    virtual int numVertexes() const = 0;
    virtual WeightType getWeight(const VertexType& src, const VertexType& des) = 0;
    virtual void setUnconnectedWeight(WeightType w) {INF = w;}
    virtual void insertEdge(const VertexType&, const VertexType&, WeightType) = 0;
protected:
    WeightType INF;
};

#endif // GRAPH_H
