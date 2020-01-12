#include <iostream>

#include "matrix.h"

// It is fine to use namespaces in .cc files.
using namespace std;
using namespace linear_algebra_project;

namespace {
void
TestFunction1() {
  Matrix<int> a_matrix(3, 2);
  cout << "Number of rows: " << a_matrix.NumRows() << endl;
  cout << "Number of columns: " << a_matrix.NumCols() << endl;
  cout << "The matrix: " << endl;
  cout << a_matrix;
  a_matrix[0][1] = 100;
  a_matrix[1][0] = 200;
  cout << "The matrix: " << endl;
  cout << a_matrix;

  // Test copy constructor
  Matrix<int> b_matrix = a_matrix;
  cout << "b matrix is:" << endl;
  cout << b_matrix;
  
  // Test constructor from a vector
  vector<vector<int>> a_vector{{1, 2}, {3, 4}};
  Matrix<int> c_matrix(a_vector);
  cout << "c matrix is: " << endl;
  cout << c_matrix;

  // Test constructor from literals initializer list
  Matrix<int> d_matrix({{1, 2, 3}, {4, 5, 6}});
  cout << "d matrix is: " << endl;
  cout << d_matrix;

  // Test constructor that uses an Rvalue reference.
  Matrix<int> e_matrix(std::move(a_vector));
  cout << "e matrix is: " << endl;
  cout << e_matrix;
  // Now the a_vector should not contain anything.
  cout << "size is " << a_vector.size() << endl;
  
  // Test the std::swap for matrices
  cout << "Swapping.." << endl;
  std::swap(d_matrix, e_matrix);
  cout << "d matrix is " << endl;
  cout << d_matrix;
  cout << "e matrix is " << endl;
  cout << e_matrix;
}

void
TestFunction2() {
  Matrix<int> a_matrix(2, 3);
  cout << a_matrix.NumRows() << endl;
  cout << a_matrix.NumCols() << endl;
  a_matrix[0][1] = 3.0;
  a_matrix[1] = vector<int>{10, 20, 30};
  cout << a_matrix;
}

}  // namespace
int main() {
  TestFunction1();
  cout << "Finished TestFunction1" << endl;
  TestFunction2();
  cout << "Finished TestFunction2" << endl;
}
  
  
