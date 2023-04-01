#include <iostream>
#include <string>
#include <locale.h>
#include <ctype.h>
#include <regex>
#include <iostream>

#define DEBUG_FLG

using namespace std;

class Library {

private:
	string Phone;
	string Library_name;

public:
	int setPhone(string saLibraly) {
		int error_current{ 0 };
		smatch m;
		if (regex_match(saLibraly, m, regex("^[1-9][0-9]{4}-[0-9]{2}$"))){
			error_current = 0;
		}
		else {
			error_current = 1;
		};
		return error_current;
	};

	string getPhone() {
		return Phone;
	};

	int setLibrary_name() {
	};

	string getLibrary_name() {
		return Library_name;
	};
};

class Service {
private:
	string Service_type;
	int Price;

public:
	int setService_type() {
	};

	string getService_type() {
		return Service_type;
	};

	int setPrice(string saPrise) {
		int error_current1{ 0 };
		smatch m;
		if (regex_search(saPrise, m, regex("^[1-9][0-9]*$"))){
			error_current1 = 0;
		}
		else {
			error_current1 = 1;
		};
		return error_current1;
	};

	int getPrice() {
		return Price;
	};

};

void testLibrarysetPhone(Library testingLibPhone) {

	cout << endl << "Testing Lib Phone:" << endl;

	string Phone = "11111-11";
	if (testingLibPhone.setPhone(Phone) == 0) {
		cerr << "Positive test " << Phone << " passed" << endl;
	}
	else {
		cerr << "Positive test " << Phone << " failed" << endl;
	}

	Phone = "01111-11";
	if (testingLibPhone.setPhone(Phone) == 1) {
		cerr << "Negative test " << Phone << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Phone << " failed" << endl;
	}

	Phone = "00000-00";
	if (testingLibPhone.setPhone(Phone) == 1) {
		cerr << "Negative test " << Phone << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Phone << " failed" << endl;
	}

	Phone = "0";
	if (testingLibPhone.setPhone(Phone) == 1) {
		cerr << "Negative test " << Phone << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Phone << " failed" << endl;
	}
	Phone = "10000-asdfg";
	if (testingLibPhone.setPhone(Phone) == 1) {
		cerr << "Negative test " << Phone << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Phone << " failed" << endl;
	}

	Phone = "asdfg[{{";
	if (testingLibPhone.setPhone(Phone) == 1) {
		cerr << "Negative test " << Phone << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Phone << " failed" << endl;
	}
};

void testPriceServise(Service testingPrice) {

	cout << endl << "Testing Service Price:" << endl;

	string Price = "1111111";
	if (testingPrice.setPrice(Price) == 0) {
		cerr << "Positive test " << Price << " passed" << endl;
	}
	else {
		cerr << "Positive test " << Price << " failed" << endl;
	}

	Price = "1";
	if (testingPrice.setPrice(Price) == 0) {
		cerr << "Positive test " << Price << " passed" << endl;
	}
	else {
		cerr << "Positive test " << Price << " failed" << endl;
	}

	Price = "-1";
	if (testingPrice.setPrice(Price) == 1) {
		cerr << "Negative test " << Price << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Price << " failed" << endl;
	}

	Price = "0";
	if (testingPrice.setPrice(Price) == 1) {
		cerr << "Negative test " << Price << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Price << " failed" << endl;
	}

	Price = "asdfg{}{}}";
	if (testingPrice.setPrice(Price) == 1) {
		cerr << "Negative test " << Price << " passed" << endl;
	}
	else {
		cerr << "Negative test " << Price << " failed" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Ru");
	Library testingLibPhone;
	Service testingPrice;

#ifdef DEBUG_FLG
	testLibrarysetPhone(testingLibPhone);
	testPriceServise(testingPrice);
#endif

	return 0;
}
