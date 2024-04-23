
#include <iostream>
#include <thread>
void foo(int* ptr) {
    if(ptr!=nullptr)
        std::cout << *ptr << std::endl; // 访问已经被销毁的指针
    else std::cout<<"*****"<<std::endl;
}
int main() {
    int x = 1;
    std::thread t(foo, &x); // 传递指向局部变量的指针
    t.join();
    return 0;
}



#if 0

#include<iostream>
#include<thread>

std::thread t;

void foo(int &x){
    x += 1;
}

void test()
{
    int a = 1; //应该放到全局
    t = std::thread(foo,std::ref(a));
}

int main()
{

    test();
    t.join();
    std::cout<<"****"<<std::endl;
    


    return 0;
}

#endif
