#include <iostream>
#include <string.h>

using namespace std;

class Object
{
 public:
   virtual void print()
   {
   		void *a= this;
   		cout<<a;
   }
   virtual int equals (Object* obj)
   {
  		if(this==obj)
   			return 1;
   		return 0;
   }
 	friend int operator == ( Object& obj1, Object& obj2)
 	{
 		return obj1.equals(&obj2);
 	}
};


class String: public Object
{
	private:
		char* a;
	public:
		String(char * b)
		{
			a=new char;
			strcpy(a,b);
		}
		void print()
   	    {
   			cout<<a;
   		}
   int equals (String* obj)
   {
  		if(strcmp(a,obj->a)==0)
   			return 1;
   		return 0;
   }

   friend char* operator + ( String& ob1, String& ob2)
   {
   		char *sir= new char [strlen(ob1.a)+strlen(ob2.a)+1];
   		strcpy(sir,"");
   		strcat(sir,ob1.a);
   		strcat(sir,ob2.a);
   		return sir;
   }
};


class Int: public Object
{
private:
    int x;
public:
    Int(int a)
    {
        x=a;
    }
    void print()
    {
        cout<<x<< " ";
    }
    int equals (Object* obj)
    {
        Int* p=(Int*)obj;
        if(x==p->x)
            return 1;
        return 0;
    }

};

class Vector
{
	private:
		Object** v;
		int n_max,n;
	public:
		Vector (int Size)
		{
		    v=new Object* [Size];
		    n_max=Size;
		    n=0;
		}
		void add(Object& s)
		{
		    v[n++]=&s;
		}

		int contains(Object& c)
		{
		    for(int i=0;i<n;i++)
                if(v[i]->equals(&c))
                    return 1;
            return 0;
		}
		void print()
		{
		    for(int i=0;i<n;i++)
            {
                v[i]->print();
                cout<<",";
            }
            cout<<endl;
		}
		Object* &operator [] (int i)
        {
            return v[i];
        }
};

int main(void)
{
	Vector V(8);
	int n=10;
	char s[100];
	for(int i=0;i<4;i++)
    {
        cout<<"s=";
        cin>>s;
        String* c = new String(s);
        V.add(*c);
    }
    //a.print();
    for(int i=0;i<8;i++)
        {
            V[i]->print();
            cout<<endl;
        }
	return 0;

}
