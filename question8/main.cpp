#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	int num1 {};
    int num2 {};
    
    cin>>num1>>num2;
    
    cout<<num1<<"+"<<num2<<"="<<num1 + num2<<endl;
    cout<<num1<<"-"<<num2<<"="<<num1 - num2<<endl;
    cout<<num1<<"*"<<num2<<"="<<num1 * num2<<endl;
    cout<<fixed<<setprecision(4);
    cout<<num1<<"/"<<num2<<"="<<static_cast<double>(num1) / num2<<endl;
    cout<<num1<<"%"<<num2<<"="<<num1 % num2<<endl;
    
	return 0;
}