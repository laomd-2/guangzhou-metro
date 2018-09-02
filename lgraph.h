#ifndef L_GRAPH_H
#define L_GRAPH_H
#include <stdexcept>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <limits>
#include "Graph.h"

template<typename VertexType, typename WeightType>
class UndirectedLGraph : public Graph<VertexType, WeightType>
{
    using Graph<VertexType, WeightType>::INF;
    struct Neighbor {
    	VertexType vertex;
    	WeightType weight;
        Neighbor(const VertexType& v, const WeightType& w) : vertex(v), weight(w) { }

        bool operator <(const Neighbor& other) const {
            return vertex < other.vertex;
        }
	};
	
	struct _Edge {
		VertexType src;
		VertexType des;
		WeightType weight;
		_Edge(const VertexType& s, const VertexType& d, const WeightType& w)
			: src(s), des(d), weight(w) {
				
		}
	};
	
    std::map<VertexType, std::set<Neighbor> > neighborsList;
     
public:
	typedef _Edge Edge;
	
    virtual int numVertexes() const;
    virtual WeightType getWeight(const VertexType& src, const VertexType& des);
    virtual void insertEdge(const VertexType&, const VertexType&, WeightType);

	template<typename Visit>
    void BFS(const VertexType& begin, Visit);
    template<typename Visit>
    void DFS(const VertexType& begin, Visit);
    
    template<typename Rule, typename T>
    void findShortestPath(const VertexType&,
                        const VertexType&,
                        Rule,
                        std::map<VertexType, VertexType>&,
                        std::map<VertexType, T>&
						);
private:
    template<typename Visit>
    void DFS(const VertexType& begin, Visit, std::map<VertexType, bool>&);
    
    void checkVertex(const VertexType&) const;
};

template<typename VertexType, typename WeightType>
void UndirectedLGraph<VertexType, WeightType>::checkVertex(const VertexType& v) const {
    if(neighborsList.find(v) == neighborsList.end()) {
        throw std::logic_error("The vertex is not in the graph");
    }
}

template<typename VertexType, typename WeightType>
int UndirectedLGraph<VertexType, WeightType>::numVertexes() const {
    return neighborsList.size();
}
template<typename VertexType, typename WeightType>
WeightType UndirectedLGraph<VertexType, WeightType>::getWeight(const VertexType& src,
                                                     const VertexType& des) {
    checkVertex(src);
    checkVertex(des);
    for(const auto& neighbor : neighborsList[src]) {
        if(neighbor.vertex == des) {
            return neighbor.weight;
        }
    }
    return INF; 
}

template<typename VertexType, typename WeightType>
inline void UndirectedLGraph<VertexType, WeightType>::insertEdge(const VertexType& src,
                                                        const VertexType& des,
                                                        WeightType w) {
    if (!(w == INF))
    {
    	neighborsList[src].insert(Neighbor(des, w));
        neighborsList[des].insert(Neighbor(src, w));
    }

}

template<typename VertexType, typename WeightType>
template<typename Rule, typename T>
void UndirectedLGraph<VertexType, WeightType>::findShortestPath(const VertexType& src,
                                                            const VertexType& des,
                                                            Rule rule,
                                                            std::map<VertexType, VertexType>& precursor,
                                                            std::map<VertexType, T>& distances) {
    checkVertex(src);
    checkVertex(des);
    std::map<VertexType, bool> isOK;
    
    auto pred = [&](const VertexType& a, const VertexType& b) {
        return distances[a] > distances[b];
    };
    std::priority_queue<VertexType, std::vector<VertexType>, decltype(pred)> bests(pred);

    for(const auto& v : neighborsList) {
        precursor[v.first] = v.first;
        distances[v.first] = std::numeric_limits<T>::max();
    }
    distances[src] = T();

    VertexType best = src;

    while(!(best == des)) {
        isOK[best] = true;
        for(const auto& neighbor: neighborsList[best]) {
            VertexType n = neighbor.vertex;
            if (!isOK[n])
            {
                T new_weight = distances[best] + rule(best, n);
                if (new_weight < distances[n])
                {
                    precursor[n] = best;
                    distances[n] = new_weight;
                    bests.push(n);
                }
            }
        }
        if(bests.empty())	break;
        best = bests.top();
        bests.pop();
    }
}

template<typename VertexType, typename WeightType>
template<typename Visit>
void UndirectedLGraph<VertexType, WeightType>::BFS(const VertexType& begin,
                                        Visit doSomething) {

    checkVertex(begin);
    std::map<VertexType, bool> visited;
    std::queue<VertexType> help;
    help.push(begin);
    while(!help.empty()) {
        VertexType v = help.front();
        help.pop();
        if (!is_visited(v))
        {
            doSomething(v);
            visited[v] = true;
        }
        for (const VertexType& n : neighborsList[v]) {
            if (!is_visited(n))
            {
                help.push(n);
            }
        }
    }
}

template<typename VertexType, typename WeightType>
template<typename Visit>
void UndirectedLGraph<VertexType, WeightType>::DFS(const VertexType& begin,
                                         Visit doSomething, std::map<VertexType, bool>& visited) {

    doSomething(begin);
    visited[begin] = true;
    for(const VertexType& v : neighborsList[begin]) {
        if (!visited(v))
        {
            DFS(v, doSomething, visited);
        }
    }
}

template<typename VertexType, typename WeightType>
template<typename Visit>
inline void UndirectedLGraph<VertexType, WeightType>::DFS(const VertexType& begin,
                                                Visit doSomething) {
    checkVertex(begin);
    std::map<VertexType, bool> visited;
    DFS(begin, doSomething, visited);
}

#endif // L_GRAPH_H
