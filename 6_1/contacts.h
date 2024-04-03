#ifndef CONTACTS_H
#define CONTACTS_H

typedef struct Contact {
    char firstName[50];
    char lastName[50];
    char jobTitle[50];
    char company[50];
    char phoneNumber[15];
    char email[50];
    char twitter[50];
    struct Contact* next;
} Contact;

Contact* createContact(char* firstName, char* lastName, char* jobTitle, char* company, char* phoneNumber, char* email, char* twitter);
void insertContact(Contact** head, Contact* newContact);
void displayContacts(Contact* head);
int deleteContact(Contact** head, char* firstName, char* lastName);

#endif

