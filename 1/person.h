#ifndef PERSON_H
#define PERSON_H
struct Contact {
    char last_name[50];
    char first_name[50];
    char phone_numbers[15]; //  max 15 characters each
    struct Soc soci;
    struct Work wor;
};
#endif
