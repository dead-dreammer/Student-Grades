#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function that calculates the full period mark for each student
int full_period(int test_1,int test_2,int assignment){
    return (test_1*0.33) + (test_2*0.33) + (assignment*0.34);
}

//function that calculates the final mark for each student
int final_mark(int period_mark, int exam){
   return period_mark*0.4 + exam*0.6;
}

//function that indicates if a student passed or failed
string pass_fail(int period_mark, int final_mark){
    return (period_mark >= 40 && final_mark >= 50) ? "PASS" : "FAIL";   
}

int main(){

    int num_students;
    cout << "Enter the number of students in class: ";
    cin >> num_students;

    // Declare arrays to store student information
    string name[num_students], surname[num_students];
    int test_1[num_students], test_2[num_students], assignment[num_students], exam[num_students];

    // Input student information
    for (int i=0; i < num_students; i++){

        cout << "Enter student name: ";
        cin >> name[i];

        cout << "Enter student surname: ";
        cin >> surname[i];

        cout << "Enter test 1 score: ";
        cin >> test_1[i];

        // validator for test 1 score
        if (test_1[i]>100 || test_1[i]< 0){
            cout << "Incorrect value entered!!" << endl;
            cout << "Please try again." << endl;
            cout << "Enter test 1 score: ";
            cin >> test_1[i];
        }

        cout << "Enter test 2 score: ";
        cin >> test_2[i];

        //validator for test 2 score
        if (test_2[i]>100 || test_2[i]< 0){
            cout << "Incorrect value entered!!" << endl;
            cout << "Please try again." << endl;
            cout << "Enter test 2 score: ";
            cin >> test_2[i];
        }

        cout << "Enter assignment score: ";
        cin >> assignment[i];

        // validator for assignment score
        if (assignment[i]>100 || assignment[i]< 0){
            cout << "Incorrect value entered!!" << endl;
            cout << "Please try again." << endl;
            cout << "Enter assignment score: ";
            cin >> assignment[i];
        }

        cout << "Enter exam score: ";
        cin >> exam[i];

        // validator for exam score
        if (exam[i]>100 || exam[i]< 0){
            cout << "Incorrect value entered!!" << endl;
            cout << "Please try again." << endl;
            cout << "Enter exam score: ";
            cin >> exam[i];
        }
        cout << endl;

    }

    // Output table header
    cout  << "NAME" << setw(15) << "SURNAME" << setw(15) << "PERIOD MARK" << setw(15) << "FINAL MARK" << setw(15) << "PASS OR FAIL" << endl;
    
    for (int i=0; i < num_students; i++){
        int period_mark = full_period(test_1[i], test_2[i], assignment[i]);
        int finalMark = final_mark(period_mark, exam[i]);
        string result = pass_fail(period_mark, finalMark);
    
        // Output student details in table format
        cout  << name[i] << setw(15) << surname[i] << setw(15) << period_mark << setw(15) << finalMark << setw(15) << result << endl;
    }

    return 0;
}
