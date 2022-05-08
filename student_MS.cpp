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

void studentMS::add() // add a new student in asscending order of ID
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
        while (i >= 0 && st.getID() <= students[i].getID())
        {
            i--;
        }
        students.insert(i + 1, st);
    }
}

void studentMS::remove(string id) // remove a student by ID
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

void studentMS::importFromList(string filename)
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

void studentMS::writeToList() // write back to student-list file
{
    ofstream f;
    f.open("studentList.txt");
    for (int i = 0; i < students.size(); i++)
    {
        f << students[i] << endl;
    }
    f.close();
}

float studentMS::avg_class() // calculate average mark of all students
{
    float sum = 0;
    for (int i = 0; i < students.size(); i++)
    {
        sum = sum + students[i].avg();
    }
    float avg = sum / students.size();
    return avg;
}

void studentMS::output_avg() // write students info have average marks smaller than average mark of all students
{
    ofstream f;
    f.open("studentList_avg.txt");
    float avg_cl = avg_class();
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].avg() < avg_cl)
        {
            f << students[i] << "," << students[i].avg() << endl;
        }
    }
    f.close();
}

void studentMS::display() // display all students to screen
{
    for (int i = 0; i < students.size(); i++)
    {
        students[i].display();
        cout << "Rank: " << classify(students[i].avg()) << endl;
        cout << "-----------------------------" << endl;
    }
}

string studentMS::classify(const float avg) // classfy student by average mark
{
    if (avg < 3)
    {
        return "F";
    }
    else if (avg >= 3 && avg < 5)
    {
        return "D";
    }
    else if (avg >= 5 && avg < 6)
    {
        return "C";
    }
    else if (avg >= 6 && avg < 8)
    {
        return "B";
    }
    else if (avg >= 8 && avg <= 10)
    {
        return "A";
    }
    else
    {
        return "NA";
    }
}

void studentMS::output_rank() // write students info with their ranks
{
    ofstream f;
    f.open("studentList_rank.txt");
    for (int i = 0; i < students.size(); i++)
    {
        f << students[i] << "," << classify(students[i].avg()) << endl;
    }
    f.close();
}