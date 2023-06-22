#include <iostream>
#include <fstream>

int		main()
{
	std::fstream	file;
	std::string		str;
	double			theta0, theta1, x;

	file.open("theta", std::ios::in);
	if (!file)
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	std::getline(file, str);
	theta0 = stod(str);
	std::getline(file,str);
	theta1 = stod(str);
	file.close();
	std::cout << "type mileage: " << std::endl;
	std::cin >> x;
	std::cout << "price = " << theta0 + (theta1 * x) << std::endl;
}
