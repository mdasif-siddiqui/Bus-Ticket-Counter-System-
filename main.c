#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

void mainmenu(void);
void userlogin(void);
void adminlogin(void);
void Password(int);
void adminmenu(void);
void usermenu(void);
void addmembers(void);
void removemember(void);
void viewmemberlist(void);
void addbusinfo(void);
void removebusinfo(void);
void addschediul(void);
void changeschediul(void);
void viewbusinfolist(void);
void viewschediullist(void);
void adminlogout(void);
void checkprofile(void);
void checkschediul(void);
void editprofile(void);
void bookingticket(void);
void userlogout(void);
void returnfunc(void);
void returnadmenu(void);
void returnusermenu(void);
int t(void);
int  getdata();
int  checkid(int);
int  getdata1();
int checkid1(int);
int getdata2();
int checkid2(int);
void loaderanim();

char password[10]={"asisai"};

COORD coord = {0,0};

void gotoxy (int x, int y)
{
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
char catagories[][15]={"Platinam","Gold","Selver"};
struct members
{
    int id;
    char name[30];
    char pw[30];
    char mobilenumber[30];
    char *cat;
};
struct members member;
FILE *fp,*ft;
int s;

int getdata()
{
    system(" COLOR 70 ");
	int t;
	gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	gotoxy(20,3);
	printf("Enter the Information Below");
	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(50,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(50,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(50,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(50,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(50,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(50,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(50,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2");gotoxy(50,12);printf("\xB2");
	gotoxy(20,13);
	printf("\xB2");gotoxy(50,13);printf("\xB2");
	gotoxy(20,14);
	printf("\xB2");gotoxy(50,14);printf("\xB2");
	gotoxy(20,15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(28,5);
	printf("Category:");
	gotoxy(40,5);
	printf("%s",catagories[s-1]);
	gotoxy(21,6);
	printf("Member ID:\t");
	gotoxy(31,6);
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		gotoxy(21,13);
		printf("\aThe member id already exists\a");
		getch();
		adminmenu();
		return 0;
	}
	member.id=t;
	gotoxy(21,8);
	printf("Member Name:");
	gotoxy(33,8);
	scanf("%s",member.name);
	gotoxy(21,10);
	printf("Password:");
	gotoxy(35,10);
	scanf("%s",member.pw);
	gotoxy(21,12);
	printf("Mobile Number:");
	gotoxy(35,12);
	scanf("%s",member.mobilenumber);

	return 1;

}
int checkid(int t)
{
	rewind(fp);
	while(fread(&member,sizeof(member),1,fp)==1)
	if(member.id==t)
	return 0;
    return 1;
}

char catagorie[][25]={"First Class","Second Class"};
struct buses
{
    int busid;
    char name[30];
    char dname[30];
    char mobilenumber[30];
    char *cata;


};
struct buses bus;
FILE *fs, *fa;
int sa;

int getdata1()
{
    system(" COLOR 70 ");
	int ta;
	gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	gotoxy(20,3);
	printf("Enter the Information Below");
	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(55,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(55,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(55,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(55,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(55,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(55,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(55,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2");gotoxy(55,12);printf("\xB2");
	gotoxy(20,13);
	printf("\xB2");gotoxy(55,13);printf("\xB2");
	gotoxy(20,14);
	printf("\xB2");gotoxy(55,14);printf("\xB2");
	gotoxy(20,15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(25,5);
	printf("Category:");
	gotoxy(40,5);
	printf("%s",catagorie[sa-1]);
	gotoxy(21,6);
	printf("Bus ID:\t");
	gotoxy(31,6);
	scanf("%d",&ta);
	if(checkid1(ta) == 0)
	{
		gotoxy(21,18);
		printf("\aThe member id already exists\a");
		gotoxy(21,20);
		printf("Press Enter for go back-");
		getch();
		adminmenu();
		return 0;
	}
	bus.busid=ta;
	gotoxy(21,8);
	printf("Bus Name:");
	gotoxy(33,8);
	scanf("%s",bus.name);
	gotoxy(21,10);
	printf("Driver Name:");
	gotoxy(35,10);
	scanf("%s",bus.dname);
	gotoxy(21,12);
	printf("Mobile Number:");
	gotoxy(35,12);
	scanf("%s",bus.mobilenumber);

	return 1;

}
int checkid1(int ta)
{
	rewind(fs);
	while(fread(&bus,sizeof(bus),1,fs)==1)
	if(bus.busid==ta)
	return 0;
    return 1;
}

struct schediuls
{
    int serial;
    int id;
    char start[30];
    char endp[30];
    char times[30];
    int price;

};
struct schediuls schediul;
FILE *fb, *fc;

int getdata2()
{
    system(" COLOR 70 ");
	int x;
	gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	gotoxy(20,3);
	printf("Enter the Information Below");
	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(55,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(55,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(55,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(55,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(55,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(55,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(55,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2");gotoxy(55,12);printf("\xB2");
	gotoxy(20,13);
	printf("\xB2");gotoxy(55,13);printf("\xB2");
	gotoxy(20,14);
	printf("\xB2");gotoxy(55,14);printf("\xB2");
	gotoxy(20,15);
	printf("\xB2");gotoxy(55,15);printf("\xB2");
	gotoxy(20,16);
	printf("\xB2");gotoxy(55,16);printf("\xB2");
	gotoxy(20,17);
	printf("\xB2");gotoxy(55,17);printf("\xB2");
	gotoxy(20,18);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,6);
	printf("Schediul serial:\t");
	gotoxy(37,6);
	scanf("%d",&x);
	if(checkid2(x) == 0)
	{
		gotoxy(21,18);
		printf("\aThis Schediul id already exists\a");
		gotoxy(21,20);
		printf("Press Enter for go back-");
		getch();
		adminmenu();
		return 0;
	}
	schediul.serial=x;
	gotoxy(21,8);
	printf("Bus Id:");
	gotoxy(37,8);
	scanf("%d", &schediul.id);
	gotoxy(21,10);
	printf("Source ststion:");
	gotoxy(37,10);
	scanf("%s",schediul.start);
	gotoxy(21,12);
	printf("Destination:");
	gotoxy(37,12);
	scanf("%s",schediul.endp);
	gotoxy(21,14);
	printf("Start Time:");
	gotoxy(37,14);
	scanf("%s",schediul.times);
    gotoxy(21,16);
	printf("Ticket Price:");
	gotoxy(37,16);
	scanf("%d",&schediul.price);
	return 1;

}
int checkid2(int x)
{
	rewind(fb);
	while(fread(&schediul,sizeof(schediul),1,fb)==1)
	if(schediul.serial==x)
	return 0;
    return 1;
}

char findmember;
char findbus;
char findschediul;

int main()
{
    system(" COLOR 71 ");
    mainmenu();
    getch();
    return 0;
}

void mainmenu()
{
    system(" COLOR 07 ");
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(17,3);
    printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1 MAIN MEMU \xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2  1. Admin Login");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2  2. User Login");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2  3. Exit");
    gotoxy(20,13);
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,15);
    t();

    gotoxy(20,17);
    printf("Enter Your Choice:");


    switch(getch())
    {
        case '1':
            adminlogin();
            break;
        case '2':
            userlogin();
            break;
        case '3':
            {
                system("cls");
                gotoxy(16,3);
                printf("Programmers....");
                gotoxy(16,5);
                printf("1. Md Asif Siddiqui       (132-35-469)");
                gotoxy(16,7);
                printf("   Mobile:01933646034  E-mail:asif.kholaakash@diu.edu.bd");
                gotoxy(16,9);
                printf("2.  Saikat Biswas         (131-35-405)");
                gotoxy(16,11);
                printf("   Mobile:01689112775  E-mail:saikatbiswas024@diu.edu.bd");
                gotoxy(16,14);
                printf("With  the Unexplainable Help of Ms. Shikha Anirban");
                gotoxy(16,16);
                printf("Exiting in 5 second...........>");
                delay(5000);
                exit(0);
	      }
        default:
            {
                gotoxy(10,20);
                printf("\aWrong Entry!!Please re-entered correct option");
                if(getch())
                mainmenu();
            }
    }
}



void adminlogin()
{
    system(" COLOR 07 ");
    Password(1);

}
void Password(int isFirstTime)
{

   system("cls");
   if(isFirstTime == 0)
   {
     gotoxy(15,16);
	 printf("Incorrect Password. Input the password again");
	 delay(1500);
     system("cls");
   }

   char d[25]="Password Protected";
   char ch,pass[10];
   int i=0,j;

    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    delay(50);
    printf("*");
    }
    for(j=0;j<20;j++)
   {
    delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
    delay(50);
   printf("*");
   }
    gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,9);
	printf("Password match");
	gotoxy(15,11);
	printf("Press any key to go to the admin menu.");
	if(getch())
    {
     adminmenu();
    }
   }
   else
   {
	 Password(0);
   }
}

void adminmenu()
{
    system(" COLOR F0 ");
    loaderanim();
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(17,3);
    printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1 ADMIN MEMU \xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2  1. Add Member");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2  2. Remove Member");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2  3. Member List");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2  4. Add Bus Info");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2  5. Remove Bus Info");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2  6. Bus info list");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2  7. Add Schediul");
    gotoxy(20,21);
    printf("\xDB\xDB\xDB\xDB\xB2  8. Change Schediul");
    gotoxy(20,23);
    printf("\xDB\xDB\xDB\xDB\xB2  9. Schediul list");
    gotoxy(20,25);
    printf("\xDB\xDB\xDB\xDB\xB2  0. Logout");
    gotoxy(20,27);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,30);
    t();
    IpOptions:
    gotoxy(20,33);
    printf("Enter Your Choice:");


    switch(getch())
    {
        case '1':
            addmembers();
            break;
        case '2':
            removemember();
            break;
        case '3':
            viewmemberlist();
            break;
         case '4':
            addbusinfo();
            break;
         case '5':
            removebusinfo();
            break;
         case '6':
            viewbusinfolist();
            break;
         case '7':
            addschediul();
            break;
         case '8':
            changeschediul();
            break;
         case '9':
            viewschediullist();
            break;
        case '0':
            adminlogout();
            break;
        default:
            {
                gotoxy(10,33);
                printf("\aWrong Entry !! Please re-enter your choise");
                goto IpOptions;
            }

    }


}
void addmembers()
{
    system(" COLOR 71 ");
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	gotoxy(20,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Platinam");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Gold");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Selver");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Back to main menu");
	gotoxy(20,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,20);
	printf("Enter your choice:");
	scanf("%d",&s);
	if(s==4)

	adminmenu() ;
	system("cls");
	fp=fopen("asisai.dat","ab+");
	if(getdata()==1)
	{
	member.cat=catagories[s-1];
	fseek(fp,0,SEEK_END);
	fwrite(&member,sizeof(member),1,fp);
	fclose(fp);
	gotoxy(21,20);
	printf("The record is sucessfully saved");
	gotoxy(21,22);
	printf("Save any more?(Y / N):");
	if(getch()=='n')
	    adminmenu();
	else
	    system("cls");
	    addmembers();
	}
}

void removemember()
{
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	gotoxy(10,5);
	printf("Enter the Member ID to  delete:");
	scanf("%d",&d);
	fp=fopen("asisai.dat","rb+");
	rewind(fp);
	while(fread(&member,sizeof(member),1,fp)==1)
	{
	    if(member.id==d)
	    {

		gotoxy(10,7);
		printf("The member record is available");
		gotoxy(10,8);
		printf("Member name is %s",member.name);
		findmember='t';
	    }
	}
	if(findmember!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    adminmenu();
	}
	if(findmember=='t' )
	{
	    gotoxy(10,9);
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		ft=fopen("test.dat","wb+");
		rewind(fp);
		while(fread(&member,sizeof(member),1,fp)==1)
		{
		    if(member.id!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&member,sizeof(member),1,ft);
		    }
		}
		fclose(ft);
		fclose(fp);
		remove("asisai.dat");
		rename("test.dat","asisai.dat");
		fp=fopen("asisai.dat","rb+");
		if(findmember=='t')
		{
		    gotoxy(10,10);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,11);
		    printf("Delete another record?(Y/N)");
		}
	    }
	else
	returnadmenu();
	fflush(stdin);
	another=getch();
	}
	}
    gotoxy(10,15);
    returnadmenu();
}
void viewmemberlist(void)
{
    system(" COLOR 71 ");
    int i=0,j;
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(1,1);
    printf("*********************************Member List*****************************");
    gotoxy(2,3);
    printf(" CATEGORY      ID           Member NAME        Mobile Number      ");
    j=5;
    fp=fopen("asisai.dat","rb");
    while(fread(&member,sizeof(member),1,fp)==1)
    {
	gotoxy(3,j);
	printf("%s", member.cat);
	gotoxy(18,j);
	printf("%d", member.id);
	gotoxy(30,j);
	printf("%s", member.name);
	gotoxy(49,j);
	printf("%s", member.mobilenumber);
	printf("\n\n");
	j=j+2;

    }
      fclose(fp);
      gotoxy(35,25);
      returnadmenu();
}

void addbusinfo()
{
    system(" COLOR 71 ");
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	gotoxy(20,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 1. First Class");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Second Class");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Back to main menu");
	gotoxy(20,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,20);
	printf("Enter your choice:");
	scanf("%d",&sa);
	if(sa==3)

	adminmenu() ;
	system("cls");
	fs=fopen("asif.dat","ab+");
	if(getdata1()==1)
	{
	bus.cata=catagorie[sa-1];
	fseek(fs,0,SEEK_END);
	fwrite(&bus,sizeof(bus),1,fs);
	fclose(fs);
	gotoxy(21,20);
	printf("The record is sucessfully saved");
	gotoxy(21,22);
	printf("Save any more?(Y / N):");
	if(getch()=='n')
	    adminmenu();
	else
	    system("cls");
	    addbusinfo();
	}

}
void removebusinfo()
{
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    int da;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	gotoxy(10,5);
	printf("Enter the Bus ID to  delete:");
	scanf("%d",&da);
	fs=fopen("asif.dat","rb+");
	rewind(fs);
	while(fread(&bus,sizeof(bus),1,fs)==1)
	{
	    if(bus.busid==da)
	    {

		gotoxy(10,7);
		printf("The bus record is available");
		gotoxy(10,8);
		printf("Bus name is %s",bus.name);
		findbus='t';
	    }
	}
	if(findbus!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    adminmenu();
	}
	if(findbus=='t' )
	{
	    gotoxy(10,9);
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		fa=fopen("sid.dat","wb+");
		rewind(fs);
		while(fread(&bus,sizeof(bus),1,fs)==1)
		{
		    if(bus.busid!=da)
		    {
			fseek(fa,0,SEEK_CUR);
			fwrite(&bus,sizeof(bus),1,fa);
		    }
		}
		fclose(fa);
		fclose(fs);
		remove("asif.dat");
		rename("sid.dat","asif.dat");
		fs=fopen("asif.dat","rb+");
		if(findbus=='t')
		{
		    gotoxy(10,10);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,11);
		    printf("Delete another record?(Y/N)");
		}
	    }
	else
	returnadmenu();
	fflush(stdin);
	another=getch();
	}
	}
    gotoxy(10,15);
    returnadmenu();
}
void addschediul()
{
    system(" COLOR 71 ");
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
	int i;

	fb=fopen("saikat.dat","ab+");
	if(getdata2()==1)
	{
	fseek(fb,0,SEEK_END);
	fwrite(&schediul,sizeof(schediul),1,fb);
	fclose(fb);
	gotoxy(21,20);
	printf("The record is sucessfully saved");
	gotoxy(21,22);
	printf("Save any more?(Y / N):");
	if(getch()=='n')
	    adminmenu();
	else
	    system("cls");
	    addschediul();
	}
}
void changeschediul()
{
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    int g;
    char another='y';
    while(another=='y')
    {
	system("cls");
	gotoxy(10,4);
	printf("Enter the schediul serial to  delete:");
	scanf("%d",&g);
	fb=fopen("saikat.dat","rb+");
	rewind(fb);
	while(fread(&schediul,sizeof(schediul),1,fb)==1)
	{
	    if(schediul.serial==g)
	    {

		gotoxy(10,5);
		printf("The schediul record is available");
		gotoxy(10,7);
		printf("Source Station is %s",schediul.start);
		gotoxy(10,8);
		printf("Destination is %s",schediul.endp);
		gotoxy(10,9);
		printf("Start Time is %s",schediul.times);
		findschediul='t';
	    }
	}
	if(findschediul!='t')
	{
	    gotoxy(10,11);
	    printf("No record is found modify the search");
	    if(getch())
	    adminmenu();
	}
	if(findschediul=='t' )
	{
	    gotoxy(10,13);
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		fc=fopen("si.dat","wb+");
		rewind(fb);
		while(fread(&schediul,sizeof(schediul),1,fs)==1)
		{
		    if(schediul.serial!=g)
		    {
			fseek(fc,0,SEEK_CUR);
			fwrite(&schediul,sizeof(schediul),1,fc);
		    }
		}
		fclose(fc);
		fclose(fb);
		remove("saikat.dat");
		rename("si.dat","saikat.dat");
		fb=fopen("saikat.dat","rb+");
		if(findschediul=='t')
		{
		    gotoxy(10,15);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,16);
		    printf("Delete another record?(Y/N)");
		}
	    }
	else
	returnadmenu();
	fflush(stdin);
	another=getch();
	}
	}
    gotoxy(10,25);
    returnadmenu();
}
void viewbusinfolist()
{
    system(" COLOR 71 ");
    int i=0,j;
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(1,1);
    printf("*********************************Bus List*****************************");
    gotoxy(2,3);
    printf(" CATEGORY      ID          Bus Name       Driver Name      Mobile Number      ");
    j=5;
    fs=fopen("asif.dat","rb");
    while(fread(&bus,sizeof(bus),1,fs)==1)
    {
	gotoxy(3,j);
	printf("%s", bus.cata);
	gotoxy(18,j);
	printf("%d", bus.busid);
	gotoxy(30,j);
	printf("%s", bus.name);
	gotoxy(49,j);
	printf("%s", bus.dname);
	gotoxy(63,j);
	printf("%s", bus.mobilenumber);
	printf("\n\n");
	j=j+2;

    }
      fclose(fs);
      gotoxy(35,25);
      returnadmenu();
}
void viewschediullist()
{
    system(" COLOR 71 ");
    int i=0,j=5;
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(1,1);
    printf("*********************************Schediul List********************************");
    gotoxy(2,3);
    printf("SERIAL   Bus id   SOURCE STATION     DESTINATION       TIME    Ticket Price  ");
    fb=fopen("saikat.dat","rb");
    while(fread(&schediul,sizeof(schediul),1,fb)==1)
    {
	gotoxy(4,j);
	printf("%d", schediul.serial);
	gotoxy(13,j);
	printf("%d", schediul.id);
	gotoxy(25,j);
	printf("%s", schediul.start);
	gotoxy(40,j);
	printf("%s", schediul.endp);
	gotoxy(57,j);
	printf("%s", schediul.times);
	gotoxy(68,j);
	printf("%d", schediul.price);
	printf("\n\n");
	j=j+2;

    }
      fclose(fb);
      gotoxy(35,25);
      returnadmenu();
}

void adminlogout()
{
    system(" COLOR 71 ");
    system("cls");
    gotoxy(20,10);
    printf("Are you confirm to logout, if yes- press Y.");
    if(getch()=='y')
    {
       returnfunc();
    }
    else
    {
        adminmenu();
    }

}
void userlogin()
{
    system(" COLOR 71 ");
    system("cls");
    int memberid;
    int i=0;
    char memberpw[30];
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("Enter your id :");
    scanf("%d", &memberid);
    gotoxy(20,9);
    printf("Enter your Password :");
    scanf("%s", memberpw);

    fp=fopen("asisai.dat","rb");
    rewind(fp);
    while(fread(&member,sizeof(member),1,fp)==1)
	    {
		if(member.id==memberid && strcmp(member.pw,memberpw)==0)
		{
		    loaderanim();
            usermenu();
            i=1;
		}
	    }
	    if(i==0)
        {
            loaderanim();
            mainmenu();
        }
    fclose(fp);

}

void usermenu()
{
    system(" COLOR F0 ");
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(26,3);
    printf("Welcome User - to your Info of Bus Counter");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,6); printf("USER NAME          %s", member.name);
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2  1. View Profile");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2  2. Edit Profile");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2  3. Check Schediul");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2  4. Booking Ticket");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2  5. Logout");
    gotoxy(20,17);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,19);
    t();
    Options:
    gotoxy(20,21);
    printf("Enter Your Choice:");

    switch(getch())
    {
        case '1':
            checkprofile();
            break;
        case '2':
           editprofile();
            break;
        case '3':
            checkschediul();
            break;
        case '4':
            bookingticket();
            break;
         case '5':
            userlogout();
            break;
        default:
            {
                gotoxy(10,20);
                printf("\aWrong Entry !! Please re-enter");
                goto Options;
            }

    }


}
void checkprofile()
{
    system(" COLOR 71 ");
   system("cls");
   gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
   gotoxy(10,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(10,5);
	printf("\xB2");gotoxy(70,5);printf("\xB2");
	gotoxy(10,6);
	printf("\xB2");gotoxy(70,6);printf("\xB2");
	gotoxy(10,7);
	printf("\xB2");gotoxy(70,7);printf("\xB2");
	gotoxy(10,8);
	printf("\xB2");gotoxy(70,8);printf("\xB2");
	gotoxy(10,9);
	printf("\xB2");gotoxy(70,9);printf("\xB2");
	gotoxy(10,10);
	printf("\xB2");gotoxy(70,10);printf("\xB2");
	gotoxy(10,11);
	printf("\xB2");gotoxy(70,11);printf("\xB2");
	gotoxy(10,12);
	printf("\xB2");gotoxy(70,12);printf("\xB2");
	gotoxy(10,13);
	printf("\xB2");gotoxy(70,13);printf("\xB2");
	gotoxy(10,14);
	printf("\xB2");gotoxy(70,14);printf("\xB2");
	gotoxy(10,15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,17);
    t();
    gotoxy(12,7);
    printf("NAME:           %s",member.name);
    gotoxy(12,9);
    printf("ID:             %d",member.id);
    gotoxy(12,11);
    printf("Catagories:     %s",member.cat);
    gotoxy(40,7);
    printf("PASSWORD:       %s",member.pw);
    gotoxy(40,9);
    printf("MOBILE NO:      %s",member.mobilenumber);
    gotoxy(4,21);
    printf("Press any key to return to user menu......");
    if(getch())
    {
        usermenu();
    }

}
void editprofile()
{
    system(" COLOR 71 ");
   system("cls");
   gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
   gotoxy(10,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(10,5);
	printf("\xB2");gotoxy(70,5);printf("\xB2");
	gotoxy(10,6);
	printf("\xB2");gotoxy(70,6);printf("\xB2");
	gotoxy(10,7);
	printf("\xB2");gotoxy(70,7);printf("\xB2");
	gotoxy(10,8);
	printf("\xB2");gotoxy(70,8);printf("\xB2");
	gotoxy(10,9);
	printf("\xB2");gotoxy(70,9);printf("\xB2");
	gotoxy(10,10);
	printf("\xB2");gotoxy(70,10);printf("\xB2");
	gotoxy(10,11);
	printf("\xB2");gotoxy(70,11);printf("\xB2");
	gotoxy(10,12);
	printf("\xB2");gotoxy(70,12);printf("\xB2");
	gotoxy(10,13);
	printf("\xB2");gotoxy(70,13);printf("\xB2");
	gotoxy(10,14);
	printf("\xB2");gotoxy(70,14);printf("\xB2");
	gotoxy(10,15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,17);
    t();
    fp=fopen("asisai.dat","rb+");
    gotoxy(12,6);
		    printf(" ID:            %d",member.id);
		    gotoxy(12,8);
		    printf(" Name:          %s",member.name);
		    gotoxy(12,10);
		    printf(" Mobile Number: %s",member.mobilenumber);
		    gotoxy(12,12);
		    printf(" Password:      %s",member.pw);

		    gotoxy(42,8);
		    printf("New Name:      ");scanf("%s",member.name);
		    gotoxy(42,10);
		    printf("New Mobile No: ");scanf("%s",member.mobilenumber);
		    gotoxy(42,12);
		    printf("New Password:  ");scanf("%s",member.pw);

            fseek(fp,ftell(fp)-sizeof(member),0);
            fwrite(&member,sizeof(member),1,fp);
            fclose(fp);
				gotoxy(10,20);
				printf("your profile is modified....       press any key to continue....");

				if (getch())
                {
                    system("cls");
                    checkprofile();
                }

}
void checkschediul()
{
    system(" COLOR 71 ");
    int i=0,j=5;
    system("cls");
    gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
    gotoxy(1,1);
    printf("*********************************Schediul List*****************************");
   gotoxy(2,3);
    printf("SERIAL   Bus id   SOURCE STATION     DESTINATION       TIME    Ticket Price  ");
    fb=fopen("saikat.dat","rb");
    while(fread(&schediul,sizeof(schediul),1,fb)==1)
    {
	gotoxy(4,j);
	printf("%d", schediul.serial);
	gotoxy(13,j);
	printf("%d", schediul.id);
	gotoxy(25,j);
	printf("%s", schediul.start);
	gotoxy(40,j);
	printf("%s", schediul.endp);
	gotoxy(57,j);
	printf("%s", schediul.times);
	gotoxy(68,j);
	printf("%d", schediul.price);
	printf("\n\n");
	j=j+2;

    }
      fclose(fb);
      gotoxy(35,25);
      returnusermenu();
}

void bookingticket()
{
   system("cls");
   gotoxy(0,0);
    printf(">>>>>>>>>>>>>>>>>>>>>>> BUS COUNTER INFORMATION SYSTEM <<<<<<<<<<<<<<<<<<<<<<<<<");
   int i=0;
   int serial, a, b;
   fs=fopen("asif.dat","rb+");
    fb=fopen("saikat.dat","rb+");
    rewind(fs);
    rewind(fb);
    gotoxy(20,7);
   printf("Enter schediul serial :");
    scanf("%d", &serial);
    gotoxy(20,9);
    printf("Enter bus Id :");
    scanf("%d",&b);
    while((fread(&schediul,sizeof(schediul),1,fb)==1))
	    {
                if(schediul.serial==serial)
                    {
                        while(fread(&bus,sizeof(bus),1,fs)==1)
                        {
                            if(bus.busid==b)
                            {
                                system("cls");
                                //loaderanim();
                                gotoxy(20,2);
                                printf("Your Source Station is : %s", schediul.start);
                                gotoxy(20,4);
                                printf("Your Destination : %s", schediul.endp);
                                gotoxy(20,6);
                                printf("Your Time : %s", schediul.times);
                                gotoxy(20,8);
                                printf("Your Bus Name : %s", bus.name);
                                gotoxy(20,10);
                                printf("Bus Driver Name : %s", bus.dname);
                                gotoxy(20,12);
                                printf("Driver Mobile Number : %s", bus.mobilenumber);
                                gotoxy(20,14);
                                printf("Bus Serial : %d", bus.busid);
                                gotoxy(20,16);
                                printf("Ticket Price : %d", schediul.price);
                                 i=1;
                                break;

                            }

                        }
                        break;


                    }

	    }
	    if(i!=0)
        {
            gotoxy(20,18);
            printf("How many ticket you want:");
            scanf("%d", &a);
            gotoxy(20,20);
            printf("Total Ticket Price : %d", a*schediul.price);
                gotoxy(20,22);
                printf(" Press Y to confirme your booking");

                if(getch()=='y')
                {
                    system("cls");
                    gotoxy(20,13);
                    printf("Congratulation. Your Booking confirm.");
                    gotoxy(20,15);
                    printf("Press any key to return to user menu......");
                    if(getch())
                    {
                        usermenu();
                    }
                }
                else
	                usermenu();
        }
	    else
        {
            loaderanim();
            usermenu();
        }
    fclose(fs);
    fclose(fb);
}
void userlogout()
{
    system("cls");
    returnfunc();
}


void returnfunc(void)
{
    {
        gotoxy(20,15);
        printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13)
    mainmenu();
    else
    goto a;
}
void returnadmenu(void)
{
    {
        gotoxy(20,15);
        printf(" Press ENTER to return to admin menu");
    }
    a:
    if(getch()==13)
    adminmenu();
    else
    goto a;
}
void returnusermenu(void)
{
     {
        gotoxy(20,15);
        printf(" Press ENTER to return to user menu");
     }
    a:
    if(getch()==13)
    usermenu();
    else
    goto a;

}

int t(void)
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
void loaderanim()
{
int loader;
system("cls");
gotoxy(20,10);
printf("LOADING........");
printf("\n\n");
gotoxy(22,11);
for(loader=1;loader<20;loader++)
{
delay(100);printf("%c",219);}
}

