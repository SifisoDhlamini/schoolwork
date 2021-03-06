#include <iostream>
#include <math.h>
using namespace std;

class Point{
private:
    float x, y;
public:
    Point(): x(0), y(0){}
    Point(float x1, float y1): x(x1), y(y1){}

    void printPoint(){// pint points of segment
        cout<<"("<<x<<", "<<y<<")";
    }

    float getX() { return x;}
    float getY() { return y;}
    void setX(float x1){ x = x1; }
    void setY(float y1){ y = y1; }

    float getDistance(Point p){//get distance between 2 points using distance formula
        float a = p.getX() - this -> x;
        float b = p.getY() - this -> y;
        float square = a*a + b*b;


        return sqrt(square);
    }

};

class Segment{
private:
    Point point1, point2;
public:
    Segment(): Segment(point1, point2){}
    Segment(Point p1, Point p2): point1(p1), point2(p2){}
    float getLength() {return point1.getDistance(point2); }
    Point getPoint1() {return point1;}
    Point getPoint2() {return point2;}
};

class Shape
{
public:
    Shape():seg{}, edgeCount{}{}
    Shape(int e):seg{}, edgeCount{e}{}
    Shape(Segment *s, int x){
    for(int i = 0; i < x; i++){
        seg[i] = s[i];
    }
    edgeCount = x;

    }; 

    int getEdgeCount() { return edgeCount;}
    Segment *getSegArr() { return seg; }
  
private:
  Segment seg[10];
  int edgeCount;
};

class Triangle : public Shape
{
public:
    Triangle(): Shape(3){}
    Triangle(Segment *s, int edges = 3): Shape(s, edges){}//use default 3 for number of edges in case not specified
    float getPerimeter(){
        Segment *s = getSegArr();//point to first element of Array seg[] in Shape Class
        float p{};
        for(int i = 0; i < 3; i++){//add all sides
            p += s[i].getLength();
        }
        
        return p;
    }
    //Get area of triangle
    float getArea(){
        Segment *s = getSegArr();// point to first element of array of segments
        Point p1;
        Point p2;
        Point p3;
        if(s[0].getPoint1().getDistance(s[1].getPoint1()) == 0){//if point1 of segment 0 and segment 1 are the same
            p1 = s[0].getPoint1();
            p2 = s[0].getPoint2();
            p3 = s[1].getPoint2();
        } else {// then it must be the other point because they segments share a point
            p1 = s[0].getPoint2();
            p2 = s[0].getPoint1();
            p3 = s[1].getPoint2();
        }
        //use formula (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 *(y1 -y2))) to get area
        return ((p1.getX() * (p2.getY() - p3.getY())) + (p2.getX() * (p3.getY() - p1.getY())) + (p3.getX() * (p1.getY() - p2.getY())))/2;
    }    
};

int main(int argc, char **argv)
{   
    Point coordinateA = {15, 15};    
    Point coordinateB = {23,30};
    Point coordinateC = {50, 25};    
    
    Segment seg1(coordinateA, coordinateB);
    Segment seg2(coordinateB, coordinateC);
    Segment seg3(coordinateC, coordinateA);
    cout<<"The length of the Segment 1: "<<seg1.getLength()<<endl;
    cout<<"The length of the Segment 2: "<<seg2.getLength()<<endl;
    Segment segs[] = {seg1, seg2, seg3};
    
    Triangle tri(segs);
    
    cout<<"The perimeter of the Triangle: "<<tri.getPerimeter()<<endl;
    cout<<"The area of the Triangle: "<<tri.getArea()<<endl;
    
    return 0;
}
