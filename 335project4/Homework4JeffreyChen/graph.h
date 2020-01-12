#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
class Graph{
public:
	insert(const vertex & vtx){
		v.push_back(vtx);
	}
private:
	std::vector<vertices> v;
	int size = 0;
}
#endif