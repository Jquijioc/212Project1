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

void Gradebook::print(int cat, int totalCat, int totalCatPoints){
    float totalCourse = 0;
    switch(cat) {
        case 1:
            std::cout << "ASSIGNMENT GRADES: " << std::endl;
            for(int i = 0; i < assignmentGrades.size(); i++) {
                std::cout << "Assignment " << i+1 << "...................... " << assignmentGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Assignment:" << " " << totalCat << std::endl;
            std::cout << "Points Earned For Assignments: " << totalCatPoints << "/20" << std::endl; // Print earned points for assignments
            break;
        case 2:
            std::cout << "PROJECT GRADES: " << std::endl;
            for(int i = 0; i < projectGrades.size(); i++) {
                std::cout << "Project " << i+1 << "...................... " << projectGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Project:" << " " << totalCat << std::endl;
            std::cout << "Points Earned For Projects: " << totalCatPoints << "/50" << std::endl; // Print earned points for projects
            break;
        case 3:
            std::cout << "PROJECT GRADES: " << std::endl;
            for(int i = 0; i < projectGrades.size(); i++) {
                std::cout << "Project " << i+1 << "...................... " << projectGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Project:" << " " << totalCat << std::endl;
            std::cout << "Points Earned For Projects: " << totalCatPoints << "/50" << std::endl; // Print earned points for projects
            break;
        case 4:
            std::cout << "EXAM GRADES: " << std::endl;
            for (int i = 0; i < examGrades.size(); i++) {
                std::cout << "Exam " << i+1 << "...................... " << examGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Exam:" << " " << totalCat << std::endl;
            std::cout << "Points Earned For Exam: " << totalCatPoints << "/10" << std::endl; // Print earned points for exams
            break;
    }
}

//This function adds all the grades into their respective categories and return all grades in the category and gets the total for how many points can be earned.
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
    if(category == 1){
        print(category, totalLab, totalLabPoints);
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
        print(category, totalAssignment, totalAssignmentPoints);
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
        print(category, totalProj, totalProjectPoints);
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
        print(category, totalExam, totalExamPoints);
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

    print(1, totalLab, totalLabPoints);

    std::cout << std::endl;

    //Prints all assignment grades:
    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }
    float totalAssignmentPoints = weightedGrades[1] * assignmentGrades.size() * 100;
    totalCourse += totalAssignmentPoints;

    print(2, totalAssignment, totalAssignmentPoints);

    std::cout << std::endl;

    //Prints all project grades:
    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }
    float totalProjectPoints = weightedGrades[2] * projectGrades.size() * 100;
    totalCourse += totalProjectPoints;

    print(3, totalProj, totalProjectPoints);

    std::cout << std::endl;

    //Prints all exam grades:
    int totalExam = 0;
    for (int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }
    float totalExamPoints = weightedGrades[3] * examGrades.size() * 100;
    totalCourse += totalExamPoints;

    print(4, totalExam, totalExamPoints);

    std::cout << std::endl;

    //prints out course overall at the end:
    std::cout << "Total Course Overall: " << totalCourse << std::endl;
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
    for(int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
    }

    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
    }

    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
    }

    int totalExam = 0;
    for(int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
    }

    float totalCourseGrade = totalLab + totalAssignment + totalProj + totalExam;
    std::cout << "Total Course Overall: " << totalCourseGrade/10 << std::endl;
}

//Amer
//The get individual grade function.
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
