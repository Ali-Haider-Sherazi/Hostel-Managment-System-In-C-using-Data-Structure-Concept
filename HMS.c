                    //HOSTEL MANAGMENT SYSTEM
                    //FA20-BSE-017(B)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define total 250
struct hostelite
{
    char name[50];
    int id;
    int block;
    int age;
    char phone[30];
    char gender[5];
    char pass[30];
    char room[10];//Single bed, DOUBLE bed
    char food[10];
    float fee;
    char gues[10];
    int roomNo;
    struct hostelite *next;
    struct hostelite *next1;//SAMPLE
    char notific[150];
};
struct complain//For Complaint
{
    int sender;
    char com[150];
    struct complain *nextone;
};
struct messages//For message
{
    int sender_id;
    int reciver_id;
    char mes[150];
    char seen[10];
    int count;
    int numbers;
    int hsnumbers;
    struct messages *next;
};
struct LeaveN//For Leave Note
{
    int sender;
    int approve;
    char note[150];
    int seen;
    struct LeaveN *next;
};
//Declare some pointer
struct hostelite *host,*guest,*add,*holdH,*p,*q,*temp,*first=NULL,*q1,*tempdel;
struct messages *header=NULL,*newnode,*newnode1,*temp1,*s,*n;
struct complain *head=NULL,*node,*t,*u;
struct LeaveN *point=NULL,*sample,*start,*z;
//declare some global variable
int idnumb=1,rooms=1,roomc=50,roomfs=100,roomfc=150,roomgs=200,roomgc=225,reserved=0;//rooms and roomc is for single room for male similar roomg for guest and roomf for females
int removes=0,removec=0,removefs=0,removefc=0,removegs=0,removegc=0;//if person delete then it will decrement reserved section
float Fees=1000.00;
int deletion=0,incremental=0;//deletion count for msg
int lockA=0,lockB=0;
char password[30],prev[30];
void Already(char name[10],char passw[10],char ph[13],char gend[10],char roomn[10],char foody[10])//same for deletion data store
{
    strcpy(password,"1111");//password for admin
    add= (struct hostelite *)malloc(sizeof(struct hostelite));
    add->next=NULL;
    if(host==NULL)
    {
        host=holdH=add;
    }
    else
    {
        holdH->next=add;
        add->next=NULL;
        holdH=add;
    }
    add->id=idnumb;
    idnumb++;
    add->age=18;
    strcpy(add->name,name);
    strcpy(add->notific,"NULL");
    strcpy(add->pass,passw);
    strcpy(add->phone,ph);
    strcpy(add->gender,gend);
    strcpy(add->room,roomn);
    add->roomNo=roomc;
    reserved++;
    roomc++;
    removec=roomc;
    strcpy(add->food,foody);
    add->fee=2500.00;
    add->block=0;
}
void Design(char s[100])
{
    printf("\t\t\t\t\t================================================\n");
    printf("\t\t\t\t\t\t  %s \n",s);
    printf("\t\t\t\t\t================================================\n");
}
void Line()
{
    int n=1;
    while(n!=44)
    {
        printf("-");
        n++;
    }
}
void load(int value,char s[100])
{

    if(s!=NULL)
    printf("\n\n\t\t\t\t\t    %s \n\t\t\t\t\t");
    for(int c=1; c<=value; c++)
    {
        for(int d=0; d<=10000000; d++); //to display the character slowly
        printf("%c",177);
    }
    if(s==NULL)
    {   printf("  %d",value);
        return;
    }
    system("cls");
}

void loadP(char s[100])
{
    for(int r=1; r<=20; r++)
    {
        for(int f=0; f<=10000000;f++); //to display the character slowly
            printf("%c",177);
    }
    if(s!=NULL)
    {
        printf(" %s Successfully...",s);
        loadP(NULL);
    }
}

void screen(char name[100])
{
    printf("\t\t\t\t _______________________________________\n");
    for(int i=1;i<6;i++)
    printf("\t\t\t\t|\t\t\t\t\t|\n");
    printf("\t\t\t\t|\t Welcome Mr.%s ",name);
    for(int i=strlen(name);i<=18;i++)
        printf(" ");
        printf("|");
    for(int i=1;i<7;i++)
    printf("\n\t\t\t\t|\t\t\t\t\t|");
    printf("\n\t\t\t\t|_______________________________________|\n");

}
void clear()
{
    getch();
    system("cls");
}

void Admin()
{
    char log[30],pin[30];
    int choice=-1,info=-1;

    system("COLOR 0B");
    Design("LOGIN-IN SECTION");
    printf("\n\t\t\t\t Enter Your Id here  ");
    scanf("%s",&log);
    if(strcmp(log,"11")!=0 )
    {
        system("cls");
        system("COLOR 4");
        Design(" INVALID ID ");
        clear();
        Login();
    }
    else
    {
        printf("\t\t\t\t___________________________________________________");
        printf("\n\t\t\t\t Enter password ");
        scanf("%s",&pin);
        printf("\t\t\t\t___________________________________________________");
        if(strcmp(pin,password)==0)
        {
        load(20,"LOADING....");
        clear();
        do
        {
            system("COLOR 0B");
            screen("ALI SHERAZI");
            printf("\n\t\t\t\t=========_______________________=========");
            printf("\n\t\t\t\t\t    What you want to do \n ");
            printf("\n\t\t\t\t 1->> Add a new hostelite/Guest \n\t\t\t\t 2->> Remove any hostelite/Guest \n\t\t\t\t 3->> Find Room \n\t\t\t\t 4->> Search \n\t\t\t\t 5->> Display All \n\t\t\t\t");
            printf(" 6->> Contact List \n\t\t\t\t 7->> Send notification \n\t\t\t\t 8->> Message \n\t\t\t\t 9->> View Leave Note \n\t\t\t\t 10->> View Complaint Box \n\t\t\t\t 11->> Unblock ID  \n\t\t\t\t 0->> LogOut ");
            scanf("\n %d",&choice);
            load(20,"LOADING....");
            system("cls");
            if(choice==1)
            {
                New();
            }
            else if(choice==2)
            {
                Remove();
            }
            else if(choice==3)
            {
                Rooms();//issue in resevred and available printing part
            }
            else if(choice==4)
            {
                Search();
            }
            else if(choice==5)
            {
                display();
            }
            else if(choice==6)
            {
                Contact();
            }
            else if(choice==7)
            {
                Notif();
            }
            else if(choice==8)
            {
                Message();
            }
            else if(choice==9)
            {
                ViewLeave();
            }
            else if(choice==10)
            {
                ViewComp();
            }
            else if(choice==11)
            {
                Unblock();
            }
            else if(choice!=0)
            {
                Design(" INVALID Option ");
                clear();
            }
            fflush(stdin);
            }
            while(choice!=0);
            }
            else
            {
                    system("cls");
                    system("COLOR 4");
                    Design(" Invalid Password... Try Again ");
                    clear();
                    Admin();
            }
        }
}
void Address(struct hostelite *p)
{
    if(host==NULL)
        {
            host=holdH=p;
        }
        else
        {
            holdH->next=p;
            holdH=p;
            p->next=NULL;
        }
}
void Unblock()
{
    int id;
    printf("\n Enter id your want to Unblock ");
    scanf("%d",&id);
    p=host;
    while(p!=NULL)
    {
        if(p->id==id)
        {
            if(p->block==3)
            {
                p->block=0;
                Design("ID UNBLOCKED");
            }
            else
                Design("Already UNBLOCKED");
                clear();
                break;
        }
        p=p->next;
    }
}

void data(struct hostelite *p)
{
    char ask[10],fo[10],bed[10];
        fflush(stdin);
        printf("\n\t\t\t\t\t  Food Service include(Yes/No) ");
        scanf("%s",&fo);
        strcpy(p->food,strupr(fo));
        printf("\t\t\t\t\t _____________________________________");
        fflush(stdin);
        printf("\n\t\t\t\t\t  Enter Room(Single || DOUBLE) ");
        scanf("%s",&bed);
        strcpy(p->room,strupr(bed));
        printf("\t\t\t\t\t _____________________________________");
        fflush(stdin);
        printf("\n\t\t\t\t\t  Enter as Guest?(Y/N) ");
        scanf("%s",&ask);
        strcpy(p->gues,strupr(ask));
        printf("\t\t\t\t\t _____________________________________");
        fflush(stdin);
}

void Insertion(int counter,struct hostelite *p,int room,int remove)
{
    int check=1,number=counter;
    while(counter<room)//if any user delete then his room allocate to other by this scenario
    {
        temp=host;
        while(temp!=NULL)
        {
            if(temp->roomNo==counter)
            {
                check=1;
                break;
            }
            else
            {
                check=0;
            }
            temp=temp->next;
        }
        if(check==0)
        {
            p->roomNo=counter;
            reserved++;
            remove=room;
            break;
        }
        counter++;
        }
        if(check==1)
        {
            p->roomNo=room;
            room++;
            remove=room;
            reserved++;
        }
    if(number==1)
    {
        rooms=room;
        removes=remove-1;
    }
    else if(number==50)
    {
        roomc=room;
        removec=remove;
    }
    else if(number==100)
    {
        roomfs=room;
        removefs=remove;
    }

    else if(number==150)
    {
        roomfc=room;
        removefc=remove;
    }
    else if(number==200)
    {
        roomgs=room;
        removegs=remove;
    }
    else if(number==225)
    {
        roomgc=room;
        removegc=remove;
    }
}

int New()
{
//room resverd + available
    int old,number,n=1,oldid,flag=0,flag1=1,counter=1,check=1,r,q,close=1;
    float inc;
    char nam[30],phn[30],pas[30],gen[10],code[20];
    printf("\t\t_______________________________________________");
    printf("\n\t\t How many member you want to add ");
    printf("\n\t\t_______________________________________________\t ");
    scanf("%d",&number);
    system("cls");
    while(n<=number)
    {
        system("COLOR B");
        close=1;
        p=(struct hostelite *)malloc(sizeof(struct hostelite));
        Design("ADD HOSTELITE SECTION");
        printf("\n Is the hostalite is an old member(1-YES 0-NO)? ");
        scanf("%d",&old);
        clear();
        if(old==0)
        {
            Address(p);
            fflush(stdin);
            printf("\n\t\t\t\t\t  Enter Name ");
            gets(nam);
            strcpy(p->name,strupr(nam));//strupr to convert it in upper case
            printf("\t\t\t\t\t _____________________________________");
            fflush(stdin);
            printf("\n\t\t\t\t\t  Enter Phone Number ");
            scanf("%s",&phn);
            strcpy(p->phone,phn);
            printf("\t\t\t\t\t _____________________________________");
            fflush(stdin);
            printf("\n\t\t\t\t\t  Enter Password ");
            gets(code);
            printf("\t\t\t\t\t _____________________________________");
            printf("\n\t\t\t\t\t  Enter age ");
            scanf("%d",&p->age);
            printf("\t\t\t\t\t _____________________________________");
            fflush(stdin);
            printf("\n\t\t\t\t\t  Enter Gender ");
            scanf("%s",&gen);
            strcpy(p->gender,strupr(gen));
            printf("\t\t\t\t\t _____________________________________");
            data(p);
            p->id=idnumb;
            idnumb++;
        }
        else
        {
            strcpy(code,"NULL");
            if(first!=NULL)
            {
            printf("\n Enter id of your old member ");
            scanf("%d",&oldid);
            getch();
            q1=first;
            while(q1!=NULL )
            {
                if(q1->id==oldid)
                {
                    Address(p);
                    if(first->id==oldid)
                    {
                        if(q1->next1!=NULL)//MORE THAN 1 ELEMENT
                            first=q1->next1;
                        else
                            first=tempdel=NULL;
                    }
                    else
                    {
                        if(q1->next1!=NULL)//mid one
                            temp->next1=q1->next1;
                        else//last
                            tempdel=temp;
                    }
                    //sumup with already values
                    strcpy(p->name,q1->name);//strupr to convert it in upper case
                    strcpy(p->phone,q1->phone);
                    strcpy(p->pass,q1->pass);
                    p->age=q1->age;
                    p->id=q1->id;
                    strcpy(p->gender,q1->gender);
                    data(p);
                    flag=1;
                    break;
                }
                temp=q1;
                q1=q1->next1;
            }
            if(flag==0)
            {
                close=0;
                system("color 4");
                Design("Invalid INPUT... Try Again.");
                clear();
            }
        }
        else
        {
            close=0;//not printing next statments
            system("color 4");
            Design("YET,NO DATA DELETED");
            clear();
        }
        }
    if(close==1)
    {

        strcpy(p->notific,"NULL");
        p->fee=Fees;
        if(strcmp(p->food,"YES")==0)
        {
            p->fee=p->fee+500.0;
        }
        if(strcmp(p->room,"DOUBLE")==0)
        {
            p->fee=p->fee+1000.0;
            p->roomNo=rooms;
            reserved=rooms;
            rooms++;
        }
        if(strcmp(p->room,"DOUBLE")==0)
        {
            if((strcmp(p->gues,"Y")==0))
            {
                counter=225;
                Insertion(counter,p,roomgc,removegc);
            }
            else if(strcmp(p->gender,"MALE")==0)//Male room
            {
                counter=50;
                Insertion(counter,p,roomc,removec);
            }
            else//female rooms
            {
                counter=150;
                Insertion(counter,p,roomfc,removefc);
            }
        }
        else//singe bed
        {
            if((strcmp(p->gues,"Y")==0))
            {
                counter=200;
                Insertion(counter,p,roomgs,removegs);
            }
            else if(strcmp(p->gender,"MALE")==0)//Male room
            {
                counter=1;
                Insertion(counter,p,rooms,removes);
            }
            else//female rooms
            {
                counter=100;
                Insertion(counter,p,roomfs,removefs);
            }
        }
        n++;
        load(30,"DATA INSERTINIG WAIT PLEASE...");
        clear();
        printf("\n\n\n\n\t\t\t\t");
        system("COLOR 0A");
        loadP("DATA INSERTED");
        clear();
        p->block=0;
    }
    if(strcmp(code,"NULL")!=0)
    strcpy(p->pass,code);
    clear();
    }
    return 0;
}

void Remove()
{
    //for rooms loop from starting room to current maximum if it have match room number assign room and terminate otherwise increment
    //deleted member delete again case
    //i'll call one function for printing instead of this
    system("COLOR 3");
    Design("DELETE HOSTELITE SECTION");
    struct hostelite *q;
    int Id,n=1,i=1,a=1,flag=0;
    int r,f;
    system("COLOR 6");
    printf("\n\t\t_____________________________________________________");
    printf("\n\t\t Enter id of hostelite you want to delete ");
    scanf("%d",&Id);
    printf("\n\t\t_____________________________________________________\n");
    system("COLOR 4");
        if(Id>=idnumb)
        {
            system("cls");
            Design("DELETE HOSTELITE SECTION");
            Design("No such id exit.... Enter again or Check correct id by display all data ");
            clear();
        }
        else
        {
            p=host;
            q=p;
            while(p!=NULL)
            {
                if(p->id==Id)
                {
                    flag=1;//DATA FOUND
                    break;
                }
                q=p;
                p=p->next;
            }
            //p=host;
                if(flag==1)
                {
                a=0;
                system("cls");
                Design("DELETE HOSTELITE SECTION");
                load(30,"Data is Deleting ...");
                clear();
                a=0;
                Design("DELETE HOSTELITE SECTION");
                system("COLOR 2");
                printf("\n\n\n\n\t\t\t\t");
                loadP("DATA DELETED");
                clear();
                Design("DELETE HOSTELITE SECTION");
                system("COLOR 4");//MAKE SAME FOR SEARCH AND IT
                Represent(" Deleted Person data is");
                Printing(p);
                q1=(struct hostelite *)malloc(sizeof(struct hostelite));
                q1->next1=NULL;
                if(first==NULL)
                {
                    first=tempdel=q1;
                    tempdel->next1=NULL;
                }
                else
                {
                    tempdel->next1=q1;
                    tempdel=q1;
                }
                strcpy(q1->name,p->name);
                strcpy(q1->phone,p->phone);
                q1->id=p->id;
                strcpy(q1->pass,p->pass);
                q1->age=p->age;
                strcpy(q1->gender,p->gender);
            clear();
            if(p->roomNo>=1 && p->roomNo<=49)
            {
                removes=removes-1;
            }
            else if(p->roomNo >=50 && p->roomNo<99)
            {
                removec=removec-1;
            }
            else if(p->roomNo>=100 && p->roomNo<149)
            {
                removefs=removefs-1;
            }
            else if(p->roomNo>=150 && p->roomNo<199)
            {
                removefc=removefc-1;
            }
            else if(p->roomNo>=200 && p->roomNo<224)
            {
                removegs=removegs-1;
            }
            else if(p->roomNo>=225 && p->roomNo<250)
            {
                removegc=removegc-1;
            }
            if(host->id==Id)
            {
                host=p->next;
            }
            else
            {
                if(p->next==NULL)
                {//last element deleted so update holdH
                    holdH=q;
                    q->next=NULL;
                }
                else
                q->next=p->next;
            }
            reserved--;//reserved rooms
        }
           else
            {
                system("cls");
                Design("DELETE HOSTELITE SECTION");
                Design("No such data exit.... ");
                clear();
            }
        }

getch();
}

void check(int a)
{
    int n,roomm=0,counter=1;
    printf("______________________________________________________________________________________________________________________________\n");
    if(a==1)
    {
        roomm=rooms;
        n=49;
    }
    else if(a==2)
    {
        roomm=roomc;
        n=99;
        counter=50;
    }
    else if(a==3)
    {
        roomm=roomfs;
        n=149;
        counter=100;
    }
    else if(a==4)
    {
        roomm=roomfc;
        n=199;
        counter=150;
    }
    else if(a==5)
    {
        roomm=roomgs;
        n=224;
        counter=200;
    }
    else if(a==6)
    {
        roomm=roomgc;
        n=250;
        counter=225;
    }
    int check=1;
    while(counter<roomm)
    {
        temp=host;
        while(temp!=NULL)
        {
            if(temp->roomNo==counter)
            {
                check=1;
                break;
            }
            else
            {
                check=0;
            }
            temp=temp->next;
        }
        if(check==0)
        {
            printf("\t| %d",counter);
        }
        counter++;
        }
        for(int i=roomm;i<=n;i++)
        {
            printf("\t| %d",i);
        }
        printf("\n______________________________________________________________________________________________________________________________\n");
        clear();
}

void Rooms()
{
    system("COLOR 0D");
    Design("ROOM AVAILABILTY SECTION");
    int ask=-1;
    printf("\t\t\t\t _______________________________________________");
    printf("\n\t\t\t\t| Reserved Rooms :\t %d\t\t\t|",reserved);
    printf("\n\t\t\t\t| Total Available Rooms :\t %d\t\t|",total-reserved);
    printf("\n\t\t\t\t|-----------------------------------------------|\n");
    printf("\t\t\t\t|\t\t\t\t\t\t|\n");
    printf("\t\t\t\t| Available Male Single Bed Room :\t %d\t|",50-removes);
    printf("\n\t\t\t\t| Available Male DOUBLE Bed Room :\t %d\t|",100-removec);
    if(removefs==0)
    {
        removefs=100;
    }
    if(removefc==0)
    {
        removefc=150;
    }
    if(removegs==0)
    {
        removegs=200;
    }
    if(removegc==0)
    {
        removegc=225;
    }

    printf("\n\t\t\t\t| Available Female Single Bed Room :\t %d\t|",150-removefs);
    printf("\n\t\t\t\t| Available Female DOUBLE Bed Room :\t %d\t|",200-removefc);
    printf("\n\t\t\t\t| Available Guest Single Bed Room :\t %d\t|",225-removegs);
    printf("\n\t\t\t\t| Available Guest DOUBLE Bed Room :\t %d\t|",250-removegc);
    printf("\n\t\t\t\t|_______________________________________________|\n");
    while(ask!=0)
    {
        system("COLOR 0D");
        printf("\n-----------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t Do you want to print \n\t\t 1-> Male Single Bed Available Rooms \n\t\t 2-> Male DOUBLE Bed Available Rooms \n\t\t 3-> Female Single Bed Available Rooms \n\t\t 4-> Female DOUBLE Bed Available Rooms \n\t\t 5-> Guest Single Bed Available Rooms \n\t\t 6-> Guest DOUBLE Bed Available Rooms \n\t\t 7-> VIEW GRAPHICAL ANALYSIS \n\t\t 0-> Exit  ");
        scanf("%d",&ask);
        system("cls");
        load(20,"LOADING....");
        system("COLOR A");
        if(ask==1)
        {
            if(rooms==50)
            {
                system("COLOR 4"); //room section add
                Design("No Male Single Room Available!!!");
                clear();

            }
            else
            {
                Design(" Male Available Single Rooms Numbers ");
                check(1);
            }
        }
        else if(ask==2)
        {
            if(roomc==100)
            {
                system("COLOR 4");
                Design("No Male DOUBLE Room Available!!!");
                clear();
            }
            else
            {
                Design(" Male Available Double Rooms Numbers are ");
                check(2);
            }
        }
        else if(ask==3)
        {
            if(roomfs==150)
            {
                system("COLOR 4");
                Design("No FeMale Single Room Available!!!");
                clear();

            }
            else
            {
                Design(" FeMale Available Single Rooms Numbers are ");
                check(3);
            }
        }
        else if(ask==4)
        {
            if(roomfc==200)
            {
                system("COLOR 4");
                Design("No FeMale Double Room Available!!!");
                clear();
            }
            else
            {
                Design(" FeMale Available Double Rooms Numbers are ");
                check(4);
            }
        }
        else if(ask==5)
        {
            if(roomgs==225)
            {
                system("COLOR 4");
                Design("No Guest Single Room Available!!!");
                clear();
            }
            else
            {
                Design(" Guest Available Single Rooms Numbers are ");
                check(5);
            }

        }
        else if(ask==6)
        {
            if(roomgc==250)
            {
                system("COLOR 4");
                Design("No Guest Double Room Available!!!");
                clear();
            }
            else
            {
                Design(" Guest Available Double Rooms Numbers are ");
                check(6);
            }

        }
        else if(ask==7)
        {
            Design("ROOM AVAILABILTY SECTION");
            int n=24,n1=50,n2=50,n3=49;
        for(int i=1;i<=11;i++)
        {
            printf("\n ");
            if(i==1)
                printf("MALE SINGLE");
            else if(i==3)
                printf("MALE DOUBLE");
            else if(i==5)
                printf("FEMALE SINGLE");
            else if(i==7)
                printf("FEMALE DOUBLE");
            else if(i==9)
                printf("GUEST SINGLE");
            else if(i==11)
                printf("GUEST Double");
            else
                printf("          ");
            printf(" \t\t|");
            int c,d;//make another same funtionality
            if(i==1)
            {
                load(50-removes,NULL);
            }
            if(i==3)
            {
                load(100-removec,NULL);
            }
            if(i==5)
            {
                load(150-removefs,NULL);
            }
            if(i==7)
            {
                load(200-removefc,NULL);
            }
            if(i==9)
            {
                load(225-removegs,NULL);
            }
            if(i==11)
            {
                load(250-removegc,NULL);
            }
    }
            clear();
        }
        else if(ask!=0)
        {

               Design("ROOM AVAILABILTY SECTION");
                system("COLOR 4");
                Design("INVALID OPTION!!!!  ");
                clear();
        }

    }
}
//CHECK TILLL HERE........
void Printing(struct hostelite *p)
{
    system("COLOR 2");//GREEN
    printf("\t\t\t\t\t _____________________________");
    printf("\n\t\t\t\t\t| Name     |\t %s",p->name);
    printf("\n\t\t\t\t\t| Phone    |\t %s",p->phone);
    printf("\n\t\t\t\t\t| Id       |\t %d",p->id);
    printf("\n\t\t\t\t\t| Room No  |\t %d",p->roomNo);
    printf("\n\t\t\t\t\t| Password |\t %s",p->pass);
    printf("\n\t\t\t\t\t| Age      |\t %d",p->age);
    printf("\n\t\t\t\t\t| Gender   |\t %s",p->gender);
    printf("\n\t\t\t\t\t| Food     |\t %s",p->food);
    printf("\n\t\t\t\t\t| Room     |\t %s",p->room);
    printf("\n\t\t\t\t\t| Fee      |\t %.2f",p->fee);
    printf("\n\t\t\t\t\t -----------------------------\n");
}
void Represent(char s[100])
{
    printf("\t\t\t\t\t ----------------------------");
    printf("\n\t\t\t\t\t~   %s   ~\n",s);
    printf("\t\t\t\t\t ----------------------------\n");
}
void Search()
{
    int Id,flag=0,n=1;
    system("COLOR E");
    Design("SEARCH HOSTALITE SECTION");
    printf("\n Enter Id you want to search ");
    scanf("%d",&Id);
    system("cls");
    load(30," SEARCHING...");
    clear();
    if(Id>=idnumb)
    {
        system("COLOR 4");
        Design("SEARCH HOSTALITE SECTION");
        Design(" INVALID  ID!!!! ");
        clear();
    }
    else
    {
        system("COLOR 2");
        Design("SEARCH HOSTALITE SECTION");
        p=host;
        //possibilty change
        while(p!=NULL)
        {
            if(p->id==Id)
            {
                flag=1;
                break;
            }
            p=p->next;
        }
        if(flag==1)
        {
            Represent("Searched Person data");
            Printing(p);
            printf("\n");
            }
            else
            {
                system("COLOR 4");
                Design(" INVALID  ID!!!! ");
                clear();
            }
    }
    clear();
}
void display()
{
    Represent("DISPLAY ALL RECORD SECTION");
    p=host;
    if(host!=NULL)
    {
        while(p!=NULL)
        {
            Printing(p);
            p=p->next;
        }
    }
    else
    {
        system("COLOR 4");
        Design("SEARCH HOSTALITE SECTION");
        Design(" NO DATA EXIT!!!! ");
    }
    clear();
}

void Contact()
{
        Design("CONTACT LIST");
        for(int i=65;i<=90;i++)
        {
            printf("\t\t\t\t\t%c \n",i);
            printf("\t\t\t\t\t---------------------\n");
            p=host;
            while(p!=NULL)
            {
            if(p->name[0]==i)//first index compare
            {
                printf("\t\t\t\t\t%s ",p->name);
                printf("\t  %s ",p->phone);
                printf("\n");
                printf("\t\t\t\t\t---------------------\n");
            }
            p=p->next;
            }
    }
    clear();
}
 void Notif()
 {
     char text[150];
     int decs;
     system("COLOR E");//LIGHT YELLOW
     fflush(stdin);
     printf("\n\n Do You want to send Notification \n 1-YES 2-EXIT ");
     scanf("%d",&decs);
     if(decs==1)
     {
         fflush(stdin);
         printf(" You can enter your Notification here ");
         gets(text);
         p=host;
         while(p!=NULL)
         {
            strcpy(p->notific,text);
             p=p->next;
         }
        load(30,"NOTIFICATION SENDING ");
        printf("\n\n\n\n\t\t\t\t");
        system("COLOR 0A");
        loadP("NOTIFICATION SEND");
    }
     else if(decs!=2)
     {
         system("COLOR C");
         Design("Invalid input... Back To Main ");
     }
     clear();
 }

void seenoption(int count)
{
    if(count==0)
        printf("||");
    else
        printf("|");
}
void MessageShort(int id, char option)
{
    system("COLOR A");//LIGHT GREEN
    printf(" ------------------------------------------------------------------------");
    s=header;
    while(s!=NULL)
    {
        if(option=='H')
        {
            if(s->sender_id==id && s->reciver_id==11 )//for hostalite
            {
                printf("\n|\t\t\t\t\t\tMe: %s(%d)",s->mes,s->hsnumbers);
                seenoption(s->count);
                for(int i=strlen(s->mes);i<=15;i++)
                printf(" ");
                printf("|");
            }
            if(s->sender_id==11 && s->reciver_id==id)
            {
                printf("\n|%s :Admin",s->mes);
                s->count=0;//for msg seen
                seenoption(s->count);
                for(int i=strlen(s->mes);i<=62;i++)
                printf(" ");
                printf("|");
            }
        }
        else
        {
            if(s->sender_id==11 && s->reciver_id==id)//for admin
            {
                printf("\n|\t\t\t\t\t\tMe: %s(%d)",s->mes,s->numbers);
                seenoption(s->count);
                for(int i=strlen(s->mes);i<=15;i++)
                printf(" ");
                printf("|");
            }
            if(s->sender_id==id && s->reciver_id==11)
            {
                printf("\n|%s :%s",s->mes,temp->name);
                s->count=0;
                seenoption(s->count);
                for(int i=strlen(s->mes);i<=64;i++)
                printf(" ");
                printf("|");
            }
        }
        printf("\n");
        s=s->next;
    }
    printf("\n ------------------------------------------------------------------------");
}
void MessageCommon(struct messages *newnode,int sender, int reciver)
{
    newnode->next=NULL;
    if(header==NULL)
    {
        header=temp1=newnode;
    }
    else
    {
        temp1->next=newnode;
        temp1=newnode;
    }
    newnode->sender_id=sender;
    newnode->reciver_id=reciver;
}
void Message()//counter for message
{
    int id,flag=0,ch=1,incr=0,a=251,store=0,check=0;
    char text[150];
    system("COLOR A");//LIGHT GREEN
    //ask for id then new node that store id and message
    printf("\n Enter id of of person you want to send text ");
    scanf("%d",&id);
    clear();
    p=host;
    while(p!=NULL)
    {
        if(p->id==id)
        {
            temp=p;
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0)
    {
        system("COLOR 4");
        Design("MESSAGE SECTION");
        Design(" INVALID  ID!!!! ");
        clear();
    }
    else
    {
        MessageShort(id,'A');
        printf("\n Do you want to send more Message to %d\n 1-YES \n 2-Delete \n 0-NO ",id);
        scanf("%d",&ch);
        while(ch!=0)
        {
            check=0;
            if(ch==1)
            {
                newnode1=(struct messages *)malloc(sizeof(struct messages));
                MessageCommon(newnode1,11,id);
                newnode1->numbers=deletion;
                deletion++;//id give to msg
                fflush(stdin);
                printf("\n Enter message you want to send ");
                gets(text);
                strcpy(newnode1->mes,text);
                incr++;
                newnode1->count=incr;//seen
                MessageShort(id,"A");
            }
            else if(ch==2)
            {
                if(header==NULL)
                {
                    system("cls");
                    system("COLOR 4");//RED
                    Design("No Message is available for deletion");
                    clear();
                }
                else
                {
                printf("\n Enter message code you want to delete ");
                scanf("%d",&store);
                s=header;
                while(s!=NULL)
                {
                    if(s->sender_id==11)
                    {
                    if(s->numbers==store)
                    {
                        check=1;
                        deletion=s->numbers;
                        if(header->numbers==s->numbers && header->sender_id==11)//for head delete
                        {
                            header=s->next;
                            newnode=header;
                        }
                        else if(temp1->numbers==store)
                        {
                            temp1=n;
                            temp1->next=NULL;
                            newnode=NULL;
                        }
                        else
                        {
                            n->next=s->next;
                            newnode=n->next;
                        }
                        while(newnode!=NULL)
                        {
                            if(newnode->sender_id==11)
                            {
                                newnode->numbers=deletion;
                                deletion++;
                            }
                            newnode=newnode->next;
                        }
                        break;
                    }
                    }
                    n=s;
                    s=s->next;
                    }
                    if(check==0)
                    {
                        clear();
                        system("COLOR 4");//RED
                        Design(" Invalid Message ID");
                    }
                    clear();
                    MessageShort(id,"A");
            }
            }
            printf("\n Do you want to send more Message to %d\n 1-YES \n 2-Delete Specific message \n 0-NO ",id);
            scanf("%d",&ch);
        }
        clear();
    }
}

void ViewLeave()
{
    int ans;
    z=point;
    if(z==NULL)
    {
        system("COLOR 4");//RED
        Design(" No Leave Request Received yet");
    }
    else
    {
        while(z!=NULL)
        {
            system("COLOR D");//LIGHT PURPLE
            printf("\n Leave Note From %d Id :- \n",z->sender);
            printf(" ' %s ' \n",z->note);
            printf("-------------------------------");
            if(z->approve==0)
            {
                printf("\n Press \n 1-Approve this request \n 2-Decline this request \n 3-Ignore ");
                scanf("%d",&ans);
                z->approve=ans;
            }
            z=z->next;
        }
    }

    printf(" \n Press Anything to GO BACK the program \n");
    clear();
}
void ViewComp()
{
    system("COLOR 9");//LIGHT BLUE
    u=head;
    if(u==NULL)
    {
        Design(" Complain Box is empty Currently ");
    }
    else
    {
        while(u!=NULL)
        {
            printf("\n Complain from id: %d is\n '%s' ",u->sender,u->com);
            u=u->nextone;
            printf("\n-----------------------------------------------------------");
        }
    }
    printf("\n Press anything to go back \n ");
    clear();
}

void Hostal()
{
    char pin[30];
    int log,choice=-1,flag=0;
    Design("LOGIN-IN SECTION");
    printf("\n\t\t\t\t Enter your id ");
    scanf("%d",&log);
    p=host;
    while(p!=NULL)
    {
        flag=0;
        if(log==p->id)
        {
            flag=1;
            temp=p;
        if(p->block==3)
        {
            Design("Your ID is Blocked....!");
            clear();
            Login();
        }
            break;
        }
        p=p->next;
    }

        if(flag==0)
        {
            Design("Invalid ID TRY AGAIN....!");
            clear();
            Login();
        }
        else
        {
            printf("\t\t\t\t___________________________________________________");
            flag=0;
            printf("\n\t\t\t\t Enter password ");
            scanf("%s",&pin);
            printf("\t\t\t\t___________________________________________________");
            system("cls");
            load(30,"LOADING...");
            clear();
            if(strcmp(pin,temp->pass)==0)
            {
                do
                {
                    system("COLOR 0B");
                    screen(temp->name);
                    printf("\n\t\t\t\t=========_______________________=========");
                    printf("\n\t\t\t\t\t    What you want to do \n ");
                    printf("\n\t\t\t\t 1->> View Details \n\t\t\t\t 2->> Edit Details \n\t\t\t\t 3->> View Notification \n\t\t\t\t 4->> View Fee \n\t\t\t\t 5->> Send Leave Note \n\t\t\t\t");
                    printf(" 6->> Messages  \n\t\t\t\t 7->> Send Complaint to Admin  \n\t\t\t\t 0->> LogOut ");
                    scanf("\n %d",&choice);
                    system("cls");
                    if(choice==1)
                    {
                        ViewDetail(temp);
                    }
                    else if(choice==2)
                    {
                        EditDetail(temp);

                    }
                    else if(choice==3)
                    {
                        ViewNoti(temp);
                    }
                    else if(choice==4)
                    {
                        Fee(temp);
                    }
                    else if(choice==5)
                    {
                        Leave(temp);
                    }
                    else if(choice==6)
                    {
                        ViewMsg(temp);
                    }
                    else if(choice==7)
                    {
                        comp(temp);
                    }
                    else if(choice!=0)
                    {
                        Design(" Invalid option ");
                    }
                }
                while(choice!=0);
            }
            else
            {
                system("cls");
                system("COLOR 4");
                p->block=p->block+1;
                Design(" Invalid Password... Try Again ");
                clear();
            }
        }
}

void ViewDetail(struct hostelite *val)
{
    Represent("PERSONSAL DETAIL");
    Printing(val);
    clear();
}

void EditDetail(struct hostelite *val)
{
    Represent("CHANGE PERSONSAL DETAIL SECTION");
    int opt=-1,ag;
    char change[50];
    while(opt!=0)
    {
        system("COLOR 6");//YELLOW
        printf("\n\t\t\t\t What you want to change from your personal information ");
        printf("\n\t\t\t\t 1-Name \n\t\t\t\t 2-Phone number \n\t\t\t\t 3-Password \n\t\t\t\t 4-Age \n\t\t\t\t 0-Exit ");
        scanf("%d",&opt);
        if(opt==1)
        {
            fflush(stdin);
            printf("\n\t\t\t\t Enter new Name you want to replace with old one ");
            gets(change);
            strcpy(val->name,change);
            system("cls");
            printf("\n\n\n\n\t\t\t\t");
            system("COLOR 0A");
            loadP("Data update Successfully!! ");
            clear();
        }
        else if(opt==2)
        {
            fflush(stdin);
            printf("\n\t\t\t\t Enter new Phone Number you want to replace with old one ");
            gets(change);
            strcpy(val->phone,change);
            system("cls");
            printf("\n\n\n\n\t\t\t\t");
            system("COLOR 0A");
            loadP("Data update Successfully!! ");
            clear();
        }
        else if(opt==3)
        {
            fflush(stdin);
            printf("\n\t\t\t\t Enter new Password you want to replace with old one ");
            gets(change);
            strcpy(val->pass,change);
            system("cls");
            printf("\n\n\n\n\t\t\t\t");
            system("COLOR 0A");
            loadP("Data update Successfully!! ");
            clear();
        }
        else if(opt==4)
        {
            fflush(stdin);
            printf("\n\t\t\t\t Enter Age you want to replace with old one ");
            scanf("%d",&ag);
            val->age=ag;
            system("cls");
            printf("\n\n\n\n\t\t\t\t");
            system("COLOR 0A");
            loadP("Data update Successfully!! ");
            clear();
        }
        else if(opt!=0)
        {
            system("cls");
            system("COLOR 4");//RED
            Design("Invalid option");
            clear();
        }
        ViewDetail(val);
    }
}

void ViewNoti(struct hostelite *val)
{
    system("COLOR 9");//LIGHT BLUE
    Design("NOTIFICATION SECTION");
    printf("\n\t\t\t\t\t IMPORTANT NOTIFICATION FROM ADMIN \n");
    printf("\t\t\t\t\t------------------------------------------------------\n");
    if(strcmp(val->notific,"NULL")==1)
        printf("\t\t\t\t\t\t\t' %s '",val->notific);
    else
        printf("\t\t\t\t\t\t\t' YET,NO NOTIFICATION RECEIVED '");
    printf("\n\t\t\t\t\t-----------------------------------------------------\n");
    clear();
}

void Fee(struct hostelite *val)
{
    Represent(" Fee Information SECTION");
    printf("\n\n\t\t\t\t\tROOM : %s \t",val->room);
    if(strcmp(val->room,"SINGLE")==0)
    {
        printf("= 1000.0");
    }
    else
    {
        printf("= 2000.0");
    }
    printf("\n\t\t\t\t\tFOOD : %s \t",val->food);
    if(strcmp(val->food,"YES")==0)
    {
        printf("= 500.0");
    }
    else
    {
        printf("= 0.0");
    }
    printf("\n\t\t\t\t\t---------------------------");
    printf("\n\t\t\t\t\t TOTAL FEE  :\t %.2f ",val->fee);
    printf("\n\t\t\t\t\t---------------------------");
    clear();
}

void Leave(struct hostelite *val)
{
    int opt;
    char text[150];
    system("COLOR A");//LIGHT GREEN
    printf(" What you want to do \n 1-Send Leave Note to Admin \n 2-View Approval Notification of Leave ");
    scanf("%d",&opt);
    if(opt==1)
    {
        sample=(struct LeaveN *)malloc(sizeof(struct LeaveN));
        sample->next=NULL;
        fflush(stdin);
        printf("\n Write Your Leave Note to Admin : \t");
        gets(text);
        system("cls");
        if(point==NULL)
        {
            point=start=sample;
        }
        else
        {
            start->next=sample;
            start=sample;
        }
        strcpy(sample->note,text);
        sample->sender=val->id;
        sample->seen=0;
        system("COLOR 0A");
        clear();
        printf("\n\n\n\n\t\t\t\t");
        loadP("Forwarded to Admin");
        clear();
    }
    else if(opt==2)
    {
        if(point!=NULL)
        {
            z=point;
            while(z!=NULL)
            {
                if(z->sender==val->id)
                {
                    printf("\n %s \n ", z->note);
                    if(z->approve==1)
                    {
                        point=point->next;
                        Design("Yahooo!! Your Leave Note is Accepted by Admin! ");
                    }
                    else if(z->approve==2)
                    {
                        point=point->next;
                        Design("Extremely Sorry! Your Leave Note is Rejected By Admin ");
                    }
                    else
                    {
                        Design("NO RESPONSE RECIEVED FROM ADMIN YET ! ");
                    }
                }
                z=z->next;
            }
        }
        else
        {
            system("cls");
            system("COLOR 4");//RED
            Design("NO LEAVE NOTE FORWARDED TO ADMIN  ! ");
        }
    }
    else
    {
        system("cls");
        system("COLOR 4");//RED
        Design("Invalid Option ");
    }
    clear();
}

void ViewMsg(struct hostelite *val)
{
    int opt=1,up=0,store=0,check;
    char text[150];
    MessageShort(val->id,'H');
    while(opt!=0)
    {
        check=0;
        printf("\n 1-Send Message \n 2-Delete \n 0-Exit");
        scanf("%d",&opt);
        if(opt==1)
        {
            newnode=(struct messages *)malloc(sizeof(struct messages));
            MessageCommon(newnode,temp->id,11);
            fflush(stdin);
            printf("\n Enter message you want to sender ");
            gets(text);
            strcpy(newnode->mes,text);
            up++;
            newnode->count=up;
            newnode->hsnumbers=incremental;//id for msg
            incremental++;
            MessageShort(val->id,'H');
        }
        else if(opt==2)
        {
            if(header==NULL)
            {
                Design("\n No Message is available for deletion\n  ");
            }
            else
            {
            printf("\n Enter message code you want to delete ");
            scanf("%d",&store);
            s=header;
        while(s!=NULL)
        {
            if(s->sender_id==val->id)
            {
                if(s->hsnumbers==store)
                {
                    check=1;
                    incremental=s->hsnumbers;
                    printf(" %s(%d) is Deleted \n ",s->mes,s->hsnumbers);
                    if(store==header->hsnumbers)//for first element
                    {
                        header=s->next;
                        newnode=header;
                    }
                    else if(temp1->hsnumbers==store)
                    {
                        temp1=n;
                        temp1->next=NULL;
                        newnode=NULL;
                    }
                    else
                    {
                        n->next=s->next;
                        newnode=n->next;
                    }
                    while(newnode!=NULL)
                    {
                        if(newnode->sender_id==val->id){
                        newnode->hsnumbers=incremental;
                        incremental++;}
                        newnode=newnode->next;
                    }
                    break;
                }
            }
                n=s;
                s=s->next;
                }
                if(check==0)
                {
                    Design("Invalid Message");
                }
            MessageShort(val->id,'H');
        }
        }
    }
    clear();
}

void comp(struct hostelite *val)
{
    char text[150];
    fflush(stdin);
    printf("\n Enter complain you want to send Admin ");
    gets(text);
    clear();
    node=(struct complain *)malloc(sizeof(struct complain));
    node->sender=temp->id;
    strcpy(node->com,text);
    node->nextone=NULL;
    if(head==NULL)
    {
        head=t=node;
    }
    else
    {
        t->nextone=node;
        t=node;
    }
    printf("\n\n\n\n\t\t\t\t");
    system("COLOR 0A");
    loadP("Forwarded to Admin");
    clear();
}

void Login()
{
    int option;
    do
    {
        system("cls");
        system("COLOR E");
        Design("LOGIN SECTION");
        printf("\n\n\t\t\t\t\t____________________________");
        printf("\n\t\t\t\t\t LOGIN AS: \n\t\t\t\t\t   1-Admin \n\t\t\t\t\t   2-hostelite \n\t\t\t\t\t   0-End ");
        scanf("%d",&option);
        load(20,"LOADING...");
        system("COLOR E");
        if(option==1)
        {
            Admin();
        }
        else if(option==2)
        {
            Hostal();
        }
        else if(option!=0)
        {
            system("cls");
            system("COLOR 4");
            Design("Invalid OPTION... Try Again ");
            getch();
        }
    }
    while(option!=0);
}
int main()
{
    Already("ALI","1234","03350439948","MALE","DOUBLE ","YES");
    Already("HAMZA","1234","0335082173","MALE","DOUBLE ","YES");
    Login();
}
