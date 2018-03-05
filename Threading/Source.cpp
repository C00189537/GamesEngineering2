#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

void producer();
void consumer();

int buf, p = 0, c = 0;
const int n = 5;

static int counter = 0;
std::mutex m_lock;


int main()
{
	std::thread producer(producer);
	std::thread consumer(consumer);
	producer.join();
	consumer.join();
	std::cin.get();
}
void producer()
{
	int a[n] = { 1, 2, 3, 4, 5 };
	bool run = true;
	while (run)
	{
		
		while (p < n)
		{			
			std::cout << "ID P: " << std::this_thread::get_id()  << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			while (!(p == c))
			{
				//std::cout << "Spinning: " << std::endl;
			}
			//lock here
			m_lock.lock();
			buf = a[p];
			m_lock.unlock();
			std::cout << a[p] << " deposited in buffer" << std::endl;
			p++;
		}
		std::cout << "Production Finished" << std::endl;
		run = false;
	}
	
	
}
void consumer()
{
	int b[n];
	bool run = true;
	while (run)
	{
		while (c < n)
		{
			std::cout << "ID C: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			while ((p <= c))
			{
				//std::cout << "Spinning: " << std::endl;
			}
			b[c] = buf;
			std::cout << buf << " deposited in b[]" << std::endl;
			c++;
		}
		std::cout << "Consumption Finished" << std::endl;
		run = false;
	}
}
