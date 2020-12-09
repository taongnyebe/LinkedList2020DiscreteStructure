#pragma once
#include <string>

#ifndef MENUUI_H
#define MENUUI_H

class MenuUI
{
private:
	std::string temp;
	int temp_i;
	const int ID_NUMBER_COUNT = 3;

	void FilteredInput(int);
	void WarningUI();
public:
	int idNumber, number;
	char choice;
	bool retry = false, incorrectInput = true;

	void WelcomUI();

	void MainMenuUI();

	// Sub-Menus for extended features
	void AddingMenuUI(char); // this will have 4 states; 1 for main submenu and following are features menu
	void DeletingMenuUI(char); 
	void SearchMenuUI();
	void DisplayMenuUI(char, int);
	void ExitUI();

	// additional feature 
	// - change/alter value inside
	void ErrorUI();

};

#endif // ! UI_H