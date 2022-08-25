#include "boss.h"

Boss::Boss(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo(){
    cout << "Id: " << this->m_Id
         << "\tName: " << this->m_Name
         << "\tDept Id: " << this->getDeptName()
         << "   \tDuty: Manage all affairs about enterprise." << endl;
}

string Boss::getDeptName(){
    return string("Boss");
}