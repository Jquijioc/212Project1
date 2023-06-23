#include <iostream>
#include <vector>

class Gradebook{
    private:
        std::vector<int> labGrades;
        std::vector<int> assignmentGrades;
        std::vector<int> projectGrades;
        std::vector<int> examGrades;
        int totalGrade;
        std::vector<std::string> Course;
    public:
        Gradebook();
        Gradebook(std::vector<int> labGrades, std::vector<int> assignmentGrades, std::vector<int> projectGrades, std::vector<int> examGrades, int totalGrade);
        ~Gradebook();
        void printGrades();
        void getCategoryTotal();
        void perCategory(std::vector<int> catname);
        void getCategory(std::string cat);
        std::vector<float> GetWeightGrades();
};
