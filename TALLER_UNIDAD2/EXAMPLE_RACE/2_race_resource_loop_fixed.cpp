#include <iostream>
#include <thread>
#include <mutex>

std::mutex mymutex;

void share_cout(std::string msg, int id)
{
	mymutex.lock();
        std::cout << msg << ":" << id << "\n";
	mymutex.unlock();
}


void thread_function()
{
    for (int i = -100; i < 0; i++)
	share_cout("thread function: ", i);
//        std::cout << "thread function: " << i << "\n";
}

int main()
{
	std::thread t(&thread_function);
	for (int i = 0; i < 100; i++)
		share_cout("main thread: ", i);
//	    std::cout << "main thread: " << i << "\n";
	t.join();
	return 0;
}
