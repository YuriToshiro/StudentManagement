#include "student_MS.h"

int main()
{
    studentMS sm;
    sm.importFromList("studentList.txt");
    sm.sortByID();
    sm.remove("20120279");
    sm.output_avg();
    sm.output_rank();
    sm.display();
    return 0;
}