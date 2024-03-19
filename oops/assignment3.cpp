#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_RECORDS=10;

class PersonalDetails
{
	public:
		string name;
		string dob;
		string blood;
		
	PersonalDetails(const string& n,const string& d,const string& b):
		name(n),dob(d),blood(b){}
};
class Physical
{
	public:
		float height;
		float weight;
	
	Physical(float h,float w):
		height(h),weight(w){}
};
class Contact
{
	public:
		string policy;
		string address;
	
	Contact(const string& p,const string& add):
		policy(p),address(add){}	
};
class PersonalRecord: public PersonalDetails,public Physical,public Contact
{
	public:
		string telephone;
		string licence;
		
	PersonalRecord():
		PersonalDetails("","",""),
		Physical(0.0,0.0),
		Contact("",""),
		telephone(""),licence(""){}
		
	PersonalRecord(const string& n,const string& d,const string& b,
					float h,float w,
					const string& p,const string& add,
					const string& tel,const string& lic):
		PersonalDetails(n,d,b),Physical(h,w),Contact(p,add),telephone(tel),licence(lic){}	
};

PersonalRecord records[MAX_RECORDS];
int currentRecords=0;
void deleteEntry();
void editRecord();
void searchRecord();

void Menu()
{
	if(currentRecords < MAX_RECORDS)
	{
		string name,dob,blood,policy,address,telephone,licence;
		double height,weight;
		
		cout<<"Enter the Name:";
		cin>>name;
		cout<<"Enter the date of birth(DD/MM/YYYY):";
		cin>>dob;
		cout<<"Enter the Blood Group:";
		cin>>blood;
		cout<<"Enter the Height:";
		cin>>height;
		cout<<"Enter the weight:";
		cin>>weight;
		cout<<"Enter Insurance policy number:";
		cin>>policy;
		cout<<"Enter contact address:";
		cin>>address;
		cout<<"Enter Telephone number:";
		cin>>telephone;
		cout<<"Enter the Licence Number:";
		cin>>licence;
		
		records[currentRecords]=PersonalRecord(name,dob,blood,height,weight,policy,address,telephone,licence);
		++currentRecords;
	}
	else
	{
		cout<<"Maximum number of record reached.\n";
	}
}
void DisplayRecord()
{
	cout<<"\n----Displaying Records----\n";
	for(int i=0;i<currentRecords;i++)
	{
		cout<<"Name:"<<records[i].name<<endl;
		cout<<"Date Of Birth:"<<records[i].dob<<endl;
		cout<<"Blood Group:"<<records[i].blood<<endl;
		cout<<"Height:"<<records[i].height<<endl;
		cout<<"Weight:"<<records[i].weight<<endl;
		cout<<"Policy Number:"<<records[i].policy<<endl;
		cout<<"Contact Address:"<<records[i].address<<endl;
		cout<<"Telephone:"<<records[i].telephone<<endl;
		cout<<"Licence:"<<records[i].licence<<endl<<"\n";
	}
}
void insertNewEntry()
{
	Menu();
}
void deleteEntry()
{
	string searchName;
	cout<<"Enter the name to Delete:";
	cin>>searchName;
	
	PersonalRecord* it=find_if(records,records+currentRecords,[searchName](const PersonalRecord& record)
	{
		return record.name==searchName;
	});
	
	if(it!=records+currentRecords)
	{
		copy(it+1,records + currentRecords ,it);
		--currentRecords;
		cout<<"Record Deleted Successfully.\n";
	}
	else
	{
		cout<<"Record Not Found.\n";
	}
}
void editRecord()
{
	string searchName;
	int choice;
	cout<<"Enter the name to edit:";
	cin>>searchName;
	
		PersonalRecord* it=find_if(records, records+ currentRecords, [searchName](const PersonalRecord& record)
	{
		return record.name==searchName;
	});
	if(it!=records + currentRecords)
	{
	
		cout<<"\nEditing a record---";
		cout<<"\n1.Name";
		cout<<"\n2.DOB";
		cout<<"\n3.Blood Group";
		cout<<"\n4.Height";
		cout<<"\n5.Weight";
		cout<<"\n6.Policy Number";
		cout<<"\n7.Telephone number";
		cout<<"\n8.Licence Number";
		cout<<"\n0.Exit";
		cout<<"Enter the number of field to edit:";
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				cout<<"Enter the new Name:";
				cin>>it->name;
				break;
			case 2:
				cout<<"Enter the new DOB:";
				cin>>it->dob;
				break;
			case 3:
				cout<<"Enter the Blood Group:";
				cin>>it->blood;
				break;
			case 4:
				cout<<"Enter new Height:";
				cin>>it->height;
				break;
			case 5:
				cout<<"Enter new Weight:";
				cin>>it->weight;
				break;
			case 6:
				cout<<"Enter new Policy Number:";
				cin>>it->policy;
				break;
			case 7:
				cin>>it->address;
				cout<<"Enter new Telephone:";
				break;
			case 8:
				cout<<"Enter new Licence Number:";
				cin>>it->licence;
				break;
			case 0:
				cout<<"Exit...";
				break;
			default:
				cout<<"Invalid choice...";
				
				
		}
//	if(it!=records + currentRecords)
//	{	
//		cout<<"Enter the new name:";
//		cin>>it->name;
//		cout<<"Enter the new DOB:";
//		cin>>it->dob;
//		cout<<"Enter the Blood Group:";
//		cin>>it->blood;
//		cout<<"Enter new Height:";
//		cin>>it->height;
//		cout<<"Enter new Weight:";
//		cin>>it->weight;
//		cout<<"Enter new Policy Number:";
//		cin>>it->policy;
//		cout<<"Enter the New Address:";
//		cin>>it->address;
//		cout<<"Enter new Telephone:";
//		cin>>it->telephone;
//		cout<<"Enter new Licence Number:";
//		cin>>it->licence;
		
		
		cout<<"Record Edited Successfully:";
	}
	else
	{
		cout<<"Record Not found...";
	}
}
void searchRecord()
{
	string searchName;
	cout<<"Enter the name to serach:";
	cin>>searchName;
	
	auto it=find_if(records,records + currentRecords,[searchName](const PersonalRecord& record)
	{
		return record.name==searchName;
	});
	if(it!=records+currentRecords)
	{
		cout<<"Record Found:\n";
		cout<<"Name:"<<it->name<<endl;
		cout<<"Date of Birth:"<<it->dob<<endl;
		cout<<"Blood Group:"<<it->blood<<endl;
		cout<<"Height:"<<it->height<<endl;
		cout<<"Weight:"<<it->weight<<endl;
		cout<<"Policy Number:"<<it->policy<<endl;
		cout<<"Contact Address:"<<it->address<<endl;
		cout<<"Telephone:"<<it->telephone<<endl;
		cout<<"Licence Number:"<<it->licence<<endl;	
	}
}
int main()
{
	int ch;
	do{
		cout<<"-----------------------";
		cout<<"\n1.Build a Master Table";
		cout<<"\n2.Display";
		cout<<"\n3.Insert a new Entry";
		cout<<"\n4.Delete a Entry";
		cout<<"\n5.Edit";
		cout<<"\n6.Serach";
		cout<<"\n7.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				Menu();
				break;
			case 2:
				DisplayRecord();
				break;
			case 3:
				insertNewEntry();
				break;
			case 4:
				deleteEntry();
				break;
			case 5:
				editRecord();
				break;
			case 6:
				searchRecord();
				break;
			case 7:
				cout<<"Exiting Program.\n";
				break;
			default:
				cout<<"Invalid chioce...Try agian.\n";
		}
	}while(ch!=7);
	return 0;
}
