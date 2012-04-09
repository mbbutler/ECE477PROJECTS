#ifndef PIDCONTROL_H_
#define PIDCONTROL_H_

struct pid_values{
int Kp; //constants for the pid controllers
int Ki;
int Kd;
long long accum_error;
int old_error; //the old error value
unsigned int gain_limit; // gain output is forced into the interval [-limit,limit]
};


struct goal_attrib{ //what we want all of the sensor data to be to have a certain mode. 
int yaw;
int pitch;
int altitude;
int roll;
};

void set_attrib(struct pid_values *s, int p, int i, int d,int limit) {
	s->Kp = p;
	s->Ki = i;
	s->Kd = d;
	s->old_error = 0;
	gain_limit = limit;
}

int get_gain(struct pid_values *s, int goal, int actual){
	int error = goal - actual;
	int derivative = error - s->old_error;
	s->old_error = error;
	int gain = (s->Kp)/1000.*error + (s->Kd)/1000.*derivative;
	if(gain > limit)
		gain = limit;
	if(gain < -limit)
		gain = -limit;
	return gain;
}
#endif
