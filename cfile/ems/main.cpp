#include "workerManager.h"

int main(){
    
    // // test code
    // Worker *p1 = new Employee(1, "hao", 1);
    // p1->showInfo(); 
    // Worker *p2 = new Manager(2, "yu", 2);
    // p2->showInfo();
    // Worker *p3 = new Boss(3, "rui", 3);
    // p3->showInfo();
    // delete p1;
    // delete p2;
    // delete p3;
    
    WorkerManager wm;
    int choice = 0;

    while (true){
        wm.showMenu();

        cout << "Please enter your choice: " << endl;
        cin >> choice;

        switch (choice){
            case 0: 
                wm.exitSystem();
                break;
            case 1:
                wm.addEmp();
                break;
            case 2:
                wm.showEmp();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("clear");
                break;
        }
    }

    return 0;
    
}