#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    while(n!=0){
        int matrix[n][n];
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> matrix[i][j];
            }
        }
        bool parity = false;
        int row;
        int col;
        int j;
        int oddrowSum = 0;//counter for when row has odd sum
        int oddcolSum = 0;
        for(int i=0; i<n; i++){
            int rowSum = 0;
            int colSum = 0;
            for(j=0; j<n; j++){
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
            }
            if((rowSum % 2 == 0) && (colSum % 2 == 0)){
                    parity = true;
                }
                else{
                     parity = false;
                     if(rowSum % 2 != 0){
                        oddrowSum++;
                        row = i;
                     }
                     if(colSum % 2 != 0){
                        oddcolSum++;
                        col = i;
                     }
                }
            if(oddrowSum > 1 || oddcolSum > 1){
                break;
            }
        }
        if(parity && oddrowSum == 0 && oddcolSum == 0){
            cout << "OK" << endl;
        }
        else if(oddrowSum == 1 && oddcolSum == 1){
            cout << "Change bit (" << row + 1 << "," << col + 1 << ")" << endl;
        }
        else{
            cout << "Corrupt" << endl;
        }
        cin >> n;
    }
    return 0;
}
