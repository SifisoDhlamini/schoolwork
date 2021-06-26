#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;//enter size of matrix
    while(n!=0){//0 is to exit
        int matrix[n][n];//declare 2 dimensional matrix
        //populate matrix
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> matrix[i][j];
            }
        }
        bool parity = false;//flag wheter there is a pairing 1
        int row;//store row with false parity
        int col;//store column with false parity
        int j;//to store column index in loop. Declared outside to be able to access after loop ends
        int oddrowSum = 0;//counter for when row has odd sum
        int oddcolSum = 0;//counter for when column has odd sum
        for(int i=0; i<n; i++){//each row
            int rowSum = 0; //declare and initialize sum counter for row
            int colSum = 0; //declare and initialize sum counter for col
            for(j=0; j<n; j++){//each column
                rowSum += matrix[i][j];//increase 
                colSum += matrix[j][i];//increase
            }
            if((rowSum % 2 == 0) && (colSum % 2 == 0)){//if even row and even column
                    parity = true;
                }
                else{//if either or both odd
                     parity = false;
                     if(rowSum % 2 != 0){//if row is odd
                        oddrowSum++;//increase oddrowSum
                        row = i;//remember row
                     }
                     if(colSum % 2 != 0){//if column odd
                        oddcolSum++;//increase oddrowSum
                        col = i;//remember column
                     }
                }
            if(oddrowSum > 1 || oddcolSum > 1){//if any of the odd sums is greater than 1 break out of loop
                break;
            }
        }
        if(parity && oddrowSum == 0 && oddcolSum == 0){//all have pairs and parity is true
            cout << "OK" << endl;
        }
        else if(oddrowSum == 1 && oddcolSum == 1){// if any is odd advise which cordinate or bit should be changed
            cout << "Change bit (" << row + 1 << "," << col + 1 << ")" << endl;
        }
        else{//otherwise the oddrows or columns are more than one hence corrupt
            cout << "Corrupt" << endl;
        }
        cin >> n;//opportunity to enter new size of matrix, or 0 to exit
    }
    return 0;
}
