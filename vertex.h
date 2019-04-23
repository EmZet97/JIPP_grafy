#ifndef VERTEX_H
#define VERTEX_H
#include <vector>

using namespace std;
class Vertex
{

public:
    vector<int> edges;
    Vertex();
    void addElement(int);
};

#endif // VERTEX_H
