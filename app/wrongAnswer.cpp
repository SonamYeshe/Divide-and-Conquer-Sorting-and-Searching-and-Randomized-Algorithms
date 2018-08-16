#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include <lib.hpp>
using namespace std;

struct Foo {
  string sortedArr;
  int numInv;
};

Foo CountSplitInv(string sortedLeftArr, string sortedRightArr) {
  Foo res;
  res.numInv = 0;
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
        res.sortedArr.append(sortedRightArr.substr(k));
        break;
      }
    } else {
      res.sortedArr.push_back(sortedRightArr[k]);
      if (k < sortedRightArrLength - 1) {
        ++k;
      } else {
        res.sortedArr.append(sortedLeftArr.substr(j));
        res.numInv = res.numInv + sortedLeftArrLength - j;
        break;
      }
      res.numInv = res.numInv + sortedLeftArrLength - j;
    }
  }
  //cout << res.numInv << '\n';
  //cout << res.sortedArr;
  return res;
}

Foo Count(string array, int length) {
  Foo res;
  res.numInv = 0;
  if (length == 1) {
    res = {array, 0};
    return res;
  }
  else {
    //string::size_type sz;  // alias of size_t

    string arrayLeft = array.substr(0, length / 2);
    Foo res1 = Count(arrayLeft, arrayLeft.length());
    //int intLeft = stoi(arrayLeft, &sz);
    //int lengthLeft = to_string(intLeft).length();
    //Foo resLeft = Count(arrayLeft, lengthLeft);

    string arrayRight = array.substr(length / 2);
    Foo res2 = Count(arrayRight, arrayRight.length());
    //int intRight = stoi(arrayRight, &sz);
    //int lengthRight = to_string(intRight).length();
    //Foo resRight = Count(arrayRight, lengthRight);

    Foo res3 = CountSplitInv(res1.sortedArr, res2.sortedArr);

    res.sortedArr = res3.sortedArr;
    res.numInv = res.numInv + res1.numInv + res2.numInv + res3.numInv;
  }
  //cout << res.numInv << '\n';
  //cout << res.sortedArr << '\n';
  return res;
}

int main() {
  vector<string> arr;
  string::size_type sz;  // alias of size_t
  string line;
  ifstream myfile("IntegerArray.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      arr.push_back(line);
    }
    myfile.close();
  } else
    cout << "Unable to open file";

  int curInt;
  int curIntLength;
  string curIntArr;
  vector<int> numInvVec;
  for (int i = 0; i < arr.size(); ++i) {
    curInt = stoi(arr[i], &sz);
    curIntLength = to_string(curInt).length();
    curIntArr = to_string(curInt);
    //cout << curIntArr << '\n';
    //cout << curIntLength << '\n';
    Foo res = Count(curIntArr, curIntLength);
    numInvVec.push_back(res.numInv);
    //cout << numInvVec.back() << '\n';
  }
  int finalRes = accumulate(numInvVec.begin(), numInvVec.end(), 0);
  cout << finalRes;
  //  dummy();
  return 0;
}
