#include <iostream>
using namespace std;

class Point {
private:
    float x;
    float y;
    
public: 
    Point(): Point(0.0, 0.0){
        
    }
    Point(float xCoordinate, float yCoordinate): x(xCoordinate), y(yCoordinate){
        
    }
    
    void printPoint(){
        cout<<"("<<x<<", "<<y<<")";
    }
    
    void setX(float xCoordinate){
        x = xCoordinate;
    }
    
    float getX() { return x;}
    
    void setY(float yCoordinate){
        y = yCoordinate;
    }
    
    float getY() { return y;}
};

int main(int argc, char **argv)
{
	Point coordinateA;
    coordinateA.printPoint();
    Point coordianteB = {2,3};
    coordianteB.printPoint();
    cout<<endl;
    
    cout<<"X: "<<coordianteB.getX()<<endl;
    cout<<"Y: "<<coordianteB.getY()<<endl;    
    
	return 0;
}
