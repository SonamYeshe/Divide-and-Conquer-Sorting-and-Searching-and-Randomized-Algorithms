#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <lib.hpp>
using namespace std;


int Count(int array, int length) {
  int numInv = 0;
  if (length == 0)
    return 0;
  else {

  }
}

int main()
{
  vector<string> arr;
  string::size_type sz;  // alias of size_t
  string line;
  ifstream myfile("IntegerArray.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      arr.push_back(line);
    }
    myfile.close();
  }
  else
    cout << "Unable to open file";

  int curInt;
  int curIntLength;
  vector<int> numInvVec;
  for (int i = 0; i < arr.size(); ++i) {
    curInt = stoi(arr[i], &sz);
    curIntLength = to_string(curInt).length();
    //cout << curInt << '\n' << curIntLength << '\n';
}

  // cout << arr[0][5] << '\n';

  //int i = stoi(arr[0], &sz);
  //cout << to_string(i).length() << '\n';

  // int i = stoi(line, &sz);
  // cout << to_string(i).length();
//  dummy();
  return 0;
}
