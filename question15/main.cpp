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
        float a = p.x - this -> x;
        float b = p.y - this -> y;
        float square = a*a + b*b;
        float sqrt = square / 2;
        float counter {0.0};
        while(counter != sqrt){
            counter = sqrt;
            sqrt = (square/counter + counter)/2;
        }
        return sqrt;
    }
    
};

class Segment{
private:
    Point point1;
    Point point2;
    
public:
Segment(): Segment(point1, point2){ 
    } 
    
    Segment(Point p1, Point p2): point1(p1), point2(p2){        
    } 
    
    float getLength(){
        return point1.getDistance(point2);
    }    
};




int main(int argc, char **argv)
{
	
}

Point coordinateA = {-4, -3};    
    Point coordinateA = {6, 6};
    coordinateA.printPoint();
    Point coordinateB = {2,3};
    coordinateB.printPoint();
    cout<<endl;
    cout<<"X: "<<coordinateA.getX()<<endl;
    cout<<"Y: "<<coordinateA.getY()<<endl;
    
    cout<<"X: "<<coordinateB.getX()<<endl;
    cout<<"Y: "<<coordinateB.getY()<<endl; 

    cout<<"Distance between the 2 points: "<<coordinateB.getDistance(coordinateA)<<endl;
    
    Segment seg(coordinateA, coordinateB);
    cout<<"The length of the Segment: "<<seg.getLength()<<endl;
    
    return 0;
