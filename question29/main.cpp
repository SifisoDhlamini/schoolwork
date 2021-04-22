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
    Set operator +(const Set& set1){
        Set tempSet(*this);
        tempSet.add(set1);
        return tempSet;
    }
    
    Set operator -(const Set& set1){
        Set tempSet;
        for(int j = 0; j < set1.count; j++){
            if(add(set1.element[j]) == 0)
            tempSet.add(set1.element[j]);
        }
        return tempSet;
    }
    
private:
    int element[100];
    int count;   
};

int main(int argc, char **argv)
{   
//    Set first;
//    
//    cout<<first.add(6)<<"added"<<endl;
//    cout<<first.add(50)<<"added"<<endl;
//    cout<<first.add(41)<<"added"<<endl;
//    cout<<first.add(35)<<"added"<<endl;
//    cout<<first.add(3)<<"added"<<endl;
//    cout<<first.add(22)<<"added"<<endl;
//    cout<<first.add(1)<<"added"<<endl;
//    cout<<first.add(11)<<"added"<<endl;
//    
//    Set second;
//    cout<<second.add(4)<<"added"<<endl;
//    cout<<second.add(38)<<"added"<<endl;
//    cout<<second.add(8)<<"added"<<endl;
//    cout<<second.add(9)<<"added"<<endl;
//    cout<<second.add(12)<<"added"<<endl;
//    cout<<second.add(77)<<"added"<<endl;
//    cout<<second.add(10)<<"added"<<endl;
//    cout<<second.add(29)<<"added"<<endl;
//    cout<<second.add(6)<<"added"<<endl;
//    cout<<second.add(50)<<"added"<<endl;
//    cout<<second.add(41)<<"added"<<endl;
//    cout<<second.add(35)<<"added"<<endl;
    
    
    
//    Set third(first);
//    cout<<third.add(second)<<"added"<<endl;
//    cout<<"First: ";
//    first.display();
//    cout<<endl;
//    cout<<"Second: ";
//    second.display();
//    cout<<endl;
//    cout<<"Third: ";
//    third.display();
//    cout<<endl;
//    
//    Set fourth;
//    fourth = first + second;
//    Set fifth;
//    fifth = first - second;
//    cout<<"Fourth: ";
//    fourth.display();
//    cout<<endl;
//    cout<<"Fifth: ";
//    fifth.display();
//    cout<<endl;
//    Set sixth = second - first;
//    cout<<"Sixth: ";
//    sixth.display();
//    cout<<endl;
//    (second - first).display();
//    
    Set a;
    cout<<a.add(6)<<"added"<<endl;
    cout<<a.add(3)<<"added"<<endl;

    a.display();
    cout << endl;

    Set b;
    cout<<b.add(4)<<"added"<<endl;
    cout<<b.add(7)<<"added"<<endl;
    cout<<b.add(8)<<"added"<<endl;
    cout<<b.add(3)<<"added"<<endl;
    b.display();
    cout << endl;

    Set c(a);
    cout<<c.add(b)<<"added"<<endl;
    cout << "this is a: ";
    a.display();
    cout<<endl;
    cout << "this is b: ";
    b.display();
    cout<<endl;
    cout << "this is c: ";
    c.display();
    cout<<endl;
    Set Union = a + b;
    cout << "this is the union: ";
    Union.display();
    cout<<endl;
    Set intersection = a-b;
    cout << "this is the intersection: ";
    intersection.display();
    
	return 0;
}
