#pragma once
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Entities.h"
#include "UI.h"

#include <vector>
#include <string>

using namespace std;

// ─────────────────────────────────────────────
//  Department
//  Owns and manages all courses, instructors,
//  and students for the registration system.
// ─────────────────────────────────────────────
class Department {
private:
    UI* ui;

public:
    vector<Course*>     courses;
    vector<Instructor*> instructors;
    vector<Student*>    students;

    explicit Department(UI* ui) : ui(ui) {}

    ~Department() {
        for (auto c : courses)     delete c;
        for (auto i : instructors) delete i;
        for (auto s : students)    delete s;
    }

    // ── Courses ──────────────────────────────
    void addCourse(const string& name, const string& id, int seats) {
        courses.push_back(new Course(name, id, seats));
        ui->displayLine("Course added successfully.");
    }

    void deleteCourse(const string& id) {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i]->id == id) {
                delete courses[i];
                courses.erase(courses.begin() + i);
                ui->displayLine("Course deleted successfully.");
                return;
            }
        }
        ui->displayLine("Error: Course not found.");
    }

    void listCourses() const {
        if (courses.empty()) {
            ui->displayLine("No courses registered yet.");
            return;
        }
        ui->displayLine("\n--- Course List ---");
        for (auto c : courses) {
            string line = "[" + c->id + "] " + c->name
                        + "  (Seats: " + to_string(c->seats) + ")";

            if (c->instructor)
                line += "  | Instructor: " + c->instructor->name;

            if (!c->prerequisites.empty()) {
                line += "  | Prerequisites: ";
                for (auto p : c->prerequisites)
                    line += p->id + " ";
            }
            ui->displayLine(line);
        }
    }

    // ── Instructors ───────────────────────────
    void addInstructor(const string& name, const string& id) {
        instructors.push_back(new Instructor(name, id));
        ui->displayLine("Instructor added successfully.");
    }

    void assignInstructorToCourse(const string& courseID, const string& instructorID) {
        Course*     c = findCourse(courseID);
        Instructor* i = findInstructor(instructorID);
        if (c && i) {
            c->assignInstructor(i);
            ui->displayLine("Instructor assigned successfully.");
        } else {
            ui->displayLine("Error: Course or Instructor not found.");
        }
    }

    // ── Students ──────────────────────────────
    void addStudent(const string& name, const string& id) {
        students.push_back(new Student(name, id));
        ui->displayLine("Student added successfully.");
    }

    // ── Prerequisites ─────────────────────────
    void addPrerequisite(const string& courseID, const string& prereqID) {
        Course* course = findCourse(courseID);
        Course* prereq = findCourse(prereqID);
        if (course && prereq) {
            course->addPrerequisite(prereq);
            ui->displayLine("Prerequisite added successfully.");
        } else {
            ui->displayLine("Error: Course or prerequisite not found.");
        }
    }

    // ── Lookup helpers ────────────────────────
    Instructor* findInstructor(const string& id) const {
        for (auto i : instructors)
            if (i->id == id) return i;
        return nullptr;
    }

    Course* findCourse(const string& id) const {
        for (auto c : courses)
            if (c->id == id) return c;
        return nullptr;
    }
};

#endif // DEPARTMENT_H
