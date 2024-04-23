#include<iostream>
#include<thread>



void printHelloworld()
{
    std::cout<<"*************************************"<<std::endl;
    std::cout<<"*************************************"<<std::endl;
    std::cout<<"*************************************"<<std::endl;
    for(int i = 0  ;i<100000; i++)
        std::cout<<i<<" ";

    std::cout<<std::endl;
    std::cout<<"Hello World!"<<std::endl;
    return;
}


int main()
{

    //1.创建线程,起点是printHelloworld.  printHelloworld线程开始运行
    std::thread thread1(printHelloworld);

    bool isJoin = thread1.joinable();//可以join或者detach
    if(isJoin){
        //阻塞主线程,主线程等待子线程完成,然后子线程和主线程汇合,再往下执行
        thread1.join();
    }
    std::cout<<"over"<<std::endl;

    std::thread thread2(printHelloworld);
    //分离线程,子线程在后台运行,主线程无需等待自线程执行完才继续向下执行.所以主程序执行完之后,thread1销毁了,
    thread2.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    

    return 0;
}