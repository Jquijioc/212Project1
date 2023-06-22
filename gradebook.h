#include <iostream>
#include <vector>

class Gradebook{
    private:
    public:
        Gradebook();
        ~Gradebook();
        void printGrades();
        void getCategoryTotal();
        void perCategory(std::vector<int> catname);
        void getCategory(std::string cat);
        std::vector<float> GetWeightGrades();
};
