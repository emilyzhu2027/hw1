#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    //TESTCASE1
    ULListStr list;
    for(int count = 0; count < 4; ++count)
    {
      list.push_back("test");
      list.pop_back();
    }
    for(int count = 0; count < 4; ++count)
    {
      list.push_front("test");
      list.pop_front();
    }

    //TESTCASE2
    ULListStr dat;
    dat.push_back("7");
    dat.push_back("9");
    dat.push_back("10");
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    cout << dat.size() << endl;

    dat.pop_front();
    cout << dat.get(0) << " " << dat.get(1) << endl;
    cout << dat.front() << endl;
    cout << dat.size() << endl;

    //TESTCASE3
    ULListStr dat2;
    dat2.push_front("8");
    dat2.push_front("9");
    cout << dat2.get(0) << " " << dat2.get(1) << endl;
    cout << dat2.size() << endl;

    dat2.pop_back(); 
    cout << dat2.get(0)<< endl;
    cout << dat2.back() << endl;
    cout << dat2.size() << endl;
}
