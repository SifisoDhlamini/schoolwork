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
    
    float getDistance(Point p){
        float a = p.getX() - this -> x;
        float b = p.getY() - this -> y;
        float square = a*a + b*b;
        float sqrt = square / 2;
        int found = 0;
        float counter {0.0};
        while(counter != sqrt){
            counter = sqrt;
            sqrt = (square/counter + counter)/2;
        }
        return sqrt;
    }
};

int main(int argc, char **argv)
{
	Point coordinateA = {6,7};
    coordinateA.printPoint();
    Point coordianteB = {2,3};
    coordianteB.printPoint();
    cout<<endl;
    
    cout<<"X: "<<coordianteB.getX()<<endl;
    cout<<"Y: "<<coordianteB.getY()<<endl; 

    cout<<"Distance between the 2 points: "<<coordianteB.getDistance(coordinateA)<<endl;
    
    return 0;
}
