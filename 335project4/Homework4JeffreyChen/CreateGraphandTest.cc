//Jeffrey Chen
//CSCI-335
//PROJECT 4
// Instructor: Ioannis Stamos 
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
void queryGraph(const string &graph_filename, const string &query_filename){
ifstream readFile;
readFile.open(graph_filename);
int graph_size;
string vertex_read;
readFile>>graph_size;

int vertex;
float vertex_it;
float temp;
vector<vector<pair<int, float> > >list;

while(getline(readFile,vertex_read)){ //reading till end of file
	vector<pair<int,float> > temp_vertex;
	istringstream cur_line; //string stream for current line
	cur_line.str(vertex_read);
	cur_line>>vertex;
	while(cur_line>>vertex>>temp){ //whle reading input from string stream create pairs and push onto the adjacency list
		pair<int,float> vertex_pair(vertex,temp);
		temp_vertex.push_back(vertex_pair);
	}
	list.push_back(temp_vertex);  //pushing full vertex adjacency onto list   
}
readFile.close();

ifstream readQuery;
bool found=0;
readQuery.open(query_filename);
while(getline(readQuery,vertex_read)){ //reading query to end 
	istringstream cur_line; //string stream for current line
	cur_line.str(vertex_read);
	cur_line>>vertex_it>>temp;
	for(int i = 0 ; i < list[vertex_it].size() ; i++){ //looping to check adjacency list
		if(get<0>(list[vertex_it][i]) == temp ){ //only outputs weight if adjacency query is true and found is set to 1
			cout<<vertex_it<<" "<<temp<<": connected weight of "<<get<1>(list[vertex_it][i])<<endl;
			found = 1;
		}
	}
	if(found == 0){ //if not found output not connected
		cout<<vertex_it<<" "<<temp<<" not connected"<<endl;
	}
	found = 0;
	}			
  }


int main(int argc, char **argv){
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <graphfilename> <queryfilename>" << endl;
	return 0;
	}

    
  
  const string graph_filename(argv[1]);
  const string query_filename(argv[2]);
  queryGraph(graph_filename,query_filename);
  return 0;
}
