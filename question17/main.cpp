#include <iostream>

using namespace std;

class Digit
{
private:
    int digit;
public:
    
    //Constructors
    Digit(): Digit(0){
        
    }
    
    Digit(int d){
        setDigit(d);
    }
    
    void setDigit(int d){
        if(d >= 0 && d <= 9){
            digit = d;            
        } else{
            digit = 0;
        }
    }
    
    int getDigit(){
        return digit;
    }
};

int main(int argc, char **argv)
{
	int c;
    cin>>c;
    Digit digit2;
    digit2.setDigit(c);
    Digit digit4(80);
    
    cout<<digit2.getDigit()<<endl;
    cout<<digit4.getDigit()<<endl;
    
	return 0;
}
