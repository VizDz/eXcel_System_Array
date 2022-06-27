#pragma once

#pragma once

#include <iostream>
#include "classes.h"
#include <string>

using namespace std;


void mainMenu();
void loginPage();
void managerMenu();
void adminMenu(int);
void tutorMenu(int);



//MAIN MENU
void mainMenu()
{
	int option, opt;

	cout << "===== eXcel System =====" << endl;
	cout << "Welcome to eXcel System" << endl;
	cout << "1. Login to System" << endl << "2. Exit" << endl;

	cout << "Enter Option: ";
	cin >> option;

	while (cin.fail() || option < 1 || option > 2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Wrong Input" << endl;
		cout << "Enter Option: ";
		cin >> option;
	}
	// Login Page
	if (option == 1)
	{
		system("cls");
		loginPage();
	}
	else return;
}



//LOGIN PAGE
void loginPage()
{
	int option, cont, userID;
	string password, username;

	cout << "=== Login Page ===" << endl;
	cout << "1. HR" << endl << "2. Admin" << endl << "3. Tutor" << endl << "4. Back" << endl;

	cout << "Enter Login Option: ";
	cin >> option;

	while (cin.fail() || option < 1 || option > 4)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Wrong Input" << endl;
		cout << "Enter Login Option: ";
		cin >> option;
	}

	//HR LOGIN
	if (option == 1)
	{
		cont = 1;
		// HR
		cout << "\n=== HR Login ===" << endl;
		while (cont == 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Username: ";
			getline(cin, username);
			cout << "Password: ";
			getline(cin, password);
			

			if (username == "HR1" && password == "HR1")
			{
				break;
			}
			cout << "\nIncorrect Username/Password" << endl;
			cout << "Retry Login? (1 for Yes)";
			cin >> cont;
			cout << endl;
			if (cont != 1)
			{
				return;
			}
		}
		system("cls");
		managerMenu();
	}

	//ADMIN LOGIN
	else if (option == 2)
	{

		cont = 1;
		cout << "\n=== Admin Login ===" << endl;
		while (cont == 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Username: ";
			getline(cin, username);
			cout << "Password: ";
			getline(cin, password);

			if (bSearchAdminLog(username, password) != -1)
			{
				break;
			}
			cout << "\nIncorrect Username/Password" << endl;
			cout << "Retry Login? (1 for Yes)";
			cin >> cont;
			cout << endl;
			if (cont != 1)
			{
				return;
			}
		}
		userID = std::stoi(username);

		system("cls");
		adminMenu(userID);

	}

	//TUTOR LOGIN
	else if (option == 3)
	{
		cont = 1;
		cout << "\n=== Tutor Login ===" << endl;
		while (cont == 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Username: ";
			getline(cin, username);
			cout << "Password: ";
			getline(cin, password);

			if (bSearchTutorLog(username, password) != -1)
			{
				break;
			}
			cout << "\nIncorrect Username/Password" << endl;
			cout << "Retry Login? (1 for Yes)";
			cin >> cont;
			cout << endl;
			if (cont != 1)
			{
				return;
			}
		}
		userID = std::stoi(username);

		system("cls");
		tutorMenu(userID);
	}


	//BACK
	else
	{
		system("cls");
		mainMenu();
	}
}



//HR ADMIN MENU
void managerMenu()
{
	int choice, choice2, choice3;
	int id;

	cout << "=== HR Manager Menu ===" << endl;
	cout << "1. Manage User (Admin)" << endl << "2. Manage Centre" << endl << "3. Manage Subjects" << endl
		<< "4. Manage Tutors" << endl << "5. Add Ratings" << endl << "6. Generate Report" << endl
		<< "7. Logout" << endl;

	cout << "Enter Option: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 7)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Wrong Input" << endl;
		cout << "Enter Option: ";
		cin >> choice;
	}

	system("cls");

	//MANAGE ADMIN 
	if (choice == 1)
	{

		cout << "=== Admin Management ===" << endl;
		cout << "1. Add Admin" << endl << "2. Display Admin" << endl <<
			"3. Search Admin" << endl << "4. Edit Admin" << endl << "5. Delete Admin" << endl << "6. Back" << endl;
		if (sizeA == 0) {
			cout << "\nNo Admin Record Exist !!!" << endl << "Please Enter New Admin Data :)" << endl << "Only Can Choose 1 or 6 !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || (choice2 != 1 && choice2 != 6))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeA != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		else if (sizeA == 1000)
		{
			cout << "\nAdmin Record FULL !!!" << endl << "Cannot choose 1 to Add Admin !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 > 6 || choice < 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		system("cls");

		//ADD ADMIN
		if (choice2 == 1)
		{
			int c1 = 0;
			int cID;
			string pass;

			for (int i = 0; i < sizeC; i++) {
				if (centreArray[i].fill == 0)
				{
					c1++;
				}
			}
			if (c1 != 0)
			{
				cout << "==ADD NEW ADMIN==" << endl;
				int id = generateAdminID();
				cout << "\nAdmin ID : " << id << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Password: ";
				getline(cin, pass);

				cout << "\nAvailable Centre ID : " << endl;
				for (int i = 0; i < sizeC; i++)
				{
					if (centreArray[i].fill == 0) {
						cout << centreArray[i].centreID << endl;
					}
					
				}
				cout << "Enter Centre ID: ";
				cin >> cID;
				while (cin.fail() || bSearchEmptyCentreID(cID) == -1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Centre Not Found!" << endl;
					cout << "\nEnter Centre ID: ";
					cin >> cID;
				}
				for (int i = 0; i < sizeC; i++) {
					if (centreArray[i].centreID == cID)
					{
						centreArray[i].fill = 1; //Change to 0 to indicate the centre become empty
					}
				}
				insertAdmin(createAdmin(id, pass, cID));
				cout << "Admin Added Succesfully" << endl;
			}
			else {
				cout << "NO CENTRE AVAILABLE... /n Therefore cannot add new Admin !!!" << endl;
				system("pause");
				system("cls");
				managerMenu();
			}

			system("pause");
			system("cls");
			managerMenu();
		}

		// DISPLAY ALL ADMIN
		else if (choice2 == 2)
		{
			cout << "==ALL ADMIN INFORMATION==" << endl;
			displayA();
			system("pause");
			system("cls");
			managerMenu();
		}

		//SEARCH & DISPLAY ADMIN
		else if (choice2 == 3)
		{
			cout << "==SEARCH & DISPLAY ADMIN==" << endl;
			cout << "Available Admin ID : " << endl;
			for (int i = 0; i < sizeA; i++) {
				cout << "| " << adminArray[i].adminID << " |";
			}
			cout << "\nEnter Admin ID (1001-1999) : ";
			cin >> id;
			while (cin.fail() || bSearchAdminID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Admin Not Found!" << endl;
				cout << "\nEnter Admin ID (1001-1999) : ";
				cin >> id;
			}
			sdAdmin(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		// MODIFY ADMIN
		else if (choice2 == 4)
		{
			cout << "==MODIFY ADMIN==" << endl;
			cout << "\n Available Admin ID : " << endl;
			for (int i = 0; i < sizeA; i++) {
				cout << "| " << adminArray[i].adminID << " |";
			}
			cout << "\nEnter Admin ID (1001-1999) : ";
			cin >> id;
			while (cin.fail() || bSearchAdminID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Admin Not Found!" << endl;
				cout << "\nEnter Admin ID: ";
				cin >> id;
			}
			editA(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		//DELETE ADMIN
		else if (choice2 == 5)
		{
			cout << "==DELETE ADMIN==" << endl;
			cout << "\n Available Admin ID : " << endl;
			for (int i = 0; i < sizeA; i++)
			{
				cout << "| " << adminArray[i].adminID << " |";
			}
			cout << "\nEnter Admin ID (1001-1999) : ";
			cin >> id;
			while (cin.fail() || bSearchAdminID(id) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Admin Not Found!" << endl;
				cout << "\nEnter Admin ID: ";
				cin >> id;
			}
			deleteA(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		// BACK
		else
		{
			system("cls");
			managerMenu();
		}

	}

	//MANAGE CENTRE
	else if (choice == 2)
	{
		cout << "=== Centre Management ===" << endl;
		cout << "1. Add Centre" << endl << "2. Display Centre" << endl << "3. Search Centre" << endl <<
			"4. Edit Centre" << endl << "5. Delete Centre" << endl << "6. Back" << endl;

		if (sizeC == 0) {
			cout << "\nNo Centre Record Exist !!!" << endl << "Please Enter New Centre Data :)" << endl << "Only Can Choose 1 or 6 !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || (choice2 != 1 && choice2 != 6))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeC != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		else if (sizeC == 100)
		{
			cout << "\nCentre Record FULL !!!" << endl << "Cannot choose 1 to Add Centre !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 > 6 || choice < 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		system("cls");

		//ADD NEW CENTRE
		if (choice2 == 1)
		{
			int id;
			int fill = 0;
			string name, location;

			cout << "=== ADD NEW CENTRE ===" << endl;
			id = generateCentreID();
			cout << "\nCentre ID : " << id << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter Centre Name: ";
			getline(cin, name);
			cout << "Enter Centre Location: ";
			getline(cin, location);

			insertCentre(createCentre(id, name, location, fill));
			cout << "Centre Added Succesfully" << endl;

			system("pause");
			system("cls");
			managerMenu();
		}

		//DISPLAY ALL CENTRE
		else if (choice2 == 2)
		{
			cout << "==ALL CENTRE INFORMATION==" << endl;
			displayC();
			system("pause");
			system("cls");
			managerMenu();
		}

		//SEARCH & DISPLAY CENTRE
		else if (choice2 == 3)
		{
			cout << "==SEARCH & DISPLAY CENTRE==" << endl;
			cout << "Availabe Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++) {
				cout << "| " << centreArray[i].centreID << " |";
			}
			cout << "\nEnter Centre ID (201-299) : ";
			cin >> id;
			while (cin.fail() || bSearchCentreID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;
				cout << "\nEnter Centre ID (201-299): ";
				cin >> id;
			}
			sdCentre(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		//MODIFY CENTRE
		else if (choice2 == 4)
		{
			cout << "==MODIFY CENTRE==" << endl;
			cout << "\n Available Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++) {
				cout << "| " << centreArray[i].centreID << " |";
			}
			cout << "\nEnter Centre ID (201-299) : ";
			cin >> id;
			while (cin.fail() || bSearchCentreID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;
				cout << "\nEnter Centre ID (201-299) : ";
				cin >> id;
			}
			editC(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		//DELETE CENTRE
		else if (choice2 == 5)
		{
			cout << "==DELETE CENTRE==" << endl;
			cout << "\n Available Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++)
			{
				cout << "| " << centreArray[i].centreID << " |";
			}
			cout << "\nEnter Centre ID (201-299) : ";
			cin >> id;
			while (cin.fail() || bSearchCentreID(id) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;
				cout << "\nEnter Centre ID (201-299) : ";
				cin >> id;
			}
			deleteC(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		// BACK
		else
		{
			system("cls");
			managerMenu();
		}

	}

	//MANAGE SUBJECT
	else if (choice == 3)
	{
		cout << "=== Subject Management ===" << endl;
		cout << "1. Add Subject" << endl << "2. Display Subject" << endl << "3. Search Subject" << endl <<
			"4. Edit Subject" << endl << "5. Delete Subject" << endl << "6. Back" << endl;
		if (sizeS == 0) {
			cout << "\nNo Subject Record Exist !!!" << endl << "Please Enter New Subject Data :)" << endl << "Only Can Choose 1 or 6 !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while
				(cin.fail() || (choice2 != 1 && choice2 != 6))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeS != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		else if (sizeS == 100)
		{
			cout << "\nSubject Record FULL !!!" << endl << "Cannot choose 1 to Add Subject !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 > 6 || choice < 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}

		system("cls");

		//ADD NEW SUBJECT
		if (choice2 == 1)
		{
			int id;
			double rate;
			string name;

			cout << "=== ADD NEW SUBJECT ===" << endl;
			id = generateSubjectID();
			cout << "\nSubject ID : " << id << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Subject Name: ";
			getline(cin, name);

			while (cin.fail() || bSearchSubjectName(name) != -1) {
				cin.clear();
				cout << "Subject Name Exist!" << endl;
				cout << "\nEnter New Subject Name: ";
				getline(cin, name);
			}

			cout << "Enter Hourly Rate (40-80): ";
			cin >> rate;

			while (cin.fail() || rate < 40 || rate > 80) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nWrong Input!" << endl;
				cout << "Enter Hourly Rate (40-80): ";
				cin >> rate;
			}

			insertSubject(createSubject(id, name, rate));
			cout << "Subject Added Succesfully" << endl;

			system("pause");
			system("cls");
			managerMenu();
		}

		//DISPLAY ALL SUBJECT
		else if (choice2 == 2)
		{
			cout << "==ALL SUBJECT INFORMATION==" << endl;
			displayS();
			system("pause");
			system("cls");
			managerMenu();
		}

		//SEARCH & DISPLAY SUBJECT
		else if (choice2 == 3)
		{
			cout << "==SEARCH & DISPLAY SUBJECT==" << endl;
			cout << "Availabe Subject ID : " << endl;
			for (int i = 0; i < sizeS; i++) {
				cout << "| " << subjectArray[i].subjectID << " |";
			}
			cout << "\nEnter Subject ID (101-199) : ";
			cin >> id;
			while (cin.fail() || bSearchSubjectID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Subject Not Found!" << endl;
				cout << "\nEnter Subject ID (101-199): ";
				cin >> id;
			}
			sdSubject(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		//MODIFY SUBJECT
		else if (choice2 == 4)
		{
			cout << "==MODIFY SUBJECT==" << endl;
			cout << "Availabe Subject ID : " << endl;
			for (int i = 0; i < sizeS; i++) {
				cout << "| " << subjectArray[i].subjectID << " |";
			}
			cout << "\nEnter Subject ID (101-199) : ";
			cin >> id;
			while (cin.fail() || bSearchSubjectID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Subject Not Found!" << endl;
				cout << "\nEnter Subject ID (101-199): ";
				cin >> id;
			}
			editS(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		//DELETE SUBJECT
		else if (choice2 == 5)
		{
			cout << "==DELETE SUBJECT==" << endl;
			cout << "Availabe Subject ID : " << endl;
			for (int i = 0; i < sizeS; i++) {
				cout << "| " << subjectArray[i].subjectID << " |";
			}
			cout << "\nEnter Subject ID (101-199) : ";
			cin >> id;
			while (cin.fail() || bSearchSubjectID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Subject Not Found!" << endl;
				cout << "\nEnter Subject ID (101-199): ";
				cin >> id;
			}
			deleteS(id);
			system("pause");
			system("cls");
			managerMenu();
		}

		// BACK
		else
		{
			system("cls");
			managerMenu();
		}
	}

	//MANAGE TUTOR
	else if (choice == 4)
	{
		cout << "=== Tutor Management ===" << endl;
		cout << "1. Add Tutor" << endl << "2. Display Tutor" << endl << "3. Search Tutor" << endl <<
			"4. Edit Tutor" << endl << "5. Delete Tutor" << endl << "6. Back" << endl;

		if (sizeT == 0) {
			cout << "\nNo Tutor Record Exist !!!" << endl << "Please Enter New Tutor Data :)" << endl << "Only Can Choose 1 or 6 !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while
				(cin.fail() || (choice2 != 1 && choice2 != 6))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeT != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		else if (sizeS == 1000)
		{
			cout << "\nTutor Record FULL !!!" << endl << "Cannot choose 1 to Add Tutor !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 > 6 || choice < 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}

		system("cls");

		//ADD NEW TUTOR
		if (choice2 == 1)
		{
			int id, centreID, subjectID, maxTutor = 4, cnt = 0;
			string pass, fname, lname, address, phone, jDate;

			cout << "=== ADD NEW TUTOR ===" << endl;
			id = generateTutorID();
			cout << "\nTutor ID : " << id << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Password: ";
			getline(cin, pass);
			cout << "Enter Tutor First Name: ";
			getline(cin, fname);
			cout << "Enter Tutor Last Name: ";
			getline(cin, lname);
			cout << "Enter Tutor Address: ";
			getline(cin, address);
			cout << "Enter Phone Number: ";
			getline(cin, phone);
			cout << "Enter Join Date (dd/mm/yyyy): ";
			getline(cin, jDate);

			cout << "\nAvailabe Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++) {
				cout << "| " << centreArray[i].centreID << " |";
			}
			cout << "\nEnter Centre ID (201-299) : ";
			cin >> centreID;
			while (cin.fail() || bSearchCentreID(centreID) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;
				cout << "\nEnter Centre ID (201-299): ";
				cin >> centreID;
			}


			cout << "\nAvailabe Subject ID : " << endl;
			for (int i = 0; i < sizeS; i++) {
				cout << "| " << subjectArray[i].subjectID << " | " << subjectArray[i].subjectName << " | " << subjectArray[i].hourlyPayRate << " | " << endl;
			}


			cout << "\nEnter Subject ID (101-199) : ";
			cin >> subjectID;
			while (cin.fail() || bSearchSubjectID(subjectID) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Subject Not Found!" << endl;
				cout << "\nEnter Subject ID (101-199): ";
				cin >> subjectID;
			}

			//CHECK TO MAKE SURE ONLY 4 TUTOR WITH SAME SUBJECT IN EVERY CENTRE
			cnt = checkerTut(centreID, subjectID);

			if (cnt < 4) {
				insertTutor(createTutor(id, pass, fname, lname, address, phone, jDate, centreID, subjectID));

				cout << "\nTutor Added Succesfully" << endl;
				system("pause");
				system("cls");
				managerMenu();
			}
			else {
				cout << "\nSlot is FULL !!!" << endl << "Record not Saved :/" << endl;
				system("pause");
				system("cls");
				managerMenu();
			}
		}

		//DISPLAY TUTOR OPTION
		else if (choice2 == 2)
		{
			cout << "=== TUTOR DISPLAY ===" << endl;
			cout << "1. Display All by Tutor ID (Ascending)" << endl << "2. Display All by HourlyPayRate (Ascending)" << endl <<
				"3. Display All by Overall Performance (Ascending)" << endl << "4. Pagination" << endl << "5. Back" << endl;
			cout << "Enter Option : ";
			cin >> choice3;

			while (cin.fail() || choice3 < 1 || choice3 > 5)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice3;
			}

			system("cls");

			//TUTOR ID ASC ORDER
			if (choice3 == 1)
			{
				cout << "==ALL TUTOR INFORMATION BY TUTOR ID==" << endl;
				quickSortTutorID(tutorArray, 0, sizeT - 1);
				displayT();
				system("pause");
				system("cls");
				managerMenu();
			}

			//TUTOR PAYRATE ASC ORDER
			else if (choice3 == 2)
			{
				cout << "==ALL TUTOR INFORMATION BY TUTOR HOURLY PAY RATE==" << endl;
				quickSortSubjectHPR(subjectArray, 0, sizeS - 1);
				for (int i = 0; i < sizeS; i++)
				{
					for (int j = 0; j < sizeT; j++)
					{
						if (subjectArray[i].subjectID == tutorArray[j].subjectID)
						{
							cout << "Tutor ID\t: " << tutorArray[j].tutorID << endl;
							cout << "Password\t: " << tutorArray[j].password << endl;
							cout << "First Name\t: " << tutorArray[j].fname << endl;
							cout << "Last Name\t: " << tutorArray[j].lname << endl;
							cout << "Address\t\t: " << tutorArray[j].address << endl;
							cout << "Phone Number\t: " << tutorArray[j].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[j].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[j].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[j].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[j].numberRated << endl;
							cout << "Rating\t\t\t: " << tutorArray[j].rating << endl;
							cout << "Centre ID\t: " << tutorArray[j].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[j].subjectID << endl;
							cout << endl;
						}
					}
				}
				quickSortSubjectID(subjectArray, 0, sizeS - 1);
				system("pause");
				system("cls");
				managerMenu();
			}

			//OVERALL PERFORMANCE
			else if (choice3 == 3)
			{
				cout << "==ALL TUTOR INFORMATION BY OVERALL PERFORMANCE==" << endl;
				quickSortTutorRating(tutorArray, 0, sizeT - 1);
				displayT();
				quickSortTutorID(tutorArray, 0, sizeT - 1);
				system("pause");
				system("cls");
				managerMenu();
			}

			//PAGINATION
			else if (choice3 == 4)
			{
				cout << "PAGINATION" << endl; 
				pagination(sizeT);
				system("pause");
				system("cls");
				managerMenu();
			}

			else
			{
				system("cls");
				managerMenu();
			}

		}

		//SEARCH & DISPLAY TUTOR
		else if (choice2 == 3)
		{
			int choice4 = 0;
			cout << "==SEARCH & DISPLAY TUTOR==" << endl;
			cout << "1. Search By ID" << endl << "2. Search By Overall Performance" << endl << "3. Back" << endl;
			cout << "Enter Option : ";
			cin >> choice3;
			while (cin.fail() || choice3 < 1 || choice3 > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice3;
			}
			system("cls");

			//SEARCH BY ID
			if (choice3 == 1)
			{
				cout << "\nAvailabe Tutor ID : " << endl;
				for (int i = 0; i < sizeT; i++) {
					cout << "| " << tutorArray[i].tutorID << " |";
				}
				cout << "\nEnter Tutor ID (2001-2999) : ";
				cin >> id;
				while (cin.fail() || bSearchTutorID(id) == -1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Tutor Not Found!" << endl;
					cout << "\nEnter Tutor ID (2001-2999): ";
					cin >> id;
				}
				sdTutor(id);
				system("pause");
				system("cls");
				managerMenu();
			}
			//SEARCH BY OVERALL PERFORMANCE
			else if (choice3 == 2)
			{
				cout << "==SEARCH TUTOR BY RATING==" << endl << "1. 0 to 1" << endl;
				cout << "2. 1+ to 2" << endl << "2. 2+ to 3" << endl << "4. 3+ to 4" << endl << "5. 4+ to 5" << endl << "6. Back" << endl;
				cout << "Enter Option : ";
				cin >> choice4;
				while (cin.fail() || choice4 < 1 || choice4 > 6)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Wrong Input" << endl;
					cout << "Enter Option: ";
					cin >> choice4;
				}
				if (choice4 == 1)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating >= 0 && tutorArray[i].rating <= 1) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					managerMenu();
				}
				else if (choice4 == 2)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 1 && tutorArray[i].rating <= 2) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					managerMenu();
				}
				else if (choice4 == 3)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 2 && tutorArray[i].rating <= 3) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					managerMenu();
				}
				else if (choice4 == 4)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 3 && tutorArray[i].rating <= 4) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					managerMenu();
				}
				else if (choice4 == 5)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 4 && tutorArray[i].rating <= 5) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					managerMenu();
				}
				else
				{
					system("cls");
					managerMenu();
				}

			}
			//BACK
			else
			{
				system("cls");
				managerMenu();
			}
		
		}

		//MODIFY TUTOR
		else if (choice2 == 4)
		{
			cout << "==MODIFY TUTOR==" << endl;
			cout << "Availabe Tutor ID : " << endl;
			for (int i = 0; i < sizeT; i++)
			{
				cout << "| " << tutorArray[i].tutorID << " |";
			}
			cout << "\nEnter Tutor ID (2001-2999) : ";
			cin >> id;
			while (cin.fail() || bSearchTutorID(id) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Tutor Not Found!" << endl;
				cout << "\nEnter Tutor ID (2001-2999): ";
				cin >> id;
			}
			editT(id); 
			system("pause");
			system("cls");
			managerMenu();
		}

		//DELETE TUTOR
		else if (choice2 == 5)
		{
			cout << "==DELETE TUTOR==" << endl;
			cout << "Availabe Tutor ID : " << endl;
			for (int i = 0; i < sizeT; i++) {
				cout << "| " << tutorArray[i].tutorID << " |";
			}
			cout << "\nEnter Tutor ID (2001-2999) : ";
			cin >> id;
			while (cin.fail() || bSearchTutorID(id) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Tutor Not Found!" << endl;
				cout << "\nEnter Tutor ID (2001-2999): ";
				cin >> id;
			}
			deleteT(id); 
			system("pause");
			system("cls");
			managerMenu();
		}

		//BACK
		else
		{
			system("cls");
			managerMenu();
		}

	}

	//ADD RATINGS
	else if (choice == 5)
	{
		cout << "==ADD TUTOR RATING==" << endl;
		cout << "Availabe Tutor ID : " << endl;
		for (int i = 0; i < sizeT; i++)
		{
			cout << "| " << tutorArray[i].tutorID << " |";
		}
		cout << "\nEnter Tutor ID (2001-2999) : ";
		cin >> id;
		while (cin.fail() || bSearchTutorID(id) == -1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Tutor Not Found!" << endl;
			cout << "\nEnter Tutor ID (2001-2999): ";
			cin >> id;
		}

		addRating(id);
		system("pause");
		system("cls");
		managerMenu();
	}

	//GENERATE REPORT
	else if (choice == 6)
	{
		cout << "===REPORT===" << endl;
		genReport();

		system("pause");
		system("cls");
		managerMenu();
	}

	//LOGOUT
	else
	{
		system("cls");
		loginPage();
	}

}



//ADMIN MENU
void adminMenu(int userID)
{
	int choice, choice2, choice3;
	int id2 = userID;
	int id;

	cout << "=== Admin Menu ===" << endl;
	cout << "1. View Centre" << endl << "2. View Subject" << endl << "3. Manage Tutor (Centre)" << endl
		<< "4. Generate Report" << endl << "5. Logout" << endl;
	cout << "Enter Option: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 5)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong Input" << endl;
		cout << "Enter Option: ";
		cin >> choice;
	}

	system("cls");
	//VIEW & SEARCH CENTRE
	if (choice == 1)
	{
		cout << "=== View Centre Menu ===" << endl;
		cout << "1. Display All" << endl << "2. Search" << endl << "3. Back" << endl;
		if (sizeC == 0) {
			cout << "\nNo Centre Record Exist !!!" << endl << "Only Can Choose 3 to back !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || (choice2 != 3))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeC != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		system("cls");
		//DISPLAY ALL CENTRE
		if (choice2 == 1)
		{
			cout << "==ALL CENTRE INFORMATION==" << endl;
			displayC();
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		//SEARCH & DISPLAY CENTRE
		else if (choice2 == 2)
		{
			cout << "==SEARCH & DISPLAY CENTRE==" << endl;
			cout << "Availabe Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++) {
				cout << "| " << centreArray[i].centreID << " |";
			}
			cout << "\nEnter Centre ID (201-299) : ";
			cin >> id;
			while (cin.fail() || bSearchCentreID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;                
				cout << "\nEnter Centre ID (201-299): ";
				cin >> id;
			}
			sdCentre(id);
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		// BACK
		else
		{
			system("cls");
			adminMenu(id2);
		}
	}


	//VIEW & SEARCH SUBJECT
	else if (choice == 2)
	{
		cout << "=== View Subject Menu ===" << endl;
		cout << "1. Display All" << endl << "2. Search" << endl << "3. Back" << endl;
		if (sizeS == 0) {
			cout << "\nNo Subject Record Exist !!!" << endl << "Only Can Choose 3 to back !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || (choice2 != 3))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeS != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		system("cls");
		//DISPLAY ALL SUBJECT
		if (choice2 == 1)
		{
			cout << "==ALL SUBJECT INFORMATION==" << endl;
			displayS();
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		//SEARCH & DISPLAY SUBJECT
		else if (choice2 == 2)
		{
			cout << "==SEARCH & DISPLAY SUBJECT==" << endl;
			cout << "Availabe Subject ID : " << endl;
			for (int i = 0; i < sizeS; i++) {
				cout << "| " << subjectArray[i].subjectID << " |";
			}
			cout << "\nEnter Subject ID (101-199) : ";
			cin >> id;
			while (cin.fail() || bSearchSubjectID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Subject Not Found!" << endl;
				cout << "\nEnter Subject ID (101-199): ";
				cin >> id;
			}
			sdSubject(id);
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		//BACK
		else
		{
			system("cls");
			adminMenu(id2);
		}
	}


	//MANAGE TUTOR (SPECIFIC CENTRE)
	else if (choice == 3)
	{
		int cenID;
		int sizeCon = 0;
		for (int i = 0; i < sizeC; i++)
		{
			if (adminArray[i].adminID == id2)
			{
				cenID = adminArray[i].centreID;
			}
		}

		for (int i = 0; i < sizeT; i++)
		{
			if (tutorArray[i].centreID == cenID)
			{
				sizeCon++;
			}
		}

		cout << "=== TUTOR MANAGEMENT IN CENTRE " << cenID << " ===" << endl;
		cout << "1. View Tutor" << endl << "2. Search & Display Tutor" << endl << "3. Modify Tutor" << endl << "4. Delete Tutor" << endl <<
			"5. Add Ratings" << endl << "6. Back" << endl;

		if (sizeCon == 0) {
			cout << "\nNo Tutor Record Exist !!!" << endl << "Only Can Choose 5 to back !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while
				(cin.fail() || (choice2 != 6))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeCon != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}

		system("cls");

		//VIEW TUTOR
		if (choice2 == 1)
		{
			cout << "=== TUTOR DISPLAY ===" << endl;
			cout << "1. Display All by Tutor ID (Ascending)" << endl << "2. Display All by HourlyPayRate (Ascending)" << endl <<
				"3. Display All by Overall Performance (Ascending)" << endl << "4. Pagination" << endl << "5. Back" << endl;
			cout << "Enter Option : ";
			cin >> choice3;

			while (cin.fail() || choice3 < 1 || choice3 > 5)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice3;
			}

			system("cls");

			//TUTOR ID ASC ORDER
			if (choice3 == 1)
			{
				cout << "==ALL TUTOR INFORMATION BY TUTOR ID==" << endl;
				quickSortTutorID(tutorArray, 0, sizeT - 1);
				displayST(cenID);
				system("pause");
				system("cls");
				adminMenu(id2);
			}

			//TUTOR PAYRATE ASC ORDER
			else if (choice3 == 2)
			{
				cout << "==ALL TUTOR INFORMATION BY TUTOR HOURLY PAY RATE==" << endl;
				quickSortSubjectHPR(subjectArray, 0, sizeS - 1);
				for (int i = 0; i < sizeS; i++)
				{
					for (int j = 0; j < sizeT; j++)
					{
						if ((subjectArray[i].subjectID == tutorArray[j].subjectID) && (tutorArray[j].centreID == cenID))
						{
							cout << "Tutor ID\t: " << tutorArray[j].tutorID << endl;
							cout << "Password\t: " << tutorArray[j].password << endl;
							cout << "First Name\t: " << tutorArray[j].fname << endl;
							cout << "Last Name\t: " << tutorArray[j].lname << endl;
							cout << "Address\t\t: " << tutorArray[j].address << endl;
							cout << "Phone Number\t: " << tutorArray[j].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[j].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[j].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[j].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[j].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[j].rating << endl;
							cout << "Centre ID\t: " << tutorArray[j].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[j].subjectID << endl;
							cout << endl;
						}
					}
				}
				quickSortSubjectID(subjectArray, 0, sizeS - 1);
				system("pause");
				system("cls");
				adminMenu(id2);
			}

			//OVERALL PERFORMANCE
			else if (choice3 == 3)
			{
				cout << "==ALL TUTOR INFORMATION BY OVERALL PERFORMANCE==" << endl;
				quickSortTutorRating(tutorArray, 0, sizeT - 1);
				displayST(cenID);
				quickSortTutorID(tutorArray, 0, sizeT - 1);
				system("pause");
				system("cls");
				adminMenu(id2);
			}

			//PAGINATION
			else if (choice3 == 4)
			{
				cout << "PAGINATION" << endl; //ADD PAGINATIOIN FUNCTION HERE
				pagination(sizeCon);
				system("pause");
				system("cls");
				adminMenu(id2);
			}

			else
			{
				system("cls");
				adminMenu(id2);
			}
		}

		//SEARCH & DISPLAY TUTOR
		else if (choice2 == 2)
		{

			int choice4 = 0;
			cout << "== SEARCH & DISPLAY TUTOR IN CENTRE " << cenID << " ==" << endl;
			cout << "1. Search By ID" << endl << "2. Search By Overall Performance" << endl << "3. Back" << endl;
			cout << "Enter Option : ";
			cin >> choice3;
			while (cin.fail() || choice3 < 1 || choice3 > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice3;
			}
			system("cls");

			//SEARCH BY ID
			if (choice3 == 1)
			{
				cout << "Availabe Tutor ID : " << endl;
				for (int i = 0; i < sizeT; i++)
				{
					if (tutorArray[i].centreID == cenID)
					{
						cout << "| " << tutorArray[i].tutorID << " |";
					}

				}
				cout << "\nEnter Tutor ID (2001-2999) : ";
				cin >> id;
				while (cin.fail() || bSearchTutorCen(id, cenID) == -1)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Tutor Not Found!" << endl;
					cout << "\nEnter Tutor ID (2001-2999): ";
					cin >> id;
				}
				sdTutor(id);
				system("pause");
				system("cls");
				adminMenu(id2);
			}
			//SEARCH BY OVERALL PERFORMANCE
			else if (choice3 == 2)
			{
				cout << "==SEARCH TUTOR BY RATING==" << endl << "1. 0 to 1" << endl;
				cout << "2. 1+ to 2" << endl << "2. 2+ to 3" << endl << "4. 3+ to 4" << endl << "5. 4+ to 5" << endl << "6. Back" << endl;
				cout << "Enter Option : ";
				cin >> choice4;
				while (cin.fail() || choice4 < 1 || choice4 > 6)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Wrong Input" << endl;
					cout << "Enter Option: ";
					cin >> choice4;
				}
				if (choice4 == 1)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating >= 0 && tutorArray[i].rating <= 1 && tutorArray[i].centreID == cenID) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					adminMenu(id2);
				}
				else if (choice4 == 2)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 1 && tutorArray[i].rating <= 2 && tutorArray[i].centreID == cenID) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					adminMenu(id2);
				}
				else if (choice4 == 3)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 2 && tutorArray[i].rating <= 3 && tutorArray[i].centreID == cenID)  {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					adminMenu(id2);
				}
				else if (choice4 == 4)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 3 && tutorArray[i].rating <= 4 && tutorArray[i].centreID == cenID) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					adminMenu(id2);
				}
				else if (choice4 == 5)
				{
					for (int i = 0; i < sizeT; i++)
					{
						if (tutorArray[i].rating > 4 && tutorArray[i].rating <= 5 && tutorArray[i].centreID == cenID) {
							cout << "\nTutor ID\t: " << tutorArray[i].tutorID << endl;
							cout << "Password\t: " << tutorArray[i].password << endl;
							cout << "First Name\t: " << tutorArray[i].fname << endl;
							cout << "Last Name\t: " << tutorArray[i].lname << endl;
							cout << "Address\t\t: " << tutorArray[i].address << endl;
							cout << "Phone Number\t: " << tutorArray[i].phoneNumber << endl;
							cout << "Joined Date\t: " << tutorArray[i].joinedDate << endl;
							cout << "Terminated Date\t: " << tutorArray[i].terminatedDate << endl;
							cout << "Total Rating\t: " << tutorArray[i].totRating << endl;
							cout << "Number Rated\t: " << tutorArray[i].numberRated << endl;
							cout << "Rating\t\t: " << tutorArray[i].rating << endl;
							cout << "Centre ID\t: " << tutorArray[i].centreID << endl;
							cout << "Subject ID\t: " << tutorArray[i].subjectID << endl;
						}
					}
					system("pause");
					system("cls");
					adminMenu(id2);
				}
				else
				{
					system("cls");
					adminMenu(id2);
				}

			}
			//BACK
			else
			{
				system("cls");
				adminMenu(id2);
			}



		}
		//MODIFY TUTOR IN THIS CENTRE
		else if (choice2 == 3)
		{
		cout << "== MODIFY TUTOR IN CENTRE " << cenID << " ==" << endl;
			cout << "Availabe Tutor ID : " << endl;
			for (int i = 0; i < sizeT; i++)
			{
				if (tutorArray[i].centreID == cenID)
				{
					cout << "| " << tutorArray[i].tutorID << " |";
				}

			}
			cout << "\nEnter Tutor ID (2001-2999) : ";
			cin >> id;
			while (cin.fail() || bSearchTutorCen(id, cenID) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Tutor Not Found!" << endl;
				cout << "\nEnter Tutor ID (2001-2999): ";
				cin >> id;
			}
			editT(id);
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		//MODIFY TUTOR IN THIS CENTRE
		else if (choice2 == 4)
		{
			cout << "== DELETE TUTOR IN CENTRE " << cenID << " ==" << endl;
			cout << "Availabe Tutor ID : " << endl;
			for (int i = 0; i < sizeT; i++)
			{
				if (tutorArray[i].centreID == cenID)
				{
					cout << "| " << tutorArray[i].tutorID << " |";
				}

			}
			cout << "\nEnter Tutor ID (2001-2999) : ";
			cin >> id;
			while (cin.fail() || bSearchTutorCen(id, cenID) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Tutor Not Found!" << endl;
				cout << "\nEnter Tutor ID (2001-2999): ";
				cin >> id;
			}
			deleteT(id);
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		//ADD RATINGS FOR TUTOR IN THIS ADMIN CENTRE
		else if (choice2 == 5)
		{
			cout << "== ADD TUTOR RATING IN CENTRE " << cenID << " ==" << endl;
			cout << "Availabe Tutor ID : " << endl;
			for (int i = 0; i < sizeT; i++)
			{
				if (tutorArray[i].centreID == cenID)
				{
					cout << "| " << tutorArray[i].tutorID << " |";
				}

			}
			cout << "\nEnter Tutor ID (2001-2999) : ";
			cin >> id;
			while (cin.fail() || bSearchTutorCen(id, cenID) == -1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Tutor Not Found!" << endl;
				cout << "\nEnter Tutor ID (2001-2999): ";
				cin >> id;
			}
			addRating(id);
			system("pause");
			system("cls");
			adminMenu(id2);
		}

		else
		{
			system("cls");
			adminMenu(id2);
		}
	}


	//GENERATE REPORT
	else if (choice == 4)
	{
		cout << "===REPORT===" << endl;
		genReport();
		system("pause");
		system("cls");
		adminMenu(id2);
	}


	//LOGOUT
	else
	{
		id2 = NULL;
		userID = NULL;
		system("cls");
		loginPage();
	}
}



//TUTOR MENU
void tutorMenu(int userID)
{
	int choice, choice2;
	int id2 = userID;
	int id;

	cout << "=== Tutor Menu ===" << endl;
	cout << "1. View Centre" << endl << "2. View Subject" << endl << "3. View Profile" << endl << "4. Logout" << endl;
	cout << "Enter Option: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 4)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong Input" << endl;
		cout << "Enter Option: ";
		cin >> choice;
	}

	system("cls");
	//VIEW CENTRE
	if (choice == 1)
	{
		cout << "=== View Centre Menu ===" << endl;
		cout << "1. Display All" << endl << "2. Search" << endl << "3. Back" << endl;

		if (sizeC == 0) {
			cout << "\nNo Centre Record Exist !!!" << endl << "Only Can Choose 3 to back !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || (choice2 != 3))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeC != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		system("cls");
		//DISPLAY ALL CENTRE
		if (choice2 == 1)
		{
			cout << "==ALL CENTRE INFORMATION==" << endl;
			displayC();
			system("pause");
			system("cls");
			tutorMenu(id2);
		}

		//SEARCH & DISPLAY CENTRE
		else if (choice2 == 2)
		{
			cout << "==SEARCH & DISPLAY CENTRE==" << endl;
			cout << "Availabe Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++) {
				cout << "| " << centreArray[i].centreID << " |";
			}
			cout << "\nEnter Centre ID (201-299) : ";
			cin >> id;
			while (cin.fail() || bSearchCentreID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;
				cout << "\nEnter Centre ID (201-299): ";
				cin >> id;
			}
			sdCentre(id);
			system("pause");
			system("cls");
			tutorMenu(id2);
		}

		// BACK
		else
		{
			system("cls");
			tutorMenu(id2);
		}

	}

	//VIEW SUBJECT
	else if (choice == 2)
	{
		cout << "=== View Subject Menu ===" << endl;
		cout << "1. Display All" << endl << "2. Search" << endl << "3. Back" << endl;
		if (sizeS == 0) {
			cout << "\nNo Subject Record Exist !!!" << endl << "Only Can Choose 3 to back !!!" << endl;
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || (choice2 != 3))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}

		}
		else if (sizeS != 0) {
			cout << "Enter Option: ";
			cin >> choice2;
			while (cin.fail() || choice2 < 1 || choice2 > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Wrong Input" << endl;
				cout << "Enter Option: ";
				cin >> choice2;
			}
		}
		system("cls");
		//DISPLAY ALL SUBJECT
		if (choice2 == 1)
		{
			cout << "==ALL SUBJECT INFORMATION==" << endl;
			displayS();
			system("pause");
			system("cls");
			tutorMenu(id2);
		}

		//SEARCH & DISPLAY SUBJECT
		else if (choice2 == 2)
		{
			cout << "==SEARCH & DISPLAY SUBJECT==" << endl;
			cout << "Availabe Subject ID : " << endl;
			for (int i = 0; i < sizeS; i++) {
				cout << "| " << subjectArray[i].subjectID << " |";
			}
			cout << "\nEnter Subject ID (101-199) : ";
			cin >> id;
			while (cin.fail() || bSearchSubjectID(id) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Subject Not Found!" << endl;
				cout << "\nEnter Subject ID (101-199): ";
				cin >> id;
			}
			sdSubject(id);
			system("pause");
			system("cls");
			tutorMenu(id2);
		}

		//BACK
		else
		{
			system("cls");
			tutorMenu(id2);
		}
	}

	//VIEW PROFILE
	else if (choice == 3)
	{

		cout << "==PROFILE==" << endl;
		sdTutor(id2);
		system("pause");
		system("cls");
		tutorMenu(id2);


	}

	//LOGOUT
	else
	{
		id2 = NULL;
		userID = NULL;
		system("cls");
		loginPage();

	}

}








