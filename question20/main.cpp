#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Encode
{
private:
    string decoded;
public:
    Encode(string s){
        decoded = s;
    }
    
    string encode(){
        string e = "";
        
        for(size_t i = 0; i < decoded.length(); i++){
            if(int(decoded[i]) < 10){
                e = e + "00" + to_string(int(decoded[i]));
            } else if(int(decoded[i]) < 100){
                e = e + "0" + to_string(int(decoded[i]));
            } else {
                e = e + to_string(int(decoded[i]));
            }
        }
        return e;        
    }
    
    
};
int main() {
  string str;
  getline(cin, str);
  Encode *code = new Encode(str);
  cout<<code->encode();
  return 0;
}
