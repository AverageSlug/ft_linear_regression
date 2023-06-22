#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

int		main()
{
	std::fstream		file;
	std::string			str;
	std::vector<int>	data[2];

	file.open("data3.csv", std::ios::in);
	if (!file)
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	std::getline(file, str);
	while (file)
	{
		std::getline(file, str);
		if (str.size())
		{
			data[0].push_back(atoi(str.substr(0, str.find(",")).c_str()));
			data[1].push_back(atoi(str.substr(str.find(",") + 1, str.size()).c_str()));
		}
	}
	file.close();

	double	learningRate = 0.02;
	double	m = data[0].size();
	double	theta0t = 0, theta1t = 0;

	for (int i = 0; i < 10000; i++)
	{
		double	seum0 = 0, seum1 = 0;
		double	cost = 0;

		for (int j = 0; j < m; j++)
		{
			double	est = theta0t + (theta1t * data[0][j]);
			cost += (data[1][j] - est) * (data[1][j] - est);
			seum0 += data[1][j] - est;
			seum1 += (data[1][j] - est) * data[0][j];
		}
		cost /= m;
		theta0t += learningRate * seum0 * (1 / m);
		theta1t += learningRate * seum1 * (1 / m);
		std::cout << theta0t << " | " << theta1t << " | " << cost << std::endl;
		// std::cout << seum0 << " | " << seum1 << std::endl;
	}
	std::ofstream	ofs;
	ofs.open("theta", std::ofstream::out | std::ofstream::trunc);
	ofs << theta0t << std::endl << theta1t;
	ofs.close();
}
