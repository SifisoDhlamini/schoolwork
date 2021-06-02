#include <iostream>

using namespace std;

template<class T>
void excange(T &val1, T &val2){
    T temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
}

int main(int argc, char **argv)
{
	cout<<"Hello World\n";
    
	return 0;
}
