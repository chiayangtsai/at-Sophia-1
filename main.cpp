#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

// google cplusplus.com

#include "includes.h"

using namespace std;

int main(int argc, char **argv) {

  int testID = 30;
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
  case 22: // binary tree
    basic_binary_tree();
    break;
  case 30: // binary tree - creation - Breath first / level first
    basic_binaryTree_creation_breathFirst();
    break;
  case 31: // binary tree - creation - depth first
    basic_binaryTree_creation_depthFirst();
    break;
  default:
    printf("not a supproted ID : %d\n", testID);
    exit(-1);
  }

  //-- middle --
  // binay tree basic (definition, balanced, complete)
  // - find BT leaves
  // binary tree creation and traversals
  // - find layer of leaves
  // - balanced tree
  // - find target and k-distance nodes

  //-- expereinced --
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
    // HW0830
    vector<int> leafs;
    
    //excetion/base
    // when both children are null pointers

    // general case
    // get vectors from left tree
    // get vector from right tree

    return leafs;
  }
};

class CFindLeafsVK : public CFindLeafsBase {
public:
  vector<int> findLeafs(STreeNode *root) {
    // TBD
    return vector<int>(0);
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

  int impltID = 0;

  if (impltID == 0) {
    sol = &solDerived;
  } else if (impltID == 1) {
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

STreeNode* createBFTree(vector<STreeNode>& nodes){

  //METHOD 0: index 0 -> last index (connect child nodes)
  //METHOD 1: index 1 -> last index (connect parenet nodes)
  for(int i=1; i< nodes.size(); i++){
    if(i%2){
      int parentIdx = (i-1)/2;
      nodes[parentIdx].left = &(nodes[i]);
    }
    else{
      int parentIdx = (i-2)/2;
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
  for(auto & ir : vals){
    nodes.push_back( STreeNode(ir));
  }
  
  STreeNode* root = createBFTree(nodes);
  printf("root : %d\n", root->val);
  printNodes(nodes);
}

void basic_binaryTree_creation_depthFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});
  vector<STreeNode> nodes;
  // STreeNode *root = nullptr;
}