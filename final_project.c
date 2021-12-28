//Bismillah.
#include<stdio.h>
#include<curses.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Boishakhi Akhter;

// some global variables;
int ok;
int i,flag=0;
int x,y;
FILE *ek,*ps,*it,*item;


struct password{// for admin password setup;
    char name[20];
    char pass[20];
}admin;

typedef struct admin_interface{

    char uid[50];
    char food_name[50];
    float price;
    struct admin_interface *next;

}aif;

aif *head_a=NULL, *pt=NULL;

// list of all the functions;
//beautify function;
void wellcome_screen();
void title_screen();
void title_screen2();
void title_screen3();
void login();

//core function;
void login_screen();
void u_or_a();
void set_admin();
void m_m();
void ex_it();
void admin_if();
void user_if();
void write_to_file();

//admin function;
void add_item();
void delete_item();
void view_item();
void order_menu();
void total_sale();

//user function;
void place_order();
void view_order();
void delete_ifo();
void display_order();
void user_order_menu();
void read_user_item();
void bill();



void wellcome_screen(){

    //✿

    //system("clear");

    printf("\n");
    printf("\t\t\t\t\t\t\t\t✿✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿✿\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t✿                           ✿\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t✿     Welcome to Hotel de   ✿\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t✿            Doro           ✿\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t✿                           ✿\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t✿                           ✿\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t✿✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿✿\t\t\t\t\t\t\t\t\n");
    getchar_unlocked();
    system("clear");

}

void title_screen(){

    printf("\n");
    printf("\t\t\t\t\t\t\t          =----------------------=  \t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t               Hotel De DORO  \t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t          =----------------------=  \t\t\t\t\t\t\t\n\n");
    printf("\t\t\t\t\t\t\t   ==>Please Enter Your User Name & Passwprd<==  \t\t\t\t\t\t\t\n");

}

void title_screen2(){

    printf("\n");
    printf("\t\t\t\t\t\t\t           =----------------------=  \t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t                Hotel De DORO  \t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\t           =----------------------=  \t\t\t\t\t\t\t\n\n");

}


void login(){
    printf("\t\t\t\t\t\t\t\t login successful\n\n");
}



void u_or_a(){// admin or user ?

    char t,m;
    int i;
    

    title_screen2();
    printf("Press A for admin or press U for user:\n");
    scanf("%c",&t);


    if(t=='A' || t=='a'){// if admin:

        printf("Press L for Login S for Sign up:");
        getc_unlocked(stdin);
        scanf("%c",&m);


        if(m=='S' || m=='s'){// sign up or login? :sign up.
        ps=fopen("pass.txt","r+");
            if(ps==NULL){
                set_admin();  //For creating admin;
            }
            else{
                system("clear");
            printf("\n\n\n\n\n\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\t\t\t\t\t\t\t ...!!..An admin already exist: No more can be added..!!...\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n\n\n\n\n\n");
            getc_unlocked(stdin);

            }
            fclose(ps);
            getc_unlocked(stdin);
            system("clear");
            u_or_a();
        }
        
        else if(m=='L'|| m=='l'){// login:
        login_screen();
        }else{
            printf("wrong selection!");
            u_or_a();
        }
    }

    else if(t=='U' || t=='u'){
        user_if();
    }


}
void login_screen(){ // cheaking admin's user name && password;

    system("clear");
    title_screen2();
    int x=0;
    char user_name[20];
    char password[20];

    ps=fopen("pass.txt","r+");

    fscanf(ps,"%s %s", admin.name, admin.pass);
    do{
        printf("\t\t\t\t\t\t\t    Please Enter Your User Name And Password\n");
        printf("\t\t\t\t\t\t\t\t\tUser Name:");
        scanf("%s",user_name);
        printf("\t\t\t\t\t\t\t\t\tPassword:");
        scanf("%s",password);
        

        if(strcmp(user_name,admin.name)==0 && strcmp(password,admin.pass)==0){

            system("clear");

            title_screen2();

            admin_if();
            return;
        }

        else{
            printf("\n\t\t\t\t\t\t      !!..Wrong user name or password..!!\n");
            printf("\t\t\t\t\t\t\t    ==> please try again <==\n");
            x++;
        }
    }
    
    while(x<=2);
    fclose(ps);
    system("clear");

        if(x>=2){
            printf("\n\n\n\n\n\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\t\t\t\t\t\t\t ...!!..You Have Crossed Your Attempt Limit..!!...\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n\n\n\n\n\n");
            getchar_unlocked();
            //e_xit();
        }
}


void set_admin(){// for new admin;

    ps=fopen("pass.txt","ab+");

    printf("welcome sir");
    printf("Give ur user name sir:");
    scanf("%s",admin.name);
    printf("give ur password sir");
    scanf("%s",admin.pass);
    fprintf(ps,"%s %s",admin.name, admin.pass);

    fclose(ps);
}

//=========================================================================================//
// ahsan Habib;

void admin_if(){

    A:
    printf("\t\t\t\t\t\t\t1. Add new items in the order menu\n");
    printf("\t\t\t\t\t\t\t2. Delete items from the order menu\n");
    printf("\t\t\t\t\t\t\t3. View total sales\n");
    printf("\t\t\t\t\t\t\t4. Display order menu\n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
    

    int a;
    scanf("%d",&a);
    getchar_unlocked();
    system("clear");
    switch(a){
        case 1:
        add_item();
        break;

        case 2:
        delete_item();
        break;

        case 3:
        total_sale();
        break;

        case 4:
        order_menu();
        break;

        case 5:
        u_or_a();
        break;

        default:
            printf("Wrong selection");
            getc_unlocked(stdin);
            goto A;
        
    }

}



void add_item(){// admin adding food items; case 1:

    char k;
    aif a, *node;
    //getc_unlocked(stdin);
    printf("Unique id?"); 
    scanf("%[^\n]",a.uid);
    getc_unlocked(stdin);
    printf("Food Name:");
    scanf("%[^\n]",a.food_name);
    printf("price:");
    scanf("%f",&a.price);

    node = (aif*)malloc(sizeof(aif));
    strcpy(node->uid,a.uid);
    strcpy(node->food_name,a.food_name);
    node->price=a.price;
    node->next=NULL;
    head_a=node;

    write_to_file();
    admin_if();
}

void write_to_file(){//writing admin's inserted item to file;
    FILE *item=fopen("items.txt","a");

    for(pt=head_a; pt; pt=pt->next){
        fprintf(item, "%s %s %.2f \n", pt->uid, pt->food_name, pt->price);
    }
    fclose(item);
}

void delete_item(){//admin deleting selected item; case :2
    
    system("clear");
    title_screen2();

    int found=0;int s;float price;
    char food_name[30], uid[30],u[30];
    FILE *ft;


    ft=fopen("restu_temp.txt","w+");
    item=fopen("items.txt","r");
    printf("\t\t\t\t\t\t\t\t ...!!..Delete Item Record..!!...\n");
    printf("Enter Item's Unique Number:");
    fflush(stdin);
    scanf("%s",u);
    while(fscanf(item,"%s %s %f \n", uid, food_name, &price)!=EOF){
        if(strcmp(uid,u)!=0){

            fprintf(ft, "%s %s %.2f \n", uid, food_name, price);

        }else{
            printf("%s %s %.2f \n", uid, food_name, price);
            found=1;
        }
    }
    if(found==0){
            printf("Item not found ^_^\n");
            getchar_unlocked();
            admin_if();
        }else{//found==1
        fclose(ft);
        fclose(item);
        remove("items.txt");
        rename("restu_temp.txt","items.txt");
        printf("Item deleted\n");
        getchar_unlocked();
        admin_if();
    }
}



void total_sale(){// admin cheaking totak sales; case 3:
    int s,q;
    float price;
    char food_name[30], uid[30];

    FILE* uitem;
    uitem=fopen("user_item.txt","r");

            system("clear");
            x=4,y=60;
            printf("\033[%d;%dH Unique Id\n",x,y);
            x=4,y=80;
            printf("\033[%d;%dH Item Name\n",x,y);
            x=4,y=100;
            printf("\033[%d;%dH Price\n",x,y);



    printf("\t\t\t\t\t\t=====================================================================\n");
    int r=7;
    while(fscanf(uitem,"%s %s %f  \n", uid, food_name, &price)!=EOF)
    {
    
 
            y=62;
            printf("\033[%d;%dH %s",r,y,uid);
            y=81;
            printf("\033[%d;%dH %s",r,y,food_name);
            y=100;
            printf("\033[%d;%dH %.2f",r,y,price);
            r++;
    }
    printf("\n");
    fclose(uitem);
    getchar_unlocked();
    admin_if();

}


void order_menu(){// viewing order menu; case 4:

    title_screen2();
    int s;
    float price;
    char food_name[30], uid[30];

    FILE *item;
    item=fopen("items.txt","r");

            system("clear");
            x=4,y=60;
            printf("\033[%d;%dH Unique Id\n",x,y);
            x=4,y=80;
            printf("\033[%d;%dH Item Name\n",x,y);
            x=4,y=100;
            printf("\033[%d;%dH Price\n",x,y);



    printf("\t\t\t\t\t\t=====================================================================\n");
    int r=7;
    while(fscanf(item,"%s %s %f \n", uid, food_name, &price)!=EOF)
    {
    
 
            y=62;
            printf("\033[%d;%dH %s",r,y,uid);
            y=81;
            printf("\033[%d;%dH %s",r,y,food_name);
            y=100;
            printf("\033[%d;%dH %.2f",r,y,price);
            r++;
    }
    printf("\n");
    fclose(item);
    getchar_unlocked();
    system("clear");
    admin_if();
}


//================================================================================================
// abdulla al masud;


void user_if(){

    A:
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from order\n");
    printf("\t\t\t\t\t\t\t4. See Your Bill \n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
    

    int a;
    scanf("%d",&a);
    getchar_unlocked();
    system("clear");
    switch(a){
        case 1:
        user_order_menu();
        break;

        case 2:
        read_user_item();
        break;

        case 3:
        delete_ifo();
        break;

        case 4:
        bill();
        break;

        case 5:
        u_or_a();
        break;

        default:
            printf("Wrong selection");
            getc_unlocked(stdin);
            goto A;
        
    }

}

void user_order_menu(){// User placing order case 1:

    title_screen2();
    int s;
    float price;
    char food_name[30], uid[30];

    FILE*item;
    item=fopen("items.txt","r");

            system("clear");
            x=4,y=60;
            printf("\033[%d;%dH Unique Id\n",x,y);
            x=4,y=80;
            printf("\033[%d;%dH Item Name\n",x,y);
            x=4,y=100;
            printf("\033[%d;%dH Price\n",x,y);

    printf("\t\t\t\t\t\t=====================================================================\n");
    int r=7;
    while(fscanf(item,"%s %s %f \n", uid, food_name, &price)!=EOF)
    {
            y=62;
            printf("\033[%d;%dH %s",r,y,uid);
            y=81;
            printf("\033[%d;%dH %s",r,y,food_name);
            y=100;
            printf("\033[%d;%dH %.2f",r,y,price);
            r++;
    }
    printf("\n");
    fclose(item);
    //getchar_unlocked();
    place_order();
}

void place_order(){// User placing order case 1:

    char u[50],uid[50], food_name[50]; float price; int flag=0;
    XD:
    printf("Chose your order By unique number: ");

    FILE *uitem;
    uitem=fopen("user_item.txt","a");
    item=fopen("items.txt","r");

    scanf("%s",u);
    while(fscanf(item,"%s %s %f \n", uid, food_name, &price)!=EOF){
        if(strcmp(uid,u)==0){

            fprintf(uitem, "%s %s %.2f\n", uid, food_name, price);
            flag=1;
        }
    }fclose(uitem); fclose(item);
    if(flag!=1){
        printf("Sorry..! Item does not exist!");
        goto XD;
    }else{
        getc_unlocked(stdin);
    printf("Do you Want to buy more?");
    char x;
    scanf("%c",&x);
    if(x=='Y' || x=='y'){
        goto XD;
    }else{
        read_user_item();
    }
    }
}

void read_user_item(){// confirming after order; case 1/2:
    int s;
    float price;
    char food_name[30], uid[30];

    FILE* uitem;
    uitem=fopen("user_item.txt","r");

            system("clear");
            x=4,y=60;
            printf("\033[%d;%dH Unique Id\n",x,y);
            x=4,y=80;
            printf("\033[%d;%dH Item Name\n",x,y);
            x=4,y=100;
            printf("\033[%d;%dH Price\n",x,y);


    printf("\t\t\t\t\t\t=====================================================================\n");
    int r=7;
    while(fscanf(uitem,"%s %s %f \n", uid, food_name, &price)!=EOF)
    {
    
 
            y=62;
            printf("\033[%d;%dH %s",r,y,uid);
            y=81;
            printf("\033[%d;%dH %s",r,y,food_name);
            y=100;
            printf("\033[%d;%dH %.2f",r,y,price);
            r++;
    }
    printf("\n");
    fclose(uitem);
    getchar_unlocked();
    bill();
    user_if();
    //place_order();
}


void bill(){
    int s;
    float price,bill=0;
    char food_name[30], uid[30];

    FILE* uitem;
    uitem=fopen("user_item.txt","r");

    while(fscanf(uitem,"%s %s %f \n", uid, food_name, &price)!=EOF)
    {
    bill=bill+price;
    }
    printf("\n");
    fclose(uitem);
    printf("Your Total Bill = %.2f Taka Only.\n",bill);
    printf("Thank You for Visiting us");
    getchar_unlocked();
    user_if();
    //place_order();
}



void delete_ifo(){// user deleting item after cheaking; case 3:
    
    system("clear");
    title_screen2();

    int found=0;
    int s;
    float price;
    char food_name[30], uid[30],u[30];
    FILE *uft, *uitem;


    uft=fopen("urestu_temp.txt","w+");
    uitem=fopen("user_item.txt","r");
    printf("\t\t\t\t\t\t\t\t ...!!..Delete Item Record..!!...\n");
    printf("Enter Item's Unique Number:");
    fflush(stdin);
    scanf("%s",u);
    while(fscanf(uitem,"%s %s %f \n", uid, food_name, &price)!=EOF){
        if(strcmp(uid,u)!=0){

            fprintf(uft, "%s %s %.2f\n", uid, food_name, price);

        }else{
            printf("%s %s %f\n", uid, food_name, price);
            found=1;
        }
    }
    if(found==0){
            printf("result not found");
            getchar_unlocked();
            user_if();
        }else{//found==1
        fclose(uft);
        fclose(uitem);
        remove("user_item.txt");
        rename("urestu_temp.txt","user_item.txt");
        printf("Item deleted\n");
        getchar_unlocked();
        user_if();
    }
}


int main()
{

    wellcome_screen();
    u_or_a();

    return 0;
}
