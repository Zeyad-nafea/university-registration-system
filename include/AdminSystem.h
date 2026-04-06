#pragma once
#ifndef ADMINSYSTEM_H
#define ADMINSYSTEM_H

#include "Department.h"
#include "UI.h"

#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
//  AdminSystem
//  Handles admin authentication and exposes the
//  administration menu for managing the department.
// ─────────────────────────────────────────────
class AdminSystem {
private:
    UI         ui;
    Department department;

    struct AdminAccount {
        string username;
        string password;
    };

    vector<AdminAccount> admins;

    // ── Auth ──────────────────────────────────
    bool login() {
        ui.displayLine("\n--- Admin Login ---");
        string username = ui.readString("Username: ");
        string password = ui.readString("Password: ");

        for (const auto& a : admins) {
            if (a.username == username && a.password == password) {
                ui.displayLine("Login successful! Welcome, " + username + ".");
                return true;
            }
        }
        ui.displayLine("Error: Invalid username or password.");
        return false;
    }

    // ── Admin menu ────────────────────────────
    void adminMenu() {
        int choice;
        do {
            ui.displayLine("\n====== Admin Menu ======");
            ui.displayLine("1. Add Course");
            ui.displayLine("2. Delete Course");
            ui.displayLine("3. List Courses");
            ui.displayLine("4. Add Instructor");
            ui.displayLine("5. Assign Instructor to Course");
            ui.displayLine("6. Add Prerequisite to Course");
            ui.displayLine("7. Add Student");
            ui.displayLine("8. Logout");
            choice = ui.readInt("Choose: ");

            switch (choice) {
                case 1: addCourse();                  break;
                case 2: deleteCourse();               break;
                case 3: department.listCourses();     break;
                case 4: addInstructor();              break;
                case 5: assignInstructor();           break;
                case 6: addPrerequisite();            break;
                case 7: addStudent();                 break;
                case 8: ui.displayLine("Logged out."); break;
                default: ui.displayLine("Invalid choice. Try again."); break;
            }
        } while (choice != 8);
    }

    // ── Action helpers ────────────────────────
    void addCourse() {
        string name = ui.readString("Course Name: ");
        string id   = ui.readString("Course ID:   ");
        int seats   = ui.readInt("Seats:       ");
        department.addCourse(name, id, seats);
    }

    void deleteCourse() {
        string id = ui.readString("Course ID to delete: ");
        department.deleteCourse(id);
    }

    void addInstructor() {
        string name = ui.readString("Instructor Name: ");
        string id   = ui.readString("Instructor ID:   ");
        department.addInstructor(name, id);
    }

    void addStudent() {
        string name = ui.readString("Student Name: ");
        string id   = ui.readString("Student ID:   ");
        department.addStudent(name, id);
    }

    void assignInstructor() {
        string courseID     = ui.readString("Course ID:     ");
        string instructorID = ui.readString("Instructor ID: ");
        department.assignInstructorToCourse(courseID, instructorID);
    }

    void addPrerequisite() {
        string courseID = ui.readString("Course ID:              ");
        string prereqID = ui.readString("Prerequisite Course ID: ");
        department.addPrerequisite(courseID, prereqID);
    }

public:
    AdminSystem() : department(&ui) {}

    // Entry point — only proceeds if login succeeds
    void run() {
        if (login())
            adminMenu();
    }

    void registerAdmin() {
        ui.displayLine("\n--- Register New Admin ---");
        string username = ui.readString("Username: ");
        string password = ui.readString("Password: ");
        admins.push_back({ username, password });
        ui.displayLine("Admin account created successfully.");
    }

    bool hasAdmins() const {
        return !admins.empty();
    }
};

#endif // ADMINSYSTEM_H
