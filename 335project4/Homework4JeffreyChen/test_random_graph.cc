//Jeffrey Chen
//CSCI-335
//PROJECT 4
// Instructor: Ioannis Stamos 

#include "disjoint_sets.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> GetRandomVariables(int maximum_val){ //generating two random variables and returning them as a vector
  srand(time(NULL));
  int random_var1, random_var2;
  random_var1 = rand() % maximum_val;
  random_var2 = rand() % maximum_val;
  return { random_var1, random_var2 };
}

int GetNumofSets(DisjSets & list, const int & num_of_nodes) { //keeping track of number of sets currently in disjoint set
  int num_of_sets = 0;
  for(int i = 0; i < num_of_nodes; i++){ //increment number of sets find returnes index number recursevly
    if(i == list.find(i)) {
      num_of_sets++;
    }
  }
  return num_of_sets;
}

bool ContainsSet(vector<vector<int>> list, vector<int> set){ //checking if a set contains a certain set
  bool in_set = false;
  for(auto s : list){ //going through adjacency list to check if a set is already contained and there are no duplicates
    if(s[0] == set[0] && s[1] == set[1]) {
      in_set = true;
    }
    if(s[1] == set[0] && s[0] == set[0]) {
      in_set = true;
    }
  return in_set;
}
}

void TestRandomGraph(DisjSets & disjoint_set, const int & num_of_nodes) {
  srand(time(0));
  int edges = 0;
  vector<vector<int>> list;
  vector<int> out_degrees(num_of_nodes, 1);
  int random_var1 = 0;
  int random_var2 = 0;

  while(GetNumofSets(disjoint_set, num_of_nodes) > 1){ //adding edges while number of sets is greater than one 
    random_var1 = rand() % num_of_nodes;
    random_var2 = rand() % num_of_nodes;
    while(random_var1 == random_var2){ //checking for same variables
      random_var2 = rand() % num_of_nodes;
    }
    if(!ContainsSet(list, {random_var1, random_var2}) and disjoint_set.find(random_var1) != disjoint_set.find(random_var2)){ //unions only if set isn't already contained 
      disjoint_set.unionSets(random_var1, random_var2);
      edges++;
      list.push_back({random_var1, random_var2}); //pushing onto adjacency list
      out_degrees[random_var1]++;
      out_degrees[random_var2]++;
    }
  }

  cout<<"Number of edges: "<<edges<<endl;

  int smallest = out_degrees[0];
  int largest = out_degrees[0];
  int sum = 0;
  for(auto x : out_degrees){ //calculating smallest and largest out degrees from degree list vector
    if(x < smallest){
      smallest = x;
    }
    if(x > largest){
      largest = x;
    }
    sum+=x;
  }
  cout<<"Smallest out degree: "<<smallest<<endl;
  cout<<"Largest out degree: "<<largest<<endl;
  cout<<"Average out degree: "<<sum/num_of_nodes<<endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <numberofnodes>" << endl;
    return 0;
  }

  const int num_of_nodes(stoi(argv[1], nullptr));

  DisjSets random_graph(num_of_nodes);
  TestRandomGraph(random_graph, num_of_nodes);

  return 0;
}
