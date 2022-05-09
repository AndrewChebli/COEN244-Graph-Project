//
// Created by Andrew on 2022-03-01.
//

#ifndef GRAPH_PROJECT_GRAPH_H
#define GRAPH_PROJECT_GRAPH_H
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
using namespace std ;



class Graph {
public:
    Graph(); // creates an empty graph
    virtual ~Graph(); // destructor
    virtual bool addVertex(Vertex &v) =0; // add a vertex
    virtual bool addEdge(Edge& e) = 0; // add edge
    virtual bool remove(Edge& e)=0; // remove edge
    virtual bool searchVertex(const Vertex& v) = 0;// check if an Vertex exists in a graph
    virtual bool searchEdge(const Edge& e) =0;// check if an Edge exists in a graph
    virtual void display() const = 0; // display the connections
    virtual bool removeVertex(Vertex &v) = 0; // remove a vertex
    virtual void queried_vertex(Vertex& v)=0;// display all the paths that originates from vertex v
    virtual void queried_edge(Edge& e)=0;// check if the graph contains the edge e
    virtual void queried_int(int value)=0;// check if the graph contains a vertex with this value
};


#endif //GRAPH_PROJECT_GRAPH_H
