#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>

//The default unparameterized constructor.
Gradebook::Gradebook(){
    this->labGrades = {0};
    this->assignmentGrades = {0};
    this->projectGrades = {0};
    this->examGrades = {0};
}

//The parameterized constructor that assigns the vectors to appropriate vectors in the Gradebook.
Gradebook::Gradebook(std::vector<int> labGrades, std::vector<int> assignmentGrades, std::vector<int> projectGrades, std::vector<int> examGrades){
    //The vectors assume inputs for grades for all assignments, and grades not given yet should be input as 0.
    this->labGrades = labGrades;
    this->assignmentGrades = assignmentGrades;
    this->projectGrades = projectGrades;
    this->examGrades = examGrades;
    //The total grade is the total amount of possible points available.
}

//The destructor is unnecessary, since we aren't allocating any dynamic memory on the heap.
Gradebook::~Gradebook(){

}

//Finds the average for each assignment in all categories.
std::vector<float> Gradebook::GetWeightGrades() {
    std::vector<float> allGradesWeighted;

    //Check if there are any lab grades.
    if (!labGrades.empty()) {
        float totalLabWeighted = 0;
        for (int i = 0; i < labGrades.size(); i++) {
            totalLabWeighted += (labGrades[i] / 200.0) * 0.20;
        }
        allGradesWeighted.push_back(totalLabWeighted);
    }

    //Check if there are any assignment grades.
    if (!assignmentGrades.empty()) {
        float totalAssignmentWeighted = 0;
        for (int i = 0; i < assignmentGrades.size(); i++) {
            totalAssignmentWeighted += (assignmentGrades[i] / 200.0) * 0.20;
        }
        allGradesWeighted.push_back(totalAssignmentWeighted / assignmentGrades.size());
    }

    //Check if there are any project grades.
    if (!projectGrades.empty()) {
        float totalProjectWeighted = 0;
        for (int i = 0; i < projectGrades.size(); i++) {
            totalProjectWeighted += (projectGrades[i] / 500.0) * 0.50;
        }
        allGradesWeighted.push_back(totalProjectWeighted / projectGrades.size());
    }

    //Check if there are any exam grades.
    if (!examGrades.empty()) {
        float totalExamWeighted = 0;
        for (int i = 0; i < examGrades.size(); i++) {
            totalExamWeighted += (examGrades[i] / 100.0) * 0.10;
        }
        allGradesWeighted.push_back(totalExamWeighted / examGrades.size());
    }
    return allGradesWeighted;
}

//This function adds all the grades in its respective categories and return all grades in the category and gets the total for how many points can be earned.
void Gradebook::printGrades(int category) {
    std::vector<float> weightedGrades = GetWeightGrades(); // Gets the weighted averages for each category
    float totalCourse = 0;

    //LAB
    //for loop for total course overall
    int totalLab = 0;
    for (int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
    }
    float totalLabPoints = ((weightedGrades[0] / labGrades.size()) * 8) * 100;
    totalCourse += totalLabPoints;

    //Print All Grades in Lab
    if(category == 1) {
        std::cout << "LAB GRADES: " << std::endl;
        for (int i = 0; i < labGrades.size(); i++) {
            std::cout << "Lab " << i+1 << "...................... " << labGrades[i] << std::endl;
        }
        std::cout << "Total Grade for lab:" << " " << totalLab << "/200" << std::endl;
        std::cout << "Points Earned For Labs: " << totalLabPoints << "/20" << std::endl; // Print earned points for labs
    }

    //ASSIGNMENTS
    //for loop for total course overall
    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }
    float totalAssignmentPoints = weightedGrades[1] * assignmentGrades.size() * 100;
    totalCourse += totalAssignmentPoints;
    //Prints All Grades in Assignment

    if(category == 2){
        std::cout << "ASSIGNMENT GRADES: " << std::endl;
        for(int i = 0; i < assignmentGrades.size(); i++) {
            std::cout << "Assignment " << i+1 << "...................... " << assignmentGrades[i] << std::endl;
        }
        std::cout << "Total Grade for Assignment:" << " " << totalAssignment << std::endl;
        std::cout << "Points Earned For Assignments: " << totalAssignmentPoints << "/20" << std::endl; // Print earned points for assignments
    }

    //PROJECTS
    //for loop for total course overall
    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }
    float totalProjectPoints = weightedGrades[2] * projectGrades.size() * 100;
    totalCourse += totalProjectPoints;

    //Prints All Grades in Projects
    if(category == 3) {
        std::cout << "PROJECT GRADES: " << std::endl;
        for(int i = 0; i < projectGrades.size(); i++) {
            std::cout << "Project " << i+1 << "...................... " << projectGrades[i] << std::endl;
        }
        std::cout << "Total Grade for Project:" << " " << totalProj << std::endl;
        std::cout << "Points Earned For Projects: " << totalProjectPoints << "/50" << std::endl; // Print earned points for projects
    }

    //EXAMS
    //for loop for total course overall
    int totalExam = 0;
    for (int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }
    float totalExamPoints = weightedGrades[3] * examGrades.size() * 100;
    totalCourse += totalExamPoints;

    //Prints all grades in exams.
    if(category == 4) {
        std::cout << "EXAM GRADES: " << std::endl;
        for (int i = 0; i < examGrades.size(); i++) {
            std::cout << "Exam " << i+1 << "...................... " << examGrades[i] << std::endl;
        }
        std::cout << "Total Grade for Exam:" << " " << totalExam << std::endl;
        std::cout << "Points Earned For Exam: " << totalExamPoints << "/10" << std::endl; // Print earned points for exams
    }

    //prints out course overall at the end
    std::cout << "Total Course Overall: " << totalCourse << std::endl;
}

void Gradebook::getAll() {
    std::vector<float> weightedGrades = GetWeightGrades();
    float totalCourse = 0;

    //Prints all lab grades:
    int totalLab = 0;
    for (int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
    }
    float totalLabPoints = ((weightedGrades[0] / labGrades.size()) * 8) * 100;
    totalCourse += totalLabPoints;

    std::cout << "LAB GRADES: " << std::endl;
    for (int i = 0; i < labGrades.size(); i++) {
        std::cout << "Lab " << i+1 << "...................... " << labGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Lab" << "........." << totalLab << "/200" << std::endl;
    std::cout << "Points Earned For Labs" << "......" << totalLabPoints << "/20" << std::endl; // Print earned points for labs

    std::cout << std::endl;

    //Prints all assignment grades:
    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }
    float totalAssignmentPoints = weightedGrades[1] * assignmentGrades.size() * 100;
    totalCourse += totalAssignmentPoints;

    std::cout << "ASSIGNMENT GRADES: " << std::endl;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        std::cout << "Assignment " << i+1 << "...................... " << assignmentGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Assignment: " <<  totalAssignment << std::endl;
    std::cout << "Points Earned For Assignments: " <<  totalAssignmentPoints << "/20" << std::endl; // Print earned points for assignments

    std::cout << std::endl;

    //Prints all project grades:
    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }
    float totalProjectPoints = weightedGrades[2] * projectGrades.size() * 100;
    totalCourse += totalProjectPoints;

    std::cout << "PROJECT GRADES: " << std::endl;
    for(int i = 0; i < projectGrades.size(); i++) {
        std::cout << "Project " << i+1 << "...................... " << projectGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Project: " <<  totalProj << std::endl;
    std::cout << "Points Earned For Projects: " <<  totalProjectPoints << "/50" << std::endl; // Print earned points for projects

    std::cout << std::endl;

    //Prints all exam grades:
    int totalExam = 0;
    for (int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }
    float totalExamPoints = weightedGrades[3] * examGrades.size() * 100;
    totalCourse += totalExamPoints;

    std::cout << "EXAM GRADES: " << std::endl;
    for (int i = 0; i < examGrades.size(); i++) {
        std::cout << "Exam " << i+1 << "...................... " << examGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Exam: " << totalExam << std::endl;
    std::cout << "Points Earned For Exam: " << totalExamPoints << "/10" << std::endl; // Print earned points for exams

    std::cout << std::endl;

    //prints out course overall at the end:
    std::cout << "Total Course Overall: " << totalCourse << std::endl;
}

void Gradebook::respectiveGrades() {
    std::vector<float> weightedGrades = GetWeightGrades(); // Gets the weighted averages for each category

    std::cout << "LAB GRADES: " << std::endl;
    int totalLab = 0;
    for (int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
        std::cout << labGrades[i] << std::endl;
    }

    //Gets the weighted lab grades for course overall.
    float totalLabPoints = ((weightedGrades[0] / labGrades.size()) * 8) * 100;

    //space between category
    std::cout << " " << std::endl;

    std::cout << "ASSIGNMENT GRADES: " << std::endl;
    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
        std::cout << assignmentGrades[i] << std::endl;
    }

    //get the weighted assignment grades for course overall
    float totalAssignmentPoints = weightedGrades[1] * assignmentGrades.size() * 100;

    //space between category
    std::cout << " " << std::endl;

    std::cout << "PROJECT GRADES: " << std::endl;
    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
        std::cout << projectGrades[i] << std::endl;
    }

    //get the weighted project grades for course overall
    float totalProjectPoints = weightedGrades[2] * projectGrades.size() * 100;

    //space between category
    std::cout << " " << std::endl;

    std::cout << "EXAM GRADES: " << std::endl;
    int totalExam = 0;
    for(int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
        std::cout << examGrades[i] << std::endl;
    }

    //Get the weighed exam grades for course overall.
    float totalExamPoints = weightedGrades[3] * examGrades.size() * 100;

    //The space between category
    std::cout << " " << std::endl;

    //now print out the total course overall using weighted categories
    float courseTotal = totalLabPoints + totalAssignmentPoints + totalExamPoints + totalProjectPoints;
    std::cout << "Total Course Overall: " << courseTotal << std::endl;

}

//Jon
//This functions gets the category total and course overall grade.
void Gradebook::getCategoryTotal(){
    int totalLab = 0;
    for(int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
    }
    std::cout << "Total Grade for Lab" << "...................... " << totalLab << "/200"<< std::endl;

    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }
    std::cout << "Total Grade for Assignment" << "...................... " << totalAssignment << "/200" << std::endl;

    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }
    std::cout << "Total Grade for Project" << "...................... " << totalProj << "/500" << std::endl;

    int totalExam = 0;
    for(int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }
    std::cout << "Total Grade for Exam" << "...................... " << totalExam << "/100" << std::endl;

    float totalCourseGrade = totalLab + totalAssignment + totalProj + totalExam;
    std::cout <<"Final Grade: " << totalCourseGrade << "/1000" << std::endl;
}

//Summer
//The course overall function.
void Gradebook::getCourseTotal() {
    std::vector<float> weightedGrades = GetWeightGrades(); // Gets the weighted averages for each category

    int totalLab = 0;
    for (int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
    }

    float totalLabPoints = ((weightedGrades[0] / labGrades.size()) * 8) * 100;
    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }

    float totalAssignmentPoints = weightedGrades[1] * assignmentGrades.size() * 100;
    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }

    float totalProjectPoints = weightedGrades[2] * projectGrades.size() * 100;
    int totalExam = 0;
    for(int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }

    //Get the weighed exam grades for course overall.
    float totalExamPoints = weightedGrades[3] * examGrades.size() * 100;
    float courseTotal = totalLabPoints + totalAssignmentPoints + totalExamPoints + totalProjectPoints;
    std::cout << "Total Course Overall: " << courseTotal << std::endl;
}

//Amer
//The get individual grade function.
int Gradebook::getCategoryNumber() {
    int cat;
    if(cat < 5 && cat > 0) {
        std::cout << "Please input a category:" << std::endl;
        std::cout << "1: Lab" << std::endl;
        std::cout << "2: Assignment" << std::endl;
        std::cout << "3: Project" << std::endl;
        std::cout << "4: Exam" << std::endl;
        std::cin >> cat;
        return cat;
    } else {
        std::cout << "An invalid category was input. The program is now exiting.." << std::endl;
        return 0;
    }
}
void Gradebook::getIndividual(int category) {
    int grade, number;
    std::cout << "Please input the number of the assignment:" << std::endl;
    std::cin >> number;
    int index = number - 1;

    switch (category) {
        case 1:
            grade = labGrades[index];
            if (index < labGrades.size()) {
                std::cout << "Lab " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout << "Lab Does not exist." << std::endl;
            }
            break;
        case 2:
            grade = assignmentGrades[index];
            if (index < assignmentGrades.size()) {
                std::cout << "Assignment " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout <<  "Assignment Does not exist." << std::endl;
            }
            break;
        case 3:
            grade = projectGrades[index];
            if (index < projectGrades.size()) {
                std::cout << "Project " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout <<  "Project Does not exist." << std::endl;
            }
            break;
        case 4:
            grade = examGrades[index];
            if (index < examGrades.size()) {
                std::cout << "Exam " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout << "Exam Does not exist." << std::endl;
            }
            break;
        default:
            break;
    }
}
