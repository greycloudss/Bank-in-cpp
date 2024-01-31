#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <iomanip>
#pragma once
#define cache_n "log.bin"


void upprCase(std::string& word) {
	for (int i = 0; i < word.length(); i++) {
		if ((int)word[i] >= 97 && (int)word[i] <= 122)
			word[i] -= 32;
	}
}

void lwrCase(std::string& word) {
	for (int i = 0; i < word.length(); i++)
		if ((int)word[i] >= 65 && (int)word[i] <= 90)
			word[i] += 32;
}


int userInterface(bool *status, unsigned instance) {
	bool state = true;
	unsigned sel = 0;
	unsigned codes[][2] = { {0, 1}, {2, 3} };
	std::string prompts[] = {"Register", "Login", "Balance", "Transfer"};
	

	do {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) {
			sel = sel ^ 1;
			state = true;
		}
		int shorter = codes[instance][sel];
		if (GetAsyncKeyState(VK_RETURN) & 0x800) {
			if (shorter == 0) {
				//register
			}
			if (shorter == 1) {
				//login
			}
			if (shorter == 2) {
				//balance
			}
			if (shorter == 3) {
				//transfer
			}
		}
		
		if (GetAsyncKeyState(VK_TAB) & 0x800)
			return -1;

		if (state == true) {
			system("cls");
			std::cout << std::setw(prompts[codes[instance][sel ^ 1]].length()*2 + prompts[codes[instance][sel]].length()*2 + 16);
			upprCase(prompts[shorter]);
			lwrCase(prompts[codes[instance][sel ^ 1]]);
			std::cout << prompts[codes[instance][sel ^ 1]] << "\t\t\t\t" << prompts[codes[instance][sel]] << std::endl;
			state = false;
		}
	} while (1);
}