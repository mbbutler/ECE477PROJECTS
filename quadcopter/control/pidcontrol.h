#ifndef PIDCONTROL_H_
#define PIDCONTROL_H_
#include <stdlib.h>

struct pid_values{
float Kp; //constants for the pid controllers
float Ki;
float Kd;
int old_error; //the old error value
unsigned int old_time;	//time between readings
};


struct goal_attrib{ //what we want all of the sensor data to be to have a certain mode. 
int yaw;
int pitch;
int altitude;
int roll;
};

void set_attrib(struct pid_values *s, float p, float i, float d, int error, unsigned int time) {
	s->Kp = p;
	s->Ki = i;
	s->Kd = d;
	s->old_error = error;
	s->old_time = time;
}

//calculates the error
int get_diff(int goal, int measure){
	return goal - measure;
}

//calculates the integral of error
float get_integral(struct pid_values *s, int error, int delta_t){
	float integral = delta_t * ((s->old_error + error) / 2.);		
	return integral;
}

//calculates the derivative error
float get_deriv(struct pid_values *s, int error, int delta_t){
	float derivative = (error - s->old_error) / ((float) (delta_t));
	s->old_error = error;
	return derivative;
}

float get_gain(struct pid_values *s, float goal, float actual, unsigned int time){
	int delta_t = time - s->old_time;
	if (delta_t < 0) {
		delta_t = 0xFFFF - s->old_time + time + 1; 
	}
	s->old_time = time;
	int error = get_diff(goal, actual);
	return (s->Kp)*error + (s->Ki)*get_integral(s, error, delta_t) + (s->Kd)*get_deriv(s, error, delta_t);
}
#endif
