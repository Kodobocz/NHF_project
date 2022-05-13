
#include <iostream>
#include "menu.h"
#include "inventory.h"
#include "string.h"
#include <string>

void test() {

	char buffer[1024];
	std::cin.getline(buffer, 1024);
	string str(buffer);
	std::cout << str;
	auto vec = str.split();
	std::cout << vec[0] << vec[1] << vec[2] << vec[3];
	std::cout << "\nhello\n";

}


int main() {
	try {
		
		//menu();
		inventory inv;
		inv.set_up("user.txt", "usage.txt");

		inv.print_monthly_fees("0620123456", "2022.02");
		//test();


	}catch (std::exception e) {
		std::cout << "HIBA TÖRTÉNT:\n";
		std::cout << e.what();
	}
}