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
    void getIndividual(int category);
    void respectiveGrades();
    void getCategory();
    void getCategoryTotal();
    int getCategoryNumber();
    void getCourseTotal();
    void getAll();
    std::vector<float> GetWeightGrades();
};
