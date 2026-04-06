#pragma once
#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
//  Instructor
// ─────────────────────────────────────────────
class Instructor {
public:
    string name;
    string id;

    Instructor(const string& name, const string& id)
        : name(name), id(id) {}
};

// ─────────────────────────────────────────────
//  Student
// ─────────────────────────────────────────────
class Student {
public:
    string name;
    string id;

    Student(const string& name, const string& id)
        : name(name), id(id) {}
};

// ─────────────────────────────────────────────
//  Course
// ─────────────────────────────────────────────
class Course {
public:
    string       name;
    string       id;
    int          seats;
    Instructor*  instructor;
    vector<Course*> prerequisites;

    Course(const string& name, const string& id, int seats)
        : name(name), id(id), seats(seats), instructor(nullptr) {}

    void assignInstructor(Instructor* instr) {
        instructor = instr;
    }

    void addPrerequisite(Course* course) {
        prerequisites.push_back(course);
    }
};

#endif // ENTITIES_H
