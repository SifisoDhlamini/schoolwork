#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct POINT {int x; int y;}; //coordinate or point
int main() {
    
    vector<int> vecScent;
     
    char szIns[100], szOri[4] = {'N', 'E', 'S', 'W'};
    
    POINT ptSize, ptPos, ptOri[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //face N, E, S, W representation
     
    cin >> ptSize.x >> ptSize.y;//enter x size (row) and y size (columns)
     
    for (char cOri; cin >> ptPos.x >> ptPos.y >> cOri >> szIns; ) {//start position, origin, directions
        int nOri;//to store origin to move
        //marking index describing orientation
        if (cOri=='N') {
            nOri=0;//indicates it is facing north
        }
        if (cOri=='E') {
            nOri=1;//indicates it is facing East
        }
        if (cOri=='S') {
            nOri=2;//indicates it is facing South
        }
        if (cOri=='W') {
            nOri=3;//indicates it is facing West
        }
        
        bool lost=false;// default to not lost 
        for (int i = 0; szIns[i] != 0; i++) {
             
            if (szIns[i] != 'F') {// if current move is not forward
            //rotate on same block a new direction. 
            //if the direction is left, add 3 moves to make it -1 where it is else add one 90 degree rotion right
            //get the value % 4 to keep it within the 4 origins (N E S W)
                nOri = (nOri + (szIns[i] == 'L' ? 3 : 1)) % 4; 
                continue; //then continue iteration through directions
            }
            //If we are here, then it was a forward move
            //move forward facing current direction
            POINT ptNew = {ptPos.x + ptOri[nOri].x, ptPos.y + ptOri[nOri].y}; 
            //if still within boundaries
             if (ptNew.x >= 0 && ptNew.x <= ptSize.x &&
                ptNew.y >= 0 && ptNew.y <= ptSize.y) {
                    ptPos = ptNew;
                    continue; //countinue iteration through directions
            }
            //this means we are out of bounds if we got here
            //mark the scent of coordinate where the robot fell off the grid as a multiple of max(50)+ 1 and y, plus x (integer value)
             int nScent = ptPos.y * 51 + ptPos.x; 
             
            //check if scent allready exist in integer vector
            //if it exists, ignore it, else save the value
            //mark lost as 1
            //break out of iteration of directions
             if (find(vecScent.begin(), vecScent.end(), nScent) == vecScent.end()) {
                vecScent.push_back(nScent);
                 lost=1;
                break;
            }          
        }
         cout << ptPos.x << ' ' << ptPos.y << ' ' << szOri[nOri]; //print last position and direction
        cout << ((lost == 1) ? " LOST" : "") << endl;//if lost print it or print nothing
    }
    return 0;
}