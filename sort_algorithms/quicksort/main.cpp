#include <cstdlib>
#include <iostream>
#include "quicksort.hpp"

double getValue(double obj){
  return obj;
}

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
  qsrt::quicksort<double, double>(&list, 0, 9, getValue);
  std::cout << "--------------------" << std::endl;
  for(int i = 0; i < 10; i++){
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;
  free(list);
  return 0;
}