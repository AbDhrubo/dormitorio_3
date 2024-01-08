#include <iostream>
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
	ofstream outfile("D:/CSE 2-1/OOPPSSSS/dormitorio_3/Guard_login.txt", ios::app);
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
				cout << "Welcome To This Page!" << endl;
			}
		}
		if (!found) {
			cout << "Error: Incorrect Login ID Or Password!" << endl;
		}
	}
	infile.close();
	Sleep(1000);
}

void Resident_login(students &s)
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
				int val;
				cout << endl << "Enter your ID: ";
				cin >> val;
				Student* logged = s.find_student(val);
				cout << "Your ";
				logged->get_location()->print_Location();
				cout << "Do you want to update room clean status?" << endl
					<< "1.Yes" << endl
					<< "2.No" << endl;
				cin >> val;
				if (val == 1)
				{
					system("cls");
					logged->get_location()->update_clean_status();
					cout << "Update Successful!" << endl
						 << "Status: ";
					if (logged->get_location()->get_clean_status()) cout << "Cleaned" << endl;
					else cout << "To be cleaned" << endl;
					Sleep(10000);
				}
				else if (val == 2)
				{
					system("cls");
					cout << "Have a good day!" << endl;
					Sleep(2000);
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

void Guard_login(students &s)
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
					cout << "Enter choice: " << endl;
					cin >> val;
					if (val == 1)
					{
						system("cls");
						int id, val;
						cout << "Enter Student ID:" << endl;
						cin >> id;
						cout << "1.Entering Without ID Card" << endl
							<< "2.Exiting Without ID Card" << endl
							<< "3.Going On Leave" << endl
							<< "4.Is Late" << endl
							<< "5.Back" << endl;
						cout << "Enter choice: " << endl;
						cin >> val;
						if (val == 1)
						{
							s.student_entry(id);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 2)
						{
							s.student_exit(id);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 3)
						{
							s.find_student(id)->set_on_leave(true);
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 4)
						{
							s.find_student(id)->increment_late_count();
							cout << "Update Successful!";
							Sleep(2000);
						}
						else if (val == 5)
						{
							Sleep(200);
						}
					}
					else if (val == 2)
					{
						system("cls");
						int id, val;
						cout << "Enter Student ID:" << endl;
						cin >> id;
						s.find_student(id)->show_info();
						cout << "Press 0 to go back: ";
						cin >> val;
						Sleep(100);
					}
					else if (val == 3)
					{
						exit = true;
						cout << "Have a good day!";
						Sleep(1000);
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

void login(students &s)
{
	system("cls");
	int val;
	cout << "1.Supervisor" << endl;
	cout << "2.Resident" << endl;
	cout << "3.Guard" << endl;
	cout << "Enter choice: ";
	cin >> val;
	if (val == 1) Supervisor_login();
	else if (val == 2) Resident_login(s);
	else if (val == 3) Guard_login(s);

}

int main() 
{
	cout << "------------Dormitorio------------" << endl;
	students s;
	Location loc(4, 5, 6);
	s.add_student(137, "Dhrubo", "01552393972", "CSE", "01793597139", &loc, 2);
	Location locc(3, 2, 1);
	s.add_student(125, "Sreya", "01711150081", "EEE", "01824203131", &locc, 3);

	cooks c;
	Position p = Position::Head;
	Meal m = Meal::Breakfast;
	c.add_cook(135, "Sad man", "012383", 700, 180, p, m);

	//c.find_cook(135).show_info();
	//c.find_cook(136).show_info();
	Sleep(10000);

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
			login(s);
		}

		else if (val == 2) {
			system("cls");
			exit = true;
			cout << "Good Luck!" << endl;
			Sleep(2000);
		}
		Sleep(2000);
	}
}