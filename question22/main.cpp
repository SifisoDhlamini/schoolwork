#include <iostream>
using namespace std;


class Fraction
{
private:
    int denominator;
    int numerator;
public:

    Fraction(): Fraction(0,0){
        
    }
    
    Fraction(int numerator, int denominator){
        this->denominator = denominator;
        this->numerator = numerator;
    }
    
    int getNumerator(){ return numerator; }
    
    int getDenominator(){ return denominator; }
    
    void setNumerator(int n){
        numerator = n;
    }
    
    void setDenominator(int d){
        denominator = d;
    }
    
    void display(){
        int cFactor = 0;
        for(int i = 2; i <= denominator; i++){
            if(denominator % i == 0 && numerator % i == 0){
                cFactor = i;
            }
        }
        
        if(cFactor > 0){
            denominator/=cFactor;
            numerator/=cFactor;
        }
        
        if(denominator == 0 || numerator == 0){
            cout<<'('<<0<<')';
        } else if(denominator == 1){
            cout<<'('<<numerator<<')';
        } else {
            cout<<'('<<numerator<<'/'<<denominator<<')';
        }
    }    
};

int main(int argc, char **argv)
{
//    Fraction a, b, c, d, e, f;
//
//    a = (((b + c) - d) * e) / f;
//    a.display();
    
    
	Fraction f1(2,4);
    Fraction f2(5,9);
    Fraction f3(12,4);
    Fraction f4(1/3);
    Fraction f5(3/4);
    Fraction f6(0,5);
    Fraction f7(5,0);
    
    f4.setNumerator(4);
    f4.setDenominator(1);
    
    f1.display();
    cout<<endl;
    f2.display();
    cout<<endl;
    f3.display();
    cout<<endl;
    f4.display();
    cout<<endl;  
    f5.display();
    cout<<endl; 
    f6.display();
    cout<<endl;
    f7.display();
    cout<<endl;

    Fraction a;
    a = (((f1 +f2) - f3) * f4)/f5);
    a.display();
    cout<<endl;
    
    
	return 0;
}


