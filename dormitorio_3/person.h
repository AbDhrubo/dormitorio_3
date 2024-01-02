#pragma once
#include<iostream>
using namespace std;
class Person
{
protected:
	string name;
	int id;
	string cont_no;
public:
	Person(int _id, string& _name, string& _cont) : id(_id), name(_name), cont_no(_cont) {}

	void set_name(string& _name) {
		name = _name;
	}
	void set_id(int _id) {
		id = _id;
	}
	void set_cont(string& _cont) {
		cont_no = _cont;
	}
	string get_name() { return name; }
	string get_cont() { return cont_no; }
	int get_id() { return id; }
	virtual void show_info() = 0;
};

