/*
Assignment no- 2
Title of program-Implement  database  management  using  array  of  structures  with  operations  Create,
display, Modify, Append, Search and Sort.
*/
#include <stdio.h>
#include <string.h>

struct employee_database
{
  int emp_no;
  char name[20];
};

void get_employee_info(struct employee_database info[], int number);
void edit_employee_info(struct employee_database info[], int number);
void display_employee_info(struct employee_database info[]);
void delete_employee_info(struct employee_database info[], int number,int size);

int total_employee;

int main()
{
        int n;
        printf("\nEnter size of employee list=");
        scanf("%d",&n);
        struct employee_database employee_info[n];
        int option, rno;
        get_employee_info(employee_info,n);
        do
        {
                 printf("\n ******************** MENU ********************\n");
                 printf("1. Edit employee name (Employee no is given)\n");
                 printf("2. Display employee databases \n");
                 printf("3. Delete employee name from list (employee no. is know.)\n");
                 printf("4. Exit from program \n");
                 printf("Enter Choice = ");
                 scanf("%d", &option);
                 switch (option)
                 {
                  case 1:
                  printf("\nEnter Employee no. of Employee to edit =");
                  scanf("%d",&rno);
                  edit_employee_info(employee_info, rno);
                  break;
                  case 2:
                  display_employee_info(employee_info);
                  break;
                  case 3:
                  printf("\Enter Employee no. of Employee to delete=");
                  scanf("%d",&rno);
                  delete_employee_info(&employee_info[0], rno, n);
                  break;
                  default:
                    printf("Invalid");
                  }
       }while(option!=4);
return 0;
}

void get_employee_info(struct employee_database info[], int number)
{
        int i;
        for (i=0; i < number; i++)
        {
                printf("For %d the Employee \n",i + 1);
                printf("Enter Employee Number= \n");
              scanf("%d", &info[i].emp_no);
              printf("Enter Name = \n");
                scanf("%s",info[i].name);
              total_employee++;
        }
}

void edit_employee_info(struct employee_database info[], int number)
{
         int i;
         for (i=0; i< number; i++)
         {
               if (info[i].emp_no == number)
               {
                     printf("Enter new name of Employee no. %d = ", number);
                     scanf ("%s", info[i].name);
                         break;
                }
         }
}


void display_employee_info(struct employee_database info[])
{
     int i;
     printf("\nEmployee no \t Name \n");
     for (i=0; i < total_employee; i++)
     {
         printf("%d \t\t %s \n",info[i].emp_no, info[i].name);
     }
     printf("\n");
}

void delete_employee_info(struct employee_database info[], int number, int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
               if (info[i].emp_no == number)
             break;
        }

        do
        {
               info[i].emp_no=info[i+1].emp_no;
               strcpy(info[i].name, info[i+1].name);
               i = i +1;
        } while (i < (size-1));
        info[i].emp_no = 0;
        strcpy(info[i].name, "");
        total_employee--;
}
