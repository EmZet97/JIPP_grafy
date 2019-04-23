#include "graph.h"
#include <QString>
#include "mainwindow.h"
Graph::Graph()
{
}
void Graph::addEdge(int f, int t){
vertices[f].addElement(t);
}
void Graph::addVertex(){
   vertices.push_back(Vertex());
}
void Graph::deleteEdge(int f, int t){
    for(int i = 0 ; i<vertices[f].edges.size(); i++){
        if(vertices[f].edges[i] == t){
            vertices[f].edges.erase(vertices[f].edges.begin() + i);
        }
}
}
void Graph::deleteVertex(int w){
   vertices.erase(vertices.begin() + w);
   for(int i = 0 ; i<vertices.size(); i++){
       for(int j = 0 ; j<vertices[i].edges.size(); j++){
           if(vertices[i].edges[j] == w){
               vertices[i].edges.erase(vertices[i].edges.begin() + j);
           }
       }
   }
   //dodac usuwanie krawedzi ktore przylegaly do wierzcholka
}
QString Graph::showGraph(){
    QString t ;//"elo\n1
    for(int i = 0 ; i<vertices.size(); i++){
        for(int j = 0 ; j<vertices[i].edges.size(); j++){
            t+= QString::number( vertices[i].edges[j]);

        }
        t+="\n";
    }
    return t;
}
QString Graph::getXML(){
    QString t = "<Graph>\n" ;
    for(int i = 0 ; i<vertices.size(); i++){
        t+="\t<Vertex number='" +QString::number( i )+ "'>\n";
        for(int j = 0 ; j<vertices[i].edges.size(); j++){
            t+="\t\t<Edge>" + QString::number( vertices[i].edges[j]) + "</Edge>\n";

        }
        t+="\t</Vertex>\n";
    }
    t+="</Graph>";
    return t;
}
