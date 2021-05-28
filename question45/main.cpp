#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n){
        bool arr[n][n];
        int rowSum[n] = {0}, colSum[n] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
                if(arr[i][j]){
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }
        int changeRow = -1, changeCol = -1;
        bool printed = false;
        for(int i = 0; i < n; i++){
            if(rowSum[i] % 2){
                if(changeRow != -1){
                    cout << "Corrupt" << endl;
                    printed = true;
                    break;
                }
                changeRow = i;
            }
            if(colSum[i] % 2){
                if(changeCol != -1){
                    cout << "Corrupt" << endl;
                    printed = true;
                    break;
                }
                changeCol = i;
            }
        }
        if(!printed){
            if((changeRow == -1 && changeCol != -1) || (changeRow != -1 && changeCol == -1)){
                cout << "Corrupt" << endl;
            }
            if(changeRow != -1 && changeCol != -1){
                cout << "Change bit (" + to_string(changeRow + 1) + "," + to_string(changeCol + 1) + ")" << endl;
            }
            if(changeRow == -1 && changeCol == -1){
                cout << "OK" << endl;
            }
        }
    }
    return 0;
}