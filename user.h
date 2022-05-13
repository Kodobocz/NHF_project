#pragma once

#include <iostream>
#include "string.h"
#include "subscription.h"
#include "vector.h"


class user {
	string phone_number;
	subscription* package = nullptr;
	string name;
	string address;
	vector <usage> history;
public:
	user() {}

	user(string phone_number, subscription *package, string name, string address) : phone_number(phone_number), package(package), name(name), address(address) {}

	user(const user& u) {
		phone_number = u.phone_number;
		package = u.package;
		name = u.name;
		address = u.address;
	}

	user& operator=(const user& u) {
		phone_number = u.phone_number;
		package = u.package->clone();
		name = u.name;
		address = u.address;
		history = vector<usage>(u.history);
		return *this;
	}

	string getPnumber() const {
		return phone_number;
	}

	const vector<usage>& getHistory() const {
		return history;
	}

	const subscription* getPackage() const {
		return package;
	}

	

	friend const std::istream& operator>>(std::istream& is, user& u) {

		char buffer[1024];
		is.getline(buffer, 1024);
		string str(buffer);
		vector<string> vec = str.split();
		if (vec.size() != 4)
			throw std::runtime_error("user, hiba");
		u.phone_number = vec[0];
		u.package = subscription::factory(vec[1]);
		u.name = vec[2];
		u.address = vec[3];
		return is;
	}

	void add_to_history(const usage& u) {		
		history.push_back(u);
	}

	~user() {
		delete package;
	}

};
