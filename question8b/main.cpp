#include <iostream>
using namespace std;

class bar3d
{
    public:
        int width;
        int height;
        int depth;
        
        bar3d() {
                width = 0;
                height = 0;
                depth = 0;
        }
        

        bar3d(int w, int h, int d) {
            if((w < 0 || w > 1000) || (h < 0 || h > 1000) || (d < 0 || d > 1000)){
                width = 0;
                height = 0;
                depth = 0;
            } else {
              width = w;
              height = h;
              depth = d;
            }
        }

};

int main(int argc, char **argv)
{
	bar3d bar(150, 400, 200);
    
	return 0;
}

