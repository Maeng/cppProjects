//전자정보통신대학 컴퓨터공학부 20103331 맹성주

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void computeEaster(int y); 

int main(void)
{
	FILE *inFile;
	int numTestCases;

	inFile = fopen("input.txt", "r");

	if (inFile == NULL)
	{
		cerr << "Input file opening failed.";
		exit(1);
	}

	fscanf(inFile, "%d", &numTestCases);

	for(int i=0; i<numTestCases; i++)
	{
		int year;

		fscanf(inFile, "%d", &year);

		computeEaster(year);
	}

	return 0;

}

void computeEaster(int y)
{
	int c, n, t, i, j, k, l, p, q;
	int t1, t2, t3, t4, t5, t6, t7;
	int month, day;
	
	c = y/100;	//2
	n = y-((y/19)*19);	//3
	t = (c-17)/25;	//4
	t1 = c-((c/4)+((c-t)/3));	//5
	t2 = (n*19)+15;	//6
	i = t1 + t2;	//7
	j = i- ((i/30)*30);	//8
	t3 = j/28;	//9
	t4 = 1-(j/28);	//10
	t5 = 29/(j+1);	//11
	t6 = (21-n)/11;	//12
	k = j-(t1*t2*t3*t4);	//13
	t7 = y+(y/4)+j+2;	//14
	l = (t7-c)+(c/4);	//15
	p = l-((l/7)*7);	//16
	q = k-p;	//17
	month = ((q+40)/44)+3;	//18
	day = (q+28)-((month/4)*31);

	cout << month << " " << day << endl;
	
}
