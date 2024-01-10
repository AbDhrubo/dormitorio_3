#pragma once
#include "cooks.h"
#include "Cleaners.h"
#include "Guards.h"

class ShowStaffInfo
{
private:
	cooks* coo;
	Cleaners* cle;
	Guards* gur;
public:
	void static menu();
	void cooks(int n);
	void cleaners(int n);
	void guards(int n);
};

