#pragma once
#include <pebble.h>
	
void show_iss_windows(void);
void hide_iss_windows(void);

#define INNINGS_TIME 300000 /* Each Inning is 5m or 300s or 300000ms */
#define MAX_INNINGS 2 /* 2 innings per game */
#define ISS_START 1
#define ISS_PAUSE 2
#define ISS_CHANGE 3
#define ISS_END 4

/*
 * window definitions
 */

static Window *s_window;
static GFont s_res_gothic_18_bold;
static TextLayer *s_Up;
static TextLayer *s_Down;
static TextLayer *s_HomeAway;
static TextLayer *s_Status;
static TextLayer *s_HomeScore;
static TextLayer *s_AwayScore;
static TextLayer *s_TimeLeft;
static TextLayer *s_Innings;
static TextLayer *s_Home_const;
static TextLayer *s_Away_const;

/*
 * Text for windows
 */

static char t_timeleft[8] = "05:00.0";
static char t_HomeScore[5] = "+000";
static char t_AwayScore[5] = "+000";
static char t_Inning[5] = "In:1";
static char t_Status[7] = "Start";
static char t_HomeAway[5] = "Away";

/*
 * Globals
 */

static bool Away = true;
static int HomeScore[2] = {0,0};
static int AwayScore[2] = {0,0};
static int TotalHome = 0;
static int TotalAway = 0;
static int Inning = 0;
static bool Started = false;
static bool Paused = false;
static bool Change = false;
static int Select_Status = ISS_START;

/*
 * Time structure
 */

static double Elapsed_time = 0;
static double Last_time = 0;
static double Display_time = INNINGS_TIME;

/*
 * Application timer structure for a 100ms timer
 */
static AppTimer* update_timer = NULL;

