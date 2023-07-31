#include <iostream>
#include <algorithm> 
using namespace std;

typedef struct job
{
    string jobName;
    int startingtime;
    int finishtime;
    int compatibility;
} job;

job jobs[100];
int numJobs;
int finishtime[100];

void getInput()
{
    cout << "Enter the jobs: ";
    cin >> numJobs;

    for (int i = 0; i < numJobs; i++)
    {
        cin >> jobs[i].jobName >> jobs[i].startingtime >> jobs[i].finishtime;
        finishtime[i] = jobs[i].finishtime;
        jobs[i].compatibility = 1;
    }
}

void sortFinishtime()
{
    sort(finishtime, finishtime + numJobs);

    for (int i = 0; i < numJobs; i++)
    {
        for (int j = 0; j < numJobs; j++)
        {
            if (finishtime[i] == jobs[j].finishtime)
            {
                swap(jobs[i], jobs[j]); 
            }
        }
    }
}

void checkCompatibility(int i)
{
    int m= i+1;

    while(m<= numJobs && jobs[m].startingtime < jobs[i].finishtime)
    {
        jobs[m].compatibility=0;
        m++;
    }

    if(m <= numJobs)
    {
    checkCompatibility(m);
    }
}

void printSchedule()
{
    for (int i = 0; i < numJobs; i++)
    {
        if (jobs[i].compatibility == 1)
        {
            cout << jobs[i].jobName << " " << jobs[i].startingtime << " "<< jobs[i].finishtime << endl; // Print starting time
        }
    }
}

void scheduling()
{
    freopen("input.txt", "r", stdin);
    getInput();
    sortFinishtime();
    checkCompatibility(0);
    printSchedule();
}

int main()
{
    scheduling();
    return 0;
}