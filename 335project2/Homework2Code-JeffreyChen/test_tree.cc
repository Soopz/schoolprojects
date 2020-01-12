// Jeffrey Chen
// Main file for Part2(b) of Homework 2.

#include "avl_tree.h"
#include "sequencemap.h"
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  ifstream readFile;
  readFile.open(db_filename);
  string junk;
  string db_line;
  for(int i = 0 ; i < 10 ; i++){ //getting rid of title junk in database
    getline(readFile,junk);
  }
  while(getline(readFile,db_line,'/')){
    if(db_line[0] == '\n'){

      db_line=db_line.substr(1,db_line.size()-1); //taking away newline that was leftover from previous line
    }
    string an_enz_acro = db_line;
    string a_reco_seq;
    while(readFile.peek()!='\n' && getline(readFile,db_line,'/')){ //seeing if next part in text is new line to start a new line
    a_reco_seq = db_line;
    SequenceMap newSequenceMap(a_reco_seq, an_enz_acro);
    a_tree.insert(newSequenceMap);
   }
}
  readFile.close();

  int count_nodes = a_tree.countNodes(); //total nodes
  double internal_path  = a_tree.internalPath(),log = log2(count_nodes); //calculating internal path and log2
  string seq_line,fill_acro;
  int count_seq = 0;
  double recurs_count = 0,remove_recurs = 0, removes = 0;
  ifstream readSequence;
  readSequence.open(seq_filename);

  while(getline(readSequence,seq_line)){ //getting every ine

    SequenceMap newSequenceMap(seq_line,fill_acro);
    if(a_tree.contains(newSequenceMap)){ //if tree contains then it will count as successful query
      count_seq += 1;
      recurs_count += a_tree.findCount(newSequenceMap); //adding to total recursive count
    }

  }
  readSequence.close();

  ifstream removeSequence;
  removeSequence.open(seq_filename);

  while(getline(removeSequence,seq_line) ){ //getting everyother line by storing next in junk
    getline(removeSequence,junk);
    SequenceMap newSequenceMap(seq_line,fill_acro); //if tree contains sequence, remove
    if(a_tree.contains(newSequenceMap)){
      removes++;
      remove_recurs+=a_tree.removeCount(newSequenceMap);
    }
    

 
  }
  cout<<"2: "<<count_nodes<<endl;
  count_nodes = a_tree.countNodes();
  internal_path = a_tree.internalPath();
  log = log2(count_nodes);

  
  cout<<"3a: "<<internal_path/count_nodes<<endl;
  cout<<"3b: "<<((internal_path/count_nodes)/log)<<endl;
  cout<<"4a: "<<count_seq<<endl;
  cout<<"4b: "<<recurs_count/count_seq<<endl;
  cout<<"5a: "<<removes<<endl;
  cout<<"5b: "<<remove_recurs/removes<<endl;
  cout<<"6a: "<<count_nodes<<endl;
  cout<<"6b: "<<internal_path/count_nodes<<endl;
  cout<<"6c: "<<((internal_path/count_nodes)/log)<<endl;



 
}

}  // namespace

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
