#include "Days.h"
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
}