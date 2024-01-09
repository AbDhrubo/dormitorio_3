#pragma once
#include "Person.h"

enum type{electrician, carpenter, plumber, food};

class Supplier : public Person
{
protected:
    type ty; 

public:
    Supplier(int _id, string& _name, string& _cont, type _ty) : Person(_id, _name, _cont), ty(_ty) {}
    void call() {
        cout << "Hello" << endl;
    }
    void set_id(int _id) {
        id = _id;
    }
    int get_id() {
        return id;
    }
    void set_name(string& _name) {
        name = _name;
    }
    string get_name() {
        return name;
    }

    void set_type(type _ty) {
        ty = _ty;
    }
    string get_type()
    {
        if (ty == type::electrician)
            return string("Electrician");
        else if (ty == type::carpenter)
            return string("Carpenter");
        else if (ty == type::plumber)
            return string("Plumber");
        else if (ty == type::food)
            return string("Food Supplier");
    }
    void show_info() override;
};

