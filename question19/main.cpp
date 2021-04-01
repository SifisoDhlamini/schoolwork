#include <iostream>
#include <ctype.h>

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
    
    //member getters and setters
    void setDigit(int d){
        if(d >= -9 && d <= 9){
            digit = d;            
        } else{
            digit = 0;
        }
    }
    
    int getDigit(){
        return digit;
    }
};

class IntNumber
{
private:
    Digit number[1000];
    int arrCounter = 0;
    bool positive = true;
public:
    //constructors
    IntNumber(){
        number[0].setDigit(0);
    }
    
    IntNumber(char *not_string){
        int counter = 0;
        
        if(isdigit(not_string[0])){
            //number = stoll(not_string);            
            while(isdigit(not_string[counter])){
                number[arrCounter].setDigit(not_string[counter] - '0');
                counter++;
                arrCounter++;
            }
        } else if((not_string[0] == '+' || not_string[0] == '-') && isdigit(not_string[1])){
            //move one up
            counter = 1;
            //set first number to negative if need be
            if(not_string[0] == '-'){
                number[arrCounter].setDigit(-1 * (not_string[counter] - '0'));
                counter++;
                arrCounter++;
            } 
            
            while(isdigit(not_string[counter])){
                number[arrCounter] = not_string[counter] - '0';
                counter++;
                arrCounter++;
            }
        } else {
            number[0].setDigit(not_string[0]);
            arrCounter++;
        }        
    }
    
    void display(){
        int i = 0;
        //if there is more than 1 saved Digit and it starts with 0
        if(arrCounter > 1){
            while(number[i].getDigit() == 0){
                i++;
            }  
        }        
        
        //print
        for(;i < arrCounter; i++){
            cout<<number[i].getDigit();
        }
        cout<<endl;        
    } 

    IntNumber *add(const IntNumber *n) const;
    
};

IntNumber *IntNumber::add(const IntNumber *n) const{
    
    return nullptr;
}

int main()
{
  char num1[10000], num2[10000];
  cin>>num1>>num2;
  IntNumber *number1 = new IntNumber(num1);
  IntNumber *number2 = new IntNumber(num2);
  number1->display();
  cout<<endl;
  number2->display();
  cout<<endl;
  number1->add(number2)->display();
  cout<<endl;
  number2->add(number1)->display();
  return 0;
}
