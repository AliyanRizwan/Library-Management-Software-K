#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Book {

protected:
	int size;
	int bookid;
	char* name;
	char* dateofPurchase;
	char status;
	double price;

public:

	Book() {
		size = 25;
		bookid = 0;
		name = new char[size];
		dateofPurchase = new char[size];
		status = NULL;
		price = 0;
	}
	Book(int bookid, char* author, char* name, char* dateofPurchase, char status, double price) {
		strcpy_s(this->name, sizeof size, name);
		strcpy_s(this->dateofPurchase, sizeof size, dateofPurchase);
		this->bookid = bookid;
		this->status = status;
		this->price = price;
	}

	void setstatus() {
		cout << "\nStatus (A/O): ";
		cin >> status;
		while (status != 'A' && status != 'a' && status != 'O' && status != 'o')
		{
			cout << "Enter Correct Status (A/O): ";
			cin >> status;
		}
		if (status == 'a' || status == 'o')
		{
			status = status - 32;
		}
	}
	void setname() {
		cout << "Enter Book Name: ";
		cin >> name;
	}
	void setdateofPurchase() {
		cout << "Enter Date of Purchase (dd/mm/yy) : ";
		cin >> dateofPurchase;
	}
	void setprice() {
		cout << "Enter Book Price: ";
		cin >> price;
	}
	int getbookid() {
		return bookid;
	}
	char* getname() {
		return name;
	}
	char* getdateofPurchase() {
		return dateofPurchase;
	}
	char getstatus() {
		return status;
	}
	double getprice() {
		return price;
	}

	virtual void displaymember() = 0;
	void displayBookDetails() {

		int noofline = 0;

		ifstream fin1;
		fin1.open("library.txt");
		string linecount;
		while (getline(fin1, linecount))
		{
			if (!linecount.empty())
				noofline++;
		}
		bookid = noofline;
		bookid++;
		ofstream fout;
		fout.open("library.txt", ios::app);
		fout << endl;
		fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
		fout.close();
		cout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
		cout << "Book Added" << endl;

	}

	void updateStatus() {

		int linenumber;
		ifstream fin;
		ofstream fout;
		int check = 0;
		cout << "\nEnter Book Id Number that you want to Update: ";
		cin >> linenumber;
		fin.open("library.txt");
		fout.open("temp.txt");
		while (!fin.eof()) {
			fin >> bookid >> name >> dateofPurchase >> status >> price;

			if (bookid == linenumber) {
				if (status == 'A')
				{
					status = 'O';

				}
				else
				{
					status = 'A';
				}

			}

			fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
			check++;
		}
		fin.close();
		fout.close();
		fin.open("temp.txt");
		fout.open("library.txt");
		for (int i = 0; i < check - 1; i++)
		{
			fin >> bookid >> name >> dateofPurchase >> status >> price;
			fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
		}
		fin.close();
		fout.close();
		fout.open("temp.txt");
		fout << "Content Not Stored" << endl;
		fout.close();
	}

	virtual void displaylibraryfile() {

		cout << "\n";
		ifstream fin;
		fin.open("library.txt");

		cout << "\nID\tBook Name\tDate\tAvailability\tPrice" << endl;
		cout << "----------------------------------------------------" << endl;
		while (fin >> bookid)
		{

			fin >> name;
			fin >> dateofPurchase;
			fin >> status;
			fin >> price;
			cout << "" << bookid << "\t" << name << "\t\t" << dateofPurchase << "\t(" << status << ")\t\t" << price << endl;

		}
		cout << "----------------------------------------------------" << endl;
	}

	~Book(){
		delete[]name;
		delete[]dateofPurchase;

	}
};


class MemberRecord
{
protected:
	int size;
	int memberid;
	int noBookIssued;
	int maxBookLimit;
	char* mname;
public:
	MemberRecord() {
		size = 25;
		memberid = 0;
		noBookIssued = 0;
		maxBookLimit = 12;
		mname = new char[size];
	}

	MemberRecord(int memberid, int noBookIssued, int maxBookLimit, char* name) {
		this->memberid = memberid;
		this->noBookIssued = noBookIssued;
		this->maxBookLimit = maxBookLimit;
		strcpy_s(this->mname, size, name);
	}


	void setNoBookIssued() {
		cout << "No of Book Issued: ";
		cin >> noBookIssued;
	}

	void setName() {
		cout << "Name: ";
		cin >> mname;
	}

	void setMemberid() {
		cout << "Enter Member ID: ";
		cin >> memberid;
	}
	int getMemberid() {
		return memberid;
	}

	int getNoBookIssued() {
		return noBookIssued;
	}
	int getMaxBookLimit() {
		return maxBookLimit;
	}

	char* getName() {
		return mname;
	}




	void displaySMemberDetails() {

		int nooflineofmember = 0;

		ifstream fin1;

		fin1.open("member1.txt");
		string linecount;
		while (getline(fin1, linecount))
		{
			if (!linecount.empty())
				nooflineofmember++;
		}
		memberid = nooflineofmember;
		memberid++;
		ofstream fout;
		fout.open("member1.txt", ios::app);
		fout << endl;
		fout << memberid << " " << mname << " " << noBookIssued << endl;
		fout.close();
		fin1.close();

		ifstream fin2;
		fin1.open("member1.txt");

		cout << "\nID\tName\t\tNo of Book Issued" << endl;
		cout << "----------------------------------------" << endl;
		while (fin1 >> memberid)
		{
			fin1 >> mname;
			fin1 >> noBookIssued;

			cout << "" << memberid << "\t" << mname << "\t\t" << noBookIssued << endl;
		}
		fin2.close();
		cout << "Book Issued" << endl;

	}

	void displayTMemberDetails() {

		int nooflineofmember = 0;

		ifstream fin1;

		fin1.open("member2.txt");
		string linecount;
		while (getline(fin1, linecount))
		{
			if (!linecount.empty())
				nooflineofmember++;
		}
		memberid = nooflineofmember;
		memberid++;
		ofstream fout;
		fout.open("member2.txt", ios::app);
		fout << endl;
		fout << memberid << " " << mname << " " << noBookIssued << endl;
		fout.close();
		fin1.close();

		ifstream fin2;
		fin1.open("member2.txt");

		cout << "\nID\tName\t\tNo of Book Issued" << endl;
		cout << "----------------------------------------" << endl;
		while (fin1 >> memberid)
		{
			fin1 >> mname;
			fin1 >> noBookIssued;

			cout << "" << memberid << "\t" << mname << "\t\t" << noBookIssued << endl;
		}
		fin2.close();
		cout << "Book Issued" << endl;

	}
	~MemberRecord(){
		delete[]mname;
	}

};
class Student :virtual public MemberRecord
{
public:
	~Student(){

	}
};


class Faculty :virtual public MemberRecord
{
public:
	~Faculty(){

	}
};
class Librarian : public Book, public Student, public  Faculty {
protected:

	string userNameAttempt;
	string passWordAttempt;
	string passWord;
	string userName;
	bool verifymemberr;
	bool verifyissueBook;
	string searchName;
	char searchAvailability;
	string inputcheck;
	string option;
	int counter;
	int searchID;
	int searchmemID;
	int inputcheckid;
	int inputid;
	string slection;
	ifstream fin;
	int inputid1;
	int searchid1;
	int inputcheckid1;
public:
	bool accessGranted;
	Librarian() {
		accessGranted = false;
		verifymemberr = false;
		verifyissueBook = false;
		counter = 0;
		searchid1 = 0;
		inputid1 = 0;
		inputcheckid1 = 0;
		userName = "admin";
		passWord = "pass";
		accessGranted = false;

	}

	void searchBook() {

		cin >> option;
		while (true) {
			if (option == "1" || option == "2" || option == "3") {
				break;
			}
			cout << "Wrong Input: Enter Right Option: ";
			cin >> option;
		}

		if (option == "1")
		{
			cout << "\nSearch Book by Name: ";
			cin >> searchName;
			cout << "\nID\tBook Name\tDate\tAvailability\tPrice" << endl;;
			cout << "----------------------------------------------------" << endl;
			ifstream fin;
			fin.open("library.txt");
			while (fin >> bookid)
			{

				fin >> name;
				fin >> dateofPurchase;
				fin >> status;
				fin >> price;
				if (name == searchName) {
					counter++;
					inputcheck = searchName;
					verifyissueBook = true;
					cout << "" << bookid << "\t" << name << "\t\t" << dateofPurchase << "\t(" << status << ")\t\t" << price << endl;
				}
			}
			fin.close();
			if (inputcheck == searchName) {
				cout << "----------------------------------------------------" << endl;
				cout << "No of " << counter << " Book Found " << endl;

			}
			else
			{
				cout << "----------------------------------------------------" << endl;
				cout << "No Book Found" << endl;

			}
			fin.close();
		}
		else if (option == "2")
		{

			cout << "Search Book By Availability A/O: ";
			cin >> searchAvailability;

			while (true) {
				if (searchAvailability == 'A' || searchAvailability == 'O' || searchAvailability == 'a' || searchAvailability == 'o') {
					break;
				}
				cout << "Wrong Input: Enter Right Option: ";
				cin >> searchAvailability;
			}
			if (searchAvailability == 'a' || searchAvailability == 'o')
			{
				searchAvailability = searchAvailability - 32;
			}



			cout << "\nID\tBook Name\tDate\tAvailability\tPrice" << endl;
			cout << "----------------------------------------------------" << endl;
			ifstream fin;
			fin.open("library.txt");
			while (fin >> bookid)
			{

				fin >> name;
				fin >> dateofPurchase;
				fin >> status;
				fin >> price;
				if (status == searchAvailability) {
					counter++;
					verifyissueBook = true;
					status = searchAvailability;
					if (searchAvailability == 'A')
					{
						cout << bookid << "\t" << name << "\t\t" << dateofPurchase << "\t(" << status << ")\t\t" << price << endl;

					}
					else
					{
						cout << bookid << "\t" << name << "\t\t" << dateofPurchase << "\t(" << status << ")\t\t" << price << endl;

					}
				}
			}
			fin.close();
			if (status == 'A' || status == 'O') {
				cout << "----------------------------------------------------" << endl;
				cout << "No of " << counter << " Book Found " << endl;

			}
			else
			{
				cout << "----------------------------------------------------" << endl;
				cout << "No Book Found " << endl;
			}


			fin.close();
		}

		if (option == "3")
		{

			cout << "\nSearch Book By ID: ";
			cin >> searchid1;

			cout << "\nID\tBook Name\tDate\tAvailability\tPrice" << endl;
			cout << "----------------------------------------------------" << endl;

			ifstream fin;
			fin.open("library.txt");
			while (fin >> bookid)
			{

				fin >> name;
				fin >> dateofPurchase;
				fin >> status;
				fin >> price;
				if (bookid == searchid1) {
					counter++;
					inputcheckid1 = searchid1;
					verifyissueBook = true;
					cout << bookid << "\t" << name << "\t\t" << dateofPurchase << "\t(" << status << ")\t\t" << price << endl;

				}
			}
			fin.close();
			if (inputcheckid1 == searchid1) {
				cout << "----------------------------------------------------<" << endl;
				cout << "No of " << counter << " Book Found " << endl;

			}
			else
			{
				cout << "----------------------------------------------------" << endl;
				cout << "No Book Found " << endl;

			}
			fin.close();
		}
	}
	void verifyMember() {

		cout << "\nSelect (1) for Student" << endl;
		cout << "Select (2) for Faculty" << endl;
		cout << "Choice Your Option: ";
		cin >> slection;
		while (true) {
			if (slection == "1" || slection == "2") {
				break;
			}
			cout << "\nWrong Input: Enter Right Option: ";
			cin >> slection;
		}
		if (slection == "1")
		{

			fin.open("member1.txt");
		}

		else
		{
			fin.open("member2.txt");
		}

		cout << "\nSearch Member by Name or ID" << endl;
		cout << "Select option (1) for Name" << endl;
		cout << "Select option (2) for ID" << endl;
		cout << "Enter Your Option: ";


		cin >> option;
		while (true) {
			if (option == "1" || option == "2") {
				break;
			}
			cout << "\ntWrong Input: Enter Right Option: ";
			cin >> option;
		}
		int input3 = 0;
		if (option == "1")
		{
			cout << "\nSearch Member By Name: ";
			cin >> searchName;

			cout << "\n" << "ID\tMemberName\tBook Issue" << endl;
			cout << "-----------------------------------" << endl;

			while (fin >> memberid)
			{

				fin >> mname;
				fin >> noBookIssued;
				if (mname == searchName) {
					searchID = memberid;
					counter++;
					verifymemberr = true;
					inputcheck = searchName;
					cout << memberid << "\t  " << mname << "\t" << noBookIssued << endl;
				}
			}
			fin.close();
			if (inputcheck == searchName) {
				cout << "-----------------------------------" << endl;
				cout << "No of " << counter << " Member Found " << endl;
			}
			else
			{
				cout << "-----------------------------------" << endl;
				cout << "No Member Found " << endl;
			}

			fin.close();
		}

		else if (option == "2")
		{


			cout << "Search Member By ID: ";
			cin >> searchID;


			cout << "\nID\tName\t\tBook Issues" << endl;
			cout << "-----------------------------------" << endl;
			while (fin >> memberid)
			{

				fin >> mname;
				fin >> noBookIssued;
				if (memberid == searchID) {
					counter++;
					verifymemberr = true;
					inputcheckid = searchID;
					cout << memberid << "\t" << mname << "\t\t" << noBookIssued << endl;
				}
			}
			fin.close();
			if (inputcheckid == searchID) {
				cout << "-----------------------------------" << endl;
				cout << "No of " << counter << " Member Found " << endl;
			}
			else
			{
				cout << "-----------------------------------" << endl;
				cout << "No Member Found " << endl;
			}
			fin.close();
		}

	}



	void displaylibraryfile() {

		cout << "\n";
		ifstream fin;
		fin.open("library.txt");

		cout << "\nID\tBook Name\tDate\tAvailability\tPrice" << endl;
		cout << "----------------------------------------------------" << endl;
		while (fin >> bookid)
		{

			fin >> name;
			fin >> dateofPurchase;
			fin >> status;
			fin >> price;
			cout << "" << bookid << "\t" << name << "\t\t" << dateofPurchase << "\t(" << status << ")\t\t" << price << endl;

		}
		cout << "----------------------------------------------------" << endl;
	}

	void issueBook() {
		verifyMember();
		if (verifymemberr == true)
		{
			cout << "\nVerified Member" << endl;
			cout << "Which book do you need" << endl;
			displaylibraryfile();
			cout << "\nSearch Book By ID: ";

			cin >> searchid1;

			ifstream fin;
			fin.open("library.txt");
			while (fin >> bookid)
			{

				fin >> name;
				fin >> dateofPurchase;
				fin >> status;
				fin >> price;
				if (bookid == searchid1) {
					counter++;
					inputcheckid1 = searchid1;
					verifyissueBook = true;

				}
			}
			fin.close();
			if (inputcheckid1 == searchid1) {
				cout << "----------------------------------------------------" << endl;
				cout << "No of " << counter << " Book Found " << endl;

			}
			else
			{
				cout << "----------------------------------------------------" << endl;
				cout << "No Book Found " << endl;

			}
			fin.close();

			if (verifyissueBook == true)
			{
				cout << "Available" << endl;
				int linenumber;
				ifstream fin;
				ofstream fout;
				int check = 0;
				int check1 = 0;
				linenumber = searchid1;
				fin.open("library.txt");
				fout.open("temp.txt");

				while (!fin.eof()) {
					fin >> bookid >> name >> dateofPurchase >> status >> price;

					if (bookid == linenumber) {
						status = 'O';

					}
					fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
					check++;
				}

				fin.close();
				fout.close();


				fin.open("temp.txt");
				fout.open("library.txt");
				for (int i = 0; i < check - 1; i++)
				{
					fin >> bookid >> name >> dateofPurchase >> status >> price;
					fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
				}
				fin.close();
				fout.close();
				fout.open("temp.txt");
				fout << "Content Not Stored" << endl;
				fout.close();

				if (slection == "1")
				{

					fin.open("member1.txt");
				}

				else
				{

					fin.open("member2.txt");
				}

				linenumber = searchID;

				fout.open("temp.txt");

				int memID;
				string memName;
				int issued;

				while (!fin.eof()) {
					fin >> memID >> memName >> issued;

					if (memID == linenumber) {
						if (issued < 5) {
							issued = issued + 1;
						}
						else
						{
							cout << "Book Limit 4" << endl;
						}
					}
					fout << memID << " " << memName << " " << issued << endl;
					check1++;
				}

				fin.close();
				fout.close();


				if (slection == "1")
				{

					fout.open("member1.txt");
				}

				else
				{

					fout.open("member2.txt");
				}

				fin.open("temp.txt");

				for (int i = 0; i < check1 - 1; i++)
				{
					fin >> memID >> memName >> issued;
					fout << memID << " " << memName << " " << issued << endl;
				}
				fin.close();
				fout.close();
				fout.open("temp.txt");
				fout << "Content Not Stored" << endl;
				fout.close();


			}
			else
			{
				cout << "Book Not Available" << endl;
			}

		}
		else
		{
			cout << "Member Not Verified: " << endl;
		}

	}
	void displaymember()
	{

		ifstream fin;
		if (slection == "1")
		{
			fin.open("member1.txt");
		}
		if (slection == "2")
		{
			fin.open("member2.txt");
		}

		cout << "\n";
		cout << "\nID\tMember Name\tNo of Issued Book" << endl;
		cout << "----------------------------------------------------" << endl;
		while (fin >> memberid)
		{

			fin >> mname;
			fin >> noBookIssued;
			cout << "" << memberid << "\t" << mname << "\t\t" << noBookIssued << endl;

		}
		cout << "----------------------------------------------------" << endl;

	}

	void rerturnBook() {
		displaylibraryfile();
		cout << "(1) Student" << endl;
		cout << "(2) Faculty" << endl;
		cout << "Select You Option: ";

		cin >> slection;


		int linenumber;
		ifstream fin;
		ofstream fout;
		int check = 0;
		int check1 = 0;
		cout << "Enter Book Id: ";
		cin >> linenumber;
		fin.open("library.txt");
		fout.open("temp.txt");

		while (!fin.eof()) {
			fin >> bookid >> name >> dateofPurchase >> status >> price;

			if (bookid == linenumber) {
				status = 'A';

			}
			fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
			check++;
		}

		fin.close();
		fout.close();


		fin.open("temp.txt");
		fout.open("library.txt");
		for (int i = 0; i < check - 1; i++)
		{
			fin >> bookid >> name >> dateofPurchase >> status >> price;
			fout << bookid << " " << name << " " << dateofPurchase << " " << status << " " << price << endl;
		}
		fin.close();
		fout.close();
		fout.open("temp.txt");
		fout << "Content Not Stored" << endl;
		fout.close();

		if (slection == "1")
		{

			fin.open("member1.txt");
		}

		else
		{

			fin.open("member2.txt");
		}
		cout << "Enter Member Id: ";
		cin >> linenumber;

		fout.open("temp.txt");

		int memID;
		string memName;
		int issued;

		while (!fin.eof()) {
			fin >> memID >> memName >> issued;

			if (memID == linenumber) {
				if (issued > 0) {
					issued--;
				}
				else
				{
					cout << "No Book issued" << endl;
				}
			}
			fout << memID << " " << memName << " " << issued << endl;
			check1++;
		}

		fin.close();
		fout.close();


		if (slection == "1")
		{

			fout.open("member1.txt");
		}

		else
		{

			fout.open("member2.txt");
		}

		fin.open("temp.txt");

		for (int i = 0; i < check1 - 1; i++)
		{
			fin >> memID >> memName >> issued;
			fout << memID << " " << memName << " " << issued << endl;
		}
		cout << "Book Return" << endl;
		fin.close();
		fout.close();
		fout.open("temp.txt");
		fout << "Content Not Stored" << endl;
		fout.close();



	}

	void login() {

		cout << "\nEnter your Username and password.\nUsername:";
		cin >> userNameAttempt;
		while (true)
		{
			if (userNameAttempt == userName) {
				cout << "Password:";
				cin >> passWordAttempt;
				while (true)
				{
					if (passWordAttempt == passWord) {
						accessGranted = true;
						break;
					}
					cout << "Enter correct Password: ";
					cin >> passWordAttempt;
				}
				break;
			}
			cout << "Enter Correct UserName: ";
			cin >> userNameAttempt;

		}
	}


	~Librarian(){

	}
};

class LoginManager {
protected:
	string userNameAttempt;
	string passWordAttempt;
	string passWord;
	string userName;

public:

	Librarian composition;
	LoginManager() {


	}
	~LoginManager(){

	}

};
int main() {

	cout << "\t\t\t\t\t\tLibrary Management System" << endl;
	LoginManager loginManager;
	Librarian librarian;
	Book *book[1];
	Librarian obj1;
	book[0] = &obj1;
	string option;
	loginManager.composition.login(); // composition
	if (loginManager.composition.accessGranted == true)
	{
		do
		{

			cout << "\n\n(1) Add Book";
			cout << "\n(2) Search Book";
			cout << "\n(3) Update Book Status";
			cout << "\n(4) Add Member";
			cout << "\n(5) Verify Member";
			cout << "\n(6) Issue Book";
			cout << "\n(7) Return Book";
			cout << "\n\nEnter e/E to Exit";
			cout << "\nSelect Your Option: ";
			cin >> option;




			while (true) {
				if (option == "1" || option == "2" || option == "3" || option == "4" || option == "5" || option == "6" || option == "7" || option == "E" || option == "e") {
					break;
				}
				cout << "\nWrong Input: Enter Right Option: ";
				cin >> option;
			}


			if (option == "1")
			{
				system("cls");
				book[0]->setname();
				book[0]->setdateofPurchase();
				book[0]->setstatus();
				book[0]->setprice();
				book[0]->displayBookDetails();

			}

			else if (option == "2")
			{
				system("cls");
				cout << "Find books in these ways" << endl;
				cout << "(1) Name" << endl;
				cout << "(2) Availability" << endl;
				cout << "(3) ID" << endl;
				cout << "Enter Your Option: ";
				librarian.searchBook();

			}

			else if (option == "3")
			{

				system("cls");
				book[0]->displaylibraryfile();
				book[0]->updateStatus();
				book[0]->displaylibraryfile();


			}

			else if (option == "4")
			{
				string option;
				system("cls");
				cout << "(1) Student" << endl;
				cout << "(2) Faculty" << endl;
				cout << "select Your Option: ";
				cin >> option;

				while (true) {
					if (option == "1" || option == "2") {
						break;
					}
					cout << "\nWrong Input: Enter Right Option: ";
					cin >> option;
				}
				if (option == "1")
				{
					Student student;
					student.setName();
					student.setNoBookIssued();
					student.displaySMemberDetails();
				}
				else if (option == "2")
				{
					Faculty faculty;
					faculty.setName();
					faculty.setNoBookIssued();
					faculty.displayTMemberDetails();
				}

			}


			else if (option == "5")
			{

				system("cls");
				librarian.verifyMember();

			}

			else if (option == "6")
			{
				Book *vobj; // virtual
				Librarian vlobj;
				vobj = &vlobj;
				system("cls");
				librarian.issueBook();
				vobj->displaylibraryfile();
				librarian.displaymember();

			}
			else if (option == "7")
			{

				system("cls");
				librarian.rerturnBook();
				librarian.displaylibraryfile();
				librarian.displaymember();
			}


		} while (option != "E" && option != "e");
	}

	system("pause");
	return 0;
}