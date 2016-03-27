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

void process(){
    
    int i, n;
    
    cout << "Number of student: "; // prompt
    cin >> n; // n: number of students
    
    struct student *s;
    s = new struct student[n];

/*
--------------------READ FILE--------------------
*/

    FILE *input;
    input = fopen ("list2.txt", "r");

    // error message
    if (input == NULL)
    {
        cout << "Failed to open the file.\n";
    }
    
    // input from a txt. file
    for (i = 0; i < n; i++)
    {
        fscanf (input, "%79s %d %d %d %d", s[i].name, &s[i].age, &s[i].score1, &s[i].score2, &s[i].score3);
       }
    
/*
--------------------AVG.--------------------
*/
    
    for (i = 0; i < n; i++)
    {
        double avg = (s[i].score1 + s[i].score2 + s[i].score3) / 3.0;
        s[i].avg = avg;
    }
    
    // name the columns: #, NAME, AGE, SCORE1, SCORE2, SCORE3, AVG.
    cout << "\n\n#" << setw(12) << "NAME" << setw(8) << "AGE"<< setw(8) << "SCORE1" << setw(8) << "SCORE2" << setw(8) << "SCORE3" << setw(12) << "AVG." << endl;
    cout << "----------------------------------------------------------" << endl;
    
    // print results
    for (i = 0; i < n; i++){
        cout << i+1 << setw(12) << s[i].name << setw(8) << s[i].age << setw(8) << s[i].score1 << setw(8) << s[i].score2 << setw(8) << s[i].score3 << setw(12) << s[i].avg << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    
/*
--------------------find MAX--------------------
*/
    
    int max = s[0].avg;
    string  max_stu;
    for (i = 0; i < n; i++){
        if (s[i].avg > max){
            max = s[i].avg;
            max_stu = s[i].name;
        }
    }
    
    cout << "\nTHE HIGHEST SCORE: " << max << endl;
    cout << "Student with the highest score: " << max_stu << endl;
/*
--------------------find MIN--------------------
*/
    
    int min = s[0].avg;
    string  min_stu;
    for (i = 0; i < n; i++){
        if (s[i].avg < min){
            min = s[i].avg;
            min_stu = s[i].name;
        }
    }
    cout << "\nTHE LOWEST SCORE: " << min << endl;
    cout << "Student with the lowest score: " << min_stu << endl;
    
/*
--------------------Bubble Sort--------------------
*/

    int j;
    struct student temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (s[j].avg < s[j + 1].avg)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // name the columns: #, NAME, AGE, SCORE1, SCORE2, SCORE3, AVG.
    cout << "\n\n#" << setw(12) << "NAME" << setw(8) << "AGE"<< setw(8) << "SCORE1" << setw(8) << "SCORE2" << setw(8) << "SCORE3" << setw(12) << "AVG." << endl;
    cout << "----------------------------------------------------------" << endl;
    
    // print results
    for (i = 0; i < n; i++){
        cout << i+1 << setw(12) << s[i].name << setw(8) << s[i].age << setw(8) << s[i].score1 << setw(8) << s[i].score2 << setw(8) << s[i].score3 << setw(12) << s[i].avg << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    
/*
--------------------END--------------------
*/

    cout << "\n\n";
    fclose(input);
}

#endif /* process_h */

