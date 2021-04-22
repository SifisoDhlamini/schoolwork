#include<iostream>
using namespace std;

class Encode
{
    string toEncode;
public:
    Encode(string s): toEncode{s} {}

    string encode(){
        string temp = "00";
        string temp1 ="0";
        string encoded;
        for(auto c: toEncode){
            if(int(c) < 10){
               encoded+= temp + to_string(int(c));
            } else if(int(c) < 100) {
                encoded+= temp1 +  to_string(int(c));
            } else {
              encoded+=to_string(int(c));
            }
        }
        return encoded;
    }
};
int main() {
  string str;
  getline(cin, str);
  Encode *code = new Encode(str);
  cout<<code->encode();
  return 0;
}
