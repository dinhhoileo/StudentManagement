#include <iostream>
#include <string>
#include <cstring>
#include "HashTable.cpp"

int main(int argc, char const *argv[])
{
    ListStudent listStudent;
    ListSubject listSubject;
    ListClass   listClass;
    ListFaculty listFaculty;
    ListTerm    listTerm;
    
    HashTable hashTable(100);
    
    hashTable.addToClassToTable(new Student());

   
    return 0;
}
