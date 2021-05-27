#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

int CPUballing(string);
int CPUbatting(string);
int Toss();
void Decision(int,int);
const double pitchlength = 22.56;    //standard pitch length is about 22 meters  
const double distanceV = 2.44;		//ball of length (starting from pitch) above 2.44-meters will be considered as no ball...
const double distanceH = 1;			//ball of width above 1m will be considered as wide ball...
const double height = 1.3;          //ball of height above 1.3m will be considered as bouncer...
const double lowangle = -5;		//ball of angle deviation less than -5Degrees(from throwing angle of ball)......OR
const double highangle = 5;        //ball of angle deviation more than 5Degrees(from throwing angle of ball) ....is Spin ball...
						//" OUT will be only in the case of Spin Ball if angle crosses 10Degrees deviation (more or less) ".....
double entereddistanceV = 0;
double entereddistanceH = 0;
double enteredheight = 0;
double enteredangle = 0;
int main() {
	int re1 = 0, re2 = 0;
	const string f="1st", s="2nd";
	cout << "*****WELCOME to Cricket Game*****It is 1 over(6-balls) match...\n";
	int t = Toss();
	
	if (t == 1)
	{
		system("CLS");
		re1 = CPUballing(f);
		system("CLS");
		cout << "\n*****Runs made by you: " << re1 << "*****\n\n";

		re2 = CPUbatting(s);
		system("CLS");
		cout << "\n*****Runs made by you: " << re1 << "*****\n\n";
		cout << "\n*****Runs made by me: " << re2 << "*****\n\n";

		Decision(re1, re2);
	}
	if (t == 0)
	{
		system("CLS");
		re2 = CPUbatting(f);
		system("CLS");
		cout << "\n*****Runs made by me: " << re2 << "*****\n\n";

		re1 = CPUballing(s);
		system("CLS");
		cout << "\n*****Runs made by me: " << re2 << "*****\n\n";
		cout << "\n*****Runs made by you: " << re1 << "*****\n\n";

		Decision(re1, re2);
	}
	if (t == 2)
	{
		re1 = CPUballing(f);
		system("CLS");
		cout << "\n*****Runs made by you: " << re1 << "*****\n\n";

		re2 = CPUbatting(s);
		system("CLS");
		cout << "\n*****Runs made by you: " << re1 << "*****\n\n";
		cout << "\n*****Runs made by me: " << re2 << "*****\n\n";

		Decision(re1, re2);
	}
	system("pause");
	return 0;
}

//Toss performing function.......
int Toss()
{
	int ch = 0;
	cout << "\nLet's do TOSS:\n\nRULe:\n\nI am picking a random number...if even number comes, then u will win, otherwise I will win the toss\n";
	srand(time(0));
	int random = rand();
	cout << "\nRoandom number is: " << random << endl;
	if (random % 2 == 0)
	{
		cout << "\nCongrats! U have won the toss\n";
		string choose;
		cout << "\nwrite 'bat' to choose batting... OR 'ball' to choose balling: "; cin >> choose;
		if (choose == "bat") ch = 1;
		else                 ch = 0;
	}
	else
	{
		cout << "\nHey! you can see I have won the Toss\n\nSo.....I am choosing balling..\n";
		ch = 2;
	}
	
	return ch;
}

//CPUballing function.........
int CPUballing(string fs)
{   
	cout << "\nIt is "<<fs<<" innings....I am bowler and you are batsman....Result is shown side by side...\n\n";
	int runs = 0, truns = 0,boo=0, ballsrem = 6, wicketsremain = 10;
	cout << "Runs: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;

	while (ballsrem != 0)
	{
		//as computer is performing balling so let randomly choose the category of ball by distance
		entereddistanceV = 2.7; 
		cout << "\nIt is no ball;\nenter 1 if you want to strike ,,,0 if not: "; cin >> boo;
		if (boo == 1)    runs = 6;
		else             runs = 1;		//1 extra score for no ball, + ball aslo counnts...
		truns = truns + runs;
		ballsrem--;
		cout << "Runs: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;



		//2nd ball, wide ball ..
	    entereddistanceH = 1.3; 
		cout << "\nIt is wide ball:\nenter 1 if you want to strike ,,,0 if not: "; cin >> boo;
		if (boo == 1)   runs = 4;
		else            runs = 1;			//1 extra score for wide ball...ball not counts..
		truns = truns + runs;
		cout << "Runs: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;



		//3rd ball ...maaking it bouncer...
		enteredheight = 2;       
		cout << "\nIt is bouncer ball:\nenter 1 if you want to strike ,,,0 if not: "; cin >> boo;
		if (boo == 1)    runs = 6;
		else             runs = 0;
		truns = truns + runs;
		ballsrem--;
		cout << "Runs: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;



		//fourth ball...making it spin...
		enteredangle = 12;          //angle deviation is of 12-Degrees from throwing angle of ball...
		cout << "\nIt is spin ball:\nenter 1 if you want to strike ,,,0 if not: "; cin >> boo;

		if ((enteredangle > highangle || enteredangle < lowangle) && (boo == 1))      //angle deviation more than 10 degrees will out the player........
		{
			wicketsremain--;
			cout << "\n\t*****OUT*****\n";
		}
		else
		{
			if (boo == 1)  runs = 2;
			else           runs = 0;
			truns = truns + runs;
		}
		ballsrem--;
		cout << "Runs: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;
	}
	return truns;

}

//CPUbatting function............
int CPUbatting(string ss)
{
	cout << "It is "<<ss<<" innings.....I am batsman and you are bowler....Result is shown side by side\n";
	int runs = 0, truns = 0, boo = 0, ballsrem = 6, wicketsremain = 10;
	cout << "Runs: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;
	while (ballsrem != 0)
	{
		cout << "\nSelect category of ball of your choice...enter relevent distances for each category below\n";
		cout << "length entered above 2.44m will be considered as noball: "; cin >> entereddistanceV;
		cout << "width entered above 1m will bs considered as wide ball: "; cin >> entereddistanceH;
		cout << "height entered above 1.3m will be considered as bouncer: "; cin >> enteredheight;
		cout << "angle deviation more than 5 or -5 Degrees (from throwing angle of ball) will give spin ball: "; cin >> enteredangle;
		
		if (entereddistanceV > distanceV)
		{
			cout << "\nIt was no ball, I have played...";  //CPU wants to strike
			runs = 6;
			ballsrem--;
			truns = truns + runs;
			cout << "\nRuns: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;
		}

		else if (entereddistanceH > distanceH)
		{
			cout << "\nIt was wide ball, I have played...";			//CPU wants to strike
			runs = 4;
			truns = truns + runs;
			cout << "\nRuns: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;
		}
		
		else if (enteredheight > height)
		{
			cout << "\nIt was bouncer ball, I have played...";			//CPU don't wants to strike
			runs = 0;
			ballsrem--;
			cout << "\nRuns: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;
		}

		else if (enteredangle > highangle || enteredangle <lowangle)
		{
			cout << "\nIt was spin ball, I have played...";				//CPU wants to strike
			if (enteredangle > 10 || enteredangle < -10)      //angle deviation more than 10 degrees will out the player........
			{
				wicketsremain--;
				cout << "\n\t*****OUT*****\n";
			}
			else
			{
				runs = 2;
				truns = truns + runs;
			}
			ballsrem--;
			cout << "\nRuns: " << truns << "\nRemaining Balls: " << ballsrem << "\nRemaining Wickets: " << wicketsremain << endl;
		}

		else
		{
			cout << "enter properly\n";
		}
		
	}
	return truns;
}

//decison of result function.............
void Decision(int ree1, int ree2)
{
	cout << "\nMatch Result:\n";
	if (ree1 > ree2)
		cout << "*****Congrats! you have won the match*****\n";
	else if (ree1 < ree2)
		cout << "*****Oh Sorry! you lost..I have won the match*****\n";
	else
		cout << "*****We scored equal so...match has drawn*****\n";
}





