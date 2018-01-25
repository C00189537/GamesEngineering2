#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex m_lock;
static int counter = 0;
void fun();

int main(void)
{
	std::thread t1(fun);
	t1.join();
	std::cin.get();
}
void fun()
{
	while (true)
	{
		m_lock.lock();
		counter++;
		std::cout << "Counter: " << counter << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		m_lock.unlock();
	}
}