#include "student.h"

int main()
{
    student s1;
    string s = "Truong Cao Hoang Gia,20120279,20/10/2002,8.5,7.0,9.0";
    s1.split_info(s);
    cout << s1;
    return 0;
}