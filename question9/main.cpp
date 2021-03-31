#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	int number {};
    cin>> number;
    
    vector<vector<int>> triangle(number, vector<int>(number, 0));
    triangle.at(0).at(0) = 1;
    
    
    for(int row {1}; row < number; row++){
        for(int col {0}; col <= row; col++){
            if(col == 0 || col == row){
                triangle.at(row).at(col) = 1;
            } else {
                int value1  = triangle.at(row - 1).at(col - 1);
                int value2 = triangle.at(row - 1).at(col);
                triangle.at(row).at(col) = value1 + value2;
            }
        }
    } 
    
    for(int row {0}; row < number; row++){
        //align preceding spaces
        for(int space {0}; space < (number -  row); space++){
            if(space > 0)
                cout<<"  ";
        }
        for(int col {0}; col <= row; col++){
            int value = triangle.at(row).at(col);
            if(col == row){
                cout<<std::right<<std::setw(2)<<value;
            } else {
                cout<<std::right<<std::setw(2)<<value<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
	return 0;
}
