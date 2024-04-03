#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

Contact* create_contact(char* lastname, char* firstname, char* job, char* phone, char* email, char* social_media) {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    if(new_contact == NULL) {
        printf("Error creating new contact.\n");
        exit(1);
    }
    strcpy(new_contact->lastname, lastname);
    strcpy(new_contact->firstname, firstname);
    strcpy(new_contact->job, job);
    strcpy(new_contact->phone, phone);
    strcpy(new_contact->email, email);
    strcpy(new_contact->social_media, social_media);
    new_contact->next = NULL;
    new_contact->prev = NULL;
    return new_contact;
}

void insert_contact(Contact** list, Contact* new_contact) {
    Contact* current = *list;
    if(current == NULL) {
        *list = new_contact;
        return;
    }
    while(current->next != NULL && strcmp(current->lastname, new_contact->lastname) < 0) {
        current = current->next;
    }
    if(strcmp(current->lastname, new_contact->lastname) < 0) {
        new_contact->next = current->next;
        new_contact->prev = current;
        if(current->next != NULL) {
            current->next->prev = new_contact;
        }
        current->next = new_contact;
    } else {
        new_contact->next = current;
        new_contact->prev = current->prev;
        if(current->prev != NULL) {
            current->prev->next = new_contact;
        } else {
            *list = new_contact;
        }
        current->prev = new_contact;
    }
}

void print_contacts(Contact* list) {
    Contact* current = list;
    if(current == NULL) {
        printf("Contact list is empty.\n");
        return;
    }
    while(current != NULL) {
        printf("Lastname: %s\nFirstname: %s\nJob: %s\nPhone: %s\nEmail: %s\nSocial Media: %s\n\n", current->lastname, current->firstname, current->job, current->phone, current->email, current->social_media);
        current = current->next;
    }
}

void delete_contact(Contact** list, char* lastname, char* firstname) {
    Contact* current = *list;
    while(current != NULL) {
        if(strcmp(current->lastname, lastname) == 0 && strcmp(current->firstname, firstname) == 0) {
            if(current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *list = current->next;
            }
            if(current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

