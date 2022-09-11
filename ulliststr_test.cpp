/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  // test case 1
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

  // test case 2
  ULListStr LList;
  LList.push_back("1");
  LList.push_back("4");
  LList.push_front("3");
  LList.push_back("7");
  cout << LList.get(0) << " " << LList.get(1) << " " << LList.get(2) << " " << LList.get(3) << endl;
  cout << LList.size() << endl; // print 4
  // prints: 3 1 4 7
  LList.pop_back();
  cout << LList.get(0) << " " << LList.get(1) << " " << LList.get(2) << endl;
  // prints: 3 1 4
  cout << LList.size() << endl;
  // print: 3
  LList.pop_front();
  cout << LList.get(0) << " " << LList.get(1) << endl;
  // print: 1 4
  LList.clear();
  cout << LList.size() << endl;
  // print: 0
  return 0;
}
