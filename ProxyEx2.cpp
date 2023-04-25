#include <iostream>

using namespace std;

class Person{
    private:
        string name;
        static string list[];
        static int next;
    public:
        Person(){
            name = list[next++];
        }
        
        string getName(){ return name; }
    
};

string Person::list[] = { "Tom", "Dick", "Harry", "Bubba" };
int Person::next = 0;

class PettyCashProtected{
    private:
        int balance;    
    public:
        PettyCashProtected(){ balance = 500; }
        
        bool withdraw(int amount){ 
            if(amount > balance)
                return false;
            
            balance -= amount;
            return true;
        }
        
        int getBalance(){ return balance; }
};

class PettyCash{
    PettyCashProtected realThing;
    public:
        bool withdraw(Person &p, int amount){
            if(p.getName()=="Tom" || p.getName()=="Harry" 
                || p.getName()=="Dick" || p.getName()=="Bubba")
                    return realThing.withdraw(amount);
            else
                    return false;                                                
        }
        
        int getBalance(){ return realThing.getBalance(); }
};

int main()
{
    PettyCash pc;
    int size = 4;
    Person workers[size];
    
    for(int i = 0, amount = 100; i < size; i++, amount+=100)
        if(!pc.withdraw(workers[i], amount))
            cout << "No money for " << workers[i].getName() << endl;
        else 
            cout << amount << " dollars for " << workers[i].getName() << endl;
    cout << "Remaining balance is " << pc.getBalance() << '\n';
    return 0;
}
