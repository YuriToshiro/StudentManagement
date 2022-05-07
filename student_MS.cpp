#include "student_MS.h"

studentMS::studentMS()
{
    // default ctor
}

studentMS::studentMS(vector<student> &s)
{
    students = s;
}

studentMS::studentMS(const studentMS &s)
{
    students = s.students;
}

studentMS::~studentMS()
{
    // default dtor
}

void studentMS::add()
{
    student st;
    st.inputFromKeyboard();
    if (st.getID() > students.back().getID())
    {
        students.push_back(st);
    }
    else
    {
        int i = students.size() - 1;
        while (i >= 0 && st.getID() < students[i].getID())
        {
            i--;
        }
        students.insert(i + 1, st);
    }
}

void studentMS::remove(string id)
{
    int l = 0;
    int r = students.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (students[mid].getID() == id)
        {
            students.erase(mid);
        }
        else if (students[mid].getID() < id)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}

student *studentMS::findByID(string id)
{
    int l = 0;
    int r = students.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (students[mid].getID() == id)
        {
            return &students[mid];
        }
        else if (students[mid].getID() < id)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return nullptr;
}

void studentMS::sortByID()
{
    for (int i = 1; i < students.size(); i++)
    {
        student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].getID() > key.getID())
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void studentMS::inputdata(string filename)
{
    ifstream f;
    f.open(filename);
    string s;
    while (!f.eof())
    {
        getline(f, s);
        if (s.size() > 0)
        {
            student st;
            st.split_info(s);
            students.push_back(st);
        }
    }
    f.close();
}

void studentMS::output()
{
    ofstream f;
    f.open("studentList.txt");
    for (int i = 0; i < students.size(); i++)
    {
        f << students[i] << endl;
    }
    f.close();
}

float studentMS::avg_class()
{
    float sum = 0;
    for (int i = 0; i < students.size(); i++)
    {
        sum = sum + students[i].avg();
    }
    float avg = sum / students.size();
    return avg;
}

void studentMS::output_avg()
{
    ofstream f;
    f.open("studentList_avg.txt");
    float avg_cl = avg_class();
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].avg() < avg_cl)
        {
            f << students[i] << endl;
        }
    }
    f.close();
}

void studentMS::display()
{
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i] << endl;
    }
}