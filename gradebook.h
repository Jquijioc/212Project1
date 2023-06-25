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
        //The constructors, parameterized and unparameterized:
        Gradebook();
        Gradebook(std::vector<int> labGrades, std::vector<int> assignmentGrades, std::vector<int> projectGrades, std::vector<int> examGrades);
        //The destructor (not necessary):
        ~Gradebook();
        //The helper methods:
        int getCategoryNumber(); //A helper function for main.cpp to get user input for category.
        void print(int cat, int totalCat, float totalCatPoints); //A helper method to print out grades.
        float total(int cat); //A helper method to get the individual point totals of each category.
        std::vector<float> totalGrade(int cat); //A helper method to calculate category point weights.
        std::vector<float> GetWeightGrades(); //A helper method to actually calculate weighted grades.
        //The primary methods:
        void printGrades(int category); //The function prints category grades, totals, and all grades.
        void getIndividual(int category); //The function prints individual grades.
        void getCategoryTotal(); //The function prints the total of each category.
        void getCourseTotal(); //The function prints only the course total out of 100.
};
