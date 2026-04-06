# University Registration System

A console-based C++ application for managing university course registrations. Built as an OOP project demonstrating class design, composition, and clean separation of concerns.

## Features

- **Admin authentication** — register and log in with admin accounts
- **Course management** — add, delete, and list courses with seat capacity
- **Instructor management** — add instructors and assign them to courses
- **Student management** — add students to the system
- **Prerequisites** — define prerequisite chains between courses

## Project Structure

```
UniversityRegistrationSystem/
├── include/
│   ├── Entities.h       # Course, Instructor, Student classes
│   ├── UI.h             # Console I/O wrapper
│   ├── Department.h     # Manages all entities
│   └── AdminSystem.h    # Auth + admin menu
├── src/
│   └── main.cpp         # Entry point
├── Makefile
├── .gitignore
└── README.md
```

## Build & Run

### Windows (MSVC — Visual Studio)

Open the `.vcxproj` file in Visual Studio and build normally.


## Class Design

| Class | Responsibility |
|---|---|
| `UI` | Thin wrapper around `cin` / `cout` — keeps I/O out of business logic |
| `Entities` (`Course`, `Instructor`, `Student`) | Plain data classes |
| `Department` | Owns and manages all entities; exposes CRUD operations |
| `AdminSystem` | Handles login, admin registration, and the admin menu |

