#include <iostream>
using namespace std;

class bar3d
{
public:
  int width;
  int height;
  int depth;
  
  int calcVolume() { return width * height * depth;}
  void displayVolume();
 
};

void bar3d::displayVolume(){
    cout<<"width = "<<width<<endl;
    cout<<"height = "<<height<<endl;
    cout<<"height = "<<height<<endl;
    cout<<"The volume of the 3D bar is "<<calcVolume()<<endl;
    
}

int main(int argc, char **argv)
{
    bar3d bar;
    bar.width = 100;
    bar.height = 400;
    bar.depth = 300;
    
    bar.displayVolume();    
    
	return 0;
}
