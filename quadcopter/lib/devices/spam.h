#ifndef SPAM_H_
#define SPAM_H_
#include <string.h>
#include "../data.h"
#include "magnetometer.h"
//#include "barometer.h"
#include "gyro.h"
#include "nunchuck.h"

void spam(int sensor_code,long value){
	char temp[40];	
        sprintf(temp,"%c%c%ld",SENSORDATAPACKETCHARACTER,sensor_code,value);
	transmit(temp);
}
void spam_magnetometer(){
	spam(COMPASSHEADING,sensor_data_cache.compass_heading);
}

void spam_sonar(){
/*	char temp[40];
	sprintf(temp,"alt: %ld",sensor_data_cache.filt_altitude);
	transmit(temp);*/
	spam(SONARDISTANCE,sensor_data_cache.filt_altitude);
}
/*
void spam_barometer(){
	spam(BAROMETERTEMPERATURE,sensor_data_cache.barometer_temperature);
	spam(BAROMETERPRESSURE,sensor_data_cache.barometer_pressure);
	spam(BAROMETERALTITUDE,sensor_data_cache.barometer_altitude);
}*/

void spam_gyro(){
	spam(GYROSCOPEY,sensor_data_cache.gyroscope_x_rotational_velocity);
	spam(GYROSCOPEX,sensor_data_cache.gyroscope_y_rotational_velocity);
	spam(GYROSCOPETEMPERATURE,sensor_data_cache.gyroscope_temperature);
}

void spam_nunchuck(){
	spam(NUNCHUCKX,sensor_data_cache.nunchuck_x_value);
	spam(NUNCHUCKY,sensor_data_cache.nunchuck_y_value);
	spam(NUNCHUCKZ,sensor_data_cache.nunchuck_z_value);
}

void spam_nunchuck_angles(){
	spam(YAW,sensor_data_cache.yaw);
	spam(PITCH,sensor_data_cache.filt_pitch_angle);
	spam(ROLL,sensor_data_cache.filt_roll_angle);

}

void spam_gain(){
	spam(ALTGAIN,sensor_data_cache.alt_gain);
	spam(ROLLGAIN,sensor_data_cache.roll_gain);
	spam(PITCHGAIN,sensor_data_cache.pitch_gain);
}

void send_spam(){
	spam_magnetometer();
	spam_sonar();
	//spam_barometer();
	spam_gyro();
	spam_nunchuck();
	spam_nunchuck_angles();
	spam_gain();
}
#endif
