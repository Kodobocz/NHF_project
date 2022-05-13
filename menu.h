#pragma once

#include <iostream>
#include "string.h"
#include "inventory.h"
#include "user.h"
#include "usage.h"

void submenu(inventory& inv);

void menu() {
	//String vagy const char* k�z�tti v�laszt�s
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
		std::cout << "1 sz�mla lek�r�se... \n2 kil�p�s \n";
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
			std::cout << "1 havi egy f� \n 2 havi �sszes \n 3 �ves egy f� \n 4 �ves �sszes \n";
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
