#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 10
typedef struct{
    int code;
    char name[50];
    double price;
} Item;
char confirm_action(const char *message){
    char confirm;
    printf("%s (y/n): ", message);
    scanf(" %c", &confirm);
    return (confirm=='y' || confirm=='Y');
}
int main(){
    Item items[]={
        {101, "Apple", 1.5},
        {102, "Banana", 0.8},
        {103, "Carrot", 2.0},
        {104, "Milk", 1.2},
        {105, "Bread", 2.5}
    };
    int num_items = 5;
    int cart[MAX_ITEMS], quantities[MAX_ITEMS], cart_size = 0;
    double total = 0.0;
    char option;
    int i,j;
    do{
        printf("\nMenu:\n1. Add items to cart\n2. Show total\n3. Checkout\n4. Cancel session\nq. Quit\nChoose an option: ");
        scanf(" %c", &option);
        if(option=='1'){
            if(cart_size>=MAX_ITEMS){
                printf("Cart is full! You can't add more items.\n");
                continue;
            }
            int code,quantity,found=0;
            printf("\nAvailable items:\n");
            for(i=0;i<num_items;i++){
                printf("%d - %s - $%.2f\n", items[i].code, items[i].name, items[i].price);
            }
            printf("Enter item code: ");
            if(scanf("%d", &code)!=1){
                printf("Invalid input. Please enter a valid item code.\n");
                while (getchar()!='\n');
                continue;
            }
            for(i=0;i<num_items;i++){
                if(items[i].code == code){
                    printf("Enter quantity for %s: ", items[i].name);
                    if(scanf("%d", &quantity) != 1 || quantity <= 0){
                        printf("Invalid quantity. Please enter a positive number.\n");
                        continue;
                    }
                    cart[cart_size]=code;
                    quantities[cart_size]=quantity;
                    cart_size++;
                    total +=items[i].price*quantity;
                    printf("%s (%d x $%.2f) added to cart.\n", items[i].name, quantity, items[i].price);
                    found = 1;
                    break;
                }
            }
            if(!found){
                printf("Item code not found. Try again.\n");
            }
        }
        else if(option=='2'){
            printf("\nCurrent total: $%.2f\n", total);
        }
        else if(option=='3'){
            printf("\nItemized bill:\n");
            for(i=0;i<cart_size;i++){
                for(j=0;j< num_items;j++){
                    if(items[j].code==cart[i]){
                        printf("%s - %d x $%.2f = $%.2f\n", items[j].name, quantities[i], items[j].price, quantities[i] * items[j].price);
                        break;
                    }
                }
            }
            printf("Total: $%.2f\n", total);
            total = 0.0;
            cart_size = 0;
            printf("New session started.\n");
        }
        else if (option=='4'){
            if(confirm_action("Are you sure you want to cancel the session?")){
                total=0.0;
                cart_size=0;
                printf("Session canceled. New session started.\n");
            }
        }
        else if (option=='q'){
            if(confirm_action("Are you sure you want to quit?")){
            printf("Exiting program...\n");
            break;
            }
        }
        else{
            printf("Invalid option. Please try again.\n");
        }
    }while(option!='q');
    return 0;
}
