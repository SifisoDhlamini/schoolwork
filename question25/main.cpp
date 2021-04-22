#include <iostream>
#include <algorithm>
using namespace std;

class Fraction
{
private:
    int denominator, numerator;
public:
    Fraction(){ denominator, numerator = 0; }    
    Fraction(int num, int den): numerator(num), denominator(den){}    
    int getNumerator() const{ return numerator; }    
    int getDenominator() const{ return denominator; }    
    void setNumerator(int n){ numerator = n; }    
    void setDenominator(int d){ denominator = d; }
    
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
    
    friend ostream& operator <<(ostream& outputStream, const Fraction& fraction);
    
    Fraction operator !(){
        Fraction tempFraction;    
        tempFraction.numerator = this->getDenominator();
        tempFraction.denominator = this->getNumerator();
        return tempFraction;
    }
};

ostream& operator <<(ostream& outputStream, const Fraction& f){
    int numer = f.getNumerator();
    int denom = f.getDenominator();
    int cD = __gcd(numer, denom);
    if(denom == 0){
        outputStream<<'('<<0<<')';
    } else {            
        numer /= cD;
        denom /= cD;
        if(denom == 1){
            outputStream<<'('<<numer<<')';
        } else {
            
            outputStream<<'('<<numer<<'/'<<denom<<')';
        }
    }
    
    return outputStream;
}