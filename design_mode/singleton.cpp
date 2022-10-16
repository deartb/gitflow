#include<iostream>
using namespace std;

//懒汉式
class Lazy{
    private:
        static Lazy *instance;
        // static int a;
    public:
        Lazy(){}
        static Lazy *getInstance();
        // static void show();
};

Lazy *Lazy::instance = nullptr;
// int Lazy::a = 10;
Lazy *Lazy::getInstance(){
    if(nullptr != instance){
        instance = new Lazy();
    }
    return instance;
}
// void Lazy::show(){
//     cout << a << endl;
// }

//饿汉式
class Hungry{
    private:
        static Hungry *instance;
        // static int h;
    public:
        Hungry(){}
        static Hungry *get_instance();
        // static void show();
};

//初始化 函数定义
Hungry *Hungry::instance = new Hungry();
// int Hungry::h = 5;
Hungry *Hungry::get_instance(){
    return instance;
}
// void Hungry::show(){
//     cout << h << endl;
// }

int main()
{
    Lazy *ins = Lazy::getInstance();
    // ins->show();

    Hungry *hungry = Hungry::get_instance();
    // hungry->show();
}
