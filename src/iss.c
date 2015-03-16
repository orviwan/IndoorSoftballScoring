#include "iss.h"
#include "iss_windows.h"
#include <pebble.h>
	
static void init(void) {
	show_iss_windows();
}

static void deinit(void) {
	hide_iss_windows();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
