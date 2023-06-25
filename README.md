# 212 Project 1
Project members: Summer Lizarda, Jonathan Ok, Joseph Quijioc, Amer al Sayari

## Summary of the Project

The premise of this project, from the assignment itself, is to "build a gradebook application to interpret course grades into categorical totals and semester final grades."

The viewable outputs of the program should include:
files: main.cpp, gradebook.cpp, gradebook.h


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
example pseudocode 2

```
//put code in between the tics

```
//Pseudocode for Gradebook.cpp
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

Flowchart

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

## Instructions on how to compile/use our program

Command line arguments

Function and method calls

## Runtime Instructions

## Example outputs

Sample output given grades:

![example output](https://github.com/Jquijioc/212Project1/blob/main/samplePics/testingjpg.jpg)


### Contributions Table

| Name | Contribution | Started | Ended | Finished by |
| ---- | ------ | ------ | ------ | ------ |
| Summer Lizarda | main.cpp | 6/15/23 | 6/23/23 | Summer Lizarda |
| | getCourseTotal() | 6/22/23 | 6/23/23 | Summer Lizarda |
| Jonathan Ok | pseudocode, gradebook.cpp, getCategoryTotal(), printGrades(), GetWeightGrades()| 6/15/23 | 6/23/23 | Jonathan Ok |
| Joseph Quijioc | ReadMe file | 6/15/23 | | |
| | nothing | test | | | 
| Amer al Sayari | | | | |
