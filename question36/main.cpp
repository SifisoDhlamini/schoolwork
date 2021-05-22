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

    float getX() const{ return x;}
    float getY() const{ return y;}
    void setX(float x1){ x = x1; }
    void setY(float y1){ y = y1; }

    float getDistance(Point p) const{
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
    float getLength() const{return point1.getDistance(point2); }
    Point getPoint1() {return point1;}
    Point getPoint2() {return point2;}
    
    bool getIntersect(Segment s) const{
//        if((point1.getDistance(s.point1) == 0) || (point1.getDistance(s.point2) == 0)){
//           continue;
//        }
//        if((point2.getDistance(s.point1) == 0) || (point2.getDistance(s.point2) == 0)){
//          continue;
//        }

        float t = -1 * (point1.getX() - s.point1.getX())/((point2.getX() - point1.getX()) - (s.point2.getX() - s.point1.getX()));

        return (t >= 0 && t <= 1)? true: false;

    }
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
            match = false;
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
    
    virtual float getArea() const = 0;
    
    float getPerimeter(){
        float p{};
        for(int i = 0; i < edgeCount; i++){
            p += seg[i].getLength();
        }
        
        return p;
    }
    
    Segment const &getSeg(int index) const{
        return seg[index];
    }    
  
private:
  Segment seg[10];
  int edgeCount;
};

class Square : public Shape
{
public:
    Square(Segment *seg) : Shape(seg, 4){}
    float getArea() const { return pow(getSeg(0).getLength(), 2);}
};

class Rectangle : public Shape
{
public:
    Rectangle(): Shape(4){}
    Rectangle(Segment *s, int edges = 4): Shape(s, edges){}
    float getArea() const{
        float a = getSeg(0).getLength();
        float b = (a != getSeg(1).getLength())? getSeg(1).getLength(): getSeg(2).getLength();        
        return (a * b);
    }     

    bool isCollision(const Rectangle &r){
        int sides = 4; 
        for(int i = 0; i < sides; i++){
            for(int j = 0; j < sides; j++){
                if(r.getSeg(i).getIntersect(this->getSeg(j)))  return true;
            }            
        }        
        return false;
    }    
};

int main(int argc, char **argv)
{   
    Point coordinateA = {-4,-6};    
    Point coordinateB = {-4,1};
    Point coordinateC = {3, 1};    
    Point coordinateD = {3,-6};
    
    Point coordinateA1 = {1,1};    
    Point coordinateB1 = {5,5};
    Point coordinateC1 = {1,5};    
    Point coordinateD1 = {5,1};
    
    Point coordinateA2 = {3,3};    
    Point coordinateB2 = {3,7};
    Point coordinateC2 = {8, 3};    
    Point coordinateD2 = {8,7};
    
    Segment segA1(coordinateA1, coordinateC1);
    Segment segA2(coordinateD1, coordinateB1); 
    Segment segA3(coordinateA1, coordinateD1); 
    Segment segA4(coordinateB1, coordinateC1); 
    
    Segment segB1(coordinateA2, coordinateC2);
    Segment segB2(coordinateA2, coordinateB2);
    Segment segB3(coordinateB2, coordinateD2);
    Segment segB4(coordinateC2, coordinateD2);
    
    Segment segs1[] = {segA1, segA2, segA3, segA4};
    Segment segs2[] = {segB1, segB2, segB3, segB4};
    Rectangle Rect1(segs1);
    Rectangle Rect2(segs2);
    
    Segment seg1(coordinateA, coordinateB);
    Segment seg2(coordinateC, coordinateD);
    cout<<"The length of the Segment 1: "<<seg1.getLength()<<endl;
    cout<<"The length of the Segment 2: "<<seg2.getLength()<<endl;
    Segment segs[] = {seg1, seg2, seg1, seg2};
    
    Rectangle Rect(segs);
    
    cout<<"The perimeter of the Rectangle: "<<Rect.getPerimeter()<<endl;
    cout<<"The area of the Rectangle: "<<Rect.getArea()<<endl;
    
    string isTrue = (Rect1.isCollision(Rect2)) ? "true" : "false"; 
    cout<<isTrue<<endl;
    
    return 0;
}

