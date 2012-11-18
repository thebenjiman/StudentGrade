//
//  grade.h
//  StudentGrade
//
//  Created by Benjamin DOMERGUE on 23/10/12.
//  Copyright (c) 2012 Benjamin DOMERGUE. All rights reserved.
//

#ifndef __StudentGrade__grade__
#define __StudentGrade__grade__

#include <vector>

#include "StudentInfo.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const StudentInfo&);

#endif /* defined(__StudentGrade__grade__) */
