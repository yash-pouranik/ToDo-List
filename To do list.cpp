#include <iostream>
using namespace std;

string tasks[10];
int i = 0; // stores index of current task+1

string newtaskk() {
    cin.ignore(); 
    string newtask;
    cout << "Enter New Task: ";
    getline(cin, newtask);
    return newtask;
}

void dlt(int a) {
    for(int j = a-1; j < i-1; j++) {
        tasks[j] = tasks[j+1];
    }
    i--; 
}

void viewtaskk(int a) {
    if (a >= 1 && a <= i) {
        cout << tasks[a-1] << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
    cout << endl;
}

void marktaskk(int a) {
    tasks[a-1] += " (DONE!)";
}

int main() {
    int n; // for choosing task
    do {
        cout << "1. Add task." << endl;
        cout << "2. Delete task." << endl;
        cout << "3. View task." << endl;
        cout << "4. Mark task as Done." << endl;
        cout << "Select from 1-4: ";
        cin >> n;
        cout<<endl;

        switch(n) {
            case 1:
                if (i == 10) {
                    cout << "Can't add more task :(" << endl;
                    break;
                }
                tasks[i] = newtaskk();
                i++;
                cout<<"Task Added"<<endl;
                cout<<endl;
                break;
            case 2:
                int tasknum;
                cout << "Which task to be deleted? ";
                cin >> tasknum;
                dlt(tasknum);
                cout<<"Task Deleted"<<endl;
                cout<<endl;
                break;
            case 3:
                cout<<"If you want to view all tasks press 0"<<endl;
                int viewtask;
                cout << "Which task you want to see? ";
                cin >> viewtask;
                if(viewtask == 0){
                    for(int m = 0; m<i; m++){
                        cout<<tasks[m]<<endl;
                    }
                    cout<<endl;
                    break;
                }
                else if(viewtask > i){
                    cout<<"Ivalid Input :("<<endl;
                    cout<<endl;
                    break;
                }
                viewtaskk(viewtask);
                cout<<endl;
                break;
            case 4:
                if (i == 0) {
                    cout << "No task is added yet :(" << endl;
                    cout<<endl;
                    break;
                }
                int marktask;
                cout << "Which task has to be marked as done? ";
                cin >> marktask;
                marktaskk(marktask);
                cout<<"Marked as Done"<<endl;
                cout<<endl;
                break;
            case 0:
                cout << "Hare Krishna! Let's end :)" << endl;
                break;
        }
    } while(n != 0);

    return 0;
}

