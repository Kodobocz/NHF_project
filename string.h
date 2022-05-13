
#pragma once

#include <iostream>
#include "vector.h"
#include <cstring>
#include <stdio.h>

class string {
	char* sData;
	size_t len;
public:

	size_t size() const { return len; }

	const char* getStr() const { return sData; }


	string(size_t n) {
		len = n;
		sData = new char[len+1];
		sData[0] = '\0';
		sData[len] = '\0';
	}

	string(const char* s = "") {
		len = strlen(s);
		sData = new char[len + 1];
		for (size_t i = 0; i < len; i++) {
			sData[i] = s[i];
		}
		sData[len] = '\0';
	}

	string(char c) {
		len = 1;
		sData = new char[len + 1];
		sData[0] = c;
		sData[1] = '\0';
	}

	string(const string& s) {
		len = s.len;
		sData = new char[len+1];
		for (size_t i = 0; i < len; i++) {
			sData[i] = s.sData[i];
		}
		sData[len] = '\0';
	}

	~string() {
		delete[] sData;
	}

	string operator+(const string& rhs) const;

	string operator+(char c) {
		return *this + string(c);
	}

	string& operator=(const string& rhs);

	string operator+=(const string& rhs) const ;

	vector<string> split(string sep = string(",")) const;

	bool operator==(const string& rhs) const {
		return strcmp(this->sData, rhs.sData) == 0;
	}

};

std::istream& operator>>(std::istream&, string&);

std::ostream& operator<<(std::ostream&, const string&);



