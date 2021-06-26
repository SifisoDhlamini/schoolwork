#include <iostream>
#include <vector>

using namespace std;

//search template to find index of parameter
template<class T>
int find(vector<T> x, T l){
    
    for (size_t i = 0; i < x.size(); i++){
        if(x[i] == l){
            return i;
        }
    }
    return -1;
}

int main()
{
    char c;//to save character entered
    string m, word;// to save mors code and word entered
    vector <char> charac;// to save vector of characters (Used vector to capitalize on inbuilt functions)
    vector <string> cmors;// vector to save string of mors cors as a collective
    
    //collect characters and save with corresponding mors while not a star/asterix
    while (cin >> c && c != '*')
    {
        charac.push_back(c);//append carrector to char vector
        cin >> m; //get mors code input
        cmors.push_back(m);   //append mors code to corresponding index in another vector     
    }

    vector<vector<string>> words; // to save mors code and associated string on different collection but same index
    vector <string> str1; //word to be saved here
    vector <string> smors; //corresponding mors code to be saved here
    
    
    //collect words and save with corresponding mors
    while (cin >> word && word != "*") //while there is a word to collect and while it is not an asterix
    {
        m.clear(); //make sure variable is clear
        str1.push_back(word);//add word to vector
        //create mors code acording to charcarter vector (find it using find() function for each letter
        for(char letter: word){
            int index = find(charac, letter);
            m += cmors.at(index);
        }
        smors.push_back(m); //add the mors code for the word
    }
    
    //save word and mors code
    words.push_back(str1);
    words.push_back(smors);
        
    //collect code to be checked
    vector <string> morscode;
    while (cin >> m && m != "*"){ //double check again for asterix or empty (no string added)
        morscode.push_back(m);
    }
    for(string code: morscode){
        //initial index as the first word
        int index = find(words.at(1), code);
        //check for perfect match
        if(index != -1){
            int found = 1;
            for(size_t i = index + 1; i < words.at(1).size(); i++){//check through the whole vector for more possible matches
                if(words.at(1).at(i) == code){
                    found++;//increase found if there is a match
                }
            }
             if(found > 1){//if there is more tghan one match
               cout<<words.at(0).at(index)<<'!'<<endl;    
            } else {
                cout<<words.at(0).at(index)<<endl;
            }
        } else {
            bool found = false;
            while(!found){//try to see if there is any almost match from the other words as there is no perfect match
                for(size_t i = 0; i < words.at(1).size(); i++){
                    string str2 = words.at(1).at(i);
                    //if the size of code is less than the stored string we are comparing, and the compare returns 0, which means the whole of code can be found in the stored string although they are not the same
                    if(code.length() <= str2.length() && str2.compare(0, code.size(), code) == 0){ 
                        found = true; 
                        index = i;
                        break;
                    }                
                }
                code.pop_back();//delete a character at the end of the string to check again because match was not found, and continue with iteration
            }
            cout<<words.at(0).at(index)<<'?'<<endl;//display the found partial match
        }       
    }       

    return 0;
}