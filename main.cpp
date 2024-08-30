#include"admin.h"
#include"stall.h"
using namespace std;

int login(void);

int main()
{
    admin a;
    fstall s;
    fstream file;
    file.open("FCMSDATA.DAT",ios::out|ios::app|ios::binary);
    if(!file)
    {
        cout<<"errorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror";
    }
    while(1)
    {
        int ch;
        system("cls");
        cout<<"\n\n\t\t\t\t\tWELCOME TO FOOD COURT MANAGEMENT SYSTEM";
        cout<<"\n\n\t\t\t\t\t1.ADMIN Portal";
        cout<<"\n\t\t\t\t\t2.FOOD COURT Portal";
        cout<<"\n\t\t\t\t\t3.GUEST Portal";
        cout<<"\n\t\t\t\t\t4.EXIT";
        cout<<"\n\n\t\t\t\t\tEnter your choice : ";
        cin>>ch;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        file.close();
        if(ch==1)
        {
            system("cls");
            int alog=login();
            if(alog==0)
            {
                system("cls");
                while(1)
                {
                    system("cls");
                    cout<<"\n\n\t\t\t\t\tWelcome to ADMIN Portal";
                    cout<<"\n\t\t\t\t\t1.Add a food stall";
                    cout<<"\n\t\t\t\t\t2.Delete a food stall";
                    cout<<"\n\t\t\t\t\t3.View all records";
                    cout<<"\n\t\t\t\t\t4.Back to Main Menu";
                    cout<<"\n\t\t\t\t\t5.EXIT";
                    cout<<"\n\t\t\t\t\t\tEnter your choice : ";
                    cin>>ch;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(ch==1)
                    {
                        file.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
                        a.add_stall();
                        file.write(reinterpret_cast<char*>(&a),sizeof(admin));
                        a.show_det();
                        file.close();
                        cout<<"\n\n\t\t\t\t\tPress ENTER...";
                        getch();
                    }
                    if(ch==2)
                    {
                        a.del_stall();
                        getch();   
                    }
                    if(ch==3)
                    {
                        file.open("FCMSDATA.DAT",ios::in|ios::binary);
                        file.seekg(0,ios::beg);
                        file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                        while(!file.eof())
                        {
                            a.display_stall();
                            file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                        }
                        file.close();
                        cout<<"\n\n\t\t\t\t\tPress ENTER...";
                        getch();
                    }
                    if(ch==4)
                    {
                        goto mainmenu;
                    }
                    if(ch==5)
                    {
                        exit(0);
                    }
                }
                mainmenu:continue;
            }
            if(alog==1)
            {
                cout<<"\n\n\t\t\t\t\tINCORRECT Username..";
                continue;
            }
        }
        if(ch==2)
        {
            int inid;
            system("cls");
            cout<<"\n\n\n\t\t\t\t\tWelcome to FOOD STALL Portal";
            cout<<"\n\n\t\t\t\t\tEnter your ID : ";
            cin>>inid;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            int slog=s.flogin(inid);
            if(slog==0)
            {
                while(1)
                {
                    system("cls");
                    cout<<"\n\n\t\t\t\t\tWelcome to FOOD STALL Portal";
                    cout<<"\n\t\t\t\t\t\t\t\t\tUser ID : "<<inid;
                    cout<<"\n\n\t\t\t\t\t1.View your profile";
                    cout<<"\n\t\t\t\t\t2.Know your Menu";
                    cout<<"\n\t\t\t\t\t3.Add Food Items";
                    cout<<"\n\t\t\t\t\t4.Delete a Food Item";
                    cout<<"\n\t\t\t\t\t5.Modify your profile";
                    cout<<"\n\t\t\t\t\t6.Back to Main Menu";
                    cout<<"\n\t\t\t\t\t7.EXIT";
                    cout<<"\n\t\t\t\t\t\tEnter your choice : ";
                    cin>>ch;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(ch==1)
                    {
                        s.show_profile(inid);
                        cout<<"\n\n\t\t\t\t\tPress ENTER to Continue..";
                        getch();
                    }
                    if(ch==2)
                    {
                        s.show_menu(inid);
                        cout<<"\n\n\t\t\t\t\tPress ENTER to Continue..";
                        getch();
                    }
                    if(ch==3)
                    {
                        s.add_item(inid);
                        cout<<"\n\n\t\t\t\t\tPress ENTER to Continue..";
                        getch();
                    }
                    if(ch==4)
                    {
                        s.show_menu(inid);
                        s.del_item(inid);
                        cout<<"\n\n\t\t\t\t\tPress ENTER to Continue..";
                        getch();
                    }
                    if(ch==5)
                    {
                        cout<<"\n\n\t\t\t\t\tEnter Unique ID of Stall : ";
                        int uid;
                        cin>>uid;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        s.modify_prof(uid);
                        cout<<"\n\n\t\t\t\t\tPress ENTER to Continue..";
                        getch();
                    }
                    if(ch==6)
                    {
                        goto MainMenu;
                    }
                    if(ch==7)
                    {
                        exit(0);
                    }
                }
                MainMenu:continue;
            }
            if(slog==1)
            {
                system("cls");
                cout<<"\n\n\t\t\t\t\t\t\tYour LogIn credentials are incorrect!!";
                cout<<"\n\t\t\t\t\tThe Username is your Stall ID";
                cout<<"\n\t\t\t\t\tThe Password is Case-Sensitive!!";
                cout<<"\n\t\t\t\t\tPress 1 to Recover Password & 2 to Re-Attempt LogIn : ";
                cin>>ch;
                int inid;
                if(ch==1)
                {
                    cout<<"\n\n\t\t\t\t\tEnter your ID : ";
                    cin>>inid;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    s.recover(inid);
                    cout<<"\n\n\t\t\t\t\tPress ENTER to LogIn again...";
                    getch();
                    continue;
                }
                if(ch==2)
                {
                    continue;
                }
            }
        }
        if(ch==3)
        {
            while(1)
            {
                system("cls");
                cout<<"\n\n\t\t\t\t\t\tWelcome to Customer Panel";
                cout<<"\n\t\t\t\t\t\t\t\t\t\t\tGuest Login";
                cout<<"\n\n\t\t\t\t\t1.View all Food Stalls";
                cout<<"\n\t\t\t\t\t2.Search a Stall by Unique ID";
                cout<<"\n\t\t\t\t\t3.Search a Food Stall by Food Type";
                cout<<"\n\t\t\t\t\t4.Back to Main Menu";
                cout<<"\n\t\t\t\t\t5.EXIT";
                cout<<"\n\t\t\t\t\t\tEnter your Choice : ";
                cin>>ch;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if(ch==1)
                {
                    file.open("FCMSDATA.DAT",ios::in|ios::binary);
                    file.seekg(0,ios::beg);
                    file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                    while(!file.eof())
                    {
                        a.display_stall();
                        file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                    }
                    file.close();
                    cout<<"\n\n\t\t\t\t\tPress ENTER to continue...";
                    getch();
                }   
                if(ch==2)
                {
                    cout<<"\n\n\t\t\t\t\tEnter Unique ID of Stall : ";
                    int unid;
                    cin>>unid;
                    int uiid;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    file.open("FCMSDATA.DAT",ios::in|ios::binary);
                    file.seekg(0,ios::beg);
                    bool flag=false;
                    file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                    while(!file.eof())
                    {
                        uiid=a.retuid();
                        if(uiid==unid)
                        {
                            flag=true;
                            a.display_stall();
                            break;
                        }
                        file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                    }
                    if(flag==false)
                    {
                        cout<<"\n\n\t\t\t\t\tYou entered WRONG Unique ID ! ! !";
                    }
                    file.close();
                    cout<<"\n\n\t\t\t\t\tPress ENTER to continue...";
                    getch();
                }
                if(ch==3)
                {
                    cout<<"\n\n\t\t\t\t\tFood Options available are : ";
                    cout<<"\n\t\t\t\t\t1.South Indian";
                    cout<<"\n\t\t\t\t\t2.Continental";
                    cout<<"\n\t\t\t\t\t3.Chinese Foods";
                    cout<<"\n\t\t\t\t\t4.Thailand Foods";
                    cout<<"\n\t\t\t\t\t5.Multiple";
                    cout<<"\n\n\t\t\t\t\tEnter Food Type number you want : ";
                    int no;
                    cin>>no;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    char type[25];
                    if(no==1)
                    {
                        strcpy(type,"South Indian");
                    }
                    else if(no==2)
                    {
                        strcpy(type,"Continental");
                    }
                    else if(no==3)
                    {
                        strcpy(type,"Chinese Foods");
                    }
                    else if(no==4)
                    {
                        strcpy(type,"Thailand Foods");
                    }
                    else if(no==5)
                    {
                        strcpy(type,"Multiple");
                    }
                    else
                    {
                        strcpy(type,"none");
                    }
                    const char* retty;
                    file.open("FCMSDATA.DAT",ios::in|ios::binary);
                    file.seekg(0,ios::beg);
                    bool flag=false;
                    file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                    while(!file.eof())
                    {
                        retty=a.rettype();
                        if(strcmp(retty,type)==0)
                        {
                            flag=true;
                            a.display_stall();
                            file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                            continue;
                        }
                        file.read(reinterpret_cast<char*>(&a),sizeof(admin));
                    }
                    if(flag==false)
                    {
                        cout<<"\n\n\t\t\t\t\tYou entered WRONG choice ! ! !";
                    }
                    file.close();
                    cout<<"\n\n\t\t\t\t\tPress ENTER to continue...";
                    getch();
                }
                if(ch==4)
                {
                    goto main_menu;
                }
                if(ch==5)
                {
                    exit(0);
                }
            }
            main_menu:continue;
        }
        if(ch==4)
        {
            exit(0);
        }
    }
    getch();
    return 0;
}

int login(void)
{
    char user[20];
    char pass[20];
    cout<<"\n\n\n\t\t\t\t\tWelcome to ADMIN Portal";
    cout<<"\n\n\t\t\t\t\tEnter username : ";
    cin>>user;
    cout<<"\t\t\t\t\tEnter password : ";
    int z;
    pass[5]={0};
    for(z=0;z<5;z++)
    {
        pass[z]=getch();
        cout<<"*";
    }
    getch();
    if(strcmp(user,"admin")==0&&strcmp(pass,"12345")==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
} 