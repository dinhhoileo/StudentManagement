#include <iostream>
#include <string>
#include <cstring>
#include <vector>
// HỌC SINH
class Student
{
private:
    std::string fullName;            // họ và tên
    std::string ID;                  // mã số sinh viên
    std::string dateOfBirth;         // ngày sinh
    std::string address;             // địa chỉ
    std::string email;               // thư điện tử email
    std::string phoneNumber;         // số điện thoại
    std::string *registeredSubjects; // danh sách môn học đã đăng ký
public:
    // constructor
    Student(std::string fullName, std::string ID, std::string dateOfBirth, std::string address, std::string email, std::string phoneNumber, std::string *registeredSubjects)
    {
        this->fullName = fullName;
        this->ID = ID;
        this->dateOfBirth = dateOfBirth;
        this->address = address;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->registeredSubjects = registeredSubjects;
    }
    std::string GetFullName() const { return this->fullName; }
    void SetFullName(std::string fullName) { this->fullName = fullName; }

    std::string GetID() const { return this->ID; }
    void SetID(std::string ID) { this->ID = ID; }

    std::string GetDateOfBirth() const { return this->dateOfBirth; }
    void SetDateOfBirth(std::string dateOfBirth) { this->dateOfBirth = dateOfBirth; }

    std::string GetAddress() const { return this->address; }
    void SetAddress(std::string address) { this->address = address; }

    std::string GetEmail() const { return this->email; }
    void SetEmail(std::string email) { this->email = email; }

    std::string GetPhoneNumber() const { return this->phoneNumber; }
    void SetPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }

    std::string *GetRegisteredSubjects() const { return this->registeredSubjects; }
    void SetRegisteredSubjects(std::string *registeredSubjects) { this->registeredSubjects = registeredSubjects; }
};
// MÔN HỌC
class Subject
{
private:
    std::string nameSubject;           // tên môn học
    std::string IdSubject;             // mã môn học
    int numberOfCredits;               // số tín chỉ
    Student *registeredStudentSubject; // sinh viên đã đăng ký

public:
    // constructor
    Subject(std::string nameSubject, std::string IdSubject, int numberOfCredis, Student *registeredStudentSubject)
    {
        this->nameSubject = nameSubject;
        this->IdSubject = IdSubject;
        this->numberOfCredits = numberOfCredis;
        this->registeredStudentSubject = registeredStudentSubject;
    }
    std::string GetNameSubject() const { return this->nameSubject; }
    void SetNameSubject(std::string nameSubject) { this->nameSubject = nameSubject; }

    std::string GetIdSubject() const { return this->IdSubject; }
    void SetIdSubject(std::string IdSubject) { this->IdSubject = IdSubject; }

    int GetNumberOfCredits() const { return this->numberOfCredits; }
    void SetNumberOfCredits(int numberOfCredits) { this->numberOfCredits = numberOfCredits; }

    Student *GetRegisteredStudentSubject() const { return this->registeredStudentSubject; }
    void SetRegisteredStudentSubjects(Student *registeredStudentSubjects) { this->registeredStudentSubject = registeredStudentSubjects; }
};

// LỚP
class Class
{
private:
    std::string idClass;           // mã lớp
    std::string nameClass;         // têm lớp
    Student *studentInClass;       // danh sách học sinh trong lớp
    Subject *subjectTaughtInClass; // danh sách môn học được dạy trong lớp

public:
    Class(std::string idClass, std::string nameClass, Student *studentInClass, Subject *subjectTaughtInClass)
    {
        this->idClass = idClass;
        this->nameClass = nameClass;
        this->studentInClass = studentInClass;
        this->subjectTaughtInClass = subjectTaughtInClass;
    }
    std::string GetIdClass() const { return idClass; }
    void SetIdClass(std::string idClass) { this->idClass = idClass; }

    std::string GetNameClass() const { return nameClass; }
    void SetNameClass(std::string nameClass) { this->nameClass = nameClass; }

    Student *GetStudentInClass() const { return studentInClass; }
    void SetStudentInClass(Student *studentInClass) { this->studentInClass = studentInClass; }

    Subject *GetSubjectTaughtInClass() const { return subjectTaughtInClass; }
    void SetSubjectTaughtInClass(Subject *subjectTaughtInClass) { this->subjectTaughtInClass = subjectTaughtInClass; }
};
// KHOA
class Faculty
{
private:
    std::string nameFaculty;   // têm khoa
    std::string idFaculty;     // mã khoa
    Class *listClassOfFaculty; // danh sách lớp thuộc khoa đó

public:
    Faculty(std::string nameFaculty, std::string idFaculty, Class *listClassOfFaculty)
    {
        this->nameFaculty = nameFaculty;
        this->idFaculty = idFaculty;
        this->listClassOfFaculty = listClassOfFaculty;
    }
    std::string GetNameFaculty() const { return nameFaculty; }
    void SetNameFaculty(std::string nameFaculty) { this->nameFaculty = nameFaculty; }

    std::string GetIdFaculty() const { return idFaculty; }
    void SetIdFaculty(std::string idFaculty) { this->idFaculty = idFaculty; }

    Class *GetListOfFaculty() const { return listClassOfFaculty; }
    void SetListOfFaculty(Class *listClassOfFaculty) { this->listClassOfFaculty = listClassOfFaculty; }
};

// HỌC KỲ
class Term
{
private:
    std::string idTerm;     // mã học kỳ
    std::string nameTerm;   // tên học kỳ
    Class *listClassInTerm; // danh sách các lớp học trong một học kỳ

public:
    // constructor
    Term(std::string idTerm, std::string nameTerm, Class *listClassInTerm)
    {
        this->idTerm = idTerm;
        this->nameTerm = nameTerm;
        this->listClassInTerm = listClassInTerm;
    }
    std::string GetIdTerm() const
    {
        return idTerm;
    }

    void SetIdTerm(std::string idTerm)
    {
        this->idTerm = idTerm;
    }

    std::string GetNameTerm() const
    {
        return nameTerm;
    }

    void SetNameTerm(std::string nameTerm)
    {
        this->nameTerm = nameTerm;
    }

    Class *GetListClassInTerm() const
    {
        return listClassInTerm;
    }

    void SetListClassInTerm(Class *listClassInTerm)
    {
        this->listClassInTerm = listClassInTerm;
    }
};

