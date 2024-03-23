#include <stdio.h>
#include "copy.h"
#include "two.h"
#include "one.h"
#include "person.h"
int main() {
    int choice;
    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Edit Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            edit_contact();
            break;
        case 3:
            delete_contact();
            break;
        case 4:
            display_contacts();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
