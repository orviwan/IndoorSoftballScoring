#include "iss.h"
#include "iss_windows.h"
#include <pebble.h>
	

void format_time(double count_time, char* buffer) {
	int tenths = (int)(count_time * 10) % 10;
	int seconds = (int)count_time % 60;
	int minutes = (int)(count_time / 60) % 60;

	snprintf(buffer, 8, "%02d:%02d.%d", minutes, seconds, tenths);
}

double float_time_ms() {
	time_t seconds;
	uint16_t milliseconds;
	time_ms(&seconds, &milliseconds);
	return (double)seconds + ((double)milliseconds / 1000.0);
}

void handle_timer(void* data) {
	double now = float_time_ms();
	if (Paused){
		Last_time = now;
	}
	else {
		Elapsed_time += now - Last_time;
		Last_time = now;
		update_timer = app_timer_register(100, handle_timer, NULL);
		Display_time = INNINGS_TIME - Elapsed_time;
		format_time(Display_time, t_timeleft);
		text_layer_set_text(s_TimeLeft, t_timeleft);
	}
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
	if (!Started) {
		/*update_timer = app_timer_register(100, handle_timer, NULL);*/
		Started = true;
		Select_Status = ISS_PAUSE;
		text_layer_set_text(s_Status,"Pause");
	} else {
		/* if () */
		text_layer_set_text(s_Status,"End");
	}
	
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
	if (Started || Paused){
		if (Away){
			AwayScore[Inning]++;
			if (AwayScore[Inning] < 0 ){
				snprintf(t_AwayScore,5,"%03d",AwayScore[Inning]);
				text_layer_set_text(s_AwayScore,t_AwayScore);
			} else {
				snprintf(t_AwayScore,5,"+%03d",AwayScore[Inning]);
				text_layer_set_text(s_AwayScore,t_AwayScore);
			}
		}
		else {
			HomeScore[Inning]++;
			if (HomeScore[Inning] < 0){
				snprintf(t_HomeScore,5,"%03d",HomeScore[Inning]);
				text_layer_set_text(s_HomeScore,t_HomeScore);
			} else {
				snprintf(t_HomeScore,5,"+%03d",HomeScore[Inning]);
				text_layer_set_text(s_HomeScore,t_HomeScore);
			}
		}
	}
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
	if (Started || Paused){
		if (Away){
			AwayScore[Inning]--;
			if (AwayScore[Inning] < 0){
				snprintf(t_AwayScore,5,"%03d",AwayScore[Inning]);
				text_layer_set_text(s_AwayScore,t_AwayScore);
			} else {
				snprintf(t_AwayScore,5,"+%03d",AwayScore[Inning]);
				text_layer_set_text(s_AwayScore,t_AwayScore);
			}
		}
		else{
			HomeScore[Inning]--;
			if (HomeScore[Inning] < 0){
				snprintf(t_HomeScore,5,"%03d",HomeScore[Inning]);
				text_layer_set_text(s_HomeScore,t_HomeScore);
			} else {
				snprintf(t_HomeScore,5,"+%03d",HomeScore[Inning]);
				text_layer_set_text(s_HomeScore,t_HomeScore);
			}
			
		}
	}
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void init(void) {
	show_iss_windows();
	window_set_click_config_provider(s_window, click_config_provider);
}

static void deinit(void) {
	hide_iss_windows();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
