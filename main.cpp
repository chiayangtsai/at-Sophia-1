#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// google cplusplus.com

#include "includes.h"

using namespace std;

int main(int argc, char **argv) {

  int testID = 103;
  if (argc < 2)
    printf("default testID : %d\n\n", testID);
  else
    testID = atoi(argv[1]);

  switch (testID) {
  case 0:
    printf("hello world\n");
    break;
  case 1: // vector
    basic_vector();
    break;
  case 2: // vector
    leetcode_print_descending_order();
    break;
  case 3: // vector, LUT
    leetcode_remove_redundant_elements();
    break;
  case 5: // sort : bubble sort
    leetcode_bubble_sort();
    break;
  case 6: // LUT
    leetcode_twoSum();
    break;
  case 7: // recursive
    leetcode_fibonacci();
    break;
  case 8: // vector
    leetcode_shuffle_lists_ii();
    break;
  case 9: // sort lists
    leetcode_sorting_two_sorted_lists();
    break;
  case 10: // string
    basic_string_usage();
    break;
  case 11:
    leetcode_find_num_prefix_matches();
    break;
  case 12:
    leetcode_letters_histogram();
    break;
  case 14: // sort : std
    basic_sort_usage();
    break;
  case 15: // pair, unordered_map, map
    basic_std_pair_unordered_map_map();
    break;
  case 16: // struct
    basic_struct();
    break;
  case 17:
    leetcode_studentScore();
    break;
  case 18: // recursive :
    leetcode_power_of_two();
    break;

  case 20: // recursive :
    leetcode_find_leafs();
    break;
  //------ mid-level classes -------//
  case 22: // binary tree
    basic_binary_tree();
    break;
  case 30: // binary tree - creation - Breath first / level first
    basic_binaryTree_creation_breathFirst(); // 1D->Tree
    break;
  case 31: // binary tree - creation - depth first
    basic_binaryTree_creation_depthFirst(); // 1D->Tree
    break;
  case 32: // binary tree - traversal //Tree->1D
    basic_binaryTree_traversal();
    break;
  case 33:
    leetcode_balanced_tree();
    break;
  case 34:
    leetcode_recursive_leafs();
    break;
  case 35: // decimal, binary representation
    basic_digit_manipulation();
    break;
  case 36:
    leetcode_revert_integer();
    break;
  case 37:
    leetcode_bits_resersal();
    break;
  case 38:
    leetcode_even_odd_diff();
    break;
  case 39: // heapify
    basic_heapify();
    break;
  case 40: // sort
    basic_heap_sort();
    break;
  case 41:
    leetcode_bt_findKthMin();
    break;
  case 42:
    basic_pivot_partitioning();
    break;
  case 43: // quick sort
    basic_quickSort();
    break;
  case 45: // merge sort
    basic_mergeSort();
    break;
  case 46:
    leetcode_bt_distanceK();
    break;
  case 47:
    basic_class_usage();
    break;
    //------ Experienced-level classes -------//
  case 100: // dynamic programming (DP)
    leetcode_functionParsing();
    break;
  case 101: // DP
    leetcode_permuteData();
    break;
  case 103: // Linked list, Hash table
    leetcode_prefix_score();
    break;
  case 104: // ordering conflict
    leetcode_merge_interval();
    break;
  default:
    printf("not a supproted ID : %d\n", testID);
    exit(-1);
  }

  // experienced-level
  //  linked list / Hash table / string
  //  ordering conflict
  //  dynamic programming - targetsum
  //  miscs - FSM (hardware)
  //  graph theory (optional)
}

class CMergeIntervalBase {
public:
  virtual vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> merged;
    printf("please derive your implementation from CmergeIntervalBase \n");
    return merged;
  }
};

class CMergeInterval : public CMergeIntervalBase {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // HW1031
    return vector<vector<int>>(0);
  }
};

void leetcode_merge_interval() {

  // HW1031
  // https://leetcode.com/problems/merge-intervals/description/

  /*
  Given an array of intervals where intervals[i] = [starti, endi], merge all
  overlapping intervals, and return an array of the non-overlapping intervals
  that cover all the intervals in the input.


  Example 1:

  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
  Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
  Example 2:

  Input: intervals = [[1,4],[4,5]]
  Output: [[1,5]]
  Explanation: Intervals [1,4] and [4,5] are considered overlapping.


  Constraints:

  1 <= intervals.length <= 10^4
  intervals[i].length == 2
  0 <= starti <= endi <= 10^4

  */
  CMergeInterval objDerived;
  CMergeIntervalBase *obj;

  obj = &objDerived;

  vector<vector<int>> intervals;
  vector<vector<int>> mergedIntervals;
  intervals.push_back({1, 3});
  intervals.push_back({8, 10});
  intervals.push_back({2, 6});
  intervals.push_back({15, 18});

  printf("== case 1: before merge ==\n");
  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [1, 6] [8, 10], [15, 18]\n\n\n");

  printf("== case 2: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({4, 5});
  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [1, 5]\n\n\n");

  printf("== case 3: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({2, 3});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [1, 4]\n\n\n");

  printf("== case 4: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({0, 2});
  intervals.push_back({3, 5});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [0, 5]\n\n\n");

  printf("== case 5: before merge ==\n");
  intervals.clear();
  intervals.push_back({2, 3});
  intervals.push_back({5, 5});
  intervals.push_back({2, 2});
  intervals.push_back({3, 4});
  intervals.push_back({3, 4});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [2, 4], [5, 5]\n\n\n");
}

struct STreeNode {
  int val;
  STreeNode *left;
  STreeNode *right;

  //-- initialization --
  // constructor : can be ignore if nothing shall be initialized
  STreeNode() : left(nullptr), right(nullptr) {}
  STreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  // destructor : can be ignored if no memory allocation
  //~STreeNode(){}
};

void printNodes(vector<STreeNode> &nodes) {
  for (auto &ir : nodes) {
    printf("val=%d ", ir.val);
    if (ir.left)
      printf("left = %d ", ir.left->val);
    else
      printf("left = null ");

    if (ir.right)
      printf("right = %d ", ir.right->val);
    else
      printf("right = null ");

    printf("\n");
  }
  printf("\n");
}

void basic_binary_tree() {
  //       5       d= 0  :   1 = 2^0
  //      / \
  //     0   2     d = 1  :  2 = 2^1
  //    / \   \
  //   2  3    8   d = 2  :  4 = 2^2
  //       \
  //        7      d = 3  :  8
  //   balanced (O) , complete (X)

  // complete tree:
  //  n : number of data (data size)
  //  d : maximum depth number = log2(n)
  //     For example:  n = 1 =>  log2(1) = 0
  //                   n = 2 =>  log2(2) = 1
  //                   n = 3 =>  log2(3) = 1.x
  //                   n = 5 =>  log2(5) = 2.x
  //  definition: current maximum depth number == (int)log2(n)

  // balanced tree:
  //  max (left tree depth ) - max (right tree depth) <= 1
  //
}

class CClassData {
public:
  float getAverage() {
    // HW0822
    // printf("No implementation");
    int sum = 0;
    for (auto &i : data) {
      sum = i.second + sum;
    }
    return sum / data.size();
  }
  void addData(string name, int score) {
    // HW0822
    data.push_back({name, score}); // O(1)
  }
  void sortedByInitialLetter() {
    // HW0822
    sort(data.begin(), data.end(), letters); // O(N logN )
  }
  void sortedByScores() {
    // HW0822
    sort(data.begin(), data.end(), number); // O(N log N)
  }
  void printStudentData() {
    for (auto &ir : data) {
      printf("%s %d\n", ir.first.c_str(), ir.second);
    }
    printf("\n");
  }
  // void findStudentByString(vector<SStudentData> &outData, string keyStr) {
  //   printf("No implementation");
  // }
private:
  // In C++ class, all call-back functions SHALL be declaired with "static" to
  // keep function execution efficiency
  static bool letters(pair<string, int> &left, pair<string, int> &right) {
    return (left.first.front() < right.first.front());
  }
  static bool number(pair<string, int> &left, pair<string, int> &right) {
    return (left.second < right.second);
  }

private:
  vector<pair<string, int>> data; // name, score
};

class CClassDataMap {
public:
  CClassDataMap() {
    dataStr.clear();
    dataScore.clear();
  }

public:
  float getAverage() {
    // HW0825
    int sum = 0;
    for (auto &i : dataStr) {
      sum = i.second + sum;
    }
    return sum / dataStr.size();
  }
  void addData(string name, int score) {
    // HW0825 : O(logN)
    dataStr[name] = score;
    dataScore[score] = name;
  }
  void sortedByInitialLetter() {
    // HW0825 : O(1)
    sortByScores = false;
  }
  void sortedByScores() {
    // HW0825 : O(1)
    sortByScores = true;
  }
  void printStudentData() {
    // HW0825
    if (sortByScores) {
      for (auto it = dataScore.begin(); it != dataScore.end(); it++) {
        printf("%d %s\n", it->first, it->second.c_str());
      }
      printf("\n");
    } else {
      for (auto it = dataStr.begin(); it != dataStr.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
      }
      printf("\n");
    }
  }

private:
  map<string, int> dataStr;   //<name, score>
  map<int, string> dataScore; //<score, name>
  bool sortByScores;
};

void leetcode_studentScore() {
  // HW0822
  // CClassData *obj = new CClassData;
  // HW0825
  CClassDataMap *obj = new CClassDataMap;
  obj->addData("John", 56);
  obj->addData("Apple", 72);
  obj->addData("Kenny", 89);
  obj->addData("Ace", 99);
  obj->addData("Ash", 23);

  // Question 0: get average of student scores
  printf("score average of students = %.2f\n", obj->getAverage());

  obj->addData("Jack", 78);
  obj->addData("Mario", 67);
  obj->addData("Ben", 49);
  obj->addData("Katie", 78);
  obj->addData("Peace", 88);
  obj->addData("Kelly", 98);

  printf("score average of students = %.2f\n", obj->getAverage());

  printf("== unsorted ==\n");
  obj->printStudentData();

  // Question 1: sorting student data by scores (high to low)

  obj->sortedByScores();
  printf("== sorted by score==\n");
  obj->printStudentData();

  // Question 2: sorting student data by the initial 1st letter of names
  // (alphabet order)

  obj->sortedByInitialLetter();
  printf("== sorted by 1st letter of names (alphabet order) ==\n");
  obj->printStudentData();

  delete obj;
}

// class is used for processing "solution"
//   - defaultly "private" (you can set "public" to make is accessable)
//  class BTProcess
//  {
//  public:
//    int val;
//  };

// struct is used for processing "data"
//   - defaultly "public" (you can set "private" to secure it)

void basic_struct() {

  // constructor for basic data type / how to initialize a variable
  //  int == int32_t
  // int a(5);

  // constructor
  STreeNode obj;
  obj.val = 5;

  STreeNode objtmp(5);

  // memory allocation
  STreeNode *ptr;
  ptr = new STreeNode(5);
  delete ptr;

  STreeNode *nodeArr = new STreeNode[10];
  delete[] nodeArr;

  // memory copy - array
  int a[5] = {1, 3, 6, 2, 7};
  int b[5];
  int copySize = 5;
  // METHOD 1: element-by-element copy
  for (int i = 0; i < 5; i++)
    b[i] = a[i];

  // METHOD 2 : memcpy( destination address , source address  ,  size in bytes)
  memcpy(b, a, sizeof(int) * copySize);

  // memory copy - vector
  vector<int> vecA(10, 0);
  vector<int> vecB;
  vecB = vecA;

  // mind set : when to use vector? when to use array? when to use mempcy?
  //  => when your platform/device is weak, use C instead C++.

  // TBD : operator
}

bool myDesCompre(int &left, int &right) { return (left > right); }

void basic_sort_usage() {
  // std::sort(start iterator, end iterator)
  vector<int> in({3, 7, 1, 8, 2});

  printf("before sort\n");
  for (auto &ir : in) {
    printf("%d ", ir);
  }
  printf("\n");

  // time complexity : O(NlogN) <= quick sort , merge sort
  //    bubble sort    O(N^2)
  //
  sort(in.begin(), in.end());

  printf("after sort\n");
  for (auto &ir : in) {
    printf("%d ", ir);
  }
  printf("\n");

  // std::sort(start iterator, end iterator, customized compare)
  // descending order
  sort(in.begin(), in.end(), myDesCompre);
  printf("after sort(descending)\n");
  for (auto &ir : in) {
    printf("%d ", ir);
  }
  printf("\n");
}

void leetcode_find_num_prefix_matches() {
  // vector<string> words({"abc", "ab", "b", "c"});

  string word = "abcd";
  string key = "ab";
  // Q : is key a prefix of word?
  // METHOD 0 : compare ASCII code diference
  // METHOD 1 : string.find() == 0

  // .find(str) != string::npos <== str is found
  //    return : match position
}

void leetcode_letters_histogram() {
  string word = "as;lkdjfha.. al;kshjdf;laikhs;dflk jkl;j!";

  // Q : print out the histogram of alphbet apperance with alphbet order.
  //
  //   NOTE: non-existence and non-alphabet shall not be printed
  //
  // HW0818
  // Example:
  //     a : 4
  //     b : 2
  //     d : 1

  vector<int> ans(26, 0);
  for (int i = 0; i < word.length(); i++) {
    ans[word[i] - 'a']++;
  }
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] > 0) {
      char temp = 'a' + i;
      printf("%c:%d \n", temp, ans[i]);
    }
  }
}

void leetcode_shuffle_lists_ii() {

  // Q: given two list, shuffle these two lists to a new listC.
  //
  // For example: listA = {8, 1, 3, 9, 10, 2},
  //              listB = {4, 5, 7, 3}
  //              listC = {8, 4, 1, 5, 3, 7, 9, 3, 10, 2}

  vector<int> listA({8, 1, 3, 9, 10, 2});
  vector<int> listB({4, 5, 7, 3});
  vector<int> listC;

  // HW0812
  // int maxSize= max(listA.size(), listB.size());
  int maxSize = (listA.size() > listB.size()) ? listA.size() : listB.size();
  for (int i = 0; i < maxSize; i++) {
    if (i < listA.size()) {
      listC.push_back(listA[i]);
    }
    if (i < listB.size()) {
      listC.push_back(listB[i]);
    }
  }

  for (auto &ir : listC) {
    printf("%d ", ir);
  }
  printf("\n");
}

void leetcode_sorting_two_sorted_lists() {

  // Q: given two sorted lists, comebine these two sorted lists to a new sorted
  // on For example: listA = {1, 5, 7, 9}
  //              listB = {2, 3, 6, 10, 12}
  //  Combine listA and listB => listC = {1, 2, 3, 5, 6, 7, 9, 10, 12}
  vector<int> listA({1, 5, 7, 9});
  vector<int> listB({2, 3, 6, 10, 12});
  vector<int> listC;
  // HW0812
  auto first = listA.begin();
  auto sec = listB.begin();
  int count = listA.size() + listB.size();
  // unordered_map<int,int> temp;
  while (count > 0) {
    if (*first < *sec) {
      listC.push_back(*first);
      if (first != listA.end() - 1)
        first++;
      else
        break;
    } else {
      listC.push_back(*sec);
      if (sec != listB.end() - 1)
        sec++;
      else
        break;
    }
    count--;
  }
  if (first == listA.end() - 1) {
    while (sec != listB.end()) {
      listC.push_back(*sec);
      sec++;
    }
  }
  for (auto &ir : listC) {
    printf("%d ", ir);
  }
  printf("\n");
}

bool myPairComp(pair<int, string> &left, pair<int, string> &right) {
  return (left.first < right.first);
}

void basic_std_pair_unordered_map_map() {

  int sID[7] = {3, 2, 6, 4, 8, 10, 9};
  string sName[7] = {"John", "Jack", "Topher", "Ku", "Elly", "Kim", "Hailey"};
  int num = 7;

  // pair
  {
    vector<pair<int, string>> data;
    for (int i = 0; i < 7; i++) {
      // v0: initialization
      //  pair<int, string> tmp;
      //  tmp.first = sID[i];
      //  tmp.second = sName[i];

      // data.push_back(tmp);
      // v1: make_pair()
      data.push_back(make_pair(sID[i], sName[i]));
    }

    sort(data.begin(), data.end(), myPairComp);

    for (auto &ir : data) {
      printf("%d %s\n", ir.first, ir.second.c_str());
    }
    printf("\n");
  }

  // unordered_map
  {
    //.begin(), .end() : same definition in "vector"
    //.count(key) : if key exists, return value > 0 <= O(1)
    //              .count() "usually" got implemented by .find(key)
    //.find(key) : return iterator if exists; otherwise, return .end() <= O(1)
    unordered_map<int, string> inMap;
    for (int i = 0; i < num; i++) {
      inMap[sID[i]] = sName[i];
    }
    for (auto it = inMap.begin(); it != inMap.end(); it++) {
      printf("%d %s\n", it->first, it->second.c_str());
    }
    printf("\n");

    // how to sort the unordered_map elements according to key value?
    //  step 1 : create a vector of pairs which has the same data types in
    //  unordered_map step 2: sort the vector of paris.
  }

  // map
  {
    //.begin(), .end() : same definition in "vector"
    //.find(key) : return iterator if exists; otherwise, return .end() <=
    // O(logN)

    map<int, string> inMap;
    for (int i = 0; i < num; i++) {
      inMap[sID[i]] = sName[i];
    }
    for (auto it = inMap.begin(); it != inMap.end(); it++) {
      printf("%d %s\n", it->first, it->second.c_str());
    }
    printf("\n");

    //.lower_bound(key) : if key exist, return iterator. Otherwise, use the next
    // iterator. - O(log(N))
    //  - key > last key : return .end()
    //  - key < first key : return .begin()
    int key = 4;
    auto it = inMap.lower_bound(key);
    if (it != inMap.end()) {
      printf("lower_bound(%d) => key=%d, val=%s\n", key, it->first,
             it->second.c_str());
    } else
      printf("lower_bound(%d) =>  end()\n", key);

    key = 5;
    it = inMap.lower_bound(key);
    if (it != inMap.end()) {
      printf("lower_bound(%d) => key=%d, val=%s\n", key, it->first,
             it->second.c_str());
    } else
      printf("lower_bound(%d) => end()\n", key);

    key = 1;
    it = inMap.lower_bound(key);
    if (it != inMap.end()) {
      printf("lower_bound(%d) => key=%d, val=%s\n", key, it->first,
             it->second.c_str());
    } else
      printf("lower_bound(%d) => end()\n", key);

    key = 12;
    it = inMap.lower_bound(key);
    if (it != inMap.end()) {
      printf("lower_bound(%d) => key=%d, val=%s\n", key, it->first,
             it->second.c_str());
    } else
      printf("lower_bound(%d) => end()\n", key);

    key = 7;
    it = inMap.lower_bound(key);
    if (it != inMap.end()) {
      printf("lower_bound(%d) => key=%d, val=%s\n", key, it->first,
             it->second.c_str());
    } else
      printf("lower_bound(%d) => end()\n", key);
  }

  // unordered_set<key> :
  // set<key> :
}

void leetcode_remove_redundant_elements() {
  // HW0807
  vector<int> in({3, 2, 6, 3, 5, 7, 8, 2});
  // Q: given a input array, remove the redundnat elements and print the results
  //  For example: in = {3, 2, 6, 3, 5, 7, 7, 8, 2}
  //  The expected output = {3, 2, 6, 5, 7, 8}
  unordered_map<int, int> temp;
  for (auto it = in.begin(); it < in.end(); it++) { // O(N)
    if (temp.count(*it)) {
      in.erase(it);
    } else
      temp[*it] = *it;
  }
  for (auto vec : in) {
    printf("%d ", vec);
  }

#if 1
  temp.clear();
  // assign vector values to unordered_map
  for (auto &ir : in) { // O(N)
    if (temp.find(ir) != temp.end()) {
      temp[ir]++;
    } else {
      temp[ir] = 1;
    }
  }

  // find value in unordered_map to check if appearance > 1
  for (auto &ir : in) { // O(N
    if (temp[ir] < 2) {
      printf("%d ", ir);
    }
  }
  printf("\n");

#endif
}

void leetcode_print_descending_order() {
  vector<int> in({3, 2, 6, 3, 5, 7, 8, 2});
  // Q: print "in" results at descending order.
  //    That is, 2, 8, 7, 5, 3, 6, 2, 3
  //  NOTE: please use "iterator" instead of conventional "index accessing" way

  // HW0812
  // auto right = in.end() - 1;
  auto right = prev(in.end());
  while (right >= in.begin()) {

    printf("%d ", *right);
    right--;
  }
  // use iterator from the last element to the first element
  // previous : iterator -= 1
  // use prev() :  prev(iterator)
  //
  // NOTE: next() : next(iterator), get the next iterator

#if 0  
  //HW0807
  auto left = in.begin();
  auto right = in.end()-1;
  while(left<right){
    swap(*left,*right);
    left++;
    right--;
  }
  for (auto vec : in) {
        printf("%d ",vec);
    }
#endif
}

void basic_string_usage() {

  // ASCII code
  string tmp = "John";
  //(SKIPPED)
}

int fibonacciSeq(int k, vector<int> &memo) {

  // HW0812 : use "caching" to memorize previous-caclulated results to save time
  // complexity
  if (k < 2)
    return k;
  if (memo[k])
    return memo[k];
  return memo[k] = fibonacciSeq(k - 2, memo) + fibonacciSeq(k - 1, memo);

  // if (k == 0)
  //   return 0;
  // if (k == 1)
  //   return 1;

  // return fibonacciSeq(k - 2) + fibonacciSeq(k - 1);

  //
  // time complexity : O(2^n)
  //
  // recursive principal: use caching to reduce the time complexity
  // How to solve "dynamic programming":
  // (1) top-down / backtracking + memoization <= recommended !
  // (2) bottom-up + tabulation <= cons : you need to figure out detailed
  // algorithm
  //
  //
  // example X(5)
  //        X(4)              X(3)
  //      X(3), X(2)            X(2) , X(1)
  //  X(2) X(1)   X(1) X(0)    X(1) X(0)
  // X(1) X(0)
  //
  // improved version : "caching" skill
}

int fibonacciSeq_nonrec(int k) {
  // O(N)
  int Xn2 = 0; // X(0)
  if (k == 0)
    return Xn2;

  int Xn1 = 1; // X(1)
  if (k == 1)
    return Xn1;

  int Xk;
  for (int i = 2; i <= k; i++) {
    Xk = Xn1 + Xn2;

    int tmp = Xn1;
    Xn1 = Xk;
    Xn2 = tmp;
  }

  return Xk;
}

void leetcode_fibonacci() {
  // X(n) = X(n-1) + X(n-2)
  // X(0) = 0, X(1) = 1;
  // 0, 1, 1, 2, 3, 5....
  // X(0)........X(N)
  //
  //  Q1: find X(K)?
  int k = 7;
  int Xk;
  enum IMPLT_ID_ {
    IMPLT_REC = 0, // O(2^N) (no caching) => O(N) (no caching)
    IMPLT_NONREC   // O(N)
  };

  int impltID = IMPLT_NONREC;

  if (impltID == IMPLT_REC) {
    vector<int> memo(k + 1, 0);
    Xk = fibonacciSeq(k, memo);
  } else if (impltID == IMPLT_NONREC) {
    Xk = fibonacciSeq_nonrec(k);
  } else {
    printf("not a supported implementation %d\n", impltID);
    exit(-1);
  }

  printf("X(%d)=%d\n", k, Xk);
}

vector<vector<int>> twoSumCore(vector<int> in, int targetSum) {
  // HW0807
  unordered_map<int, int> temp;
  vector<vector<int>> res;

  for (int i = 0; i < in.size(); i++) { // O(N)
    int num = targetSum - in[i];
    if (temp.count(num)) {
      res.push_back({temp[num], i});
      temp.erase(num);
    } else
      temp[in[i]] = i;
  }
  return res;

  return vector<vector<int>>(0); // To-be-modified
}

void leetcode_twoSum() {
  vector<int> in({5, 1, 6, 3, 9, 4, 3, 6});
  int targetSum = 10;

  // NOTE: only print out the non-repeated results
  // NOTE: time complexity has to be O(N)

  vector<vector<int>> res = twoSumCore(in, targetSum);
  // HW0807
  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto in_it = it->begin(); in_it != it->end(); in_it++) {
      printf("%d ", *in_it);
    }
  }

  // use iterator to finish the "print out"
}

void bubble_sort_core(vector<int> &in) {
  // {3, 6, 1, 9, 3, 5, 2}
  //  ------------------> max
  //  ---------------> 2nd max
  //  ....
  // HW0807

  for (int i = 0; i < in.size() - 1; i++) {
    for (int j = 0; j < in.size() - 1 - i; j++) {
      if (in[j + 1] > in[j])
        swap(in[j + 1], in[j]);
    }
  }

  /*
    for (int num = 0; num < in.size(); num++) {
      for(int compare = 0; compare < num-1; compare++)
      {
        //compare
      }
    }
  */
}

void basic_vector() {
  // https://cplusplus.com/reference/vector/vector/
  // .begin() : the first iterator
  // .end() : the last iterator
  // .front() : the first reference // a[0]
  // .back() : the last reference
  // .push_back( <element type> )
  // .erase( <erased iterator> )
  // .insert( <inserted iterator> )

  //   3 5 1 9 3 5 2  <== consecutive memory allocation if "in" is array

  vector<int> in({3, 6, 1, 9, 3, 5, 2});
  //  | 3 | 5 | 1 | 9 | 3 | 5 | 2 |
  //  ^ iterator
  //  ^ .begin()                  ^ .end()

  // --iterator to access element
  //  *(iterator) : reference
  for (vector<int>::iterator it = in.begin(); it != in.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");

  vector<int>::iterator it = in.begin();
  while (it != in.end()) {
    printf("%d ", *it);

    it++;
  }
  printf("\n");

  // simplifed
  for (auto it = in.begin(); it != in.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");

  // simplified version like Python
  // HW0807 for VK : check "auto" usage
  for (auto x : in) { // call-by-value : copy (A Bug in Replit or clang++ 17)
                      // for(auto& x : in){ // call-by-reference : reference
    x = 0;
    printf("%d ", x);
  }
  printf("\n");
}

void leetcode_bubble_sort() {
  vector<int> in({3, 6, 1, 9, 3, 5, 2});
  //   3 5 1 9 3 5 2  <== consecutive memory allocation if "in" is array
  //  | 3 | 5 | 1 | 9 | 3 | 5 | 2 |

  bubble_sort_core(in);

  // print the resoults in
  // index access
  for (int i = 0; i < in.size(); i++) {
    printf("%d ", in[i]);
  }
  printf("\n");
}

#define POWEROFTWOBITWISE_FIX 1

int powerOfTwoBitwise(int k) {
  // 0000 0001 = 2^0 (1 在 0 bit location)
  // 0000 0010 = 2^1 (1 在 1 bit location)
  // 0000 0100 = 2^2 (1 在 2 bit location)
  // 0000 1000 = 2^3
  // 0001 0000 = 2^4

#if POWEROFTWOBITWISE_FIX
  return (1 << k); // O(1)
#else
  int res = 1;
  for (int i = 0; i < k; i++) // O(N)
  {
    res = res << 1;
  }
  return res;
#endif
}

int powerOfTwoRecur(int k) // O(N)
{
  // f(k) = 2*f(k-1)
  // f(0) =1

  // exception | base
  if (k == 0)
    return 1;

  // general
  return 2 * powerOfTwoRecur(k - 1); // backtracking
}

void leetcode_power_of_two() {
  // X(k) = 2^k

  enum IMPT_ID_ {
    IMPLT_BITWISE = 0, // O(1)
    IMPLT_RECURSIVE,   // O(N)
  };

  int k = 8;
  int Xk = -1;

  int impltID = IMPLT_RECURSIVE;
  if (impltID == IMPLT_BITWISE) {
    Xk = powerOfTwoBitwise(k);
  } else if (impltID == IMPLT_RECURSIVE) {
    Xk = powerOfTwoRecur(k);
  } else {
    printf("not a supported implementation id : %d\n", impltID);
  }

  printf("X(%d) = %d\n", k, Xk);
}

class CFindLeafsBase {
public:
  virtual vector<int> findLeafs(STreeNode *root) {
    printf("need a implementation\n");
    return vector<int>(0);
  }
};

class CFindLeafsDerived : public CFindLeafsBase {
public:
  vector<int> findLeafs(STreeNode *root) {
    // f(root) = f(root->left) + f(root->right)
    //
    // HW0831
    vector<int> leafs;
    if (!root->left && !root->right) {
      leafs.push_back(root->val);
    } else {
      if (root->left) {
        vector<int> left_num = findLeafs(root->left);
        for (int i = 0; i < left_num.size(); i++) {
          leafs.push_back(left_num[i]);
        }
      }
      if (root->right) {
        vector<int> right_num = findLeafs(root->right);
        for (int i = 0; i < right_num.size(); i++) {
          leafs.push_back(right_num[i]);
        }
      }
    }

    // exception/base
    //  when both children are null pointers

    // general case
    // get vectors from left tree
    // get vector from right tree

    return leafs;
  }
};

class CFindLeafsVK : public CFindLeafsBase {
public:
  vector<int> findLeafs(STreeNode *root) {
    // f(root) = f(root->left) + f(root->right)

    vector<int> res;
    // exception | base
    if (root == nullptr)
      return res;

    if (root->left == nullptr && root->right == nullptr) {
      res.push_back(root->val);
      return res;
    }

    // general
    vector<int> resLeft = findLeafs(root->left);
    res.insert(res.end(), resLeft.begin(), resLeft.end());

    vector<int> resRight = findLeafs(root->right);
    res.insert(res.end(), resRight.begin(), resRight.end());

    return res;
  }
};

void leetcode_find_leafs() {
  //             7
  //            / \
  //           9   1
  //          /     \
  //         5       2
  //           {5, 2}

  //             7
  //            / \
  //           9   1
  //          /
  //         5
  //            {5, 1}

  vector<STreeNode> nodeData(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //             7
  //            / \
  //           9   1
  //          / \    \
  //         5   4   2
  //             /
  //            6
  //

  printNodes(nodeData);
  //---------------//
  STreeNode *tree = &(nodeData[0]);

  CFindLeafsDerived solDerived;
  CFindLeafsVK solVK;

  CFindLeafsBase *sol = nullptr;

  enum _IMPLT_ID {
    IMPLT_DERIVED = 0,
    IMPLT_VK,
  };

  int impltID = IMPLT_DERIVED;

  if (impltID == IMPLT_DERIVED) {
    sol = &solDerived;
  } else if (impltID == IMPLT_VK) {
    sol = &solVK;
  } else {
    printf("not a supported implementation");
    exit(-1);
  }

  vector<int> resVec = sol->findLeafs(tree);

  printf("res = ");
  for (auto &ir : resVec) {
    printf("%d ", ir);
  }
  printf(" (ans : 5, 6, 2)\n");
}

STreeNode *createBFTree(vector<STreeNode> &nodes) {

  // METHOD 0: index 0 -> last index (connect child nodes)
  // METHOD 1: index 1 -> last index (connect parenet nodes)
  for (int i = 1; i < nodes.size(); i++) {
    if (i % 2) {
      int parentIdx = (i - 1) / 2;
      nodes[parentIdx].left = &(nodes[i]);
    } else {
      int parentIdx = (i - 2) / 2;
      nodes[parentIdx].right = &(nodes[i]);
    }
  }

  return &(nodes[0]);
}

void basic_binaryTree_creation_breathFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});

  // Breath-first / level-first binary tree
  //     8(0)
  //    /      \
  //   5(1)     3(2)
  //  /   \      /    \
  // 2(3) 9(4)  1(5)   null(6)

  // left child index = 2 * parent index +1
  // right child index = 2* parent index +2

  // establish binary tree for data with size N

  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  STreeNode *root = createBFTree(nodes);
  printf("root : %d\n", root->val);
  printNodes(nodes);
}

STreeNode *createDFPreOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                               int depth, int &dataIdx) {
  // f(x) = {root | dataIdx } + f(x->left) + f(x->right) //root, left, right
  STreeNode *root = nullptr;

  // exception
  if (depth == maxDepthNo) {
    if (dataIdx < nodes.size()) {
      root = &(nodes[dataIdx]);
      dataIdx++;
    }
    return root;
  }

  // general
  root = &(nodes[dataIdx]);
  dataIdx++;

  root->left = createDFPreOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  root->right = createDFPreOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  return root;
}

STreeNode *createDFPreOrderRec(vector<STreeNode> &nodes, int startIdx,
                               int endIdx) {
  // f(x) =  {root} + f(x->left | 50% remaining nodes) + f(x->right | 50%
  // remaining nodes)
  //           (0)           (1)      (2)                           (3) (4) (5)
  //                         ^         ^
  //                        startIdx   endIdx
  STreeNode *root = nullptr;

  // exception
  if (startIdx == endIdx) // only 1 node
  {
    return &(nodes[startIdx]);
  }

  if (startIdx + 1 == endIdx) // only 2 nodes
  {
    root = &(nodes[startIdx]);
    root->left = &(nodes[endIdx]); // endIdx-node could be either left or right
    return root;
  }

  // general
  int rootIdx = startIdx;
  root = &(nodes[rootIdx]);

  int len = endIdx - (startIdx + 1) + 1; // remaining nodes

  root->left =
      createDFPreOrderRec(nodes, startIdx + 1, startIdx + 1 + (len / 2) - 1);
  root->right = createDFPreOrderRec(nodes, startIdx + 1 + (len / 2), endIdx);

  return root;
}

STreeNode *createDFTree_PreOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;
  // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right

  enum _IMPLTID {
    IMPLT_DATAIDX = 0,
    IMPLT_DIV_N_CONQ,
  };
  int impltID = IMPLT_DIV_N_CONQ;
  if (impltID == IMPLT_DIV_N_CONQ) {
    //      8(0)
    //    /      \
    //   5(1)     2(3)
    //  /   \      /    \
    // 3(2) null  9(4)   1(5)

    // f(x) =  {root} + f(x->left | 50% remaining nodes) + f(x->right | 50%
    // remaining nodes)
    //           (0)           (1) (2)                           (3) (4) (5)

    // input/condition: startIdx, endIdx
    // output (return, reference): return tree
    // variable among recursion: nodes
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFPreOrderRec(nodes, startIdx, endIdx);

  } else if (impltID == IMPLT_DATAIDX) {
    //      8(0)                   d= 0
    //    /      \
    //   5(1)     9(4)             d= 1
    //  /   \      /    \
    // 3(2) 2(3)  1(5)   null      d= 2

    // f(x) = {root | dataIdx } + f(x->left | dataIdx ) + f(x->right | dataIdx)
    // //root, left, right

    int maxDepthNo = (int)log2((double)nodes.size());

    // input/condition: nodes, maxDepthNo
    // output (return, reference): tree
    // variable among recursion: depth, next tree, data indx (nodes)
    int depth = 0;
    int dataIdx = 0;
    root = createDFPreOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else {
    printf("Not a supported implementation %d \n", impltID);
    exit(-1);
  }

  return root;
}

STreeNode *createDFInOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                              int depth, int dataIdx) {
  // f(x) = f(x->left) + {root | dataIdx } + f(x->right) //left, root, right
  STreeNode *root = nullptr;
  if (depth == maxDepthNo) {
    if (dataIdx < nodes.size()) {
      root = &(nodes[dataIdx]);
    }
    return root;
  }

  root = &(nodes[dataIdx]);
  if (depth + 1 != maxDepthNo) {
    root->left = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx - 2);
    root->right = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx + 2);
  } else {
    root->left = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx - 1);
    root->right = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx + 1);
  }
  // HW0906
  return root;
}

STreeNode *createDFInOrderRec(vector<STreeNode> &nodes, int startIdx,
                              int endIdx) {
  // f(x) = f(x->left | 50% remaining nodes) + {root} + f(x->right | 50%
  // remaining nodes)
  //           (0)           (1)         (2)      (3)         (4)  (5)    <==
  //           left root right

  STreeNode *root = nullptr;
  // exception
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }
  if (startIdx + 1 == endIdx) {
    root = &(nodes[endIdx]);
    root->left = &(nodes[startIdx]); // must be left
    return root;
  }

  // general
  int rootIdx = startIdx + (endIdx - startIdx + 1) / 2;
  root = &(nodes[rootIdx]);

  root->left = createDFInOrderRec(nodes, startIdx, rootIdx - 1);
  root->right = createDFInOrderRec(nodes, rootIdx + 1, endIdx);

  return root;
}

STreeNode *createDFTree_InOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum _IMPLTID {
    IMPLT_DATAIDX = 0,
    IMPLT_DIV_N_CONQ,
  };
  int impltID = IMPLT_DIV_N_CONQ;
  if (impltID == IMPLT_DIV_N_CONQ) {
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFInOrderRec(nodes, startIdx, endIdx);

  } else if (impltID == IMPLT_DATAIDX) {
    // input/condition: nodes, maxDepthNo
    // output (return, reference): tree
    // variable among recursion: depth, next tree, data indx (nodes)
    int maxDepthNo = (int)log2((double)nodes.size());
    int depth = 0;
    int dataIdx = 3;
    root = createDFInOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else {
    printf("Not a supported implementation %d \n", impltID);
    exit(-1);
  }

  return nullptr;
}

STreeNode *createDFPostOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                                int depth, int &dataIdx) {
  // f(x) =  f(x->left) + f(x->right) + {root | dataIdx } //left, right, root
  STreeNode *root = nullptr;
  // HW0906
  //      1(5)
  //    /      \
  //   3(2)      9(4)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)
  // 後序遞迴構建樹，依照 "左子樹 -> 右子樹 -> 根節點"
  //後面開始:根節點->右子樹->左子樹
  if (depth == maxDepthNo) {
    if (dataIdx >= 0) {
      root = &(nodes[dataIdx]);
    }
    return root;
  }
  root = &(nodes[dataIdx]);
  dataIdx--;
  root->right = createDFPostOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  dataIdx--;
  root->left = createDFPostOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  return root;
}

STreeNode *createDFPostOrderRec(vector<STreeNode> &nodes, int startIdx,
                                int endIdx) {
  // f(x) = f(x->left | 50% remaining nodes) + f(x->right | 50%remaining nodes)
  // + {root}
  //           (0)   (1) (2)                      (3)    (4) (5)    <== left
  //           right  root
  // HW0913
  STreeNode *root = nullptr;

  // exception
  if (startIdx == endIdx) // only 1 node
  {
    return &(nodes[startIdx]);
  }

  if (startIdx + 1 == endIdx) // only 2 nodes
  {
    root = &(nodes[endIdx]);
    root->right =
        &(nodes[startIdx]); // startIdx-node could be either left or right
    return root;
  }

  // general
  int rootIdx = endIdx;
  root = &(nodes[rootIdx]);
  int len = (endIdx - 1) - startIdx + 1;

  root->left = createDFPostOrderRec(nodes, startIdx, startIdx + (len / 2) - 1);
  root->right = createDFPostOrderRec(nodes, startIdx + (len / 2), endIdx - 1);

  return root;
}

STreeNode *createDFTree_PostOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum _IMPLTID {
    IMPLT_DATAIDX = 0,
    IMPLT_DIV_N_CONQ,
  };
  int impltID = IMPLT_DIV_N_CONQ;
  if (impltID == IMPLT_DIV_N_CONQ) {
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFPostOrderRec(nodes, startIdx, endIdx);

  } else if (impltID == IMPLT_DATAIDX) {
    int maxDepthNo = (int)log2((double)nodes.size());

    // input/condition: nodes, maxDepthNo
    // output (return, reference): tree
    // variable among recursion: depth, next tree, data indx (nodes)
    int depth = 0;                  // 初始深度設置為最大深度
    int dataIdx = nodes.size() - 1; // 初始化索引
    // int temp = nodes.size()%3;
    root = createDFPostOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else {
    printf("Not a supported implementation %d \n", impltID);
    exit(-1);
  }

  return nullptr;
}

void basic_binaryTree_creation_depthFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});
  vector<STreeNode> nodes;
  STreeNode *root = nullptr;

  // 1D -> tree

  printf("== Depth First: Pre-order ==\n");
  // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
  //      8(0)
  //    /      \
  //   5(1)     9(4)
  //  /   \      /    \
  // 3(2) 2(3)  1(5)   null
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_PreOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);

  printf("== Depth First: In-order ==\n");
  // Depth-first binary tree 2) In-order traversal : Left, Root, Right
  //      2(3)
  //    /      \
  //   5(1)     1(5)
  //  /   \      /    \
  // 8(0) 3(2)  9(4)   null(6)
  nodes.clear();
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_InOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);

  printf("== Depth First: Post-order ==\n");
  // Depth-first binary tree 3) Post-order traversal : Left, Right, Root
  //      null(6) ?
  //    /        \
  //   3(2)      1(5)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)   9(4)

  //      1(5)
  //    /      \
  //   3(2)      9(4)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)

  //      1(5)
  //    /      \
  //   5(1)      9(4)
  //  /   \      /   \
  //     8(0)    3(2) 2(3)

  nodes.clear();
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_PostOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
}

vector<int> traverseBTPreOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1

  // Pre-order traversal : root, left, right:  {8, 5, 2, 9, 3, 1}
  // f(x) = {root} + f(x->left) + f(x->right)
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  traversed.push_back(root->val);

  vector<int> childnodes = traverseBTPreOrder(root->left);
  traversed.insert(traversed.end(), childnodes.begin(), childnodes.end());

  childnodes = traverseBTPreOrder(root->right);
  traversed.insert(traversed.end(), childnodes.begin(), childnodes.end());

  return traversed;
}

vector<int> traverseBTInOrder(STreeNode *root) {
  // f(x) = f(x->left) + {root} + f(x->right)
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  vector<int> childnodes = traverseBTInOrder(root->left);
  traversed.insert(traversed.end(), childnodes.begin(), childnodes.end());

  traversed.push_back(root->val);

  childnodes = traverseBTInOrder(root->right);
  traversed.insert(traversed.end(), childnodes.begin(), childnodes.end());

  return traversed;
}

vector<int> traverseBTPostOrder(STreeNode *root) {
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  vector<int> childnodes = traverseBTPostOrder(root->left);
  traversed.insert(traversed.end(), childnodes.begin(), childnodes.end());

  childnodes = traverseBTPostOrder(root->right);
  traversed.insert(traversed.end(), childnodes.begin(), childnodes.end());

  traversed.push_back(root->val);
  return traversed;
}

void basic_binaryTree_traversal() {
  vector<int> vals({8, 5, 3, 2, 9, 1});

  STreeNode *root = nullptr;
  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  root = createBFTree(nodes);
  printNodes(nodes);
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1

  // Pre-order traversal : root, left, right:  {8, 5, 2, 9, 3, 1}
  // In-order traversal : left, root, right:   {2, 5, 9, 8, 1, 3}
  // Post-order traversal : left, right, root: {2, 9, 5, 1, 3, 8}

  vector<int> traversed;

  printf("== Pre-order traversal === \n");
  traversed = traverseBTPreOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  printf("== In-order traversal === \n");
  traversed = traverseBTInOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  printf("== Post-order traversal === \n");
  traversed = traverseBTPostOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");
}
vector<int> tree_to_vec(STreeNode *root) {
  vector<int> temp;
  if (!root)
    return temp;
  temp.push_back(root->val);

  vector<int> childnodes_l = tree_to_vec(root->left);
  temp.insert(temp.end(), childnodes_l.begin(), childnodes_l.end());

  vector<int> childnodes_r = tree_to_vec(root->right);
  temp.insert(temp.end(), childnodes_r.begin(), childnodes_r.end());
  return temp;
}
STreeNode *vec_to_inorder(vector<STreeNode> &nodes, int start, int end) {
  // f(x) = f(x->left | 50% remaining nodes) + {root} + f(x->right | 50%
  // remaining nodes)
  //           (0)           (1)         (2)      (3)         (4)  (5)    <==
  //           left root right
  STreeNode *root = nullptr;
  if (start == end)
    return &(nodes[start]);
  if (start + 1 == end) {
    root = &(nodes[end]);
    root->left = &(nodes[start]); // must be left
    return root;
  }

  int rootidx = start + (end - start + 1) / 2;
  root = &(nodes[rootidx]);
  root->left = vec_to_inorder(nodes, start, rootidx - 1);
  root->right = vec_to_inorder(nodes, rootidx + 1, end);
  return root;
}

void getInOrderBinaryTreeBalanced(STreeNode *tree) {

  // HW0926 : don't call existing function.
  if (!tree)
    return;
  vector<int> res = tree_to_vec(tree);
  vector<STreeNode> nodes;
  for (int i : res) {
    nodes.push_back(STreeNode(i));
  }
  int n = res.size() - 1;
  STreeNode *root = vec_to_inorder(nodes, 0, n);
  /* // HW0921
  vector<int> vals = traverseBTPreOrder(tree);

  STreeNode *root = nullptr;
  vector<STreeNode> nodes;
  for (auto &ir : vals) {
      printf("%d ", ir);
      nodes.push_back(STreeNode(ir));
  }
  // root = createBFTree(nodes);
  printf("\n");
  int startIdx = 0;
  int endIdx = nodes.size() - 1;

  root = createDFInOrderRec(nodes, startIdx, endIdx);
  */
}
void leetcode_balanced_tree() {
  vector<STreeNode> nodeData(6);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;

  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;

  //             7
  //            / \
  //           9   1
  //          / \
  //         5   4
  //             /
  //            6
  printNodes(nodeData);
  //---------------//
  STreeNode *root = &(nodeData[0]);

  // Q:  Given an unbalanced binary tree, make it in-order balanced tree.

  //      6
  //     /  \
  //   5     1
  //  / \   / \
  // 9   4 7   NULL
  getInOrderBinaryTreeBalanced(root);
  printNodes(nodeData);
}

class CRecurLeafBase {
public:
  virtual vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    printf("No implementation\n");
    return vector<vector<int>>(0);
  }
};

class CRecurLeaf : public CRecurLeafBase {
public:
  //             7
  //            / \
//           9   1
  //          / \    \
//         5   4   2
  //             /
  //            6
  //
  // Q:  Given binary tree, print out the leave values at different layers
  //   Examples: {5, 6, 2} {4, 1} {9}, {7}
  void dfs(STreeNode *root, vector<int> &result, int &count) {
    if (root == nullptr) {
      return;
    }
    // if (result.size() < depth){
    //     result.push_back({root->val});
    // }

    if (!root->left && !root->right) {
      result.push_back(root->val);
      count++;
    } else {
      dfs(root->left, result, count);
      if (count > 0) {
        // printf("%d",root->left->val);
        root->left = nullptr;
        count--;
      }

      dfs(root->right, result, count);
      if (count > 0) {
        // printf("%d",root->right->val);
        root->right = nullptr;
        count--;
      }
    }
  }
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    // HW0921
    // return vector<vector<int>>(0); // To be modified
    vector<vector<int>> res;

    int count = 0;
    while (tree->right != nullptr && tree->left != nullptr) {
      vector<int> temp(0);
      dfs(tree, temp, count);
      // printf("\n");
      res.push_back(temp);
    }
    res.push_back({tree->val});

    return res;
  }
};

class CRecurLeafVK : public CRecurLeafBase {
public:
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    printf("No implementation\n");
    return vector<vector<int>>(0);
  }
};

void leetcode_recursive_leafs() {

  //             7
  //            / \
  //           9   1
  //          /     \
  //         5       2
  //     {5, 2}, {9, 1}, {7}

  //             7
  //            / \
  //           9   1
  //          /
  //         5
  //     {5, 1}, {9}, {7}

  vector<STreeNode> nodeData(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //             7
  //            / \
  //           9   1
  //          / \    \
  //         5   4   2
  //             /
  //            6
  //

  printNodes(nodeData);

  //---------------//
  STreeNode *tree = &(nodeData[0]);

  CRecurLeaf solDerived;
  CRecurLeafVK solVK;
  CRecurLeafBase *sol = nullptr;

  int impltID = 0;

  if (impltID == 0) {
    sol = &solDerived;
  } else {
    sol = &solVK;
  }

  // Q:  Given binary tree, print out the leave values at different layers
  //   Examples: {5, 6, 2} {4, 1} {9}, {7}

  vector<vector<int>> vecOut;
  vecOut = sol->getLayeredLeaveValues(tree);
  for (auto ir : vecOut) {
    for (auto ir_t : ir) {
      printf("%d ", ir_t);
    }
    printf("\n");
  }
}

void basic_digit_manipulation() {
  // decimal:
  int a = 789; // 7*10^2 + 8*10^1 + 9;

  int b = a % 10; // get the last digit
  int c = a / 10; // pop out the last digit

  // binary representation:
  int x = 17;     // 1 0001
  int y = x & 1;  // get the last digit
  int z = x >> 1; // pop out the last digit
}

int revertInteger(int num) {
  /*
  // 10^4 ....
  // 4...

  int size = (int)log10(num)+1;
  int temp =0; //result
  for(int i=0;i<size;i++){
    //get the last digit => %10
    //put the digit to tht right position in "temp" => digit * pow(10, size-1-i)
    //digit /10
  }
  */

  // HW0921
  int temp = 0;
  int res = 0;
  while (num != 0) {
    temp = num % 10;
    res = res * 10 + temp;
    num = num / 10;
  }
  return res; // TBD
}

void leetcode_revert_integer() {
  int num = 12345;
  num = revertInteger(num);
  printf("reverted number = %d (ans : 54321)\n", num);
}

int reverseInt(int word) {
  // HW0921
  int temp = 0;
  int res = 0;
  for (int i = 0; i < 32; i++) {
    res = res << 1;
    temp = word & 1;
    res = res + temp;
    word = word >> 1;
    printf("%d\n", res);
  }
  return res;
  // return -1; // TBDF
}

void leetcode_bits_resersal() {
  // Q: reverse the 32-bit positive integer
  //  For example : integer 20
  //    0000 0000 0000 0000 0000 0000 0001 0100
  //  after reversing the 20
  //    0010 1000 0000 0000 0000 0000 0000 0000
  int word = 20;
  word = reverseInt(word);
}

int funcEvenOddDiff(int x) {
  // HW0926
  int odd = 0, even = 0, temp = 0;

  int res = 0;
  int pos = 0;
  while (x != 0) {
    if (pos % 2 == 0) {
      temp = x % 10;
      odd += temp;

    } else {
      temp = x % 10;
      even += temp;
    }
    pos++;
    x = x / 10;
  }
  res = abs(even - odd);

  return res; // TBD
}
void leetcode_even_odd_diff() {
  int X = 263541;
  //|(2+3+4) - (6+5+1)| = 3
  int diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 3)\n", diff);

  X = 131;
  // |(1+1)- 3| = 1
  diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 1)\n", diff);
}

void heapifyMaxHeap(vector<int> &vecData, int rootIdx) {
  // purpose : make sure vecData[rootIdx] >= child value

  int maxIdx = rootIdx;
  // compare with left
  int childIdx = 2 * rootIdx + 1;
  if (childIdx < vecData.size()) {
    if (vecData[childIdx] > vecData[maxIdx]) {
      maxIdx = childIdx;
    }
  }

  // compare with right
  childIdx = 2 * rootIdx + 2;
  if (childIdx < vecData.size()) {
    if (vecData[childIdx] > vecData[maxIdx]) {
      maxIdx = childIdx;
    }
  }
  // if maxIdx ! = rootIdx
  if (maxIdx != rootIdx) {
    // swap root and child
    int tmp = vecData[maxIdx];
    vecData[maxIdx] = vecData[rootIdx];
    vecData[rootIdx] = tmp;

    heapifyMaxHeap(vecData, maxIdx);
  }
}

void buildMaxHeap(vector<int> &vecData) {
  //      5(0)             d = 0  2^0
  //      /    \
  //    4(1)    1(2)       d = 1  2^0 + 2^1
  //   /   \      /   \
  //  9(3)  2(4)  3(5)      d = 2  2^0 + 2^1 + 2^2

  int maxDepthNo = (int)log2((double)vecData.size());
  printf("maxDepthNo=%d\n", maxDepthNo);
  int maxTestNodes = 0;
  // O(logN)
  for (int d = 0; d <= maxDepthNo - 1; d++) {

    // pow(2, d)
    int num = 1;
    for (int n = 0; n < d; n++)
      num *= 2;
    printf("d=%d => num = %d\n", d, num);
    maxTestNodes += num;
  }
  printf("maxTestNodes = %d\n", maxTestNodes);
  // O(NlogN)
  for (int i = maxTestNodes - 1; i >= 0; i--) // N
  {
    heapifyMaxHeap(vecData, i); // logN
  }
}

void basic_heapify() {
  vector<int> vecData({5, 4, 1, 9, 2, 3});
  //      5(0)
  //      /    \
  //    4(1)    1(2)
  //   /   \      /   \
  //  9(3)  2(4)  3(5)

  printf("== input data ==\n");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");

  // Def: Max heap:  parent value >= any child value

  //--- build max/min heap  ---//
  buildMaxHeap(vecData);

  // heapify a "non-heapified" data : O(NlogN)
  // heapify a "semi-heapified" data : O(logN)
}

void basic_heap_sort() {
  vector<int> vecData({5, 4, 1, 9, 2, 3});

  printf("== input data ==\n");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");

  vector<int> sortedVec;

  // build max heap
  // while
  //   extract the max from the top => output to sorted vector
  //   move one of the node from bottom to root
  //   heapify again
  //
  buildMaxHeap(vecData);

  printf("max heap: ");
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");

  while (1) {
    // general
    int tmp = vecData.front();
    vecData.front() = vecData.back();
    vecData.back() = tmp;

    // max is the last element in vector
    sortedVec.push_back(vecData.back());

    // ascending: sortedVec.insert(sortedVec.begin(), vecData.begin(),
    // vecData.begin()+1);

    // vecData.front() == vecData[0]
    //  For example:  vecData[0]= -1 <==> vecData.front() = -1
    //  vector<int>::iterator <== .begin type

    vecData.pop_back();

    // if(vecData.size() == 0)
    if (vecData.empty())
      break;

    heapifyMaxHeap(vecData, 0); // O(logN)

    // ending condition
  }

  printf("== heap sorted data == \n");
  for (auto &ir : sortedVec) {
    printf("%d ", ir);
  }
  printf("\n");
}
void heapifyminHeap(vector<int> &vecData, int rootIdx) {
  // purpose : make sure vecData[rootIdx] <= child value
  int minIdx = rootIdx;
  // compare with left
  int childidx = 2 * rootIdx + 1;
  if (childidx < vecData.size()) {
    if (vecData[childidx] < vecData[minIdx]) {
      minIdx = childidx;
    }
  }
  // compare with right
  childidx = 2 * rootIdx + 2;
  if (childidx < vecData.size()) {
    if (vecData[childidx] < vecData[minIdx]) {
      minIdx = childidx;
    }
  }
  // if maxIdx ! = rootIdx
  // swap root and child
  if (minIdx != rootIdx) {
    int temp = vecData[minIdx];
    vecData[minIdx] = vecData[rootIdx];
    vecData[rootIdx] = temp;

    heapifyminHeap(vecData, minIdx);
  }
}
void buildminHeap(vector<int> &vecData) {
  //      5(0)             d = 0  2^0
  //      /    \
  //    4(1)    1(2)       d = 1  2^0 + 2^1
  //   /   \      /   \
  //  9(3)  2(4)  3(5)      d = 2  2^0 + 2^1 + 2^2

  int maxDepthNo = (int)log2((double)vecData.size()); // maxDepthNo = 2 ,d=0,d=1

  int maxTestNodes = 0;
  // O(logN)
  for (int d = 0; d <= maxDepthNo - 1; d++) {

    // pow(2, d) => pow(2,0)+pow(2,1)
    int num = 1;
    for (int n = 0; n < d; n++) {
      num *= 2;
    }

    maxTestNodes += num;
    // maxTestNodes 計算出所有非葉子節點的數量（這些節點需要 heapify 操作）
  }
  printf("maxTestNodes = %d\n", maxTestNodes);
  // O(NlogN)
  for (int i = maxTestNodes - 1; i >= 0; i--) // N
  {
    heapifyminHeap(vecData, i); // logN
    for (auto &ir : vecData) {
      printf("%d ", ir);
    }
    printf("\n");
    //所以從點2開始往回測到點0
  }
}

int funcFindKthMinFromArray(vector<int> vecData, int k) {
  // build a min heap
  // extract number till K times

  // HW1001
  //       5(0)             d = 0  2^0
  //        /    \
  //    4(1)    1(2)       d = 1  2^0 + 2^1
  //     /   \      /   \
  //  9(3)  2(4)  3(5)      d = 2  2^0 + 2^1 + 2^2

  // time complexity : O(NlogN)
  printf("== input data ==\n");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");

  vector<int> sortedVec;
  buildminHeap(vecData); // O(NlogN)

  // O(KlogN)
  for (int i = 0; i <= k; i++) {

    sortedVec.push_back(vecData.front());
    for (auto &ir : sortedVec) {
      printf("%d ", ir);
    }
    printf("\n");

    vecData.erase(vecData.begin());
    printf("-vecData size = %d\n", (int)vecData.size());
    // if(vecData.size() == 0)
    if (vecData.empty())
      break;

    vecData.insert(vecData.begin(), vecData.back());
    vecData.erase(vecData.end());

    heapifyminHeap(vecData, 0); // O(logN)
  }
  return sortedVec[k];
  //-------------------------------------------------------
  // int maxDepthNo = (int)log2((double)vecData.size());
  // int maxTestNodes = 0;

  // for (int d = 0; d < maxDepthNo; d++) { // maxDepthNo = 2 ,d=0,d=1
  //   int num = 1;
  //   for (int n = 0; n < d; n++) {
  //     num = num * 2;
  //   }
  //   maxTestNodes = maxTestNodes + num;
  // }
  // // maxTestNodes=3
  // for (int i = 0; i <= k; i++) {

  //   for (int i = maxTestNodes; i >= 0; i--) {
  //     heapifyminHeap(vecData, i);
  //     for (auto &ir : vecData) {
  //       printf("%d ", ir);
  //     }
  //     printf("\n");
  //   }
  //   printf("------\n");
  //   if (i != k) {
  //     int n = vecData.size() - 1;
  //     swap(vecData[0], vecData[n]);
  //     vecData.pop_back();
  //   }
  // }
  // for (auto &ir : vecData) {
  //   printf("%d ", ir);
  // }
  // printf("\n");
  // return vecData[0];
  //-------------------------------------------------------
}
void leetcode_bt_findKthMin() {
  // Given any array/vector, find the K-min number.
  // NOTE: please build a min heap first and take maximum O(NlogN) complexity
  vector<int> vecData({5, 4, 1, 9, 2, 3}); //{1, 2, 3, 4, 5, 9}
  printf("input= { ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("}\n");

  int k = 3;
  int kthMin = funcFindKthMinFromArray(vecData, k);
  printf("%d-min is %d\n\n", k, kthMin);
}

int pivotPartition(vector<int> &data, int startIdx, int endIdx) {
  // Step 1: {smaller elements}  {pivot} {greater elements}
  // Step 2: swap pivot and the last element in "greater elements"
  //{5, 2, 6, 1, 8, 3, 6, 9, 4}
  //                          ^^
  //  ------> forwardidx , continue if encountering element < pivot
  //                  <------| backwardidx, continue if encoutering element >=
  //                  pivot

  int pivotIdx = endIdx;
  int forwardIdx = startIdx;
  int backwardIdx = pivotIdx - 1;
  while (forwardIdx <= backwardIdx) {
    bool isForwarding = false;
    bool isBackwarding = false;
    // forward idx : if element < pivot, forwardIdx ++ ; otherwise, stuck
    if (data[forwardIdx] < data[pivotIdx]) {
      forwardIdx++;
      isForwarding = true;
    }

    // backward idx : if element >= pivot, backwardIdx ++; otherwise, stuck
    if (data[backwardIdx] >= data[pivotIdx]) {
      backwardIdx--;
      isBackwarding = true;
    }

    // if both stuck, swap backward-idx element and forward-idx elemetn,
    // continue
    if (!isForwarding && !isBackwarding) // TBD
    {
      // swap
      int tmp = data[forwardIdx];
      data[forwardIdx] = data[backwardIdx];
      data[backwardIdx] = tmp;
      forwardIdx++;
      backwardIdx--;
    }
    // ending condition
    //  if(forwardIdx > backwardIdx){
    //    break;
    //  }
  }

  printf("forwardIdx %d\n", forwardIdx);
  printf("backwardIdx %d\n", backwardIdx);

  printf("after pivot before swap: ");
  for (auto &ir : data)
    printf("%d ", ir);
  printf("\n");

  // pivot idx , forward idx
  int tmp = data[forwardIdx];
  data[forwardIdx] = data[pivotIdx];
  data[pivotIdx] = tmp;

  printf("final: ");
  for (auto &ir : data)
    printf("%d ", ir);
  printf("\n");

  return forwardIdx;
}

void basic_pivot_partitioning() {
  // ideal pivot : midium value
  // practical pivot : take the first or the last (practical)
  //  {smaller elements} {pivot} {greater elements}
  //     2, 3, 1             4      5, 6, 8, 9
  vector<int> vecData({5, 2, 6, 1, 8, 3, 6, 9, 4}); //{1, 2, 3, 4, 5, 6, 8, 9}

  pivotPartition(vecData, 0, vecData.size() - 1);
}

void quickSort(vector<int> &inVec, int startIdx, int endIdx) {
  // f(x) = f(Y | y < pivot) + {pivot| last element} + f(Z | z >= pivot)
  // exception
  if (startIdx >= endIdx)
    return;

  // general

  // piviot parition
  int pivotIdx = pivotPartition(inVec, startIdx, endIdx);

  // smaller
  quickSort(inVec, startIdx, pivotIdx - 1);

  // greater
  quickSort(inVec, pivotIdx + 1, endIdx);
}

void basic_quickSort() {

  // time complexity :
  //        best case : O(NlogN)
  //        worst case : O(N^2)
  // space complexity : O(N)
  //
  // scenario : limited hardware resource  +  limited data size
  vector<int> inVec({7, 0, 2, 8, 5});
  printf("== unsorted ==\n");
  for (auto &ir : inVec) {
    printf("%d ", ir);
  }
  printf("\n");

  // f(x) = f(Y | y < pivot) + {pivot| last element} + f(Z | z >= pivot)
  int startIdx = 0;
  int endIdx = inVec.size() - 1;
  quickSort(inVec, startIdx, endIdx);

  printf("== sorted ==\n");
  for (auto &ir : inVec) {
    printf("%d ", ir);
  }
  printf("\n");
}

vector<int> mergeSortedList(vector<int> a, vector<int> b) {
  // vector<int> a({1, 5, 7, 9});
  // vector<int> b({2, 3, 6, 10, 12});
  vector<int> c; //{1, 2, 3, 5, 6, 7, 9, 10, 12}

  while (!a.empty() || !b.empty()) {
    // select the vector with minimum front() => s
    vector<int> *s;
    if (!a.empty() && !b.empty())
      s = (a.front() < b.front()) ? (&a) : (&b);
    else if (!a.empty())
      s = &a;
    else
      s = &b;

    // push back s.front() to c, s.front() pop out
    c.push_back(s->front());
    s->erase(s->begin());
  }
  return c;
}

vector<int> mergeSort(vector<int> inVec, int startIdx, int endIdx) {
  // f(X0, X1) = f ( f(X00, X01),  f(X10, X11) )
  vector<int> merged;

  // HW1004

  // exception
#if 0
  if (startIdx + 1 == endIdx) {
    vector<int> merged_a;
    vector<int> merged_b;
    merged_a.push_back(inVec[startIdx]);
    merged_b.push_back(inVec[endIdx]);
    merged = mergeSortedList(merged_a, merged_b);

    return merged;
  }
  if (startIdx = endIdx)
  {
    merged.push_back(inVec[startIdx]);
    return merged;
  }
#else
  if (startIdx == endIdx) {
    merged.push_back(inVec[startIdx]);
    return merged;
  }
#endif

  // general
  // find the middle point, midIdx
  int midIdx = (endIdx - startIdx + 1) / 2 + startIdx - 1;
  vector<int> leftData = mergeSort(inVec, startIdx, midIdx);
  vector<int> rightData = mergeSort(inVec, midIdx + 1, endIdx);
  merged = mergeSortedList(leftData, rightData);

  return merged;
}

void basic_mergeSort() {
  vector<int> inVec({1, 6, 2, 9, 3, 7, 2, 0, 2, 8, 5});
  // {sorted list}
  // {sorted list 1}                            {sorted list 2}
  // {sorted list 1-1} {sorted list 1-2}        {sorted list 2-1} {sorted list
  // 2-2}
  //....
  // {1} {6}
  printf("== unsorted ==\n");
  for (auto &ir : inVec) {
    printf("%d ", ir);
  }
  printf("\n");

  // f(X0, X1) = f ( f(X00, X01),  f(X10, X11) )
  inVec = mergeSort(inVec, 0, inVec.size() - 1);

  printf("== sorted ==\n");
  for (auto &ir : inVec) {
    printf("%d ", ir);
  }
  printf("\n");

  //                 Quick sort        Merge sort
  // compleixty      O(NlogN)          O(NlogN)
  // worse-case      O(N^2)            O(NlogN)
  // memory          in-place (less)   not-in-place (more)
  // Use case        small-array       large-array
  //                 hardware          software general case
}

class CVehicle {
public:
  CVehicle() { type = "Vehicle"; }
  virtual void getGasFee() {
    printf("%s: gas fee = %d\n", type.c_str(), price);
  }
  virtual int getNumTires() { return 0; }

  // private:
protected: // considered as "private" within "family"
  string type;
  int price;
};

class CBus : public CVehicle {
public:
  CBus() {
    type = "Bus";
    price = 500;
  }
  void getGasFee() { printf("%s: gas fee = %d\n", type.c_str(), price); }
  int getNumTires() { return 6; }
};

class CSportCar : public CVehicle {
public:
  CSportCar() {
    type = "SportCar";
    price = 300;
  }
  void getGasFee() { printf("%s: gas fee = %d\n", type.c_str(), price); }
  int getNumTires() { return 4; }
};

void basic_class_usage() {
  // inheritance
  // {
  //   CBus *myBus = new CBus;
  //   myBus->getGasFee();
  //   printf("num tires : %d\n", myBus->getNumTires());

  //   CSportCar *mySportCar = new CSportCar;
  //   mySportCar->getGasFee();
  //   printf("num tires : %d\n", mySportCar->getNumTires());

  //   delete myBus;
  //   delete mySportCar;
  // }

  // polynomial : 多型 / 多態
  CBus objBus;
  CSportCar objSportCar;

  CVehicle *obj;
  obj = &objBus;

  obj->getGasFee();
  printf("num tires : %d\n", obj->getNumTires());

  obj = &objSportCar;
  obj->getGasFee();
  printf("num tires : %d\n", obj->getNumTires());
}

class CSolDistanceKInBTBase {
public:
  virtual vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    return vector<int>();
  }
};

class CSolDistanceKinBT : public CSolDistanceKInBTBase {
public:
  bool downnode(STreeNode *node, STreeNode *target, vector<int> &out) {
    if (!node)
      return false;

    out.push_back(node->val);
    if (node->val == target->val) {
      out.pop_back();
      return true;
    }

    bool right_judge = downnode(node->right, target, out);
    if (!right_judge && out.size() > 1) {
      out.pop_back();
      return false;
    }
    bool left_judge = downnode(node->left, target, out);
    if (!left_judge && out.size() > 1) {
      out.pop_back();
      return false;
    }
    return true;
  }

  void dp(STreeNode *root, vector<int> &out, int k) {
    if (!root)
      return;

    if (k == 0) {
      out.push_back(root->val);
      return;
    }

    dp(root->right, out, k - 1);
    dp(root->left, out, k - 1);
  }
  vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    // 1.把整條root->target的路徑都寫入out內->downnode
    // 2.1找到target再往下找k
    // 2.2沿著剛剛out往上找k 碰到root為止 再從root往另一條路找k-size()

    vector<int> down{root->val};
    vector<int> res;
    bool right_res = downnode(root->right, target, down);
    bool left_res = downnode(root->left, target, down);
    if (right_res) {
      dp(target, res, k);
      int temp = k - down.size() - 1;
      dp(root->left, res, temp);
    }
    if (left_res) {
      dp(target, res, k);
      int temp = k - down.size() - 1;
      dp(root->right, res, temp);
    }
    return res;
  }
};

class CSolDistanceKinBTVK : public CSolDistanceKInBTBase {
public:
  vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    // TBD
    return vector<int>();
  }
};

void leetcode_bt_distanceK() {

  // HW1010

  CSolDistanceKinBT objDerived;
  CSolDistanceKinBTVK objVK;
  CSolDistanceKInBTBase *obj;

  enum _IMPLT_ID {
    IMPLT_SOPHIA = 0,
    IMPLT_VK,
  };

  int impltID = IMPLT_SOPHIA;
  if (impltID == IMPLT_SOPHIA) {
    obj = &objDerived;
  } else {
    obj = &objVK;
  }

  int k;
  vector<int> kVals;

  STreeNode *root = nullptr;
  STreeNode *target = nullptr;
  vector<STreeNode> nodeData;
  printf("-- case 0 --\n");
  nodeData.clear();
  nodeData.resize(4);
  nodeData[0].val = 0;
  nodeData[1].val = 1;
  nodeData[2].val = 3;
  nodeData[3].val = 2;
  nodeData[0].left = &(nodeData[1]);
  nodeData[1].left = &(nodeData[2]);
  nodeData[1].right = &(nodeData[3]);
  root = &(nodeData[0]);
  target = &(nodeData[3]);

  printNodes(nodeData);

  //      0
  //     / \      //
  //   1
  //  / \         //
  //  3  2
  //     ^ target

  k = 1;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [1]\n");

  printf("-- case 1 --\n");
  nodeData.clear();
  nodeData.resize(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //              7 (0)
  //            /      \
  //           9 (1)    1 (2)
  //          / \         /  \
  //       5(3)  4 (4)  null   2(6)
  //             /
  //            6 (5)
  printNodes(nodeData);

  root = &(nodeData[0]);
  target = &(nodeData[1]);
  k = 2;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [6 1]\n");
}

class CFuncParsingBase {
public:
  virtual int solveFunctions(string paramStr) { return -1; }
};

class CFuncParsingGreedy : public CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // 𝑓(𝑥) = 2𝑥 – 3
    // 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
    // ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧
    // input string = "h f 5 g 3 4 3"
    vector<string> paramList;

    string oneStr;
    for (auto &ir : paramStr) {
      if (ir == ' ') {
        paramList.push_back(oneStr);
        oneStr.clear();
      } else {
        oneStr.push_back(ir);
      }
    }
    paramList.push_back(oneStr);

    return greedySolvFunc(paramList);
  }

private:
  int greedySolvFunc(vector<string> paramList) {
    int res = -1;

    while (paramList.size() > 1) {
      auto it = prev(paramList.end());
      // find "function idenfier"
      while (isdigit(it->back())) {
        it--;
      }

      char f = it->front();
      // merge parameters
      if (f == 'f') {
        // 𝑓(𝑥) = 2𝑥 – 3
        auto x = it + 1;
        *it = to_string(2 * stoi(*x) - 3);
        paramList.erase(x);
      } else if (f == 'g') {
        // 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
        auto x = it + 1;
        auto y = x + 1;
        *it = to_string(2 * stoi(*x) + stoi(*y) - 7);

        paramList.erase(y);
        paramList.erase(x);
      } else // h
      {
        // ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧
        auto x = it + 1;
        auto y = x + 1;
        auto z = y + 1;

        *it = to_string(3 * stoi(*x) - 2 * stoi(*y) + stoi(*z));
        paramList.erase(z);
        paramList.erase(y);
        paramList.erase(x);
      }

      // look backward
      it--;

      // ending condition
      //  if(paramList.size()==1)
      //    break;
    }

    res = stoi(paramList.front());

    return res;
  }
};

class CFuncParsingRecur : public CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // 𝑓(𝑥) = 2𝑥 – 3
    // 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
    // ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧
    // input string = "h f 5 g 3 4 3"
    vector<string> paramList;

    string oneStr;
    for (auto &ir : paramStr) {
      if (ir == ' ') {
        paramList.push_back(oneStr);
        oneStr.clear();
      } else {
        oneStr.push_back(ir);
      }
    }
    paramList.push_back(oneStr);

    return recSolvFunc(paramList);
  }

private:
  int recSolvFunc(vector<string> &paramList) {

    int res = -1;

    // HW1013
    //  exception
    if (isdigit(paramList.front().back())) {
      int oneParam = stoi(paramList.front());
      paramList.erase(paramList.begin());
      return oneParam;
    }

    // general

    // get the function identifier
    char f = paramList.front().front();
    paramList.erase(paramList.begin());

    int num = -1;
    if (f == 'f') {
      num = 1;
    } else if (f == 'g') {
      num = 2;
    } else // h
    {
      num = 3;
    }

    // -> number of recursive call
    vector<int> funcParams;
    for (int i = 0; i < num; i++) {
      int param = recSolvFunc(paramList);
      funcParams.push_back(param);
    }

    // apply parameters to function
    //  input : funcParams
    //  output : res

    // HW1026 use "function" instead of "number of parameters"
    if (f == 'f') {
      res = 2 * funcParams.front() - 3;
    } else if (f == 'g') {
      res = 2 * funcParams[0] + funcParams[1] - 7;
    } else if (f == 'h') {
      res = 3 * funcParams[0] - 2 * funcParams[1] + funcParams[2];
    } else {
      res = -1;
    }

    return res;
  }
};

class CFuncParsing : public CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // HW1010
    //新建string 把所有f計算後的值 都重新寫入新string
    //新建string 把所有g計算後的值都重新寫入string
    string t1, t2;
    int res = 0;
    for (int i = 0; i < paramStr.length(); i++) {
      if (paramStr[i] == 'f') {
        int temp1 = (paramStr[i + 2] - '0') * 2 - 3;
        t1.push_back(temp1 + '0');
        i = i + 3;
      } else if (paramStr[i] != ' ') {
        t1.push_back(paramStr[i]);
      }
    }
    for (int i = 0; i < t1.length(); i++) {
      if (t1[i] == 'g') {
        int temp1 = (t1[i + 1] - '0') * 2 + (t1[i + 2] - '0') - 7;
        t2.push_back(temp1 + '0');
        i = i + 2;
      } else {
        t2.push_back(t1[i]);
      }
    }

    res = (t2[1] - '0') * 3 - 2 * (t2[2] - '0') + (t2[3] - '0');

    return res;
  }
};

void leetcode_functionParsing() {
  // 𝑓(𝑥) = 2𝑥 – 3
  // 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
  // ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧

  //
  //
  // input string = {h f 5 g 3 4 3}, "space" is inserted between two consecutive
  // parameters, ℎ(𝑓(5), 𝑔(3, 4), 3) = ℎ(7, 3, 3) = 18
  //
  //

  enum _IMPLT_ID {
    IMPLT_GREEDY = 0,
    IMPLT_RECURSIVE,
  };

  CFuncParsingBase *sol = nullptr;
  CFuncParsingGreedy solGreedy;
  CFuncParsingRecur solRecur;

  // CFuncParsing solDerived;
  // sol = &solDerived;
  int impltID = IMPLT_GREEDY;
  if (impltID == IMPLT_GREEDY) {
    sol = &solGreedy;
  } else {
    sol = &solRecur;
  }

  string inStr = "h f 5 g 3 4 3";
  int res = sol->solveFunctions(inStr);
  printf("%d (ans = 18)\n", res);
}

class CSolPermuteBase {
public:
  virtual int permute(vector<int> &nums) {
    printf("need implementation\n");
    return -1;
  }
};

class CSolPermuteSophia : public CSolPermuteBase {
public:
  int permute(vector<int> &nums) {
    // TBD
    return -1;
  }
};

class CSolPermute : public CSolPermuteBase {
public:
  void dp(vector<int> nums, vector<int> end_vec, int &res,
          unordered_map<string, int> &inMap) {
    //變動 固定 現在第幾個
    string st;
    if (nums.size() == 1) {
      for (auto i : end_vec) {

        st = st + to_string(i);
        st = st + '-';
      }

      st = st + to_string(nums.front());
      if (!inMap.count(st)) {
        res = res + 1;
        inMap[st] = res;
      }
      return;
    }
    // if剩最後2個要回傳vector 給前面的寫map

    for (int i = 0; i < nums.size(); ++i) {
      vector<int> temp = nums;
      end_vec.push_back(temp[i]); //固定的最後數寫入vector
      if (nums.size() > 1) {
        temp.erase(temp.begin() + i);
      }

      dp(temp, end_vec, res, inMap); //組合都寫入unordermap
      end_vec.pop_back();
    }
  }

  void rec(vector<int> &path, vector<int> &vis, int &res, vector<int> &nums) {
    if (path.size() == nums.size()) {
      res++;
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!vis[i]) {
        vis[i] = 1;
        path.push_back(nums[i]);
        rec(path, vis, res, nums);
        vis[i] = 0;
        path.pop_back();
      }
    }
  }

  int permute(vector<int> &nums) {
    // HW1013
    int res = 0;
    vector<int> temp;
    unordered_map<string, int> inMap;
    dp(nums, temp, res, inMap);
    // vector<int> path;
    // vector<int> vis(nums.size());
    // rec(path, vis, res, nums);

    return res;
  }
};

#define CONSIDER_REPEATETD 1
#if CONSIDER_REPEATETD
#define PERMUTE_MEMO 1
#endif

class CSolPermuteVK : public CSolPermuteBase {
public:
#if CONSIDER_REPEATETD
  int permute(vector<int> &nums) {
    permutedRes.clear();
    return permute(nums, vector<int>(0));
  }

private:
  int permute(vector<int> &nums, vector<int> fixed)
#else
  int permute(vector<int> &nums)
#endif
  {
    // f({a, b, c, d, e}) = f( {b, c, d, e} | a)
    //                    + f( {a, c, d, e} | b)
    //                    ....
    //                    + f ( {a, b, c, d} |e)
    //                      ^^^^^^^^^^^^^^^^^^^^
    //              f({b, c, d} | {a, e} ) +.......
    //           .. f({} | {e, a, b, c, d})

    //  {a, b, c}  =>   {a, b | c}  ,   {a, c} , {b, c}
    //                 {a |b} , {b}   {a}  {c}  {b} {c}
    //                {}     {}    {}    {}  {}   {}
    //

    int sum = 0;
    // exception
    if (nums.empty()) {
#if CONSIDER_REPEATETD && !PERMUTE_MEMO
      if (permutedRes.find(getHashKey(fixed)) == permutedRes.end()) {
        permutedRes.insert(getHashKey(fixed));
        sum = 1;
      }

      return sum;
#else
      return 1;
#endif
    }

    // general
    for (int i = 0; i < nums.size(); i++) {
      int cached = nums[i];
      nums.erase(nums.begin() + i);
#if CONSIDER_REPEATETD
      fixed.push_back(cached);

#if PERMUTE_MEMO
      string permuteKey = getHashKey(fixed) + getHashKey(nums);
      if (permutedRes.find(permuteKey) == permutedRes.end()) {
#endif
        sum += permute(nums, fixed);
#if PERMUTE_MEMO
        permutedRes.insert(permuteKey);
      }
#endif
      fixed.pop_back();
#else
      sum += permute(nums);
#endif

      nums.insert(nums.begin() + i, cached);
    }
    return sum;
  }
#if CONSIDER_REPEATETD
private:
  string getHashKey(vector<int> nums) {
    stringstream ss;
    for (int i = 0; i < nums.size(); i++) {
      ss << nums[i] << "_";
    }
    // "1_1_2_3_"
    return ss.str();
  }

private:
  unordered_set<string> permutedRes;
#endif
};

void leetcode_permuteData() {
  // https://leetcode.com/problems/permutations/description/

  CSolPermute obj;
  CSolPermuteVK objVK;
  CSolPermuteSophia objSophia;

  enum _IMPLT_ID { IMPLT_SOPHIA = 0, IMPLT_VK };

  CSolPermuteBase *sol;

  int impltID = IMPLT_SOPHIA;
  if (impltID == IMPLT_SOPHIA) {
    // sol = &obj;
    sol = &objSophia;
  } else {
    sol = &objVK;
  }

  vector<int> in;
  // f({a, b, c, d, e}) = f( {b, c, d, e} | a)
  //                    + f( {a, c, d, e} | b)
  //                    ....
  //                    + f ( {a, b, c, d} |e)
  //                      ^^^^^^^^^^^^^^^^^^^^
  //              f({b, c, d} | {e, a}) +.......
  //           .. f({} | {e, a, b, c, d})
  //  exception case:  when nothing can be permuted, just return 1;
  //
  //
  // f({1, 1, 2}) => backtracking + memo
  //                                key : "1-1-2"

  // v0: backtracking
  // v1: (backtracking + repeated case) <== initial implementation
  // v2: (backtracking + repeated case) + memorization

  //-- non-repeated case --
  // time complexity O(M * N! )

  //-- repeated case --
  // time complexity O(N * N!/(A! B! ....)  )

  // -- extension --
  // P(N,N) -> P(N, K) (?)
  // C(N,K) (?)

  in = {1, 2, 3}; // 3!
  printf("num = %d (ans: 6)\n", sol->permute(in));

  in = {1, 1, 2, 3}; // 4! / 2!
  printf("num = %d (ans: 12)\n", sol->permute(in));

  in = {1, 1, 2, 2, 3, 3}; // 6! / (2! 2! 2!)
  printf("num = %d (ans: 90)\n", sol->permute(in));
}

class CPrefixScoreBase {
public:
  virtual vector<int> sumPrefixScores(vector<string> &words) {
    vector<int> scores;
    printf("need a implementation");
    return scores;
  }
};

class CPrefixScoreLUT : public CPrefixScoreBase {
public:
  vector<int> sumPrefixScores(vector<string> &words) {
    // "abc","ab","bc","b"
    unordered_map<string, int> prefixMemo;

    // find all prefix(es)
    for (auto word : words) {
      while (!word.empty()) {
        prefixMemo[word] = 0;
        word.pop_back();
      }
    }

    // abc, ab, a, bc, b
    //  1    2  2  1   2

    // find the # of appearances of each prefix
    for (auto word : words) {
      // abc -> abc, ab, a = 1+2+2 = 5
      // ab -> ab, a = 2+2 = 4
      // bc -> bc, b = 1+2 = 3
      // b  -> b = 2

      while (!word.empty()) {
        prefixMemo[word]++;
        word.pop_back();
      }
    }

    // sum up the # of apperances for each word
    vector<int> scores;
    for (auto word : words) {
      int sum = 0;
      while (!word.empty()) {
        sum += prefixMemo[word];
        word.pop_back();
      }
      scores.push_back(sum);
    }

    return scores;
  }
};

class CPrefixScore : public CPrefixScoreBase {
  class TrieNode {
  public:
    unordered_map<char, TrieNode *> children;
    int val;

    TrieNode(int x) : val(0) {}
  };

public:
  vector<int> sumPrefixScores(vector<string> &words) {
    vector<int> scores;
    // HW1026
    TrieNode *root = new TrieNode(0);
    for (auto word : words) {
      TrieNode *node = root;
      for (auto ch : word) {
        if (!node->children.count(ch)) {
          node->children[ch] = new TrieNode(0);
        }
        node = node->children[ch];
        node->val += 1; // 每次經過此節點，增加計數
      }
    }
    for (auto word : words) {
      TrieNode *node = root;
      int score = 0;
      for (auto ch : word) {
        if (!node->children.count(ch)) {
          break;
        }
        node = node->children[ch];
        // cout<<node->val<<endl;
        score = score + node->val;
      }
      scores.push_back(score);
    }
    return scores;
  }
};

void leetcode_prefix_score() {
  /*

  https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

  You are given an array words of size n consisting of non-empty strings.

  We define the score of a string word as the number of strings words[i]
  such that word is a prefix of words[i].

  For example, if words = ["a", "ab", "abc", "cab"],
  then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
  Return an array answer of size n
  where answer[i] is the sum of scores of every non-empty prefix of words[i].

  Note that a string is considered as a prefix of itself.


  Example 1:

  Input: words = ["abc","ab","bc","b"]
  Output: [5,4,3,2]
  Explanation: The answer for each string is the following:

  - "abc" has 3 prefixes: "a", "ab", and "abc".
  - There are 2 strings with the prefix "a", 2 strings with the prefix "ab",
  and 1 string with the prefix "abc".
  The total is answer[0] = 2 + 2 + 1 = 5.

  - "ab" has 2 prefixes: "a" and "ab".
  - There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
  The total is answer[1] = 2 + 2 = 4.

  - "bc" has 2 prefixes: "b" and "bc".
  - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
  The total is answer[2] = 2 + 1 = 3.

  - "b" has 1 prefix: "b".
  - There are 2 strings with the prefix "b".
  The total is answer[3] = 2.

  Example 2:

  Input: words = ["abcd"]
  Output: [4]
  Explanation:
  "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
  Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.


  Constraints:

  1 <= words.length <= 1000
  1 <= words[i].length <= 1000
  words[i] consists of lowercase English letters.
  */

  CPrefixScore objDerived;
  CPrefixScoreLUT objLUT;
  CPrefixScoreBase *obj = nullptr;

  //
  // Linked list <-> LUT / Hash table
  //
  enum IMPLT_ID_ {
    IMPLT_DERIVED = 0, // O(NM) (Linked list)
    IMPLT_LUT,         // O(MN) (LUT)
  };

  int impltID = IMPLT_LUT;

  if (impltID == IMPLT_DERIVED) {
    obj = &objDerived;
  } else if (impltID == IMPLT_LUT) {
    obj = &objLUT;
  } else {
    printf("not a supported implementation\n");
    exit(-1);
  }

  vector<int> scores;

  vector<string> words;
  words.push_back("abc");
  words.push_back("ab");
  words.push_back("bc");
  words.push_back("b");

  scores = obj->sumPrefixScores(words);
  for (auto &ir : scores)
    printf("%d, ", ir);
  printf("\n");
  printf("ans : 5, 4, 3, 2\n");
}