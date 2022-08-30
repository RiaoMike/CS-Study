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
                << "dept name: " << this->m_EmpArray[i]->m_DeptId << endl;
        }
    }
}

void WorkerManager::showMenu(){
    cout << "********************************************************" << endl;
    cout << "***********  Welcome to WorkerManager System  **********" << endl;
    cout << "***************  0.Quit Manager System  ****************" << endl;
    cout << "***************  1.Add Worker Information  *************" << endl;
    cout << "***************  2.Display Worker Information  *********" << endl;
    cout << "***************  3.Delete Worker  **********************" << endl;
    cout << "***************  4.Change Worker Information  **********" << endl;
    cout << "***************  5.Search Worker Information  **********" << endl;
    cout << "***************  6.Sort by Number  *********************" << endl;
    cout << "***************  7.Clear all Information  **************" << endl;
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
    
        // delete old array
        delete [] this->m_EmpArray;

        // pointing to new array
        this->m_EmpArray = newSpace;

        for (int i = 0; i < addNum; ++i){
            int id;
            string name;
            int did;


            cout << "Please enter the id of the " << i + 1 << "th new worker: " << endl;
            cin >> id;
            // !!! prevent to add same ID
            // enter again if id already exists
            while (isExists(id) != -1){
                cout << "ID has already exists! Please enter again: " << endl;
                cin >> id;
            }

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

            this->m_EmpArray[this->m_EmpNum] = p;
            this->m_EmpNum++;
        }
        
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
    }
    system("read");
    system("clear");
}

void WorkerManager::delEmp(){
    if (this->m_FileIsEmpty){
        cout << "File not exists or empty!" << endl;
    }
    else {
        cout << "Please enter the worker ID you want to delete: " << endl;
        int id;
        cin >> id;

        int index = this->isExists(id);
        if (index != -1){
            for (int i = index + 1; i < this->m_EmpNum; ++i){
                this->m_EmpArray[i-1] = this->m_EmpArray[i];
            }
            this->m_EmpNum--;
            this->save();
            cout << "Delete successfully!" << endl;
        }
        else {
            cout << "ID not Exists!" << endl;
        }
    }
    system("read");
    system("clear");
}

// return index if worker exists and return -1 if not
int WorkerManager::isExists(int id){
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; ++i){
       if (this->m_EmpArray[i]->m_Id == id){
           index = i;
           break;
       } 
    }
    return index;
}

void WorkerManager::modEmp(){
    if (this->m_FileIsEmpty){
        cout << "File not exists or empty!" << endl;
    }
    else {
        cout << "Please enter the worker ID that you want to change: " << endl;
        int id;
        cin >> id;

        int index = this->isExists(id);
        if (index != -1){
            int newId = 0;
            string newName = "";
            int newDid = 0;

            cout << "Find the worker whose ID is " << id << ": " << endl;
            this->m_EmpArray[index]->showInfo();
            
            cout << "Please enter the new ID: " << endl;
            cin >> newId;

            cout << "Please enter the new Name: " << endl;
            cin >> newName;

            cout << "Please enter the new Dept name: " << endl
                 << "1. Employee" << endl
                 << "2. Manager" << endl
                 << "3. Boss" << endl;
            cin >> newDid;

            Worker *worker = NULL;
            switch (newDid){
                case 1:
                    worker = new Employee(newId, newName, newDid);
                    break;
                case 2:
                    worker = new Manager(newId, newName, newDid);
                    break;
                case 3:
                    worker = new Boss(newId, newName, newDid);
                    break;
                default:
                    break;
            }
            
            // delete the worker
            delete this->m_EmpArray[index];

            // add the modified worker
            this->m_EmpArray[index] = worker;

            this->save();
            cout << "Successfully modified." << endl;
        }
        else {
            cout << "ID not Exists!" << endl;
        }
    }

    system("read");
    system("clear");
}

WorkerManager::~WorkerManager(){
    if (this->m_EmpArray != NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}