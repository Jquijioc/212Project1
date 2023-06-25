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
        std::string firstString;  //Add a variable to store the first string (for readability, labeling).
        ss >> firstString;  //Read and ignore the first string.

        int temp;
        while (ss >> temp) {
            gradeCategory.push_back(temp);
        }
        courseGrades.push_back(gradeCategory); // Append it to the list of vectors.
    }

    Gradebook test(courseGrades[0], courseGrades[1], courseGrades[2], courseGrades[3]);

    int inp;
    int cat;
    int num;
    int cor;

    std::cout << "Hello! Please input an integer to request:" << std::endl;
    std::cout << "1: Individual: Return an individual deliverable name and grade." << std::endl;
    std::cout << "2: Category: Returns all grades from the category and category total." << std::endl;
    std::cout << "3: Course: Return all grades within their respective categories and course overall, only the category totals and course overall, or only the course overall." << std::endl;

    std::cin >> inp;

    //The switch statement alters the menu based on the requisite category selected.
    switch(inp) {
        case 1:
            cat = test.getCategoryNumber();
                switch (cat) {
                    case 1:
                        test.getIndividual(cat);
                        break;
                    case 2:
                        test.getIndividual(cat);
                        break;
                    case 3:
                        test.getIndividual(cat);
                        break;
                    case 4:
                        test.getIndividual(cat);
                        break;
                }
            break;
        case 2:
            cat = test.getCategoryNumber();
            switch(cat) {
                case 1:
                    test.printGrades(cat);
                    break;
                case 2:
                    test.printGrades(cat);
                    break;
                case 3:
                    test.printGrades(cat);
                    break;
                case 4:
                    test.printGrades(cat);
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
                    test.printGrades(5);
                    break;
                case 2:
                    test.getCategoryTotal();
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
