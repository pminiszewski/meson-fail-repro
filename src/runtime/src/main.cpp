#include<iostream>
 
using namespace std;

#include "hello.pb.h"

int main()
{ 
    meson::repro::TestProto test;
    test.set_foo("hello!");

    cout << test.foo();
     
    return 0;
}