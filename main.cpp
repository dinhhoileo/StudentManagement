#include <iostream>
#include <string>
#include <cstring>
#include "HashTable.cpp"

int main(int argc, char const *argv[])
{
    // khởi tạo một listStudent
    ListStudent listStudent;

    // Tạo một bảng băm với kích thước là 10
    HashTable hashTable(10);

    // Thêm sinh viên vào bảng băm
    hashTable.addStudentInTable(new Student("Nguyen Van A", "SV001", "01/01/2000", "Ha Noi", "nguyenvana@gmail.com", "0123456789", nullptr));
    hashTable.addStudentInTable(new Student("Tran Thi B", "SV002", "02/02/2001", "Ho Chi Minh", "tranthib@gmail.com", "0123456789", nullptr));
    hashTable.addStudentInTable(new Student("Pham Van C", "SV003", "03/03/2002", "Da Nang", "phamvanc@gmail.com", "0123456789", nullptr));

    hashTable.findStudent("Nguyen Van A");
    return 0;
}
