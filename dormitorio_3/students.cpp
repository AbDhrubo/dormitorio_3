#include "students.h"
void students::add_student(int ID, string name, string contact_no, string dept,
	string emergency_no, int loc, int _year, int late, bool meet, bool on_leave, bool visitor, int present) {
	Student s1(ID, name, contact_no, dept, emergency_no, loc, _year);
	s1.set_late_count(late);
	s1.set_meet_notification(meet);
	s1.set_on_leave(on_leave);
	s1.set_has_visitor(visitor);
	s1.set_presence(present);
	arr.push_back(s1);
	Student::update_total_student_count(1);
}

int students::remove_student(int ID) {
	int ch = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {

			Student::update_total_student_count(0);
			Student::update_total_student_present(0);
			if (arr[i].get_on_leave()) Student::update_total_student_on_leave(0);

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
			Student::update_total_student_present(1);
			return 0;
		}
	}
	return 1;
}

void students::student_exit(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
			Student::update_total_student_present(0);
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

void students::show_info(int i, vector <Location> &locco)
{
	cout << "Index :" << i << endl;
	arr[i].show_student_info(locco);
}