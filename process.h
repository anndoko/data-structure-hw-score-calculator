//
//  process.h
//  HomeworkStudentScore
//
//  Created by Yu-An Ko on 2016/3/25.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip> // include IO Manipulators to set field width
#ifndef process_h
#define process_h
#include "student.h"
using namespace std;

void readFile(){
    
    struct STUDENT data;    // use structure
    
    // start:
    
    FILE *input = NULL;
    input = fopen("list1.txt", "r");    //open the file (r: read only)
    
    cout << "Score Calculator Data: \n\n";
    
    while( fscanf( input, "%s", data.name )!=EOF ){ // EOF: end of file
        fscanf( input, "%d", &(data.age) );
        fscanf( input, "%d", &(data.score) );
        
        cout << data.name << setw(12) << data.age << setw(4) << data.score << endl;
    }
    
    if((input = NULL)){
        cout << "Failed to open the file."; // Error message
        return;
    }
    
    // exit:
    cout << "\n\n";
    fclose(input);
    system("PAUSE");
    
}

#endif /* process_h */
