// points2.h
// Author: Jeffrey Chen
// course: CSCI 335
// Instructor: Ioannis Stamos
// Assignment: Project 1
// This program will read a sequence of numbers and create an object that will store the sequence in an array of size 2 and
// be able to swap and add two secquences together.

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
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
  Points2(){
    size_ = 0;
    sequence_ = nullptr;

  }

  // Copy-constructor.
  Points2(const Points2 &rhs){

     sequence_ = new std::array<Object, 2> [rhs.size_]; //creating new sequence with same size as rhs 
     size_ = rhs.size_;
     for( size_t i = 0 ; i < size_ ; i++){ //copying rhs sequence into new sequence
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
  Points2& operator=(const Points2 &rhs){
    Points2 <Object>copy = rhs; 
      std::swap(*this, copy);
      size_ = rhs.size_;
    return *this;

  }

  // Move-constructor. 
  Points2(Points2 &&rhs){
    sequence_ = new std::array<Object, 2> {{}}; //initializing empty sequence;
    size_ = 0;
    std::swap(rhs.sequence_, sequence_); //swaps sequence
    std::swap(rhs.size_,size_); //swaps size
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2& operator=(Points2 &&rhs){
    std::swap(rhs.sequence_, sequence_); //swaps sequence
    std::swap(rhs.size_,size_); //swaps size
    return *this;
  }

  ~Points2(){
    delete sequence_;
    sequence_ = nullptr;
  }

  // End of big-five.

  // One parameter constructor.
  Points2(const std::array<Object, 2>& item) {

  sequence_ = new std::array<Object, 2> {item}; 
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
    Points2 <Object>read;
    size_ = size_of_sequence;
    sequence_ = new std::array<Object, 2> [size_of_sequence];
    
    Object token;
    for (int i = 0 ;input_stream >> token; ++i) {
      // Read coordinates.
      // Fill sequence_ here.
      sequence_[i][0] = token;
      input_stream>>token;
      sequence_[i][1] = token;

    }
    
  }
  //@returns the size of the sequence.
  size_t size() const {
    return size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const { 
    if(location >= size_){
      abort();
    }else{
    return sequence_[location]; //returns cell of sequence according to location
    }
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
  Points2 <Object>c3; //creates a third sequence
    if(c1.size_ > c2.size_ ){ // if first sequence is greater than the second third will be size of c1
      
      c3.sequence_ = new std::array<Object , 2> [c1.size_];
      c3.size_ = c1.size_;
      for(size_t i = 0 ; i < c2.size_ ; i++){ //adds two sequeces and saves in c3
        c3.sequence_[i][0] = c2.sequence_[i][0] + c1.sequence_[i][0];
        c3.sequence_[i][1] = c2.sequence_[i][1] + c1.sequence_[i][1];
      }
      for(size_t i = c2.size_ ; i < c2.size_+(c3.size_-c2.size_) ; i++){ //appends c1 into c2
        c3.sequence_[i][0] = c1.sequence_[i][0];
        c3.sequence_[i][1] = c1.sequence_[i][1];
      }
      
   }
   if(c2.size_ > c1.size_){ // if second sequence is greater than the first, third will be size of c2
    
      c3.sequence_ = new std::array<Object , 2> [c2.size_];
      c3.size_ = c2.size_;
      for(size_t i = 0 ; i < c3.size_ ; i++){ //adds two sequeces and saves in c3
        c3.sequence_[i][0] = c2.sequence_[i][0] + c1.sequence_[i][0];
        c3.sequence_[i][1] = c2.sequence_[i][1] + c1.sequence_[i][1];
      }
      for(size_t i = c1.size_ ; i < c1.size_+(c3.size_-c1.size_) ; i++){ //appends c2 into c3
        c3.sequence_[i][0] = c1.sequence_[i][0];
        c3.sequence_[i][1] = c1.sequence_[i][1];
      }
      
    }
      
   if(c2.size_ == c1.size_){ //if equal, c3 size will just take c2 size
   c3.sequence_ = new std::array<Object , 2> [c2.size_];
      c3.size_ = c2.size_;
      for(size_t i = 0 ; i < c3.size_ ; i++){ // adds two sequences and saves in c3
        c3.sequence_[i][0] = c2.sequence_[i][0] + c1.sequence_[i][0];
        c3.sequence_[i][1] = c2.sequence_[i][1] + c1.sequence_[i][1];
      }

 }
 return c3;
}

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) {

  for( size_t i = 0 ; i < some_points2.size_ ; i++ ){ //outputs according to length of sequence;
   out<<"("<<some_points2.sequence_[i][0]<<", "<<some_points2.sequence_[i][1]<<") ";

 }
 out<<std::endl;
   return out;
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
