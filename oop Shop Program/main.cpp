#include <iostream>
using namespace std;
struct food
{
  int number,id;
  string name_of_salary;
  double price;
  food*next;
};
struct book
{
  int id;string author,book_name;
  double price;
  book*next;
};
class shop
{   public:
    int Number_of_passage;double price;
    void wshop()
    {
     cout<<"Enter The Number of Passage(1->food,2->Books):";
     cin>>Number_of_passage;
    }
   ~shop()
    {cout<<"Good bye....\n";}
};
class Food:protected shop
{
    int number,id;
    string name_of_salary;
    public:
    food*dataenterf()
    {
    food *food1=new food();
    cout<<"Enter The Id of food:";
    cin>>food1->id;
    cout<<"Enter The Name of food:";
    cin>>food1->name_of_salary;
    cout<<"Enter The Number of food:";
    cin>>food1->number;
    cout<<"Enter The price of food:";
    cin>>food1->price;
    cout<<"Done\n";
    food1->next=NULL;
    return food1;
    }
};
class Books:protected shop
{
    protected:
    int id;string author,book_name;
};
class Action:protected Books
{
    public:
    book *dataenterb()
    {
    book*book1=new book();
    cout<<"Enter The Id of book:";
    cin>> book1->id;
    cout<<"Enter The book Name of book:";
    cin>> book1->book_name;
    cout<<"Enter The author of book:";
    cin>> book1->author;
    cout<<"Enter The book price of book:";
    cin>> book1->price;
    cout<<"Done\n";
    book1->next=NULL;
    return book1;
    }
};
food*insertfood(food*listfood,food*newfood)
{
  food*ptr;ptr=NULL;
  ptr=listfood;
  if(listfood==NULL)
  {
    listfood=newfood;
  }
  else
   {
   ptr->next=newfood;
   newfood=ptr;
   }
return listfood;
}
book*insertbook(book*listbook,book*newbook)
{
    book*ptr;ptr=NULL;
    ptr=listbook;
    if(listbook==NULL)
  {
    listbook=newbook;
  }
   else
    {
     ptr->next=newbook;
     newbook=ptr;
    }
return listbook;
}
 void printfoodlist(food *foodlist)
    {
    food*ptr;
    ptr=foodlist;
      while(ptr!=NULL)
        {
            cout << "id of food:" << ptr->id<<"\n";
			cout << "Name of food:" << ptr->name_of_salary<<"\n";
			cout << "Number of food:" << ptr->number<<" of "<< ptr->name_of_salary<<"\n" ;
			cout << "The price of food:" << ptr->price<< " L.E\n";
			cout<<"\n";
			ptr=ptr->next;
        }
    }
     void printbooklist(book *booklist)
    {
    book *ptr;
    ptr=booklist;
      while(ptr!=NULL)
        {
            cout << "id of Book:" << ptr->id<<"\n";
			cout << "Name of Book:" << ptr->book_name<<"\n";
			cout << "Name of author:" << ptr->author<<"\n" ;
			cout << "The price of food:" << ptr->price<< " L.E\n";
			cout<<"\n";
			ptr=ptr->next;
        }
    }
int main()
{
    string ans;
    cout<<"Welcome to Shop....\n";
       food*listfood=NULL;
       book*listbook=NULL;
       ask:  shop s;
       s.wshop();
   if(s.Number_of_passage==2)
    {
     Action a;
     book*newbook=a.dataenterb();
     listbook=insertbook(listbook,newbook);
     cout<<"Do You Want To Show The Salary(Yes,No)";
     cin>>ans;
     if((ans=="yes")||(ans=="Yes"))
        {
            printbooklist(listbook);
            goto ask;
        }
        else
            {
                goto ask;
            }
    }
    else
        {
         Food f;
         food*newfood=f.dataenterf();
         listfood=insertfood(listfood,newfood);
         cout<<"Do You Want To Show The Salary(Yes,No)";
         cin>>ans;
         if((ans=="yes")||(ans=="Yes"))
         {
             printfoodlist(listfood);
              goto ask;
         }
         else
            {
                goto ask;
            }
        }
return 0;
}
