/*
Aaron McCormick Assignment 5
Aaron McCormick
2/20/2019


*/
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <stdio.h> 
#include <math.h>

using namespace std;
double getJudgeData(string jname, double score);
double getAverage(double judge1, double judge2, double judge3, double judge4, double judge5);
double  findLowest(double judge1, double judge2, double judge3, double judge4, double judge5);
double  findHighest(double judge1, double judge2, double judge3, double judge4, double judge5);

int main()
{
	double judge1, judge2, judge3, judge4, judge5, average_sc, lowest_sc, highest_sc;;

	judge1 = getJudgeData("Judge 1", 0);
	judge2 = getJudgeData("Judge 2", 0);
	judge3 = getJudgeData("Judge 3", 0);
	judge4 = getJudgeData("Judge 4", 0);
	judge5 = getJudgeData("Judge 5", 0);

	highest_sc = findHighest(judge1, judge2, judge3, judge4, judge5);
}

double findHighest(double judge1, double judge2, double judge3, double judge4, double judge5) {

	double high;

	//Start var1
	if (judge1 > judge2) {
		high = judge1;
	}

	else if (judge1 > judge3) {
		high = judge1;
	}

	else if (judge1 > judge4) {
		high = judge1;
	}
	else if (judge1 > judge5) {
		high = judge1;
	}
	//End var1

	//Start var2
	return high;

}

double getJudgeData(string jname, double score) {
	bool testnum;
	cout << "Please enter " << jname << "'s score." << endl;
	cin >> score;
	do
	{
		
		if (cin.fail() == true) {

			cout << "Please enter a number for the score." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> score;
			testnum = 1;
		}

		else if (score < 0) {

			cout << "The score cannot be less than zero." << endl;
			cin >> score;
			testnum = 1;

		}
		else if (score > 10) {

			cout << "The score cannot be greater than 10." << endl;
			cin >> score;
			testnum = 1;
		}
		else	{
			testnum = 0;
		}

	} while (testnum == 1);

	return score;
}