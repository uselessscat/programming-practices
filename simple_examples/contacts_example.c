#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* The contact data */
struct Contact {
    char name[51];
    char email[256];
    char phone[21];
    
    // linked list
    struct Contact *previous;
    struct Contact *next;
};

/* pointers to head and tail of the list */
struct Contact *firstContact, *lastContact;

/* contact list functions */
void addContact(struct Contact *contact){
    if (firstContact == NULL){
        // the actual contact is the only
        firstContact = contact;
        lastContact = contact;
        
        // and dont have siblings elements
        contact->previous = NULL;
        contact->next = NULL;
    } else {
        // update references inside the actual contact
        contact->previous = lastContact;
        contact->next = NULL;
        
        // update next element in the old last (penultimate)
        lastContact->next = contact;
        
        // update last contact to point the new element
        lastContact = contact;
    }
}

void deleteContact(struct Contact *contact){
    if(contact != NULL){
        struct Contact *prev = contact->previous,
                       *next = contact->next;
        
        // logic to update the pointers in other elements
        if (contact == firstContact){
            if (next != NULL){
                firstContact = next;
                next->previous = NULL;
            } else {
                firstContact = NULL;
                lastContact = NULL;
            }
        } else if(contact == lastContact){
            if (prev != NULL){
                lastContact = prev;
                prev->next = NULL;
            } else {
                firstContact = NULL;
                lastContact = NULL;
            }
        } else {
            prev->next = next;
            next->previous = prev;
        }
        
        // i assume that contacts are allocated, so i have to free that mem
        free(contact);
    }
}

void deleteContactByIndex(int index){
    int i = 0;
    struct Contact *contact = firstContact;
    
    // update *contact to point the correct index
    while (contact != NULL && i < index){
        contact = contact->next;
        i++;
    }
    
    // delete contact at selected index
    if(contact != NULL){
        deleteContact(contact);
    }
}

/* contact utils */
void printContact(struct Contact *contact){
    printf("<Contact: name: %s, email: %s, phone: %s>\n", contact->name, contact->email, contact->phone);
}
 
void createContact(){
    struct Contact *contact = (struct Contact*) malloc(sizeof(struct Contact));

    printf("Ingrese el nombre: ");
    scanf(" %50[^\n]s", contact->name);
    
    printf("Ingrese el email: ");
    scanf(" %250[^\n]s", contact->email);
    
    printf("Ingrese el telefono: ");
    scanf(" %20[^\n]s", contact->phone);
    
    addContact(contact);
}

void deleteContactMenu(){
    int indice = 0;
    
    printf("Ingrese el contacto a eliminar: ");
    scanf("%d", &indice);
    
    deleteContactByIndex(indice);
}

void printAllContacts(){
    int i = 0;
    struct Contact *contact = firstContact;
    
    printf("Mostrando los contactos:\n");
    
    while (contact != NULL) {
        printf("%d) %s %s %s\n", i++, contact->name, contact->email, contact->phone);
        
        contact = contact->next;
    }
}

/* app menu actions */
void showOptions(){
    printf(
        "Ingrese una opcion:\n"
        "1) Mostrar los contactos\n"
        "2) Ingresar contacto.\n"
        "3) Eliminar contacto.\n"
        "0) Salir.\n"
        "Opcion: "
    );
}

void *selectOption(int selectedOption){
    // return the function that handles the selected option
    switch (selectedOption) {
        case 1:
            return printAllContacts;
        case 2:
            return createContact;
        case 3:
            return deleteContactMenu;
        default:
            return NULL;
    }
}

/* MAIN FUNCION */
int main() {
    int selectedOption = 0;
    
    do {
        // show menu
        showOptions();
        
        // read the option
        scanf("%d", &selectedOption);
        
        // get the function (as pointer) that handles the option
        void (*selectedFunction)(void) = selectOption(selectedOption);
        
        // call the function
        if(selectedFunction != NULL){
            selectedFunction();
        }
    } while (selectedOption != 0);
    
    return 0;
}
