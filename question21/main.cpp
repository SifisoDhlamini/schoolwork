#include <iostream>
#include <string>

class Decode
{
public:
    string decoded;
    Decode(string s): decoded(s){}
    string decode(){
        string dec;
        for(size_t i = 0; i < decoded.length(); i+=3){
            int temp = 0;
                for(size_t j = i; j < i+3; j++){
                    temp = temp * 10 + decoded[j] - '0';
                }
            dec+= char(temp);
        }

        return dec;
    }
};
int main() {
  string str;
  cin>>str;
  Decode *code = new Decode(str);
  cout<<code->decode();
  return 0;
}
