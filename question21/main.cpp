#include <iostream>
#include <string>

using namespace std;

class Decode
{
private:
    string encoded;
public:
    Decode(string s){
        encoded = s;
    }
    
    string decode(){
        string d = "";        
        for(size_t i = 0; i < encoded.length(); i+=3){
            int temp = 0;
            for(size_t j = i; j < (i + 3); j++){
                temp = temp * 10 + encoded[j] - '0';
            }
            d += char(temp);
        }
        return d;       
    }
};
int main() {
    string str;
    cin>>str;
    Decode *code = new Decode(str);
    cout<<code->decode();
    return 0;
}
