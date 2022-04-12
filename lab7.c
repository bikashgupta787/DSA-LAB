#include<stdio.h>
#include<stdlib.h>

struct item{
    int part_num;
    int qty;
};
int size = 20;
struct item arr[20];
int collision=0;

void init_array()
{
    int i;
    for(i=0;i<size;i++)
    {
        arr[i].part_num = NULL;
        arr[i].qty = NULL;
    }
}

int hashcode(int part_num)
{
    return(part_num%size);
}
void insert(int part_num,int qty)
{

    int index = hashcode(part_num);
    struct item *newItem;
    newItem = (struct item*)malloc(sizeof(struct item));
    newItem->part_num = part_num;
    newItem->qty = qty;

    if(arr[index].part_num == NULL && arr[index].qty == NULL)
    {
        arr[index].part_num = part_num;
        arr[index].qty = qty;
    }
    else
    {
        while(arr[index].part_num !=0 )
        {
            index++;
            collision++;
        }
        arr[index].part_num = part_num;
        arr[index].qty = qty;
    }
}

void display()
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("the part_num is %d the qty is %d\n",arr[i].part_num,arr[i].qty);
    }
}
void serachItem(int key)
{
    int index = hashcode(key);
    //printf("%d",index);
    if(arr[index].part_num == NULL ){
        printf("The item doesnot exits\n");
        return;
    }
    else if(arr[index].part_num == key){
        printf("The quantity sold for part number %d ------> %d\n",key,arr[index].qty);
    }else
    {
       while(arr[index].part_num != key)
       {
           index++;
       }
       printf("The quantity sold for  part number %d ------> %d\n",key,arr[index].qty);
    }

}


int main()
{
    int i,j=0,part_num,qty,search,option = 1;
    init_array();
    int inventory[15][2] = {{112,12},{130,30},{156,56},{173,17},{197,19},{150,50},{166,66},{113,13},{123,12},{143,14},{167,16},{189,18},{193,19},{117,11},{176,76}};
    for(i=0;i<15;i++)
    {

            part_num = inventory[i][j];
            qty = inventory[i][j+1];
            insert(part_num,qty);
            j=0;


    }
    display();
    printf("\nThe total number of collison is %d\n",collision);
    printf("\n");
    while(option == 1)
    {

    printf("\nEnter the part number to be searched:");
    scanf("%d",&search);
    serachItem(search);
    }
    return 0;
}
