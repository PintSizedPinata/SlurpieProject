// Slurpie Mid Term Project.cpp : Defines the entry point for the console application.
// List of Indices: XtremeSlurpies0, RegularChips1, LargeChips2, Water3, Soda4, Candy5, SunflowerSeeds6, Nuts7, SmallJerky8, BagOfJerky9, FountainDrink10, HotFood11, Cookies12, SmallPizza13, LargePizza14, Gas15;


#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
float change;
float cash;
float check;
char answer1;
int answer2;
int x = 0;
char answerYN;
int y = 0;
int amount;
float taxTotal;
float total;
double tax = 1.092;
double totalConstant;
double taxTotalConstant;
string cashCheck;
struct store_products {
	double price;
	string name;
};

store_products menu[15];

void start_menu() {
	menu[0].name = "Xtreme Slurpee";
	menu[0].price = 7.99;
	menu[1].name = "Regular Chips";
	menu[1].price = .99;
	menu[2].name = "Large Chips";
	menu[2].price = 1.49;
	menu[3].name = "Water";
	menu[3].price = .99;
	menu[4].name = "Soda";
	menu[4].price = 1.09;
	menu[5].name = "Candy";
	menu[5].price = .99;
	menu[6].name = "Sunflower Seeds";
	menu[6].price = 1.29;
	menu[7].name = "Nuts";
	menu[7].price = 1.49;
	menu[8].name = "Small beef jerky";
	menu[8].price = .99;
	menu[9].name = "Bag of beef jerky";
	menu[9].price = 3.99;
	menu[10].name = "Fountain Drink";
	menu[10].price = 1.39;
	menu[11].name = "Hot Food";
	menu[11].price = 4.99;
	menu[12].name = "Cookies";
	menu[12].price = .50;
	menu[13].name = "Small Pizza";
	menu[13].price = 5.99;
	menu[14].name = "Large Pizza";
	menu[14].price = 9.99;
	menu[15].name = "Gas per gallon";
	menu[15].price = 2.15;

}
double menuFunction() {	start_menu();
	system("CLS");
	system("Color A1");
	cout << "------Welcome to Slurpie's Speedy Stop------\n\n";
	cout << "Here is our fine selection of products:\n";
	while (x <= 15) {
		cout << "(" << x << ") " << menu[x].name << " - " << menu[x].price << endl;
		x++;
	}
	x = 0;
	
	do {
	cout << "Whataya buyin'?\n";
	cin >> y;
	cout << "How many would you like?\n";
	cin >> amount;
	total = (total + menu[y].price) * amount;
	taxTotal = total * tax;
	cout << "want something else?Y\\N\n\n";
	cin >> answerYN;
	} while (answerYN == 'y' || answerYN == 'Y');
	return (total);
}

void checkoutFunction(){
	system("Color D2");
	taxTotal = total * tax;
	if (total == 0) {
		cout << "There is nothing on your bill right now, here's our menu.\n\n";
		system("PAUSE");
		menuFunction();
	}
	cout << "Your total is: $" << total << " and after tax that makes $" << setprecision(3) <<  taxTotal << endl;
	cout << "How would you like to pay? Cash or Check, this is 1983 so cards aren't an option.\n";
	cin >> cashCheck;
	if (cashCheck == "cash" || cashCheck == "Cash") {
		do {
			cout << "How much cash are you gonna hand me?\n";
			cin >> cash;
			change = (cash - taxTotal);
			if (change > 0) {
				cout << "Your change is $" << setprecision(3) << change << endl;
				cout << "Thanks for shopping!\n\n";
				system("PAUSE");
			}
			else if (change < 0) {
				cout << "You would still owe $" << abs(change) << " either give me a larger bill or don't waste my time"<< endl;
			}
		} while (change < 0);
	}
	else if (cashCheck == "check" || cashCheck == "Check") {
		cout << "No cash back is allowed with a check, you must write it for the full amount.\n\n";
		cout << "Thank you for shopping!\n";
		cin >> answer1;
	}
	

}


int main()
{
	system("Color 7");
	totalConstant = total + totalConstant;
	taxTotal = total * tax;
	taxTotalConstant = taxTotal + taxTotalConstant;
	start_menu();
	system("CLS");
	cout << "------Welcome to Slurpie's Speedy Stop------\n\n";
	cout << "---Main Menu---\n\n";
	cout << "1. Menu\n";
	cout << "2. Total\n";
	cout << "3. Checkout\n";
	cin >> answer2;
	if (answer2 == 1) {
		menuFunction();
		main();
	}
	else if (answer2 == 2) {
		system("CLS");
		system("Color F0");
		if (total == 0) {
			cout << "You have nothing on your bill right now, here is our menu.\n";
			system("PAUSE");
			menuFunction();
		}
		cout << "Your current total is $" << total << ". After tax that makes $" << setprecision(3) << taxTotal << endl;
		cout << "Enter anything to return to the main menu.\n";
		cin >> answer1;
		main();
	}
	else if (answer2 == 3) {
		checkoutFunction();
	}

	system("PAUSE");
    return 0;
}

