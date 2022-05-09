#include <iostream>
//#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "Directed.h"
#include "Undirected.h"
using namespace std;

int main(){

    Graph *p = nullptr;
    Graph *pu = nullptr;
    Directed *d = new Directed();
    Undirected *u = new Undirected();
    p = d;

    pu = u;
    Vertex v1("Montreal", 1); // vertex 1
    Vertex v2("Toronto", 2);// vertex 2
    Vertex v3("Vancouver", 3);// vertex 3
    Vertex v4("Ottawa", 4);// vertex 4
    Vertex v5("Kingston", 5);// vertex 5
    Vertex v6("Calgary", 6);// vertex 6


    p->addVertex(v1); // add the vertex to the graph p
    p->addVertex(v2); // add the vertex to the graph p
    p->addVertex(v3); // add the vertex to the graph p
    p->addVertex(v4); // add the vertex to the graph p
    p->addVertex(v5); // add the vertex to the graph p
    p->addVertex(v6); // add the vertex to the graph  p


    Edge e1(d->getVertex(v1),d->getVertex(v2),541); // initialize edge
    Edge e2(d->getVertex(v2),d->getVertex(v1),541); // initialize edge
    Edge e3(d->getVertex(v6),d->getVertex(v4),3327); // initialize edge
    Edge e4(d->getVertex(v1),d->getVertex(v4),198); // initialize edge
    Edge e5(d->getVertex(v4),d->getVertex(v3),4713); // initialize edge
    Edge e11(d->getVertex(v3), d->getVertex(v5),4589); // initialize edge

    Edge e6(d->getVertex(v1),d->getVertex(v2),541); // initialize edge
    Edge e7(d->getVertex(v2),d->getVertex(v1),541); // initialize edge
    Edge e8(d->getVertex(v6),d->getVertex(v4),3327); // initialize edge
    Edge e9(d->getVertex(v4),d->getVertex(v2),450); // initialize edge
    Edge e10(d->getVertex(v2),d->getVertex(v4),450); // initialize edge


    p->addEdge(e1); // add edge to the graph p
    p->addEdge(e2); // add edge to the graph p
    p->addEdge(e3); // add edge to the graph p
    p->addEdge(e4); // add edge to the graph p
    p->addEdge(e5); // add edge to the graph p
    p->addEdge(e11); // add edge to the graph p

    pu->addVertex(v1); // add vertex to the graph pu
    pu->addVertex(v2); // add vertex to the graph pu
    pu->addVertex(v3); // add vertex to the graph pu
    pu->addVertex(v4); // add vertex to the graph pu
    pu->addVertex(v5); // add vertex to the graph pu
    pu->addVertex(v6); // add vertex to the graph pu

    pu->addEdge(e6);// add edge to the graph pu
    pu->addEdge(e7);// add edge to the graph pu
    pu->addEdge(e8);// add edge to the graph pu
    pu->addEdge(e9);// add edge to the graph pu
    pu->addEdge(e10);// add edge to the graph pu

    cout << "------------------------------------------------" << endl;
    cout << "before removing v6 from directed graph:" << endl;
    p->display(); // display the graph p
    cout << "\n------------------------------------------------" << endl;
    cout <<endl <<"after removing v6 from directed graph:" << endl;
    p->removeVertex(v6); // remove vertex v6 from graph p
//    cout << "------------------------------------------------" << endl;

    cout << "directed graph is: " << endl;
    p->display(); // display graph p after removing the vertex
    cout << "\n------------------------------------------------" << endl;
    cout << endl <<"undirected graph is: " << endl;
    pu->display(); // display the undirected graph pu
    cout << "\n------------------------------------------------" << endl;
    cout << endl;
    cout << "----------queried vertex checking vertex v1-------" << endl;
    p->queried_vertex(v1); // queried vertex v1 for graph p
    cout << "-----------queried edge checking edge e1----------"<< endl;
    p->queried_edge(e1); // queried edge e1 for graph p
    cout << "------------queried int checking value 4--------- "<< endl;
    p->queried_int(4); // queried int 4 for graph p
    cout << "------------------------------------------------" << endl;


    cout <<"Trying copy constructor for a directed graph" << endl;
    Directed *a(d); // using copy constructor to create a
    a->display(); // displaying a
    cout << endl;
    cout << "----------queried vertex checking vertex v2-------" << endl;
    pu->queried_vertex(v2); // using queried vertex v2 for graph pu

    return 0;
}