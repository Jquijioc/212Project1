#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>

//The default unparameterized constructor.
Gradebook::Gradebook(){
    this->labGrades = {0};
    this-> assignmentGrades = {0};
    this->projectGrades = {0};
    this->examGrades = {0};
    this->totalGrade = 0;
}


//The parameterized constructor to assign vectors in the Gradebook.
Gradebook::Gradebook(std::vector<int> labGrades, std::vector<int> assignmentGrades, std::vector<int> projectGrades, std::vector<int> examGrades, int totalGrade){
     this->labGrades = labGrades;
     this-> assignmentGrades = assignmentGrades;
     this->projectGrades = projectGrades;
     this->examGrades = examGrades;
     this->totalGrade = totalGrade;
}

//A destructor method isn't necessary since we aren't allocating any dynamic memory on the heap.
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
void Gradebook::printGrades() {
    std::vector<float> weightedGrades = GetWeightGrades(); // Gets the weighted averages for each category

    std::cout << "LAB GRADES: " << std::endl;
    int totalLab = 0;
    for (int i = 0; i < labGrades.size(); i++) {
        totalLab += labGrades[i];
        std::cout << labGrades[i] << std::endl;
    }
    std::cout << "Total Grade for lab:" << " " << totalLab << "/200" << std::endl;
    float totalLabPoints = ((weightedGrades[0] / labGrades.size()) * 8) * 100;
    std::cout << "Points Earned For Labs: " << totalLabPoints << "/20" << std::endl; // Print earned points for labs

    //space between category
    std::cout << " " << std::endl;

    std::cout << "ASSIGNMENT GRADES: " << std::endl;
    int totalAssignment = 0;
    for(int i = 0; i < assignmentGrades.size(); i++) {
        totalAssignment += assignmentGrades[i];
        std::cout << assignmentGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Assignment:" << " " << totalAssignment << std::endl;
    float totalAssignmentPoints = weightedGrades[1] * assignmentGrades.size() * 100;
    std::cout << "Points Earned For Assignments: " << totalAssignmentPoints << "/20" << std::endl; // Print earned points for assignments

    //space between category
    std::cout << " " << std::endl;

    std::cout << "PROJECT GRADES: " << std::endl;
    int totalProj = 0;
    for(int i = 0; i < projectGrades.size(); i++) {
        totalProj += projectGrades[i];
        std::cout << projectGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Project:" << " " << totalProj << std::endl;
    float totalProjectPoints = weightedGrades[2] * projectGrades.size() * 100;
    std::cout << "Points Earned For Projects: " << totalProjectPoints << "/50" << std::endl; // Print earned points for projects

    //space between category
    std::cout << " " << std::endl;


    std::cout << "EXAM GRADES: " << std::endl;
    int totalExam = 0;
    for(int i = 0; i < examGrades.size(); i++) {
        totalExam += examGrades[i];
        std::cout << examGrades[i] << std::endl;
    }
    std::cout << "Total Grade for Exam:" << " " << totalExam << std::endl;
    float totalExamPoints = weightedGrades[3] * examGrades.size() * 100;
    std::cout << "Points Earned For Exam: " << totalExamPoints << "/10" << std::endl; // Print earned points for exams
    //space between category
    std::cout << " " << std::endl;

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

//this is mine, method 2

//helper func for getCategory
void Gradebook::perCategory(std::vector<int> catname) {

    int categoryTotal = 0;

    for(int i = 0; i < catname.size(); i++){

        std::cout << catname[i] << std::endl;

        categoryTotal += catname[i];
    }

    std::cout << "The category total is " << categoryTotal;

}

//this function gets all the grades from a specific category and returns the total points in that category
void Gradebook::getCategory(std::string catname){

    std::cout << "Every grade from " << catname << std::endl;

    if(catname == "lab"){

        perCategory(labGrades);

    }else if(catname == "assignment"){

        perCategory(assignmentGrades);

    }else if(catname == "project"){

        perCategory(projectGrades);

    } else if(catname == "exam"){

        perCategory(examGrades);
    }

