#include <stdio.h>
#include "copy.h"
#include <string.h>
#include "two.h"
#include "one.h"
#include "person.h"
#define MAX_CONTACTS 100
int size = 0;



struct Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (size < 100) {
        printf("Input last_name: ");
        scanf("%s", contacts[size].last_name);
        printf("Input first_name: ");
        scanf("%s", contacts[size].first_name);
        printf("Do you want to insert phone? 0-No, 1-Yes  ");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            printf("Input phone");
            scanf("%s", contacts[size].phone_numbers);
        }
        printf("Do you want to insert work? 0-No, 1-Yes   ");
        flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            printf("Input work");
            scanf("%s", contacts[size].wor.work);
            printf("Input position");
            scanf("%s", contacts[size].wor.position);
        }
        printf("Do you want to social service? 0-No, 1-Yes   ");
        flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            printf("Input email:  ");
            scanf("%s", contacts[size].soci.emails);
            printf("Input messengers:   ");
            scanf("%s", contacts[size].soci.messengers);
            printf("Input social service:   ");
            scanf("%s", contacts[size].soci.social_media);
        }
    }
    size++;
    printf("Finished");
}
void edit_contact() {
    printf("Input number of the person:\n");
    for (int i = 0; i < size; i++){
        printf("%d )   %s   %s", i, contacts[i].last_name, contacts[i].first_name);
    }
    int flag = 0;
    int flag1 = 0;
    scanf("%d", &flag);
    if (flag < size) {
        printf("What to change?\n 1)Work\n 2)Social service\n 3)Phone number\n");
        scanf("%d", &flag1);
        if (flag1 == 1) {
            printf("Input work:   ");
            scanf("%s", contacts[flag].wor.work);
            printf("Input position:    ");
            scanf("%s", contacts[flag].wor.position);
        }
        if (flag1 == 2) {
            printf("Input email:  ");
            scanf("%s", contacts[flag].soci.emails);
            printf("Input messengers:  ");
            scanf("%s", contacts[flag].soci.messengers);
            printf("Input social service:  ");
            scanf("%s", contacts[flag].soci.social_media);
        }
        if (flag1 == 3) {
            printf("Input phone:   ");
            scanf("%s", contacts[flag].phone_numbers);
        }
    }
}
void delete_contact() {
    printf("Input number of the person:\n");
    for (int i = 0; i < size; i++) {
        printf("%d )   %s %s", i, contacts[i].last_name, contacts[i].first_name);
    }
    int flag = 0;
    scanf("%d", &flag);
    memset(contacts[flag].last_name, 0, sizeof(contacts[flag].last_name));
    memset(contacts[flag].first_name, 0, sizeof(contacts[flag].first_name));
    memset(contacts[flag].phone_numbers, 0, sizeof(contacts[flag].phone_numbers));
    memset(contacts[flag].soci.emails, 0, sizeof(contacts[flag].soci.emails));
    memset(contacts[flag].soci.messengers, 0, sizeof(contacts[flag].soci.messengers));
    memset(contacts[flag].soci.social_media, 0, sizeof(contacts[flag].soci.social_media));
    memset(contacts[flag].wor.position, 0, sizeof(contacts[flag].wor.position));
    memset(contacts[flag].wor.work, 0, sizeof(contacts[flag].wor.work));
}
void display_contacts() {
    printf("Database composition\n");
    for (int i = 0; i < size; i++) {
        printf("%d )   %s %s", i, contacts[i].last_name, contacts[i].first_name);
    }
    printf("\nDo you want to display information the person? 0 - No,  1 - Yes:    ");
    int flag = 0;
    scanf("%d", &flag);
    if (flag==1){
    	printf("Number person: \n");
        int flag1 = 0;
        scanf("%d", &flag1);
        printf("Lastname  %s\n", contacts[flag1].last_name);
        printf("First name  %s\n", contacts[flag1].first_name);
        printf("Phone   %s\n", contacts[flag1].phone_numbers);
        printf("Email   %s\n", contacts[flag1].soci.emails);
        printf("Messenger  %s\n", contacts[flag1].soci.messengers);
        printf("Social media  %s\n", contacts[flag1].soci.social_media);
        printf("Position  %s\n", contacts[flag1].wor.position);
        printf("Work  %s\n", contacts[flag1].wor.work);
    }
}
