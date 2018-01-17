#include <vector>

int main()
{

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
