//
//  process.h
//  HomeworkStudentScore
//
//  Created by Yu-An Ko on 2016/3/25.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip> // include IO Manipulators to set field width
#include "student.h"
#ifndef process_h
#define process_h
using namespace std;

void readFile(){
    int i, n;
    struct student *s;
    FILE *input;
    input = fopen ("list2.txt", "r");
    
    cout << "Number of student: "; // prompt
    cin >> n; // n: number of students
    
    s = new struct student[n];
    
    if (input == NULL)
    {
        cout << "Failed to open the file.\n";
    }
    
    // name the columns: #, NAME, AGE, SCORE1, SCORE2, SCORE3, AVG.
    cout << "#" << setw(12) << "NAME" << setw(8) << "AGE"<< setw(8) << "SCORE1" << setw(8) << "SCORE2" << setw(8) << "SCORE3" << setw(8) << "AVG.\n" << endl;
    
    for (i = 0; i < n; i++)
    {
        // input from a txt. file
        fscanf (input, "%79s %d %d %d %d", s[i].name, &s[i].age, &s[i].score1, &s[i].score2, &s[i].score3);
        
        // average
        s[i].avg = (s[i].score1 + s[i].score1 + s[i].score1) / 3;
        
        // print results
        cout << i+1 << setw(12) << s[i].name << setw(8) << s[i].age << setw(8) << s[i].score1 << setw(8) << s[i].score2 << setw(8) << s[i].score3 << setw(8) << s[i].avg << "\n" << endl;
    }
    cout << "\n\n";
    fclose(input);
}


 void sortFile(){
 
 }

void printResults(){
    // result: students who got the highest and lowest score.
    cout << "The Highest Score: " << endl;
    cout << "The Lowest Score: " << endl;
    
    // result: sort
    // name the columns: #, NAME, AGE, SCORE1, SCORE2, SCORE3, AVG.
    cout << "Sort by Avg. (from the highest to the lowest): " << endl;
    cout << "#" << setw(12) << "NAME" << setw(8) << "AGE"<< setw(8) << "SCORE1" << setw(8) << "SCORE2" << setw(8) << "SCORE3" << setw(8) << "AVG.\n" << endl;
 }

#endif /* process_h */

