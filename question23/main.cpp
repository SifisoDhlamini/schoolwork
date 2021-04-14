#include <iostream>
#include <algorithm>

using namespace std;

class Fraction
{
private:
    int denominator;
    int numerator;
public:
    Fraction(){
        denominator = 0;
        numerator = 0;
    }
    
    Fraction(int numerator, int denominator){
        this->denominator = denominator;
        this->numerator = numerator;
    }
    
    int getNumerator() const{ return numerator; }
    
    int getDenominator() const{ return denominator; }
    
    void setNumerator(int n){
        numerator = n;
    }
    
    void setDenominator(int d){
        denominator = d;
    }
    
    void display(){ 
        int numer = numerator;
        int denom = denominator;
        int cD = __gcd(numer, denom);
        if(denom == 0){
            cout<<'('<<0<<')';
        } else {            
            numer /= cD;
            denom /= cD;
            if(denom == 1){
                cout<<'('<<numer<<')';
            } else {
                
                cout<<'('<<numer<<'/'<<denom<<')';
            }
        }
    } 
    
    //operator overloaders declaration
    void operator =(const Fraction& fraction1){
        denominator = fraction1.denominator;
        numerator = fraction1.numerator;
    }
    Fraction operator +(const Fraction& fraction1){
        Fraction tempFraction;
        tempFraction.numerator = (fraction1.getNumerator() * denominator) + (numerator * fraction1.getDenominator());
        tempFraction.denominator = fraction1.getDenominator() * denominator;
        return tempFraction;
    }
    Fraction operator -(const Fraction& fraction1){
        Fraction tempFraction;
        tempFraction.numerator = (numerator * fraction1.getDenominator())  - (fraction1.getNumerator() * denominator);
        tempFraction.denominator = fraction1.getDenominator() * denominator;
        return tempFraction;
    }
    Fraction operator *(const Fraction& fraction1){
        Fraction tempFraction;    
        tempFraction.numerator = numerator * fraction1.getNumerator();
        tempFraction.denominator = denominator * fraction1.getDenominator();
        return tempFraction;
    }
    
    Fraction operator /(const Fraction& fraction1){
        Fraction tempFraction;    
        tempFraction.numerator = numerator * fraction1.getDenominator();
        tempFraction.denominator = denominator * fraction1.getNumerator();
        return tempFraction;
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
    Fraction f4(1,3);
    Fraction f5(3,4);
    Fraction f6(0,5);
    Fraction f7(5,0);
    
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
    a = ((((f1 + f2) - f3) * f4)/f5);
    cout<<"Overloaded Fraction: ";
    a.display();
    cout<<endl;
    
    
	return 0;
}


