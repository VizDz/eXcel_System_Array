#pragma once
#pragma once

#include <iostream>
#include <string.h>
#include "menu.h"
#include <string>
#include <conio.h>
#include <time.h>

using namespace std;


//STRUCTURE
struct Tutor
{
	int tutorID;
	string password;
	string fname;
	string lname;
	string address;
	string phoneNumber;
	string joinedDate;
	string terminatedDate;
	double totRating;
	double numberRated;
	double rating;
	int centreID;
	int subjectID;
};

struct Admin
{
	int adminID;
	string password;
	int centreID;
};

struct Subject
{
	int subjectID;
	string subjectName;
	double hourlyPayRate;
};

struct Centre
{
	int centreID;
	string centreName;
	string location;
	int fill;
};




//CREATE ITEM CONSTRUCTOR
Tutor createTutor(int tutorID, string password, string fname, string lname, string address, string phoneNumber, string joinedDate, int centreID, int subjectID)
{
	Tutor tutor;
	tutor.tutorID = tutorID;
	tutor.password = password;
	tutor.fname = fname;
	tutor.lname = lname;
	tutor.address = address;
	tutor.phoneNumber = phoneNumber;
	tutor.joinedDate = joinedDate;
	tutor.terminatedDate = "";
	tutor.totRating = 0;
	tutor.numberRated = 0;
	tutor.rating = 0;
	tutor.centreID = centreID;
	tutor.subjectID = subjectID;
	return tutor;
}

Admin createAdmin(int adminID, string password, int centreID)
{
	Admin admin;
	admin.adminID = adminID;
	admin.password = password;
	admin.centreID = centreID;
	return admin;
}

Subject createSubject(int subjectID, string subjectName, double hourlyPayRate)
{
	Subject subject;
	subject.subjectID = subjectID;
	subject.subjectName = subjectName;
	subject.hourlyPayRate = hourlyPayRate;
	return subject;
}

Centre createCentre(int centreID, string centreName, string location, int fill)
{
	Centre centre;
	centre.centreID = centreID;
	centre.centreName = centreName;
	centre.location = location;
	centre.fill = fill;
	return centre;
}


int calculateDate(string date1, string date2);

//ARRAY & VARIABLE
int sizeT = 0;
int sizeA = 0;
int sizeC = 0;
int sizeS = 0;
Tutor* tutorArray = new Tutor[sizeT + 1];
Admin* adminArray = new Admin[sizeA + 1];
Centre* centreArray = new Centre[sizeC + 1];
Subject* subjectArray = new Subject[sizeA + 1];



//QUICK SORT
void quickSortTutorID(Tutor* tutorArray, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = tutorArray[(left + right) / 2].tutorID;

	while (i <= j)
	{
		while (tutorArray[i].tutorID < pivot)
		{
			i++;
		}

		while (tutorArray[j].tutorID > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Tutor temp = tutorArray[i];
			tutorArray[i] = tutorArray[j];
			tutorArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortTutorID(tutorArray, left, j);
	}

	if (i < right)
	{
		quickSortTutorID(tutorArray, i, right);
	}
}

void quickSortAdminID(Admin* adminArray, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = adminArray[(left + right) / 2].adminID;

	while (i <= j)
	{
		while (adminArray[i].adminID < pivot)
		{
			i++;
		}

		while (adminArray[j].adminID > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Admin temp = adminArray[i];
			adminArray[i] = adminArray[j];
			adminArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortAdminID(adminArray, left, j);
	}

	if (i < right)
	{
		quickSortAdminID(adminArray, i, right);
	}
}

void quickSortSubjectID(Subject* subjectArray, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = subjectArray[(left + right) / 2].subjectID;

	while (i <= j)
	{
		while (subjectArray[i].subjectID < pivot)
		{
			i++;
		}

		while (subjectArray[j].subjectID > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Subject temp = subjectArray[i];
			subjectArray[i] = subjectArray[j];
			subjectArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortSubjectID(subjectArray, left, j);
	}

	if (i < right)
	{
		quickSortSubjectID(subjectArray, i, right);
	}
}

void quickSortCentreID(Centre* centreArray, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = centreArray[(left + right) / 2].centreID;

	while (i <= j)
	{
		while (centreArray[i].centreID < pivot)
		{
			i++;
		}

		while (centreArray[j].centreID > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Centre temp = centreArray[i];
			centreArray[i] = centreArray[j];
			centreArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortCentreID(centreArray, left, j);
	}

	if (i < right)
	{
		quickSortCentreID(centreArray, i, right);
	}
}

void quickSortTutorRating(Tutor* tutorArray, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = tutorArray[(left + right) / 2].rating;

	while (i <= j)
	{
		while (tutorArray[i].rating < pivot)
		{
			i++;
		}

		while (tutorArray[j].rating > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Tutor temp = tutorArray[i];
			tutorArray[i] = tutorArray[j];
			tutorArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortTutorRating(tutorArray, left, j);
	}

	if (i < right)
	{
		quickSortTutorRating(tutorArray, i, right);
	}
}

void quickSortSubjectHPR(Subject* subjectArray, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = subjectArray[(left + right) / 2].hourlyPayRate;

	while (i <= j)
	{
		while (subjectArray[i].hourlyPayRate < pivot)
		{
			i++;
		}

		while (subjectArray[j].hourlyPayRate > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Subject temp = subjectArray[i];
			subjectArray[i] = subjectArray[j];
			subjectArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortSubjectHPR(subjectArray, left, j);
	}

	if (i < right)
	{
		quickSortSubjectHPR(subjectArray, i, right);
	}
}

void quickSortSubjectName(Subject* subjectArray, int left, int right)
{
	int i = left;
	int j = right;
	string pivot = subjectArray[(left + right) / 2].subjectName;

	while (i <= j)
	{
		while (subjectArray[i].subjectName < pivot)
		{
			i++;
		}

		while (subjectArray[j].subjectName > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Subject temp = subjectArray[i];
			subjectArray[i] = subjectArray[j];
			subjectArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSortSubjectName(subjectArray, left, j);
	}

	if (i < right)
	{
		quickSortSubjectName(subjectArray, i, right);
	}
}



//INSERT
void insertAdmin(Admin admin)
{
	Admin* temp = new Admin[sizeA + 1];
	for (int i = 0; i < sizeA
		; i++)
	{
		temp[i] = adminArray[i];
	}
	temp[sizeA] = admin;
	delete[] adminArray;
	adminArray = temp;
	sizeA++;
	quickSortAdminID(adminArray, 0, sizeA - 1);
}

void insertCentre(Centre centre)
{
	Centre* temp = new Centre[sizeC + 1];
	for (int i = 0; i < sizeC; i++)
	{
		temp[i] = centreArray[i];
	}
	temp[sizeC] = centre;
	delete[] centreArray;
	centreArray = temp;
	sizeC++;
	quickSortCentreID(centreArray, 0, sizeC - 1);
}

void insertTutor(Tutor tutor)
{
	Tutor* temp = new Tutor[sizeT + 1];
	for (int i = 0; i < sizeT; i++)
	{
		temp[i] = tutorArray[i];
	}
	temp[sizeT] = tutor;
	delete[] tutorArray;
	tutorArray = temp;
	sizeT++;
	quickSortTutorID(tutorArray, 0, sizeT - 1);
}

void insertSubject(Subject subject)
{
	Subject* temp = new Subject[sizeS + 1];
	for (int i = 0; i < sizeS; i++)
	{
		temp[i] = subjectArray[i];
	}
	temp[sizeS] = subject;
	delete[] subjectArray;
	subjectArray = temp;
	sizeS++;
	quickSortSubjectID(subjectArray, 0, sizeS - 1);
}




//BINARY SEARCH
int bSearchEmptyCentreID(int centreID)
{
	quickSortCentreID(centreArray, 0, sizeC - 1);

	int low = 0;
	int high = sizeC - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (centreArray[mid].centreID == centreID && centreArray[mid].fill == 0)
		{
			return mid;
		}
		else if (centreArray[mid].centreID < centreID)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int bSearchCentreID(int centreID)
{
	quickSortCentreID(centreArray, 0, sizeC - 1);

	int low = 0;
	int high = sizeC - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (centreArray[mid].centreID == centreID)
		{
			return mid;
		}
		else if (centreArray[mid].centreID < centreID)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int bSearchAdminID(int adminID)
{
	quickSortAdminID(adminArray, 0, sizeA - 1);

	int low = 0;
	int high = sizeA - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (adminArray[mid].adminID == adminID)
		{
			return mid;
		}
		else if (adminArray[mid].adminID < adminID)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int bSearchAdminLog(string username, string password)
{
	quickSortAdminID(adminArray, 0, sizeA - 1);

	int low = 0;
	int high = sizeA - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (username == to_string(adminArray[mid].adminID) && password == adminArray[mid].password)
		{
			return mid;
		}
		else if (username < to_string(adminArray[mid].adminID))
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int bSearchSubjectID(int subjectID)
{
	quickSortSubjectID(subjectArray, 0, sizeS - 1);

	int low = 0;
	int high = sizeS - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (subjectArray[mid].subjectID == subjectID)
		{
			return mid;
		}
		else if (subjectArray[mid].subjectID < subjectID)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int bSearchSubjectName(string subjectName)
{
	quickSortSubjectName(subjectArray, 0, sizeS - 1);

	int low = 0;
	int high = sizeS - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (subjectArray[mid].subjectName == subjectName)
		{
			return mid;
		}
		else if (subjectArray[mid].subjectName < subjectName)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int bSearchTutorID(int tutorID)
{
	quickSortTutorID(tutorArray, 0, sizeT - 1);

	int low = 0;
	int high = sizeT - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (tutorArray[mid].tutorID == tutorID)
		{
			return mid;
		}
		else if (tutorArray[mid].tutorID > tutorID)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int bSearchTutorLog(string username, string password)
{
	quickSortTutorID(tutorArray, 0, sizeT - 1);

	int low = 0;
	int high = sizeT - 1;
	int mid;


	while (low <= high)
	{
		mid = (low + high) / 2;
		if (username == to_string(tutorArray[mid].tutorID) && password == tutorArray[mid].password)
		{
			return mid;
		}
		else if (username < to_string(tutorArray[mid].tutorID))
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int bSearchTutorCen(int tutorID, int centreID)
{
	quickSortTutorID(tutorArray, 0, sizeT - 1);

	int low = 0;
	int high = sizeT - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (tutorArray[mid].tutorID == tutorID && tutorArray[mid].centreID == centreID)
		{
			return mid;
		}
		else if (tutorArray[mid].tutorID > tutorID)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}




//DISPLAY
void displayT()
{
	for (int i = 0; i < sizeT; i++)
	{
		cout << "\nNumber " << i + 1 << endl;
		cout << "Tutor ID\t: " << tutorArray[i].tutorID << endl;
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
		cout << endl;
	}
}

void displayC()
{

	for (int i = 0; i < sizeC; i++)
	{
		cout << "\nNumber " << i + 1 << endl;
		cout << "Centre ID\t: " << centreArray[i].centreID << endl;
		cout << "Centre Name\t: " << centreArray[i].centreName << endl;
		cout << "Location\t: " << centreArray[i].location << endl;
	}
}

void displayA()
{

	cout << "ARRAY SIZE  : " << sizeA << endl;
	for (int i = 0; i < sizeA; i++)
	{
		cout << "\nNumber " << i + 1 << endl;
		cout << "Admin ID\t: " << adminArray[i].adminID << endl;
		cout << "Password\t: " << adminArray[i].password << endl;
		cout << "Centre ID\t: " << adminArray[i].centreID << endl;
	}
}

void displayS()
{
	for (int i = 0; i < sizeS; i++)
	{
		cout << "\nNumber " << i + 1 << endl;
		cout << "Subject ID\t: " << subjectArray[i].subjectID << endl;
		cout << "Subject Name\t: " << subjectArray[i].subjectName << endl;
		cout << "Hourly Pay Rate\t: " << subjectArray[i].hourlyPayRate << endl;
	}
}

void displayST(int cenID)
{
	for (int i = 0; i < sizeT; i++)
	{
		if (tutorArray[i].centreID == cenID)
		{
			cout << "Tutor ID\t: " << tutorArray[i].tutorID << endl;
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
			cout << endl;
		}

	}
} //DISPLAY FOR TUTOR IN SPECIFIC CENTRE



//SEARCH & DISPLAY
void sdAdmin(int id) {
	for (int i = 0; i < sizeA; i++) {
		if (adminArray[i].adminID == id) {
			cout << "\nAdmin ID\t: " << adminArray[i].adminID << endl;
			cout << "Password\t: " << adminArray[i].password << endl;
			cout << "Centre ID\t: " << adminArray[i].centreID << endl;
		}

	}

}

void sdCentre(int id) {
	for (int i = 0; i < sizeC; i++) {
		if (centreArray[i].centreID == id) {
			cout << "\nCentre ID\t: " << centreArray[i].centreID << endl;
			cout << "Centre Name\t: " << centreArray[i].centreName << endl;
			cout << "Location\t: " << centreArray[i].location << endl;
			if (centreArray[i].fill == 0) {
				cout << "Centre Status \t: Empty (No Admin Yet)" << endl;
			}
			else {
				cout << "Centre Status \t: Occupied (Admin Exist)" << endl;
			}
		}

	}

}

void sdSubject(int id)
{
	for (int i = 0; i < sizeS; i++) {
		if (subjectArray[i].subjectID == id) {
			cout << "\nSubject ID\t: " << subjectArray[i].subjectID << endl;
			cout << "Subject Name\t: " << subjectArray[i].subjectName << endl;
			cout << "Hourly Pay Rate\t: " << subjectArray[i].hourlyPayRate << endl;
		}

	}

}

void sdTutor(int id)
{
	for (int i = 0; i < sizeT; i++) {
		if (tutorArray[i].tutorID == id) {
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

}




//GENEREATE AUTOMATIC ID
int generateAdminID()
{
	quickSortAdminID(adminArray, 0, sizeA - 1);

	int id = 1001;
	if (sizeA != 0) {
		int id1 = 1001;
		int id2;
		int id3 = 0;
		id = sizeA + id;
		for (int i = 0; i < sizeA; i++)
		{
			for (int j = 0; j < sizeA; j++)
			{
				id2 = adminArray[j].adminID;
				if (id2 == id1)
				{
					id3 = 0;
					break;
				}
				else
				{
					id3 = 1;
				}
			}
			if (id3 == 1)
			{
				id = id1;
				return id;
			}
			id1++;
		}
	}
	return id;
}

int generateCentreID()
{
	quickSortCentreID(centreArray, 0, sizeC - 1);

	int id = 201;
	if (sizeC != 0) {
		int id1 = 201;
		int id2;
		int id3 = 0;
		id = sizeC + id;
		for (int i = 0; i < sizeC; i++)
		{
			for (int j = 0; j < sizeC; j++)
			{
				id2 = centreArray[j].centreID;
				if (id2 == id1)
				{
					id3 = 0;
					break;
				}
				else
				{
					id3 = 1;
				}
			}
			if (id3 == 1)
			{
				id = id1;
				return id;
			}
			id1++;
		}
	}
	return id;
}

int generateSubjectID()
{
	quickSortSubjectID(subjectArray, 0, sizeS - 1);

	int id = 101;
	if (sizeS != 0) {
		int id1 = 101;
		int id2;
		int id3 = 0;
		id = sizeS + id;
		for (int i = 0; i < sizeS; i++)
		{
			for (int j = 0; j < sizeS; j++)
			{
				id2 = subjectArray[j].subjectID;
				if (id2 == id1)
				{
					id3 = 0;
					break;
				}
				else
				{
					id3 = 1;
				}
			}
			if (id3 == 1)
			{
				id = id1;
				return id;
			}
			id1++;
		}
	}
	return id;
}

int generateTutorID()
{
	quickSortTutorID(tutorArray, 0, sizeT - 1);

	int id = 2001;
	if (sizeT != 0) {
		int id1 = 2001;
		int id2;
		int id3 = 0;
		id = sizeT + id;
		for (int i = 0; i < sizeT; i++)
		{
			for (int j = 0; j < sizeT; j++)
			{
				id2 = tutorArray[j].tutorID;
				if (id2 == id1)
				{
					id3 = 0;
					break;
				}
				else
				{
					id3 = 1;
				}
			}
			if (id3 == 1)
			{
				id = id1;
				return id;
			}
			id1++;
		}
	}
	return id;
}




//EDIT RECORDS
void editA(int id) {
	int choice, confirm;
	int index;
	string nowPass, checkPass, edit;

	for (int i = 0; i < sizeA; i++) {
		if (int(adminArray[i].adminID) == id)
		{
			index = i;
		}
	}
	cout << "\nCurrent Information : " << endl;
	sdAdmin(id);
	cout << "\nAVAILABLE OPTIONS : " << endl;
	cout << "1. Password" << endl << "2. Centre ID" << endl << "3. Back" << endl;

	do
	{
	cout << "Choice: ";
	cin >> choice;

	// clear input
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail() || choice < 1 || choice > 3);

	//MODIFY PASSWORD
	if (choice == 1)
	{
		cout << "Enter Current Password: ";
		getline(cin, nowPass);

		if (nowPass != adminArray[index].password)
		{
			cout << "\nIncorrect Password";
			return;
		}

		cout << "\nEnter New Password: ";
		getline(cin, edit);
		cout << "Re-Enter New Password: ";
		getline(cin, checkPass);

		if (edit != checkPass)
		{
			cout << "\nPasswords do not Match" << endl;
			return;
		}

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;

			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			adminArray[index].password = edit;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}

		cout << " =Current Admin Info= " << endl;
		cout << adminArray[index].adminID << " | " << adminArray[index].password << " | " << adminArray[index].centreID << endl;
		return;
	}

	//MODIFY CENTRE ID
	else if (choice == 2)
	{
		int c1 = 0, cID;
		for (int i = 0; i < sizeC; i++) {
			if (centreArray[i].fill == 0)
			{
				c1++;
			}
		}
		if (c1 != 0)
		{

			cout << "\nAvailable Centre ID : " << endl;
			for (int i = 0; i < sizeC; i++)
			{
				if (centreArray[i].fill == 0) {
					cout << centreArray[i].centreID << endl;
				}
			}

			cout << "Enter New Centre ID: ";
			cin >> cID;
			while (cin.fail() || bSearchEmptyCentreID(cID) == -1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Centre Not Found!" << endl;
				cout << "\nEnter Centre ID: ";
				cin >> cID;
			}

			do
			{
				cout << "\nConfirm (Enter 1): ";
				cin >> confirm;

				// clear input
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (cin.fail());

			if (confirm == 1)
			{
				for (int i = 0; i < sizeC; i++) {
					if (centreArray[i].centreID == cID)
					{
						centreArray[i].fill = 1; //Change to 1 to indicate the inputted centre become occupied
					}

					if (centreArray[i].centreID == adminArray[index].centreID)
					{
						centreArray[i].fill = 0; //Change to 0 to indicate the centre become empty
						
					}
				}
				adminArray[index].centreID = cID;
				cout << "\nSuccessfull Change Centre :)" << endl;

			}
			else
			{
				cout << "\nNo changes were made" << endl;
			}

		}
		else {
			cout << "NO CENTRE AVAILABLE... /n Therefore cannot add new Admin !!!" << endl;
			return;

		}
	}
	else
	{
		system("cls");
		return;
	}
}

void editC(int id)
{
	int choice, confirm;
	int index;
	string edit;
	for (int i = 0; i < sizeC; i++) {
		if (int(centreArray[i].centreID) == id)
		{
			index = i;
		}
	}
	cout << "\nCurrent Information : " << endl;
	sdCentre(id);
	cout << "\nAVAILABLE OPTIONS : " << endl;
	cout << "1. Centre Name" << endl << "2. Location" << endl << "3. Back" << endl;

	do
	{
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail() || choice < 1 || choice > 3);

	if (choice == 1)
	{
		cout << "Enter New Centre Name : ";
		getline(cin, edit);

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			centreArray[index].centreName = edit;
			cout << "\nSuccessfull Change Centre Name:)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}

	else if (choice == 2)
	{
		cout << "Enter New Location : ";
		getline(cin, edit);

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			centreArray[index].location = edit;
			cout << "\nSuccessfull Change Centre Location:)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}
	else
	{
		system("cls");
		return;
	}

}

void editS(int id)
{
	int choice, confirm;
	double rate;
	int index;
	string edit;
	for (int i = 0; i < sizeS; i++) {
		if (int(subjectArray[i].subjectID) == id)
		{
			index = i;
		}
	}
	cout << "\nCurrent Information : " << endl;
	sdSubject(id);
	cout << "\nAVAILABLE OPTIONS : " << endl;
	cout << "1. Subject Name" << endl << "2. Hourly Pay Rate" << endl << "3. Back" << endl;

	do
	{
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail() || choice < 1 || choice > 3);

	if (choice == 1)
	{
		cout << "Enter Subject Name: ";
		getline(cin, edit);

		while (cin.fail() || bSearchSubjectName(edit) != -1) {
			/*cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
			cout << "Subject Name Exist!" << endl;
			cout << "\nEnter New Subject Name: ";
			getline(cin, edit);
		}
		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			subjectArray[index].subjectName = edit;
			cout << "\nSuccessful Change Subject Name:)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}

	else if (choice == 2)
	{
		cout << "Enter New Hourly Pay Rate (40-80) : ";
		cin >> rate;

		while (cin.fail() || rate < 40 || rate > 80) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nWrong Input!" << endl;
			cout << "Enter New Hourly Pay Rate (40-80): ";
			cin >> rate;
		}

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			subjectArray[index].hourlyPayRate = rate;
			cout << "\nSuccessfull Change Subject Hourly Pay Rate :)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}
	else
	{
		system("cls");
		return;
	}

}

void editT(int id)
{
	int index, choice, confirm;
	string edit;

	index = bSearchTutorID(id);
	cout << "\nCurrent Information : " << endl;
	sdTutor(id);
	cout << "\nAVAILABLE OPTIONS : " << endl;
	cout << "1. Phone Number" << endl << "2. Address" << endl << "3. Terminate " << endl << "4. Back" << endl;
	
	do
	{
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail() || choice < 1 || choice > 4);

	if (choice == 1)
	{
		cout << "Enter Phone Number: ";
		getline(cin, edit);

		tutorArray[index].phoneNumber = edit;

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			tutorArray[index].phoneNumber = edit;
			cout << "\nSuccessful Change Phone Number:)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "Enter Address: ";
		getline(cin, edit);

		tutorArray[index].address = edit;

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			tutorArray[index].address = edit;
			cout << "\nSuccessful Change Address:)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}

	else if (choice == 3)
	{
		cout << "Enter Terminated Date (dd/mm/yyyy): ";
		getline(cin, edit);

		tutorArray[index].terminatedDate = edit;

		do
		{
			cout << "\nConfirm (Enter 1): ";
			cin >> confirm;
			// clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());

		if (confirm == 1)
		{
			tutorArray[index].terminatedDate = edit;
			cout << "\nSuccessful Put Termination Date :)" << endl;
		}
		else
		{
			cout << "\nNo changes were made" << endl;
		}
	}

	else
	{
		system("cls");
		return;
	}
}


//DELETE RECORDS
void deleteA(int id)
{
	int confirm;
	int index;

	for (int i = 0; i < sizeA; i++)
	{
		if (int(adminArray[i].adminID) == id)
		{
			index = i;
		}
	}
	cout << "\nAdmin ID : " << adminArray[index].adminID << endl;

	do
	{
		cout << "\nConfirm to Delete (Enter 1): ";
		cin >> confirm;

		// clear input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail());

	if (confirm == 1)
	{
		Admin* temp = new Admin[sizeA - 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = adminArray[i];
		}
		for (int i = index + 1; i < sizeA; i++)
		{
			temp[i - 1] = adminArray[i];
		}
		delete[] adminArray;
		adminArray = temp;
		sizeA--;

		cout << "Admin Data Deleted :(" << endl;
		quickSortAdminID(adminArray, 0, sizeA - 1);
	}
	else
	{
		cout << "\nNo changes were made" << endl;
	}
}

void deleteC(int id)
{
	int confirm;
	int index;

	for (int i = 0; i < sizeC; i++)
	{
		if (int(centreArray[i].centreID) == id)
		{
			index = i;
		}
	}
	cout << "\nCentre ID : " << centreArray[index].centreID << endl;

	do
	{
		cout << "\nConfirm to Delete (Enter 1): ";
		cin >> confirm;

		// clear input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail());

	if (confirm == 1)
	{
		Centre* temp = new Centre[sizeC - 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = centreArray[i];
		}
		for (int i = index + 1; i < sizeC; i++)
		{
			temp[i - 1] = centreArray[i];
		}
		delete[] centreArray;
		centreArray = temp;
		sizeC--;

		cout << "Centre Data Deleted :(" << endl;
		quickSortCentreID(centreArray, 0, sizeC - 1);
	}
	else
	{
		cout << "\nNo changes were made" << endl;
	}
}

void deleteS(int id)
{
	int confirm;
	int index;

	for (int i = 0; i < sizeS; i++)
	{
		if (int(subjectArray[i].subjectID) == id)
		{
			index = i;
		}
	}
	cout << "\nSubject ID : " << subjectArray[index].subjectID << endl;

	do
	{
		cout << "\nConfirm to Delete (Enter 1): ";
		cin >> confirm;

		// clear input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail());

	if (confirm == 1)
	{
		Subject* temp = new Subject[sizeS - 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = subjectArray[i];
		}
		for (int i = index + 1; i < sizeS; i++)
		{
			temp[i - 1] = subjectArray[i];
		}
		delete[] subjectArray;
		subjectArray = temp;
		sizeS--;

		cout << "Subject Data Deleted :(" << endl;
		quickSortSubjectID(subjectArray, 0, sizeS - 1);
	}
	else
	{
		cout << "\nNo changes were made" << endl;
	}
}

//DELETE IF ALREADY MORE THAN 6 MONTHS TERMINATED
void deleteT(int id)
{
	int index, confirm;
	string today;

	index = bSearchTutorID(id);

	// check if terminated date is more than 6 months

	if (tutorArray[index].terminatedDate != "")
	{
		cout << "Enter Today's Date (dd/mm/yyyy): ";
		cin >> today;

		int totalDays = calculateDate(tutorArray[index].terminatedDate, today);

		// 6+ MONTHS = 180+ DAYS (1 month = 30 days on average)
		if (totalDays >= 180)
		{
			do
			{
				cout << "\nConfirm to Delete (Enter 1): ";
				cin >> confirm;

				// clear input
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (cin.fail());

			if (confirm == 1)
			{
				Tutor* temp = new Tutor[sizeT - 1];
				for (int i = 0; i < index; i++)
				{
					temp[i] = tutorArray[i];
				}
				for (int i = index + 1; i < sizeT; i++)
				{
					temp[i - 1] = tutorArray[i];
				}
				delete[] tutorArray;
				tutorArray = temp;
				sizeT--;

				cout << "Tutor Data Deleted :(" << endl;
				quickSortTutorID(tutorArray, 0, sizeT - 1);
			}
			// CANCEL DELETION
			else
			{
				cout << "\nNo changes were made" << endl;
			}
		}
		else
		{
			cout << "Not over 6 months since termination. No Deletion taking place" << endl;
		}		
	}
	// NOT TERMINATED
	else
	{
		cout << "Tutor is still teaching in the centre" << endl;
	}
	
}




//CHECKER TO MAX 4 TUTOR WITH SAME SUBJECT IN EVERT CENTRE
int checkerTut(int cID, int sID)
{
	int cnt = 0;
	for (int i = 0; i < sizeT; i++)
	{
		if (tutorArray[i].centreID == cID && tutorArray[i].subjectID == sID)
		{
			cnt++;
		}
	}

	return cnt;
}




//ADD RATING
void addRating(int id)
{
	double cnt = 0;
	int index;
	double totRate = 0, rate = 0;

	for (int i = 0; i < sizeT; i++) {
		if (int(tutorArray[i].tutorID) == id)
		{
			index = i;
		}
	}

	cout << "Enter Number of Rating : ";
	cin >> cnt;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong Input" << endl;
		cout << "\nEnter Number of Rating : ";
		cin >> cnt;
	}
	for (int i = 0; i < cnt; i++)
	{
		cout << "Rating Number " << i + 1 << " : ";
		cin >> rate;
		while (cin.fail() || rate > 5 || rate < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wrong Input" << endl;
			cout << "Rating Number " << i + 1 << " : ";
			cin >> rate;
		}
		totRate = totRate + rate;
	}

	tutorArray[index].numberRated = tutorArray[index].numberRated + cnt;
	tutorArray[index].totRating = tutorArray[index].totRating + totRate;
	tutorArray[index].rating = roundf((tutorArray[index].totRating / tutorArray[index].numberRated) *100) / 100;
	cout << "\nSuccess Add Rating to Selected Tutor :)" << endl;

}

void giveRating(int id, double rt)
{
	int index;
	index = bSearchTutorID(id);
	tutorArray[index].numberRated = tutorArray[index].numberRated + 1;
	tutorArray[index].totRating = tutorArray[index].totRating + rt;
	tutorArray[index].rating = roundf((tutorArray[index].totRating / tutorArray[index].numberRated) * 100) / 100;

}


//GENERATE REPORT
void genReport()
{
	int cnt = 0;
	cout << "\n=== Summary ===" << endl;
	cout << "Number of Admin : " << sizeA << endl;
	cout << "Number of Centre : " << sizeC << endl;
	cout << "Number of Tutor : " << sizeT << endl;
	cout << "Number of Subject : " << sizeS << endl;

	cout << "\n === Summary Tutor in Each Centre === " << endl;
	for (int i = 0; i < sizeC; i++)
	{
		for (int j = 0; j < sizeT; j++)
		{
			if (centreArray[i].centreID == tutorArray[j].centreID)
			{
				cnt++;
			}
		}
		cout << "Number of Tutor in " << centreArray[i].centreName << " : " << cnt << endl;
		cnt = 0;
	}

}


void pagination(int size)
{
	int startPosition = 0, currentPosition = 0; //Starting index or position inside the list
	int endPosition = 0, noOfPage; //Ending index or position/page, and number of Page
	int noPerPage = 0, currentPage = 1;
	int left, move = 9, print;

	cout << "Total number of tutor: " << size << endl;
	do {
		cout << "Enter how many tutor records per page: ";
		cin >> noPerPage;
		cin.clear(); //remove the input operation
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail() || noPerPage < 1 || noPerPage > size);

	endPosition = noPerPage;
	noOfPage = size / noPerPage;
	left = size % noPerPage; //Checking any elements left
	if (left > 0) {
		noOfPage++;
	}

	do {
		system("cls");
		if (move == 0) {
			if (endPosition < size) {
				currentPage += 1;
				startPosition += noPerPage;
				endPosition += noPerPage;
				currentPosition += noPerPage;

			}
			else {
				cout << "You are already at the last Page!" << endl;
			}
		}
		else if (move == 1) {
			if (startPosition >= noPerPage) {
				currentPage -= 1;
				startPosition -= noPerPage;
				endPosition -= noPerPage;
				currentPosition -= noPerPage;

			}
			else {
				cout << "You are already at the first Page!" << endl;
			}
		}
		//Tutor* temp = currentElement;
		int tempPosition = currentPosition;
		for (print = startPosition; print < endPosition; print++) {
			if (tempPosition < size) {
				cout << tutorArray[print].tutorID << " - " << tutorArray[print].fname << " - " << tutorArray[print].lname << endl;
				tempPosition++;
				//temp = temp->nextAddress;
			}
			else {
				cout << endl;
			}

		}
		cout << "\t\tPage " << currentPage << " of " << noOfPage << endl << endl;
		cout << "Next Page [0] / Previous Page [1] / Exit [Any Other Number] : ";
		cin >> move;
		cin.clear(); //remove the input operation
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (move == 0 || move == 1);
}



// FIND DAYS BETWEEN 2 DATES
int calculateDate(string date1, string date2)
{
	// date1 & date2 are in dd/mm/yyyy format
	// assuming 1 month = 30 days, 6 months+ = 180+ days 
	int total;
	int d1, m1, y1, d2, m2, y2;
	time_t a, b;

	d1 = stoi(date1.substr(0, 2));
	m1 = stoi(date1.substr(3, 2));
	y1 = stoi(date1.substr(6, 4));

	d2 = stoi(date2.substr(0, 2));
	m2 = stoi(date2.substr(3, 2));
	y2 = stoi(date2.substr(6, 4));

	struct tm t1 = { 0, 0, 0, d1, m1 - 1, y1 - 1900 };
	struct tm t2 = { 0, 0, 0, d2, m2 - 1, y2 - 1900 };
	a = mktime(&t1);
	b = mktime(&t2);
	total = abs(difftime(a, b) / (60 * 60 * 24));
	return total;
}