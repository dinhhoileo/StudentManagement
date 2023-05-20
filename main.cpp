#include <iostream>
#include <string>
#include <cstring>
#include "HashTable.cpp"

int main(int argc, char const *argv[])
{
    // khởi tạo một hash table
    HashTable hashtable(100);
    Student* newStudent = new Student;
    newStudent->putInformationStudent();
    while (true )
    {
        char choice;
        std::cout<<"Do you want exit (y/Y):";
        std::cin>>choice;
        
        // hashtable.addToStudentTable();

        // base case
        if (choice=='y'||choice =='Y')
        {
            break;
        }
    }
    return 0;
}
