#pragma once

#include <iostream>
#include "string.h"
#include "inventory.h"
#include "user.h"
#include "usage.h"

void submenu(inventory& inv);

void menu() {
	//String vagy const char* közötti választás
	std::cout << "faljnev 1: ";
	string usersfile;
	std::cin >> usersfile;

	string usagefile;
	std::cout << "fajlnev 2: ";
	std::cin >> usagefile;

	inventory inv;

	inv.set_up(usersfile.getStr(), usagefile.getStr());


	int answer = 0;
	bool quit = false;
	while (quit != true) {
		std::cout << "1 számla lekérése... \n2 kilépés \n";
		std::cin >> answer;
		switch (answer) {
		case 1:
			submenu(inv);
			break;
		case 2:
			quit = true;
			break;
		}
	}
}

	

void submenu(inventory& inv) {
	int answer = 0;
	bool quit = false;
		while (quit != true) {
			std::cout << "1 havi egy fõ \n 2 havi összes \n 3 éves egy fõ \n 4 éves összes \n";
			std::cin >> answer;
			switch (answer) {
			case 1:
			{
				string pnumber; string date;
				std::cin >> pnumber; std::cin >> date;
				inv.print_monthly_fees(pnumber, date);
				break;
			}
			case 2:
			{
				string date;
				std::cin >> date;
				//inv.print_monthly_fees(date);
				break;
			}
			case 3:
			{
				string pnumber; string date;
				std::cin >> pnumber; std::cin >> date;
				//inv.print_yearly_fees(pnumber, date);
				break;	
			}
			case 4:
			{
				string date;
				std::cin >> date;
				//inv.print_yearly_fees(date);
				break;
			}
			}
		}
}
