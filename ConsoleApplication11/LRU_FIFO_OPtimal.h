#include <vector>
#include <iostream>


class PageReplacement
{
public:
PageReplacement();
 ~PageReplacement();
	void GetData();
	void FiFo(); // algorithm Fifo
	void Optimal(); //  algorithm OTM
	void LRU(); //   algorithm LRU
	void display(); 
	void mManu(); 
	void menu();
	


private :

	int  NOFrames, NOPages, Page_Fault = 0, j, hit = 0;
	int * ArrayP, *ArrayF , temp[10];
	int Flag ;
};