/**
 * @file quicksort.hpp
 * @author Luca Hanel (lhjnk@pm.me)
 * @brief Templated In-Place Quicksort Algorithm
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once
#include <iostream>

namespace qsrt
{
  /**
   * @brief Get pivot index
   * 
   * @details compares left-most, right-most and middle element values and
   * returns index of median value element
   * 
   * @tparam T Type of objects in list
   * @param list List to get pivot index from
   * @param left Left index
   * @param right Right index
   * @param getValue Function to get value from objects
   * @param compare Function to compare the values by (lower than for low-to-high, greater than for high-to-low)
   * @return int Returns pivot element index
   */
  template<class T, typename F>
  int getPivot(T **list, int left, int right, F (*getValue)(T), bool (*compare)(T, T)){
    int middle = (int) (left + (right-left)/2);
    F l_value = getValue((*list)[left]);
    F r_value = getValue((*list)[right]);
    F m_value = getValue((*list)[middle]);
    if(compare(l_value, r_value) && compare(l_value, m_value)){ // left is lowest
      if(compare(m_value, r_value))
        return middle; // left < middle < right
      return right; // left < right < middle
    }
    if(compare(m_value, l_value) && compare(m_value, r_value)){ // middle is lowest
      if(compare(l_value, r_value))
        return left; // middle < left < right
      return right; // middle < right < left
    }
    // Right is lowest (no need to check)
    if(compare(l_value, m_value))
      return left; // right < left < middle
    return middle; // right < middle < left
  }

  /**
   * @brief Swap the objects in the list at index 0 and index 1
   * 
   * @tparam T Type of objects in list
   * @param list List in which swap happens
   * @param idx0 Index 0 to swap
   * @param idx1 Index 1 to swap
   */
  template<class T>
  void swap(T **list, int idx0, int idx1){
    T tmp;
    tmp = (*list)[idx0];
    (*list)[idx0] = (*list)[idx1];
    (*list)[idx1] = tmp;
  }

  /**
   * @brief Sorts the list around a pivot element (left lower, right higher)
   * 
   * @tparam T Type of objects in list to sort
   * @tparam F Type of the value to sort by
   * @param list List to sort
   * @param left Left index
   * @param right Right index
   * @param getValue Function to get the value to sort by from a given object
   * @param compare Function to compare the values by (lower than for low-to-high, greater than for high-to-low)
   * @return int Returns new index of pivot element
   */
  template<class T, typename F>
  int sort(T **list, int left, int right, F (*getValue)(T), bool (*compare)(T, T)){
    int l = left;
    int r = right;
    int pivot = qsrt::getPivot<T, F>(list, left, right, getValue, compare);
    // Sort the list between left and right
    while(l < r){
      // From left: Search for element which satisfies comparison
      while(l < right && compare(getValue((*list)[l]), getValue((*list)[pivot]))){
        l++;
      }
      // From right: Search for element which does not satisfy comparison
      while(r > left && !compare(getValue((*list)[r]), getValue((*list)[pivot]))){
        r--;
      }
      // Swap found elements
      if(l < r){
        qsrt::swap<T>(list, l, r);
      }
    }
    // Swap pivot element if it doesn't satisfy comparison
    if(!compare(getValue((*list)[l]), getValue((*list)[pivot]))){
      qsrt::swap<T>(list, l, pivot);
    }
    // Return location of pivot
    return l;
  }

  /**
   * @brief Performs the quicksort algorithm on the given list
   * 
   * @tparam T Type of list objects
   * @tparam F Type of parameter to sort by
   * @param list List to sort
   * @param left Left index
   * @param right Right index
   * @param getValue Function to get parameter to sort by
   * @param compare Function to compare the values by (lower than for low-to-high, greater than for high-to-low)
   */
  template<class T, typename F>
  void quicksort(T **list, int left, int right, F (*getValue)(T), bool (*compare)(T, T)){
    int divisor;
    if(left < right){
      divisor = sort<T, F>(list, left, right, getValue, compare);
      qsrt::quicksort<T>(list, left, divisor-1, getValue, compare);
      qsrt::quicksort<T>(list, divisor+1, right, getValue, compare);
    }
  }
}