//
//  StudentInfo.h
//  StudentGrade
//
//  Created by Benjamin DOMERGUE on 22/10/12.
//  Copyright (c) 2012 Benjamin DOMERGUE. All rights reserved.
//

#ifndef __StudentGrade__StudentInfo__
#define __StudentGrade__StudentInfo__

#include <vector>
#include <string>

struct StudentInfo
{
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);
bool did_all_homework(const StudentInfo&);

std::istream& read_student(std::istream&, StudentInfo&);
std::istream& read_homework(std::istream&, std::vector<double>&);

#endif /* defined(__StudentGrade__StudentInfo__) */
