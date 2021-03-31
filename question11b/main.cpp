#include <iostream>
using namespace std;

class bar3d
{
    public:
        float width;
        float height;
        float depth;
        
        bar3d() {
                width = 0.0;
                height = 0.0;
                depth = 0.0;
        }
        

        bar3d(float w, float h, float d) {
            if((w < 0.0 || w > 1000.0) || (h < 0.0 || h > 1000) || (d < 0 || d > 1000)){
                width = 0.0;
                height = 0.0;
                depth = 0.0;
            } else {
              width = w;
              height = h;
              depth = d;
            }
        }
        
        float getVolume(){
            return width * height * depth;
        }
        
        void scale(float value){
            width *= value;
            height *= value;
            depth *= value;
        }
        
        float addVolume(bar3d b){
            return b.getVolume() + this -> getVolume();
        }

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

