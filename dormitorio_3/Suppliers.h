#pragma once
#include"Supplier.h"
#include<vector>

class Suppliers
{
private:
	vector<Supplier> arr_supplier;
public:
	void add_supplier(int _id, string _name, string _cont, type _ty);
	int remove_supplier(int _id);
	int supplier_entry(int _id);
	void supplier_exit(int _id);
	Supplier find_supplier(int _id);
};