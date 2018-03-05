#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

struct sem
{
	int empty = 5, full = 0;
};

void producer();
void consumer();

int buf, p = 0, c = 0;
int rear = 0, front = 0;
int s_buf[5];

const int n = 5;

void P(int &s);
void V(int &s);

sem m_sem;

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
			buf = a[p];
			std::cout << a[p] << " deposited in buffer" << std::endl;

			//Semaphore
			P(m_sem.empty);
			s_buf[rear] = buf;
			rear = (rear + 1) % n;
			V(m_sem.full);

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
			//b[c] = buf;
			std::cout << buf << " deposited in b[]" << std::endl;

			//Semaphore
			P(m_sem.full);
			b[c] = s_buf[front];
			front = (front + 1) % n;
			V(m_sem.empty);

			c++;
		}
		std::cout << "Consumption Finished" << std::endl;
		run = false;
	}
}
void P(int &s)
{
	while (s > 0)
	{
		s--;
	}
}

void V(int &s)
{
	s++;
}