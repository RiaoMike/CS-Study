#include "manager.h"

Manager::Manager(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showInfo(){
    cout << "Id: " << this->m_Id
         << "\tName: " << this->m_Name
         << "\tDept Id: " << this->getDeptName()
         << "\tDuty: Complete the tasks that boss gives, and allot tasks to the employees." << endl;
}

string Manager::getDeptName(){
    return string("Manager");
}