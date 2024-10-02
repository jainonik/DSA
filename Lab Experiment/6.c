// // Q.  Represent a 2-variable polynomial using array. Use this representation to implement the addition of polynomials. 
// // Also use a header-linked list to manage polynomials stored in an array that can help in efficiently handling dynamic polynomial terms, 
// // allowing for easy addition and removal of terms without worrying about fixed array sizes.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create a header node for the polynomial linked list
struct Node* createHeaderNode() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    if (!header) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    header->coeff = 0;
    header->exp = -1;
    header->next = NULL;
    return header;
}

// Function to insert a term (coeff, exp) in the polynomial in descending order of exponents
void insert(struct Node* header, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    // Traverse to find the correct position to insert the new node
    struct Node* current = header;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to display a polynomial
void display(struct Node* header) {
    struct Node* current = header->next;  // Skip the header node
    while (current != NULL) {
        if (current->coeff != 0) {
            printf("%dx^%d ", current->coeff, current->exp);
            if (current->next != NULL && current->next->coeff != 0) {
                printf("+ ");
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomial(struct Node* p1, struct Node* p2) {
    struct Node* temp1 = p1->next;
    struct Node* temp2 = p2->next;
    struct Node* result = createHeaderNode();

    // Traverse both polynomials and add terms
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp > temp2->exp) {
            insert(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else if (temp2->exp > temp1->exp) {
            insert(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
        else {
            // If exponents are the same, add the coefficients
            int sumcoeff = temp1->coeff + temp2->coeff;
            if (sumcoeff != 0) {
                insert(result, sumcoeff, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // If any terms are left in p1 or p2, add them to the result
    while (temp1 != NULL) {
        insert(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insert(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    // Display the resulting polynomial
    printf("\nSum of polynomials: ");
    display(result);
}

int main() {
    // Create two polynomials p1 and p2
    struct Node* p1 = createHeaderNode();
    struct Node* p2 = createHeaderNode();

    // Insert terms in polynomial p1
    printf("\nFOR POLYNOMIAL-1:\n");
    insert(p1, 4, 3);
    insert(p1, 3, 2);
    insert(p1, 2, 1);
    insert(p1, 4, 0);

    // Insert terms in polynomial p2
    printf("\nFOR POLYNOMIAL-2:\n");
    insert(p2, 4, 3);
    insert(p2, 3, 2);
    insert(p2, 2, 1);
    insert(p2, 4, 0);

    // Add the two polynomials and display the result
    addPolynomial(p1, p2);

    return 0;
}