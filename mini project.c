#include<stdio.h>
#include<string.h>
#include <windows.h>

int main_exit;
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
 DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}

void menu(void)
{
    static int totalCost;
    int i,j,choice,c=1,a[9],cost[9];
    for(i=0;i<9;i++)
    a[i]=0;
    int quantity;

    char str[100];
    char items[9][100]={"Pendrive 16 GB",
    "Logitech Mouse",
    "Keyboard 16 GB",
    "Adidas     ",
    "Nike       ",
    "Puma       ",
    "RedmiNote8Pro",
    "Iphone XS Max",
    "Xiaomi POCO F3"
    };

    system("cls");
     ClearConsoleToColors(15,3);
    //system("color 9");
    printf("\n\n\t\t\t\t  ONLINE SHOPPING SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");

 do{
  //C is 1 by default
  if(c==1){
  printf("\n\n\t\t\t\tEnter\n\t\t\t\t1 - Computer Accessories\n\t\t\t\t2 - Shoes\n\t\t\t\t3 - Mobiles\n\t\t\t\tAny other number to exit\n\n");
  printf("\t\t\tChoice: ");
  scanf("%d",&choice);
  printf("\n");
  switch(choice)
  {
   case 1:
   {
    int accessoriesChoice;
    printf("\t\t\t\tEnter\n\t\t\t\t0 - Pendrive 16 GB - RM 20\n\t\t\t\t1 - Logitech Mouse- RM 35\n\t\t\t\t2 - Keyboard - RM 60\n\t\t\t\tAny other number to exit\n");
    printf("\t\t\tChoice:");
    scanf("%d",&accessoriesChoice);
    printf("\n");
    cost[0]=20;
    cost[1]=35;
    cost[2]=60;
    switch(accessoriesChoice)
    {
     case 0:
     {
      int num;
      printf("\t\tYou chose Pendrive 16GB with RM 20. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
       printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[0]+=quantity;
       totalCost+=20*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     case 1:
     {
      int num;
      printf("\t\tYou chose Logitech Mouse with RM 35. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
          printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[1]+=quantity;
       totalCost+=35*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     case 2:
     {
      int num;
      printf("\n\t\tYou chose Keyboard with RM 60. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
       printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[2]+=quantity;
       totalCost+=60*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     default:{
      printf("\n\t\t\t\tExit from Computer Accesories\n");
      break;
     }
    }
    break;
   }

   case 2:
   {
    int shoesChoice;
    printf("\n\n\t\t\t\tEnter\n\t\t\t\t3 - Adidas - RM 199\n\t\t\t\t4 - Nike - RM 399\n\t\t\t\t5 - Puma - RM 250\n\t\t\t\tAny other number to exit\n");
    printf("\t\t\tChoice: ");
    scanf("%d",&shoesChoice);
    cost[3]=199;
    cost[4]=399;
    cost[5]=250;
    switch(shoesChoice)
    {
     case 3:
     {
      int num;
      printf("\n\t\tYou chose Adidas Shoes for RM 199. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
        printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[3]+=quantity;
       totalCost+=199*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     case 4:
     {
      int num;
      printf("\n\t\tYou chose Nike Shoes for RM 399. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
        printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[4]+=quantity;
       totalCost+=399*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     case 5:
     {
      int num;
      printf("\n\t\tYou chose Puma Shoes for RM 250. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
          printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[5]+=quantity;
       totalCost+=250*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     default:{
      printf("\n\t\t\t\tExit from Shoes Category\n");
      break;
     }
    }
    break;
   }
   case 3:
   {
    int mobileChoice;
    printf("\n\n\t\t\t\tEnter\n\t\t\t\t6 - Redmi Note 8 Pro - RM 1100\n\t\t\t\t7 - Iphone XS Max - RM 2999\n\t\t\t\t8 - Xiaomi POCO F3 - RM 1800\n\t\t\t\tAny other number to exit\n");
    printf("\t\t\tChoice: ");
    scanf("%d",&mobileChoice);
    cost[6]=1100;
    cost[7]=2999;
    cost[8]=1800;
    switch(mobileChoice)
    {
     case 6:
     {
      int num;
      printf("\n\t\tYou chose to buy Redmi Note 8 Pro for RM 1100. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
          printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[6]+=quantity;
       totalCost+=1100*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     case 7:
     {
      int num;
      printf("\n\t\tYou chose to buy Iphone XS Max for RM 2999. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
          printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[7]+=quantity;
       totalCost+=2999*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     case 8:
     {
      int num;
      printf("\n\t\tYou chose to buy Xiaomi POCO F3 for RM 1800. Are you sure to buy? If 'Yes', please enter 1, else any number\n");
      printf("\t\t\tChoice: ");
      scanf("%d",&num);
      if(num==1)
      {
          printf("\t\t\tquantity: ");
       scanf("%d",&quantity);
       a[8]+=quantity;
       totalCost+=1800*quantity;
      }
      printf("\n\t\t\t\tYour Cost in Cart is %d\n",totalCost);
      break;
     }
     default:{
      printf("\n\t\t\t\tExit from Mobile Category\n");
      break;
     }
    }
    break;
   }
   default:
   {
    printf("\n\t\t\t\tEnter Valid Categories Choice\n");
    break;
   }
  }
  printf("\n\t\tYour cart\n");
  printf("\t\tId\tItems\t\t\tQuantity\t\t\tPrice\n");
  for(i=0;i<9;i++)
  {
   if(a[i]!=0)
   {
    printf("\t\t%d\t%s\t\t%d\t\t\t\t%d\n",i,items[i],a[i],(cost[i]*a[i]));
   }
  }
  printf("\n\t\t\tTotal Cost\t\t\t\t\t\t%d\n",totalCost);
  printf("\n\t\t\tIf you wish to buy anything more Enter\n\t\t\t1 to Add Item\n\t\t\t2 to Delete Items \n\t\t\tAny other number to Exit\n");
  printf("\t\t\tChoice: ");
  scanf("%d",&c);
 }
  if(c==2)
  {
   int id;
   printf("\n\t\t\tEnter id to delete item\n");
   printf("\t\t\tChoice: ");
   scanf("%d",&id);
   printf("\n");
   if(id<9&&id>0){
   totalCost=totalCost-(cost[id]*a[id]);
   a[id]=0;
   }
   else{
    printf("\t\t\t\tEnter Valid id\n");
   }
       printf("\t\tRevised Items \n");
       printf("\t\tId\tItems\t\t\tQuantity\t\tPrice\n");
            for(i=0;i<9;i++)
      {
     if(a[i]!=0)
      {
    printf("\t\t%d\t%s\t\t%d\t\t\t%d\n",i,items[i],a[i],(cost[i]*a[i]));
      }
     }
        printf("\n\t\t\tTotal Cost\t\t\t\t\t%d\n",totalCost);
        printf("\n\t\t\tIf you wish to buy anything more Enter\n\t\t\t\t1 to Add Item\n\t\t\t\t2 to Delete Items \n\t\t\t\tAny other number to Exit\n");
        printf("\t\t\tChoice: ");
     scanf("%d",&c);
  }

 }while(c==1 || c==2);
 printf("\n\t\t\t\tYour Final Cost is %d\n",totalCost);
 printf("\t\t\t\tThanks you for Choosing Us and Visit us again.\n");
    }



    void signup(char **username, char **password)
    {
         system("cls");
        int choice,select,i=0;
         printf("                      ===========================================================================\n");
            printf("                      |                                                                         |\n");
            printf("                      |   -------------------------------------------------------------------   |\n");
            printf("                      |   ||***************************************************************||   |\n");
            printf("                      |   ||*               WELCOME TO ONLINE SHOPPING CENTER             *||   |\n");
            printf("                      |   ||***************************************************************||   |\n");
            printf("                      |   -------------------------------------------------------------------   |\n");
            printf("                      |                         ---------------------                           |\n");
            printf("                      |                         |       LOGIN       |                           |\n");
            printf("                      |                         |       PAGE        |                           |\n");
            printf("                      |                         ---------------------                           |\n");
            printf("                      |                                                                         |\n");
            printf("                      ===========================================================================\n");
        printf("\n\t\t\t\t\t1.Login\n\t\t\t\t\t2.Sign up\n\t\t\t\t\t");
        scanf("%d",&choice);

        if(choice==1){
        login(username, password);
        }
        else if(choice== 2){
        printf("\n\t\t\t\t\tSIGN UP PAGE\n");

        for(i=0;i<1;i++)
        {
        printf("\t\t\t\t\tEnter your username: ");
        scanf("%s", &username[i]);
        printf("\n\t\t\t\t\tEnter your password: ");
        scanf("%s", &password[i]);
        }
        signup(username, password);
        }
        else{
        printf("WRONG INPUT!!!");
        }

        }

        void login(char **user_name, char **password)
        {
            //printf("%s\n", username);
            //printf("%s\n", password);
            system("cls");
            char un[20];
            char pw[20];
            printf("                      ===========================================================================\n");
            printf("                      |                                                                         |\n");
            printf("                      |   -------------------------------------------------------------------   |\n");
            printf("                      |   ||***************************************************************||   |\n");
            printf("                      |   ||*               WELCOME TO ONLINE SHOPPING CENTER             *||   |\n");
            printf("                      |   ||***************************************************************||   |\n");
            printf("                      |   -------------------------------------------------------------------   |\n");
            printf("                      |                         ---------------------                           |\n");
            printf("                      |                         |       LOGIN       |                           |\n");
            printf("                      |                         |       PAGE        |                           |\n");
            printf("                      |                         ---------------------                           |\n");
            printf("                      |                                                                         |\n");
            printf("                      ===========================================================================\n");
            printf("\n\t\t\t\t\tEnter your username: ");
            scanf("%s", &un);
            if((strcmp(un,user_name)==0)){
            printf("\n\t\t\t\t\tEnter pass: ");
            scanf("%s", &pw);
            if(strcmp(pw,password)==0) {
            printf("SUCCESSS");
            }
            else{
            printf("Password wrong\n");
            login(user_name, password);
            }
            }
        else{
            printf("Username wrong\n");
            login(user_name, password);
            }}



        int main(){
            char name[50],user_name[50]="J";
            char pass[10],password[10]="1234";
            int i=0;
            int choice,select;
            ClearConsoleToColors(1,14);
            // system("COLOR F2");
            printf("                      ===========================================================================\n");
            printf("                      |                                                                         |\n");
            printf("                      |   -------------------------------------------------------------------   |\n");
            printf("                      |   ||***************************************************************||   |\n");
            printf("                      |   ||*               WELCOME TO ONLINE SHOPPING CENTER             *||   |\n");
            printf("                      |   ||***************************************************************||   |\n");
            printf("                      |   -------------------------------------------------------------------   |\n");
            printf("                      |                         ---------------------                           |\n");
            printf("                      |                         |       LOGIN       |                           |\n");
            printf("                      |                         |       PAGE        |                           |\n");
            printf("                      |                         ---------------------                           |\n");
            printf("                      |                                                                         |\n");
            printf("                      ===========================================================================\n");


            printf("\n\n\t\t\t\t\t1.Login\n\t\t\t\t\t2.Sign up");
            printf("\n\n\t\t\t\t\tChoice:");
            scanf("%d",&choice);

            if(choice==1){
            printf("\n\n\t\t\t\t\tEnter Name:");
            scanf("%s",name);
            printf("\n\t\t\t\t\tEnter the password:");
            scanf("%s",pass);
            if (strcmp(pass,password)==0 && strcmp(name,user_name)==0)
            {printf("\n\nPassword Match!\nLOADING");
            for(i=0;i<=6;i++)
            {
            fordelay(100000000);
            printf(".");
            }
                system("cls");
                menu();
            }
        else
        {   printf("\n\nWrong username or password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
    }
    else if(choice== 2){
    system("cls");
    printf("\n\n\t\t\t\t\tSIGN UP PAGE\n");

    for(i=0;i<1;i++)
    {
    printf("\t\t\t\t\tEnter your username: ");
    scanf("%s", &user_name[i]);
    printf("\n\t\t\t\t\tEnter your password: ");
    scanf("%s", &password[i]);
    }
   signup(user_name, password);
    {printf("\n\nPassword Match!\nLOADING");
            for(i=0;i<=6;i++)
            {
            fordelay(100000000);
            printf(".");
            }
                system("cls");
                menu();
            }
    }

    else{
    printf("WRONG INPUT!!!");
    }
    return 0;

    }






