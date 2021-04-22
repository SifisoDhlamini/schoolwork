#include<iostream>
#include<math.h>

using namespace std;

class Point{
    float x, y;
public:
    Point(): Point(0,0){};
    Point(float x1, float y1): x{x1}, y{y1}{};
    void printPoint(){ cout<<'('<<x<<", "<<y<<')';}
    float getX(){ return x;}
    float getY(){ return y;}
    void setX(float x1){ x = x1;}
    void setY(float y1){ y = y1;}
    float getDistance(Point p){
        return sqrt(pow((x - p.getX()),2) + pow((y - p.getY()),2));
    }
};

class Segment{
    Point point1, point2;
public:
    Segment():Segment(point1, point2){}
    Segment(Point p1, Point p2):point1(p1), point2(p2) {}

    float getLength(){ return point1.getDistance(point2);}

    Point *getIntersect(Segment s){
        if((point1.getDistance(s.point1) == 0) || (point1.getDistance(s.point2) == 0)){
           return &point1;
        }
        if((point2.getDistance(s.point1) == 0) || (point2.getDistance(s.point2) == 0)){
           return &point2;
        }

        float t = -1 * (point1.getX() - s.point1.getX())/((point2.getX() - point1.getX()) - (s.point2.getX() - s.point1.getX()));
        float x = point1.getX() + (point2.getX() - point1.getX()) * t;
        float y = point1.getY() + (point2.getY() - point1.getY()) * t;

        Point *newP = new Point(x, y);
        return (t >= 0 && t <= 1)? newP: NULL;

    }
};


int main(int argc, char **argv)
{
	Point coordinateA = {10, 0};
    coordinateA.printPoint();
    Point coordinateB = {0, 10};
    coordinateB.printPoint();
    cout<<endl;
    cout<<"X: "<<coordinateA.getX()<<endl;
    cout<<"Y: "<<coordinateA.getY()<<endl;
    
    cout<<"X: "<<coordinateB.getX()<<endl;
    cout<<"Y: "<<coordinateB.getY()<<endl; 

    cout<<"Distance between the 2 points: "<<coordinateB.getDistance(coordinateA)<<endl;
    
    Segment seg(coordinateA, coordinateB);
    cout<<"The length of the Segment: "<<seg.getLength()<<endl;
    
    Point coordinateC = {0, 0}; //0,0
    coordinateC.printPoint();
    Point coordinateD = {0,10};//10,10
    coordinateD.printPoint();
    cout<<endl;
    cout<<"X: "<<coordinateC.getX()<<endl;
    cout<<"Y: "<<coordinateC.getY()<<endl;
    
    cout<<"X: "<<coordinateD.getX()<<endl;
    cout<<"Y: "<<coordinateD.getY()<<endl; 

    cout<<"Distance between the 2 points: "<<coordinateD.getDistance(coordinateC)<<endl;
    
    Segment seg2(coordinateC, coordinateD);
    cout<<"The length of the Segment: "<<seg2.getLength()<<endl;
    
    Point *inter;
    inter = seg2.getIntersect(seg);
    
    if (inter != NULL){
        inter -> printPoint();
    } else {
        cout<<"NULL"<<endl;
    }
 
   return 0;
}
