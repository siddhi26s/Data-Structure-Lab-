#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
	if (n <= 0) return NULL;

    NODE head = NULL, last = NULL, newNode;
    int x;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        newNode = createNodeInCLL(x);

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = head;  
    return head;

}

// Traverse CLL
void traverseListInCLL(NODE head) {
if(head == NULL) return;
	NODE temp = head;
	do{
		printf("%d -> ", temp->data);
		temp = temp->next;
		
	}while(temp != head);
	printf("\n");

}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE head, int pos, int data) {
	
 if (pos <= 0) {
        printf("Position not found\n");
        return head;
    }

NODE newNode = createNodeInCLL(data);
 if (head == NULL) {
        if (pos == 1) {
            newNode->next = newNode;
            return newNode;
        } else {
            printf("Position not found\n");
            return head;
        }
    }

    if (pos == 1) {
        NODE temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        return newNode;
    }

    NODE temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && pos > 2) {
        printf("Position not found\n");
        return head;
    }
	{
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE head, int pos) {
	 if (head == NULL || pos <= 0) {
        printf("Position not found\n");
        return head;
    }

    if (pos == 1) {
        if (head->next == head) {
            printf("Deleted element: %d\n", head->data);
            free(head);
            return NULL;
        }

        NODE temp = head;
        while (temp->next != head)
            temp = temp->next;

        NODE delNode = head;
        temp->next = head->next;
        head = head->next;

        printf("Deleted element: %d\n", delNode->data);
        free(delNode);
        return head;
    }

    NODE temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        printf("Position not found\n");
        return head;
    }

    NODE delNode = temp->next;
    temp->next = delNode->next;
	{
    printf("Deleted element: %d\n", delNode->data);
    free(delNode);

    return head;
}
	
	
}

// Reverse CLL
NODE reverseCLL(NODE head) {

	if(head == NULL || head->next == head)
		return head;
	NODE prev = NULL, curr = head, 
	next = NULL;
	NODE last = head;
	do{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		
	}while(curr != head);
	head->next = prev;
	head = prev;
	return head;

}

// Concatenate two CLLs
NODE concatCLL(NODE head1, NODE head2 ) {
	
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    NODE temp1 = head1;
    while (temp1->next != head1)
        temp1 = temp1->next;

    NODE temp2 = head2;
    while (temp2->next != head2)
        temp2 = temp2->next;

    temp1->next = head2;
    temp2->next = head1;

    return head1;


}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
