#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


int main(int argc, char* argv[]){
    std::string file_name(argv[1]);

    std::vector<int> file_data;
    std::ifstream file(file_name);
    std::vector<std::vector<int>> courseGrades;
    std::string line;

    while (std::getline(file, line)){
      std::stringstream ss(line);
      std::vector<int> gradeCategory;
      int temp;
      while (ss >> temp) {
        gradeCategory.push_back(temp);
      }
      courseGrades.push_back(gradeCategory); // append it to the list of vectors
    }

    Gradebook test(courseGrades[0], courseGrades[1], courseGrades[2], courseGrades[3]);
    
    //test.printGrades();
    //test.getCategory();

    int inp;
    int cat;
    int num;
    int cor;

    std::cout << "Hello! Please input an integer to request:" << std::endl;
    std::cout << "1: Individual: Return an individual deliverable name and grade." << std::endl;
    std::cout << "2: Category: Returns all grades from the category and category total." << std::endl;
    std::cout << "3: Course: Return all grades within their respective categories and course overall, only the category totals and course overall, or only the course overall." << std::endl;

    std::cin >> inp;

    switch(inp) {
        case 1:
            std::cout << "Please input a category:" << std::endl;
            std::cout << "1: Lab" << std::endl;
            std::cout << "2: Assignment" << std::endl;
            std::cout << "3: Project" << std::endl;
            std::cout << "4: Exam" << std::endl;

            std::cin >> cat;

            std::cout << "Please input the number of the assignment:" << std::endl;

            std::cin >> num;

            switch(cat) {
                case 1:
                    if(num < courseGrades[0].size()) {
                        std::cout << "LAB " << num << " GRADE IS:.." << std::endl;
                        //Call individual grade function using cat and num variables.
                    } else {
                        std::cout << "The input individual deliverable number is larger than the amount in the category." << std::endl;
                    }
                    break;
                case 2:
                    if(num < courseGrades[1].size()) {
                        std::cout << "ASSIGNMENT " << num << " GRADE IS:.." << std::endl;
                        //Call individual grade function using cat and num variables.
                    } else {
                        std::cout << "The input individual deliverable number is larger than the amount in the category." << std::endl;
                    }
                    break;
                case 3:
                    if(num < courseGrades[2].size()) {
                        std::cout << "PROJECT " << num << " GRADE IS:.." << std::endl;
                        //Call individual grade function using cat and num variables.
                    } else {
                        std::cout << "The input individual deliverable number is larger than the amount in the category." << std::endl;
                    }
                    break;
                case 4:
                    if(num < courseGrades[3].size()) {
                        std::cout << "EXAM " << num << " GRADE IS:.." << std::endl;
                        //Call individual grade function using cat and num variables.
                    } else {
                        std::cout << "The input individual deliverable number is larger than the amount in the category." << std::endl;
                    }
                    break;
                default:
                    std::cout << "An invalid category was input. The program is now exiting.." << std::endl;
                    break;
                }

            break;
        case 2:
            std::cout << "Please input a category:" << std::endl;
            std::cout << "1: Lab" << std::endl;
            std::cout << "2: Assignment" << std::endl;
            std::cout << "3: Project" << std::endl;
            std::cout << "4: Exam" << std::endl;

            switch(cat) {
                case 1:
                    //Return all lab grades and category total.
                    break;
                case 2:
                    //Return all assignment grades and category total.
                    break;
                case 3:
                    //Return all project grades and category total.
                    break;
                case 4:
                    //Return all exam grades and category total.
                    break;
                default:
                    std::cout << "An invalid category was input. The program is now exiting.." << std::endl;
                    break;
            }

            break;
        case 3:
            std::cout << "Hello! Please input an integer to request:" << std::endl;
            std::cout << "1: All Grades: Return all grades within their respective categories and course overall." << std::endl;
            std::cout << "2: Category Total: Returns only the category totals and course overall." << std::endl;
            std::cout << "3: Return only the course overall out of 100." << std::endl;

            std::cin >> cor;

            switch(cor) {
                case 1:
                    //Return all grades.
                    break;
                case 2:
                    //Returns only the category totals and course overall.
                    break;
                case 3:
                    test.getCourseTotal();
                    break;
                default:
                    std::cout << "An invalid course grade request was input. The program is now exiting.." << std::endl;
                    break;
            }
            break;
        default:
            std::cout << "An invalid input was detected. The program is now exiting.." << std::endl;
            break;
    }


    
    return 0;
}
