#include <string>

class Class
{
private:
    std::string idClass;               // mã lớp
    std::string nameClass;             // têm lớp
    std::string *studentInClass;       // danh sách học sinh trong lớp
    std::string *subjectTaughtInClass; // danh sách môn học được dạy trong lớp

public:
    Class(std::string idClass, std::string nameClass, std::string *studentInClass, std::string *subjectTaughtInClass)
    {
        this->idClass = idClass;
        this->nameClass = nameClass;
        this->studentInClass = studentInClass;
        this->subjectTaughtInClass = subjectTaughtInClass;
    }
    std::string GetIdClass() const
    {
        return idClass;
    }

    void SetIdClass(std::string idClass)
    {
        idClass = idClass;
    }

    std::string GetNameClass() const
    {
        return nameClass;
    }

    void SetNameClass(std::string nameClass)
    {
        nameClass = nameClass;
    }

    std::string *GetStudentInClass() const
    {
        return studentInClass;
    }

    void SetStudentInClass(std::string *studentInClass)
    {
        studentInClass = studentInClass;
    }

    std::string *GetSubjectTaughtInClass() const
    {
        return subjectTaughtInClass;
    }

    void SetSubjectTaughtInClass(std::string *subjectTaughtInClass)
    {
        subjectTaughtInClass = subjectTaughtInClass;
    }
};