#include"admin.h"
using namespace std;

admin::admin(void)
{
    id=0;
    unique_id=0;
    total_items=0;
}

void admin::add_stall(void)
{
    system("cls");
    cout<<"\n\n\t\t\t\t\tEnter details : ";
    cout<<"\n\t\t\t\t\tEnter the food stall name : ";
    gets(stall_name);
    cout<<"\n\t\t\t\t\tEnter the food stall ID : ";
    cin>>id;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\n\t\t\t\t\tEnter the mobile no : ";
    gets(phno);
    cout<<"\n\t\t\t\t\tEnter the Email-ID : ";
    gets(email_id);
    cout<<"\n\t\t\t\t\tEnter the stall Unique ID : ";
    cin>>unique_id;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\n\n\t\t\t\t\tFood Options available are : ";
    cout<<"\n\t\t\t\t\t1.South Indian";
    cout<<"\n\t\t\t\t\t2.Continental";
    cout<<"\n\t\t\t\t\t3.Chinese Foods";
    cout<<"\n\t\t\t\t\t4.Thailand Foods";
    cout<<"\n\t\t\t\t\t5.Multiple";
    cout<<"\n\t\t\t\t\tEnter the type number : ";
    int no;
    cin>>no;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(no==1)
    {
        strcpy(food_type,"South Indian");
    }
    else if(no==2)
    {
        strcpy(food_type,"Continental");
    }
    else if(no==3)
    {
        strcpy(food_type,"Chinese Foods");
    }
    else if(no==4)
    {
        strcpy(food_type,"Thailand Foods");
    }
    else if(no==5)
    {
        strcpy(food_type,"Multiple");
    }
    cout<<"\n\t\t\t\t\tEnter the Total Food Items : ";
    cin>>total_items;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string nm;
    int pri;
    for(int i=0;i<total_items;i++)
    {
        cout<<"\n\n\t\t\t\t\tEnter the Food Item "<<i+1<<" Name : ";
        gets(itname[i]);
        cout<<"\n\t\t\t\t\tEnter the Food Item "<<i+1<<" Price : ";
        cin>>itprice[i];
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"\n\t\t\t\t\tEnter your Password : ";
    gets(password);
    cout<<"\n\t\t\t\t\tEnter the Unique KEYWORD to recover the password : ";
    gets(uni_keyword);
}

void admin::show_det(void)
{
    system("cls");
    cout<<"\n\n\t\t\t\t\tPlease note your username : "<<id;
    cout<<"\n\n\t\t\t\t\tRecord Entered Successfully.....";
}

void admin::del_stall(void)
{
    fstream file;
    admin a;
    int tempid,fid;;
    system("cls");
    cout<<"\n\n\t\t\t\t\tEnter the Food Stall ID : ";
    cin>>tempid;
    file.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fstream fs;
    fs.open("TEMPDATA.DAT",ios::out|ios::binary);
    if(!fs)
    {
        cout<<"\n\n\t\t\t\t\terrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror";
    }
    fs.close();
    fs.open("TEMPDATA.DAT",ios::in|ios::out|ios::app|ios::binary);
    fs.seekg(0,ios::beg);
    file.seekg(0,ios::beg);
    file.read(reinterpret_cast<char*>(&a),sizeof(admin));
    bool flag=false;
    while(!file.eof())
    {
        fid=a.retid();
        if(fid==tempid)
        {
            flag=true;
            file.read(reinterpret_cast<char*>(&a),sizeof(admin));
            continue;
        }
        fs.write(reinterpret_cast<char*>(&a),sizeof(admin));
        file.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    if(flag==false)
    {
        cout<<"\n\n\t\t\t\t\tID not found in Records!!!";
    }
    else
    {
        cout<<"\n\n\t\t\t\t\tRecord Deleted Successfully...";
    }
    file.close();
    file.open("FCMSDATA.DAT",ios::out);
    file.seekg(0,ios::beg);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        file.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();
    file.close();
    fs.open("TEMPDATA.DAT",ios::out);
    fs.close();
}

void admin::display_stall(void)
{
    cout<<"\n\n\t\t\t\t\tStall Name : "<<stall_name;
    cout<<"\n\t\t\t\t\tStall ID : "<<id;
    cout<<"\n\t\t\t\t\tStall Phone no : "<<phno;
    cout<<"\n\t\t\t\t\tStall Email-ID : "<<email_id;
    cout<<"\n\t\t\t\t\tTotal number of items : "<<total_items;
    for(int q=0;q<total_items;q++)
    {
        cout<<"\n\t\t\t\t\t\tFood item "<<q+1<<" name : ";
        cout<<itname[q];
        cout<<"\n\t\t\t\t\t\tFood item "<<q+1<<" price : ";
        cout<<itprice[q];
    }
}

int admin::retid(void)
{
    return id;
}

int admin::rettotit(void)
{
    return total_items;
}

int admin::retpri(int i)
{
    return itprice[i];
}

int admin::retuid(void)
{
    return unique_id;
}

const char* admin::retpwd(void)
{
    return password;
}

const char* admin::retuk(void)
{
    return uni_keyword;
}

const char* admin::retname(void)
{
    return stall_name;
}

const char* admin::retph(void)
{
    return phno;
}

const char* admin::rettype(void)
{
    return food_type;
}

const char* admin::retitname(int i)
{
    return itname[i];
}

void admin::incitem(void)
{
    total_items++;
}

const char* admin::retemail(void)
{
    return email_id;
}

void admin::addit(int no)
{
    cout<<"\n\n\t\t\t\t\tEnter food item name : ";
    gets(itname[no-1]);
    cout<<"\n\t\t\t\t\tEnter price : ";
    cin>>itprice[no-1];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void admin::decitem(void)
{
    total_items--;
}

void admin::delit(int no,int tot)
{
    for(int i=no-1;i<tot-1;i++)
    {
        strcpy(itname[i],itname[i+1]);
    }
    cout<<"\n\n\t\t\t\t\tItem Deleted Successfully...";
}

void admin::modprof(int no)
{
    if(no==1)
    {
        cout<<"\n\n\t\t\t\t\tEnter new Email-ID : ";
        gets(email_id);
    }
    if(no==2)
    {
        cout<<"\n\n\t\t\t\t\tEnter new Mobile no : ";
        gets(phno);
    }
    if(no==3)
    {
        cout<<"\n\n\t\t\t\t\tEnter new Food Type : ";
        gets(food_type);
    }
    cout<<"\n\n\t\t\t\t\tRecord Updated Successfully...";
}