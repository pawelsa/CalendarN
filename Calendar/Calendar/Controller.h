#pragma once
#include "Calendar.h"
#include "EventHelper.h"
#include "FileHelper.h"


class Controller {

	Calendar* ActualCalendar;
	Year *ActualYear;
	Month *ActualMonth;
	Day *ActualDay;
	EventHelper *EventH;
	FileHelper* FHelper;
	


public:

	Controller() :ActualYear(NULL) , ActualMonth(NULL), ActualDay(NULL), EventH(NULL) {

		ActualCalendar = new Calendar();	// to bedzie zamiast maina
		FHelper = new FileHelper(ActualCalendar->GetYearList());
		FHelper->LoadData();
	}

	void display() {

		if (EventH) {

			EventH->display();
			return;
		}

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

		if (EventH) {

			if (EventH->intersection(mousePos)) {

				EventH = NULL;
			}
			return;
		}


		if (ActualCalendar->isAddNewEventPressed(mousePos)) {
		
			if (!EventH) {
			
				EventH = new EventHelper(ActualCalendar->GetYearList());
			}

			return;
		}


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

		if (EventH) {

			//delete EventH;	trzeba stworzyc jesli wgl jest potrzebny
			EventH = NULL;
			return;
		}

		if (ActualCalendar) {

			if (ActualYear) {

				if (ActualMonth) {

					if (ActualDay) {

						ActualDay = NULL;
						return;
					}

					if (ActualMonth->moveBack()) {

						ActualMonth = NULL;
						return;
					}

					return;
				}

				ActualYear = NULL;
				return;
			}

		}

	}

	void enterChar(int c) {

		if (EventH) {

			EventH->enterChar(c);
		}
	}

	void SaveData()
	{
		FHelper->SaveData();
	}
};
