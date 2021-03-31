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
        
        float scale(float value){
            width *= value;
            height *= value;
            depth *= value;
        }

};

int main(int argc, char **argv)
{
	bar3d bar(150, 400, 200);
    
	return 0;
}

