#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
//Audrey Lundy, Final exam due 4/24/24. My program generate symptoms for a user-inputted # of patients and then groups them according to their illness.
using namespace std;
class Symptoms
{
	private:
		//tracker 2d-vector to store generate numbers according to patient
		vector<vector<int>>tracker;
		
	public:		
		Symptoms(){}
		
		void test(int numPatients,int generate)
		{
			//resizes tracker vector to have user inputted # of rows and each row has vector of generate numbers
			tracker.resize(numPatients, vector<int>(generate));
			srand(time(0));
			//iterates through 2d vectors, assigning 7 random numbers to each patient
			for (int i=0;i<numPatients;++i)
			{
				for (int j=0;j<generate;++j)
				{
					int isPresent= rand()%2;
					tracker[i][j]=isPresent;
				}
			}	
		}	
	//Return info to main function
	const vector<vector<int>>& getTracker() const
	{
		return tracker;
	}
};
//CheckDisease derived class to match symptoms with disease and display them.
class CheckDisease : public Symptoms 
{
	public:
		void diagnose(const vector<vector<int>>& tracker)
		{
			int numPatients= tracker.size();
			int covidP=0;
			int coldP=0;
			int fluP=0;
			int otherP=0;
			string illness;
			//for loop to iterate through vector keeping track of patient's symptoms
			for (int i=0;i<numPatients;++i)
			{	
				//if and else-if to identify which symptoms match up with the table and adds person to variable of their illness(covidP,coldP,fluP,or otherP)
				if (tracker[i][0]==1 && tracker[i][1]==1 && tracker[i][2]==1 && tracker[i][5]==0)
				{
					illness="Covid-19";
					covidP++;
				}
				else if (tracker[i][2]==0 && tracker[i][3]==1 && tracker[i][5]==1)
				{
					illness="Cold";
					coldP++;
				}
				else if (tracker[i][0]==1 && tracker[i][1]==1 && tracker[i][2]==0 && tracker[i][4]==1 && tracker[i][5]==0 && tracker[i][6]==1)
				{
					illness="Flu";
					fluP++;
				}
				else
				{
					otherP++;
				}
				
			}	
			//display info to user including how many are in each category and finds the percentage of each illness
			cout<<"Symptoms Check...."<<endl;
			cout<< covidP <<" patients have symptoms of COVID-19"<<endl;
			cout<< coldP <<" patients have symptoms of Cold"<<endl;
			cout<< fluP <<" patients have symptoms of Flu"<<endl;
			cout<< otherP <<" patients may have some other illness"<<endl;
			cout << "=====================================" <<endl;
			cout <<"\n\nPercentage of each illlness: " <<endl;
			cout <<"COVID-19:\t["<<(covidP*100)/numPatients<<"%]"<<endl;
			cout <<"Cold:\t\t["<<(coldP*100)/numPatients<<"%]"<<endl;
			cout <<"Flu:\t\t["<<(fluP*100)/numPatients<<"%]"<<endl;
			cout <<"Other illness:\t["<<(otherP*100)/numPatients<<"%]"<<endl;
			
		}			
};
int main()
{
	//variables used throughout program
	int generate=7;
	int numPatients;
	//displays table and asks for # of patients
	cout << "Welcome to Symptoms Checker" <<endl;
	cout <<"\n\nGuide: \t\t\t * Common\t + Sometimes/Rarely\t - NO" << endl;
	cout <<"====================================================================" << endl;
	cout <<"Symptoms \t\t |    COVID-19    |    Cold    |    Flu    |" << endl;
	cout <<"====================================================================" << endl;
	cout <<"Fever \t\t\t |       *        |      +     |      *    |" << endl;
	cout <<"Cough \t\t\t |       *        |      +     |      *    |" << endl;
	cout <<"Shortness of Breath\t |       *        |      -     |      -    |" << endl;
	cout <<"Runny Nose \t\t |       +        |      *     |      +    |" << endl;
	cout <<"Headaches \t\t |       +        |      +     |      *    |" << endl;
	cout <<"Sneezing \t\t |       -        |      *     |      -    |" << endl;
	cout <<"Fatigue \t\t |       +        |      +     |      *    |" << endl;
	cout <<"====================================================================" << endl;
	cout <<"\n\nEnter the number of patients? " << endl;
	cin >> numPatients;
	cout << "Thank you..." << endl;
	cout << "=====================================" <<endl;
	
	//creates instances of Symptoms and CheckDiseases classes.   
	Symptoms symptoms;
	symptoms.test(numPatients,generate);
	
	//reference to tracker vector to collect symptoms data
	const vector<vector<int>>&tracker=symptoms.getTracker();
	
	CheckDisease diseaseChecker;
	diseaseChecker.diagnose(tracker);
	
	return 0;
}





























