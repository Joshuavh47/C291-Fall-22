#include <stdio.h>
#include <stdlib.h>

typedef struct Address{
  char *streetName;
  char *cityName;
  char *stateName;
  char *zipCode;
} Address;

typedef struct Product{
  char *prodName;
  double prodPrice;
} Product;

typedef struct Item{
  Product product;
  int amount;
} Item;

typedef struct Invoice{
  Item *invItems;
  Address addr;
} Invoice;

int itemAmt=0;

Address createAddress(char * street, char * city, char * state, char * zip){
  Address a;
  a.streetName=street;
  a.cityName=city;
  a.stateName=state;
  a.zipCode=zip;
  return a;
}

Product createProducts(char * name, double price) {
  Product p;
  p.prodName=name;
  p.prodPrice=price;
  return p;
}

Item createLineItem(Product prod, int quantity) {
  Item i;
  i.product=prod;
  i.amount=quantity;
  itemAmt++;
  return i;
}

Invoice createInvoice(Item * items, Address address) {
  Invoice i;
  i.invItems=items;
  i.addr=address;
  return i;
}

void printLineItem(Item it){
  printf("%-30s $%-10.2lf%-10d $%-10.2lf\n",it.product.prodName,it.product.prodPrice,it.amount,it.amount*it.product.prodPrice);
}

void printInvoice(Invoice invoice){
  printf("%s\n", invoice.addr.streetName);
  printf("%s, %s %s\n\n", invoice.addr.cityName,invoice.addr.stateName, invoice.addr.zipCode);
  printf("%-30s %-10s %-10s %-10s\n","Description","Price","Qty","Total");
  double total=0;
  for(int i=0;i<itemAmt;i++){
    printLineItem(invoice.invItems[i]);
    total+=invoice.invItems[i].product.prodPrice*invoice.invItems[i].amount;
  }
  puts("\n");
  printf("%s$%.2lf\n","AMOUNT DUE: ",total);
}

int main(void){
  Address a=createAddress("123 Test Ln.","Test","IL","60061");
  Product p1=createProducts("Computer",999.99);
  Product p2=createProducts("Phone",599.99);
  Product p3=createProducts("Tablet",799.99);
  Item it1=createLineItem(p1,5);
  Item it2=createLineItem(p2,10);
  Item it3=createLineItem(p3,7);
  Item *itemArr=(Item*)malloc(3*sizeof(Item));
  itemArr[0]=it1;
  itemArr[1]=it2;
  itemArr[2]=it3;
  Invoice inv=createInvoice(itemArr,a);
  printInvoice(inv);
  return 0;
}
