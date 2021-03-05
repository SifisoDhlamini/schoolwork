#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double km {};
    double hrs {};
    
    cin>>km>>hrs;
    
    double velocity {};
    velocity = km/hrs;
    
    cout<<fixed<<setprecision(6);
    cout<<velocity<<endl;       
    
	return 0;
}