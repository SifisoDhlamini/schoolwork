#include<iostream>
#include<algorithm>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(){
        this ->numerator=0;
        this ->denominator=0;
    }
    Fraction(int numerator, int denominator){

        this->setNumerator(numerator);
        this->setDenominator(denominator);

    }
    int getNumerator()const{
        return numerator;
    }
    int getDenominator()const{
        return denominator;
    }
    void setNumerator(int _numerator){
        this ->numerator = _numerator;
    }
     void setDenominator(int _denominator){
        this->denominator = _denominator;
    }
    void display(){
        int _a = getNumerator();
        int _b = getDenominator();
        int hcf = __gcd(_a, _b);
        if(_b==0){
            return;
        }
        if(_a!=0){
             _a = _a/hcf;
            _b = _b/hcf;

        }
        if (_b==1){
            cout << _a;
        }
        else
        {
            cout << "(" << _a << "/" << _b << ")";
        }
    }

    Fraction operator +(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.denominator + example1.numerator * getDenominator();
        fracAnswer.denominator = getDenominator() * example1.denominator;
        return fracAnswer;
        }

    Fraction operator -(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.denominator - example1.numerator * getDenominator();
        fracAnswer.denominator = getDenominator() * example1.denominator;
        return fracAnswer;
        }
    Fraction operator *(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.numerator;
        fracAnswer.denominator = getDenominator() * example1.denominator;
        return fracAnswer;
        }
    Fraction operator /(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.denominator;
        fracAnswer.denominator = getDenominator()* example1.numerator;
        return fracAnswer;
        }
    void operator =(const Fraction& example1){
        numerator = example1.numerator;
        denominator = example1.denominator;
        }

};

int main(){

//    Fraction a;
//    Fraction b = Fraction(5,2);
//    Fraction c = Fraction(1,3);
//    Fraction d = Fraction(5,6);
//    Fraction e = Fraction(3,2);
//    Fraction f = Fraction(4,7);
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


return 0;
}
