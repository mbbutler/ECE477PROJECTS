#ifndef DISPLAY
#define DISPLAY 1
#include <ncurses.h>

// sets up curses for data display
void setup_display(){
	initscr();
}

void refresh_display(){
	move(0,0);
	printw("                                        ");
	move(0,0);
	printw("Last Command Received: %s",last_command_received);
	char i;
	move(0,40);
	printw("Hex: ");
	for(i=0; i<strlen(last_command_received); i++)
		printw("%hhx",last_command_received[i]);

	move(2,0);
	printw("                                        ");
	move(2,0);
	printw("Compass Heading (degrees): %ld.%ld",sensor_data_cache.compass_heading/100,sensor_data_cache.compass_heading%100);
	
	move(2,40);
	printw("                                        ");
	move(2,40);
	printw("Sonar Distance (feet): %ld.%ld",sensor_data_cache.filt_altitude/100,sensor_data_cache.filt_altitude%100);
	
	move(3,0);
	printw("                                        ");
	move(3,0);
	printw("Barometer Temperature: %ld.%ld",sensor_data_cache.barometer_temperature/100,sensor_data_cache.barometer_temperature%100);

	move(3,40);
	printw("                                        ");
	move(3,40);
	printw("Barometer Pressure: %ld.%ld",sensor_data_cache.barometer_pressure/100,sensor_data_cache.barometer_pressure%100);
	
	move(4,0);
	printw("                                        ");
	move(4,0);
	printw("Barometer Altitude: %ld.%ld",sensor_data_cache.barometer_altitude/100,sensor_data_cache.barometer_altitude%100);
	
	move(5,0);
	printw("                                        ");
	move(5,0);
	printw("Nunchuck X: %ld",sensor_data_cache.nunchuck_x_value);
	
	move(6,0);
	printw("                                        ");
	move(6,0);
	printw("Nunchuck Y: %ld",sensor_data_cache.nunchuck_y_value);
	
	move(7,0);
	printw("                                        ");
	move(7,0);
	printw("Nunchuck Z: %ld",sensor_data_cache.nunchuck_z_value);

	move(8,0);
	printw("                                        ");
	move(8,0);
	printw("Gyroscope Roll (deg/sec): %ld",sensor_data_cache.gyroscope_x_rotational_velocity);
	
	move(8,40);
	printw("                                        ");
	move(8,40);
	printw("Gyroscope Pitch (deg/sec): %ld",sensor_data_cache.gyroscope_y_rotational_velocity);


	move(9,0);
	printw("                                        ");
	move(9,0);
	printw("Yaw   (deg): %ld",sensor_data_cache.yaw);

	move(9,40);
	printw("                                        ");
	move(9,40);
	printw("Alt Gain: %d", sensor_data_cache.alt_gain);
	
	move(10,0);
	printw("                                        ");
	move(10,0);
	printw("Pitch (deg): %ld",sensor_data_cache.filt_pitch_angle);
	
	move(10,40);
	printw("                                        ");
	move(10,40);
	printw("Pitch Gain: %d", sensor_data_cache.pitch_gain);
	
	move(11,0);
	printw("                                        ");
	move(11,0);
	printw("Roll  (deg): %ld",sensor_data_cache.filt_roll_angle);
	
	move(11,40);
	printw("                                        ");
	move(11,40);
	printw("Roll Gain: %d", sensor_data_cache.roll_gain);
	
	move(20,0);
	printw("Type 'q' to quit.");
	
	move(21,0);
	printw("                                        ");
	move(21,0);
	printw(": %s",user_command_buffer);

	move(22,0);
	printw("                                        ");
	move(22,0);
	printw("Number of bytes sent:  %d",number_of_bytes_sent);

	move(23,0);
	printw("                                        ");
	move(23,0);
	printw("Last Command Sent: %s",last_command_sent);
	move(23,40);
	printw("Hex: ");
	for(i=0; i<strlen(last_command_sent); i++)
		printw("%hhx",last_command_sent[i]);
	
	// return the cursor to the command input line
	move(21,strlen(user_command_buffer)+2);
	refresh();
}

//ends the curses window mode
void quit_display(){
	endwin();
}

#endif
