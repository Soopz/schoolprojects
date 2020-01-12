// Some functions to test rvalues.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Use unnamed namespace for stand-alone functions if possible.
namespace {

void TestFunction1() {
  string str = "fine" ;
  cout << str << endl;
  string &rstr = str;
  cout << rstr << endl;
  str += 'o';
  cout << str << endl;
  cout << rstr << endl;
  cout << "True/false: " << (&rstr == &str) << endl;
}


void TestFunction3() {
  string str = "fine" ;
  string &&b1 = "hello" ;
  string &&b2 = str + 'a';
  string &&b3 = str.substr(0,3);

  cout << b1 << endl;
  cout << b2 << endl;
  cout << b3 << endl;
}

void TestFunction4() {
  vector<int> a_vector = {1, 2, 3, 4, 5};
  for (auto &x : a_vector) ++x;
  for (auto x : a_vector) cout << x << ", ";
  cout << endl;
}

string RandomItem(const vector<string> &arr) {
  cout << "Version 1" << endl;
  const size_t n = std::rand() % arr.size(); 
  return arr[n];
}

const string &RandomItem2(const vector<string> &arr) {
  cout << "Version 1 -- const reference" << endl;
  const size_t n = std::rand() % arr.size(); 
  return arr[n];
}

string RandomItem(vector<string> &&arr) {
  cout << "Version 2" << endl;
  const size_t n = std::rand() % arr.size(); 
  return arr[n];
} 

void TestRandomItems() {
  const vector<string> v = {"hello", "world", "hi", "why"};
  cout << RandomItem(v) << endl;  
  cout << RandomItem({"hello", "world", "hi", "why"}) << endl; 

  auto &result = RandomItem2(v);
  cout << "Result is " << result << endl;
}

const string &TestLValueReference(const vector<string> &v, size_t element) {
  if (element >= v.size()) abort();
  return v[element];
}

void CompleteTestLValueReference() {
  vector<string> temp{"aa", "bb", "cc"};
  const string &x = TestLValueReference(temp, 1);
  cout << x << endl;
  temp[1] = "jj";
  cout << x << endl;
}

}  // namespace

int main() {
 TestFunction1();
 TestFunction3();
 TestFunction4();
 TestRandomItems();
 CompleteTestLValueReference();
 return 0;
}
