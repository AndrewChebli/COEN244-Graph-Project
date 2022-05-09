//
// Created by Andrew on 2022-03-01.
//

#ifndef GRAPH_PROJECT_EDGE_H
#define GRAPH_PROJECT_EDGE_H
#include "Vertex.h"
using namespace std;

class Edge{
private:
    Vertex *v1;
    Vertex *v2;
    int distance; // weight of the edges
public:
    Edge();
    ~Edge();
    Edge(Vertex &v,Vertex &c, int distance); //v to v1 and c to v2
    Edge(const Edge& e); // copy constructor
    void setV1(Vertex &v);
    void setV2(Vertex &c);
    void setWeight(int w);
    int getWeight() const;
    string getV1() const;
    string getV2() const;
    Edge getEdge() const;
};


#endif //GRAPH_PROJECT_EDGE_H
