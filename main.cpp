// Array System
// TP061236 TP060288 TP058396

#include <iostream>
#include "menu.h"
#include "classes.h"

using namespace std;

// MAIN FUNCTION
int main()
{

	insertCentre(createCentre(201, "Kuala Lumpur Centre", "Kuala Lumpur", 1));
	insertCentre(createCentre(202, "Sabah Centre", "Sabah", 1));
	insertCentre(createCentre(203, "Penang Centre", "Penang", 1));
	insertCentre(createCentre(206, "Puchong Centre", "Puchong", 0));
	insertCentre(createCentre(205, "Sri Petaling Centre", "Sri Petaling", 0));
	insertCentre(createCentre(204, "Bukit Jalil Centre", "Bukit Jalil", 0));

	insertAdmin(createAdmin(1001, "admin1", 201));
	insertAdmin(createAdmin(1003, "admin2", 202));
	insertAdmin(createAdmin(1002, "admin3", 203));

	insertSubject(createSubject(101, "English", 50));
	insertSubject(createSubject(103, "Math", 70));
	insertSubject(createSubject(102, "Science", 65));


	insertTutor(createTutor(2005, "2005", "Axel", "Pribadi", "Bukit Jalil", "01122337", "01/01/2022", 201, 101));
	giveRating(2005, 5);
	giveRating(2005, 5);
	giveRating(2005, 4);

	insertTutor(createTutor(2003, "2003", "Edmund", "Farrel", "Bukit Jalil", "01133557", "01/01/2022", 201, 101));

	insertTutor(createTutor(2002, "2002", "Gaby", "Harris", "Bukit Bintang", "02468642", "01/01/2022", 201, 101));
	giveRating(2002, 2);
	giveRating(2002, 3);
	giveRating(2002, 3);

	insertTutor(createTutor(2001, "2001", "Kevin", "AP", "Bukit Star", "01222337", "01/10/2022", 201, 101));

	insertTutor(createTutor(2004, "2004", "Budi", "Idub", "Bukit Bukit", "01622337", "10/01/2022", 201, 102));
	giveRating(2004, 4);
	giveRating(2004, 3);
	giveRating(2004, 4);

	insertTutor(createTutor(2006, "2006", "Big", "Small", "Bukit Moon", "097773332", "11/10/2021", 201, 102));

	insertTutor(createTutor(2007, "2007", "Cat", "Dog", "Bukit Moon", "0675757574", "15/03/2022", 201, 102));
	giveRating(2007, 5);
	giveRating(2007, 3);
	giveRating(2007, 4);

	insertTutor(createTutor(2008, "2008", "Water", "Fire", "Bukit Moon", "03983832", "12/12/2021", 201, 103));

	insertTutor(createTutor(2009, "2009", "Earth", "Mars", "Bukit Moon", "0919191919", "31/12/2021", 201, 103));
	giveRating(2009, 5);
	giveRating(2009, 5);
	giveRating(2009, 3);

	insertTutor(createTutor(2010, "2010", "Happy", "Glad", "Bukit Moon", "038383833", "28/02/2022", 201, 103));

	int cont = 1;

	while (cont == 1)
	{
		system("cls");
		// Main Menu
		mainMenu();

		// Continue?
		do
		{
			cout << "Do you want to continue System? (1 for Yes): ";
			cin >> cont;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (cin.fail());
	}

	cout << "A " << ::sizeA << " " <<" T " << ::sizeT << endl;
	cout << "C " << ::sizeC << " " <<" S " << ::sizeS << endl;

	return 0;
}
