#include <iostream>
#include <vector>

void coordinator();
std::vector<double> worker(double row[3], double matrix[3][3]);


int main()
{
	coordinator();
	system("pause");
}


std::vector<double> worker(double row[3], double mat[3][3])
{
	std::vector<double> c;

	for (int j = 0; j < 3; j++)
	{
		c.push_back(0.0);
		for (int k = 0; k < 3; k++)
		{
			c[j] += row[k] * mat[k][j];
		}
	}
	return c;

}


void coordinator()
{
	double a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double b[3][3] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	double c[3][3];

	for (int i = 0; i < 3; i++)
	{
		std::vector<double> temp;
		temp = worker(a[i], b);

		for (int j = 0; j < 3; j++)
		{
			c[i][j] = temp[j];
			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
