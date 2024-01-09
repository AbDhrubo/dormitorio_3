#include "students.h"
void students::add_student(int ID, string name, string contact_no, string dept,
	string emergency_no, Location* loc, int _year) {
	Student s1(ID, name, contact_no, dept, emergency_no, loc, _year);
	arr.push_back(s1);
	Student::update_total_student_count(1);
	//delete &s1;
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
	return nullptr;
}

void students::initiate_leave(int ID, int dur) {
	try {
		if (dur > 4 || dur <0) throw 1;
		Student *temp = find_student(ID);
		if (temp == nullptr) throw 2;
		temp->start_leave(dur);
	}
	catch (int n) {
		if (n == 1) {
			cout << "Duration must be between 1 and 4" << endl
				<< "Your duration: " << dur;
		}
		else cout << "Student not found" << endl;
	}
}

void students::terminate_leave(int ID) {
	try {
		Student* temp = find_student(ID);
		if (temp == nullptr) throw 1;
		temp->end_leave();
	}
	catch (int n) {
		cout << "Student not found" << endl;
	}
}
