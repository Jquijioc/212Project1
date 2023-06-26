# 212 Project 1
Project members: Summer Lizarda, Jonathan Ok, Joseph Quijioc, Amer al Sayari

## Summary of the Project

The premise of this project is to build a gradebook application to interpret course grades into individual grades, categorical totals and semester final grades.
More specifically, the project required our program to be able to output the grade/s in several different configurations, which were as follows:
1. Individual: returns individual deliverable name and grade
2. Category: returns all grades from category and category total
3. Course:
   * all grades in their respective categories and course overall
   * only category totals and course overall
   * only course overall
    
## Planning of the Project

Pseudocode For Main.cpp

``` 
#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]){
    
    //skeleton code for file input and storing the numbers
    //declare file name as argv1
    //use ifstream read data from the file
    //declare vector within a vector to hold courseGrades
    //declare a string
    
    //declare gradeCategory vector to hold grades for each category
    //use a while loop to read line by line and push back the grades into the gradeCategory vector
    //stringstream the line

    return 0;
}

```

Pseudocode for Gradebook.cpp
```
GetWeightGrades Function
std::vector<float> Gradebook::GetWeightGrades()
//initialize a vector to hold all of the weighted grades
//check if there are grades from the input files
//for loop to iterate through list
//divide by max points that can be earned for that category and multiply by the decimal version of the max points that can be earned
//then push back into our vector to hold all of the weighted grades
//do this for all categorys

This function adds all the grades in its respective categories and return all grades in the category and gets the total for how much points can be earned
printGrades function
void Gradebook::printGrades()
//initialize a vector and call the GetWeightGrades function
//Use a for loop to loop through the grades
//Add the current grade to the total
//print the current grade while in the loop
//print total lab grade divided by max points that can be earned
//calculate the points earned for lab

Returns Total Grades For All Categorys and Course Overall
getCategorys Totals and Course Overall function
void Gradebook::getCategoryTotal(){
//initialize a total variable
//loop through the categorys
//add total and the category grades together
//initialize totalcoursegrade
//add all the categorys together
//print

```

Flowcharts

Big picture overview of program

```mermaid
flowchart TD
  A[Enter data] --> B{input data};
  B --> C[User enters request];
  C --> D{is data corrrect};
  D -- Yes --> E[run program];
  D -- No --> F[ask user again];
  E ----> G[output requested Data];
  F ----> D{is data correct};
  
 ```
GetWeightedGrades Flowchart

```mermaid
flowchart TD
    A[create empty vector for allGradesWeighted] --> B{Is the category vector empty?};
    B -- Yes --> C[end];
    B -- No --> D[enter for loop, looping for the category vector's size];
    D --> E[The weighted grade at i'th element is added to totalWeighted];
    E --> F[exit for loop];
    F --> G[push_back totalWeighted / category vector size into allGradesWeighted];
    G -- next category ----> B{Is the category vector empty?};

```

totalGrade Flowchart

```mermaid
flowchart TD
    A[generate weighted grades via GetWeightGrades] --> B[initialize float vector totalGradePoints with elements totalPoints and totalCategory];
    B --> C{User input picks which category via switch statement};
    C -- Lab --> D[totalPoints = lab weighted average grade * num of labs * 100];
    C -- Assignments --> E[totalPoints = assignments weighted average grade * num of assignments * 100];
    C -- Projects --> F[totalPoints = project weighted average grade * num of projects * 100];
    C -- Exam --> G[totalPoints = exams weighted average grade * num of exam * 100];
    D --> H[totalCategory += totalPoints];
    E --> I[totalCategory += totalPoints];
    F --> J[totalCategory += totalPoints];
    G --> K[totalCategory += totalPoints];
    H ---> L[return totalGradePoints vector];
    I ---> L[return totalGradePoints vector];
    J ---> L[return totalGradePoints vector];
    K ---> L[return totalGradePoints vector];
  
```

print Flowchart

```mermaid

flowchart TD
    A[take in cat, totalCat, and totalCatPoints parameters] --> B[switch statment for user to choose category];
    B --> C{pick category using parameter cat};
    C --> D[print out category Grades using for loop ranged for the category vector size];
    D --> E[print out category grade average using given parameter totalCat];
    E --> F[print out category total points using given parameter totalCatPoints ];

```
printGrades Flowchart

```mermaid
flowchart TD
    A[take in int category parameter] --> B{does user want specific category or all grades?};
    B -- specific category --> C[use totalGrades function to get weighted total for the chosen category];
    C --> D[get total raw points earned in specific category];
    D --> E[pass in weighted total and total raw points into print function to cout requested grades];
    B -- all grades --> F[create float totalCourse to record total Course weighted grade];
    F --> G[ create for loop ranging from i = 1 to i <= 4 to loop through each category];
    G --> H[use a variation of the specific category implementation but instead pass i as a parameter to go through all categories];
    H --> I[as i iterates by 1, add to the totalCourse to print out total course overall];
    I --> J[print out course overall];


```
## Instructions on how to compile/use our program

Our program takes in a file with the users sorted recorded grades.
Each line starts with the category name, such as Labs, followed by the grade for Lab 1, then Lab 2, etc.
The order of the categories is Labs, Assignments, Projects, and then Final.

### **Warning**

User must fill any missing grades with a zero or else the program will not work. Example of a working data file below:

![datafile](https://github.com/Jquijioc/212Project1/blob/main/samplePics/ExampleData.jpg)

Command line arguments

Command Line arguments follow the form of

```
g++ main.cpp gradebook.cpp -o test && ./test dataset
```
where "dataset" is the name of the file with the user's data

Function and method calls

## Runtime Instructions

Running this program is rather straightforward.
After running the correct commands with the desired file name, users will be presented with a menu requesting the user to type an integer and press enter to request the grade/s they wish to see.

![examplemenu](https://github.com/Jquijioc/212Project1/blob/main/samplePics/ExampleMenu.jpg)

## Example outputs

Sample output of user requesting 1 individual grade, then 1 for Lab, then the third Lab grade:

![example output](https://github.com/Jquijioc/212Project1/blob/main/samplePics/Output1.jpg)

Sample output of user requesting all grades and course overall:

![example output2](https://github.com/Jquijioc/212Project1/blob/main/samplePics/output2.jpg)


### Contributions Table

| Name | Contribution | Started | Ended | Finished by |
| ---- | ------ | ------ | ------ | ------ |
| Summer Lizarda | pseudocode | 6/15/23 | 6/23/23 | Summer Lizarda |
| | main.cpp | 6/15/23 | 6/23/23 | Summer Lizarda |
| | getCourseTotal() | 6/22/23 | 6/23/23 | Summer Lizarda |
| | comments | 6/24/23 | 6/25/23 | Summer Lizarda |
| | optimization | 6/17/23 | 6/25/23 | Summer Lizarda |
| | totalGrade() | 6/17/23 | 6/25/23 | Summer Lizarda |
| | print() | 6/17/23 | 6/25/23 | Summer Lizarda |
| | total() | 6/17/23 | 6/25/23 | Summer Lizarda |
| Jonathan Ok | pseudocode | 6/15/23 | 6/23/23 | Jonathan Ok |
| | gradebook.cpp | 6/15/23 | 6/23/23 | Jonathan Ok |
| | getCategoryTotal() | 6/15/23 | 6/23/23 | Jonathan Ok |
| | printGrades() | 6/15/23 | 6/23/23 | Jonathan Ok |
| | GetWeightGrades() | 6/15/23 | 6/23/23 | Jonathan Ok |
| | totalGrade() | 6/17/23 | 6/25/23 | Summer Lizarda |
| | print() | 6/17/23 | 6/25/23 | Summer Lizarda |
| | total() | 6/17/23 | 6/25/23 | Summer Lizarda |
| Joseph Quijioc | pseudocode | 6/15/23 | 6/23/23 | Joseph Quijioc |
| | writing README | 6/15/23 | 6/25/23 | Joseph Quijioc |
| | Flowcharts | 6/15/23 | 6/24/23 | Joseph Quijioc |
| | printGrades() | 6/15/23 | 6/25/23 | Joseph Quijioc |
| Amer al Sayari | pseudocode | 6/15/23 | 6/23/23 | Amer al Sayari|
| | getCategoryNumber() | 6/22/23 | 6/23/23 | Amer al Sayari|
| | video | 6/23/23 | 6/23/23 | Amer al Sayari|
