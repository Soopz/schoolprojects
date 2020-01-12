#ifdef VERTEX_H
#define VERTEX_H
#include<iostream>
#include<vector>
using namespace std;
class vertex{
public:
	vertex( int vn , float vertex1 , float weight1){
		vertex_number = vn;
		v.pushback(vertex1);
		v.pushback(weight1);
	}
	vertex( int vn , float vertex1 , float weight1, float vertex2, float weight2){
		vertex_number = vn;
		v.pushback(vertex1);
		v.pushback(weight1);
		v.pushback(vertex2);
		v.pushback(weight2);
	}
	vertex( int vn , float vertex1 , float weight1, float vertex2, float weight2, float vertex3, float weight3){
		vertex_number = vn;
		v.pushback(vertex1);
		v.pushback(weight1);
		v.pushback(vertex2);
		v.pushback(weight2);
		v.pushback(vertex3);
		v.pushback(weight3);
	}
	void insert(const float & x){
		v.pushback(x)
	}
	float adjacent(float vn){
		for(auto it = v.begin() ; it!= v.end() ; it++){
			if(*it ==  vn;)
				return ++*it;
		}
		return 0;
	}
private:
	std::vector<float> v;
	int vertex_number;
};
#endif