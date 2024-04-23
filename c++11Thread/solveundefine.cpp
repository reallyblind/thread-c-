#include<iostream>
#include<thread>
#include<memory>

//友元实现访问private
class A{
private:
    friend void thread_foo();

    void foo(){

        std::cout<<"Hello"<<std::endl;
    }


};

void thread_foo(){
    std::shared_ptr<A> a = std::make_shared<A>();
    std::thread t(&A::foo,a);
    t.join();
}
int main()
{
    thread_foo();


}


#if 0
//智能指针解决生命周期

class A{
public:
    void foo(){
        std::cout<<"Hello"<<std::endl;
    }


};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::thread t(&A::foo,a);

    t.join();

}
#endif


