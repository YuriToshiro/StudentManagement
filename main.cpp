#include "student_MS.h"
#include <iomanip>
int main()
{
    system("color 70");
    studentMS sm;
    int option = 1;
    string id;
    do
    {
        cout << setw(90) << "*************************************************************" << endl;
        cout << setw(90) << "*           1. Doc danh sach SV tu tap tin                  *" << endl;
        cout << setw(90) << "*           2. Ghi danh sach SV vao tap tin                 *" << endl;
        cout << setw(90) << "*           3. Them mot SV vao sanh sach                    *" << endl;
        cout << setw(90) << "*           4. Xoa mot SV khoi danh sach                    *" << endl;
        cout << setw(90) << "*           5. Tim 1 SV theo MSSV                           *" << endl;
        cout << setw(90) << "*           6. Xuat danh sach SV co DTB thap hon DTB tong   *" << endl;
        cout << setw(90) << "*           7. Xuat danh sach SV co thong tin xep loai      *" << endl;
        cout << setw(90) << "*           8. Xuat danh sach SV ra man hinh                *" << endl;
        cout << setw(90) << "*           0. Ket thuc                                     *" << endl;
        cout << setw(90) << "*************************************************************" << endl;
        cout << "Nhap lua chon: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            fstream f;
            f.open("studentList.txt", ios_base::in);
            if (!f.fail())
            {
                sm.importFromList("studentList.txt");
                sm.sortByID();
                cout << "Da doc du lieu tu file studentList.txt" << endl;
            }
            else
            {
                cout << "File studentList.txt khong ton tai!" << endl;
            }
            f.close();
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            sm.writeToList();
            cout << "Da ghi du lieu vao file studentList.txt" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            sm.add();
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            cout << "Nhap MSSV can xoa: ";
            cin >> id;
            sm.remove(id);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            cout << "Nhap MSSV can tim: ";
            cin >> id;
            student *temp = sm.findByID(id);
            if (temp != nullptr)
                temp->display();
            else
                cout << "Khong tim thay SV co MSSV " << id << " trong danh sach!!!" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            sm.output_avg();
            cout << "Da ghi danh sach vao file studentList_avg.txt" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            sm.output_rank();
            cout << "Da ghi danh sach vao file studentList_rank.txt" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            sm.display();
            system("pause");
            system("cls");
        }
        case 0:
            break;
        default:
        {
            cout << "Lua chon khong hop le" << endl;
            system("pause");
            system("cls");
            break;
        }
        }

    } while (option != 0);
    return 0;
}