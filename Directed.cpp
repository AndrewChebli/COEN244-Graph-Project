//
// Created by Andrew on 2022-03-13.
//

#include "Directed.h"

Directed::Directed(){
    myVertex.resize(0) ;
    myEdges.resize(0);
    this->size_vertex =0;
    this->size_edge =0;
}
Directed::Directed(int num){
    myVertex.resize(num);
    this->size_vertex = num;
}
Directed::Directed(const Directed &d){
    for(int i=0; i < d.myVertex.size(); i++) {
        myVertex.push_back(d.myVertex[i]);
    }
    for(int i=0; i < d.myEdges.size(); i++){
        myEdges.push_back(d.myEdges[i]);
    }
    size_vertex = d.size_vertex;
    size_edge = d.size_edge;
    position_vertex =d.position_vertex;
    position_edge =d.position_edge;

}
 bool Directed::addVertex(Vertex &v) {
    myVertex.push_back(v);
    this->size_vertex++;
    return true;
}
 bool Directed::removeVertex(Vertex &v){
     if(searchVertex(v)){
         myVertex.erase(myVertex.begin()+position_vertex);
         for(int i =0; i < myEdges.size(); i++){
             if(myEdges[i].getV1() == v.getValue() || myEdges[i].getV2() == v.getValue()){
                 remove(myEdges[i]);
                 i--;
             }
         }

         return true;
     }else{
         return false;
     }
}

int Directed::getPosition() const {
    return this->position_vertex;
}

 bool Directed::addEdge(Edge& e){
    try {
        if (myEdges.size() != 0) {
            if (myEdges[myEdges.size() - 1].getV1() == e.getV2() && myEdges[myEdges.size() - 1].getV2() == e.getV1()) {
                throw "EXCEPTION: the edge you entered is for an undirected graph ";
            } else {
                myEdges.push_back(e);
                this->size_edge++;
                return true;
            }
        } else {
            myEdges.push_back(e);
            return true;
        }
    }
    catch(const char * msg){
        cout << msg << endl;
        cout <<"edge to be changed :" << e.getV1() << "-" << e.getV2() << endl;
    }
}
 bool Directed::remove(Edge& e){
    if(searchEdge(e)){
        myEdges.erase(myEdges.begin()+position_edge);
    }
    return true;
}
 bool Directed::searchVertex(const Vertex& v){
    for(int i =0; i < myVertex.size();i++){
        if(myVertex[i].getValue() == v.getValue()){
//            cout << endl << "Vertex found at index :" << i << endl; // to know at what index it is available
            position_vertex = i;
            return true;
        }
    }
    cout << "the vertex was not found" << endl;
    return false;
}
 bool Directed::searchEdge(const Edge& e){
     for(int i =0; i < myEdges.size();i++){
         if(myEdges[i].getV2() == e.getV2() && myEdges[i].getV1() == e.getV1()){
             position_edge = i;
             return true;
         }
     }
//     cout << "the Edge was not found" << endl; // the edge was not found
     return false;
}

void Directed::display() const {
    int i =0;
    int j = i+1;
    int distance=0;
    cout << myEdges[i].getV1();
    for( ;i < myEdges.size();i++){
        cout  << "-->" << myEdges[i].getV2() ;
        distance +=myEdges[i].getWeight();

        if(myEdges.size() >i+1) {
            if (myEdges[i + 1].getV1() == myEdges[i].getV2()) {
                continue;
            } else {
                cout << " ||| Total Distance: " << distance << " km" <<endl;
                distance =0;
                cout << myEdges[i + 1].getV1();

            }
        }else{
            cout << " ||| Total Distance: " << distance <<" km" << endl;
            break;
        }
    }
}


int Directed::getSize_edge() const {
    return size_edge ;
}
int Directed::getSize_vertex() const {
    return size_vertex;
}

Vertex& Directed::getVertex(Vertex v){
    this->searchVertex(v);
        return myVertex[position_vertex];

}

void Directed::queried_edge(Edge &e) {
    if(searchEdge(e)){
        cout << "the edge exists in this graph" <<endl;
    }else{
        cout << "the edge does not exist in this graph" << endl;
    }
}
void Directed::queried_int(int value) {
    bool found = false;
    for(int i =0; i < myVertex.size(); i++){
        if(myVertex[i].getVal() == value){
            found = true;

            break;
        }else{
            continue;
        }
    }
    if(found){
        cout <<  endl << "the graph contains the vertex with value " << value << endl;
    }else{
        cout << endl << "the graph does not contain the vertex with value " << value << endl;
    }
}
void Directed::queried_vertex(Vertex &v) {
    if (searchVertex(v)) {
        int i = 0;
        int distance =0;
        for (; i < myEdges.size(); i++) {
            if (myEdges[i].getV1() == v.getValue()) {
                distance +=myEdges[i].getWeight();
                cout << myEdges[i].getV1() << "-->" << myEdges[i].getV2();
                for(int j= i+1; j < myEdges.size(); j++){
                    if(myEdges[j].getV1() == myEdges[j-1].getV2()){
                        cout << "-->" <<myEdges[j].getV2();
                        distance += myEdges[j].getWeight();
                    }
                    else{
                        cout << " ||| Total Distance: " << distance << " km" <<  endl;
                        distance =0;

                        break;
                    }
                }
            }
        }
        cout << " ||| Total Distance: " << distance << " km" <<  endl;

    }
    cout << endl;
}



