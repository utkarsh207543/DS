#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

#define endl printf("\n")

int a[100];
int f = -1;
int r = -1;

void ins(int a[], int n, int b);
void del(int a[],int n);
void disp(int a[], int n);

int main()
{
   int n,s,b;
   clrscr();
   printf("Enter The Size Of Queue:"); endl;
   scanf("%d",&n);


	while(1)
	{
		printf("Select option: \n 1.Insert item \n 2.Delete Item \n 3.Display 4.Exit"); endl;
		scanf("%d",&s);

	  switch(s){

	  case 1: {    printf("Enter Item : "); endl;
			scanf("%d",&b);
			ins(a,n,b);
			}
			break;

	  case 2: del(a,n);
			break;

	  case 3: disp(a,n);
			break;

	   case 4: exit(1);
			break;

	  default: printf("No Option Selected!");
			break;

		  }
	}



   free(a);
   system("pause");
   return 0;
}


void ins(int a[],int n, int b)
{
 if((f == 0 && r == n - 1) || (f == r+1))
     {
      printf("OverFlow"); endl;
     }
   else
   {
      if(r == n-1 && f != 0)
	 r = -1;
      a[++r] = b;
      printf("\n Insertion compelte!");
      if(f == -1)
	 f = 0;
   }

}

void del(int a[], int n)
{
if(f == -1 && r == -1)
      printf("\nCircular Queue is Empty! ");
   else{
      printf("\nDeleted element : %d\n",a[f++]);
      if(f == n)
	 f = 0;
      if(f-1 == r)
	 f = r = -1;
   }


}

void disp(int a[], int n)
{
if(f == -1)
      printf("\nCircular Queue is Empty!!!\n");
   else{
      int i = f;
      printf("\nCircular Queue Elements are : \n");
      if(f <= r){
	 while(i <= r)
	    printf("%d\t",a[i++]);
      }
      else{
	 while(i <= n - 1)
	    printf("%d\t", a[i++]);
	 i = 0;
	 while(i <= r)
	    printf("%d\t",a[i++]);
      }
   }


}
