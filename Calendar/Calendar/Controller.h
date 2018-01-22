#pragma once
#include "Calendar.h"


class Controller {

	Calendar* ActualCalendar;
	Year *ActualYear;
	Month *ActualMonth;
	Day *ActualDay;
	Event *AddEvent;


public:

	Controller() :ActualYear(NULL) , ActualMonth(NULL), ActualDay(NULL){

		ActualCalendar = new Calendar();	// to bedzie zamiast maina

	}

	display() {

		if (ActualCalendar) {


			if (ActualYear) {

				if (ActualMonth) {

					if (ActualDay) {

						display_DAy()
					}

					displayMonth()
				}
				displayYear()
			}
			displayCalendar()
		}


	}



};
