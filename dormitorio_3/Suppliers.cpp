#include "Suppliers.h"
void suppliers::add_supplier(int _id, string& _name, string& _cont, type _ty) {
	Supplier s1(_id,_name,_cont,_ty);
	arr_supplier.push_back(s1);
	delete& s1;
}

int suppliers::remove_supplier(int ID) {
	int ch = 0;
	for (int i = 0; i < arr_supplier.size(); i++) {
		if (ID == arr_supplier[i].get_id()) {
			arr_supplier.erase(arr_supplier.begin() + i);
			ch = 1;
			return 0;
		}
	}
	if (!ch) return 1;
}

/*int suppliers::student_entry(int ID) {
	for (int i = 0; i < arr_supplier.size(); i++) {
		if (ID == arr_supplier[i].get_id()) {
			arr_supplier[i].presence_updater();
			return 0;
		}
	}
	return 1;
}

void suppliers::student_exit(int ID) {
	for (int i = 0; i < arr_supplier.size(); i++) {
		if (ID == arr_supplier[i].get_id()) {
			arr_supplier[i].presence_updater();
		}
	}
}*/
Supplier suppliers::find_supplier(int ID) {
	for (int i = 0; i < arr_supplier.size(); i++) {
		if (ID == arr_supplier[i].get_id()) {
			return arr_supplier[i];
		}
	}
	cout << "Not Found" << endl;
}