/*
Author: Luiz Padredi
Date: 02/28/2023
Assignment 3: Mock Classroom Grades
Repository: https://github.com/Padredilg/mock-classroom-grades
*/

#include <iostream>

using namespace std;

/*
defines  and  tests  a  class  called  COP3014
*/

/*
grading scheme:

3 quizzes  20 points each  20%
Midterm 100 points  30%
Final  100 points  50%
*/

/*
Based on the total grade of any student for the course,
the letter grade of each student can be computed as follows

Any grade of 90 or more is an A,
any grade of 80 or more (but less than 90) is a B,
any grade of 70 or more (but less than 80) is a C,
any grade of 60 or more (but less than 70) is a D,
and any grade below 60 is an F.
*/




/*
This class needs to have some member variables.

The first name,
last name,
the Z-number,
the grades (quizzes),
the total grade
final letter grade

all considered to be private member variables of this class.
*/

/*
The class should also have the following public methods that
can bring the objects (students of the class) to life and give them some functionality:

a. Constructor and default constructor (we will learn on 02/28)
b. Setter functions for all the member variables
c. Getter functions for all the member variables
d. A function that computes the student’s total grade
e. A function that computes the student’s final letter grade
f. A function that checks whether the student was absent on any exam, and then automatically fails them by giving them an F.
g. An output function that displays the information of any student: including their z-number, and grades on all assignment to the screen.
*/

/*
Once you generated the class definition with all its function definitions,
the next step is to use the class and generate test cases.
First, construct some objects of this class.
Give them names to represent individual students.
*/

/*
Every student has grades for each of the work assigned to them.
These grades can be initialized in the constructor
(initial value is 100, Canvas starts everyone off with 100)
and later set using the setter functions
(imagine the TAs grading your work and updating the grades).

Importantly,  each  student  gets  a  total  grade  and  a  letter  grade  which  is  computed  for  them
automatically.
*/

/*
The output function should be called on each student
to print their information along with their grades to the screen.
The output can look as follows:

Frank Fabulous – Z12345678

    Quiz 1: 20
    Quiz 2: 20
    Quiz 3: 10
    Midterm: 0
    Final: 100
    Total grade: 66.67
    Final grade: F

Gina Genius – Z98765432

    Quiz 1: 20
    Quiz 2: 20
    Quiz 3: 20
    Midterm: 98
    Final: 95
    Total grade: 96.9
    Final grade: A
*/

/*
Notes:

- Equation to compute total grade:

Total grade = (quiz1 + quiz2 +quiz3)/3 + midterm *0.3 + final * 0.5

- Z-number is 8 digits long.
*/

/*

INSTRUCTIONS TO SELF

Define the class along with prototypes for each method as public, and properties as private

then define each method down below

then on main create a few students, then call their output methods to print to screen
*/

class COP3014 {
    public:
        //Constructor with arguments
        COP3014(string firstName,
                string lastName,
                string zNumber,
                double quiz1,
                double quiz2,
                double quiz3,
                double midtermExam,
                double finalExam);
        //no arguments constructor
        COP3014();

        //Getter functions for all the member variables
        string getFirstName();
        string getLastName();
        string getZNumber();
        double getQuiz1();
        double getQuiz2();
        double getQuiz3();
        double getMidtermExam();
        double getFinalExam();
        //Setter functions for all the member variables
        void setFirstName(string name);
        void setLastName(string name);
        void setZNumber(string number);
        void setQuiz1(double grade);
        void setQuiz2(double grade);
        void setQuiz3(double grade);
        void setMidtermExam(double grade);
        void setFinalExam(double grade);

        //computes the student’s total grade
        double calculateFinalNumberGrade();
        //computes the student’s final letter grade
        double calculateFinalLetterGrade();
        //checks whether the student was absent on any exam, and then automatically fails them by giving them an F.
        void checkIfAbsentOnExams();
        //displays the information of a student: including their z-number, and grades on all assignment to the screen.
        void outputStudent();

    private:
        string firstName;
        string lastName;
        string zNumber;
        double quiz1 = 100;
        double quiz2 = 100;
        double quiz3 = 100;
        double midtermExam = 100;
        double finalExam = 100;
        double finalNumberGrade;
        char finalLetterGrade;
};

int main()
{
    COP3014 student = COP3014();
    student.setFirstName("Luiz");

    cout << student.getFirstName() << " " << student.getQuiz1() << endl;
    COP3014 student2("Giovanna", "Bruzzi", "Z2356824", 20, 19, 20, 98, 95);

    cout << student2.getFirstName() << endl
         << student2.getLastName() << endl
         << student2.getZNumber() << endl
         << student2.getQuiz2() << endl
         << student2.getFinalExam();

    return 0;
}

//Constructor with arguments
COP3014::COP3014(
        string firstNameParam,
        string lastNameParam,
        string zNumberParam,
        double quiz1Param,
        double quiz2Param,
        double quiz3Param,
        double midtermExamParam,
        double finalExamParam
){
    firstName = firstNameParam;
    lastName = lastNameParam;
    zNumber = zNumberParam;
    quiz1 = quiz1Param;
    quiz2 = quiz2Param;
    quiz3 = quiz3Param;
    midtermExam = midtermExamParam;
    finalExam = finalExamParam;
}
//no arguments constructor
COP3014::COP3014(){}
//getters
string COP3014::getFirstName(){ return firstName; }
string COP3014::getLastName(){ return lastName; }
string COP3014::getZNumber(){ return zNumber; }
double COP3014::getQuiz1(){ return quiz1; }
double COP3014::getQuiz2(){ return quiz2; }
double COP3014::getQuiz3(){ return quiz3; }
double COP3014::getMidtermExam(){ return midtermExam; }
double COP3014::getFinalExam(){ return finalExam; }
//setters
void COP3014::setFirstName(string name){ firstName = name; }
void COP3014::setLastName(string name){ lastName = name; }
void COP3014::setZNumber(string number){ zNumber = number; }
void COP3014::setQuiz1(double grade){ quiz1 = grade; }
void COP3014::setQuiz2(double grade){ quiz2 = grade; }
void COP3014::setQuiz3(double grade){ quiz3 = grade; }
void COP3014::setMidtermExam(double grade){ midtermExam = grade; }
void COP3014::setFinalExam(double grade){ finalExam = grade; }





/*NEXT, DEFINE THE remaining CLASS METHODS for calculations and output*/





