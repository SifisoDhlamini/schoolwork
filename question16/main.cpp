#include <iostream>
#include <math.h>
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
        
        return sqrt(square);
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
    
    Point *getIntersect(Segment s){ 
        static Point intersect;
        if(s.findSlope() == this -> findSlope()){
            return NULL;
        } else {
            float a1 = point1.getX();
            float b1 = point1.getY();
            float c1 = point1.getY() - (this -> findSlope() * point1.getX());
            float a2 = s.point1.getX();
            float b2 = s.point1.getY();
            float c2 = s.point1.getY() - (s.findSlope() * s.point1.getX()); 
            
            
            //b = y - mx
            intersect.setX((b1*c2 - b2*c1) / (a1*b2 - a2*b1));
            intersect.setY((a2*c1 - a1*c2) / (a1*b2 - a2*b1));            
            
            if (inRange(intersect)){ return &intersect; }            
        }
        
        return NULL;
    }
    
    float findSlope();
    bool inRange(Point p);
    
};

float Segment::findSlope(){
    return ((point2.getY() - point1.getY()) / (point2.getX() - point1.getX()));
}

bool Segment::inRange(Point p){
    
    Point max;
    Point min;
    
    if(point1.getY() >= point2.getY()){
        max = point1;
        min = point2;
    } else {
        max = point2;
        min = point1;
    }
    
    if((p.getX() > min.getX() && p.getX() < max.getX()) && (p.getY() > min.getY() && p.getY() < max.getY())){
        return true;
    }
    
    return false;
}


int main(int argc, char **argv)
{
	Point coordinateA = {6, -1};
    coordinateA.printPoint();
    Point coordinateB = {2, 7};
    coordinateB.printPoint();
    cout<<endl;
    cout<<"X: "<<coordinateA.getX()<<endl;
    cout<<"Y: "<<coordinateA.getY()<<endl;
    
    cout<<"X: "<<coordinateB.getX()<<endl;
    cout<<"Y: "<<coordinateB.getY()<<endl; 

    cout<<"Distance between the 2 points: "<<coordinateB.getDistance(coordinateA)<<endl;
    
    Segment seg(coordinateA, coordinateB);
    cout<<"The length of the Segment: "<<seg.getLength()<<endl;
    cout<<"Slope: "<<seg.findSlope()<<endl;
    
    Point coordinateC = {2, 1};
    coordinateC.printPoint();
    Point coordinateD = {4,-1};
    coordinateD.printPoint();
    cout<<endl;
    cout<<"X: "<<coordinateC.getX()<<endl;
    cout<<"Y: "<<coordinateC.getY()<<endl;
    
    cout<<"X: "<<coordinateD.getX()<<endl;
    cout<<"Y: "<<coordinateD.getY()<<endl; 

    cout<<"Distance between the 2 points: "<<coordinateD.getDistance(coordinateC)<<endl;
    
    Segment seg2(coordinateC, coordinateD);
    cout<<"The length of the Segment: "<<seg2.getLength()<<endl;
    cout<<"Slope: "<<seg2.findSlope()<<endl;  
    
    Point *inter;
    inter = seg2.getIntersect(seg);
    
    if (inter != NULL){
        inter -> printPoint();
    } else {
        cout<<"NULL"<<endl;
    }
 
   return 0;
}
