
#include<stdio.h>
#define maximum 100
struct ba {
    int ID;
    char name[50];
    char num[15];//phone number
};

struct book {

    int ID;
    char title[50];
    char author[50];
    int year;
    int member_ID;
};

struct book books[maximum];
int count2 = 0;
int count1 = 0;
struct ba members[maximum];
void showmenu();
void add1();//to add a new member
void  add2();//to add a new book
void showmembers();
void showbooks();


int main() {
    int select;


    do {
        showmenu();
        scanf_s("%d", &select);
        switch (select) {
        case 1:
            add1();
            break;
        case 2:
            add2();
            break;
        case 3:
            showmembers();
            break;
        case 4:
            showbooks();
            break;
        case 5:
            printf("exiting the pogram.\n");
            break;
        default:
            printf("try again.\n");
        }
    } while (select != 5);

    return 0;
}
void showmenu() {
    printf("Choose one of the following options:\n");
    printf("1 - to add a new member\n");
    printf("2 - to add a new book\n");
    printf("3 - to print all members' information\n");
    printf("4 - to print all books' information\n");
    printf("5 - to quit\n");
}
void add1() {

    struct ba  newmembers;
    int found = 0;


    printf("Enter Member ID: ");
    scanf_s("%d", &newmembers.ID);
    (void)getchar();
    for (int i = 0; i < count1; i++) {
        if (members[i].ID == newmembers.ID) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Member ID already exists. Try again.\n");
        return;
    }

    printf("Enter Name: ");
    gets_s(newmembers.name, 50);
    printf("Enter Phone Number: ");
    scanf_s("%s", newmembers.num, 15);


    members[count1] = newmembers;
    count1++;
    printf("Member added successfully!\n");
}





void  add2() {

    struct book newbook;

    int found = 0;

    printf(" Enter book ID:");
    scanf_s("%d", &newbook.ID);

    for (int i = 0; i < count2; i++) {

        if (books[i].ID == newbook.ID) {

            found = 1;
            break;
        }
    }
    if (found) {
        printf("Member ID already exists. Try again.\n");
        return;
    }
    printf("Enter the Title: ");
    gets_s(newbook.title, sizeof(newbook.title));

    printf("Enter Author: ");
    gets_s(newbook.author, sizeof(newbook.author));

    printf("Enter Year of publication: ");
    scanf_s("%d", &newbook.year);

    newbook.member_ID = 0;
    books[count2] = newbook;
    count2++;

    printf("Book added successfully\n");


}



void showmembers() {
    if (count1 > 0) {
        printf("%-5s%-15s%-25s%-15s\n", "NO.", "Member ID", "Member Name", "Phone");
        printf("===============================================================\n");

        for (int i = 0; i < count1; i++) {
            printf("%-5d%-15d%-25s%-15s\n", i + 1, members[i].ID, members[i].name, members[i].num);
        }

        printf("===============================================================\n");
    }
    else {
        printf("===============================================================\n");

        printf("\nNo members found to print! Please enter a new member from the menu:\n\n");
    }

}


void showbooks() {

    if (count2 > 0) {

        printf("%-5s%-10s%-30s%-25s%-15s%-15s\n", "NO.", "Book ID", "Title", "Author", "Year", "Member ID");
        printf("============================================================================================\n");


        for (int i = 0; i < count2; i++) {
            printf("%-5d%-10d%-30s%-25s%-15d",
                i + 1,
                books[i].ID,
                books[i].title,
                books[i].author,
                books[i].year);

            if (books[i].member_ID == 0) {
                printf("%-15s\n", "Available");
            }
            else {
                printf("%-15d\n", books[i].member_ID);
            }
        }


        printf("============================================================================================\n");
    }
    else {

        printf("============================================================================================\n");
        printf("\nNo books found to print! Please add a new book from the menu.\n\n");
        printf("============================================================================================\n");
    }


}