#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int page;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* curr = NULL;
void insertPage(int id) 
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->page = id;
    n->next = NULL;
    n->prev = NULL;
    if(head == NULL) 
    {
        head = n;
        curr = head;
    } 
    else
    {
        struct Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
        n->prev = temp;
        curr = n;
    }
    printf("Visited page %d\n", id);
}
void moveForward() 
{
    if(curr != NULL && curr->next != NULL) 
    {
        curr = curr->next;
        printf("Moved forward to page %d\n", curr->page);
    } 
    else 
    {
        printf("Already at the latest page. Forward not possible.\n");
    }
}
void moveBackward() {
    if(curr != NULL && curr->prev != NULL)
    {
        curr = curr->prev;
        printf("Moved backward to page %d\n", curr->page);
    } 
    else
    {
        printf("Already at the first page. Backward not possible.\n");
    }
}
void displayForward()
{
    if(head == NULL)
    {
        printf("No browsing history.\n");
        return;
    }
    struct Node* temp = head;
    printf("Pages (First-to-Last): ");
    while(temp != NULL) 
    {
        printf("%d ", temp->page);
        temp = temp->next;
    }
    printf("\n");
}
void displayBackward()
{
    if(head == NULL)
    {
        printf("No browsing history.\n");
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    printf("Pages (Last-to-First): ");
    while(temp != NULL) 
    {
        printf("%d ", temp->page);
        temp = temp->prev;
    }
    printf("\n");
}
void deletePage(int id) 
{
    if(head == NULL)
    {
        printf("History empty, cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL && temp->page != id) temp = temp->next;
    if(temp == NULL) 
    {
        printf("Page %d not found in history.\n", id);
        return;
    }
    if(temp == head) 
    head = temp->next;
    if(temp->prev != NULL) 
    temp->prev->next = temp->next;
    if(temp->next != NULL) 
    temp->next->prev = temp->prev;
    if(curr == temp) 
    curr = (temp->next != NULL) ? temp->next : temp->prev;
    free(temp);
    printf("Page %d deleted from history.\n", id);
}
int main()
{
    int choice, id;
    while(1) 
    {
        printf("1.Visit Page 2.Forward 3.Backward 4.Display Fwd 5.Display Back 6.Delete Page 7.Exit: ");
        scanf("%d", &choice);
        if(choice == 1) 
        {
            printf("Enter Page ID: ");
            scanf("%d", &id);
            insertPage(id);
        } 
        else if(choice == 2) 
        {
            moveForward();
        } 
        else if(choice == 3)
        {
            moveBackward();
        } 
        else if(choice == 4)
        {
            displayForward();
        } 
        else if(choice == 5)
        {
            displayBackward();
        } 
        else if(choice == 6)
        {
            printf("Enter Page ID to delete: ");
            scanf("%d", &id);
            deletePage(id);
        } 
        else if(choice == 7)
        {
            break;
        } 
        else 
        {
            printf("Invalid selection!\n");
        }
    }
    return 0;
}
