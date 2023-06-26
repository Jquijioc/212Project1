#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>

//The default unparameterized Gradebook constructor.
Gradebook::Gradebook(){
    this->labGrades = {0};
    this->assignmentGrades = {0};
    this->projectGrades = {0};
    this->examGrades = {0};
}

//The parameterized Gradebook constructor that assigns the vectors to their appropriate vectors.
Gradebook::Gradebook(std::vector<int> labGrades, std::vector<int> assignmentGrades, std::vector<int> projectGrades, std::vector<int> examGrades){
    //The vectors assume inputs for grades for all assignments, and grades not given yet should be input as 0.
    this->labGrades = labGrades;
    this->assignmentGrades = assignmentGrades;
    this->projectGrades = projectGrades;
    this->examGrades = examGrades;
}

//The destructor is unnecessary, since we aren't allocating any dynamic memory on the heap.
Gradebook::~Gradebook(){

}

//Amer
//The getCategoryNumber function is a helper method for main.cpp to display and take in user inputs for a category.
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

//Jon
//The GetWeightGrades function gets the weighted average for each assignment in all categories.
std::vector<float> Gradebook::GetWeightGrades() {
    std::vector<float> allGradesWeighted;

    //Check if there are any lab grades. If so, multiply by the course given weight and append it to a vector.
    if (!labGrades.empty()) {
        float totalLabWeighted = 0;
        for (int i = 0; i < labGrades.size(); i++) {
            totalLabWeighted += (labGrades[i] / 200.0) * 0.20;
        }
        allGradesWeighted.push_back(totalLabWeighted / labGrades.size());
    }

    //Check if there are any assignment grades. If so, multiply by the course given weight and append it to a vector.
    if (!assignmentGrades.empty()) {
        float totalAssignmentWeighted = 0;
        for (int i = 0; i < assignmentGrades.size(); i++) {
            totalAssignmentWeighted += (assignmentGrades[i] / 200.0) * 0.20;
        }
        allGradesWeighted.push_back(totalAssignmentWeighted / assignmentGrades.size());
    }

    //Check if there are any project grades. If so, multiply by the course given weight and append it to a vector.
    if (!projectGrades.empty()) {
        float totalProjectWeighted = 0;
        for (int i = 0; i < projectGrades.size(); i++) {
            totalProjectWeighted += (projectGrades[i] / 500.0) * 0.50;
        }
        allGradesWeighted.push_back(totalProjectWeighted / projectGrades.size());
    }

    //Check if there are any exam grades. If so, multiply by the course given weight and append it to a vector.
    if (!examGrades.empty()) {
        float totalExamWeighted = 0;
        for (int i = 0; i < examGrades.size(); i++) {
            totalExamWeighted += (examGrades[i] / 100.0) * 0.10;
        }
        allGradesWeighted.push_back(totalExamWeighted / examGrades.size());
    }
    return allGradesWeighted;
}

//Summer & Jon
//The totalGrade function gets both the *weighted total points of a category and the overall total of that category.
std::vector<float> Gradebook::totalGrade(int cat){
    std::vector<float> weightedGrades = GetWeightGrades(); // Gets the weighted averages for each category
    float totalPoints = 0;
    float totalCategory = 0;
    //The vector to hold total category points and total category (totalGradePoints[0] = totalPoints, totalGradePoints[1] = totalCategory.)
    std::vector<float> totalGradePoints = {totalPoints, totalCategory};
    //The switch statement alters weight allotment based on the category (1 for lab weight, 2 for assignment weight, etc.)
    switch(cat) {
        case 1:
            totalGradePoints[0] = weightedGrades[0] * labGrades.size() * 100;
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


//Summer & Jon
//The total function returns the unweighted points for each category depending on the category requested.
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

//Summer & Jon
//The print function takes in the category, the total amount of points for the category, and the total category points out of the weight.
void Gradebook::print(int cat, int totalCat, float totalCatPoints){
    switch(cat) {
        case 1:
            std::cout << "LAB GRADES: " << std::endl;
            for(int i = 0; i < labGrades.size(); i++) {
                std::cout << "Lab " << i+1 << "...................... " << labGrades[i] << std::endl;
            }
            std::cout << "Category Total for Lab:" << " " << totalCat << std::endl;
            std::cout << "Total Grade For Labs: " << totalCatPoints << "/20" << std::endl; // Print earned points for assignments
            break;
        case 2:
            std::cout << "ASSIGNMENT GRADES: " << std::endl;
            for(int i = 0; i < assignmentGrades.size(); i++) {
                std::cout << "Assignment " << i+1 << "...................... " << assignmentGrades[i] << std::endl;
            }
            std::cout << "Category Total for Assignment:" << " " << totalCat << std::endl;
            std::cout << "Total Grade For Assignments: " << totalCatPoints << "/50" << std::endl; // Print earned points for projects
            break;
        case 3:
            std::cout << "PROJECT GRADES: " << std::endl;
            for(int i = 0; i < projectGrades.size(); i++) {
                std::cout << "Project " << i+1 << "...................... " << projectGrades[i] << std::endl;
            }
            std::cout << "Category Total for Project:" << " " << totalCat << std::endl;
            std::cout << "Total Grade For Projects: " << totalCatPoints << "/50" << std::endl; // Print earned points for projects
            break;
        case 4:
            std::cout << "EXAM GRADES: " << std::endl;
            for (int i = 0; i < examGrades.size(); i++) {
                std::cout << "Exam " << i+1 << "...................... " << examGrades[i] << std::endl;
            }
            std::cout << "Category Total for Exam:" << " " << totalCat << std::endl;
            std::cout << "Total Grade For Exam: " << totalCatPoints << "/10" << std::endl; // Print earned points for exams
            break;
    }
}

//Jonathan & Joseph <3
//The printGrades function adds all the grades into their respective categories and return all grades in the category and gets the total for how many points can be earned.
void Gradebook::printGrades(int category) {
    if(category != 5){
        std::vector<float> totalGrades = totalGrade(category);
        float totalPoint = total(category);
        print(category, totalPoint, totalGrades[0]);
    } else {
        //If a special case is called (for All Grades), the same function prints out all the categories.
        float totalCourse = 0;
        for(int i = 1; i <= 4; i++){
            std::vector<float> totalGrades = totalGrade(i);
            float totalPoint = total(i);
            totalCourse += totalGrades[1];
            print(i, totalPoint, totalGrades[0]);
            std::cout << std::endl;
        }
        std::cout << "Total Course Overall: " << totalCourse << std::endl;
    }
}

//Jon
//The getCategoryTotal functions prints the category total the student earned for each course and course overall grade.
void Gradebook::getCategoryTotal(){
    std::cout << "Category Total for Lab" << "...................... " << total(1) << "/200"<< std::endl;
    std::cout << "Category Total for Assignment" << "...................... " << total(2) << "/200" << std::endl;
    std::cout << "Category Total for Project" << "...................... " << total(3) << "/500" << std::endl;
    std::cout << "Category Total for Exam" << "...................... " << total(4) << "/100" << std::endl;
    getCourseTotal();
}

//Summer
//The getCourseTotal function returns the total grade out of 100 for the course.
void Gradebook::getCourseTotal() {
    float totalCourseGrade = total(1) + total(2) + total(3) + total(4);
    std::cout << "Total Course Overall: " << totalCourseGrade/10 << std::endl;
}

//Amer
//The getIndividual function returns the individual grade upon request of a category and a certain number from that category (i.e. Lab 2, Project 1).
void Gradebook::getIndividual(int category) {
    int grade, number;
    //After the category is input in main.cpp, the number is input within getIndividual.
    std::cout << "Please input the number of the assignment:" << std::endl;
    std::cin >> number;
    int index = number - 1;

    switch (category) {
        case 1:
            grade = labGrades[index];
            if (index < labGrades.size() && index > -1) {
                std::cout << "Lab " << number << " grade is: ";
                std::cout << grade <<std::endl;
            } else {
                std::cout << "Lab does not exist." << std::endl;
            }
            break;
        case 2:
            grade = assignmentGrades[index];
            if (index < assignmentGrades.size() && index > -1) {
                std::cout << "Assignment " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout <<  "Assignment does not exist." << std::endl;
            }
            break;
        case 3:
            grade = projectGrades[index];
            if (index < projectGrades.size() && index > -1) {
                std::cout << "Project " << number << " grade is: ";
                std::cout<< grade << std::endl;
            } else {
                std::cout <<  "Project does not exist." << std::endl;
            }
            break;
        case 4:
            grade = examGrades[index];
            if (index < examGrades.size() && index > -1) {
                std::cout << "Exam " << number << " grade is: ";
                std::cout<< grade <<std::endl;
            } else {
                std::cout << "Exam does not exist." << std::endl;
            }
            break;
    }
}
