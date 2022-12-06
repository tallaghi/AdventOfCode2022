#include "Days.h"
#include "AllDays.h"
#include "Util.h"

void RunDay(int i) {
	if (i == 1) {
		RunDay1();
	}
	
	else if (i == 2) {
		RunDay2();
	}

	else if (i == 3) {
		RunDay3();
	}

	else if (i == 4) {
		RunDay4();
	}

	else if (i == 5) {
		RunDay5();
	}

	else if (i == 6) {
		RunDay6();
	}
}