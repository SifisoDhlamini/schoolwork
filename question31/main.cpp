#include <iostream>
#include <math.h>
using namespace std;

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
  Shape():seg{}, edgeCount{}{};

  Shape(Segment *s, int x){
    for(int i = 0; i < x; i++){
        seg[i] = s[i];
    }
    edgeCount = x;

  }; // to construct a shape with a series of segment.
private:
  Segment seg[10];
  int edgeCount;
};

int main(int argc, char **argv)
{
	cout<<"Hello World\n";
    
	return 0;
}
