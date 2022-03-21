#include <cstdlib>
#include <iostream>
#include "heapsort.hpp"

/**
 * @brief Get value function for heapsort (for templated heapsort)
 * 
 * @param obj object to get value from
 * @return double value
 */
inline double getValue(double obj){
  return obj;
}

/**
 * @brief Compare function for heapsort (for templated heapsort)
 * 
 * @param a First value
 * @param b Second value
 * @return true Satisfies comparison
 * @return false Does not satisfy comparison
 */
inline bool compare(double a, double b){
  return a > b;
}

/**
 * @brief Main function to show functionality
 * 
 * Needs unit-testing
 * 
 * @param argc 
 * @param argv 
 * @param envp 
 * @return int 
 */
int main(int argc, char **argv, char **envp){
  double *list;
  list = (double*) malloc(10 * sizeof(double));
  list[0] = 8.4;
  list[1] = 0.4;
  list[2] = 5.4;
  list[3] = 9.4;
  list[4] = 1.4;
  list[5] = 4.4;
  list[6] = 2.4;
  list[7] = 3.4;
  list[8] = 7.4;
  list[9] = 6.4;
  for(int i = 0; i < 10; i++){
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;
  hsrt::heapsort<double, double>(&list, 10, getValue, compare);
  std::cout << "--------------------" << std::endl;
  for(int i = 0; i < 10; i++){
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;
  free(list);
  return 0;
}