#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define AMOUNT 9

double money=0;
int choice1=-1;
int choice2=-1;
double totalSales=0;



typedef struct Product{
  char *name;
  double price;
} Product;

typedef struct Item{
  Product product;
  int quantity;
  char *id;
} Item;

Product createProduct(char *n,double p){
  Product prod;
  prod.name=n;
  prod.price=p;
  return prod;
}
Item createItem(Product p,int q,char *i){
  Item it;
  it.product=p;
  it.quantity=q;
  it.id=i;
  return it;
}

void printMenu(Item *items);
void custOptions(Item* items);
void ownerMenu(Item *items);

void insertMoney(Item *items,double add){
  money+=add;
  choice1=-1;
  printMenu(items);
}

void purchaseItem(Item *items,Item it,int amount){
  if(money>=it.product.price*amount&&it.quantity>=amount){
    money-=it.product.price*amount;
    totalSales+=it.product.price*amount;
    items->quantity-=amount;
  }
  else if(it.quantity<amount){
    printf("There are not enough %ss. Enter a smaller amount.\n",items->product.name);
  }
  else if(money<it.product.price*amount){
    printf("%s\n","Insufficient funds.");
  }
  choice1=-1;
  printMenu(items);
}

void returnChange(Item *items){
  if(money==0){
    printf("%s\n","There is no money to return.");
  }
  else{
    printf("Returned: $%.2lf\n",money);
    money=0;
  }
  choice1=-1;
  printMenu(items);
}

void checkBalance(Item *items){
  printf("You have $%.2lf\n",money);
  choice1=-1;
  printMenu(items);
}

void checkPrice(Item *items){
  char *tempID=(char*)malloc(3*sizeof(char));
  printf("%s", "Enter the product ID: ");
  scanf("%s",tempID);
  for(int i=0;i<AMOUNT;i++){
    if(items[i].id!=NULL&&strcmp(items[i].id,tempID)==0){
      printf("%s price: $%.2lf\n",items[i].product.name,items[i].product.price);
      choice1=-1;
      printMenu(items);
    }
  }
  printf("%s\n","ID doesn't match any products.");
  choice1=-1;
  printMenu(items);

}
void addItems(Item *items){
  char *n=(char*)malloc(100*sizeof(char));
  double c;
  int a;
  char *id=(char*)malloc(3*sizeof(char));
  printf("%s","Enter the name of the new product: ");
  scanf("%s",n);
  int count=0;

  while(n[count]!='\0'){
    count++;
  }
  char *newN=(char*)malloc((count)*sizeof(char));
  for(int i=0;i<count;i++){
    newN[i]=n[i];
  }

  printf("Enter the cost of an %s: $", newN);
  scanf("%lf",&c);
  printf("How many %ss would you like to stock: ", newN);
  scanf("%d",&a);
  printf("Enter an ID (2 char max) for %ss: ", newN);
  scanf("%s",id);
  Product p=createProduct(newN,c);
  Item newItem=createItem(p,a,id);
  for(int i=0;i<AMOUNT;i++){
    if(items[i].id==NULL){
      items[i]=newItem;
      choice1=-1;
      choice2=-1;
      printMenu(items);
    }
  }

  printf("%s\n", "There are no available spots. Remove an item and try again.");

  choice1=-1;
  choice2=-1;
  printMenu(items);
}

void restock(Item *items){
  char *tempID=(char*)malloc(3*sizeof(char));
  int amt;
  printf("%s", "Enter the product ID: ");
  scanf("%s",tempID);
  printf("%s","Enter an amount to add: ");
  scanf("%d",&amt);
  for(int i=0;i<AMOUNT;i++){
    if(items[i].id!=NULL&&strcmp(items[i].id,tempID)==0){
      items[i].quantity+=amt;
      choice1=-1;
      choice2=-1;
      printMenu(items);
    }
  }
  printf("%s\n","ID doesn't exist.");
}

void checkQuantity(Item *items){
  char *tempID=(char*)malloc(3*sizeof(char));
  printf("%s", "Enter the product ID: ");
  scanf("%s",tempID);
  for(int i=0;i<AMOUNT;i++){
    if(items[i].id!=NULL&&strcmp(items[i].id,tempID)==0){
      printf("%s quantity: %d\n",items[i].product.name,items[i].quantity);
      choice1=-1;
      choice2=-1;
      printMenu(items);
    }
  }
  printf("%s\n","ID doesn't exist.");
}

void removeItems(Item *items){
  int count=0;
  char *tempID=(char*)malloc(3*sizeof(char));
  printf("%s", "Enter the product ID: ");
  scanf("%s",tempID);
  Item *newItems=(Item*)malloc(AMOUNT*sizeof(Item));
  for(int i=0;i<AMOUNT;i++){
    if(items[i].id!=NULL&&strcmp(items[i].id,tempID)!=0){
      newItems[i]=items[i];
    }
    else {
      count++;
    }
  }
  if(count==0){
    printf("%s\n","ID doesn't match any products.");
  }
  count=0;
  choice1=-1;
  choice2=-1;
  printMenu(newItems);

}

void ownerMenu(Item *items){
  choice2=-1;
  printf("%s","Owner Menu: \n[1] Add a new type of item\n[2] Restock\n[3] Check quantity\n[4] Take down a type of item\n[5] Check total sales\n[6] Exit owner menu\nEnter an option: ");
  scanf("%d",&choice2);
  if(choice2==1){
    addItems(items);
  }
  else if(choice2==2){
    restock(items);
  }
  else if(choice2==3){
    checkQuantity(items);
  }
  else if(choice2==4){
    removeItems(items);
  }
  else if(choice2==5){
    printf("Total sales: $%.2lf\n",totalSales);
    choice1=-1;
    choice2=-1;
    printMenu(items);
  }
  else if(choice2==6){
    choice1=-1;
    choice2=-1;
    printMenu(items);
  }
}

void printMenu(Item *items){
  choice1=-1;
  choice2=-1;
  printf("%s","----------------------------------------\n|");
  if(items[0].product.name!=NULL){
    printf("%-12s%s",items[0].product.name,"|");
  }
  else{
    printf("%-12s%s","","|");
  }
  if(items[1].product.name!=NULL){
    printf("%-12s%s",items[1].product.name,"|");
  }
  else{
    printf("%-12s%s","","|");
  }
  if(items[2].product.name!=NULL){
    printf("%-12s%s",items[2].product.name,"|\n|");
  }
  else{
    printf("%-12s%s","","|\n|");
  }
  if(items[0].id!=NULL){
    printf("%-12s%s",items[0].id,"|");
  }
  else{
    printf("%-12s%s","A1","|");
  }
  if(items[1].id!=NULL){
    printf("%-12s%s",items[1].id,"|");
  }
  else{
    printf("%-12s%s","A2","|");
  }
  if(items[2].id!=NULL){
    printf("%-12s%s",items[2].id,"|\n");
  }
  else{
    printf("%-12s%s","A3","|\n");
  }
  printf("%s","----------------------------------------\n|");
  if(items[3].product.name!=NULL){
    printf("%-12s%s",items[3].product.name,"|");
  }
  else{
    printf("%-12s%s","","|");
  }
  if(items[4].product.name!=NULL){
    printf("%-12s%s",items[4].product.name,"|");
  }
  else{
    printf("%-12s%s","","|");
  }
  if(items[5].product.name!=NULL){
    printf("%-12s%s",items[5].product.name,"|\n");
  }
  else{
    printf("%-12s%s","","|\n|");
  }
  if(items[3].id!=NULL){
    printf("%-12s%s",items[3].id,"|");
  }
  else{
    printf("%-12s%s","B1","|");
  }
  if(items[4].id!=NULL){
    printf("%-12s%s",items[4].id,"|");
  }
  else{
    printf("%-12s%s","B2","|");
  }
  if(items[5].id!=NULL){
    printf("%-12s%s",items[5].id,"|\n");
  }
  else{
    printf("%-12s%s","B3","|\n");
  }
  printf("%s","----------------------------------------\n|");
  if(items[6].product.name!=NULL){
    printf("%-12s%s",items[6].product.name,"|");
  }
  else{
    printf("%-12s%s","","|");
  }
  if(items[7].product.name!=NULL){
    printf("%-12s%s",items[7].product.name,"|");
  }
  else{
    printf("%-12s%s","","|");
  }
  if(items[8].product.name!=NULL){
    printf("%-12s%s",items[8].product.name,"|\n");
  }
  else{
    printf("%-12s%s","","|\n|");
  }
  if(items[6].id!=NULL){
    printf("%-12s%s",items[6].id,"|");
  }
  else{
    printf("%-12s%s","C1","|");
  }
  if(items[7].id!=NULL){
    printf("%-12s%s",items[7].id,"|");
  }
  else{
    printf("%-12s%s","C2","|");
  }
  if(items[8].id!=NULL){
    printf("%-12s%s",items[8].id,"|\n");
  }
  else{
    printf("%-12s%s","C3","|\n");
  }
  printf("%s","----------------------------------------\n");
  custOptions(items);

}



void custOptions(Item *items){
  while(choice1==-1){
    printf("%s","[1] Insert money\n[2] Check balance\n[3] Check price\n[4] Purchase\n[5] Return change\n[6] Owner menu\n[7] Exit\nEnter an option: ");
    scanf("%d",&choice1);
  }
  if(choice1==1){
    double tempMoney=0;
    printf("%s","Enter an amount of money to add: ");
    scanf("%lf",&tempMoney);
    insertMoney(items,tempMoney);
    tempMoney=0;
    choice1=-1;
    printMenu(items);
  }
  else if(choice1==2){
    checkBalance(items);
  }
  else if(choice1==3){
    checkPrice(items);
  }
  else if(choice1==4){
    printf("%s","Enter an ID: ");
    char *tempID1=(char*)malloc(3*sizeof(char));;
    scanf("%s",tempID1);
    printf("%s","Enter an amount: ");
    int amt;
    scanf("%d",&amt);
    for(int i=0;i<AMOUNT;i++){
      if(items[i].id!=NULL&&strcmp(tempID1,items[i].id)==0){
        purchaseItem(items,items[i],amt);
      }
    }
    printf("%s\n","Item not found.");
    printMenu(items);

  }
  else if(choice1==5){
    returnChange(items);
  }
  else if(choice1==6){
    ownerMenu(items);
  }
  else if(choice1==7){
    exit(0);
  }

}

int main(void){
  Item *it=(Item*)malloc(AMOUNT*sizeof(Item));
  printMenu(it);


  return 0;

}
