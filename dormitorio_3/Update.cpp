#include "Update.h"
void Update::update_late() {

	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	/*if (DateTime::timeDiffMinute(lastLate_update, curr) > 1439 || curr.getDate() != lastLate_update.getDate()) {
		stu->update_late();
		lastLate_update = chrono::system_clock::now();
	}*/
	
	if (curr.getDate() != lastLate_update.getDate() && curr.isMidnight()) {
		stu->update_late();
		lastLate_update = chrono::system_clock::now();
	}
}
void Update::update_clean_status() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	if (curr.getDate() != lastClean_update.getDate()) {
		loc->resetClean_status();
		lastClean_update = chrono::system_clock::now();
	}
}

void Update::update_clear_late() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	if (curr.areMonthsDifferent(lastLate_clear)) {
		stu->lates_reset();
		lastLate_clear = chrono::system_clock::now();
	}
}

void Update::update_visitor() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	if (curr.getDate() != lastClean_update.getDate() && !curr.isVisiting_hour()) {
		stu->visitor_check();
		lastVisitor_update = chrono::system_clock::now();
	}
}

void Update::update_all() {
	update_clean_status();
	update_late();
	update_clear_late();
	update_duty();
}

void Update::update_duty() {
	update_duty_cleaners();
	update_duty_cooks();
	update_duty_guards();
}

void Update::update_duty_cleaners() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	if (DateTime::timeDiffMinute(lastCleaner_update, curr) > 30) {
		cle->on_duty_updater();
		lastCleaner_update = curr;
	}
	if (DateTime::timeDiffMinute(lastCleaner_update, curr) > 10) {
		cle->late_catcher();
	}
}
void Update::update_duty_cooks() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	if (DateTime::timeDiffMinute(lastCook_update, curr) > 30) {
		coo->on_duty_updater();
		lastCook_update = curr;
	}
	if (DateTime::timeDiffMinute(lastCook_update, curr) > 10) {
		coo->late_catcher();
	}
}
void Update::update_duty_guards() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	if (DateTime::timeDiffMinute(lastGuard_update, curr) > 30) {
		gur->on_duty_updater();
		lastGuard_update = curr;
	}
	if (DateTime::timeDiffMinute(lastGuard_update, curr) > 10) {
		gur->late_catcher();
	}
}


Update::Update(DateTime llu, DateTime lcu, DateTime llc, DateTime lvu, DateTime lku, DateTime lce, DateTime lgu, students* in, Locations* ip, cooks* _coo, Cleaners* _cle, Guards* _gur) :
	lastLate_update(llu), lastClean_update(lcu), lastLate_clear(llc), lastVisitor_update(lvu), lastCleaner_update(lce), lastCook_update(lku), lastGuard_update(lgu), stu(in), loc(ip), coo(_coo), cle(_cle), gur(_gur)
{}



