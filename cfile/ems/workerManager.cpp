#include "workerManager.h"

WorkerManager::WorkerManager(){
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

void WorkerManager::showMenu(){
    cout << "********************************************************" << endl;
    cout << "*************Welcome to WorkerManager System************" << endl;
    cout << "**************** 0.Quit Manager System ****************" << endl;
    cout << "**************** 1.Add Worker Information **************" << endl;
    cout << "**************** 2.Display Worker Information **********" << endl;
    cout << "**************** 3.Delete Worker ***********************" << endl;
    cout << "**************** 4.Change Worker Information ***********" << endl;
    cout << "**************** 5.Search Worker Information ***********" << endl;
    cout << "**************** 6.Sort by Number **********************" << endl;
    cout << "**************** 7.Clear all Information ***************" << endl;
    cout << "********************************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem(){
    cout << "Welcome to use next time." << endl;
    exit(0);
}

void WorkerManager::addEmp(){

    cout << "Please enter the number you want to add: " << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0){
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker *[newSize];

        if (this->m_EmpArray != NULL){
            for (int i = 0; i < this->m_EmpNum; ++i){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        for (int i = 0; i < addNum; ++i){
            int id;
            string name;
            int did;

            cout << "Please enter the id of the " << i + 1 << "th new worker: " << endl;
            cin >> id;

            cout << "Please enter the name of the " << i + 1 << "th new worker: " << endl;
            cin >> name;

            cout << "Please choose the dept of the new worker: " << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Boss" << endl;
            cin >> did;

            Worker *p = NULL;
            while (p == NULL){
                switch (did){
                    case 1:
                        p = new Employee(id, name, did);
                        break;
                    case 2:
                        p = new Manager(id, name, did);
                        break;
                    case 3:
                        p = new Boss(id, name, did);
                        break;
                    default:
                        cout << "Error! Please enter again." << endl;
                        cin >> did;
                        break;
                }
            }

            newSpace[this->m_EmpNum + i] = p;
        }
        // delete old array
        delete [] this->m_EmpArray;

        // pointing to new array
        this->m_EmpArray = newSpace;

        // update worker numbers
        this->m_EmpNum = newSize;

        // prompt
        cout << "Successfully added " << addNum << " new workers!" << endl;
    }
    else{
        cout << "Input Error!!!";
    }
    system("sleep 3");
    system("clear");
}

WorkerManager::~WorkerManager(){

}