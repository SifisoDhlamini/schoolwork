#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;
    
public:
    void setW(const int w) { width = w;}
    void setH(const int h) { height = h;}
    int getW() const {
        return width;
    }
    
    int getH() const {
        return height;
    }
    int getArea() const {
        return width * height;
    }
    




int main(int argc, char **argv)
{
	Rectangle rect;
    
    rect.setW(10);
    rect.setH(10);
    cout<<"Width: "<<rect.getW()<<endl;
    cout<<"Height: "<<rect.getH()<<endl;
    cout<<"Area: "<<rect.getArea()<<endl;
    
	return 0;
}
