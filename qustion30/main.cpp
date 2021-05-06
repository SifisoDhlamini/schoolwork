// not my code

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string c, m, word;
    vector<vector<string>> mc;
    vector <string> charac;
    vector <string> cmors;
    
    //collect characters and save with corresponding mors
    while (cin >> c && c != "*")
    {
        charac.push_back(c);
        cin >> m;
        cmors.push_back(m);        
    }
    mc.push_back(charac);
    mc.push_back(cmors)
    vector<vector<string>> words;
    vector <string> str1;
    vector <string> smors;
    
    //collect words and save with corresponding mors
    while (cin >> word && word != "*")
    {
        m.clear()
        str1.push_back(word);
        for(auto letter: word){
            auto index = find(cmors.at(0).begin(), cmors.at(0).end(), letter);
            m+=mc.at(1).at(index);
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
        auto index = find(mc.at(1).begin(), mc.at(1).begin(),
        
    }
        

    return 0;
}