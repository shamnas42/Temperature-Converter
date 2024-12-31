#include <iostream>
#include <string>
#include <cctype>

// Checks if the value of the temperature is an integer / valid
bool isValidInteger(std::string input)
{
	if (input.empty())
	{
		return false; 
	}

	int start = 0;

	if (input[0] == '.')
	{
		input = '0' + input;
	}

	if (input[0] == '+' || input[0] == '-')
	{
		start = 1;
	}

	for (int i = start; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			continue;
		}
		if (!isdigit(input[i]))
		{
			return false; 
		}
	}

	return true; 
}

// Conversions are printed 
void convertC(double userTemperature)
{
	double toKelvin = userTemperature + 273.15;
	double toFahrinheit = userTemperature * (9.0 / 5.0) + 32.0; 

	std::cout << "\n" << userTemperature << " degrees C" << " is:\n" << toKelvin << " K\n" << toFahrinheit << " degrees F\n";
}
void convertK(double userTemperature)
{
	double toCelsius = userTemperature - 273.15;
	double toFahrinheit = (userTemperature - 273.15) * 9 / 5 + 32;

	std::cout << "\n" << userTemperature << " K" << " is:\n" << toCelsius << " degrees C\n" << toFahrinheit << " degrees F\n";
}
void convertF(double userTemperature)
{
	double toCelsius = (userTemperature - 32) * 5 / 9;
	double toKelvin = (userTemperature - 32) * 5 / 9 + 273.15;
	
	std::cout << "\n" << userTemperature << " degrees F" << " is:\n" << toCelsius << " C\n" << toKelvin << " K\n";
}

// Asks for inputs and calls function to convert and print
void askingAndAnswering()
{
	std::string input;
	double userTemperature;
	char temperatureUnit;
 
	while (!isValidInteger(input))
	{
		std::cout << "What temperature do you want to convert?\nEnter number: ";
		getline(std::cin, input);
		if (isValidInteger(input))
		{
			break;
		}
		std::cout << "\nInvalid input. Please try again.\n";
	}

	userTemperature = stod(input); 

	std::cout << "\nWhat unit this number? (C or K or F): ";
	std::cin >> temperatureUnit;

	// Checks for valid response and calls function depending on input
	while (true)
	{
		if (temperatureUnit == 'C')
		{
			convertC(userTemperature);
			break;
		}
		else if (temperatureUnit == 'K')
		{
			convertK(userTemperature);
			break;
		}
		else if (temperatureUnit == 'F')
		{
			convertF(userTemperature);
			break;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input. Please try again.";
			std::cout << "What unit this number? (C or K or F): ";
			std::cin >> temperatureUnit;
		}
	}
}

// Ask if user wants to keep converting 
bool isConverting()
{
	char keepGoing;

	std::cout << "\nDo you want to keep converting? (y/N)\n";
	std::cin >> keepGoing;

	while (true)
	{
		if (keepGoing == 'y')
		{
			return true;
		}
		else if (keepGoing == 'N')
		{
			return false;
		}
		else
		{
			std::cout << "Invalid input. Please try again.";
			std::cout << "\nDo you want to keep converting? (y/N)\n";
			std::cin >> keepGoing;
		}
	}
	return false; 
}

int main()
{
	bool isOn = true;

	while (isOn)
	{
		askingAndAnswering();
		isOn = isConverting();
		std::cout << "\n";
	}

	return 0; 
}