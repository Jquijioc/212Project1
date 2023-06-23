#include <iostream>
#include <vector>

class Gradebook{
    private:
        std::vector<int> labGrades;
        std::vector<int> assignmentGrades;
        std::vector<int> projectGrades;
        std::vector<int> examGrades;
        std::vector<std::string> Course;
    public:
        Gradebook();
        Gradebook(std::vector<int> labGrades, std::vector<int> assignmentGrades, std::vector<int> projectGrades, std::vector<int> examGrades);
        ~Gradebook();
        void printGrades();
        void getIndividual();
        void getCategory();
        void getCategoryTotal();
        void getCourseTotal();
        void getAll();
        std::vector<float> GetWeightGrades();
};
