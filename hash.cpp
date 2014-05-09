#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<limits>
using namespace std;
class hash	{
         private:
         static const int tablesize=100;
         struct item	{
             string name;
             int count;
             int position[20];
             item *next;

                 };
         item* HashTable[tablesize];
         public:
         hash();
         int Hash(string key);
         void AddItem(string name,int counter);
         void PrintTable();
         void gotoetxt();
                    
     };

hash::hash()	{
         for(int i=0;i<tablesize;i++)	{
                     HashTable[i]=new item;
                     HashTable[i]->name="empty";
                     HashTable[i]->next=NULL;
                     HashTable[i]->count=0;
                     for(int j=1;j<=20;j++)	{
                         HashTable[i]->position[j]=0;
                                 }
                         }
     }



void hash::AddItem(string name,int counter)	{
         int index=Hash(name);
         int v=0;
         bool foundName;
         item* Ptr=HashTable[index];
         item* n=new item;
         if(HashTable[index]->name=="empty")	{
             HashTable[index]->name=name;
             HashTable[index]->count=1;
             v=1;
             HashTable[index]->position[1]=counter;
                             }

         if(Ptr->name==name && v==0)	{
             foundName=true;
             (HashTable[index]->count)++;
                     for(int j=1;j<=20;j++)	{
                         if(Ptr->position[j]==0)	{
                             Ptr->position[j]=counter;
                             break;
                                     }
                                 }
                         }
                     }

void hash::PrintTable()	{
         int number,pos;
         fstream outfile;
         outfile.open("b.txt",ios::out|ios::app);
         for(int i=0;i<tablesize;i++)	{
             if(HashTable[i]->name!="empty")	{
                 outfile<<(HashTable[i]->name)<<"\t"<<(HashTable[i]->count)<<"\t";
                   for(int j=1;j<=20;j++)	{
                           if((HashTable[i]->position[j])!=0)	{
                         pos=HashTable[i]->position[j];
                               outfile<<pos<<"\t"; }

                                 }
                         outfile<<"\n";
                             }
                         }
         outfile.close();
         }



int hash::Hash(string key)	{
         int hash=0;
         int index;
         for(int i=0;i<key.length();i++)	{
             hash=(hash+(int)key[i])*17;
                         }
         index=hash%tablesize;
         return index;
             }


void hash::gotoetxt()	{
         string y,name;
         int i,count=0,pos[10];
         ifstream myfilei;
string buffer;
                fstream pFile,ifs,sort;
         myfilei.open ("b.txt");
         
                pFile.open("c.txt",ios::out|ios::app);
        
                   
                     while (true)	{
    getline(myfilei, y);
                                   if (myfilei.eof())	{ break;	}
stringstream data(y);
                                    data >> name >> count;
                                
                                for(i=0;i<count;i++)	{
                                          data>>pos[i];
                                 pFile<<pos[i]<<" "<<name<<"\n";

                                           }
                              }
                pFile.close();myfilei.close();
         char k[30],s[35][30],x[30]; //Variables declaration
         int v,C1;
         v=C1=0;
ifs.open ("c.txt",ios::in);
         sort.open ("d.txt",ios::out|ios::app);

         while(!ifs.eof())
     {
     ifs.getline(k,30);
     strcpy(s[C1],k);
    
     if(C1)
     {

     strcpy(s[C1],k);
     for(v=0;v<=C1;v++)
     {
     if(strcmp(s[C1],s[v])<0)
     {
     strcpy(x,s[v]);
     strcpy(s[v],s[C1]);
     strcpy(s[C1],x);
     }
     }
     }
     C1++;
}

for(v=0;v<C1;v++)
{
sort<<s[v]<<"\n";

}


    
     }
  


int main()	{
         hash Hashy;
         int counter=0;
         string name="";
         ifstream myfilei;
         myfilei.open ("a.txt");
         if (myfilei.is_open())	{
             while (!myfilei.eof())	{
                     getline(myfilei, name);
                     if(name!="")	{
                          counter++;
                     Hashy.AddItem(name,counter);
                             }
                          }
                     }

         Hashy.PrintTable();
         Hashy.gotoetxt();
         return 0;
     }

