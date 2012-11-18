//
//  StudentInfo.cpp
//  StudentGrade
//
//  Created by Benjamin DOMERGUE on 22/10/12.
//  Copyright (c) 2012 Benjamin DOMERGUE. All rights reserved.
//

#include "StudentInfo.h"

#include <iostream>
#include <vector>

using namespace std;

istream& read_homework(istream& in, vector<double>& homework)
{
	if(in)
	{
		homework.clear();
		
		double x;
		while(in >> x)
		{
			homework.push_back(x);
		}
		
		in.clear();
	}
	return in;
}

istream& read_student(istream& in, StudentInfo& student)
{
	in >> student.name >> student.midterm >> student.final;
	read_homework(in, student.homework);
	return in;
}

bool compare(const StudentInfo& x, const StudentInfo& y)
{
	return x.name < y.name;
}

bool did_all_homework(const StudentInfo& student)
{
	return (find(student.homework.begin(), student.homework.end(), 0) == student.homework.end());
}
