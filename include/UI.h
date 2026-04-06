#pragma once
#ifndef UI_H
#define UI_H

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// ─────────────────────────────────────────────
//  UI — thin console I/O wrapper
// ─────────────────────────────────────────────
class UI {
public:
    void display(const string& msg) const {
        cout << msg;
    }

    void displayLine(const string& msg) const {
        cout << msg << "\n";
    }

    string readString(const string& prompt) const {
        display(prompt);
        string input;
        getline(cin, input);
        return input;
    }

    int readInt(const string& prompt) const {
        display(prompt);
        int value;
        cin >> value;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
};

#endif // UI_H
