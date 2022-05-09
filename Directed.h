//
// Created by Andrew on 2022-03-13.
//

#ifndef GRAPH_PROJECT_DIRECTED_H
#define GRAPH_PROJECT_DIRECTED_H
#include "Graph.h"


class Directed : public Graph {
private:
    vector<Vertex> myVertex;
    vector<Edge> myEdges;
    int size_vertex;
    int size_edge;
    int position_vertex;
    int position_edge;

public:
    Directed(); // default constructor
    Directed(int num); // constructor
    Directed(const Directed &d);
    virtual bool addVertex(Vertex &v) ; // add a vertex
    virtual bool removeVertex(Vertex &v); // remove a vertex
    virtual bool addEdge(Edge& e) ; // add edge
    virtual bool remove(Edge& e); // remove edge
    virtual bool searchVertex(const Vertex& v) ;// return bool if an Edge exists in a graph;
    virtual bool searchEdge(const Edge& e); // check if edge is in the vector  and sets the position of position_vertex
    int getPosition()const; // get position of vertex
    virtual void display() const; // display the paths
    int getSize_vertex() const; // get the size of vertex vector
    int getSize_edge() const; // get the size of the edge vector
    Vertex& getVertex(Vertex v); // get Vertex
    virtual void queried_vertex(Vertex& v); // list all paths going from a vertex
    virtual void queried_edge(Edge& e); // checks if edge exists in the graph
    virtual void queried_int(int value); // check if value exists in the graph



};


#endif //GRAPH_PROJECT_DIRECTED_H
