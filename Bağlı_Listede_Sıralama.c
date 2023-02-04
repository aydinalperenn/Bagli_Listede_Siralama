/*
   Alperen Aydın
*/

// C program which sorts According to alphabet (right and back) in 2 different groups (male and female)



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Creating the struct
struct Student
{
    char name[50];
    char gender;
    struct Student * next;
};

int checkTheListSituation (struct Student* list){
    if(list == NULL){ // Check whether the list is empty
        return -1;
    }
    else if(list->next == NULL){ // Check whether the list has only one element
        return 0;
    }
    else{
        return 1;
    }

}


struct Student * insertNode (char *name, char gender, struct Student * list)
{
    struct Student *s;

    //Allocate memory for node (malloc operation)
    s = malloc (sizeof (struct Student));
    if (s == NULL)
    {
        printf ("Memory allocation failed.");
        return list;
    }
    strcpy(s->name, name);
    s->gender = gender;
    s->next = list; //list is the start of the list
    list = s;

    return list;
}



struct Student* sortForGender(struct Student *list){

    int condition = checkTheListSituation(list);
    if(condition==-1){
        printf("The list is empty\n");
        return list;
    }
    else if (condition == 0){
        printf("The list has just one element, so it does not need to sort.\n");
        return list;
    }

    struct Student* current = list;
    struct Student* prev = NULL;
    struct Student* after = NULL;

    int isSorted = 0;   // It is a temp variable to check whether the list be sorted



    while (isSorted!=1) {

        isSorted = 1; // For first while loop

        for( ; current->next!=NULL ;){  // I can use the basic while loop like above, but as I am too bored, I want to make a basic change. It is not important  :)

            after = current->next; // Save next node in the list

            if (after != NULL && current->gender > after->gender) { // if gender of next is smaller than gender of current, then swap
                isSorted = 0; // It is make continue the loop for sorting

                // Swap current and next nodes:
                current->next = after->next;
                after->next = current;


                if (prev == NULL) { // If current node is the first node in the list, update the head of the list
                    list = after;
                }

                else { // Update the previous node's next pointer to point to the next node
                    prev->next = after;
                }

                // Update current and prev nodes
                prev = after;
                current = after->next;
            }

            else { // If the gender of current is smaller or equal to the gender of next, then continue to the next
                prev = current;
                current = current->next;
            }
        }

        // Reset variables for the next iteration
        current = list;
        prev = NULL;
        after = NULL;
    }

    return list;
}

struct Student* sortFemalesRightAlphabetically(struct Student *list){

    int condition = checkTheListSituation(list);
    if(condition==-1){
        return list;
    }
    else if (condition == 0){
        return list;
    }

    struct Student* current = list;
    struct Student* prev = NULL;
    struct Student* after = NULL;

    int isSorted = 0;   // It is a temp variable to check whether the list be sorted

    while (isSorted!=1) {

        isSorted = 1; // For first while loop

        while (current != NULL) {
            after = current->next; // Save next node in the list
                                                                                        //current->name > next->name
            if ( current->gender == 'F' && after->gender == 'F' && after != NULL && strcmp(current->name, after->name)>0) { // if name of next is smaller than name of current, then swap
                isSorted = 0; // It is make continue the loop for sorting

                // Swap current and next nodes:
                current->next = after->next;
                after->next = current;


                if (prev == NULL) { // If current node is the first node in the list, update the head of the list
                    list = after;
                }

                else { // Update the previous node's next pointer to point to the next node
                    prev->next = after;
                }

                // Update current and prev nodes
                prev = after;
                current = after->next;
            }

            else { // If the name of current is smaller or equal to the name of next, then continue to the next
                prev = current;
                current = current->next;
            }
        }

        // Reset variables for the next iteration
        current = list;
        prev = NULL;
        after = NULL;
    }

    return list;

}

struct Student* sortMalesBackAlphabetically(struct Student *list){

    int condition = checkTheListSituation(list);
    if(condition==-1){
        return list;
    }
    else if (condition == 0){
        return list;
    }

    struct Student* current = list;
    struct Student* prev = NULL;
    struct Student* after = NULL;

    int isSorted = 0;   // It is a temp variable to check whether the list be sorted

    while (isSorted!=1) {

        isSorted = 1; // For first while loop

        while (current != NULL && current->next != NULL) {
            after = current->next; // Save next node in the list
                                                                        //current->name > next->name
            if ( current->gender == 'M' && after->gender == 'M' && after != NULL && strcmp(current->name, after->name)<0) { // if name of next is smaller than name of current, then swap
                isSorted = 0; // It is make continue the loop for sorting

                // Swap current and next nodes:
                current->next = after->next;
                after->next = current;


                if (prev == NULL) { // If current node is the first node in the list, update the head of the list
                    list = after;
                }

                else { // Update the previous node's next pointer to point to the next node
                    prev->next = after;
                }

                // Update current and prev nodes
                prev = after;
                current = after->next;
            }

            else { // If the name of current is smaller or equal to the name of next, then continue to the next
                prev = current;
                current = current->next;
            }
        }

        // Reset variables for the next iteration
        current = list;
        prev = NULL;
        after = NULL;
    }

    return list;

}




//Sorting function
struct Student * sortList (struct Student *list)
{
//Write your code here

   list = sortForGender(list);
   list = sortFemalesRightAlphabetically(list);
   list = sortMalesBackAlphabetically(list);


    return list;
}



//Printing function
void printList (struct Student * list)
{
    while (list != NULL)
    {
        printf ("%s\t%c\n", list->name, list->gender);
        list = list->next;
    }
}


int main ()
{
    //Creating an Initial Node Variable
    struct Student * head=NULL;

    //Call to functions
    head = insertNode("Cenk", 'M', head);
    head = insertNode("Ceyda", 'F', head);
    head = insertNode("Esra", 'F', head);
    head = insertNode("Okan", 'M', head);
    head = insertNode("Tugce", 'F', head);
    head = insertNode("Mehmet", 'M', head);
    head = insertNode("Ayse", 'F', head);
    head = insertNode("Merve", 'F', head);
    head = insertNode("Sedat", 'M', head);
    head = insertNode("Ahmet", 'M', head);


    //call to sorting function
    head = sortList(head);
    printList(head);

}

