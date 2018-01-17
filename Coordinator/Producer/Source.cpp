#include <vector>
#include <iostream>

int main()
{

}
void coordinator()
{
	double a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double b[3][3] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	double c[3][3];

	for (int i = 0; i < 3; i++)
	{
		std::vector<double> temp;
		//temp = worker(a[i], b);

		for (int j = 0; j < 3; j++)
		{
			c[i][j] = temp[j];
			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
	}
}