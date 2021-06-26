#include <iostream>
#include <string>

using namespace std;
 
int main ()
{
    int n,m;
    int counter=0;
   while(true)
   {
       cin >> m >> n;//rows and columns
       if (n ==0 && m ==0) break;
       counter++;
       if (counter > 1) cout << '\n';
       int field[102][102] = {0};//initialize all values to zero in the 2 dimensional array/field
      //plot my field character by character
      for (int i=1; i<m+1; i++)
          for (int j=1; j<n+1; j++)
          {
              char temp;
              cin >> temp;
              if (temp == '*')//if it is a mine
                  {
                      //111
                      //1*1
                      //111
                      field[i][j] = -1;//change that square to -1
                      //increase adjacent squares by 1 if they are not mines 
                      //top  (-1 row to mark inside the top square)
                      if (field[i-1][j] != -1) field[i-1][j]++; 
                      //top left (-1 row and column to mark inside the top square on the left)
                      if (field[i-1][j-1] != -1) field[i-1][j-1]++; 
                      //top left (-1 row and +1 column to mark inside the top square on the right)
                      if (field[i-1][j+1] != -1) field[i-1][j+1]++;
                      if (field[i][j-1] != -1) field[i][j-1]++;//same row left
                      if (field[i+1][j] != -1) field[i+1][j]++; //same column bottom
                      if (field[i+1][j+1] != -1) field[i+1][j+1]++; //bottom right
                      if (field[i+1][j-1] != -1) field[i+1][j-1]++; //bottom left
                      if (field[i][j+1] != -1) field[i][j+1]++; //same row right
                  }
          }
 
           cout << "Field #" << counter << ":\n";
            for (int i=1; i<m+1; i++)
           {
 
                for (int j=1; j<n+1; j++)
                    {
                        
                        if (field[i][j] == -1) cout << '*';
                        else cout << field[i][j];
                }
                cout << "\n";
           } 
   } 
    return 0;
}