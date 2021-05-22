#include <iostream>
#include <string>
#include <set>

using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
    string strDate;
public:
    Date(): day(0), month(0), year(0), strDate(""){}
    Date(string date): day(stoi(date.substr(6,2))), month(stoi(date.substr(4,2))), year(stoi(date.substr(0,4))), strDate(date){}
    int getDay() const{return day;}
    int getMonth() const{return month;}
    int getYear() const{return year;}
    string getDate() const{return strDate;}
    
    int getLastDay(){
        int lastday;
        set<int> thirty = {4, 6, 9, 11};
        set<int> thirtyOne = {1, 3, 5, 7, 8, 10, 12};
        
        if(month == 2){
            lastday = (this->isLeapYear())? 29 : 28;
        } else if(thirty.find(month) != thirty.end()){
            lastday = 31;
        } else {
            lastday = 30;
        } 
        return lastday;
    }
    
    void setDay(int d){day = d;}
    void setMonth(int m){month = m;}
    void setYear(int y){year = y;}
    
    bool isLeapYear(){ return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0); } 
    
    void operator =(const Date& d){
        day = d.getDay();
        month = d.getMonth();
        year = d.getYear();
        strDate = d.getDate(); 
    }
        
    Date operator --(){
        Date *temp = new Date(this->getDate());
        if(temp->day >= 2){
            temp->day--;
        } else if(temp->month > 1){
            temp->month--;
            temp->day = temp->getLastDay();
        } else {
            temp->month = 12;
            temp->year--;
            temp->day = temp->getLastDay();
        }        
        return *temp;
    } 
    
    int compare(const Date& d){
        int comp;
        int intVal = stoi(strDate);
        int d_intVal = stoi(d.getDate());
        if(intVal > d_intVal) comp = 1;
        if(intVal < d_intVal) comp = -1;
        if(intVal == d_intVal) comp = 0;
        
        return comp;
    }    
};

struct DateRange{
    Date startDate;
    Date endDate;
    DateRange* next;
    DateRange* prev;        
};

typedef DateRange* DateRangePtr;

void headInsert(DateRangePtr& head, DateRangePtr& head = nullptr) {
	//head = new IntNode(n,head);
}


int main()
{
    
    
    return 0;
}


