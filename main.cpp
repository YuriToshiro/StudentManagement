#include "student_MS.h"

int main()
{
    studentMS sm;
    sm.inputdata("studentlist.txt");
    sm.sortByID();
    sm.remove("20120279");
    sm.output();
    return 0;
}