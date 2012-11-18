//
//  grade.cpp
//  StudentGrade
//
//  Created by Benjamin DOMERGUE on 23/10/12.
//  Copyright (c) 2012 Benjamin DOMERGUE. All rights reserved.
//

#include "grade.h"
#include "median.h"

using namespace std;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework)
{
	if(homework.size() == 0)
	{
		throw domain_error("Student has done no homework");
	}
	return grade(midterm, final, vector_median(homework));
}

double grade(const StudentInfo& student)
{
	return grade(student.midterm, student.final, student.homework);
}
