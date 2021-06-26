#include <iostream>
#include <stdio.h> 
#include <string.h> 

using namespace std;

int SuDoku[9][9], row[9][10], column[9][10], grid[9][10]; 
int n, tn, flag; 
void DFS(int now) { 
    if(flag == 1) //if finished
        return; 
    if(now == n*n) { //if block is the last one
        int i, j; 
        flag = 1; //flag that it id complete
        for(i = 0; i <n; i++ ) { //row
            for(j = 0; j <n; j++) { //column
                if(j) //if there is a value either than 0
                   cout<<" "; //first print a space 
                cout<<SuDoku[i][j]; //print value
            } 
            puts("");//position curser to next index
        } 
    } 
    int x = now/n, y = now%n; //position row and column according to entered value
    if(SuDoku[x][y] != 0) //if block has a 1 (not populated)
        DFS(now+1); //increase count of filled blocks and call function again (recurssion)
    else { 
        int i,g = x/tn*tn+y/tn; //zero was found, so we need to find a possible number from 1 to n*n that is valid
        for(i = 1; i <= n; i++) { 
            //zero was found, so we need to find a possible number from 1 to n*n that is valid
            //if block has value of zero in all three marker arrays (not visited)
            if(row[x][i] == 0 && column[y][i] == 0 && grid[g][i] == 0) { 
                row[x][i] = 1; //mark it as unvisited
                column[y][i] = 1; //mark it as unvisited
                grid[g][i] = 1; //mark it as unvisited
                SuDoku[x][y] = i; //enter the value of i in the sudoku array to replace 1
                DFS(now+1); //recursion call with the next value of 1 - n*n from current now
                SuDoku[x ][y] = 0; //mark as completed
                row[x][i] = 0; //mark as completed
                column[y][i] = 0; //mark as completed
                grid[g][i] = 0; //mark as completed
            } 
        } 
    } 
} 
int main() { 
    int first = 1 , i, j; 
    while(cin>>n) { 
        tn = n; //keep entred vale
        n = n*n; //get its sqare value to represent number of blocks to fill
        memset(row, 0, sizeof(row)); //initialize row array with zero
        memset(column, 0, sizeof(column)); //initialize column array with zero
        memset(grid, 0, sizeof(grid)); //initialize grid array with zero
        //populate sudoku array with input
        for(i = 0; i <n; i++) { 
            for(j = 0; j <n; j++) { 
                scanf("%d", &SuDoku[i][j]);
                //mark ith row of row array at index equivalent entered value to as needs to be changed ('1')
                row[i][SuDoku[i][j]] = 1; 
                //mark ith row of column array at index equivalent entered value to as needs to be changed  ('1')
                column[j][SuDoku[i][j]] = 1;
                //mark ith row of n blocks and at index equivalent entered value to as needs to be changed ('1')
                grid[ i/tn*tn+j/tn][SuDoku[i][j]] = 1; 
            } 
        } 
        if(!first) 
            puts(""); //position curser to next index
        flag = 0; // initialize flag
        DFS(0); //initiate sudoku populating function
        if(!flag) // if flag changed in DFS() to 0, then print the below
            puts ("NO SOLUTION"); 
        first = 0; //change first to 0 because we are done
    } 
    return 0; 
}