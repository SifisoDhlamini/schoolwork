#include<iostream>

using namespace std;

class Digit
{
private:
    int digit;
public:
    Digit(): digit(0){}
    Digit(int d){
        setDigit(d);
    }
    int getDigit(){return digit; }
    void setDigit(int d) {digit = (d < -9 || d > 9)? 0: d;}

};
class IntNumber
{
private:
    Digit number[1000];
    char * s_num;
    int count;
public:
    IntNumber(){
       s_num[0] = '0';
       number[0] = 0;
    }
    IntNumber(char *p){
        s_num = p;
        count = 0;
        long long int temp = stoll(s_num);
        string tempNum = to_string(temp);
        if(isdigit(tempNum[0])){
            for(auto dig: tempNum){
                number[count] = dig - '0';
                count++;
            }
        } else {
            string temp  = tempNum.substr(0,2);
            number[0] = stoi(temp);
            count++;
            for(size_t i = 2; i < tempNum.length(); i++){
                number[count] = tempNum[i] - '0';
                count++;
            }
        }
    }

    void display(){
        for(int i = 0; i < count;i++){
            cout<<number[i].getDigit();
        }
    }

    char *getNumber(){ return s_num;};

    IntNumber *add(IntNumber *p) const{
        long long int num1 = stoll(s_num) + stoll(p -> getNumber());
        string num2 = to_string(num1);
        char *num3 = &num2[0];
        return new IntNumber(num3);
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