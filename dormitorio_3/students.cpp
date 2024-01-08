#include "students.h"
void students::add_student(int ID, string name, string contact_no, string dept,
	string emergency_no, Location* loc, int _year) {
	Student s1(ID, name, contact_no, dept, emergency_no, loc, _year);
	arr.push_back(s1);
	//delete &s1;
}

int students::remove_student(int ID) {
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

int students::student_entry(int ID) {
	for(int i = 0; i< arr.size(); i++){
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
			return 0;
		}
	}
	return 1;
}

void students::student_exit(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
		}
	}
}

Student* students::find_student(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return &arr[i];
		}
	}
	cout << "Not Found" << endl;
}