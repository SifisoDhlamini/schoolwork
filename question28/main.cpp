#include <iostream>
using namespace std;
class Set
{
public:
    Set(): element {}, count {0}{
    }
    
    Set(const Set& s){
        count = 0;
        for(int i = 0; i < s.count; i++){
            add(s.element[i]);
        }
    }
    
    int add(const int el){
        for (int i = 0 ; i < count; i++) {
          if(element[i] == el){
              return 0;
          }
        }
        element[count] = el;
        ++count;
        return 1;
    }
    
    int add(const Set s){ 
        int added_elements = 0;
        for(int i = 0; i < s.count; i++){
            added_elements += add(s.element[i]);
        }
        return added_elements; 
    }
    
    void display()
    {
        int j;
        for(j = 0;j < count;j ++)
        std::cout<<element[j]<<" ";
    }
private:
    int element[100];
    int count;   
};

int main(int argc, char **argv)
{   
    Set first;
    
    cout<<first.add(6)<<"added"<<endl;
    cout<<first.add(50)<<"added"<<endl;
    cout<<first.add(6)<<"added"<<endl;
    cout<<first.add(35)<<"added"<<endl;
    cout<<first.add(3)<<"added"<<endl;
    cout<<first.add(22)<<"added"<<endl;
    cout<<first.add(1)<<"added"<<endl;
    cout<<first.add(11)<<"added"<<endl;
    
    Set second(first);
    cout<<second.add(4)<<"added"<<endl;
    cout<<second.add(7)<<"added"<<endl;
    cout<<second.add(8)<<"added"<<endl;
    cout<<second.add(9)<<"added"<<endl;
    cout<<second.add(12)<<"added"<<endl;
    cout<<second.add(28)<<"added"<<endl;
    cout<<second.add(10)<<"added"<<endl;
    cout<<second.add(30)<<"added"<<endl;
    
    Set third(first);
    cout<<third.add(second)<<"added"<<endl;
    first.display();
    cout<<endl;
    second.display();
    cout<<endl;
    third.display();
    
	return 0;
}
