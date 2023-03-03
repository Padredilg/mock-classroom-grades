/*
Author: Luiz Padredi
Date: 02/28/2023
Assignment 3: Mock Classroom Grades
Repository: https://github.com/Padredilg/mock-classroom-grades
*/

#include <iostream>

using namespace std;

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

double calculateFinalNumberGrade(double quizOne, double quizTwo, double quizThree, double midtermGrade, double finalGrade);
char calculateFinalLetterGrade(double finalNumberScore);

class COP3014 {
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


    public:
        //Constructor with arguments
        COP3014(string firstName,
                string lastName,
                string zNumber,
                double quiz1,
                double quiz2,
                double quiz3,
                double midtermExam,
                double finalExam
                );

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

        //checks whether the student was absent on any exam, and then automatically fails them by giving them an F.
        void checkIfAbsentOnExams();
        //displays the information of a student: including their z-number, and grades on all assignment to the screen.
        void outputStudent();
};

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    COP3014 student2("Giovanna", "Bruzzi", "Z2356824", 20, 19, 20, 98, 95);
    student2.outputStudent();

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
    finalNumberGrade = calculateFinalNumberGrade(quiz1, quiz2, quiz3, midtermExam, finalExam);
    finalLetterGrade = calculateFinalLetterGrade(finalNumberGrade);
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

//displays the information of a student: including their z-number, and grades on all assignment to the screen.
void COP3014::outputStudent(){
    cout << endl
         << "====================================================="
         << endl << endl
         << firstName << " " << lastName << " - " << zNumber
         << endl << endl
         << "      Quiz 1: " << quiz1 << endl
         << "      Quiz 2: " << quiz2 << endl
         << "      Quiz 3: " << quiz3 << endl
         << "      Midterm: " << midtermExam << endl
         << "      Final: " << finalExam << endl
         << "      Total Grade: " << finalNumberGrade << endl
         << "      Final Grade: " << finalLetterGrade
         << endl << endl
         << "====================================================="
         << endl;
};

//computes the student’s total grade
double calculateFinalNumberGrade(double quizOne, double quizTwo, double quizThree, double midtermGrade, double finalGrade){
    return (quizOne + quizTwo + quizThree)/3 + (midtermGrade * 0.3) + (finalGrade * 0.5);
}

//computes the student’s final letter grade
char calculateFinalLetterGrade(double finalNumberScore){
    if(finalNumberScore >= 90){
        return 'A';
    }
    else if(finalNumberScore >= 80){
        return 'B';
    }
    else if(finalNumberScore >= 70){
        return 'C';
    }
    else if(finalNumberScore >= 60){
        return 'D';
    }
    else{
        return 'F';
    }
}

//checks whether the student was absent on any exam, and then automatically fails them by giving them an F.
//void checkIfAbsentOnExams();




