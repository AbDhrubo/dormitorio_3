#include "ShowStaffInfo.h"
void ShowStaffInfo::menu() {
	//cout << "Enter a choice:" << endl
	//	<< "1. Show cleaners' details" << endl
	//	<< "2. Show cooks' details" << endl
	//	<< "3. Show guards' details" << endl
	//	<< "4. Back" << endl
	//	<< "Your choice: ";
	//int ch;
	//cin >> ch;
	//switch (ch) {
	//case 1:
	//	cooks();
	//case 2:
	//	cleaners();
	//case 3:
	//	guards();
	//case 4:

	//default:

	//};
}

void ShowStaffInfo::cooks(int n){
	if (n == 1) coo->show_all();
	else if (n == 2) coo->show_present();
	else if (n == 3) coo->show_absent();
	else if (n == 4) coo->show_shift_present();
	else if (n == 5) coo->show_shift_absent();
	// else back
}
void ShowStaffInfo::cleaners(int n) {
	if (n == 1) cle->show_all();
	else if (n == 2) cle->show_present();
	else if (n == 3) cle->show_absent();
	else if (n == 4) cle->show_shift_present();
	else if (n == 5) cle->show_shift_absent();
	// else back
}
void ShowStaffInfo::guards(int n) {
	if (n == 1) gur->show_all_guards();
	else if (n == 2) gur->show_present_guards();
	else if (n == 3) gur->show_absent_gurds();
	else if (n == 4) gur->show_shift_present();
	else if (n == 5) gur->show_shift_absent();
	// else back
}
