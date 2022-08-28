#include "workerManager.h"

WorkerManager::WorkerManager(){
    // file initial
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // file not exists
    if (!ifs.is_open()){
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // file exists but has no data
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    ifs.close();
    
    // file exists and has data
    this->m_EmpNum = this->getEmpNum();
    
    this->initArray();

    this->m_FileIsEmpty = false;

    // for testing
    if (1 == 0){
        for (int i = 0; i < this->m_EmpNum; ++i){
            cout << "id: " << this->m_EmpArray[i]->m_Id << " "
                << "name: " << this->m_EmpArray[i]->m_Name << " "
                << "dept id: " << this->m_EmpArray[i]->m_DeptId << endl;
        }
    }
}

void WorkerManager::showMenu(){
    cout << "********************************************************" << endl;
    cout << "*************Welcome to WorkerManager System************" << endl;
    cout << "**************** 0.Quit Manager System *****************" << endl;
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
        
        // save the employee info 
        this->save();

        // flag that file not empty
        this->m_FileIsEmpty = false;

        // prompt
        cout << "Successfully added " << addNum << " new workers!" << endl;
    }
    else{
        cout << "Input Error!!!";
    }
    // press EMTER key to continue
    system("read");
    system("clear");
}

void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    Worker ** tmp;
    for (int i = 0; i < this->m_EmpNum; ++i){
        tmp = this->m_EmpArray;
        ofs << tmp[i]->m_Id << " "
            << tmp[i]->m_Name << " "
            << tmp[i]->m_DeptId << endl;
    }

    ofs.close();
}

int WorkerManager::getEmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int EmpNum = 0;
    while (ifs >> id && ifs >> name && ifs >> did){
        EmpNum++;
    }

    ifs.close();
    return EmpNum;
}

void WorkerManager::initArray(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    this->m_EmpArray = new Worker *[this->m_EmpNum];
    int id;
    string name;
    int did;

    for (int i = 0; i < this->m_EmpNum; ++i){
        Worker *p = NULL;
        ifs >> id >> name >> did;
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
        }
        this->m_EmpArray[i] = p;
    }
    ifs.close();
}

void WorkerManager::showEmp(){
    if ( this->m_FileIsEmpty ){
        cout << "File not exists or empty!" << endl;
    }
    else{
        for (int i = 0; i < this->m_EmpNum; ++i){
            this->m_EmpArray[i]->showInfo();
        }
        system("read");
        system("clear");
    }
}

WorkerManager::~WorkerManager(){
    if (this->m_EmpArray != NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}