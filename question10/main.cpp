#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
	string word;
    cin>>word;
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    reverse(word.begin(), word.end());
    cout<<word;
    cout<<endl;
    
	return 0;
}
