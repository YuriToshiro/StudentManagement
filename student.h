#ifndef STUDENT_H
#define STUDENT_H
#include "vector.h"
#include <fstream>

struct Date
{
    int d; // day
    int m; // month
    int y; // year
};

class student
{
private:
    string name;
    string id;
    Date dob; // date of birth
    vector<float> marks;

public:
    // constructor, destructor
    student();
    student(string name, string id, Date dob, vector<float> marks);
    student(const student& s);
    ~student();
    student& operator=(const student& s);

    // get input from a string
    student& split_info(string s);

    // get input from keyboard
    void inputFromKeyboard();

    // write output
    friend ostream& operator<<(ostream& out, const student& s);
    void display();

    // get methods
    string getName() const;
    string getID() const;
    Date getDOB() const;

    // calculate average mark
    float avg() const;
};

#endif // STUDENT_H