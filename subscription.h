#pragma once

#include "string.h"
#include "usage.h"
#include "vector.h"

class subscription {
protected:
	string name;
public:
	subscription(string name = "") :name(name) {}

	subscription(const subscription& sbsn) {
		name = sbsn.name;
	}

	virtual ~subscription() {}

	virtual string getName() { return name; };

	virtual int paycheck(const vector<usage> &v) const = 0;

	virtual int paycheck(const usage &v) const = 0;

	static subscription* factory(const string&);

	virtual subscription* clone() = 0;

};

class basic : public subscription {
	int price_p_minute;
	int price_p_sms;
public:
	basic(string name, int ppm, int ppsms) : subscription(name), price_p_minute(ppm), price_p_sms(ppsms) {}

	virtual int paycheck(const vector<usage>& v) const {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += paycheck(v[i]);
		}
		return sum;
	}

	virtual int paycheck(const usage& v) const {
		return price_p_minute * v.getMins() + price_p_sms * v.getSms();
	}

	virtual subscription* clone() {
		return new basic("Alap", price_p_minute, price_p_sms);
	}
};

class mobinet : public subscription {
	int price_p_minute;
	int price_p_sms;
	int free_mins;
	int free_sms;
public:
	mobinet(string name, int ppm, int ppsms, int fmins, int fsms) : subscription(name), price_p_minute(ppm), price_p_sms(ppsms), free_mins(fmins), free_sms(fsms) {}

	virtual int paycheck(const vector<usage>& v) const {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += paycheck(v[i]);
		}
		return sum;
	}

	virtual int paycheck(const usage& v) const {
		return (v.getMins() - free_mins) * price_p_minute + (v.getSms() - free_sms) * price_p_sms;
	}

	virtual subscription* clone() {
		return new mobinet("MobiNet", price_p_minute, price_p_sms, free_mins, free_sms);
	}

};

class smsmax : public subscription {
	int price_p_minute;
	int price_p_sms;
	int free_mins;
	int free_sms;
public:
	smsmax(string name, int ppm, int ppsms, int fmins, int fsms) : subscription(name), price_p_minute(ppm), price_p_sms(ppsms), free_mins(fmins), free_sms(fsms) {}

	virtual int paycheck(const vector<usage>& v) const {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += paycheck(v[i]);
		}
		return sum;
	}

	virtual int paycheck(const usage& v) const {
		return (v.getMins() - free_mins) * price_p_minute + (v.getSms() - free_sms) * price_p_sms;
	}

	virtual subscription* clone() {
		return new smsmax("SMSMax", price_p_minute, price_p_sms, free_mins, free_sms);
	}
};

