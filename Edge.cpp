//
// Created by Andrew on 2022-03-01.
//

#include "Edge.h"

Edge::Edge(){
    this->v1 = nullptr ;
    this->v2 = nullptr ;
    this->distance = 0;
}
Edge::Edge(const Edge& e){
    v1 = new Vertex();
    v2 = new Vertex();
    this->v1 = e.v1;
    this->v2 = e.v2;
    this->distance = e.distance;
}

Edge::Edge(Vertex &v, Vertex &c, int distance) {

    this->v1 = &v;
    this->v2 =&c;
    this->distance = distance;
}
Edge::~Edge()
{

}

void Edge::setV1(Vertex &v){
    this->v1 = &v;
}
string Edge::getV1() const{
    return v1->getValue();
}

void Edge::setV2(Vertex &c){
    this -> v2 = &c ;
}
string Edge::getV2() const{
    return v2->getValue();
}
void Edge::setWeight(int w){
    distance =w;
}
int Edge::getWeight() const {
    return distance ;
}

