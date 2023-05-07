#include <string>

class Subject
{
private:
    std::string nameSubject; // tên môn học
    std::string IdSubject;   // mã môn học
    int numberOfCredits;     // số tín chỉ
    std::string *registeredStudents;    // sinh viên đã đăng ký


public:
    // constructor
    Subject(std::string nameSubject, std::string IdSubject, int numberOfCredis, std::string *registeredStudents);
    std::string GetNameSubject() const
    {
        return this->nameSubject;
    }

    void SetNameSubject(std::string nameSubject)
    {
        nameSubject = nameSubject;
    }

    std::string GetIdSubject() const
    {
        return this->IdSubject;
    }

    void SetIdSubject(std::string IdSubject)
    {
        IdSubject = IdSubject;
    }

    int GetNumberOfCredits() const
    {
        return this->numberOfCredits;
    }

    void SetNumberOfCredits(int numberOfCredits)
    {
        numberOfCredits = numberOfCredits;
    }

    std::string *GetRegisteredStudents() const
    {
        return this->registeredStudents;
    }

    void SetRegisteredStudents(std::string *registeredStudents)
    {
        registeredStudents = registeredStudents;
    }
};
