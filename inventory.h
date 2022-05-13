#pragma once

#include <iostream>
#include <fstream>
#include "string.h"
#include "vector.h"
#include "user.h"
#include "usage.h"

#include <string>

class inventory {
	vector<user> users;
	vector<usage> usages;
	void read_users(const char* filename) {
		std::ifstream ifs(filename);
		while (ifs.peek() != EOF) {
			user u;
			ifs >> u;
			users.push_back(u);
		}
	}
	void read_usages(const char* filename) {
		std::ifstream ifs(filename);
		while (ifs.peek() != EOF) {
			usage u;
			ifs >> u;
			usages.push_back(u);
		}
	}
	

	void join() {
		for (size_t i = 0; i < users.size(); i++) {
			for (size_t j = 0; j < usages.size(); j++) {
				if (users[i].getPnumber() == usages[j].getPnumber())
					users[i].add_to_history(usages[j]);
			}
		}
	}
public:

	

	void set_up(const char* filename1, const char* filename2) {
		read_users(filename1);

		read_usages(filename2);

		join(); //még nem mûködik
	}

	void print_monthly_fees(const string& pnumber, const string& date) {
		//user* u = nullptr;
		//for (size_t i = 0; i < users.size(); i++) {
		//	if (pnumber == users[i].getPnumber()) {
		//		u = &users[i];
		//		break;
		//	}
		//}
		//if (u == nullptr) {
		//	throw std::runtime_error("nem talalhato a felhasznalo");
		//}
		//usage* us = nullptr;
		//for (size_t j = 0; j < u->getHistory().size(); j++) {
		//	if (u->getHistory()[j].getDate() == date) {
		//		auto& vec = u->getHistory();
		//		us = &vec[j];
		//		break;
		//	}

		//}
		//if (us == nullptr) {
		//	throw std::runtime_error("nem talalhato");
		//}
		//std::cout << u->getPnumber() << " Fizet: " << u->getPackage()->paycheck(*us) << std::endl;
	}

	void print_monthly_fees(const string& date);

	void print_yearly_fees(const string& pnumber, const string& date);

	void print_yearly_fees(const string& date);

	~inventory () {}
};