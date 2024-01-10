#pragma once
#include "students.h"
#include "Locations.h"
#include "DateTime.h"
#include "cooks.h"
#include "Cleaners.h"
#include "Guards.h"

unsigned int guard_shift = 6;
unsigned int cleaner_shift= 6;
unsigned int cook_shift = 6;

class Update
{
public:
	Update(DateTime llu, DateTime lcu, DateTime llc, DateTime lvu, DateTime lku, DateTime lce, DateTime lgu, students *in, Locations *ip, cooks* _coo, Cleaners* _cle, Guards* _gur);
	void update_late();
	void update_clean_status();
	void update_clear_late();
	void update_visitor();
	void update_duty();
	void update_duty_cleaners();
	void update_duty_cooks();
	void update_duty_guards();
	void update_all();
private:
	DateTime lastLate_update;
	DateTime lastClean_update;
	DateTime lastLate_clear;
	DateTime lastVisitor_update;
	DateTime lastCook_update;
	DateTime lastCleaner_update;
	DateTime lastGuard_update;

	students* stu;
	Locations* loc;
	cooks* coo;
	Cleaners* cle;
	Guards* gur;
};

