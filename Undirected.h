//
// Created by Andrew on 2022-03-15.
//

#ifndef GRAPH_PROJECT_UNDIRECTED_H
#define GRAPH_PROJECT_UNDIRECTED_H
#include <iostream>
#include "Graph.h"

class Undirected:public Graph {
private:
    vector<Vertex> myVertex;
    vector<Edge> myEdges;
    int size_vertex;
    int size_edge;
    int position_vertex;
    int position_edge;

public:
    Undirected(); // default constructor
    Undirected(int num); // constructor
    Undirected(const Undirected& u);
    virtual bool addVertex(Vertex &v) ; // add a vertex
    virtual bool removeVertex(Vertex &v); // remove a vertex
    virtual bool addEdge(Edge& e) ; // add edge
    virtual bool remove(Edge& e); // remove edge
    virtual bool searchVertex(const Vertex& v) ;// return bool if a Vertexexists in a graph;
    virtual bool searchEdge(const Edge& e); // return bool of an Edge exists in the graph
    int getPosition()const; // get position of a vertex
    virtual void display() const; // display all paths
    int getSize_vertex() const ; // get the size of vertex vector
    int getSize_edge() const; // get the size of edge vectr
    Vertex& getVertex(Vertex v); // get Vertex
    virtual void queried_vertex(Vertex& v); // list all paths from a vertex
    virtual void queried_edge(Edge& e); // check if edge exists in the graph
    virtual void queried_int(int value); // check if value  exists in the grapbh
};


#endif //GRAPH_PROJECT_UNDIRECTED_H
