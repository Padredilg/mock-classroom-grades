/*
Author: Luiz Padredi
Date: 02/28/2023
Assignment 3: Mock Classroom Grades
Repository: https://github.com/Padredilg/mock-classroom-grades
*/

#include <iostream>

using namespace std;

double calculateFinalNumberGrade(double quizOne, double quizTwo, double quizThree, double midtermGrade, double finalGrade);
char calculateFinalLetterGrade(double finalNumberScore);

class COP3014 {
    private:
        string firstName;
        string lastName;
        string zNumber;
        double quiz1;
        double quiz2;
        double quiz3;
        bool presentOnMidterm;
        double midtermExam;
        bool presentOnFinal;
        double finalExam;
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
        bool absentOnAnyExam();
        //displays the information of a student: including their z-number, and grades on all assignment to the screen.
        void outputStudent();
};

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    COP3014 student("Mitchell", "Burns", "Z2356824", 20, 19, 20, 98, 95);
    student.outputStudent();

    COP3014 student2;
    student2.setFirstName("Luanna");
    student2.setLastName("Smith");
    student2.setZNumber("Z2357543");
    student2.setQuiz1(15);
    student2.setQuiz2(19);
    student2.setQuiz3(14);
    student2.setMidtermExam(100);
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
    presentOnMidterm = true;
    midtermExam = midtermExamParam;
    presentOnFinal = true;
    finalExam = finalExamParam;
}

//no arguments constructor -- GET A BETTER SENSE IF SEETING THE EXAMS TO 100 INITIALLY IS WHAT PROFESSOR REALLY WANTS
COP3014::COP3014():presentOnMidterm(false),presentOnFinal(false),midtermExam(100),finalExam(100){}

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
void COP3014::setMidtermExam(double grade){
    presentOnMidterm = true;
    midtermExam = grade;
}
void COP3014::setFinalExam(double grade){
    presentOnFinal = true;
    finalExam = grade;
}

//displays the information of a student: including their z-number, and grades on all assignment to the screen.
void COP3014::outputStudent(){

    finalNumberGrade = calculateFinalNumberGrade(quiz1, quiz2, quiz3, midtermExam, finalExam);
    finalLetterGrade = calculateFinalLetterGrade(finalNumberGrade);

    if(absentOnAnyExam()){
        finalLetterGrade = 'F';
    }

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
         << "      Final Grade: " << finalLetterGrade << endl;

    if(absentOnAnyExam()){
        cout << endl
             << "Note: Student was not present for one or more exams."
             << endl << endl;
    }

    cout << "====================================================="
         << endl;


};

//checks whether the student was absent on any exam, and then automatically fails them by giving them an F.
bool COP3014::absentOnAnyExam(){
    return ( !presentOnMidterm || !presentOnFinal );
}

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






