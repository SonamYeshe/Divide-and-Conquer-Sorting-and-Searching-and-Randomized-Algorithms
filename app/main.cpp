#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include <lib.hpp>
using namespace std;

struct Foo {
  vector<int> sortedArr;
  unsigned int numInv;
};

Foo CountSplitInv(vector<int> sortedLeftArr, vector<int> sortedRightArr) {
  Foo res;
  res.numInv = 0;
  res.sortedArr = {};
  int sortedLeftArrLength = sortedLeftArr.size();
  int sortedRightArrLength = sortedRightArr.size();
  int j = 0;
  int k = 0;
  for (int i = 0; i < (sortedLeftArrLength + sortedRightArrLength); ++i) {
    if (sortedLeftArr[j] <= sortedRightArr[k]) {
      res.sortedArr.push_back(sortedLeftArr[j]);
      if (j < sortedLeftArrLength - 1) {
        ++j;
      } else {
        res.sortedArr.insert(res.sortedArr.end(), sortedRightArr.begin() + k,
                             sortedRightArr.end());
        break;
      }
    } else {
      res.sortedArr.push_back(sortedRightArr[k]);
      if (k < sortedRightArrLength - 1) {
        ++k;
      } else {
        res.sortedArr.insert(res.sortedArr.end(), sortedLeftArr.begin() + j,
                             sortedLeftArr.end());
        res.numInv = res.numInv + sortedLeftArrLength - j;
        break;
      }
      res.numInv = res.numInv + sortedLeftArrLength - j;
    }
  }
  return res;
}

Foo Count(vector<int> array, int length) {
  Foo res;
  res.numInv = 0;
  if (length == 1) {
    res = {array, 0};
    return res;
  }
  else {
    vector<int> arrayLeft;
    arrayLeft.assign(array.begin(), array.begin() + length / 2);
    Foo res1 = Count(arrayLeft, arrayLeft.size());

    vector<int> arrayRight;
    arrayRight.assign(array.begin() + length / 2, array.end());
    Foo res2 = Count(arrayRight, arrayRight.size());

    Foo res3 = CountSplitInv(res1.sortedArr, res2.sortedArr);

    res.sortedArr = res3.sortedArr;
    res.numInv = res.numInv + res1.numInv + res2.numInv + res3.numInv;
  }
  return res;
}

int main()
{
  vector<int> arr;
  string::size_type sz;  // alias of size_t
  string line;
  ifstream myfile("IntegerArray.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      arr.push_back(stoi(line, &sz));
    }
    myfile.close();
  }
  else
    cout << "Unable to open file";

  int arrSize = arr.size();
  Foo finalRes = Count(arr, arrSize);
  cout << finalRes.numInv;
  //  dummy();
  return 0;
}






































