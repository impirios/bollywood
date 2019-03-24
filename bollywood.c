#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
char movies[100][50]={"andhadhun\0","badhaiho\0","kesari\0","uri\0","parmanu\0","swades\0","jolly llb\0","massan\0","zindagi na milegi dobara\0","gully boy\0","padmavat\0","rocket singh sales man of the year\0","bhavesh joshi superhero\0","my name is khan\0","raja hindustani\0","padman\0","koyla\0","new york\0","sholay\0","desi boys\0"};
char name[]="BOLLYWOOD";

//run function is used to animate any string


void run(char thing[])
{
	system("color c");

	char str[100],x;
	int j,s,f,ch=0;
	for(j=0;j<50;j++)
	{
		///x=(ch%2==0)?'\n':' ';
		//ch++;
		system("cls");
		for(s=0;s<j;s++)
			{
				str[s]=' ';
				
				printf("%c",str[s]);
			}
		Sleep(20);
		puts(thing);
		
		

	}
}

//vowel function will check weather a character is vowel or not 

int vowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 1;
	else
		return 0;
}

//win function displays the win animation if the player wins
void win()
{
	char woo[]="congratulations! You won";
	run(woo);
}

//lose function will display the You lose animation if the player looses
void lose()
{
	char oh[]="You lose";
	run(oh);
}

//randomarr function generates a random number from 0 to x 
int randomarr(int x)
{
   int num=(rand()%x+1);
   return num;
}


void main()
{
	
	menu:
	{
		system("cls");
		printf("\n\n\n\n\t\t\t\tStart game\n\n\n\t\t\t\tInstructions\n\n\n\t\t\t\tAbout the developer");
	}
	char ch=getche();
	if(ch=='i')
	{	
		system("cls");
		printf("\n\t\t\t\t\tWelcome to the game BOLLYWOOD\n\nRules of the game\n\nYou have to guess the movie from incomplete words\n\nif you guess the character right you'll increase your chances\n\nwrong guess will decrease your chances\n\n");
		printf("\n\nPress b to go back to main menu\n");
		getche();
		goto menu;
	}
	else if(ch=='a')
	{
		system("cls");
		printf("\t\t\t\tCould'nt think of anything");
		printf("\n\n\nPress b to go back to main menu\n");
		getche();
		goto menu;
	}
	else
	{
	run(name);
	int j,x,i,n,w=0,count;
	char c;
	char str[100];

	/*
	for(j=0;j<strlen(movies[1]);j++)
		printf("%c",movies[1][j]);
*/
	srand(time(0));
	x=randomarr(19);
	n=strlen(movies[x]);

	for(i=0;i<n;i++)
	{
		if(vowel(movies[x][i])==1||movies[x][i]==' ')
			str[i]=movies[x][i];
		else
			str[i]='_';
	}

	str[i]='\0';

count=8;
while(count!=0)
{
	system("cls");
	if(strcmp(movies[x],str)==0)
	{
		win();
		break;

	}
	else
	{	
		printf("\t\t\t\t\t");
		puts(str);
		printf("\t\t\t\t\t\t\t\t\t\tlife-%d\n",count );

		printf("\nEnter your character\n");
		scanf("%c",&c);
		for(i=0;i<n;i++)
		{
			if(movies[x][i]==c && str[i]!=c)
			{
				str[i]=movies[x][i];
				count=count+3;
			
			}
			
		}
		
	}
	count=count-1;
}
	if(count==0)
	lose();
	}
	goto menu;
}