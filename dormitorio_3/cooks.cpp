#pragma once
#include "cooks.h"
#include "DateTime.h"

void cooks::add_cook(int i, string n, string cn, string t, int d, Position p, Meal m)
{
	Cook c1(i, n, cn, t, d, p, m);
	arr.push_back(c1);
}

int cooks::remove_cook(int ID) 
{
	int ch = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr.erase(arr.begin() + i);
			ch = 1;
			return 0;
		}
	}
	if (!ch) return 1;
}

void cooks::cooks_entry(int ID) {
	try {
		Cook* temp = find_cook(ID);
		if (temp) {
			temp->set_presence(1);
			temp->set_on_duty(1);
			cout << "Entry Successfull" << endl;
		}
		else throw 1;
	}
	catch (int i) {
		cout << "ID not found" << endl;
	}
}

void cooks::cooks_exit(int ID) {
	try {
		Cook* temp = find_cook(ID);
		if (temp) {
			temp->set_presence(0);
			cout << "Entry Successfull" << endl;
		}
		else throw 1;
	}
	catch (int i) {
		cout << "ID not found" << endl;
	}
}

Cook* cooks::find_cook(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return &arr[i];
		}
	}
	return nullptr;
	cout << "Cook invisible" << endl;

}

void cooks::going_on_leave(int ID)
{
	find_cook(ID)->set_on_duty(false);
}

void cooks::returns_from_leave(int ID)
{
	find_cook(ID)->set_on_duty(true);
}

void cooks::show_present() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence()) arr[i].show_info();
	}
}
void cooks::show_absent() {
	for (int i = 0; i < arr.size(); i++) {
		if (!arr[i].get_presence()) arr[i].show_info();
	}
}

void cooks::show_shift_present() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence() && arr[i].get_on_duty()) arr[i].show_info();
	}
}
void cooks::show_shift_absent() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence() && !arr[i].get_on_duty()) arr[i].show_info();
	}
}

void cooks::show_all() {
	for (int i = 0; i < arr.size(); i++) {
		arr[i].show_info();
	}
}

void cooks::on_duty_updater() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	for (int i = 0; i < arr.size(); i++) {
		DateTime temp = arr[i].get_duty_time();
		temp.updateDate(curr);
		if (DateTime::timeDiffMinute(temp, curr) <= arr[i].get_duration()) {
			arr[i].set_on_duty(1);
		}
		else arr[i].set_on_duty(0);
	}
}

void cooks::late_catcher() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	for (int i = 0; i < arr.size(); i++) {
		DateTime temp = arr[i].get_duty_time();
		temp.updateDate(curr);
		if ((!arr[i].get_presence() || arr[i].get_on_duty()) && DateTime::timeDiffMinute(temp, curr) > 10) {
			arr[i].late_count_inc();
		}
	}
}

