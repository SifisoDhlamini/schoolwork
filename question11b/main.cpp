#include<iostream>

using namespace std;

class bar3d{
private:
    float checkRange(float x){return (x > 0 && x < 1000)? x: 0;}
public:
    float width, height, depth;

    bar3d(): bar3d(0,0,0){}
    bar3d(float w, float h, float d): width(checkRange(w)), height(checkRange(h)), depth(checkRange(d)){
        if (width == 0 || height == 0 || depth == 0)
            width = height = depth = 0;
    }
    float getVolume(){ return width * height * depth; }

    void scale(float s){
        width*=s;
        height*=s;
        depth*=s;
    }

    float addVolume(bar3d b){ return getVolume() + b.getVolume(); }
};

int main(int argc, char **argv)
{
	bar3d bar(15, 40, 20);
    
    bar3d bar2(15, 40, 10);
    
    bar3d bar3(10, 10, 10);
    
    float sum = bar.addVolume(bar2);
    float sum1 = bar3.addVolume(bar);
    
    cout<<"bar volume: "<<bar.getVolume()<<endl;
    cout<<"bar volume: "<<bar2.getVolume()<<endl;
    cout<<"bar volume: "<<sum<<endl;
    cout<<"bar volume: "<<bar3.getVolume()<<endl;
    cout<<"bar volume: "<<sum1<<endl;
    
	return 0;
}

