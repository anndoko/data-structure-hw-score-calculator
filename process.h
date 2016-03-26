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
    
    cin >> n;
    
    s = new struct student[n];
    
    if (input == NULL)
    {
        cout << "Couldn't open student file\n";
    }
    for (i = 0; i < n; i++)
    {
        // input from a txt. file
        fscanf (input, "%79s %d %d %d %d", s[i].name, &s[i].age, &s[i].score1, &s[i].score2, &s[i].score3);
        
        // average
        s[i].avg = (s[i].score1 + s[i].score1 + s[i].score1) / 3;
        
        // print result
        cout << i+1 << "  " << s[i].name << setw(4) << s[i].age << setw(4) << s[i].score1 << setw(4) << s[i].score2 << setw(4) << s[i].score3 << setw(4) << s[i].avg << endl;
    }
    cout << "\n\n";
    fclose(input);
    system("PAUSE");
}


/*
 void sortFile(){
 
 }
 
 void printFile(){
 
 }
 */

#endif /* process_h */

