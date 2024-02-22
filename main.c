#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char answer[4];
    char id_res[8];
    char nameProdDelet[30];
    int x;
    Node *L = NULL;
    while(1){
        printf("Menu :\n 1-Add a product \n 2-Search for a product by ID \n 3-Delet a product by name \n 4-Display products sorted by price \n");
        scanf("%d",&x);
        getchar();
        
        switch(x){
            case 1 :
                L = AddProduct(L);
                break;
            case 2 : 
                printf("Enter the ID :");
                fgets(id_res,sizeof(id_res),stdin);
                id_res[strcspn(id_res, "\n")] = '\0';
                SearchProductByID(L,id_res);
                break;
            case 3 :
                printf("Enter the Name of the prodect :");
                fgets(nameProdDelet,sizeof(nameProdDelet),stdin);
                nameProdDelet[strcspn(nameProdDelet, "\n")] = '\0';
                L = DeletProdectByName(L,nameProdDelet);
                break;
            case 4 :
                displayProducts(L);
                break;
            default :
                printf("This value doesn't exist in the Menu!\n");
                break;
        }
    }
    return 0;
}
