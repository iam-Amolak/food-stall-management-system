#include"stall.h"
#include"admin.h"
using namespace std;

int fstall::flogin(int inid)
{
    int rid;
    const char* pwd;
    bool flag=false;
    admin a;
    fstream fs;
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        rid=a.retid();
        if(rid==inid)
        {
            char pd[25];
            pwd=a.retpwd();
            int size=strlen(pwd);
            pd[size]={0};
            cout<<"\n\t\t\t\t\tEnter password : ";
            for(int i=0;i<size;i++)
            {
                pd[i]=getch();
                cout<<"*";
            }
            getch();
            if(strcmp(pwd,pd)==0)
            {
                flag=true;
                break;
            }
        }
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();
    if(flag==true)
    {
        return 0;
    }
    if(flag==false)
    {
        return 1;
    }
}

void fstall::recover(int id)
{
    char unik[25];
    const char* uk;
    int tid;
    cout<<"\n\t\t\t\t\tEnter the Unique Keyword(Provided by Admin) : ";
    gets(unik);
    admin a;
    fstream fs;
    bool flag=false;
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        tid=a.retid();
        if(tid==id)
        {
            uk=a.retuk();
            if(strcmp(uk,unik)==0)
            {
                cout<<"\n\t\t\t\t\tYou are a valid user.";
                cout<<"\n\t\t\t\t\tYour Password : "<<a.retpwd();
                break;
            }
            else
            {
                cout<<"\n\t\t\t\t\tWarning!!!Your Uique Keyword doesn't match with our database.";
                break;
            }
        }
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();
}

void fstall::show_profile(int inid)
{
    int rid;
    admin a;
    fstream fs;
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        rid=a.retid();
        if(rid==inid)
        {
            cout<<"\n\n\t\t\t\t\tName : "<<a.retname();
            cout<<"\n\t\t\t\t\tMobile no : "<<a.retph();
            cout<<"\n\t\t\t\t\tFood Items Type : "<<a.rettype();
            break;
        }
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();
}

void fstall::show_menu(int inid)
{
    int rid;
    admin a;
    fstream fs;
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        rid=a.retid();
        if(rid==inid)
        {
            cout<<"\n\n\t\t\t\t\tNAME : "<<a.retname();
            cout<<"\n\n\t\t\t\t\tFood Items Type : "<<a.rettype();
            cout<<"\n\t\t\t\t\tTotal number of Items : "<<a.rettotit();
            for(int i=0;i<a.rettotit();i++)
            {
                cout<<"\n\t\t\t\t\t\tFood Item "<<i+1<<" : "<<a.retitname(i)<<"\t\tPrice : "<<a.retpri(i);
            }
            break;
        }
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();        
}

void fstall::add_item(int inid)
{
    int rid;
    admin a;
    fstream fs;
    fstream fst;
    cout<<"\n\n\t\t\t\t\tHow many : ";
    int no;
    cin>>no;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fst.open("TEMPDATA.DAT",ios::out|ios::binary);
    fst.close();
    fst.open("TEMPDATA.DAT",ios::in|ios::out|ios::app|ios::binary);
    fst.seekg(0,ios::beg);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        rid=a.retid();
        if(rid==inid)
        {
            for(int i=0;i<no;i++)
            {
                a.incitem();
                a.addit(a.rettotit());
            }
        }
        fst.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();
    fs.open("FCMSDATA.DAT",ios::out);
    fs.seekg(0,ios::beg);
    fst.seekg(0,ios::beg);
    fst.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fst.eof())
    {
        fs.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fst.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fst.close();
    fs.close();
    fst.open("TEMPDATA.DAT",ios::out);
    fst.close();
}

void fstall::del_item(int inid)
{
    int rid;
    admin a;
    fstream fs;
    fstream fst;
    cout<<"\n\n\t\t\t\t\tEnter the no of item you want to delete : ";
    int no;
    cin>>no;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fst.open("TEMPDATA.DAT",ios::out|ios::binary);
    fst.close();
    fst.open("TEMPDATA.DAT",ios::in|ios::out|ios::app|ios::binary);
    fst.seekg(0,ios::beg);
    fs.seekg(0,ios::beg);
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        rid=a.retid();
        if(rid==inid)
        {
            a.delit(no,a.rettotit());
            a.decitem();
        }
        fst.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fs.close();
    fs.open("FCMSDATA.DAT",ios::out);
    fs.seekg(0,ios::beg);
    fst.seekg(0,ios::beg);
    fst.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fst.eof())
    {
        fs.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fst.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fst.close();
    fs.close();
    fst.open("TEMPDATA.DAT",ios::out);
    fst.close();
}

void fstall::modify_prof(int uniid)
{
    int uid;
    admin a;
    fstream fs;
    fstream fst;
    fs.open("FCMSDATA.DAT",ios::in|ios::app|ios::out|ios::binary);
    fst.open("TEMPDATA.DAT",ios::out|ios::binary);
    fst.close();
    fst.open("TEMPDATA.DAT",ios::in|ios::out|ios::app|ios::binary);
    fst.seekg(0,ios::beg);
    fs.seekg(0,ios::beg);
    bool flag=false;
    fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fs.eof())
    {
        uid=a.retuid();
        if(uid==uniid)
        {
            flag=true;
            cout<<"\n\t\t\t\t\tYour profile details are : ";
            cout<<"\n\t\t\t\t\t1.Fodd Stall Email-ID : "<<a.retemail();
            cout<<"\n\t\t\t\t\t2.Food Stall Mobile no : "<<a.retph();
            cout<<"\n\t\t\t\t\t3.Fodd Stall Food Type : "<<a.rettype();
            cout<<"\n\n\t\t\t\t\tEnter the detail number to be modified : ";
            int no;
            cin>>no;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            a.modprof(no);
        }
        fst.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fs.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    if(flag==false)
    {
        cout<<"\n\n\t\t\t\t\tWARNING !!! You entered Wrong Unique ID!!";
    }
    fs.close();
    fs.open("FCMSDATA.DAT",ios::out);
    fs.seekg(0,ios::beg);
    fst.seekg(0,ios::beg);
    fst.read(reinterpret_cast<char*>(&a),sizeof(admin));
    while(!fst.eof())
    {
        fs.write(reinterpret_cast<char*>(&a),sizeof(admin));
        fst.read(reinterpret_cast<char*>(&a),sizeof(admin));
    }
    fst.close();
    fs.close();
    fst.open("TEMPDATA.DAT",ios::out);
    fst.close();
}