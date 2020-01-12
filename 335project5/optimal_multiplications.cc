//Jeffrey Chen
//CSCI 335
//PROJECT 5
//IOANNIS STAMOS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void optimalMult(string dimensions_filename){
	vector<int> matrices;
	ifstream readFile;
	readFile.open(dimensions_filename);
	string read_in_cur;
	string read_in_prev;
	string read_in_next;
	while(getline(readFile,read_in_cur)){
		int matrix = stoi(read_in_cur);
		matrices.push_back(matrix);
	}
	int size = matrices.size();
	readFile.close();
	int matrix_table[size+1][size+1];
	//int last_change[size][size];
	for(int i = 1 ; i < size+1 ; i++){
	for(int j = 1 ; j < size+1 ; j++ ){
		matrix_table[i][j] = 0;
	}
	}
	// for(int i = 0 ; i < size ; i++){
	// for(int j = 0 ; j < size ; j++ ){
	// 	last_change[i][j] = 0;
	// }
	// }
	int n = size;
	for(int i = 1 ; i < n; i++){
		matrix_table[i][i] = 0;
	}
	for (int L = 2; L<n; L++) //looping through every combination of matrix multiplication
    { 
        for (int i = 1; i<n-L+1; i++) 
        { 
            int j = i+L-1; 
            matrix_table[i][j] = 999999; 
            for (int k=i; k<=j-1; k++) 
            { 
                // q = cost multiplications 
                int q = matrix_table[i][k] + matrix_table[k+1][j] + matrices[i-1]*matrices[k]*matrices[j]; //calculating cost
                if (q < matrix_table[i][j]) //updating minimum 
                    matrix_table[i][j] = q; 
            } 
        } 
    } 



// for(int i = 1 ; i < size+1 ; i++){
// 	for(int j = 1 ; j < size+1 ; j++ ){
// 		cout<<matrix_table[i][j]<<" ";
// 	}
// 	cout<<endl;
// }
cout<<"optimal: "<<matrix_table[1][size-1]<<endl;
}

int main(int argc, char **argv){
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <dimensions_filename>" << endl;
	return 0;
	}
  const string dimensions_filename(argv[1]);
  optimalMult(dimensions_filename);
  return 0;
}