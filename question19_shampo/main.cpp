class Digit
{
  int _data;
  public:
  void setDigit(int val) { _data = (0 <= val && val <= 9)? val: 0; }
  int getDigit() const { return _data; }
  Digit(int val = 0) { setDigit(val); }
};

#include <string>
#include <cctype>
#include <iostream>

class IntNumber
{
private: // utilities
    void normalize() {
        while (len > 0 && digits[len-1].getDigit() == 0)
            --len;
        if (len == 0)
            negative = false;
    }

    bool largerThan(const IntNumber *num) const {
        if (len != num->len)
            return (len > num->len);
        for (int i = len - 1; i >= 0; --i) {
            if (digits[i].getDigit() != num->digits[i].getDigit())
                return (digits[i].getDigit() > num->digits[i].getDigit());
        }
        return false;
    }
public:
    IntNumber(): len(0), negative(false) {}
    IntNumber(const std::string &str): len(0), negative(false) {
        int idx = 0;
        while (idx < str.length() && isspace(str[idx]))
            idx++;
        while (idx < str.length() && (str[idx] == '+' || str[idx] == '-')) {
            if (str[idx] == '-')
                negative = (negative)? false: true;
            idx++;
        }
        while (idx < str.length() && isdigit(str[idx])) {
            len++;
            idx++;
        }
        for (int i = 0 ; i < len; ++i)
            digits[i].setDigit(str[--idx] - '0');
        normalize();
    }

    void display() const {
        if (negative) std::cout << "-";
        if (len == 0) std::cout << 0;
        for (int i = len - 1; i >= 0; --i)
            std::cout << digits[i].getDigit();
    }

    IntNumber* add(const IntNumber *num) const {
        if (num->largerThan(this))
            return num->add(this);
        IntNumber* res = new IntNumber(*this);
        if (res->negative == num->negative) {
            int carry = 0, i;
            for (i = 0; i < num->len; ++i) {
                carry += res->digits[i].getDigit() + num->digits[i].getDigit();
                res->digits[i].setDigit(carry % 10);
                carry /= 10;
            }
            while (carry > 0 && i < res->len) {
                carry += res->digits[i].getDigit();
                res->digits[i].setDigit(carry % 10);
                carry /= 10;
                ++i;
            }
            if (carry)
                res->digits[res->len++].setDigit(carry);
        } else {
            for (int i = num->len - 1; i >= 0; --i) {
                int sum = res->digits[i].getDigit() - num->digits[i].getDigit();
                if (sum < 0) {
                    sum += 10;
                    int j = i+1;
                    while (res->digits[j].getDigit() == 0) {
                        res->digits[j].setDigit(9);
                        ++j;
                    }
                    res->digits[j].setDigit(res->digits[j].getDigit() - 1);
                }
                res->digits[i].setDigit(sum);
            }
            res->normalize();
        }
        return res;
    }
private:
    bool negative;
    int len;
    Digit digits[1000];
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