/*
    Linked List Version 2

*/

#include <iostream>
#include <Windows.h>
#include <cstdlib>

#include "LinkedList.h"
#include "MenuUI.h"



int main()
{
    LinkedList lList;
    MenuUI menuUI;

    bool retry = true;

    menuUI.WelcomUI();

    do
    {
        menuUI.incorrectInput = true;
        menuUI.MainMenuUI();

        switch (menuUI.choice)
        {
        case '1':
            // Functionalities with UI
            while (menuUI.incorrectInput) // error trapping before transfer data to the lList
            {
                menuUI.AddingMenuUI('@');
                menuUI.AddingMenuUI(menuUI.choice);

                if (menuUI.incorrectInput)
                    menuUI.ErrorUI();
            }
            // functionalities with Linked List
            lList.AddNode(menuUI.choice, menuUI.idNumber, menuUI.number);
            system("pause");
            break;

        case '2':
            while (menuUI.incorrectInput) // error trapping before transfer data to the lList
            {
                menuUI.DeletingMenuUI('@');

                if (menuUI.choice == '3')
                {
                    menuUI.number = lList.NodeCount();
                    menuUI.incorrectInput = false;
                }
                else
                    menuUI.DeletingMenuUI(menuUI.choice);
            }

            lList.DeleteNode(menuUI.number);
            system("pause");

            break;

        case '3':
            while (menuUI.incorrectInput) // error trapping before transfer data to the lList
            {
                menuUI.SearchMenuUI();

                if (menuUI.incorrectInput)
                    menuUI.ErrorUI();
            }

            lList.Search(menuUI.idNumber);
            system("pause");
            break;

        case '4':
            while (menuUI.incorrectInput) // error trapping before transfer data to the lList
            {
                if (lList.NodeCount() == 0)
                {
                    menuUI.incorrectInput = false;
                    menuUI.DisplayMenuUI('!', lList.NodeCount());
                }
                else
                {
                    menuUI.DisplayMenuUI('@', lList.NodeCount());
                    menuUI.DisplayMenuUI(menuUI.choice, lList.NodeCount());
                    menuUI.incorrectInput = (menuUI.choice == '1' || '2') ? false : true;
                }
            }

            lList.PrintList(menuUI.choice);
            system("pause");
            break;

        case '0':
            menuUI.ExitUI();
            retry = false;
            break;

        default: menuUI.ErrorUI(); break;
        }
        system("cls");

    } while (retry);
}
