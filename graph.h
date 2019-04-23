#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "vertex.h"
#include "mainwindow.h"
#include <QMainWindow>

using namespace std;
class Graph
{
vector<Vertex> vertices;

public:
    Graph();
    void paintEvent();
    void addEdge(int,int);
    void addVertex();
    void deleteEdge(int, int);
    void deleteVertex(int);
    QString showGraph();
    QString getXML();
};

#endif // GRAPH_H
