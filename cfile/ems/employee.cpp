#include "employee.h"

Employee::Employee(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo(){
    cout << "Id: " << this->m_Id
         << "\tName: " << this->m_Name
         << "\tDept Name: " << this->getDeptName()
         << "\tDuty: Complete the tasks that manager gives." << endl;
}

string Employee::getDeptName(){
    return string("Employee");
}