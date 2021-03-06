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
double getJudgeData(string jname, double &score);
double getAverage(double judge1, double judge2, double judge3, double judge4, double judge5);
double findLowest(double judge1, double judge2, double judge3, double judge4, double judge5);
double findHighest(double judge1, double judge2, double judge3, double judge4, double judge5);

int main()
{
	double judge1, judge2, judge3, judge4, judge5, average_sc, lowest_sc, highest_sc;;

	getJudgeData("Judge 1", judge1);
	getJudgeData("Judge 2", judge2);
	getJudgeData("Judge 3", judge3);
	getJudgeData("Judge 4", judge4);
	getJudgeData("Judge 5", judge5);
	average_sc = getAverage(judge1, judge2, judge3, judge4, judge5);

	highest_sc = findHighest(judge1, judge2, judge3, judge4, judge5);
	lowest_sc = findLowest(judge1, judge2, judge3, judge4, judge5);

	cout << setprecision(2) << fixed;
	
	cout << "Your highest Judge score is: " << highest_sc << endl;
	cout << "Your lowest Judge score is:" << lowest_sc << endl;
	cout << "The AVG score is:" << average_sc << endl;

	
}

double getAverage(double judge1, double judge2, double judge3, double judge4, double judge5) {

	double high = findHighest(judge1, judge2, judge3, judge4, judge5);
	double lowest = findLowest(judge1, judge2, judge3, judge4, judge5);

	if (judge1 == high)
		judge1 = 0.00;
	if (judge1 == lowest)
		judge1 = 0.00;
	if (judge2 == high)
		judge2 = 0.00;
	if (judge2 == lowest)
		judge2 = 0.00;
	if (judge3 == high)
		judge3 = 0.00;
	if (judge3 == lowest)
		judge3 = 0.00;
	if (judge4 == high)
		judge4 = 0.00;
	if (judge4 == lowest)
		judge4 = 0.00;
	if (judge5 == high)
		judge5 = 0.00;
	if (judge5 == lowest)
		judge5 = 0.00;

	double average;

	average = judge1 + judge2 + judge3 + judge4 + judge5;
	average = average / 3;

	return average;
}

double findHighest(double judge1, double judge2, double judge3, double judge4, double judge5) {

	double array[5];

	array[0] = judge1;
	array[1] = judge2;
	array[2] = judge3;
	array[3] = judge4;
	array[4] = judge5;

	int startScan, minIndex;
	double minValue;
	for (startScan = 0; startScan < 4; startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];

		for (int index = startScan + 1; index < 5; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;

			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}

	return array[4];

}

double findLowest(double judge1, double judge2, double judge3, double judge4, double judge5) {

	double array[5];

	array[0] = judge1;
	array[1] = judge2;
	array[2] = judge3;
	array[3] = judge4;
	array[4] = judge5;

	int startScan, minIndex;
	double minValue;
	for (startScan = 0; startScan < 4; startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];

		for (int index = startScan + 1; index < 5; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;

			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}

	return array[0];

}

double getJudgeData(string jname, double &score) {
	
	cout << "Please enter " << jname << "'s score." << endl;
	cin >> score;
	do
	{
		
		if (cin.fail() == true) {

			cout << "Please enter a number for the score." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> score;
			
		}

		else if (score < 0) {

			cout << "The score cannot be less than zero." << endl;
			cin >> score;
			

		}
		else if (score > 10) {

			cout << "The score cannot be greater than 10." << endl;
			cin >> score;
			
		}
		

	} while (cin.fail() == true || score < 0 || score > 10);

	return score;
}