
typedef struct product{
    char Nmproduct[30];
    char description[60];
    char idProduct[8];
    float price;
    int quantity;
}product; 

typedef struct Node{
    product data;
    struct Node *Next;
}Node;




