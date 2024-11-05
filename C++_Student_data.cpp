#include <iostream>
#include <string>

using namespace std;

class College
{
private:
    string name;
    int reg_no;
    int age[3];
    string Parentage;
    int roll_no;
    string sem;
    int attendance;
    float marks[5];
    int total;

public:
    College() : name(""), reg_no(0), Parentage(""), roll_no(0), sem(""), attendance(0), total(0)
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = 0.0;
            if (i < 3)
            {
                age[i] = 0;
            }
        }
    }

    /*Get Details Start*/

    void get_details()
    {
        cout << "Enter Your Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Your Registration Number : ";
        cin >> reg_no;
        int num = 0;
        while (1)
        {

            cout << "Enter Your Age (DD MM YYYY) Remember There is space between DD and MM and YYYY :";
            cin >> age[0];
            cin >> age[1];
            cin >> age[2];
            if (age[0] != 0 && age[1] != 0 && age[2] != 0)
            {
                break;
            }
            else if (num > 1)
            {
                cout << "You have entered wrong format 2 times so now by default your age is 0\n";
                age[0] = 0;
                age[1] = 0;
                age[2] = 0;
                break;
            }
            else
            {
                cout << "Enter Valid Format \n";
            }
            num++;
        }

        cout << "Enter Your Parentage (Either Mother/Father/Gaurdian) : ";
        cin.ignore();
        getline(cin, Parentage);
        cout << "Enter Your Class Roll Number : ";
        cin >> roll_no;
        cout << "Enter Your Semester : ";
        cin >> sem;
        while (1)
        {
            cout << "Enter  Attendance( 1 for Present and 0 for Absent) : ";
            cin >> attendance;
            if (attendance == 1 || attendance == 0)
            {
                break;
            }
            else
            {
                cout << "Wrong! Enter only 1 or 0\n";
            }
        }
        for (int i = 0; i < 5; i++)
        {

            int num = 0;
            while (1)
            {

                cout << "Enter marks of " << i + 1 << "th Subject (Max-Marks=100) : ";
                cin >> marks[i];
                if (marks[i] <= 100 && marks[i] >= 0)
                {
                    break;
                }
                if (num > 0)
                {
                    cout << "You have entered wrong marks 2 times so now by default your marks is 0\n";
                    marks[i] = 0;
                    break;
                }

                if (marks[i] > 100 || marks[i] < 0)
                {
                    cout << "Please Enter Marks between 0 to 100\n";
                    num++;
                }
            }
        }
        total++;
    }
    /*Get Details End*/

    /*Show Details Start*/

    void show_details()
    {
        cout << "Student Details \n";
        cout << "Name : " << name << endl;
        cout << "Registration Number : " << reg_no << endl;
        cout << "Age : " << age[0] << "/" << age[1] << "/" << age[2] << endl;
        cout << "Parentage : " << Parentage << endl;
        cout << "Roll Number : " << roll_no << endl;
        cout << "Semester : " << sem << endl;
        cout << "Attendance : " << attendance << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i << "th Subject Marks : " << marks[i] << endl;
        }
    }
    /*Show Details End*/

    /*SHOW Name Start*/
    void show_name()
    {
        cout << "Name: " << name << endl;
    }
    /*SHOW Name End*/

    /*SHOW Roll Number Start*/
    void show_rollno()
    {
        cout << "Roll Number: " << roll_no << endl;
    }
    /*SHOW Roll Number End*/

    /*SHOW Attendance Start*/
    void show_attendance()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Attendance: " << attendance << endl;
    }
    /*SHOW Attendance  End*/

    /*Add Attendance Start*/
    float add_attendance()
    {
        int present;
        cout << "Name: " << name << "   " << "Roll Number" << roll_no << endl;
        cout << "Enter 1 or 0 to add  attendance (1 for Present, 0 for Absent): ";
        cin >> present;
        if (present != 1 && present != 0)
        {
            return add_attendance();
        }

        if (present == 1)
        {
            attendance += 1;
        }
        total++;

        return 0.0;
    }

    /*Add Attendance End*/

    /*SHOW Shortage Start*/
    void show_shortage()
    {
        float attendance_percentage = ((float)attendance / total) * 100;
        if (attendance_percentage < 75)
        {
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << roll_no << endl;
            cout << "Attendance Percentage: " << attendance_percentage << "%" << endl;
            cout << "Status: Shortage of Attendance" << endl;
        }
        else
        {
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << roll_no << endl;
            cout << "Attendance Percentage: " << attendance_percentage << "%" << endl;
            cout << "Status: Sufficient Attendance" << endl;
        }
    }
    /*SHOW Shortage End*/

    /*Show Topper start*/
    void show_topper(College std[], int num_students)
    {
        float marks_total, percent[num_students];
        for (int i = 0; i < num_students; i++)
        {
            marks_total = 0;
            for (int j = 0; j < 5; j++)
            {
                marks_total += std[i].marks[j];
            }
            percent[i] = (marks_total / 5.0);
        }

        for (int i = 0; i < num_students; i++)
        {
            for (int j = i + 1; j < num_students; j++)
            {
                if (percent[i] < percent[j])
                {
                    float temp = percent[j];
                    percent[j] = percent[i];
                    percent[i] = temp;
                }
            }
        }

        int choose;
        while (1)
        {
            cout << "Choose :-\n 1 for Show Top 5 Toppers \n 2 for Show Students above 90%\n 0 to end \n : ";
            cin >> choose;
            if (choose == 1 || choose == 2 || choose == 0)
            {
                break;
            }
        }
        while (choose != 0)
        {
            cout << "Rank Wise Highest percentage are :\n";
            switch (choose)
            {
            case 1:
                for (int i = 0; i < 5 && i < num_students; i++)
                {
                    cout << percent[i] << endl;
                }
                break;
            case 2:
                for (int i = 0; i < num_students; i++)
                {
                    if (percent[i] > 90.0)
                    {
                        cout << percent[i] << endl;
                    }
                }
                break;
            }
        }
    }
    /*Show Topper start*/
};

/*Function Overloading for end line*/
void endline()
{
    cout << "\n ************************************************** \n";
}
void endline(int a)
{
    cout << "\n           -------------------------------------        \n";
}
/*Function Overloading for end line*/

/*Main Function Start*/

int main()
{
    int st_num;
    cout << "Number of students you want to enter : ";
    cin >> st_num;
    if (st_num == 0)
    {
        cout << "You have entered 0 so program will end\n";
        cout << "Made by : Amit sharma       Github-Username : Unknown4089863\n";
        return 0;
    }
    College students[st_num]; // Object of College Class
    string prefix[st_num] = {"st", "nd", "rd"};
    for (int i = 0; i < st_num; i++)
    {
        if (i > 3)
        {
            prefix[i] = "th";
        }
        cout << "Enter Details of " << i + 1 << prefix[i] << " Student\n";
        students[i].get_details(); // Get Details
        endline(1);                // End Line
    }
    endline();
    for (int i = 0; i < st_num; i++)
    {
        students[i].show_details(); // Show Details
        endline(1);
    }
    endline();
    for (int i = 0; i < st_num; i++)
    {
        students[i].show_attendance(); // Show Attendance
        endline(1);
    }
    endline();
    for (int i = 0; i < st_num; i++)
    {
        students[i].show_name(); // Show Name
        endline(1);
    }
    endline();
    for (int i = 0; i < st_num; i++)
    {
        students[i].show_shortage(); // Show Shortage
        endline(1);
    }

    endline();
    for (int i = 0; i < st_num; i++)
    {
        students[i].add_attendance(); // Add Attendance
        endline(1);
    }

    endline();
    students[0].show_topper(students, st_num); // Show Topper
    endline();

    cout << "End of Program\n";
    cout << "Made by : Amit sharma       Github-Username : Unknown4089863\n";
    return 0;
}

/*Main Function Start*/