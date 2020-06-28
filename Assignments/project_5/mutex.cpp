// 注释行 不要动
// #0#BEGIN# 定位行 /注释行 不要动
// 注释行 不要动
// 注释行 不要动
// #0#END# 代码戳 定位 /注释行 不要动

#include <stdio.h>
#include <pthread.h>
#include <iostream>
using namespace std;
// 注释行 不要动
// 注释行 不要动

// 注释行 不要动
// 为了简单起见，我们使用整数来表示一个数据单元
// 因此，这些代码将执行生成最多10个整数
#define MAX 10 

// 我们需要用到 <mutex> 来确保每次只有一个线程访问buffer
// 可以是consumer thread 或者是producer thread.
pthread_mutex_t the_mutex;

// blocked thread 在做出动作之前等待红绿灯
// 条件变量是告诉线程的红绿灯
// 检查buffer是否可用
// 两个变量是 ”condc", "condp"
// 分别是consumer thread 和 producer thread 的红绿灯
pthread_cond_t condc, condp; 

// 为了简化模拟，我们使用整数来作buffer
// buffer 存储一个unith数据，既是一个整数
int buffer = 0;

void *producer(void *ptr)
{
    int i;
    for(i=1; i<=MAX; i++)
    {
	// Step 1, 使用function 锁定 mutex
	// 这样只有producer thread 在使用 buffer You
	// 你不想有其他人进入
	// 如果这个mutex已经准备好被锁住有人正在使用
	// 这个线程将被等待，当你在使用的时候你也需要锁上
	// 让别人知道你也正在用
        pthread_mutex_lock(&the_mutex); 

	// Step 2, 如果buffer不是空的这意味着buffer中h包含一些数据
	// thread 在输出给buffer之前需要等待红绿灯 "condp"
        while(buffer !=0) pthread_cond_wait(&condp, &the_mutex); 
	
	// Step 3, 在下面producer需要生成一个整数
	// 分配给buffer一个数据单元
        buffer = i*7;

	// Step 4, print输出信息，告诉producer生成了什么
        cout << "producer produce item " << buffer << endl;
	
	// Step 5, 以为buffer只有一个unit所有现在它是满的
	// 我们需要停下来，并通知另一个线程
	// consumer thread 已经准备好了
	// 我们需要使用以下函数将consumer thread的红绿灯改为”绿灯“
        pthread_cond_signal(&condc);
	
	// Step 6, 在我们给另一个线程开绿灯后
	// 我们现在给 mutex 解锁，所以现在他们是可用的
        pthread_mutex_unlock(&the_mutex);
    }

    // Step 7, 退出线程 让他们return 0 成功！
    pthread_exit(0);
    
}

void *consumer(void *ptr)
{
    
    int i;
    int get_data;
    for(i=1; i<=MAX; i++)
    {
        // 在开始之前锁定 mutex
        // #1#BEGIN# 定位 注释行 不要动


	// #1#END# 定位 注释行 不要动

        // 当我们的buffer是空的，没有什么可以使用，我们必须等待
        // producerd看到了Step 2
        // #2#BEGIN# 定位 注释行 不要动


	// #2#END# 定位 注释行 不要动

	// 将buffer大护具分配给variable get_data
	// #3#BEGIN# 定位 注释行 不要动


	// #3#END# 定位 注释行 不要动

        // Print 在get_data中获得的数据
        cout << "consumer consume item " << get_data << endl;

        // 清理buffer 将0 赋值给buffer
        // #4#BEGIN# 定位 注释行 不要动


        // #4#END# 定位 注释行 不要动

	// 通知producer 可以让变量离开了
	// see step 5 example in producer
	// #5#BEGIN# 定位 注释行 不要动


        // #5#END# 定位 注释行 不要动

        // 解锁mutex, step 6 example in producer
        // #6#BEGIN# 定位 注释行 不要动


        // #6#END# 定位 注释行 不要动
    }
    
    // 退出线程, return 0 成功 Step 7
    // #7#BEGIN# 定位 注释行 不要动
 

    // #7#END# 定位 注释行 不要动
    
}

int main(int argc, char *argv[])
{

    // 注释行 不要动 banner
    // #8#BEGIN# 定位 注释行 不要动
    int banner_id = 903950779;
    // #8#END# 定位 注释行 不要动
    cout << "Banner id: " << banner_id << endl;

    pthread_t pro, con; 
    pthread_mutex_init(&the_mutex, 0); // 创建线程使用mutex
    pthread_cond_init(&condc,0);       // 初始化consumer thread变量 condc
    pthread_cond_init(&condp,0);       // 初始化producer的变量 concp
    
    pthread_create(&con, 0, consumer, 0); // 创建函数使用者的线程映射
    pthread_create(&pro, 0, producer, 0); // 创建到函数生成器的线程映射
    pthread_join(pro,0); 		  // 将producer放入系统中
    pthread_join(con,0);		  // 将consumer thread放入系统中

    // 清理 销毁互斥的两个线程
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
    return 0;
}
