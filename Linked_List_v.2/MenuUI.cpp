#include <cstdlib>
#include <Windows.h>
#include <iostream>

#include "MenuUI.h"

#define cout std::cout << "\n\t"
#define cin std::cin
#define pause_second(x) Sleep(1000 * x)
#define border cout << "\b******************************************" // 30
#define warning_border cout << "\b!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"

void MenuUI::FilteredInput(int convertTo) // Error Trapping Method
{
    cin >> temp;
    switch (convertTo)
    {
    case 1: // Convertion of multiple input to single(leading) input only
        choice = temp[0];
        break;
    case 2: // Convertion of non-numeric input to numeric and evaluating to be a unsigned number
        if (temp.size() == ID_NUMBER_COUNT && stoi(temp) > 0)
        {
            idNumber = stoi(temp);
            incorrectInput = false;
        }
        else
            incorrectInput = true;
        break;
    case 3:
        if (stoi(temp) > 0)
        {
            number = stoi(temp);
            incorrectInput = false;
        }
        else
            incorrectInput = true;
    }

}

void MenuUI::WarningUI()
{
    warning_border;
    cout << "\"Please Input Corresponding ";
    cout << "         Information Required\"";
    warning_border << '\n';
}

void MenuUI::WelcomUI() // Display welcoming UI
{
    border;
    cout << "~                Welcome                ~";
    cout << "~  This is TestBench/Experimental Bench ~";
    cout << "~     File for Linked List Theory       ~\n";
    border;

    pause_second(3);
    system("cls");

    border;
    cout << "~                Note:                  ~";
    cout << "~   Please Take Notes for the errors    ~";
    cout << "~       Spotted and report it - zyx     ~\n";
    border;

    pause_second(5);
    system("cls");
}

void MenuUI::MainMenuUI() 
{
    border;
    cout << "Linked List Main Menu\n";
    border << '\n';

    border;
    cout << "1. Add ID\n";
    cout << "2. Delete ID\n";
    cout << "3. Search ID\n";
    cout << "4. Print Stored ID\n";
    cout << "0. Exit\n\n";
    border << '\n';

    cout << ">>   <<\b\b\b\b";

    FilteredInput(1);

    system("cls");
}

void MenuUI::AddingMenuUI(char state)
{
    system("cls");

    border;
    cout << "Adding Menu Tab\n";
    border << '\n';

    MenuUI::WarningUI();

    switch (state)
    {
    case '@': // initial state
        border;
        cout << "1. Add in the Start";
        cout << "2. Add Somewhere Between";
        cout << "3. Add in the End";
        cout << "0. Exit";
        border << '\n';

        cout << ">>   <<\b\b\b\b";
        FilteredInput(1);
        break;

    case '0': incorrectInput = false; break;
    case '1': // function states
        cout << "ID Number : ";
        FilteredInput(2);

        break;
    case '2':
        cout << "List Number : ";
        FilteredInput(3);

        if (incorrectInput)
            break;

        cout << "ID Number : ";
        FilteredInput(2);
        break;
    case '3':
        cout << "ID Number : ";
        FilteredInput(2);
        break;

    default: MenuUI::ErrorUI(); break; // Error catcher for inputs that is not allowed
    }

    // this will only catch error from the three functions
    if (incorrectInput && state == ('1'||'2'||'3'))
    {
        MenuUI::ErrorUI();
    }

    cout;
}

void MenuUI::DeletingMenuUI(char state)
{
    system("cls");

    border;
    cout << "Deleting Menu Tab\n";
    border << '\n';

    MenuUI::WarningUI();

    switch (state)
    {
    case '@': // Initial state
        border;
        cout << "1. Delete in the Start";
        cout << "2. Delete Somewhere Between";
        cout << "3. Delete in the End";
        cout << "0. Exit";
        border << '\n';

        cout << ">>   <<\b\b\b\b";
        FilteredInput(1);
        break;

    case '0': incorrectInput = false; break;
    case '1': 
        number = 1; 
        incorrectInput = false;
        break;
        
    case '2':
        cout << "Number of Corresponding ID Number: ";
        FilteredInput(3);
        break;

    case '3': break; // redundant error trap

    default: MenuUI::ErrorUI(); break;
    }
}

void MenuUI::SearchMenuUI()
{
    system("cls");

    border;
    cout << "Search Menu Tab\n";
    border << '\n';
    MenuUI::WarningUI();

    cout << "ID Number: ";
    FilteredInput(2);
}

void MenuUI::DisplayMenuUI(char state, int nodesCount)
{
    system("cls");
    border;
    cout << "Print Menu Tab\n";
    border << '\n';

    border;
    cout << '\t' << "Total Number of Nodes: " << nodesCount << "\n\n";
    border << '\n';

    switch (state)
    {
    case '@':
        border;
        cout << "1. Ascending Display";
        cout << "2. Descending Display";
        cout << "0. Exit";
        border << '\n';

        cout << ">>   <<\b\b\b\b";
        FilteredInput(1);
        break;

    case '0': incorrectInput = false; break;
    case '1':
        border;
        cout << "Ascending Display";
        border << '\n';
        break;

    case '2':
        border;
        cout << "Descending Display";
        border << '\n';
        break;

    case '!':
        border;
        cout << "There is no node in the current list";
        border << '\n';
        break;

    default: 
        MenuUI::ErrorUI(); 
        break;
    }
}

void MenuUI::ExitUI()
{
    border;
    cout << "~             Thank you!               ~";
    border;

    pause_second(2);
}

void MenuUI::ErrorUI() // informing user for error occured
{
    warning_border;
    cout << "~          Warning!            ~";
    cout << "~ Please! pay attention to the ~";
    cout << "~       Input you enter   -zyx ~";
    warning_border << "\n\n";

    temp.clear();
    choice = NULL;
    idNumber = NULL;
    number = NULL;

    pause_second(3);
}