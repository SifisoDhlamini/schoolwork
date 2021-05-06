#include <iostream>
#include <math.h>
using namespace std;

class Point{
private:
    float x, y;
public:
    Point(): x(0), y(0){}
    Point(float x1, float y1): x(x1), y(y1){}

    void printPoint(){
        cout<<"("<<x<<", "<<y<<")";
    }

    float getX() { return x;}
    float getY() { return y;}
    void setX(float x1){ x = x1; }
    void setY(float y1){ y = y1; }

    float getDistance(Point p){
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
    float getLength(){return point1.getDistance(point2); }
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

    //int getEdgeCount() const{ return edgeCount;}
    Segment *getSegArr() { return seg; }
  
private:
  Segment seg[10];
  int edgeCount;
};

class Rectangle : public Shape
{
public:
    Rectangle(): Shape(4){}
    Rectangle(Segment *s, int edges = 4): Shape(s, edges){}
    float getPerimeter(){
        Segment *s = getSegArr();
        float a = s[0].getLength();
        float b = (a != s[1].getLength())? s[1].getLength(): s[2].getLength();
        return (2 * (a + b));
    }
    
    float getArea(){
        Segment *s = getSegArr();
        float a = s[0].getLength();
        float b = (a != s[1].getLength())? s[1].getLength(): s[2].getLength();        
        return (a * b);
    }    
};

int main(int argc, char **argv)
{   
    Point coordinateA = {-4, -6};    
    Point coordinateB = {-4,1};
    Point coordinateC = {3, 1};    
    Point coordinateD = {3,-6};

    
    Segment seg1(coordinateA, coordinateB);
    Segment seg2(coordinateC, coordinateD);
    cout<<"The length of the Segment 1: "<<seg1.getLength()<<endl;
    cout<<"The length of the Segment 2: "<<seg2.getLength()<<endl;
    Segment segs[] = {seg1, seg2, seg1, seg2};
    
    Rectangle Rect(segs);
    
    cout<<"The perimeter of the Rectangle: "<<Rect.getPerimeter()<<endl;
    cout<<"The area of the Rectangle: "<<Rect.getArea()<<endl;
    
    return 0;
}
