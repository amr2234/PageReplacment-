#include "pch.h"
#include "LRU_FIFO_OPtimal.h"
using namespace std;

PageReplacement::PageReplacement()
{
	NOFrames=NOPages=Page_Fault = j =hit = 0;
	cout << "------Welcome to Paging Allocation-------" << endl;
	GetData();
}

PageReplacement::~PageReplacement()
{
	delete[]ArrayF;
	delete[]ArrayP;
}

void PageReplacement::GetData()
{
	int Choise = 0;
	cout << "Enter page numbers =  ";
	cin >> NOPages;
	ArrayP = new int[NOPages];
	cout << "Enter the pages : " << endl;
	for (int i = 0; i < NOPages; i++)
	{
		cin >> ArrayP[i];
	}
	cout << "Enter number of frames =  ";
	cin >> NOFrames;
	ArrayF = new int[NOFrames];
	for (int l = 0; l < NOFrames; l++)
	{
		ArrayF[l] = -1;
	}
	mManu();
	
}

void PageReplacement::FiFo()
{
	cout << ".------------------------------------------------------------." << endl;
	cout <<"\t" <<"Frames Display" << endl;

	j = 0;
	for (int p = 0; p < NOPages; p++) 
	{
		cout <<"\t";
		Flag = 0;
		for (int h = 0; h <= NOFrames - 1; h++)
		{
			if (ArrayF[h] == ArrayP[p])
			{
				Flag = 1;
				hit++;
			}
		}
		if (Flag == 0)
		{
			ArrayF[j] = ArrayP[p];
			j = (j + 1) % NOFrames;
			Page_Fault++;

			for (int k = 0; k < NOFrames; k++)
				cout << ArrayF[k] << "\t";
		}
		cout << endl;
	}
	cout << ".------------------------------------------------------------." << endl;
	cout << "Num of Page Fault =  " << Page_Fault << endl;
	cout << " Num of Hit = " << hit;
}

void PageReplacement::Optimal()
{
	int pos, max;
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < NOPages; i++) {
	 flag1 , flag2 = 0;

		for( int j = 0; j < NOFrames; j++) {
			if (ArrayF[j] == ArrayP[i]) {
				flag1 = flag2 = 1;
				break;
			}
		}

		if (flag1 == 0) {
			for (j = 0; j < NOFrames; j++) {
				if (ArrayF[j] == -1) {
					Page_Fault++;
					ArrayF[j] = ArrayP[i];
					flag2 = 1;
					break;
				}
			}
		}

		if (flag2 == 0) 
		{
			int flag3 = 0;

			for (j = 0; j < NOFrames; j++) 
			{
			
				temp[j] = -1;

				for (int k = i + 1; k < NOPages; k++) 
				{
					if (ArrayF[j] == ArrayP[k])
					{

						temp[j] = k;
						break;
					}
				}
			}

			for (j = 0; j < NOFrames; j++) 
			{
				if (temp[j] == -1) {
					pos = j;
					flag3 = 1;
					break;
				}
			}

			if (flag3 == 0) 
			{
				max = temp[0];
				pos = 0;

				for (j = 1; j < NOFrames; j++) 
				{
					if (temp[j] > max) {
						max = temp[j];
						pos = j;
					}
				}
			}

			ArrayF[pos] = ArrayP[i];
			Page_Fault++;
		}

		for (int k = 0; k < NOFrames; k++) {
		
			
				cout << "\t" << ArrayF[k] << "\t";
			
		}
		cout << endl;
	}

	cout << ".------------------------------------------------------------." << endl;
	cout << "Num of Page Fault =  " << Page_Fault << endl;
}

void PageReplacement::LRU()
{
	int l ,position;
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < NOPages; i++) {
		flag1, flag2 = 0;

		for (int j = 0; j < NOFrames; j++)
		{
			if (ArrayF[j] == ArrayP[i]) {
				flag1 = flag2 = 1;
				break;
			}
		}

		if (flag1 == 0) {
			for (j = 0; j < NOFrames; j++) {
				if (ArrayF[j] == -1) {
					Page_Fault++;
					ArrayF[j] = ArrayP[i];
					flag2 = 1;
					break;
				}
			}
		}
		if (flag2 = 0)
		{

			for (j = 0; j < NOFrames; j++)
			{

				temp[j] = 0;
			}
			for (int k = i - 1, l = 1; l <= NOFrames - 1; l++, k--)
			{
				for (int f = 0; f < NOFrames; f++)
				{
					if (ArrayF[f] == ArrayP[k])
					{
						temp[f] = 1;
					}
				}

			}
			for (int h = 0; h < NOFrames; h++)
			{
				if (temp[h] == 0) {
					position = h;
				}
			}
			ArrayF[position] = ArrayP[i];
			Page_Fault++;
		}
		for (int k = 0; k < NOFrames; k++) {
			cout << "\t" << ArrayF[k] << "\t";
		}
		cout << endl;
	}
	cout << ".------------------------------------------------------------." << endl;
	cout << "Num of Page Fault =  " << Page_Fault << endl;

}

void PageReplacement::display()
{
}

void PageReplacement::mManu()
{
	int choice = 0;

	while (choice != 4)
	{
		menu();

		cout << "Which Page Algorithm would you like?" << endl;
		cout << "Enter a number 1-4: ";
		cin >> choice;

		if (choice == 1)
		{
			FiFo();
		}
		else if (choice == 2)
		{
			LRU();
		}
		else if (choice == 3)
		{
			Optimal();
		}
		else if (choice == 4)
		{
			cout << "Thank you";

		}
		if (choice != 4)
		{ 
			cin.ignore();
			cout << endl;
			cout << "Press any key to return to main menu";
			cin.get();
			Page_Fault = 0;

		}

	

	}
}

void PageReplacement::menu()
{
	int choice = 0;
	cout << ".------------------------------------------------------------." << endl;
	cout << endl;
	cout << "(1) FIFO" << endl;
	cout << "(2) LRU" << endl;
	cout << "(3) OPTIMAL" << endl;
	cout << "(4) Quit" << endl;

}

