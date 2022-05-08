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

student &student::split_info(string s) // split info from a formatted string
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

void student::inputFromKeyboard()
{
    cout << "Input name: ";
    getline(cin, name);
    cout << "Input id: ";
    cin >> id;
    cout << "Input date of birth (dd/mm/yyyy): ";
    char c;
    cin >> dob.d >> c >> dob.m >> c >> dob.y;
    cout << "Input marks: ";
    float m;
    for (int i = 0; i < 3; ++i)
    {
        cin >> m;
        marks.push_back(m);
    }
}

float student::avg() const // calculate average mark
{
    return marks[0] * 0.25 + marks[1] * 0.25 + marks[2] * 0.5;
}

void student::display() // display student info to screen
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "DOB: ";
    if (dob.d < 10)
    {
        cout << "0";
    }
    cout << dob.d << "/";
    if (dob.m < 10)
    {
        cout << "0";
    }
    cout << dob.m << "/" << dob.y << endl;
    cout << "Marks: ";
    for (int i = 0; i < marks.size(); ++i)
    {
        cout << marks[i] << " ";
    }
    cout << endl;
    cout << "AVG: " << avg() << endl;
}

ostream &operator<<(ostream &out, const student &s) // overload output operator
{
    out << s.name << "," << s.id << ",";
    if (s.dob.d < 10)
    {
        out << "0";
    }
    out << s.dob.d << "/";
    if (s.dob.m < 10)
    {
        out << "0";
    }
    out << s.dob.m << "/" << s.dob.y << ",";
    out << s.marks[0] << "," << s.marks[1] << "," << s.marks[2];
    return out;
}

string student::getName() const
{
    return name;
}

string student::getID() const
{
    return id;
}

Date student::getDOB() const
{
    return dob;
}