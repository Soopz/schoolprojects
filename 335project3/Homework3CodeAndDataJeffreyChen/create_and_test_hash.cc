//Jeffrey Chen
//CSCI-335 

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hash_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  
  //..Insert your own code
  ifstream readFile;
  readFile.open(words_filename);
  string word_read;
  while(getline(readFile,word_read)){ //inserting entries into hashtable
    hash_table.Insert(word_read);
  }
  readFile.close();
  string query_word;
  ifstream readQuery;
  readQuery.open(query_filename);
  while(getline(readQuery,word_read)){
    cout<<word_read<<" ";
    if(hash_table.Contains(word_read) == false){
      cout<<"Not Found"<<" probes: "<<hash_table.getProbes()<<endl;
    }else{
      cout<<"Found"<<" probes: "<<hash_table.getProbes()<<endl;
    }
  }



  cout << "Collisions: " << hash_table.getCollisions()<<endl;
  cout << "Number of items: " <<hash_table.getSize()<< endl;
  cout << "Size of hash table: " <<hash_table.getTableSize()<< endl;
  cout << "Load factor: " << static_cast<double> (hash_table.getSize())/static_cast<double> (hash_table.getTableSize()) <<endl;
  cout << "Avg. number of collisions: " <<static_cast<double>(hash_table.getCollisions())/static_cast<double>(hash_table.getSize())<< endl;
}

// Sample main for program create_and_test_hash
int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);

  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    HashTableDouble<string> double_probing_table;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}
