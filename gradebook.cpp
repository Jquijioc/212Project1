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

std::vector<float> Gradebook::totalGrade(int cat){
    float totalPoints = 0;
    float totalCourse = 0;
    std::vector<float> weightedGrades = GetWeightGrades(); // Gets the weighted averages for each category
    std::vector<float> totalGradePoints = {totalPoints, totalCourse};
    switch(cat) {
        case 1:
            totalGradePoints[0] = ((weightedGrades[0] / labGrades.size()) * 8) * 100;
            totalGradePoints[1] += totalGradePoints[0];
            break;
        case 2:
            totalGradePoints[0] = weightedGrades[1] * assignmentGrades.size() * 100;
            totalGradePoints[1] += totalGradePoints[0];
            break;
        case 3:
            totalGradePoints[0] = weightedGrades[2] * projectGrades.size() * 100;
            totalGradePoints[1] += totalGradePoints[0];
            break;
        case 4:
            totalGradePoints[0] = weightedGrades[3] * examGrades.size() * 100;
            totalGradePoints[1] += totalGradePoints[0];
            break;
    }
    return totalGradePoints;
}

int Gradebook::getCategoryNumber() {
    int cat;
    std::cout << "Please input a category:" << std::endl;
    std::cout << "1: Lab" << std::endl;
    std::cout << "2: Assignment" << std::endl;
    std::cout << "3: Project" << std::endl;
    std::cout << "4: Exam" << std::endl;
    std::cin >> cat;
    if(cat < 5 && cat > 0) {
        return cat;
    } else {
        std::cout << "An invalid category was input. The program is now exiting.." << std::endl;
        return 0;
    }
}

void Gradebook::print(int cat, int totalCat, int totalCatPoints){
    switch(cat) {
        case 1:
            std::cout << "LAB GRADES: " << std::endl;
            for(int i = 0; i < labGrades.size(); i++) {
                std::cout << "Lab " << i+1 << "...................... " << labGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Lab:" << " " << totalCat << std::endl;
            std::cout << "Category Total For Labs: " << totalCatPoints << "/20" << std::endl; // Print earned points for assignments
            break;
        case 2:
            std::cout << "ASSIGNMENT GRADES: " << std::endl;
            for(int i = 0; i < assignmentGrades.size(); i++) {
                std::cout << "Assignment " << i+1 << "...................... " << assignmentGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Assignment:" << " " << totalCat << std::endl;
            std::cout << "Category Total For Assignments: " << totalCatPoints << "/50" << std::endl; // Print earned points for projects
            break;
        case 3:
            std::cout << "PROJECT GRADES: " << std::endl;
            for(int i = 0; i < projectGrades.size(); i++) {
                std::cout << "Project " << i+1 << "...................... " << projectGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Project:" << " " << totalCat << std::endl;
            std::cout << "Category Total For Projects: " << totalCatPoints << "/50" << std::endl; // Print earned points for projects
            break;
        case 4:
            std::cout << "EXAM GRADES: " << std::endl;
            for (int i = 0; i < examGrades.size(); i++) {
                std::cout << "Exam " << i+1 << "...................... " << examGrades[i] << std::endl;
            }
            std::cout << "Total Grade for Exam:" << " " << totalCat << std::endl;
            std::cout << "Category Total For Exam: " << totalCatPoints << "/10" << std::endl; // Print earned points for exams
            break;
    }
}

float Gradebook::total(int cat){
    float total = 0;
    switch(cat) {
        case 1:
            for(int i = 0; i < labGrades.size(); i++) {
                total += labGrades[i];
            }
            break;
        case 2:
            for(int i = 0; i < assignmentGrades.size(); i++) {
                total += assignmentGrades[i];
            }
            break;
        case 3:
            for(int i = 0; i < projectGrades.size(); i++) {
                total += projectGrades[i];
            }
            break;
        case 4:
            for(int i = 0; i < examGrades.size(); i++) {
                total += examGrades[i];
            }
            break;
    }
    return total;
}

//This function adds all the grades into their respective categories and return all grades in the category and gets the total for how many points can be earned.
void Gradebook::printGrades(int category) {
    if(category != 5){
        std::vector<float> totalGrades = totalGrade(category);
        float totalPoint = total(category);
        print(category, totalPoint, totalGrades[0]);
    } else {
        float totalCourse = 0;
        for(int i = 1; i <= 4; i++){
            std::vector<float> totalGrades = totalGrade(i);
            float totalPoint = total(i);
            totalCourse += totalGrades[1];
            print(i, totalPoint, totalGrades[0]);
        }
        std::cout << "Total Course Overall: " << totalCourse << std::endl;
    }
}

//Jon
//This functions gets the category total and course overall grade.
void Gradebook::getCategoryTotal(){
    std::cout << "Total Grade for Lab" << "...................... " << total(1) << "/200"<< std::endl;
    std::cout << "Total Grade for Assignment" << "...................... " << total(2) << "/200" << std::endl;
    std::cout << "Total Grade for Project" << "...................... " << total(3) << "/500" << std::endl;
    std::cout << "Total Grade for Exam" << "...................... " << total(4) << "/100" << std::endl;

    float totalCourseGrade = total(1) + total(2) + total(3) + total(4);
    std::cout <<"Final Grade: " << totalCourseGrade << "/1000" << std::endl;
}

//Summer
//The course overall function.
void Gradebook::getCourseTotal() {
    float totalCourseGrade = total(1) + total(2) + total(3) + total(4);
    std::cout << "Total Course Overall: " << totalCourseGrade/10 << std::endl;
}

//Amer
//The get individual grade function.
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
                std::cout << "Lab does not exist." << std::endl;
            }
            break;
        case 2:
            grade = assignmentGrades[index];
            if (index < assignmentGrades.size()) {
                std::cout << "Assignment " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout <<  "Assignment does not exist." << std::endl;
            }
            break;
        case 3:
            grade = projectGrades[index];
            if (index < projectGrades.size()) {
                std::cout << "Project " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout <<  "Project does not exist." << std::endl;
            }
            break;
        case 4:
            grade = examGrades[index];
            if (index < examGrades.size()) {
                std::cout << "Exam " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout << "Exam does not exist." << std::endl;
            }
            break;
        default:
            break;
    }
    std::cout<< grade <<std::endl;
}
