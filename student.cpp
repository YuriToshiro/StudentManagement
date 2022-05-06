#include "student.h"

student::student()
{
    name = "";
    id = "";
    dob.d = dob.m = dob.y = 0;
    marks.reserve(3);
}

student::student(string name, string id, Date dob, vector<float> marks)
{
    this->name = name;
    this->id = id;
    this->dob = dob;
    this->marks = marks;
}

student::student(const student &s)
{
    name = s.name;
    id = s.id;
    dob = s.dob;
    marks = s.marks;
}

student::~student()
{
    // dtor
}

student &student::operator=(const student &s)
{
    if (this != &s)
    {
        name = s.name;
        id = s.id;
        dob = s.dob;
        marks = s.marks;
    }
    return *this;
}

student &student::split_info(string s)
{
    vector<string> buffer;
    s.push_back(',');
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ',')
        {
            buffer.push_back(s.substr(0, i));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    name = buffer[0];
    id = buffer[1];
    dob.d = stoi(buffer[2].substr(0, 2)); // format dd/mm/yyyy
    dob.m = stoi(buffer[2].substr(3, 2));
    dob.y = stoi(buffer[2].substr(6, 4));
    for (int i = 3; i < buffer.size(); ++i)
    {
        marks.push_back(stof(buffer[i]));
    }
    return *this;
}

float student::avg() const
{
    return marks[0] * 0.25 + marks[1] * 0.25 + marks[2] * 0.5;
}

ostream &operator<<(ostream &out, const student &s)
{
    out << "Name: " << s.name << endl;
    out << "ID: " << s.id << endl;
    out << "DOB: " << s.dob.d << "/" << s.dob.m << "/" << s.dob.y << endl;
    out << "Marks: ";
    for (int i = 0; i < s.marks.size(); ++i)
    {
        out << s.marks[i] << " ";
    }
    out << endl;
    out << "AVG: " << s.avg() << endl;
    return out;
}