#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>
#include <string>
#include "OhmToTemp103AT.h"
#include <errno.h>
#include <wiringPiSPI.h>

using namespace std;

unsigned int sample_SPI_CH0(int channel) {
	unsigned char buf[2];

	buf[0] = 0x60 + channel;
	buf[1] = 0x00;
	wiringPiSPIDataRW(channel, buf, 2);
	return ((buf[0] & 0x03) << 8) | buf[1];
}

int main(void) {

	int Rref = 10000;
	double Resistance;

	int i, channel = 0, hz = 2000000;
	float f, vref = 3.3;

	if (wiringPiSPISetup(channel, hz) < 0) {
		exit(errno);
	}

	f = i = sample_SPI_CH0(channel);
	printf("Value(HEX)=%04X\n", i);
	printf("Voltage:%0.5fV\n", (f * vref) / 1023.0);
	Resistance = (((1024 / f) - 1) * Rref) / 1000;
	printf("Resistance:%f\n", Resistance);
	string result = "Temperature:" + to_string(OhmToTemp103AT::Convert(Resistance)) + "\n";
	cout << result.c_str();
}