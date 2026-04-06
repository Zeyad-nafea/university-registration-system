#include "AdminSystem.h"

// ─────────────────────────────────────────────
//  University Registration System — Entry Point
// ─────────────────────────────────────────────
int main() {
    UI          ui;
    AdminSystem system;
    int         choice;

    do {
        ui.displayLine("\n====== University Registration System ======");
        ui.displayLine("1. Admin Login");
        ui.displayLine("2. Register New Admin");
        ui.displayLine("3. Exit");
        choice = ui.readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                if (system.hasAdmins())
                    system.run();
                else
                    ui.displayLine("No admins registered yet. Please register first.");
                break;
            case 2:
                system.registerAdmin();
                break;
            case 3:
                ui.displayLine("Exiting system. Goodbye!");
                break;
            default:
                ui.displayLine("Invalid choice. Try again.");
        }
    } while (choice != 3);

    return 0;
}
