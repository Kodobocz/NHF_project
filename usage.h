#pragma once

#include "string.h"

class usage {
	string phone_number;
	string date;
	int used_mins = 0;
	int used_sms = 0;
public:

	usage() {}

	usage& operator=(const usage& us) {
		phone_number = us.phone_number;
		date = us.date;
		used_mins = us.used_mins;
		used_sms = us.used_sms;
		return *this;
	}

	usage(string phone_number, string date, int used_mins, int used_sms) : phone_number(phone_number), date(date), used_mins(used_mins), used_sms(used_sms) {}

	int getMins() const {
		return used_mins;
	}
	int getSms() const {
		return used_sms;
	}

	string getPnumber() const {
		return phone_number;
	}

	const string& getDate() const {
		return date;
	}

	friend const std::istream& operator>>(std::istream& is, usage& us) {
		char buffer[1024];
		is.getline(buffer, 1024);
		string str(buffer);
		vector<string> vec = str.split();
		if (vec.size() != 4)
			throw "usage, hiba";
		us.phone_number = vec[0];
		us.date = vec[1];
		us.used_mins = std::atoi(vec[2].getStr());
		us.used_sms = std::atoi(vec[3].getStr());
		return is;
	}

	

	~usage () {}

};