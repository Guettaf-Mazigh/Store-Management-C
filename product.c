#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *NewProduct(){
    Node *b = malloc(sizeof(Node));
    printf("Enter the name of the product: ");
    fgets(b->data.Nmproduct, sizeof(b->data.Nmproduct), stdin);
    b->data.Nmproduct[strcspn(b->data.Nmproduct, "\n")] = '\0';

    printf("Enter the id of the product: ");
    fgets(b->data.idProduct, sizeof(b->data.idProduct), stdin);
    b->data.idProduct[strcspn(b->data.idProduct, "\n")] = '\0';

    printf("Enter the description of the product: ");
    fgets(b->data.description, sizeof(b->data.description), stdin);
    b->data.description[strcspn(b->data.description, "\n")] = '\0';

    printf("Enter the price of the product:");
    scanf("%f",&b->data.price);
    printf("Enter the quantity of the product:");
    scanf("%s",b->data.quantity);
    b->Next = NULL;
    return b;
}

Node *AddProduct(Node *head){
    Node *b = NewProduct();
    if(head == NULL)
        head = b;
    else{
        Node *temp = head;
        while(temp->Next != NULL)
            temp = temp->Next;
        temp->Next = b;
    }
    return head;
}

void SearchProductByID(Node *head, char id_res[]){
    if(head == NULL)
        exit(EXIT_FAILURE);
    Node *temp = head;
    int result = 999;
    do{
        result = strcmp(temp->data.idProduct , id_res);    //with do while LOOP
    }while(temp->Next != NULL && result != 0);
    if(result == 0)
        printf("The product whit ID %s is found !\n",id_res);
    else
        printf("The product whit ID %s is not found !\n",id_res);
} 

Node *DeletProdectByName(Node *head , char nameProdDelet[]){
    if(head == NULL)
        return NULL;

    Node *temp = head;
    if(strcmp (head->data.Nmproduct , nameProdDelet) == 0){ //if the product to delet is the first element
        if(head->Next != NULL){ 
            head = temp->Next;
            free(temp);
            return head;
        }
        else{    //if there is only one node
            free(head);
            return NULL;
        }
    }

    while(temp->Next != NULL && strcmp(temp->Next->data.Nmproduct,nameProdDelet) != 0)  // If the product to be deleted is found after the current node (temp)
        temp = temp->Next;

    if(temp->Next != NULL){ 
        Node *productToDelet = temp->Next;
        temp->Next = productToDelet->Next;
        free (productToDelet);
    }
    return head;
}

Node *sortProductsByPrice(Node *head){
    if(head == NULL)
        return NULL;

    Node *p , *q;
    p = head;
    while(p->Next != NULL){
        Node *min = p;
        q = p->Next;
        while(q != NULL){
            if(q->data.price < min->data.price)
                min = q;
            q = q->Next;
        }
        product tmp = p->data;
        p->data = min->data;    //permutation
        min->data = tmp;

        p = p->Next;
    }
    return head;
}

void displayProducts(Node *head){
    head = sortProductsByPrice(head); // Using the sortProductsByPrice function to sort products by price
    if(head == NULL){
        printf("There are no products !");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    Node *temp = head;
    while(temp != NULL){
        i++;
        printf("Product %d : \n",i);
        printf("product : %s \n",temp->data.Nmproduct);
        printf("ID: %s \n",temp->data.idProduct);
        printf("Descreption : %s \n",temp->data.description);
        printf("price: %f \n",temp->data.price);
        printf("Quantity : %d \n",temp->data.quantity);
        printf("-----------------------------------------------------  \n");
        temp = temp->Next;
    }
}