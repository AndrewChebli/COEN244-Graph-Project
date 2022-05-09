//
// Created by Andrew on 2022-03-15.
//

#include "Undirected.h"
//
// Created by Andrew on 2022-03-13.
//



Undirected::Undirected(){
    myVertex.resize(0) ;
    myEdges.resize(0);
    this->size_vertex =0;
    this->size_edge =0;
}
Undirected::Undirected(int num){
    myVertex.resize(num);
    this->size_vertex = num;
}
Undirected::Undirected(const Undirected& u){
    for(int i=0; i < u.myVertex.size(); i++) {
        myVertex.push_back(u.myVertex[i]);
    }
    for(int i=0; i < u.myEdges.size(); i++){
        myEdges.push_back(u.myEdges[i]);
    }
    size_vertex = u.size_vertex;
    size_edge = u.size_edge;
    position_vertex =u.position_vertex;
    position_edge =u.position_edge;
}
bool Undirected::addVertex(Vertex &v) {
    myVertex.push_back(v);
    this->size_vertex++;
    return true;
}
bool Undirected::removeVertex(Vertex &v){
    if(searchVertex(v)){
        myVertex.erase(myVertex.begin()+position_vertex);

        return true;
    }else{
        return false;
    }
}

int Undirected::getPosition() const {
    return this->position_vertex;
}

bool Undirected::addEdge(Edge& e){
    if(!searchEdge(e)) {
        myEdges.push_back(e);
        this->size_edge++;
        return true;
    }else{
        cout << "edge already exists." << endl;
        return false;
    }
}
bool Undirected::remove(Edge& e){
    if(searchEdge(e)){
        myEdges.erase(myEdges.begin()+position_edge);
    }
    return true;
}
bool Undirected::searchVertex(const Vertex& v){
    for(int i =0; i < myVertex.size();i++){
        if(myVertex[i].getValue() == v.getValue()){
            cout << endl << "Vertex found at index :" << i << endl;
            position_vertex = i;
            return true;
        }
    }
//    cout << "the vertex was not found" << endl; // vertex was not found
    return false;
}
bool Undirected::searchEdge(const Edge& e){
    for(int i =0; i < myEdges.size();i++){
        if(myEdges[i].getV2() == e.getV2() && myEdges[i].getV1() == e.getV1()){
            cout << endl <<"Edge found at index :" << i << endl;
            position_edge = i;
            return true;
        }
    }
//    cout << "the Edge was not found" << endl; // edge was not found
    return false;
}

void Undirected::display() const {
    int i =0;
    int j = i+1;
    int distance=0;
    cout << myEdges[i].getV1();
    for( ;i < myEdges.size();i++){
        cout  << "-->" << myEdges[i].getV2() ;
        distance += myEdges[i].getWeight();

        if(myEdges.size() >i+1) {
            if (myEdges[i + 1].getV1() == myEdges[i].getV2()) {
                continue;
            } else {
                cout << " ||| Total Distance: " << distance << " km" << endl;
                distance =0;
                cout << myEdges[i + 1].getV1();

            }
        }else{
            cout << " ||| Total Distance: " << distance << " km" << endl;
            break;
        }
    }
}


int Undirected::getSize_edge() const {
    return size_edge ;
}
int Undirected::getSize_vertex() const {
    return size_vertex;
}

Vertex& Undirected::getVertex(Vertex v){
    this->searchVertex(v);
    return myVertex[position_vertex];

}
void Undirected::queried_edge(Edge &e) {
    if(searchEdge(e)){
        cout << "the edge exists in this graph" <<endl;
    }else{
        cout << "the edge does not exist in this graph" << endl;
    }
}
void Undirected::queried_int(int value) {
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
//void Undirected::queried_vertex(Vertex &v) {
//    if (searchVertex(v)) {
//        int i = 0;
//        for (; i < myEdges.size(); i++) {
//            if (myEdges[i].getV1() == v.getValue()) {
//                cout << myEdges[i].getV1() << "-->" << myEdges[i].getV2();
//                for(int j= i+1; j < myEdges.size(); j++){
//                    if(myEdges[j].getV1() == myEdges[j-1].getV2()){
//                        cout << "-->" <<myEdges[j].getV2();
//                    }else if(myEdges[j].getV1() == v.getValue()){
//                        i = j-1;
//                        cout << ";";
//                        break;
//                    }else{
//                        cout <<";";
//                        continue;
//                    }
//                }
//            }
//        }
//    }
//}
void Undirected::queried_vertex(Vertex &v) {
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



