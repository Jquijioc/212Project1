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

//The destructor is unncessary, since we aren't allocating any dynamic memory on the heap.
Gradebook::~Gradebook(){

}

//Finds the average ****FOR EACH**** assignment in all categorys
std::vector<float> Gradebook::GetWeightGrades() {
    std::vector<float> allGradesWeighted;

    // Check if there are any lab grades
    if (!labGrades.empty()) {
        float totalLabWeighted = 0;
        for (int i = 0; i < labGrades.size(); i++) {
            totalLabWeighted += (labGrades[i] / 200.0) * 0.20;
        }
        allGradesWeighted.push_back(totalLabWeighted);
    }

    // Check if there are any assignment grades
    if (!assignmentGrades.empty()) {
        float totalAssignmentWeighted = 0;
        for (int i = 0; i < assignmentGrades.size(); i++) {
            totalAssignmentWeighted += (assignmentGrades[i] / 200.0) * 0.20;
        }
        allGradesWeighted.push_back(totalAssignmentWeighted / assignmentGrades.size());
    }

    // Check if there are any project grades
    if (!projectGrades.empty()) {
        float totalProjectWeighted = 0;
        for (int i = 0; i < projectGrades.size(); i++) {
            totalProjectWeighted += (projectGrades[i] / 500.0) * 0.50;
        }
        allGradesWeighted.push_back(totalProjectWeighted / projectGrades.size());
    }

    // Check if there are any exam grades
    if (!examGrades.empty()) {
        float totalExamWeighted = 0;
        for (int i = 0; i < examGrades.size(); i++) {
            totalExamWeighted += (examGrades[i] / 100.0) * 0.10;
        }
        allGradesWeighted.push_back(totalExamWeighted / examGrades.size());
    }
    return allGradesWeighted;
}

//this function adds all the grades in its respective categories and return all grades in the category and gets the total
//for how much points can be earned
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
            std::cout << labGrades[i] << std::endl;
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
            std::cout << assignmentGrades[i] << std::endl;
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
            std::cout << projectGrades[i] << std::endl;
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

    //Prints all Grades in Exams
    if(category == 4) {
        std::cout << "EXAM GRADES: " << std::endl;
        for (int i = 0; i < examGrades.size(); i++) {
            std::cout << examGrades[i] << std::endl;
        }
        std::cout << "Total Grade for Exam:" << " " << totalExam << std::endl;
        std::cout << "Points Earned For Exam: " << totalExamPoints << "/10" << std::endl; // Print earned points for exams
    }

    //prints out course overall at the end
    std::cout << "Total Course Overall: " << totalCourse << std::endl;
}

//jon
//This functions gets the category total AND course overall
void Gradebook::getCategoryTotal(){
    int totalLab = 0;
    for(int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
    }
    std::cout << "Total Grade for lab:" << " " << totalLab << "/200"<< std::endl;

    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }
    std::cout << "Total Grade for Assignment:" << " " << totalAssignment << "/200" << std::endl;

    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }
    std::cout << "Total Grade for Project:" << " " << totalProj << "/500" << std::endl;

    int totalExam = 0;
    for(int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }
    std::cout << "Total Grade for Exam:" << " " << totalExam << "/100" << std::endl;

    float totalCourseGrade = totalLab + totalAssignment + totalProj + totalExam;
    std::cout <<"Final Grade: " << totalCourseGrade << "/1000" << std::endl;
}

void Gradebook::getCourseTotal() {
    int courseTotal = 0;
    for (int i = 0; i < labGrades.size(); i++) {
        courseTotal += labGrades[i];
    }

    int totalAssignment = 0;
    for (int i = 0; i < assignmentGrades.size(); i++) {
        courseTotal += assignmentGrades[i];
    }

    int totalProj = 0;
    for (int i = 0; i < projectGrades.size(); i++) {
        courseTotal += projectGrades[i];
    }

    int totalExam = 0;
    for (int i = 0; i < examGrades.size(); i++) {
        courseTotal += examGrades[i];
    }
    std::cout << "Your current course overall out of 100 is: " << courseTotal / 100 << std::endl;
}
    //Amer
    //get invidivual grade functions
void Gradebook::getIndividual(int category, int number) {
    int grade;
    int index = number - 1;
    switch (category) {
        case 1:
            grade = labGrades[index];
            break;
        case 2:
            grade = assignmentGrades[index];
            break;
        case 3:
            grade = projectGrades[index];
            break;
        case 4:
            grade = examGrades[index];
            break;
        default:
            break;
    }
    std::cout<< grade <<std::endl;
}

