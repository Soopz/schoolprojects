//Jeffrey Chen
//CSCI-335 
#include "double_hash_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



// Sample main for program spell_check
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
    return 0;
  }
  
  const string document_filename(argv[1]);
  const string dictionary_filename(argv[2]);
  
  cout << "Input document filename is " << document_filename << endl;
  cout << "Input dictionary filename is " << dictionary_filename << endl;

  HashTableDouble<string> hash_table;
  hash_table.MakeEmpty(); 
  ifstream readFile;
  readFile.open(dictionary_filename);
  string word_read;
  while(getline(readFile,word_read)){ //inserting dictionary to hashtable
    hash_table.Insert(word_read);
  }
  readFile.close();
  //int mid = 0;
  ifstream readDoc;
  readDoc.open(document_filename);
  while(!readDoc.eof()){ //reading till end of file
      readDoc>>word_read;
      
      if(isalpha(word_read[0] == false)){ // getting rid of anything that isn't alphabetical before the word
      word_read = word_read.substr(1,word_read.size()-1);
      }
      if(isalpha(word_read[word_read.length()-1]) == false){ //getting rid of anything that isn't alphabetical after the word
      word_read = word_read.substr(0,word_read.length()-1);
      }
      if(word_read[0] < 97 ){                      //making first letter lowercase 
        word_read[0] = word_read[0]+32;
      }
        if(!hash_table.Contains(word_read)){
          cout<<word_read<<" Not Found"<<endl;
          cout<<"Alternatives : ";

          for(int i = 0 ; i < word_read.size()-1 ; i++){ //finding alternative by swapping chars
            string copy = word_read;
            char temp = copy[i];
            copy[i] = copy[i+1];
            copy[i+1] = temp;
            if(hash_table.Contains(copy)){ //outputing if an alternative is found
              cout<<copy<< " ";
            }

          }
          
          for(int i = 0 ; i < word_read.size()-1 ; i++){ //finding alternative by deleting a char
            string copy = word_read;
            copy.erase(i,1);
            if(hash_table.Contains(copy)){ //outputing if an alternative is found
              cout<<copy<<" ";
            }
          }

          for(int i = 0 ; i < word_read.size() ; i++){ //finding alternative by adding a char
            for( int j = 97 ; j < 123 ; j++ ){ //trying every alphabetical letter in every space
              string copy = word_read;
              string ascii;
              ascii = char(j);
              copy.insert(i,ascii);
              if(hash_table.Contains(copy)){ //outputing if an alternative is found
                cout<<copy<<" ";
              }
            }
          }
          cout<<endl<<endl; 
        }
  }
  readDoc.close();

  // Call functions implementing the assignment requirements.

  return 0;
}
