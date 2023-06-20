#include <iostream>
#include <vector>

class Gradebook{
    private:
    public:
        Gradebook();
        ~Gradebook();
        void printGrades();
        void getCategoryTotal();
        std::vector<float> GetWeightGrades();
};
