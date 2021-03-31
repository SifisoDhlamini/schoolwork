#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char **argv)
{
    string S1;
    string S2;
    cin>>S1;
    cout<<S1<<endl;
    cin.ignore(1000, '\n');
    getline(cin, S2, '?');
    cout<<S2<<endl;
    
	return 0;
}
