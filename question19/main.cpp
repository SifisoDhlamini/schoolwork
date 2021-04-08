#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>

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
    
    int getDigit() const{
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
            //if there is more than 1 saved Digit and it starts with 0  
            while(not_string[counter] - '0' == 0){
                counter++;
            }
            if(counter > 1 || not_string[counter] - '0' != 0){
                while(isdigit(not_string[counter])){
                    number[arrCounter].setDigit(not_string[counter] - '0');
                    counter++;
                    arrCounter++;
                }
            }
            
        } else if((not_string[0] == '+' || not_string[0] == '-') && isdigit(not_string[1])){
            //move one up
            counter = 1;
            //if there is more than 1 saved Digit and it starts with 0  
             while(not_string[counter] - '0' == 0){
                counter++;
            } 
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
        if(arrCounter > 0){
            for(int i = 0;i < arrCounter; i++){
                cout<<number[i].getDigit();
            }   
        } else {
            cout<<0;
        }
             
    } 
    
    int getSize() const{return arrCounter;}

    IntNumber *add(const IntNumber *otherLargeInt) const{
        vector <int> num;
        int remainder = 0;
        int counter = 1;
        
        //get size of each largeInt
        int size1 = otherLargeInt->getSize();
        int size2 = this->getSize();
        
        //create temp arrays for addition purposes
        Digit temp1[size1];
        Digit temp2[size2];
        
        //check if negative for passed in Digit array
        if(otherLargeInt->number[0].getDigit()< 0){
            temp1[0].setDigit(otherLargeInt->number[0].getDigit());
            for(int i = 1; i < size1;i++){
                temp1[i].setDigit(otherLargeInt->number[i].getDigit()*(-1));
            }
        } else {
            for(int i = 0; i < size1;i++){
                temp1[i].setDigit(otherLargeInt->number[i].getDigit());
            }
        }
        //check if negative for local Digit array
        if(this->number[0].getDigit() < 0){
            temp2[0].setDigit(this->number[0].getDigit());
            for(int i = 1; i < size2;i++){
                temp2[i].setDigit(this->number[i].getDigit()*(-1));
            }
        } else {
            for(int i = 0; i < size2;i++){
                temp2[i].setDigit(this->number[i].getDigit());
            }
        }
        
        if(size1 >= size2){
            while(counter <= size2){
                int val1 = temp1[size1 - counter].getDigit();
                int val2 = temp2[size2 - counter].getDigit();
                int sum = val1 + val2 + remainder;
                if(sum >= 10){
                    remainder = 1;
                    num.push_back(sum - 10); 
                } else if(sum <= (-10)){
                    remainder = -1;
                    num.push_back(sum  + 10);
                } else {
                    remainder = 0;
                    num.push_back(sum);
                }   
                counter++;
            } 
            while(counter <= size1){
                int val1 = temp1[size1 - counter].getDigit();
                int sum = val1+remainder;
                if(sum >= 10){
                    remainder = 1;
                    num.push_back(sum <= 0 && sum > -10); 
                } else if(sum < (-10)){
                    remainder = -1;
                    num.push_back(sum  + 10);                    
                } else {
                    remainder = 0;
                    num.push_back(sum);
                } 
                counter++;
            }
            if(remainder !=0){
                num.push_back(remainder);
            }
            counter = 1;
        } else {
            while(counter <= size1){
                int val1 = temp1[size1 - counter].getDigit();
                int val2 = temp2[size2 - counter].getDigit();
                int sum = val2 + val1 + remainder;
                if(sum >= 10){
                    remainder = 1;
                    num.push_back(sum - 10); 
                } else if(sum <= (-10)){
                    remainder = -1;
                    num.push_back(sum  + 10);
                } else {
                    remainder = 0;
                    num.push_back(sum);
                }   
                counter++;
            } 
            while(counter <= size2){
                int val2 = temp2[size2 - counter].getDigit();
                int sum = val2+remainder;
                if(sum >= 10){
                    remainder = 1;
                    num.push_back(sum - 10); 
                } else if(sum <= (-10)){
                    remainder = -1;
                    num.push_back(sum  + 10);                    
                } else {
                    remainder = 0;
                    num.push_back(sum);
                } 
                counter++;
            }
            if(remainder != 0){
                num.push_back(remainder);
            }
            counter = 1;
        }

        //save vector integers in to character array to pass as parameter to IntLargeNumber constructor
        
        int vecSize = num.size();        
        reverse(num.begin(), num.end());
        while(num.at(0) == 0 && vecSize > 1){
            num.erase(num.begin());
            vecSize--;
        }
        char newNum[vecSize + 2];
        if(vecSize > 1 && num.at(0) > 0){
            for(int i = 0; i < vecSize; i++){
                if((i > 0) && (num.at(i) < 0)){
                    num.at(i - 1)-= 1;
                    num.at(i)+=10;
                    newNum[i - 1] = '0' + num.at(i - 1);
                }
                newNum[i] = '0' + num.at(i);
            } 
           newNum[vecSize] ='\0';
        } else if(vecSize > 1 && num.at(0) < 0){
            int insertPos = 0;
            newNum[insertPos] = '-';
            insertPos++;
            for(int i = 0; i < vecSize; i++){
                if((i > 0) && (num.at(i) < 0)){
                    num.at(i - 1)-= 1;
                    num.at(i)+=10;
                    newNum[insertPos - 1] = '0' + num.at(i - 1);
                }
                newNum[insertPos] = '0' + abs(num.at(i));
                insertPos++;
            }
            newNum[insertPos] ='\0';
        } else {
            if (num.at(0) >= 0){
                newNum[0] = '0' + num.at(0);
                newNum[1] = '\0';
            } else {
                newNum[0] = '-';
                newNum[1] = '0' + abs(num.at(0));
                newNum[2] = '\0'; 
            }            
        }
        
        char copyN[1000];
        int copyCount = 0;
        while(newNum[copyCount] != '\0'){
            copyN[copyCount] = newNum[copyCount];
            copyCount++;
        }
            
        
        IntNumber *newNumber = new IntNumber(copyN);       
        return newNumber;                
    }
};

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
