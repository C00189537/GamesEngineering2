#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

struct sem
{
	int empty = 1, full = 0, rw = 1, mutexR = 1;
};

void producer();
void consumer();

void reader();
void writer();

//number of readers
int nr = 0;

int buf, p = 0, c = 0;
int rear = 0, front = 0;
int s_buf[5];

const int n = 5;

void P(int &s);
void V(int &s);

sem m_sem;


int main()
{
	/*std::thread producer(producer);
	std::thread consumer(consumer);
	producer.join();
	consumer.join();*/

	std::thread reader(reader);
	std::thread writer(writer);
	reader.join();
	writer.join();

	std::cin.get();
}
void producer()
{
	int a[n] = { 1, 2, 3, 4, 5 };
	bool run = true;
	while (run)
	{
				
		std::cout << "ID P: " << std::this_thread::get_id()  << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		while (!(p == c))
		{
			//std::cout << "Spinning: " << std::endl;
		}
		buf = a[1];
		std::cout << a[p] << " deposited in buffer" << std::endl;

		//Semaphore
		P(m_sem.empty);
		s_buf[rear] = buf;
		rear = (rear + 1) % n;
		V(m_sem.full);

		p++;
		std::cout << "Production Finished" << std::endl;
	}
	
	
}
void consumer()
{
	int b[n];
	bool run = true;
	while (run)
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
		std::cout << "Front " << front << std::endl;
		V(m_sem.empty);

		c++;

		std::cout << "Consumption Finished" << std::endl;

	}
}

void reader()
{
	bool run = true;
	while (run)
	{
		std::cout << "ID R: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//Begin
		P(m_sem.mutexR);
		nr++;
		if (nr==1)
		{
			P(m_sem.rw);
		}
		//Get lock
		V(m_sem.mutexR);
		//read database
		std::cout << "Database Read" << std::endl;
		P(m_sem.mutexR);
		nr--;
		if (nr == 0)
		{
			V(m_sem.rw);
		}
		//Release lock
		V(m_sem.mutexR);

	}
}
void writer()
{
	bool run = true;
	while (run)
	{
		std::cout << "ID W: " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		P(m_sem.rw);
		//write to db
		std::cout << "Write to db" << std::endl;
		V(m_sem.rw);
	}
}

void P(int &s)
{
	while (s <= 0)
	{
		//std::cout << "Spinning" << std::endl;
	}
	s--;
}

void V(int &s)
{
	s++;
}