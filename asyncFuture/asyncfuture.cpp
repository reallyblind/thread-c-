#include<iostream>
#include<future>

void func(std::promise<int>  &f){
    f.set_value(1000);

}

int main()
{
    std::promise<int> f;
    auto future_result = f.get_future();

    std::thread t1(func,std::ref(f));

    
    t1.join();
    std::cout<<future_result.get()<<std::endl;

    return 0;
}


#if 0
int func(){
    int i = 0;
    for(i = 0 ; i < 10 ; i++ ){
        std::cout<< "func" <<i << "is runing"<<std::endl;
    }
    return i;
}

int main(){
    //std::future<int> future_result =  std::async(std::launch::async, func);//直接在后台运行
    std::packaged_task<int()> task (func);//不会自动开启线程,只是把函数地址包裹成一个对象
    auto future_result = task.get_future();
    
    std::thread t1(std::move(task));

    std::cout<<func()<<std::endl;
    t1.join();
    std::cout<< future_result.get()<<std::endl;//等待future_result运行完再调用get


}
#endif