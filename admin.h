#include<iostream>
#include<cstring>
#include<fstream>
#include<string.h>
#include<limits>
#include<iomanip>
#include<ios>
#include<vector>
#include<conio.h>

class admin
{
    public:
        char stall_name[25];
        int id,unique_id,total_items;
        char phno[15];
        char email_id[50];
        char password[20];
        char uni_keyword[25];
        char food_type[20];
        char itname[10][50];
        int itprice[10];
        admin();
        void add_stall(void);
        void show_det(void);
        void del_stall(void);
        void display_stall(void);
        int retid(void);
        int rettotit(void);
        int retpri(int);
        int retuid(void);
        void incitem(void);
        void decitem(void);
        void addit(int);
        void delit(int,int);
        void modprof(int);
        const char* retuk(void);
        const char* retpwd(void);
        const char* retname(void);
        const char* retph(void);
        const char* rettype(void);
        const char* retitname(int);
        const char* retemail(void);
};