#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


// This Structure is for nodes of the linked lists in Hashing with chaining of Inventory Object.

struct LinkList
{
	long long productID;
	string name;
	float rate;
	long long quantity;
	LinkList *next;
};


// This Structure is for nodes of the linked lists in Hashing with chaining of Customer Object.

struct LinkList_Customer
{
	long long Customer_ID;
	string Customer_name;
	float Customer_Points;
	LinkList_Customer *nextC;
};


class Inventory
{
	LinkList *head,*prev;
	
	protected:
		
		void set_head_NULL(Inventory &I)   // Sets head of all Linked Lists in Hash Table to NULl.
		{
			I.head = NULL;
		}
		
		void update_item( Inventory &I , long long Id, string nm, float r, long long qtity)  // Adds Items in the inventory Hash Table. 
		{
			if(I.head == NULL)
			{
			 	LinkList *temp = new LinkList;
			 	temp->productID = Id;
			 	temp->name = nm;
			 	temp->quantity = qtity;
			 	temp->rate = r;
			 	temp->next = NULL;
			 	I.head = temp;
			}
			else
			{
				LinkList *temp = I.head;
				int f = 0;
				
				while(temp != NULL)
				{
					if(temp->productID < Id)  // Storing the items in sorted order of Product ID.
					{
						f = 1;
						prev = temp;
						temp = temp->next;
					}
					else
						break;
				}
				
				if(f == 0)
				{
					LinkList *tmp = new LinkList;
					tmp->productID = Id;
					tmp->name = nm;
					tmp->quantity = qtity;
					tmp->rate = r;
					tmp->next = I.head;
					I.head = tmp;
				}
				else
				{
					LinkList *tmp = new LinkList;
					tmp->productID = Id;
					tmp->name = nm;
					tmp->quantity = qtity;
					tmp->rate = r;
					tmp->next = prev->next;
					prev->next = tmp;
				}
			}
		}
		
		void Delete_Item( Inventory &I, long long pId )   // Deletes Items from the inventory.
		{
			LinkList *temp = I.head;
			
			int f = 0;
			
			while(temp != NULL)
			{
				if(temp->productID == pId)
				{
					if(f == 0)
					{
						if(temp->next == NULL)
						{
							I.head = NULL;
							delete temp;
						}
						else
						{
							I.head = temp->next;
							delete temp;
						}
					}
					else
					{
						prev->next = temp->next;
						delete temp;
					}
					break;
				}
				else
				{
					f = 1;
					prev = temp;
					temp = temp->next;
				}
			}
			
		}
		
		void Change_Rate( Inventory &I, long long Id, float changed_rate )  // Changes the rate of the item in the inventory.
		{
			LinkList *temp = I.head;
			
			while(temp != NULL)
			{
				if( temp->productID == Id )
				{
					temp->rate = changed_rate;
					break;
				}
				else
					temp = temp->next;
			}
		}
		
		void Change_Quantity( Inventory &I, long long Id, float changed_quantity )  // Changes the quantity of the item in the inventory.
		{
			LinkList *temp = I.head;
			
			while(temp != NULL)
			{
				if( temp->productID == Id )
				{
					temp->quantity = changed_quantity;
					break;
				}
				else
					temp = temp->next;
			}
		}
		
	public:
		
		long long provide_item_quantity( long long Id )  // Returns quantity of the item.
		{
			LinkList *tmp = head;
			
			while(tmp != NULL)
			{
				if( tmp->productID == Id )
				{
					return tmp->quantity;
				}
				tmp = tmp->next;
			}
		}
		
		float provide_item_rate( long long Id )       // Returns rate of the item.
		{
			LinkList *tmp = head;
			
			while(tmp != NULL)
			{
				if( tmp->productID == Id )
				{
					return tmp->rate;
				}
				tmp = tmp->next;
			}
		}
		
		string provide_item_name( long long Id )     // Returns name of the item.
		{
			LinkList *tmp = head;
			
			while(tmp != NULL)
			{
				if( tmp->productID == Id )
				{
					return tmp->name;
				}
				tmp = tmp->next;
			}
		}
		
		void show()
		{
			LinkList *tmp = head;
			while(tmp != NULL)
			{
				cout<<tmp->productID<<" "<<tmp->name<<" "<<tmp->rate<<" "<<tmp->quantity<<endl;
				tmp = tmp->next;
			}
		}
			
};


Inventory HashTable[10];   // Hashing with chaining with Hash Table 0f size 10 is implemented as a data structure to store Inventory Items. 


class Manager : public Inventory
{
	public:
		
		void set_NULL()
		{
			for(int i=0;i<10;i++)
				set_head_NULL(HashTable[i]);
		}
		
		void update_Inventory(long long index, long long Id, string nm, float r, long long qtity)   // This function updates and Adds Items in the Inventory.
		{
			update_item( HashTable[index], Id, nm, r, qtity);	
		}
		
		void Delete_Inventory_Item(long long pId)   // This function deletes the Product of the given Id from the Inventory.
		{
			long long Hash = pId%10;
			
			Delete_Item( HashTable[Hash], pId );
		}
		
		void Change_Inventory_Item_Rate( long long pId, float changed_rate )   // This function changes the item's rate in the inventory.
		{
			long long Hash = pId%10;
			
			Change_Rate( HashTable[Hash], pId, changed_rate );
		}
		
		void Change_Inventory_Item_Quantity( long long pId, long long changed_qty )   // This function changes the item's quantity in the inventory.
		{
			long long Hash = pId%10;
			
			Change_Quantity( HashTable[Hash], pId, changed_qty );
		}
		
};


class Customer
{
	LinkList_Customer *headC,*prevC;
	
	protected:
		
		void set_head_Customer_NULL(Customer &C)   // Sets head of all Linked Lists in Hash Table to NULl.
		{
			C.headC = NULL;
		}
		
		void update_customer_database( Customer &C , long long Id, string nm, float pts)  // Updates Items in the customer Hash Table. 
		{
			if(C.headC == NULL)
			{
			 	LinkList_Customer *temp = new LinkList_Customer;
			 	temp->Customer_ID = Id;
			 	temp->Customer_name = nm;
			 	temp->Customer_Points = pts;
			 	temp->nextC = NULL;
			 	C.headC = temp;
			}
			else
			{
				LinkList_Customer *temp = C.headC;
				int f = 0;
				
				while(temp != NULL)
				{
					if(temp->Customer_ID < Id)
					{
						f = 1;
						prevC = temp;
						temp = temp->nextC;
					}
					else
						break;
				}
				
				if(f == 0)
				{
					LinkList_Customer *tmp = new LinkList_Customer;
					tmp->Customer_ID = Id;
					tmp->Customer_name = nm;
					tmp->Customer_Points = pts;
					tmp->nextC = C.headC;
					C.headC = tmp;
				}
				else
				{
					LinkList_Customer *tmp = new LinkList_Customer;
					tmp->Customer_ID = Id;
					tmp->Customer_name = nm;
					tmp->Customer_Points = pts;
					tmp->nextC = prevC->nextC;
					prevC->nextC = tmp;
				}
			}
		}
		
		void update_Points( Customer &C, long long Id, float pts )   // This function Updates Points of the customer when he/she buys something.
		{
			LinkList_Customer *tmp = C.headC;
			
			while(tmp != NULL)
			{
				if(tmp->Customer_ID == Id)
				{
					tmp->Customer_Points = tmp->Customer_Points + pts;
					break;
				}
				else
					tmp = tmp->nextC;
			}
		}
		
		int search_customer_in_database( Customer &C, long long Id )  // Returns 1 if the customer is found in database and 0 if not found in database.
		{
			LinkList_Customer *tmp = C.headC;
			
			int found = 0;
			
			while(tmp != NULL)
			{
				if( tmp->Customer_ID == Id )
				{
					found = 1;
					break;
				}
				tmp = tmp->nextC;
			}
			
			return found;
			
		}
		
	public:
		
		void showC()
		{
			LinkList_Customer *tmp = headC;
			
			while(tmp != NULL)
			{
				cout<<tmp->Customer_ID<<" "<<tmp->Customer_name<<" "<<tmp->Customer_Points<<endl;
				tmp = tmp->nextC;	
			} 
		}
				
};

Customer Database[10];    // Hashing with chaining with Hash Table of size 10 is used as a data structure to store Customer's data.

class Billing : public Customer
{
	public:
		
		void set_Customer_NULL()
		{
			for(int i=0;i<10;i++)
				set_head_Customer_NULL(Database[i]);
		}
		
		void update_Customer(long long index, long long Id, string nm, float pts)   // This function Adds Customer in the Customer Database.
		{
			update_customer_database( Database[index], Id, nm, pts );	
		}		
		
		void update_Customer_Points( long long Id, float price )   // This function updates Customer's points.
		{
			long long Hash = Id%10;
			
			update_Points( Database[Hash], Id, price );
		}
		
		float make_payment( long long *IDs, long long *quantities, long number_of_items )  // Prints the bill and returns the total amount.
		{
			
			float Total = 0;
			
			for(long j=0;j<number_of_items;j++)
			{
				if(IDs[j] != -1)
				{
					Total += quantities[j]*HashTable[IDs[j]%10].provide_item_rate( IDs[j] );
					cout<<IDs[j]<<", "<<HashTable[IDs[j]%10].provide_item_name( IDs[j] )<<", "<<HashTable[IDs[j]%10].provide_item_rate( IDs[j] )<<", "<<quantities[j]<<", "<<quantities[j]*HashTable[IDs[j]%10].provide_item_rate( IDs[j] )<<endl;
				}
			}
			cout<<"Total: "<<Total<<endl;
			
			return Total;
			
		}
		
		int search_customer( long long Id )  // Searches for the customer in the database and returns 1 if it is found or 0 if not found.
		{
			long long Hash = Id%10;
			
			int found = search_customer_in_database( Database[Hash], Id );
			
			return found;
		}
};


int main()
{
	
	Manager Man;  // Manager Object.
	
	Man.set_NULL();
	
	long long INVENTORY_DATASET[100][4] = {
{111100000001,1,100,20},{111100000002,2,110,20},{111100000003,3,120,20},{111100000004,4,130,20},{111100000005,5,140,20},{111100000006,6,150,20},{111100000007,7,160,20},{111100000008,8,170,20},{111100000009,9,180,20},{111100000010,10,190,20},
{111100000011,11,200,20},{111100000012,12,210,20},{111100000013,13,220,20},{111100000014,14,230,20},{111100000015,15,240,20},{111100000016,16,250,20},{111100000017,17,260,20},{111100000018,18,270,20},{111100000019,19,280,20},{111100000020,20,290,20},
{111100000021,21,300,20},{111100000022,22,310,20},{111100000023,23,320,20},{111100000024,24,330,20},{111100000025,25,340,20},{111100000026,26,350,20},{111100000027,27,360,20},{111100000028,28,370,20},{111100000029,29,380,20},{111100000030,30,390,20},
{111100000031,31,400,20},{111100000032,32,410,20},{111100000033,33,420,20},{111100000034,34,430,20},{111100000035,35,440,20},{111100000036,36,450,20},{111100000037,37,460,20},{111100000038,38,470,20},{111100000039,39,480,20},{111100000040,40,490,20},
{111100000041,41,500,20},{111100000042,42,510,20},{111100000043,43,520,20},{111100000044,44,530,20},{111100000045,45,540,20},{111100000046,46,550,20},{111100000047,47,560,20},{111100000048,48,570,20},{111100000049,49,580,20},{222200001111,50,590,20},
{222200001114,51,600,20},{222200001117,52,610,20},{222200001120,53,620,20},{222200001123,54,630,20},{222200001126,55,640,20},{222200001129,56,650,20},{222200001132,57,660,20},{222200001135,58,670,20},{222200001138,59,680,20},{222200001141,60,690,20},
{222200001144,61,700,20},{222200001147,62,710,20},{222200001150,63,720,20},{222200001153,64,730,20},{222200001156,65,740,20},{222200001159,66,750,20},{222200001162,67,760,20},{222200001165,68,770,20},{222200001168,69,780,20},{222200001171,70,790,20},
{222200001174,71,800,20},{222200001177,72,810,20},{222200001180,73,820,20},{222200001183,74,830,20},{222200001186,75,840,20},{222200001189,76,850,20},{222200001192,77,860,20},{222200001195,78,870,20},{222200001198,79,880,20},{222200001201,80,890,20},
{222200001204,81,900,20},{222200001207,82,910,20},{222200001210,83,920,20},{222200001213,84,930,20},{222200001216,85,940,20},{222200001219,86,950,20},{222200001222,87,960,20},{222200001225,88,970,20},{222200001228,89,980,20},{222200001231,90,990,20},
{222200001234,91,1000,20},{222200001237,92,1010,20},{222200001240,93,1020,20},{222200001243,94,1030,20},{222200001246,95,1040,20},{222200001249,96,1050,20},{222200001252,97,1060,20},{222200001255,98,1070,20},{222200001258,99,1080,20},{222200001261,100,1090,20},
};

	
	// Updating Inventory Database.
	
	for(int i=0;i<100;i++)
	{
		long long pId = INVENTORY_DATASET[i][0];
		
		long long Name = (INVENTORY_DATASET[i][1]);
		
		string pName;
		
		if( Name < 10 )
			pName += (Name + 48);
		else if( Name >= 10 && Name <100 )
		{
			pName += (Name/10 + 48);
			pName += (Name%10 + 48);
		}
		else if( Name >= 100 )
		{
			pName += (Name/100 + 48);
			Name%=100;
			pName += (Name/10 + 48);
			pName += (Name%10 + 48);
		}
		
		float pRate = (1.0)*INVENTORY_DATASET[i][2];
		
		long long pQuantity = INVENTORY_DATASET[i][3];
		
		long long Hash = pId%10;
		
		Man.update_Inventory( Hash , pId, pName, pRate, pQuantity);   // Manager Object Updating Inventory.
		
	}
	
	//Man.Change_Inventory_Item_Quantity(111100000001,40);
	
	//Man.Change_Inventory_Item_Quantity(111100000010,2);
	//HashTable[0].show(); 
	
	Billing Bill;   // Billing Object.
	
	Bill.set_Customer_NULL();
	
	long long CUSTOMER_DATASET[100][3] = {
{9400000001,1,0},{9400000002,2,0},{9400000003,3,0},{9400000004,4,0},{9400000005,5,0},{9400000006,6,0},{9400000007,7,0},{9400000008,8,0},{9400000009,9,0},{9400000010,10,0},
{9400000011,11,0},{9400000012,12,0},{9400000013,13,0},{9400000014,14,0},{9400000015,15,0},{9400000016,16,0},{9400000017,17,0},{9400000018,18,0},{9400000019,19,0},{9400000020,20,0},
{9400000021,21,0},{9400000022,22,0},{9400000023,23,0},{9400000024,24,0},{9400000025,25,0},{9400000026,26,0},{9400000027,27,0},{9400000028,28,0},{9400000029,29,0},{9400000030,30,0},
{9400000031,31,0},{9400000032,32,0},{9400000033,33,0},{9400000034,34,0},{9400000035,35,0},{9400000036,36,0},{9400000037,37,0},{9400000038,38,0},{9400000039,39,0},{9400000040,40,0},
{9400000041,41,0},{9400000042,42,0},{9400000043,43,0},{9400000044,44,0},{9400000045,45,0},{9400000046,46,0},{9400000047,47,0},{9400000048,48,0},{9400000049,49,0},{9400000050,50,0},
{9400000051,51,0},{9400000052,52,0},{9400000053,53,0},{9400000054,54,0},{9400000055,55,0},{9400000056,56,0},{9400000057,57,0},{9400000058,58,0},{9400000059,59,0},{9400000060,60,0},
{9400000061,61,0},{9400000062,62,0},{9400000063,63,0},{9400000064,64,0},{9400000065,65,0},{9400000066,66,0},{9400000067,67,0},{9400000068,68,0},{9400000069,69,0},{9400000070,70,0},
{9400000071,71,0},{9400000072,72,0},{9400000073,73,0},{9400000074,74,0},{9400000075,75,0},{9400000076,76,0},{9400000077,77,0},{9400000078,78,0},{9400000079,79,0},{9400000080,80,0},
{9400000081,81,0},{9400000082,82,0},{9400000083,83,0},{9400000084,84,0},{9400000085,85,0},{9400000086,86,0},{9400000087,87,0},{9400000088,88,0},{9400000089,89,0},{9400000090,90,0},
{9400000091,91,0},{9400000092,92,0},{9400000093,93,0},{9400000094,94,0},{9400000095,95,0},{9400000096,96,0},{9400000097,97,0},{9400000098,98,0},{9400000099,99,0},{9400000100,100,0},
};

	// Updating Customer Database.
	
	for(int i=0;i<100;i++)
	{
		long long Id = CUSTOMER_DATASET[i][0];
		
		long long nm = CUSTOMER_DATASET[i][1];
		
		string Cname;
		
		if( nm < 10)
			Cname += (nm + 48);
		else if( nm >= 10 && nm < 100 )
		{
			Cname += (nm/10 + 48);
			Cname += (nm%10 + 48);
		}
		else if( nm >= 100 )
		{
			Cname += (nm/100 + 48);
			nm%=100;
			Cname += (nm/10 + 48);
			Cname += (nm%10 + 48);
		}
		
		float points = CUSTOMER_DATASET[i][2];
		
		long long Hash = Id%10;
		
		Bill.update_Customer( Hash, Id, Cname, points );   // Billing Object adding customer data.
		
	}

	
	// Buying Items and Payment Episode.
	
	
	// First we take input of number of customers.
	long number_of_customers;
	cout<<"Enter number of customers: ";   
	cin>>number_of_customers;
	
	long long C_IDs[number_of_customers];  // Array that stores the customer's ID.
	
	long long Transaction_ID = 1;  // Transaction Id of the customer.
	
	for(long i=0;i<number_of_customers;i++)
	{
		
		// Then we take the input of customer ID.
		cout<<endl<<"Enter customer ID: ";
		cin>>C_IDs[i];
		
		
		//Search for the customer in the database.
		int f = Bill.search_customer( C_IDs[i] );
		
		//If the customer is not found in the database then add him/her in the database.
		if(f == 0)
		{
			// Take the input of the name of the customer.
			string Name;
			
			cout<<"Enter the name: ";
			getline(cin>>ws, Name);
			
			// Update the database by adding the customer.
			Bill.update_Customer( C_IDs[i]%10, C_IDs[i], Name, 0 ); 
			
		}
		
		// Secondly, we take input of number of items that a specific customer want to buy.
		long number_of_items;
		cout<<"Enter number of items to be bought: ";
		cin>>number_of_items;
		
		long long IDs[number_of_items],quantities[number_of_items];  // Arrays that store Product IDs and Quantities that the customer want to buy. 
		
		for(long j=0;j<number_of_items;j++)
		{
			// Take the input of the Product ID.
			long long Ids;
			cout<<"Enter Product ID: ";
			cin>>Ids;
			
			IDs[j] = Ids;
			
			// Take the input of the quantity of that ID.
			long long qnty;
			cout<<"Enter the quantity: ";
			cin>>qnty;
			
			quantities[j] = qnty;
		}
		
		// Then ask the customer whether he/she wants to cancel a product from the list.
		char choice;
		cout<<"Enter 'Y' if you want to cancel a product or 'N' if you do not want to cancel a product: ";
		cin>>choice;
		
		if(choice == 'Y')
		{
			
			// Then take the input of number of products he/she want to cancel.
			long cancel_number;
			cout<<endl<<"Enter number of products that you want to cancel: ";
			cin>>cancel_number;
			
			for(long x=0;x<cancel_number;x++)
			{
				
				// Take the input of the Product ID that want to be canceled.
				long long pID;
				cout<<"Enter the Product ID: ";
				cin>>pID;
				
				// Search for the given product ID to cancel it.
				for(long t=0;t<number_of_items;t++)
				{
					if(IDs[t] == pID)
					{
						IDs[t] = -1;       // -1 indicates that the product is canceled.
						quantities[t] = 0; // Quantity is also updated to zero.
						break;
					}
				}
				
			}
			
		}
		
		for(long j=0;j<number_of_items;j++)
		{
			if( IDs[j] != -1 )   // This indicates that the product is not canceled.
			{	
				long long remaining_qty = HashTable[IDs[j]%10].provide_item_quantity( IDs[j] );  // Search for the remaining quantity of items in the inventory database.
				
				if( remaining_qty < quantities[j] )
				{
					cout<<endl<<"Sorry, we do not have the stock of product with ID: "<<IDs[j]<<endl;
					IDs[j] = -1;
				}
				else
				{	
					Man.Change_Inventory_Item_Quantity( IDs[j], remaining_qty - quantities[j] );   // Updates the stock of the items.
				}
			}
		}
		
		cout<<endl;
		
		// Generation of the Bill.
		
		cout<<"Transaction ID: "<<Transaction_ID<<endl;
		cout<<"Customer ID: "<<C_IDs[i]<<endl;
		
		cout<<endl;
		
		float Total = 0;  // Total amount that customer needs to pay.
		
		Total = Bill.make_payment( IDs, quantities, number_of_items ); 
		
		Bill.update_Customer_Points(C_IDs[i], Total);   // Update Customer Points in the customer database.
		
	}
	
	cout<<endl;
	
	HashTable[1].show();
	cout<<endl;
	
	Database[1].showC();
	
}
