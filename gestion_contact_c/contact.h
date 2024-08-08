#ifndef CONTACT_H
#define CONTACT_H

#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

#endif // CONTACT_H

