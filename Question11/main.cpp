#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int term1;
    int tolerance;
    int items;
    
    cin>>term1>>tolerance>>items;
    
    for(int i {0}; i < items; i++){
        cout<<"a["<<i+1<<"]="<<term1+(tolerance*i)<< '\n';
    }
    
	return 0;
}



