// #define GENERATOR true

#if defined(GENERATOR)
	#include "PWMGenerator.h"

	PWMGenerator servo_1;
	PWMGenerator servo_2;
	PWMGenerator servo_3;
	PWMGenerator servo_4;
	PWMGenerator servo_5;
#else
	#include <Servo.h>

	Servo servo_1;
	Servo servo_2;
	Servo servo_3;
	Servo servo_4;
	Servo servo_5;
#endif

void setup()
{
	#if defined(GENERATOR)
		servo_1.setup(23);
		servo_2.setup(25);
		servo_3.setup(27);
		servo_4.setup(29);
		servo_5.setup(31);

		servo_1.timer(500);
		servo_2.timer(1000);
		servo_3.timer(1500);
		servo_4.timer(2000);
		servo_5.timer(2500);
	#else
		servo_1.attach(23);
		servo_2.attach(25);
		servo_3.attach(27);
		servo_4.attach(29);
		servo_5.attach(31);

		servo_1.writeMicroseconds(500);
		servo_2.writeMicroseconds(1000);
		servo_3.writeMicroseconds(1500);
		servo_4.writeMicroseconds(2000);
		servo_5.writeMicroseconds(2500);
	#endif
}

void loop()
{
	#if defined(GENERATOR)
		long current_time = micros();

		servo_1.handler(current_time);
		servo_2.handler(current_time);
		servo_3.handler(current_time);
		servo_4.handler(current_time);
		servo_5.handler(current_time);
	#endif
}
