
#include <iostream>
#include "subscription.h"

subscription* subscription::factory(const string& sub) {
	if (sub == "Alap") {
		return new basic("Alap", 20, 20);
	}
	else if (sub == "MobiNet") {
		return new mobinet("MobiNet", 20, 20, 20, 20);
	}
	else if (sub == "SMSMax") {
		return new smsmax("SMSMax", 20, 20, 20, 20);
	}
}