class OhmToTemp103AT
{
public:
	static double Convert(double);
private:
	static double CalculateValue(double, double, double, int);
};

double OhmToTemp103AT::Convert(double ohm)
{

	if (ohm >= 329.5)
		return -50;
	else if (ohm < 329.5 && ohm >= 247.7)
		return CalculateValue(ohm, 329.5, 247.7, -45);
	else if (ohm < 247.7 && ohm >= 188.5)
		return CalculateValue(ohm, 247.7, 188.5, -40);
	else if (ohm < 188.5 && ohm >= 144.1)
		return CalculateValue(ohm, 188.5, 144.1, -35);
	else if (ohm < 144.1 && ohm >= 111.3)
		return CalculateValue(ohm, 144.1, 111.3, -30);
	else if (ohm < 111.3 && ohm >= 86.43)
		return CalculateValue(ohm, 111.3, 86.43, -25);
	else if (ohm < 86.43 && ohm >= 67.77)
		return CalculateValue(ohm, 86.43, 67.77, -20);
	else if (ohm < 67.77 && ohm >= 53.41)
		return CalculateValue(ohm, 67.77, 53.41, -15);
	else if (ohm < 53.41 && ohm >= 42.47)
		return CalculateValue(ohm, 53.41, 42.47, -10);
	else if (ohm < 42.47 && ohm >= 33.90)
		return CalculateValue(ohm, 42.47, 33.90, -5);
	else if (ohm < 33.90 && ohm >= 27.28)
		return CalculateValue(ohm, 33.90, 27.28, 0);
	else if (ohm < 27.28 && ohm >= 22.05)
		return CalculateValue(ohm, 27.28, 22.05, 5);
	else if (ohm < 22.05 && ohm >= 17.96)
		return CalculateValue(ohm, 22.05, 17.96, 10);
	else if (ohm < 17.96 && ohm >= 14.69)
		return CalculateValue(ohm, 17.96, 14.69, 15);
	else if (ohm < 14.69 && ohm >= 12.09)
		return CalculateValue(ohm, 14.69, 12.09, 20);
	else if (ohm < 12.09 && ohm >= 10.00)
		return CalculateValue(ohm, 12.09, 10.00, 25);
	else if (ohm < 10.00 && ohm >= 8.313)
		return CalculateValue(ohm, 10.00, 8.313, 30);
	else if (ohm < 8.313 && ohm >= 6.940)
		return CalculateValue(ohm, 8.313, 6.940, 35);
	else if (ohm < 6.940 && ohm >= 5.827)
		return CalculateValue(ohm, 6.940, 5.827, 40);
	else if (ohm < 5.827 && ohm >= 4.911)
		return CalculateValue(ohm, 5.827, 4.911, 45);
	else if (ohm < 4.911 && ohm >= 4.160)
		return CalculateValue(ohm, 4.911, 4.160, 50);
	else if (ohm < 4.160 && ohm >= 3.536)
		return CalculateValue(ohm, 4.160, 3.536, 55);
	else if (ohm < 3.536 && ohm >= 3.020)
		return CalculateValue(ohm, 3.536, 3.020, 60);
	else if (ohm < 3.020 && ohm >= 2.588)
		return CalculateValue(ohm, 3.020, 2.588, 65);
	else if (ohm < 2.588 && ohm >= 2.228)
		return CalculateValue(ohm, 2.588, 2.228, 70);
	else if (ohm < 2.228 && ohm >= 1.924)
		return CalculateValue(ohm, 2.228, 1.924, 75);
	else if (ohm < 1.924 && ohm >= 1.668)
		return CalculateValue(ohm, 1.924, 1.668, 80);
	else if (ohm < 1.668 && ohm >= 1.451)
		return CalculateValue(ohm, 1.668, 1.451, 85);
	else if (ohm < 1.451 && ohm >= 1.266)
		return CalculateValue(ohm, 1.451, 1.266, 90);
	else if (ohm > 1.266)
		return 95;
}

double OhmToTemp103AT::CalculateValue(double ohmValue, double ohmMaxLimit, double ohmMinLimit, int tempValue)
{
	double overMinValue = ohmValue - ohmMinLimit;
	double totalDifference = ohmMaxLimit - ohmMinLimit;
	return tempValue - ((5 / totalDifference) * overMinValue);
}
