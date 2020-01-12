// A simple basic implementation of a Matrix class
// using std::vector.


// Make sure that you will have unique names
// at the beginning of each header file.
#ifndef TEACH_CSCI335_MATRIX_H_
#define TEACH_CSCI335_MATRIX_H_

#include <iostream>
#include <vector>
#include <initializer_list>
// Avoid using namespace std, etc. in the header files.

// Make it a habit to use namespaces for your code.
namespace linear_algebra_project {

// Templated implementation of Matrix using
// a vector of vectors.
// Sample usage:
//   Matrix<int> a_matrix(2, 3);
//   cout << a_matrix.NumRows() << endl;
//   cout << a_matrix.NumCols() << endl;
//   a_matrix[0][1] = 3.0;
//   a_matrix[1] = vector<int>{10, 20, 30};
//   cout << a_matrix;
template <typename Object>
class Matrix {
 public:
  Matrix() = default;
  Matrix(const Matrix &rhs) = default;
  Matrix& operator=(const Matrix &rhs) = default;
  Matrix(Matrix &&rhs) = default;
  Matrix& operator=(Matrix &&rhs) = default;
  
  // @rows: number of rows.
  // @cols: number of columns.
  // Special constructor for creating a rows x cols matrix.
  Matrix(int rows, int cols) : matrix_2d_(rows) {
    for (auto &this_row : matrix_2d_)
      this_row.resize(cols);
  }
  
 // @lst: an initializer list of items.
 // Special constructor for creating a matrix containing the given items.
 Matrix(std::initializer_list<std::vector<Object>> lst) : matrix_2d_(lst.size()) {
    int i = 0;
    for (auto &v : lst)
      matrix_2d_[i++] = std::move(v);
  }

 // @v: a vector of vectors.
 // Special constructor initializing a matrix from v.
 Matrix(const std::vector<std::vector<Object>> &v) : matrix_2d_{v} {} 

 // @v: an rvalue of vectors of vectors.
 // A special constructor that moves v into the matrix.
 Matrix(std::vector<std::vector<Object>> &&v) : matrix_2d_{std::move(v)} {}
 
 // @row: an index to a row of the matrix.
 // @returns the row as a vector of items. No error checking.
 // const version.
 const std::vector<Object> & operator[](int row) const
   { return matrix_2d_[row]; }

 // @row: an index to a row of the matrix.
 // @returns the row as a vector of items. No error checking.
 // non-cost version. 
 std::vector<Object> & operator[](int row)
   { return matrix_2d_[row]; }
  
 // @returns number of rows.
 size_t NumRows() const { return matrix_2d_.size( ); }
 // @returns number of columns.
 size_t NumCols() const { return NumRows() ? matrix_2d_[0].size( ) : 0; }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Matrix &a_matrix) {
   for (int i = 0; i < a_matrix.NumRows(); ++i) {
     for (const auto &x: a_matrix[i])
       std::cout << x << "  ";
     std::cout << std::endl;
   }
   return out;
 }
 private:
  std::vector<std::vector<Object>> matrix_2d_;
};

}  // namespace linear_algebra_project

#endif  // TEACH_CSCI335_MATRIX_H


