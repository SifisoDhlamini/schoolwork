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
    float getLength() {return point1.getDistance(point2); }
    Point getPoint1() {return point1;}
    Point getPoint2() {return point2;}
};

class Shape
{
public:
    Shape() : edgeCount(0){}
    Shape(int e):seg{}, edgeCount{e}{}
    Shape(Segment *s, int x){ // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
        if(checkShape(s, x)){
            for(int i = 0; i < x; i++){
                seg[i] = s[i];
            }
            edgeCount = x;
        } else {
            throw invalid_argument("Your segments do not form a close shape");
        }      
    }
    bool checkShape(Segment *s, int x){ 
        bool match = false;
        for(int i = 0; i < x; i++){
            Point p1 = s[i].getPoint1();
            Point p2 = s[i].getPoint2();
            for(int j = 0; j < x; j++){
                if(j != i){
                    if(p1.getDistance(s[j].getPoint1()) == 0 || p1.getDistance(s[j].getPoint2()) == 0 || p2.getDistance(s[j].getPoint1()) == 0 
                    || p2.getDistance(s[j].getPoint2()) == 0 ){
                       match = true; 
                    }
                        
                }
            }
            if(match == false) return false;
        }
        return match;
    }
    
    virtual float getArea() = 0;
    
    float getPerimeter(){
        float p{};
        for(int i = 0; i < edgeCount; i++){
            p += seg[i].getLength();
        }
        
        return p;
    }
    
    Segment &getSeg(int index)
    {
        return seg[index];
    }
  
private:
  Segment seg[10];
  int edgeCount;
};

//*************************************************************************
class Triangle : public Shape
{
public:
    Triangle(): Shape(3){}
    Triangle(Segment *s, int edges = 3): Shape(s, edges){}
    /*float getPerimeter(){
        Segment *s = getSegArr();
        float p{};
        for(int i = 0; i < 3; i++){
            p += s[i].getLength();
        }
        
        return p;
    }*/
    
    float getArea(){
        Segment *s = &getSeg(0);
        Point p1;
        Point p2;
        Point p3;
        if(s[0].getPoint1().getDistance(s[1].getPoint1()) == 0){
            p1 = s[0].getPoint1();
            p2 = s[0].getPoint2();
            p3 = s[1].getPoint2();
        } else {
            p1 = s[0].getPoint2();
            p2 = s[0].getPoint1();
            p3 = s[1].getPoint2();
        }
        return ((p1.getX() * (p2.getY() - p3.getY())) + (p2.getX() * (p3.getY() - p1.getY())) + (p3.getX() * (p1.getY() - p2.getY())))/2;
    }    
};

int main(int argc, char **argv)
{   
    Point coordinateA = {15, 15};    
    Point coordinateB = {23,30};
    Point coordinateC = {50, 25}; 
    Point coordinateD = {6, 8};
    
    Segment seg1(coordinateA, coordinateB);
    Segment seg2(coordinateB, coordinateC);
    //Segment seg3(coordinateC, coordinateA);
    Segment seg4(coordinateC, coordinateD);
    Segment segs[] = {seg1, seg2, seg4};    
    Triangle tri(segs, 3);
    
//    cout<<"The perimeter of the Triangle: "<<tri.getPerimeter()<<endl;
//    cout<<"The area of the Triangle: "<<tri.getArea()<<endl;
    
    return 0;
}

