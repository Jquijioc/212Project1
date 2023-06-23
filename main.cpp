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
    test.getCategory();

    return 0;
}
