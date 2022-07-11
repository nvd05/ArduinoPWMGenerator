#include "PWMGenerator.h"
#include <Arduino.h>

void PWMGenerator::handler(long current_time)
{
	long elapsed_time = current_time - _lastPulseTime;

	if (elapsed_time <= _period)
	{
		return;
	}

	_lastPulseTime = current_time;
	_signal = !_signal;

	digitalWrite(_pin, _signal);
}

void PWMGenerator::timer(int period)
{
	_period = period;
}

void PWMGenerator::setup(int pin)
{
	pinMode(_pin, OUTPUT);

	_lastPulseTime = micros();
	_signal        = LOW;
	_pin           = pin;
}
