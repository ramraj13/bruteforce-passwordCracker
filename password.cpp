
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct char_node
{	
	public:
	char data;
	char_node* left;
	char_node(char key)
	{
		data=key;
		left=nullptr;
		
	}
};

struct point_node
{
	public:
	int data;
	point_node* point;
	point_node* track;
	point_node(int counter)
	{
		data=counter;
		point=nullptr;
		track=nullptr;
	}
};

class password
{
	private:
		int length;
		int counter=0;
		
	public:
		password(int len)
		{
			length=len;
		}
		char_node* makelist()
		{
			char_node* start=nullptr;
			char_node* temp=nullptr;
			
			int count=0;
			while(count<length)
			{
				if(temp==nullptr){start=new char_node('a');temp=start;}
				else
				{
					temp->left=new char_node('a');
					temp=temp->left;
					temp->left=nullptr;
				}
				count++;
			}
			
			
			return start;
			
		}
		point_node* make_points(char_node* start)
		{
			point_node* temp=nullptr;
			point_node* stemp=nullptr;
			char_node* temp_count=start;
			
			int count=0;
			while(count< length)
			{
				if(temp==nullptr)
				{
					temp=new point_node(0);
					stemp=temp;
					temp->point=(point_node*)temp_count;
					temp_count=temp_count->left;
				
				}
				else
				{
					
					temp->track=new point_node(0);
					temp=temp->track;
					temp->point=(point_node*)temp_count;
					temp_count=temp_count->left;
					
					
				}
				count++;
			}
			
			return stemp;
		}
		
		void printer(point_node* temp,char_node* start)
		{
			while (1)
			{
				int count=0;
				point_node* stemp=temp;
				temp->data=temp->data + 1;
				char_node* tempo=(char_node*)temp->point;
				tempo->data=(char)((int)tempo->data + 1 );
				if(tempo->data=='{'){tempo->data='a';}
			
			
				while(count < length)
				{
					if(stemp->data==26)
					{
					point_node* point=stemp->track;
					point->data=point->data + 1;
					char_node* tempo=(char_node*)point->point;
					tempo->data=(char)((int)tempo->data + 1);
					if(tempo->data=='{'){tempo->data='a';}
					
					stemp->data=0;
					
					
					}
					stemp=stemp->track;
					count++;
				
				
				}
				string password="";
				for(char_node* print=start;print!=nullptr;print=print->left){ password=password + print->data;}
				
				cout <<"The predicted password of length "<< length <<" is : "<< password;
				
				cout << endl;
			}
			
		}
		
};

int main()
{
	int string_len;
	cout << "Enter the length of the predicted password : " <<endl;
	cin >> string_len;
	password p(string_len);
	
	char_node* start=p.makelist();
	
	point_node* stemp=p.make_points(start);
	p.printer(stemp,start);
}