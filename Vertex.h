//
// Created by Andrew on 2022-03-01.
//

#ifndef GRAPH_PROJECT_VERTEX_H
#define GRAPH_PROJECT_VERTEX_H
class Edge;
#include <vector>
#include <iostream>
using namespace std;

class Vertex {
private:
    string value ;
    int val;
public:
    Vertex(); // default constructor to create an empty graph
    Vertex(string value, int val); // constructor
    Vertex(const Vertex& v); // copy constructor
    ~Vertex(); // destructorV
    string getValue() const; // get the value of the vertex
    void setValue( string s); // set the value of the vertex
    int getVal()const;

};


#endif //GRAPH_PROJECT_VERTEX_H
