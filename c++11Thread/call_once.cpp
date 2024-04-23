#include<iostream>
#include<thread>
#include<mutex>


class Log{
public:
    Log(){};
    Log(const Log&log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance(){
        //static Log log; //饿汉模式
        std::call_once(once,&init);
        return *log;
    }

    static void init(){
        if(log != nullptr) log.reset(new Log);
    }

    void PrintLog(std::string msg){
        std::cout<<__TIME__<<" "<<msg<<std::endl;
    }

private:
    static std::once_flag once;
    static std::unique_ptr<Log> log;
};
std::unique_ptr<Log> Log::log;
std::once_flag Log::once;


void print_error(){
    Log::GetInstance().PrintLog("error");
}



int main()
{
    std::thread t1(print_error);
    std::thread t2(print_error);
    t1.join();
    t2.join();

    return 0;
}
