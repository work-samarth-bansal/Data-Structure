#include <iostream>
#include <ctime>            //converts the time value pointed to by time to local time in the form of a character string
#include <chrono>           //used to deal with date and time
#include <sstream>          //allows you to manipulate strings as if they were input or output streams
#include <string>           //defines one variable type, one macro, and many functions which can be used to manipulate a string or array of characters
using namespace std;

pair<int, int> getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* timeInfo = localtime(&currentTime);

    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;

    return make_pair(hour, minute);
}

void PrintDay(int dayIndex)
{
    int day = dayIndex % 7;
    cout << "Tasks for ";
    switch (day) {
        case 0:
            cout << "Monday";
            break;
        case 1:
            cout << "Tuesday";
            break;
        case 2:
            cout << "Wednesday";
            break;
        case 3:
            cout << "Thursday";
            break;
        case 4:
            cout << "Friday";
            break;
        case 5:
            cout << "Saturday";
            break;
        case 6:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid day index";
            break;
    }
    cout << ":\n";
}


class Node
{
    public :
    string type;
    string task;
    int n;
    string *subt;
    int hr;
    int mi;

    Node *next;
    Node *prev;

    Node(string t,string tk,int num,string sub[],int h,int m) : type(t), task(tk),n(num), subt(sub), hr(h), mi(m), next(NULL), prev(NULL){}

    ~Node()
    {
        delete[] subt;
    }
    
};

class Week
{
    Node* days[7];

    public :

    Week()
    {
        for (int i = 0; i < 7; ++i) {
            days[i] = NULL;
        }
    }

    void Add(int dayno)
    {
        string type;
        cout << "Is it Work / Personal (W/P) : ";
        cin >> type;

        string task;
        cout << "Your Task : ";
        cin.ignore();
        getline(cin, task);

        int n;
        cout << "No. of SubTask : ";
        cin >> n;
        cin.ignore();
        string *sub = new string[n];
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ". -> ";
            getline(cin, sub[i]);
        }

        string hm;
        cout << "Hour/Min (hh:mm) : ";
        cin >> hm;

        istringstream ss1(hm);
        string hour_str, min_str;
        getline(ss1, hour_str, ':');
        getline(ss1, min_str, ':');

        int hr = stoi(hour_str);
        int min = stoi(min_str);

        Node *temp = new Node(type, task, n, sub, hr, min);

        if (days[dayno])
        {
            Node *curr = days[dayno];
            Node *prev = NULL;

            while (curr && days[dayno] && (hr > days[dayno]->hr || (hr == days[dayno]->hr && min > days[dayno]->mi)))
            {
                prev = curr;
                curr = curr->next;
            }

            if (prev)
            {
                prev->next = temp;
                temp->prev = prev;
                temp->next = curr;
                curr->prev = temp;
            }
            else
            {
                temp->next = days[dayno];
                days[dayno]->prev = temp;
                days[dayno] = temp;
            }
        }
        else
        {
            days[dayno] = temp;
        }
    }


    void Delete(int dayno,int idx=1)
    {
        int x=-1;
        Node *temp;
        
        if (idx == 1)
        {
            temp = days[dayno];
            days[dayno] = days[dayno]->next;
            if (days[dayno])
                days[dayno]->prev = NULL;
        }
        else
        {
            Node *p = days[dayno];
            for (int i = 1; i < idx - 1 && p; i++)
            {
                p = p->next;
            }
            if (p)
            {
                temp = p->next;
                p->next = temp->next;
                if (temp->next)
                    temp->next->prev = p;
            }
        }
        delete temp;
        
    }

    void Display(int dayIndex) {
        if (dayIndex >= 0 && dayIndex < 7) {
            Node* day = days[dayIndex];
            PrintDay(dayIndex);

            Node* p = day;
            while (p) {
                cout << "Time: " << p->hr << ":" << p->mi << endl;
                cout << "Task: " << p->task << endl;
                cout << "Type: " ;
                if(p->type=="W" || p->type=="w")
                    cout<<"Work "<<endl;
                else if (p->type=="P" || p->type=="p")
                    cout<<"Personal "<<endl;
                else
                    cout<<p->type<<endl;

                // Display subtasks if available
                if (p->subt != NULL) 
                {                    
                    cout << "Subtasks:\n";
                    for (int i = 0; i < p->n; ++i)
                    {
                        cout << i + 1 << ". -> " << p->subt[i] << endl;
                    }
                }
                cout << "-----------------------------\n";
                p = p->next;
            }
        } else {
            cout << "Invalid day index." << endl;
        }
    }

    void Latest(int dayIndex)
    {
        if (dayIndex >= 0 && dayIndex < 7)
            PrintDay(dayIndex);
        
        Node* day = days[dayIndex];
        std::pair<int, int> currentTime = getCurrentTime();

        int hour = currentTime.first;
        int minute = currentTime.second;

        Node *p = day;
        while(p && (hour > p->mi || (hour==p->hr && minute > p->mi)))
        {
            p=p->next;
        }

        if(p)
        {
            cout << "Time: " << p->hr << ":" << p->mi << endl;
            cout << "Task: " << p->task << endl;
            cout << "Type: " ;
            if(p->type=="W" || p->type=="w")
                cout<<"Work "<<endl;
            else if (p->type=="P" || p->type=="p")
                cout<<"Personal "<<endl;
            else
                cout<<p->type<<endl;

            // Display subtasks if available
            if (p->subt != NULL) {
                
                cout << "Subtasks:\n";
                for (int i = 0; i < p->n; ++i) { // Use p->n for the number of subtasks
                    cout << i + 1 << ". -> " << p->subt[i] << endl;
                }
            }

            cout << "-----------------------------\n";
        }
        else
        {
            cout<<"There is no Task left ."<<endl;
        }
    }

    
};


int main() 
{
    Week sam;
    int dayIndex = 0; // 0 corresponds to Monday

    while (true) {
        cout << "MENU:- " << endl;
        cout << "1. View Schedule" << endl;
        cout << "2. Add new Schedule" << endl;
        cout << "3. Delete Schedule" << endl;
        cout << "4. Latest Schedule" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter command : ";
        cin >> choice;

        switch (choice) {
            case 1:
                sam.Display(dayIndex);
                break;
            case 2:
                sam.Add(dayIndex);
                break;
            case 3:
                sam.Delete(dayIndex);
                break;
            case 4:
                sam.Latest(dayIndex);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid command. Please choose a valid option." << endl;
                break;
        }
    }

    return 0;
}

