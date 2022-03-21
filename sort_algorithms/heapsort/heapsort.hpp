/**
 * @file heapsort.hpp
 * @author Luca Hanel (lhjnk@pm.me)
 * @brief Templated In-Place Heapsort Algorithm
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

namespace hsrt{
  /**
   * @brief Swap the objects in the list at root 0 and root 1
   * 
   * @tparam T Type of objects in list
   * @param list List in which swap happens
   * @param idx0 root 0 to swap
   * @param idx1 root 1 to swap
   */
  template<class T>
  void swap(T **list, int idx0, int idx1){
    T tmp;
    tmp = (*list)[idx0];
    (*list)[idx0] = (*list)[idx1];
    (*list)[idx1] = tmp;
  }

  /**
   * @brief Heapify the subtree in the given list
   * 
   * @tparam T Type of objects in list to heapify
   * @tparam F Type of value to compare by
   * @param list List to heapify
   * @param length Length of list (subtree) to heapify
   * @param root Root of subtree
   * @param getValue Function to get the value to heapify by
   * @param compare Function to compare the values by (greater than for low-to-high sort, lower than for high-to-low sort)
   */
  template<class T, typename F>
  void heapify(T **list, int length, int root, F (*getValue)(T), bool (*compare)(T, T)){
    int selected = root;
    int left  = 2*root + 1;
    int right = 2*root + 2;

    if(left < length && compare(getValue((*list)[left]), getValue((*list)[selected]))){
      selected = left;
    }
    if(right < length && compare(getValue((*list)[right]), getValue((*list)[selected]))){
      selected = right;
    }

    // If the root is not the selected root, continue heapify
    if(selected != root){
      hsrt::swap<T>(list, root, selected);
      hsrt::heapify<T>(list, length, selected, getValue, compare);
    }
  }

  /**
   * @brief Heapsort
   * 
   * @tparam T Type of objects in list to sort
   * @tparam F Type of value to sort by
   * @param list List to sort
   * @param length Length of list to sort
   * @param getValue Function to obtain value from objects to sort
   * @param compare Function to compare the values by (greater than for low-to-high sort, lower than for high-to-low sort)
   */
  template<class T, typename F>
  void heapsort(T **list, int length, F (getValue)(T), bool (*compare)(T, T)){
    // Initial heapify
    for(int i = length/2-1; i >= 0; i--){
      hsrt::heapify(list, length, i, getValue, compare);
    }

    // Sort the heap
    for(int i = length-1; i > 0; i--){
      // Swap value to correct position
      hsrt::swap(list, 0, i);
      // Heapify next subtree
      hsrt::heapify(list, i, 0, getValue, compare);
    }
  }
}