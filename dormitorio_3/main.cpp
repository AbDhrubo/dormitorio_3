#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <functional>
#include <string>
#include "Cleaner.h"
#include "Cook.h"
#include "Guard.h"
#include "Location.h"
#include "Person.h"
#include "Resident.h"
#include "Staff.h"
#include "Student.h"
#include "Supervisor.h"
#include "Supplier.h"
#include "Teacher.h"
#include "students.h"
#include "cooks.h"

using namespace std;

/*int main() {
	std::string myString = "Hello, World!";
	size_t hashValue = customHash(myString);

	std::cout << "Hash value of '" << myString << "': " << hashValue << std::endl;

	return 0;
}*/
void update_location_file(vector <Location>& locco);
void update_students_file(students &s, vector <Location>& locco);

class Login 
{
private:
	string LoginID, Password;
public:
	size_t customHash(const std::string& input) {
		hash <string> hasher; 
		return hasher(input);
	}

	void setID(string id) {
		LoginID = id;
	}

	void setPW(string pw) {
		Password = customHash(pw);
	}

	string getID() {
		return LoginID;
	}

	string getPW() {
		return Password;
	}
};

void registration(Login log) 
{
	system("cls");
	string id, pw;
	cout << "Enter Login ID: ";
	cin >> id;
	log.setID(id);

start:
	cout << "Enter A Strong Password: ";
	cin >> pw;
	if (pw.length() >= 8) {
		log.setPW(pw);
	}
	else {
		cout << "Enter Minimum 8 Characters!" << endl;
		goto start;
	}
	ofstream outfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Supervisor_login.txt", ios::app);
	if (!outfile) {
		cout << "Error: File Can't Open!" << endl;
	}
	else {
		outfile << log.getID() << " : " << log.getPW() << endl << endl;
		cout << "User Registered Successfully!" << endl;
	}
	outfile.close();
	Sleep(1000);
}

void Supervisor_login()
{
	system("cls");
	hash <string> hasher;
	string id, pw, pww;
	cout << "Enter Login ID: ";
	cin >> id;

	cout << "Enter Password: ";
	cin >> pw;

	pww = hasher(pw);

	ifstream infile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Supervisor_login.txt");
	if (!infile) 
	{
		cout << "\tError: File Can't Open!" << endl;
	}
	else 
	{
		string line;
		bool found = false;
		while (getline(infile, line)) {
			stringstream ss;
			ss << line;
			string userID, userPW;
			char delimiter;
			ss >> userID >> delimiter >> userPW;

			if (id == userID && pww == userPW) {
				found = true;

				cout << "Please Wait";
				for (int i = 0; i < 3; i++) {
					cout << ".";
					Sleep(500);
				}
				system("cls");
				cout << "Total students allocated: " << Student::get_total_student_count() << endl;
				cout << "Total students present: " << Student::get_total_student_present() << endl;
				cout << "Total students on leave: " << Student::get_total_student_on_leave() << endl;
				Sleep(5000);
			}
		}
		if (!found) {
			cout << "Error: Incorrect Login ID Or Password!" << endl;
		}
	}
	infile.close();
	Sleep(1000);
}

void Resident_login(students &s, vector <Location> &locco)
{
	system("cls");
	hash <string> hasher;
	string id, pw, pww;
	cout << "Enter Login ID: ";
	cin >> id;

	cout << "Enter Password: ";
	cin >> pw;

	pww = hasher(pw);

	ifstream infile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Resident_login.txt");
	if (!infile) {
		cout << "Error: File Can't Open!" << endl;
	}
	else {
		string line;
		bool found = false;
		while (getline(infile, line)) {
			stringstream ss;
			ss << line;
			string userID, userPW;
			char delimiter;
			ss >> userID >> delimiter >> userPW;

			if (id == userID && pww == userPW) {
				found = true;

				cout << "Please Wait";
				for (int i = 0; i < 3; i++) {
					cout << ".";
					Sleep(500);
				}
				int id;
				cout << endl << "Enter your ID: ";
				cin >> id;
				Student* logged = s.find_student(id);
				
				bool exit = false;
				while (!exit)
				{
					system("cls");
					int val;
					if (logged->get_meet_notification()) cout << "*** Reminder:  You Are Expected At Supervisor's Office ***" << endl << endl;
					cout << "1.View Your Information" << endl
						<< "2.Update Cleaning Status" << endl
						<< "3.Exit" << endl
						<< "4.Update Password: " << endl
						<< "Enter Choice: ";
					cin >> val;

					if (val == 1)
					{
						system("cls");
						int x;
						logged->show_info();
						cout << "Press 0 to go back: ";
						cin >> x;
						if (x == 0) Sleep(200);

					}
					else if (val == 2)
					{
						system("cls");
						locco[logged->get_location()].update_clean_status();
						update_location_file(locco);
						cout << "Update Successful!" << endl
							<< "Status: ";
						if (locco[logged->get_location()].get_clean_status()) cout << "Cleaned" << endl;
						else cout << "To be cleaned" << endl;
						Sleep(2000);
					}
					else if (val == 3)
					{
						system("cls");
						exit = true;
						cout << "Have a good day!" << endl;
					}
				}

			}
		}
		if (!found) {
			cout << "Error: Incorrect Login ID Or Password!" << endl;
		}
	}
	infile.close();
	Sleep(1000);
}

void Guard_login(students &s, vector <Location> &locco)
{
	system("cls");
	hash <string> hasher;
	string id, pw, pww;
	cout << "Enter Login ID: ";
	cin >> id;

	cout << "Enter Password: ";
	cin >> pw;

	pww = hasher(pw);

	ifstream infile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Guard_login.txt");
	if (!infile) {
		cout << "Error: File Can't Open!" << endl;
	}
	else {
		string line;
		bool found = false;
		while (getline(infile, line)) {
			stringstream ss;
			ss << line;
			string userID, userPW;
			char delimiter;
			ss >> userID >> delimiter >> userPW;

			if (id == userID && pww == userPW) {
				found = true;

				cout << "Please Wait";
				for (int i = 0; i < 3; i++) {
					cout << ".";
					Sleep(500);
				}

				bool exit = false;
				while (!exit)
				{
					system("cls");
					int val;
					cout << "1.Update Student Info" << endl;
					cout << "2.View Student Info" << endl;
					cout << "3.Exit" << endl;
					cout << "Enter choice: ";
					cin >> val;
					if (val == 1)
					{
						system("cls");
						int id, val;
						cout << "Enter Student ID:";
						cin >> id;
						cout << "1.Entering Without ID Card" << endl
							<< "2.Exiting Without ID Card" << endl
							<< "3.Going On Leave" << endl
							<< "4.Returning From Leave" << endl
							<< "5.Is Late" << endl
							<< "6.Back" << endl;
						cout << "Enter choice: ";
						cin >> val;
						if (val == 1)
						{
							s.student_entry(id);
							update_students_file(s, locco);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 2)
						{
							s.student_exit(id);
							update_students_file(s, locco);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 3)
						{
							s.find_student(id)->set_on_leave(true);
							update_students_file(s, locco);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 4)
						{
							s.find_student(id)->set_on_leave(false);
							update_students_file(s, locco);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 5)
						{
							s.find_student(id)->increment_late_count();
							update_students_file(s, locco);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 6)
						{
							Sleep(200);
						}
					}
					else if (val == 2)
					{
						system("cls");
						int id, val;
						cout << "Enter Student ID:";
						cin >> id;
						s.find_student(id)->show_student_info(locco);
						cout << "Press 0 to go back: ";
						cin >> val;
						Sleep(100);
					}
					else if (val == 3)
					{
						system("cls");
						exit = true;
						cout << "Have a good day!";
					}
				}
			}
		}
		if (!found) {
			cout << "Error: Incorrect Login ID Or Password!" << endl;
		}
	}
	infile.close();
	Sleep(1000);
}

void login(students &s, vector<Location> &locco)
{
	system("cls");
	int val;
	cout << "1.Supervisor" << endl;
	cout << "2.Resident" << endl;
	cout << "3.Guard" << endl;
	cout << "Enter choice: ";
	cin >> val;
	if (val == 1) Supervisor_login();
	else if (val == 2) Resident_login(s, locco);
	else if (val == 3) Guard_login(s, locco);

}

void write_students_file()
{
	int stu_id, stu_year, stu_loc;
	string stu_name, stu_cont, stu_dept, stu_emg;
	cout << "Enter id: ";
	cin >> stu_id;
	cout << "Enter name: ";
	cin >> stu_name;
	cout << "Enter semester: ";
	cin >> stu_year;
	cout << "Enter dept: ";
	cin >> stu_dept;
	cout << "Enter contact: ";
	cin >> stu_cont;
	cout << "Enter emg contact: ";
	cin >> stu_emg;
	cout << "Enter location: ";
	cin >> stu_loc;

	ofstream outfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Students.txt", ios::app);
	if (!outfile) {
		cout << "Error: File Can't Open!" << endl;
	}
	else {
		outfile
			<< stu_id << " : "
			<< stu_name << " : "
			<< stu_cont << " : "
			<< stu_dept << " : "
			<< stu_emg << " : "
			<< stu_loc << " : "
			<< stu_year << endl;
	}
	cout << "Entry done!" << endl;
	outfile.close();
}


//Location ****read,write,update**** file
void read_location_file(vector <Location> &locco)
{
	ifstream infile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Location.txt", ios::in);
	if (!infile) 
	{
		cout << "Error: File Can't Open!" << endl;
	}
	else 
	{
			string line;
			while (getline(infile, line)) 
			{
				stringstream ss;
				ss << line;
				int loc_block, loc_floor, loc_room, loc_clean, loc_count;
				char delimiter;
				ss >> loc_block >> delimiter >> loc_floor >> delimiter >> loc_room >> delimiter >> loc_clean >> delimiter >> loc_count;
				Location locoloco(loc_room, loc_block, loc_floor);
				locoloco.set_clean_status(loc_clean);

				locco.push_back(locoloco);

			}
	}
	infile.close();
}

void write_location_file()
{
	ofstream outfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Location.txt", ios::app);
	if (!outfile)
	{
		cout << "Error: File Can't Open!" << endl;
	}
	else 
	{
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				for (int k = 1; k <= 3; k++)
				{
					outfile << i << " : " << j << " : " << k << " : " << 0 << " : " << 0 << endl;
				}
			}
		}
	}
}

void update_location_file(vector <Location> &locco)
{
	ofstream clearfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Location.txt", ios::out);
	clearfile << "";
	clearfile.close();

	ofstream outfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Location.txt", ios::app);
	{
		for (int i = 0; i < locco.size(); i++)
		{
			outfile << locco[i].get_blockno() << " : " << locco[i].get_floorno() << " : " << locco[i].get_roomno() << " : " << locco[i].get_clean_status() << " : " << locco[i].get_count() << endl;
		}
	}
	outfile.close();

}

void read_students_file(students& s)
{
	int stu_id, stu_year, stu_loc, stu_late, stu_on_leave, stu_visitor, stu_meet, stu_present;
	string stu_name, stu_cont, stu_dept, stu_emg;

	ifstream infile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Students.txt");
	if (!infile)
	{
		cout << "Error: File Can't Open!" << endl;
	}
	else
	{
		string line;
		while (getline(infile, line))
		{
			stringstream ss;
			ss << line;
			char delimiter;
			ss >> stu_id >> delimiter >> stu_name >> delimiter >> stu_cont >> delimiter >> stu_dept >> delimiter >> stu_emg >> delimiter >> stu_loc >> delimiter >> stu_year
				>>  delimiter >> stu_late >> delimiter >> stu_meet >> delimiter >> stu_on_leave >> delimiter >> stu_visitor >> delimiter >> stu_present;

			s.add_student(stu_id, stu_name, stu_cont, stu_dept, stu_emg, stu_loc, stu_year, stu_late, stu_meet, stu_on_leave, stu_visitor, stu_present);
		}
	}
}

void update_students_file(students &s, vector <Location> &locco)
{
	ofstream clearfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Students.txt", ios::out);
	clearfile << "";
	clearfile.close();

	ofstream outfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Students.txt", ios::app);
	{
		for (int i = 0; i < 50; i++)
		{
			outfile << s[i].get_id() << " : "
				<< s[i].get_name() << " : "
				<< s[i].get_cont() << " : "
				<< s[i].get_dept() << " : "
				<< s[i].get_emergencyno() << " : "
				<< s[i].get_location() << " : "
				<< s[i].get_year() << " : "
				<< s[i].get_late_count() << " : "
				<< s[i].get_meet_notification() << " : "
				<< s[i].get_on_leave() << " : "
				<< s[i].get_has_visitor() << " : "
				<< s[i].get_presence() << endl;
		}
	}
	outfile.close();

}


int main() 
{
	students s;
	vector <Location> locco;

	read_location_file(locco);
	read_students_file(s);

	/*locco[1].set_clean_status(1);
	locco[3].set_count(3);
	update_location_file(locco);

	cooks c;
	Position p = Position::Head;
	Meal m = Meal::Breakfast;
	c.add_cook(135, "Sad man", "012383", 700, 180, p, m);

	//c.find_cook(135).show_info();
	//c.find_cook(136).show_info();
	//Sleep(10000);
	*/
	Login log;

	bool exit = false;
	while (!exit) 
	{
		system("cls");
		int val;
		cout << "------------Dormitorio------------" << endl;
		cout << "**********************************" << endl;
		cout << "1.Login." << endl;
		cout << "2.Exit." << endl;
		cout << "Enter choice: ";
		cin >> val;

		if (val == 3) {
			registration(log);
		}

		if (val == 1) {
			login(s, locco);
		}

		else if (val == 2) {
			system("cls");
			exit = true;
			cout << "Have a good day!" << endl;
			Sleep(2000);
		}
		Sleep(2000);
	}

	/*Location a(1, 2, 3), b(1, 4, 5), c(2, 2, 2), d(2, 1, 5);
	vector <Location> loco;
	loco.push_back(a);
	loco.push_back(b);
	loco.push_back(c);
	loco.push_back(d);
	for (int i = 0; i < loco.size(); i++)
	{
		write_students_file(&loco[i]);
	}*/

	/*write_location_file();
	vector <Location> locco;
	read_location_file(locco);

	locco[1].set_clean_status(1);
	locco[3].set_count(3);
	update_location_file(locco);

	for (int i = 0; i < locco.size(); i++)
	{
		locco[i].print_Location_info();
	}*/
	//for(int i=1; i<=10; i++) write_students_file();
	//write_location_file();
	
	for (int i = 0; i < 50; i++)
	{
		s.show_info(i, locco);
	}
}

/*void read_students_file(students& s)
{
	int stu_id, stu_year, stu_loc;
	string stu_name, stu_cont, stu_dept, stu_emg;

	ifstream infile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Students.txt");
	if (!infile)
	{
		cout << "Error: File Can't Open!" << endl;
	}
	else
	{
		string line;
		while (getline(infile, line)) 
		{
			stringstream ss;
			ss << line;
			char delimiter;
			ss >> stu_id >> delimiter >> stu_name >> delimiter >> stu_cont >> delimiter >> stu_dept >> delimiter >> stu_emg >> delimiter >> stu_loc >> delimiter >> stu_year;

			s.add_student(stu_id, stu_name, stu_cont, stu_dept, stu_emg, stu_loc, stu_year);
		}
	}
}*/


