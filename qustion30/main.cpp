#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int find(vector<string> x, string l){
    for (size_t i = 0; i < x.size(); i++){
        if(x[i] == l){
            return i;
        }
    }
    return -1;
}

int find(vector<char> x, char l){
    
    for (size_t i = 0; i < x.size(); i++){
        if(x[i] == l){
            return i;
        }
    }
    return -1;
}

int main()
{
    char c;
    string m, word;
    vector <char> charac;
    vector <string> cmors;
    
    //collect characters and save with corresponding mors
    while (cin >> c && c != '*')
    {
        charac.push_back(c);
        cin >> m;
        cmors.push_back(m);        
    }

    vector<vector<string>> words;
    vector <string> str1;
    vector <string> smors;
    
    
    //collect words and save with corresponding mors
    while (cin >> word && word != "*")
    {
        m.clear();
        str1.push_back(word);
        for(char letter: word){
            int index = find(charac, letter);
            m += cmors.at(index);
        }
        smors.push_back(m);
    }
    words.push_back(str1);
    words.push_back(smors);
        
    //collect code
    vector <string> morscode;
    while (cin >> m && m != "*"){
        morscode.push_back(m);
    }
    for(auto code: morscode){
        string s = code;
        int index = find(words.at(1), s);
        if(index != -1){
            int found = 1;
            for(size_t i = index + 1; i < words.at(1).size(); i++){
                if(words.at(1).at(i) == s){
                    found++;
                }
            }
             if(found > 1){
               cout<<words.at(0).at(index)<<'!'<<endl;    
            } else {
                cout<<words.at(0).at(index)<<endl;
            }
        } else {
            //vector<string>::iterator location;
            bool found = false;
            while(!found){
                for(size_t i = 0; i < words.at(1).size(); i++){
                    string str2 = words.at(1).at(i);
                    if(s.length() <= str2.length() && str2.compare(0, s.size(), s) == 0){ 
                        found = true; 
                        index = i;
                        break;
                    }                
                }
                s.pop_back();
            }
            cout<<words.at(0).at(index)<<'?'<<endl;
        }       
    }       

    return 0;
}