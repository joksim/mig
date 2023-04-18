/*
  std::vector - An dynamic sequential array-like structure.

  Most common operations and usage of std::vector

  docs: https://en.cppreference.com/w/cpp/container/vector
*/

#include <algorithm> // For std::find
#include <iostream>
#include <vector>

/**
 * Example template overload of operator <<
 * @tparam T - type of the vector element
 * @param out - output stream
 * @param vec - the vector that is printed
 * @return - output stream
 */
template <typename T>
::std::ostream &operator<<(::std::ostream &out, const ::std::vector<T> &vec) {
  for (auto &element : vec) {
    out << ' ' << element;
  }
  return out;
}

int main() {
  // C++17 allows multiple using separated by commas;
  using std::cout, std::endl, std::cin, std::vector;


  //---------------------------------------
  // Vector construction & initialization
  //---------------------------------------

  // vector<T> - Empty vector of elements of type T
  std::vector<int> v;

  // vector<T> (int n) : Vector for n elements. The value of the elements is the
  // default value for T
  vector<int> iv(10);

  // vector<T> (int n, T t) : Vector for n elements. The value of the elements
  // is t
  vector<double> dv(3, 3.1415); // vector

  // Use of initializer lists
  vector<float> fv1 = {1.0f, 2.0f, 3.0f};
  vector<float> fv2{2.0f, 4.0f, 6.0f};
  vector<float> fv3({1.0f, 3.0f, 5.0f});
  vector<float> fv4;
  fv4 = {1.0f, 2.0f, 4.0f, 8.f, 16.f};

  //---------------------------------------
  // Iterating vectors
  //---------------------------------------

  // index-based iteration
  for (auto i = 0; i < fv1.size(); ++i) {
    cout << ' ' << fv1[i];
  }
  cout << endl;

  // Range-for loop
  for (auto &element : fv2) {
    cout << ' ' << element;
  }
  cout << endl;

  // iterator-based iteration
  for (auto iterator = fv3.begin(); iterator != fv3.end(); ++iterator) {
    cout << ' ' << *iterator;
  }
  cout << endl;

  // std::for_each + lambda
  ::std::for_each(fv4.begin(), fv4.end(),
                  [](int const &el) { cout << el << " "; });
  cout << endl;

  // overload <<
  cout << iv;

  cout << "By default the empty vector has: " << v.size() << " elements and "
       << v.capacity() << " capacity";

  int value = 5;
  int index = 0;

  // Vector is defined with its elements, the number of elements and its current
  // capacity.
  uint size = v.size();

  // Insert head, index, tail
  v.insert(v.begin(), value);         // head
  v.insert(v.begin() + index, value); // index
  v.push_back(value);                 // tail

  // Access head, index, tail
  int head = v.front(); // head
  head = v[0];          // or using array style indexing

  int new_value = v.at(index); // index
  value = v[index];            // or using array style indexing

  int tail = v.back();    // tail
  tail = v[v.size() - 1]; // or using array style indexing

  // Iterate
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }

  // Find specific element
  if (std::find(v.begin(), v.end(), value) != v.end())
    std::cout << "Element " << value << " found!" << std::endl;
  else
    std::cout << "Element " << value << "NOT found!" << std::endl;

  // Remove head, index, tail
  v.erase(v.begin());         // head
  v.erase(v.begin() + index); // index
  v.pop_back();               // tail

  // Clear
  v.clear();

  return 0;
}
