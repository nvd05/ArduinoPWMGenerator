#pragma once

class PWMGenerator
{
private:
	long _lastPulseTime;
	bool _signal;

	int _period;
	int _pin;

public:
	void handler(long current_time);
	void timer(int period);
	void setup(int pin);
};
