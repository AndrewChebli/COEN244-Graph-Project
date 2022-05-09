//
// Created by Andrew on 2022-03-01.
//

#include "Vertex.h"
Vertex::Vertex(){
//    vector<Vertex> myVector[0];
//    size =0;
    this->value ="";
    this->val =0;

}

Vertex::Vertex(string value, int val) {
    this->value = value;
    this->val=val;
}

Vertex::Vertex(const Vertex &v) {
    this->value = v.getValue();
    this->val = v.val;
}
Vertex::~Vertex() {

}
string Vertex::getValue() const{
    return value ;
}

void Vertex::setValue(string s) {
    value=s ;
}
int Vertex::getVal()const{
    return val;
}
