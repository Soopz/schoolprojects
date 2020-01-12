//Jeffrey Chen
//CSCI-335
//PROJECT 4
// Instructor: Ioannis Stamos 
#include<iostream>
#include"binary_heap.h"
#include<fstream>
#include<string>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;
void findPath( string graph_filename,string starting_vertex){
ifstream readFile;
readFile.open(graph_filename);
int graph_size;
int start_vertex = 0;
istringstream convert;
convert.str(starting_vertex);
convert>>start_vertex;
string vertex_read;
readFile>>graph_size;

int vertex;
float temp;
vector<vector<pair<int, float> > >list; //adjacency list 

while(getline(readFile,vertex_read)){ //reading till end of file
	vector<pair<int,float> > temp_vertex;
	istringstream cur_line; //string stream for current line
	cur_line.str(vertex_read);
	cur_line>>vertex;
	while(cur_line>>vertex>>temp){ //using string stream to read in vertex number and weight and pushing onto adjacency list
		pair<int,float> vertex_pair(vertex,temp);
		temp_vertex.push_back(vertex_pair);
	}
	list.push_back(temp_vertex); //pushing full vertex onto list    
}
readFile.close();

BinaryHeap< pair<float, int> > bh; //creating binary heap
vector<float> dist(graph_size,10000); //setting weight of all vertexes to 10000
pair<float,int> bh_pair(0,start_vertex);
bh.insert(bh_pair); //inserting start vertex onto binary heap
dist[start_vertex-1] = 0; 

while(!bh.isEmpty()){ //looping till the binary heap is empty
	int u = get<1>(bh.findMin()); //dequeueing smallest weight path from binary heap
	bh.deleteMin();
	
    	for (int i = 0; i < list[u].size(); i++){ //looping through adjacency list for current vertex
    	
        int v = get<0>(list[u][i]);
        float weight = get<1>(list[u][i]);
        if (dist[v-1] > dist[u-1] + weight) //updating weight of vertex if previous vertex plus path weight is less than current weight
            { 
                dist[v-1] = static_cast<float>(dist[u-1] + weight); 
                bh.insert(make_pair(dist[v-1], v)); //queueing new updated vertex into binary heap
            } 
    	}
}
cout<<"Vertex   Distance from Source"<<endl;
for (int i = 0; i < dist.size(); i++)
{
	cout<<i+1<<"   "<<dist[i]<<endl;

}
}

int main(int argc, char **argv){
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <graphfilename> <vertex>" << endl;
	return 0;
	}

    
  
  const string graph_filename(argv[1]);
  const string starting_vertex(argv[2]);
  findPath(graph_filename,starting_vertex);
  return 0;
}