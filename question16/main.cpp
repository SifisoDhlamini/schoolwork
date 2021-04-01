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
        //find values of Ax + By = C (both segments) to get intersection and detrmine if it is within range of both segments
        static Point intercect;
        float A1 = s.point2.getY() - s.point1.getY();
        float B1 = s.point1.getX() - s.point2.getX();
        float C1 = A1 * s.point1.getX() + B1 * s.point1.getY();
         
        float A2 = this->point2.getY() - this->point1.getY();
        float B2 = this->point1.getX() - this->point2.getX();
        float C2 = A2 * this->point1.getX() + B2 * this->point1.getY(); 
        
        float denominator = A1 * B2 - A2 * B1;
        
        //if it is the same line or share a point on the same axis
        if(denominator == 0){ 
            if(s.point1.getX() == this->point1.getX() && s.point1.getY() == this->point1.getY()){
                intercect.setX(s.point1.getX());
                intercect.setY(s.point1.getY());
                return &intercect;
            }
            if(s.point1.getX() == this->point2.getX() && s.point1.getY() == this->point2.getY()){
                intercect.setX(s.point1.getX());
                intercect.setY(s.point1.getY());
                return &intercect;
            }
            if(s.point2.getX() == this->point1.getX() && s.point2.getY() == this->point1.getY()){
                intercect.setX(s.point2.getX());
                intercect.setY(s.point2.getY());
                return &intercect;
            }
            if(s.point2.getX() == this->point2.getX() && s.point2.getY() == this->point2.getY()){
                intercect.setX(s.point2.getX());
                intercect.setY(s.point2.getY());
                return &intercect;
            }

            return NULL;        
        } 
        
        intercect.setX((B2 * C1 - B1 * C2)/denominator);
        intercect.setY((A1 * C2 - A2 * C1)/denominator);
        
        if(intercect.getX() == -0){
            intercect.setX(0);
        }
        if(intercect.getY() == -0){
            intercect.setY(0);
        }
        
        //check boundary ratio  or range      
        float ratioX1 = (intercect.getX() - s.point1.getX()) / (s.point2.getX() - s.point1.getX());
        float ratioY1 = (intercect.getY() - s.point1.getY()) / (s.point2.getY() - s.point1.getY());
        float ratioX2 = (intercect.getX() - this->point1.getX()) / (this->point2.getX() - this->point1.getX());
        float ratioY2 = (intercect.getY() - this->point1.getY()) / (this->point2.getY() - this->point1.getY());
        
        if(((ratioX1 >= 0 && ratioX1 <= 1) || (ratioY1 >= 0 && ratioY1 <= 1)) && ((ratioX2 >= 0 && ratioX2 <= 1) || (ratioY2 >= 0 && ratioY2 <= 1))){
            return &intercect;
        }
        
        return NULL;          
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
    cout<<"Slope: "<<seg.findSlope()<<endl;
    
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
