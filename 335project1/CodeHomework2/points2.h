// Jayson Tan 
// CSCI 335 - Assignment 1 
// NtS (Note to Self): This is strictly for learning purposes and does not affect the program
// Few comments describing the class Points2

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2 {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  // and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
  Points2() {                       
    size_ = 0; 
    sequence_ = nullptr; 
  }

  // Copy-constructor.
  // NtS: Copy Constructor is a constructor that makes a deep copy 
  Points2(const Points2 &rhs) {
   // 1) have this (refers to itself) points to the reference, rhs', size
   // 2) copy everything from rhs to this; copies rhs' arrays into the std::array that is seq
   // 3) done 
    sequence_ = new std::array<Object, 2>[rhs.size_];
    size_ = rhs.size_; 
    for (size_t i = 0; i < size_; i++) {
      sequence_[i][0] = rhs.sequence_[i][0];
      sequence_[i][1] = rhs.sequence_[i][1];
   }
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2 copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Points2& operator=(const Points2 &rhs) {
    sequence_ = new std::array<Object, 2>[rhs.size_];
    size_ = rhs.size_; 
    for (size_t i = 0; i < size_; i++) {
      sequence_[i][0] = rhs.sequence_[i][0];
      sequence_[i][1] = rhs.sequence_[i][1];
    }

    return *this;
  }

  // Move-constructor. 
  // NtS: Makes a shallow copy and nulls out the copied pointer 
  // 1) Copy Size
  // 2) Allocate array to hold 1 <Object, 2>
  // 3) Assign this newly assigned pointer to sequence_ 
  // sequence_ = new std::array<Object, 2>
  Points2(Points2 &&rhs) {
    sequence_ = new std::array<Object, 2> {{}};
    std::swap(rhs.size_, size_);
    std::swap(rhs.sequence_, sequence_); 
    //rhs.sequence_ = nullptr; 
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2& operator=(Points2 &&rhs) {
    // NtS: swap the instance of current class, with rhs
    //sequence_ = new std::array<Object, 2> {};
    std::swap(rhs.size_, size_);
    std::swap(rhs.sequence_, sequence_); 
    return *this;
  }

  ~Points2() {   
    delete[] sequence_;
    sequence_ = nullptr;
  }
  // End of big-five.

  // One parameter constructor.
  Points2(const std::array<Object, 2>& item) {
    // NtS: dynamically create a new sequence object that takes an array<Object, 2>&item
    // std::array<Object, 2>&item is an array with two index 
    // size_ = 1 since sequence_ is an std::array which holds one item 
    sequence_ = new std::array<Object, 2>{item};
    size_ = 1; 
  }


  // Read a chain from standard input.
  void ReadPoints2() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    // Allocate space for sequence.
    // Add code here. 
    sequence_ = new std::array<Object, 2>[size_of_sequence]; 
    size_ = size_of_sequence;
    Object token;
    //std::cout << "size is: " << size_; 
    for (int i = 0; input_stream >> token; ++i) {
      // Read coordinates.
      // Fill sequence_ here.
      sequence_[i][0] = token;
      input_stream >> token; 
      sequence_[i][1] = token;
    }

    /*
    //Object token;
    for (int i = 0; i < size_of_sequence; ++i) { //size_of_sequence
      // Read coordinates.
      // Fill sequence_ here.
      input_stream >> sequence_[i][0];
      input_stream >> sequence_[i][1];
    }*/
    //std::cout << sequence_ << std::endl; 
  }

  size_t size() const {
    //  NtS: returns the size of the sequence 
    return size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const { 
    if(location >= size_) {
      abort(); 
    }

    else {
      //std::cout << sequence_[location];
      return sequence_[location];
    }
    
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
  // Code missing.
  // NtS: needs to add the array indices values of both arrays
  // needs to create a new Points2 object, we call c3
  // then add c1 + c2 and store in the new object 
  // if the sequences are not the same size, append the result with the remaining part of the larger sequence 
  // return the new object  
  Points2<Object> c3; 

  // if c1.size_ is larger than c2.size_ 
  if(c1.size_ > c2.size_) {
   c3.sequence_ = new std::array<Object, 2>[c1.size_]; 
   c3.size_ = c1.size_; 
   for(size_t i = 0; i < c3.size_; i++) {
    // if i passes c2.size_, then append the larger array to the new array
    c3.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
    c3.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
   }
   
   for(size_t i = c2.size_; i < c2.size_ + (c3.size_ - c2.size_); i++) {
     c3.sequence_[i][0] = c1.sequence_[i][0];
     c3.sequence_[i][1] = c1.sequence_[i][1];
   }
  }

  // if c2.size is larger than c1.size_ 
  else if(c2.size_ > c1.size_) {
    c3.sequence_ = new std::array<Object, 2>[c2.size_]; 
    c3.size_ = c2.size_;
    for(size_t i = 0; i < c3.size_; i++) {
     // if i passes c1.size_, then append the larger array to the new array
     c3.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
     c3.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
    }

    for(size_t i = c1.size_; i < c1.size_ + (c3.size_ - c1.size_); i++) {
     c3.sequence_[i][0] = c2.sequence_[i][0];
     c3.sequence_[i][1] = c2.sequence_[i][1];
    }
  }
  
  // if c1.size_ = c2.size_ 
  else if(c1.size_ == c2.size_) {
   c3.sequence_ = new std::array<Object, 2>[c1.size_];
   c3.size_ = c1.size_;
   for(size_t i = 0; i < c3.size_; i++) {
    c3.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
    c3.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
   }
  }
  /* 
  if(c1.size_ > c2.size_) {
  c3.sequence_ = new std::array<Object, 2>[c1.size_]; 
  c3.size_ = c1.size_; 
    for(size_t i = 0; i < c3.size_; i++) {
      // if i passes c2.size_, then append the larger array to the new array
      if(i > c2.size_) {
        c3.sequence_[i][0] = c1.sequence_[i][0];
        c3.sequence_[i][1] = c1.sequence_[i][1];
      }

      else {
        c3.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
        c3.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
      }
    }
  }

  else if(c2.size_ > c1.size_) {
    c3.sequence_ = new std::array<Object, 2>[c2.size_]; 
    c3.size_ = c2.size_;
    for(size_t i = 0; i < c3.size_; i++) {
      // if i passes c1.size_, then append the larger array to the new array
      if(i > c1.size_) {
        c3.sequence_[i][0] = c2.sequence_[i][0];
        c3.sequence_[i][1] = c2.sequence_[i][1];
      }

      else {
       c3.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
       c3.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
      }
    }
  } */
  return c3; 
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) {
  //  NtS: Overload operator by instantiating a Points2 class (some_points2) 
  //  and accessing its private members 
  //  the first bracketed value represents the array of the set of arrays
  //  the second bracketed value represents the coordinate value of the array of arrays
  //std::cout << some_points2.size_ << "\n";
  for(size_t i = 0; i < some_points2.size_; i++) {
    out << "(" << some_points2.sequence_[i][0] << ", " 
               << some_points2.sequence_[i][1] << ") ";
  }

  out << std::endl;
  return out; 
 }
 
 private:
  // Sequence of points. 
  // NtS: A sequence is an array that holds the type, Object, and it has 2 elements 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
