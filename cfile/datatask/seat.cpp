#include<iostream>
#include<string>
using namespace std;

int totalNumber = 0;
struct Seat{
    string name;
    int number;
};
Seat* seat[50];

void design() {
    // total number less than or equal to 50
    if (totalNumber == 50){
        cout << "room full" << endl;
    }
    cout << "Please enter the name: " << endl;
    string s;
    cin >> s;
    Seat * newStudent = new Seat;
    newStudent->name = s;
    newStudent->number = totalNumber;

    seat[totalNumber] = newStudent;
    cout << s << "同学的座位号为： " << newStudent->number << endl; 

    totalNumber++;
}

void find(){
    cout << "Please enter the Number: " << endl;
    int n;
    cin >> n;
    for (int i = 0;i<totalNumber; i++){
        if (seat[i]->number == n){
            cout << "Name is: " << seat[i]->name << endl;
        }
    }
}

void swap(int m, int n){
    if (m >= totalNumber || m < 0 || n >= totalNumber || n < 0){
        cout << "Input error, no such student!" << endl;
    }
    else{
        string tmp = seat[m]->name;
        seat[m]->name = seat[n]->name;
        seat[n]->name = tmp; 
        cout << "Swap Successfully!" << endl;
    }
}

void display(){
    for (int i = 0; i < totalNumber; i++){
        cout << "Seat Number: " << seat[i]->number << "\t"
             << "Name: " << seat[i]->name << endl;
    }
}

void leave(){
    cout << "Please enter the number where student leaves: " << endl;
    int n;
    cin >> n;
    // check if there any student sit here
    if (n < 0 || n >= totalNumber){
        cout << "Student does not exists!" << endl;
    }
    else {
        delete seat[n];
        for (int i = n; i < totalNumber - 1; i++){
            seat[i] = seat[i+1];
            // 每个学生座位前移一个
            seat[i]->number--;
        }
        totalNumber--;
        cout << "Delete Successfully!" << endl;
    }
}

void add(){
    if (totalNumber == 50){
        cout << "room full" << endl;
        return;
    }
    cout << "Please enter the number and name of new student: " << endl;
    int n;
    string s;
    cin >> n >> s;
    Seat* newStudent = new Seat;
    newStudent->number = n;
    newStudent->name = s;
    if (n >= totalNumber){
        newStudent->number = totalNumber;
        seat[totalNumber] = newStudent;
    }
    else {
        for (int i = totalNumber; i > n; i--){
            seat[i] = seat[i-1];
            // every student move backford
            seat[i]->number++;
        }
        seat[n] = newStudent;
    }
    cout << "Added Successfully!" << endl;
    // total number added one
    totalNumber++;
}

int main(){

    bool flag = true;
    while(flag){
        cout << "Please enter what you want to do: " << endl;
        cout << "1. Add new student" << endl;
        cout << "2. Find a student" << endl;
        cout << "3. Swap two student" << endl;
        cout << "4. Display all students" << endl;
        cout << "5. Delete a student" << endl;
        cout << "6. Add a new student" << endl;
        cout << "0. Quit the program" << endl;


        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                design();
                break;
            case 2:
                find();
                break;
            case 3:{
                cout << "Please enter two number: " << endl;
                int m = 0,n = 0;
                cin >> m >> n;
                swap(m,n);
                break;
            }
            case 4:
                display();
                break;
            case 5:
                leave();
                break;
            case 6:
                add();
                break;
            case 0:
                flag = false;
                break;
            default:{
                break;
            }
        }
        if (choice != 0)
            // press ENTER key to continue
            system("read");
        // clear the screen
        system("clear");
    }

    // free all space
    for (int i = 0; i < totalNumber; i++){
        delete seat[i];
    }
    return 0;
}