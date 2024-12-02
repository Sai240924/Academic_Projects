#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct play
{
   char name[20];
   int score;

}p;
void high_score1();
void high_score();
void start();
void help();

void main()
{
    int choice = 0;
    clrscr();
    printf(" Please enter 1 to start the game \n ");
    printf(" \n Please enter 2 to the high scores \n ");
    printf(" \n Please enter 3 to seek help \n ");
    printf(" \n Please enter 0 to exit \n ");
       scanf( "%d", &choice );

    switch(choice)
    {
	case 1:
	    start();
	    break;

	case 2:
	    high_score();
	    break;

	case 3: help();
		break;

	default: exit(1);
    }
  getch();
}

void high_score1()
{
 int ch1;
 FILE*fa;
 clrscr();
  if( ( fa = fopen("\\tmp\play2.txt", "r" ) ) == NULL )
  {
    printf( "\n There are no games played !!\n " );
  }
  else
  {
    printf( "\n The high scores till now !! \n\n " );
    printf(" Name \t\t Points_Scored    \n " );
    while(fscanf(fa," %s %d %d", p.name, &p.score) !=EOF )
    {
      printf( " .................................\n " );
      printf( "  %s \t\t %d      \n\n ", p.name,p.score);
    }
    fclose(fa);
   }
   printf("\n\t\tPress 0 to exit : ");
   scanf("%d",&ch1);
   if(ch1==0)
   {
   exit(1);
   }
}
void high_score()
{
  int ch;
  FILE *fa;
  clrscr();
  if( ( fa = fopen("\\tmp\play2.txt", "r" ) ) == NULL )
  {
    printf( "\n There are no games played !!\n " );
  }
  else
  {
    printf( "\n The high scores till now !! \n\n " );
    printf(" Name \t\t Points_Scored    \n " );
    while(fscanf(fa," %s %d %d", p.name, &p.score) !=EOF )
    {
      printf( " .................................\n " );
      printf( "  %s \t\t %d      \n\n ", p.name,p.score);
    }
    fclose(fa);

  }
  printf("\nDo you still want to continue playing ? \nIf yes,then press 1 !! Else, press 0 :  " );
  scanf( "%d", &ch );
  if( ch == 1 )
  {
    start();
  }
  else
  {
    exit(1);
  }

}

void help()
{
  int ch;
  clrscr();
   printf( "\n\n Instructions that are supposed to be followed " );
   printf("while playing this game: \n " );
   printf("......................................................" );
   printf( "\n You are supposed to answer 10 questions in this game !! " );
   printf( "\n There will be 4 options given for each questions which are marked with a serial number starting from 1 to 4. " );
   printf( "\n For each correct answer, you will be awarded with 5 points !! " );
   printf( "\n As soon as you answer a question, you will be directed to the next question without any pause. " );
   printf( "\n If your answer is wrong, no marks will be deducted from your score !! " );
   printf( "\n\n !! Wish you all the best !! \n\n " );
   printf( "\n Do you still wish to continue playing ?\n If yes, then press 1. Else, press 0 :  " );
   scanf( "%d", &ch );

    if( ch == 1 )
    {
      start();
    }
    else
    {
	exit(1);
    }
}

void start()
{
  int ans,op;
  int count = 0;
  char rating[20];
  FILE *fa;
  clrscr();
  if((fa=fopen("\\tmp\play2.txt","a"))==NULL)
   {
     printf(" There is an error occurred while opening thefile\n ");
   }
  printf( "\n Enter your Full name: " );
  scanf( "%s", p.name );
  clrscr();
  printf("\n You have entered the \"Quiz game in C\"\n");
  printf(" Welcome to the game \" %s \"   \n\n ", p.name);
  printf(" The quiz game will be started now. Get ready to answer the questions !! \n ");
  printf(" ALL THE BEST !!\n ");
  printf("=============================================================================\n");

  printf(" Question 1: \n");
  printf(" In the following given characteristics, which one is not related to the federal government ? \n ");
  printf(" 1. Flexible Constitution \t \t 2. Written Constitution \n  3. Independent Judiciary \t \t 4. Supremacy of the Constitution \n\n ");
  printf(" Please enter your answer: ");
  scanf("%d", &ans);
   if( ans == 1 )
    {
      printf(" Your answer is absolutely correct \n ");
      printf(" You score 5 points !! \n\n ");
      ++count;
    }
    else
    {
     printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  1. Flexible Constitution \n\n");
    }

    printf("Question 2: \n");
    printf(" In the following given members, who was the first person belonging to India entered into the space ? \n");
    printf(" 1. Ravish Malhotra \t \t 2. Vikram Ambalal \n 3. Rakesh Sharma \t \t 4. Nagapathi Bhat \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 3 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
    else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  3. Rakesh Sharma  \n\n");
    }
    printf(" Question 3: \n");
    printf(" Who was the first women to reach the summits of all seven highest mountain peaks on every continent ? \n");
    printf(" 1. Junko Tabei \t \t 2. Bachendri Pal \n 3. Premlata Agarwal \t \t 4. Santosh yadav \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
      if( ans == 1 )
       {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
       }
      else
       {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  1. Junko Tabei  \n\n");
       }

    printf(" Question 4: \n");
    printf(" Who was the first person to be the Indian Prime Minister ? \n");
    printf(" 1. Prathiba Patel \t\t 2. Jawaharlal Nehru \n 3. Rabindranath Tagore \t\t 4. Lal Bahadur Shastri \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 2 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
    else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  2. Jawaharlal Nehru  \n\n");
    }
    printf(" Question 5: \n");
    printf(" How many bones does an adult human skeleton have ? \n");
    printf(" 1. 207 bones \t \t 2. 205 bones \n 3. 206 bones \t \t 4. 210 bones \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 3 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
    else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  3. 206 bones  \n\n");
    }
    printf(" Question 6: \n");
    printf(" Which blood group out of the following is known to be universal acceptor ? \n");
    printf(" 1. AB + \t \t 2. AB - \t \t 3. O + \t \t 4. O - \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 1 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
    else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  1. AB +  \n\n");
    }
    printf(" Question 7: \n");
    printf(" What is Vitamin K also known as ? \n");
    printf(" 1. Riboflavin \t \t 2. Thiamine \n 3. Ascorbic acid \t \t 4. Pentamine \n\n ");
   printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 3 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
   else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  3. Ascorbic acid  \n\n");
    }

    printf(" Question 8: \n");
    printf(" Out of the following membranes, which membrane is mostly present in both Spinal cord and Brain ? \n");
    printf(" 1. Meninges \t \t 2. Arachnoids \n 3. Plasma Membrane \t \t 4. Pleural membrane \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
   if( ans == 1 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
   else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option  1. Meninges  \n\n");
    }
    printf(" Question 9: \n");
    printf(" Which person among the following people have contributed their time to represent the first budget of India after its Independence ? \n");
    printf(" 1. Manmohan Singh \t \t 2. Jawaharlal Nehru \n 3. Pranav Mukherjee \t \t 4. R. K. Shanmukham Chetty \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 4 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
    else
     {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is option no. 4. R. K. Shanmukham Chetty  \n\n");
     }

    printf(" Question 10: \n");
    printf(" Which position out of the following has a right to select and appoint a Prime Minister ? \n");
    printf(" 1. President \t \t 2. Chief Justice of India \n 3. Governor \t \t 4. Vice President \n\n ");
    printf("Please enter your answer: ");
    scanf("%d", &ans);
    if( ans == 1 )
    {
	printf(" Your answer is absolutely correct \n ");
	printf(" You score 5 points !! \n\n ");
	++count;
    }
    else
    {
	printf(" The answer that you have entered is wrong.\n The correct answer for the above question is : 1. President  \n\n");
    }
    printf("You have answered %d correct out of 10 questions \n",count);

    if(count > 0)
    {
	printf(" You have scored %d points \t \n\n", count * 5 );
	printf("\t\t\t*******THANK YOU******\n");
	printf("\t\t\t*FOR SHOWING INTEREST*\n");
	printf("\t\t\t******VISIT AGAIN*****\n\n");
	p.score = count * 5;
	fprintf(fa, "%s %d ", p.name, p.score );
	fclose(fa);
    }
    else
    {
	printf(" You have not answered any of the questions with correct answer !! Please try again\n");
    }
    printf("\n\tDo you want to view Highscore? \n\tIf yes press 1 ,else press 0 : ");
    scanf("%d",&op);
    if(op==1)
    {
    high_score1();
    }
    else
    {
    exit(1);
    }
}