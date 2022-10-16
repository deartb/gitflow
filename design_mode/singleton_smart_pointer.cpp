#include<iostream>
#include<memory>
using namespace std;

//懒汉式
class Lazy{
    private:
        // static Lazy *instance;
        static shared_ptr<Lazy> instance;
        static int a;
    public:
        Lazy(){}
        // static Lazy *getInstance();
        static shared_ptr<Lazy> getInstance();
        static void show();
};

shared_ptr<Lazy> Lazy::instance(nullptr);
int Lazy::a = 10;
shared_ptr<Lazy> Lazy::getInstance(){
    if(nullptr == instance){
        instance = make_shared<Lazy>();
        // instance(make_shared<Lazy>());
        // instance = new Lazy();
    }
    return instance;
}
void Lazy::show(){
    cout << a << endl;
}


int main()
{
    shared_ptr<Lazy> ins = Lazy::getInstance();
    ins->show();
    return 0;
}