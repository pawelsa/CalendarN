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

	void display() {

		if (ActualCalendar) {

			if (ActualYear) {

				if (ActualMonth) {

					if (ActualDay) {

						ActualDay->display_Day();
						return;
					}

					ActualMonth->displayMonth();
					return;
				}

				ActualYear->displayYear();
				return;
			}

			ActualCalendar->display_Calendar();
			return;
		}

	}

	void intersection(sf::Vector2f mousePos) {

		//if (ActualCalendar->isAddNewEventPressed(mousePos)) {}

		if (ActualCalendar) {

			if (ActualYear) {

				if (ActualMonth) {

					if (ActualDay) {

						//ActualDay->doTheyIntersect_Day(mousePos);
						return;
					}

					ActualDay = ActualMonth->doTheyIntersect_Month(mousePos);
					return;
				}

				ActualMonth = ActualYear->doTheyIntersect_Year(mousePos);
				return;
			}

			ActualYear = ActualCalendar->doTheyIntersect_Calendar(mousePos);
			return;

		}

	}

	void moveToLastScreen() {

		if (ActualCalendar) {

			if (ActualYear) {

				if (ActualMonth) {

					if (ActualDay) {

						ActualDay = NULL;
						return;
					}

					ActualMonth = NULL;
					return;
				}

				ActualYear = NULL;
				return;
			}

		}

	}
};
