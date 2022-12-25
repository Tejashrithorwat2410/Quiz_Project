// mini project
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
void admin();
void student();

struct stud
{
    char name[30] ;        //student data
    int rollno ;
    int  marks;
};


struct questions            // for questions
{
    char  marks ;
    char Q[100] ;
    char first[20] ;
    char second[20];
    char third[20];
    char forth[20];
};


void view()
{
    FILE *fp ;
    fp=fopen("student.txt","rb+");    //text file for student information
    struct stud p;

    printf("\n\n\t\tsr.no\t\tname\t\t\t\troll no.t\t\tmarks\n");
    int i=1 ;

    while(fread(&p,sizeof(p),1,fp) == 1)
    {

        printf("\t\t%d\t\t%s\t\t%d\t\t\t%d\n",i++,p.name,p.rollno,p.marks);

    }

    fclose(fp);
}


void update()
{
    int password=100;

    int key;
    printf("enter your security key :  ");     //for security purpuse
    scanf("%d",&key);
    if(key==password)
    {
       FILE *ft ;
       ft=remove("question.txt");         //
       ft = fopen("questions.txt","ab+");       //text file for question paper
       struct questions que;
       for(int i=0 ;i<10 ; i++)
       {
        system("cls");
        system("color 71");
		printf("\n\tenter the question %d :",i+1);
		fflush(stdin) ;
		gets(que.Q);

		printf("\n\tenter the a option :");
		fflush(stdin);
		gets(que.first);

		printf("\n\tenter the b option :");
		fflush(stdin);
		gets(que.second);

		printf("\n\tenter the c option :");
		fflush(stdin);
		gets(que.third);

		printf("\n\tenter the d option :");
		fflush(stdin);
		gets(que.forth);
		printf("\n\n");

        printf("\n\tEnter the answer of the question :");
        fflush(stdin);
        scanf("%c",&que.marks);


		fwrite(&que , sizeof(que),1,ft);
		fflush(stdin);
	}
        fclose(ft);
    }
    else
    {
        printf("access denied.....!!");
    }
    printf("press any key to continue.........\n");
    getch();
 }


void add()
{

    system("cls");
    system("color 71");
    FILE *fp , *ft ;
    fp=fopen("student.txt","ab+");          // student information storage
    char ans ;
    ft = fopen("questions.txt","rb+");      // questions are stored in these file
    struct stud new ;
    struct questions q ;

    int ctr=0;
    fflush(stdin);
    printf("\n\tenter your name : ") ;
    gets(new.name);

    fflush(stdin);
    printf("\n\tEnter your roll no : ");
    scanf("%d",&new.rollno);


    for(int i=0 ; i<10 ; i++)
    {
        fread(&q,sizeof(q) ,1, ft);


        printf("%d\t%s\n\t\ta. %s\n\t\tb. %s\n\t\tc. %s\n\t\td. %s\n",i+1,q.Q,q.first,q.second,q.third,q.forth);  //showing the quesstions

        printf("\t\tenter you appropiate answer :");
        fflush(stdin);
        scanf("%c",&ans);
        if(ans==q.marks)
        {
            printf("\n\n\tYour answeer is correct....");
            ctr++;
        }
        else
        {
            printf("\n\n\tYour answer is not correct....");
        }
    }
    new.marks=ctr ;
    printf("\n\n\rYOUR SCORE IS %d\n\n",ctr) ;
    fwrite(&new,sizeof(new),1,fp);
    fclose(fp);
    fclose(ft);
    printf("\n\n\tpress any key to continue.........\n");
    getch();
}


void result()
{
    system("cls");
    system("color 71");
    system("cls");
    system("color 71");
    int password=100;
    int key;
    printf("\n\n\tplease enter your key : "); //for admin use only
    scanf("%d",&key);
    if(key==password)
    {


	    view();
    }
    else
    {
            printf("\n\t\t Access denied..!!");
    }
    printf("\n\n\tpress any key to continue.........\n");
    getch();
}


int main()
{
    system("cls");
    system("color 71");
    int ch;
    while(3)
    {


        printf("\n1.admin\n 2.student\n 3.exit\n");
        printf("\n\n\tEnter your option:");
        scanf("%d",&ch);             //after not neccesary because this is already saved
        switch(ch)
        {
               case 1:
                     admin();
                     break ;

                case 2:
                     student();
                     break ;

                case 3:
                       exit(0);

                default:printf("please enter the correct option");


         }
    }
}
void admin()
{


       int ch;
        while(3)
       {
          printf("1.update\n 2.result\n 3.exit\n");
          printf("enter your choice\n");
          scanf("%d",&ch);
          switch(ch)
          {

             case 1:
                   update();   // for updating question
                   break ;
             case 2:
                     result();      //  for student marks
                     break ;
             case 3:
                     exit(0);

             default:printf("please enter correct choice");
           }
        }
}

void student()
 {
      int ch;
      printf("\n\t****WELCOME ON EXAM PORTAL****\n");
      printf("\n\t*Details about exam*\n");
      printf("\n\t->student only choose start exam option\n");
      printf("\n\t->There will be 10 questions \n");
      printf("\n\t->time duration=10 min\n");
      printf("\n\t->there will be 1 mark for each question and there is no negative system\n");
      printf("\n\t->each question is complsary\n");
      printf("\n\n\t*ALL THE BEST*\n");

      printf("enter your choice\n");
      printf("\n1.start exam\n 2.exit\n");
      scanf("%d",&ch);
      switch(ch)
      {

        case 1:
               add();   // for student information and question paper
               break ;
        case 2:
               exit(0);

        default:printf("please enter the correct option");
      }
  }
