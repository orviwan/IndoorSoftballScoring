#include "iss_windows.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
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

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, 0);
  
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  // s_Up
  s_Up = text_layer_create(GRect(117, 18, 20, 20));
  text_layer_set_text(s_Up, "+");
  text_layer_set_text_alignment(s_Up, GTextAlignmentCenter);
  text_layer_set_font(s_Up, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Up);
  
  // s_Down
  s_Down = text_layer_create(GRect(118, 117, 20, 20));
  text_layer_set_text(s_Down, "-");
  text_layer_set_text_alignment(s_Down, GTextAlignmentCenter);
  text_layer_set_font(s_Down, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Down);
  
  // s_HomeAway
  s_HomeAway = text_layer_create(GRect(7, 10, 44, 26));
  text_layer_set_text(s_HomeAway, "Away");
  text_layer_set_text_alignment(s_HomeAway, GTextAlignmentCenter);
  text_layer_set_font(s_HomeAway, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_HomeAway);
  
  // s_Status
  s_Status = text_layer_create(GRect(82, 63, 55, 20));
  text_layer_set_text(s_Status, "Start");
  text_layer_set_text_alignment(s_Status, GTextAlignmentCenter);
  text_layer_set_font(s_Status, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Status);
  
  // s_HomeScore
  s_HomeScore = text_layer_create(GRect(17, 48, 42, 20));
  text_layer_set_text(s_HomeScore, "+000");
  text_layer_set_text_alignment(s_HomeScore, GTextAlignmentCenter);
  text_layer_set_font(s_HomeScore, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_HomeScore);
  
  // s_AwayScore
  s_AwayScore = text_layer_create(GRect(17, 73, 42, 20));
  text_layer_set_text(s_AwayScore, "+000");
  text_layer_set_text_alignment(s_AwayScore, GTextAlignmentCenter);
  text_layer_set_font(s_AwayScore, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_AwayScore);
  
  // s_TimeLeft
  s_TimeLeft = text_layer_create(GRect(6, 107, 59, 20));
  text_layer_set_text(s_TimeLeft, "05:00.0");
  text_layer_set_text_alignment(s_TimeLeft, GTextAlignmentCenter);
  text_layer_set_font(s_TimeLeft, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_TimeLeft);
  
  // s_Innings
  s_Innings = text_layer_create(GRect(58, 10, 44, 26));
  text_layer_set_text(s_Innings, "In:1");
  text_layer_set_text_alignment(s_Innings, GTextAlignmentCenter);
  text_layer_set_font(s_Innings, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Innings);
  
  // s_Home_const
  s_Home_const = text_layer_create(GRect(3, 48, 12, 20));
  text_layer_set_text(s_Home_const, "H");
  text_layer_set_text_alignment(s_Home_const, GTextAlignmentCenter);
  text_layer_set_font(s_Home_const, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Home_const);
  
  // s_Away_const
  s_Away_const = text_layer_create(GRect(3, 73, 12, 20));
  text_layer_set_text(s_Away_const, "A");
  text_layer_set_text_alignment(s_Away_const, GTextAlignmentCenter);
  text_layer_set_font(s_Away_const, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Away_const);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_Up);
  text_layer_destroy(s_Down);
  text_layer_destroy(s_HomeAway);
  text_layer_destroy(s_Status);
  text_layer_destroy(s_HomeScore);
  text_layer_destroy(s_AwayScore);
  text_layer_destroy(s_TimeLeft);
  text_layer_destroy(s_Innings);
  text_layer_destroy(s_Home_const);
  text_layer_destroy(s_Away_const);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_iss_windows(void) {
	initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_iss_windows(void) {
  window_stack_remove(s_window, true);
}
