#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contacts.h"

Contact* createContact(char* firstName, char* lastName, char* jobTitle, char* company, char* phoneNumber, char* email, char* twitter) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if(newContact == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strncpy(newContact->firstName, firstName, 50);
    strncpy(newContact->lastName, lastName, 50);
    strncpy(newContact->jobTitle, jobTitle, 50);
    strncpy(newContact->company, company, 50);
    strncpy(newContact->phoneNumber, phoneNumber, 15);
    strncpy(newContact->email, email, 50);
    strncpy(newContact->twitter, twitter, 50);

    newContact->next = NULL;

    return newContact;
}

void insertContact(Contact** head, Contact* newContact) {
    if(*head == NULL) {
        *head = newContact;
    } else {
        newContact->next = *head;
        *head = newContact;
    }
}

void displayContacts(Contact* head) {
    if(head == NULL) {
        printf("Contact list is empty.\n");
    } else {
        Contact* current = head;
        while(current != NULL) {
            printf("Name: %s %s\n", current->firstName, current->lastName);
            printf("Job Title: %s\n", current->jobTitle);
            printf("Company: %s\n", current->company);
            printf("Phone Number: %s\n", current->phoneNumber);
            printf("Email: %s\n", current->email);
            printf("Twitter: %s\n", current->twitter);
            printf("\n");
            current = current->next;
        }
    }
}

int deleteContact(Contact** head, char* firstName, char* lastName) {
    if(*head == NULL) {
        return 0;
    }

    Contact* current = *head;
    Contact* prev = NULL;

    while(current != NULL && (strcmp(current->firstName, firstName) != 0 || strcmp(current->lastName, lastName) != 0)) {
        prev = current;
        current = current->next;
    }

    if(current == NULL) {
        return 0;
    }

    if(prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);

    return 1;
}

