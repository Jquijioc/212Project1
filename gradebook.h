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
        void printGrades(int category);
        void getIndividual();
        void getCategory();
        void getCategoryTotal();
        void getCourseTotal();
        void getAll();
        void respectiveGrades();
        std::vector<float> GetWeightGrades();
};
