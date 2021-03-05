#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int number {};
    
    cin>>number;
    
    if(number % 2 == 0){
        cout<<number<<endl;
    } else {
        cout<<number - 1<<endl;
    }
    
	return 0;
}
