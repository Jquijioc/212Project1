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
        int getCategoryNumber();
        void getIndividual(int category);
        void getCategory();
        void getCategoryTotal();
        void getCourseTotal();
        void getAll();
        void print(int cat, int totalCat, int totalCatPoints);
        float total(int cat);
        std::vector<float> totalGrade(int cat);
        std::vector<float> GetWeightGrades();
};
