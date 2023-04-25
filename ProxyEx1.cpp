#include <iostream>

using namespace std;

class Subject{
    public: 
        virtual ~Subject(){};
        virtual void request() = 0;
};

class RealSubject: public Subject{
    public:
        void request(){
            cout << "RealSubject.request()" << endl; 
        }
};

class Proxy : Subject{
    private:
        Subject* realSubject;
    public:
        Proxy(): realSubject(new RealSubject()){};
        virtual ~Proxy(){ delete realSubject; };
    
        void request(){ realSubject->request(); }
};


int main()
{
    Proxy proxy;
    proxy.request();

    return 0;
}
