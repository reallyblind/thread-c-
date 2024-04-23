#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

std::mutex g_mutex;
std::condition_variable g_cv;
std::queue<int> g_queue;


void Producer(){
    for(int i = 0 ; i < 10 ; i++){
        {
            std::unique_lock<std::mutex> lock(g_mutex);
            g_queue.push(i);
            std::cout << "Producer : produced " << i << std::endl;
        }
        g_cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Consumer()
{
    while(true){
        std::unique_lock<std::mutex> lock(g_mutex);
        // 当消费者阻塞在条件变量时，condition_variable会释放其关联的信号量，直到被notify，所以不会死锁
        g_cv.wait(lock,[](){return !g_queue.empty();});
        int value = g_queue.front();
        g_queue.pop();
        std::cout<<"Consumer : consmed "<<value<<std::endl;
    }

}

int main()
{
    std::thread producer_thread(Producer);
    std::thread consumer_thread(Consumer);
    producer_thread.join();
    consumer_thread.join();

    return 0;
}
