#include <iostream>
#include "longint.h"

using namespace std;

//Use to test longint.cpp
/*
Values entered in to test
a: 0000000098765425hjgjhghjghj
b: -00000000225114hjgjhghjghj
c: 54654gfh321gh654fg8h7
d: -kjhdskjfhsdkjfhsdjkfhskjdfhsdkjfh0
*/
int main( ) {

LongInt a;
LongInt b;
LongInt c;
LongInt d;

cout << "enter for a: ";
cin >> a;
cout << "enter for b: ";
cin >> b;
cout << "enter for c: ";
cin >> c;
cout << "enter for d: ";
cin >> d;

cout << "a = " << a << endl;
cout << "b = " << b << endl;
cout << "c = " << c << endl;
cout << "d = " << d << endl;


cout<<"a - c = "<<a-c<<endl;
cout<<"d-d = "<<d-d<<endl;
cout<<"c-d = "<<c-d<<endl;
cout<<"d-c = "<<d-c<<endl;

cout<<"d==d Result: "<<(d==d)<<endl;
cout<<"d!=d Result: "<<(d!=d)<<endl;

cout<<"(c-d)>(d-c) Result: "<<((c-d)>(d-c))<<endl;
cout<<"(c-d)<(d-c) Result: "<<((c-d)<(d-c))<<endl;
d = a-c;
cout<<"d =(a-c) Result: "<<d<<endl;
cout<<"d == (a-c) Result: "<<(d == (a-c))<<endl;
cout<<"d <= b Result: "<<(d<=b)<<endl;
cout<<"(d-(a-c)) >= (b+b) :"<<(d-(a-c))<<" >= "<<(b+b)<<" Result: "<<((d-(a-c)) >= (b+b))<<endl;



}