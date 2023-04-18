#include <algorithm>
#include <iostream>

/**
 *
 * @return
 */
bool stl_binary_search(){

  int arr[] = {4, 6, 8, 10, 15};
  int target = 10;

  if (std::binary_search(std::begin(arr), std::end(arr), target)) {
    std::cout << "Element found in the array";
  } else {
    std::cout << "Element not found in the array";
  }
}

// C++ program to demonstrate working of `std::binary_search` algorithm
int main() {
  int arr[] = {4, 6, 8, 10, 15};
  int target = 10;

  if (std::binary_search(std::begin(arr), std::end(arr), target)) {
    std::cout << "Element found in the array";
  } else {
    std::cout << "Element not found in the array";
  }

  return 0;
}

