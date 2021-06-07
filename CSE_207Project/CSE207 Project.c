//Imlementation of Hash Table Using Linear Probing
#define size 10
#include<stdio.h>
struct item{
    int data;
    int key;
};
struct item* hashTable[size];
struct item* temp;
struct item* search(int key);
struct item* delete(struct item* del);
int main()
{
    while(1){
    puts("1.Insert\n2.Print\n3.Search\n4.Delete\n5.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("Enter key and data: ");
        int k,d;
        scanf("%d%d",&k,&d);
        insert(k,d);
    }
    if(n==2){
        print();
    }
    if(n==3){
        printf("Enter key to search: ");
        int x;
        scanf("%d",&x);
        temp=search(x);
        if(temp!=NULL){
            printf("Data founded & the data is: %d\n",temp->data);
        }
        else printf("Not found\n");
    }
    if(n==4){
        printf("Enter key to Delete: ");
        int x;
        scanf("%d",&x);
        temp=search(x);
        delete(temp);
    }
}
}
int hashing(int key){
    return key%size;
}
void insert(int key,int value)
{
    struct item *new=(struct item*)malloc(sizeof(struct item));
    new->data=value;
    new->key=key;
    int hashIndex=hashing(key);
    while(hashTable[hashIndex]!=NULL&&hashTable[hashIndex]->key!=-1){
            hashIndex++;
            hashIndex%=size;
    }
    hashTable[hashIndex]=new;
}
struct item* search(int key){
    int hIndex=hashing(key);
    while(hashTable[hIndex]!=NULL){
        if(hashTable[hIndex]->key==key){
            return hashTable[hIndex];
        }
        hIndex++;
        hIndex%=size;
    }
    return NULL;
}
struct item* delete(struct item* del){
    int key=del->key;
    int hIndex=hashing(key);
    while(hashTable[hIndex]!=NULL){
        if(hashTable[hIndex]->key==key){
            struct item* t=hashTable[hIndex];
            hashTable[hIndex]->data=-1;
            hashTable[hIndex]->key=-1;
            return t;
        }
        hIndex++;
        hIndex%=size;
    }
}
void print() {
   for(int i = 0; i<size; ++i) {

      if(hashTable[i] != NULL&& hashTable[i]->key!=-1)
         printf("The Key Is: %d & Value Is: %d\n",hashTable[i]->key,hashTable[i]->data);
   }

   printf("\n");
}
