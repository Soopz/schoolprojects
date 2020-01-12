#include "avl_tree.h"
#include "sequencemap.h"
#include<fstream>
#include <iostream>
#include <string>
using namespace std;
// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree){ 
  ifstream readFile;
  readFile.open(db_filename);
  string junk;
  string db_line;
  for(int i = 0 ; i < 10 ; i++){
    getline(readFile,junk);
  }
  while(getline(readFile,db_line,'/')){
    string an_enz_acro = db_line;
    string a_reco_seq;
    while(readFile.peek()!='\n' && getline(readFile,db_line,'/')){
    a_reco_seq = db_line;
    SequenceMap newSequenceMap(a_reco_seq, an_enz_acro);
    a_tree.insert(newSequenceMap);
   }
}
  readFile.close();
  string reco_seq1,reco_seq2,reco_seq3,enz_acro1,enz_acro2,enz_acro3;
  cin>>reco_seq1;
  cin>>reco_seq2;
  cin>>reco_seq3;
  
  SequenceMap newSequenceMap1(reco_seq1,enz_acro1);
  SequenceMap newSequenceMap2(reco_seq2,enz_acro2);
  SequenceMap newSequenceMap3(reco_seq3,enz_acro3);
  //find(newSequenceMap1,a_tree.root)

  if(  a_tree.contains(newSequenceMap1) == false){
    cout<<"Not Found "<<endl;
  }
  else{
    cout<<a_tree.find(newSequenceMap1)<<endl;
  }  
  if(  a_tree.contains(newSequenceMap2) == false){
    cout<<"Not Found "<<endl;
  }else{
    cout<<a_tree.find(newSequenceMap2)<<endl;
  }
    if(  a_tree.contains(newSequenceMap3) == false){
    cout<<"Not Found "<<endl;
  }else{
    cout<<a_tree.find(newSequenceMap3)<<endl;
  }

 }
 void TestTree( const TreeType &a_tree){

 }

 int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  TestTree(a_tree);

  return 0;
}