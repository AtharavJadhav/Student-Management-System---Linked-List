#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

typedef struct Data_Gen_tag
{
	char Name[30];
	char Dep_Code[4];
	//int year;
	int sem;
	char Roll_No[11];
	int Sub[6];
	int attendance[7];
	int application;
	int fee_status;
}Data_Gen;

typedef struct Data_Atd_tag
{
	char Dep_Code[4];
	//int year;
	char Roll_No[11];
	int attendance[2];
}Data_Atd;

typedef struct Data_Fee_tag
{
	char Roll_No[11];
	int fee;
}Data_Fee;

typedef struct Data_Appl_tag
{
	char Name[30];
	char Roll_No[11];
	int application;
}Data_Appl;

//Basic functions of a linked list.

typedef Data_Gen Item_Type;
typedef Data_Atd Item_Type2;
typedef Data_Fee Item_Type3;
typedef Data_Appl Item_Type4;

typedef struct Node_tag
{
	Item_Type data;
	struct Node_tag* next;
}Node;

typedef struct NodeA_tag
{
	Item_Type2 data;
	struct Node_tagA* next;
}NodeA;

typedef struct NodeF_tag
{
	Item_Type3 data;
	struct Node_tagF* next;
}NodeF;

typedef struct NodeP_tag
{
	Item_Type4 data;
	struct Node_tagP* next;
}NodeP;

Node* create_node(Node* head, Item_Type data)
{
	Node* nptr = NULL;

	nptr = (Node*)malloc(sizeof(Node));
	nptr->data = data;
	nptr->next = head;
	head = nptr;

	return head;
}

NodeA* create_attd_node(NodeA* head, Item_Type2 data)
{
	NodeA* nptr = NULL;

	nptr = (NodeA*)malloc(sizeof(NodeA));
	nptr->data = data;
	nptr->next = head;
	head = nptr;

	return head;
}

NodeF* create_fee_node(NodeF* head, Item_Type3 data)
{
	NodeF* nptr = NULL;

	nptr = (NodeF*)malloc(sizeof(NodeF));
	nptr->data = data;
	nptr->next = head;
	head = nptr;

	return head;
}

NodeP* create_Appl_node(NodeP* head, Item_Type4 data)
{
	NodeP* nptr = NULL;

	nptr = (NodeP*)malloc(sizeof(NodeP));
	nptr->data = data;
	nptr->next = head;
	head = nptr;

	return head;
}

//delete node functions
Node* delete_node(Node* head, Item_Type* data)
{
	Node* nptr;
	if (head != NULL)
	{
		nptr = head;
		*data = nptr->data;
		head = head->next;
		free(nptr);
		nptr = NULL;
	}

	return head;
}

NodeA* delete_attd_node(NodeA* head, Item_Type2* data)
{
	NodeA* nptr;
	if (head != NULL)
	{
		nptr = head;
		*data = nptr->data;
		head = head->next;
		free(nptr);
		nptr = NULL;
	}

	return head;
}

NodeF* delete_fee_node(NodeF* head, Item_Type3* data)
{
	NodeF* nptr;
	if (head != NULL)
	{
		nptr = head;
		*data = nptr->data;
		head = head->next;
		free(nptr);
		nptr = NULL;
	}

	return head;
}

NodeP* delete_Appl_node(NodeP* head, Item_Type4* data)
{
	NodeP* nptr;
	if (head != NULL)
	{
		nptr = head;
		*data = nptr->data;
		head = head->next;
		free(nptr);
		nptr = NULL;
	}

	return head;
}
// trial function to check if create_node is correct. Can insert nodes as per wish
Node* Create_List(Node* head)
{
	int flag = 1;
	int c;
	Item_Type data;
	int input = 0;

	FILE* fp;
	int x;
	errno_t error_code;
	error_code = fopen_s(&fp, "C:/Atharav Documents/Sem 4/DSPD 2/Assignment 1/Input.txt", "r");
	if (error_code != 0)
	{
		printf_s("The file Input.txt was not opened\n");
	}
	else
	{
		while (flag == 1)
		{
			fscanf_s(fp, "%d", &flag);

			if (flag == 1)
			{

				fscanf_s(fp, "%d", &input);
				if (input == 1)
				{

					fscanf_s(fp, "%s", &data.Dep_Code, sizeof(data.Dep_Code));

					fscanf_s(fp, "%d", &data.sem);

					for (x = 0; x < 5; x++)
					{
						fscanf_s(fp, "%d", &data.Sub[x]);
					}
				}

				fscanf_s(fp, "%s", &data.Name, sizeof(data.Name));
				fscanf_s(fp, "%s", &data.Roll_No, sizeof(data.Roll_No));
				for (x = 0; x < 5; x++)
				{
					fscanf_s(fp, "%d", &data.attendance[x]);
				}
				fscanf_s(fp, "%d", &data.application);
				fscanf_s(fp, "%d", &data.fee_status);
				head = create_node(head, data);
			}
		}
	}
	fclose(fp);
	return head;
}

NodeA* Create_attd_list(Node* head)
{
	Node* ptr;
	ptr = head;
	NodeA* aptr;
	aptr = NULL;
	Item_Type2 data;
	int mcc;
	while (ptr != NULL)
	{
		strcpy_s(data.Dep_Code, 4, ptr->data.Dep_Code);
		strcpy_s(data.Roll_No, 11, ptr->data.Roll_No);
		mcc = ptr->data.Sub[5];
		data.attendance[0] = ptr->data.attendance[mcc];
		data.attendance[1] = ptr->data.attendance[6];

		aptr = create_attd_node(aptr, data);
		ptr = ptr->next;
	}

	return aptr;

}

NodeF* Create_fee_list(Node* head)
{
	Node* ptr;
	ptr = head;
	NodeF* aptr;
	aptr = NULL;
	Item_Type3 data;
	while (ptr != NULL)
	{
		strcpy_s(data.Roll_No, 11, ptr->data.Roll_No);
		data.fee = ptr->data.fee_status;
		aptr = create_fee_node(aptr, data);
		ptr = ptr->next;
	}

	return aptr;

}

NodeP* Create_Appl_list(Node* head)
{
	Node* ptr;
	ptr = head;
	NodeP* aptr;
	aptr = NULL;
	Item_Type4 data;
	while (ptr != NULL)
	{
		strcpy_s(data.Name, 11, ptr->data.Name);
		strcpy_s(data.Roll_No, 11, ptr->data.Roll_No);
		data.application = ptr->data.application;
		aptr = create_Appl_node(aptr, data);
		ptr = ptr->next;
	}

	return aptr;

}

void Delete_List(Node* head)
{
	Item_Type data;
	int x;
	while (head != NULL)
	{
		head = delete_node(head, &data);
		//printf("\n");
		printf("Name: %s\t", data.Name);
		printf("DepCode: %s \t", data.Dep_Code);
		printf("Sem: %d \t", data.sem);
		printf("RollNo: %s \t", data.Roll_No);
		x = 5;
		printf("MCC: Sub %d\t", data.Sub[x] + 1);
		x = 6;
		printf("Attendance: %d\t", data.attendance[x]);

		if (data.application == 1)
		{
			printf(" | Applied for examination\t");
		}
		else
		{
			printf(" | Not Applied for examination\t");
		}
		if (data.fee_status == 1)
		{
			printf(" | Fee status is clear\t");
		}
		else
		{
			printf(" | Fee not paid\t");
		}
		printf("\n");
	}
}

void Delete_attd_list(NodeA* head)
{
	Item_Type2 data;

	while (head != NULL)
	{
		head = delete_attd_node(head, &data);

		printf("Dep Code: %s\t", data.Dep_Code);
		printf("Roll No: %s\t", data.Roll_No);
		printf("MCC classes attended : %d\t", data.attendance[0]);
		printf("Percentage attendance : %d\n", data.attendance[1]);
	}
}

void Delete_fee_list(NodeF* head)
{
	Item_Type3 data;

	while (head != NULL)
	{
		head = delete_fee_node(head, &data);
		printf("Roll No : %s\t", data.Roll_No);
		if(data.fee == 1)
		{
			printf("Fee is paid\n");
		}
		else{
			printf("Fee not paid\n");
		}
		
	}
}

void Delete_Appl_list(NodeP* head)
{
	Item_Type4 data;

	while (head != NULL)
	{
		head = delete_fee_node(head, &data);
		printf("Name : %s\n", data.Name);
		printf("Roll No : %s\n", data.Roll_No);
		if(data.application == 1)
		{
			printf("Application\n");
		}
		else{
			printf("Not done\n");
		}
		
	}
}

//sorting functions

Node* merge(Node* l1, Node* l2)
{
	Node* result, * tail, * ptr1, * ptr2;
	ptr1 = l1;
	ptr2 = l2;
	if (ptr1->data.sem < ptr2->data.sem)
	{
		result = ptr1;
		ptr1 = ptr1->next;
	}
	else if (ptr2->data.sem < ptr1->data.sem)
	{
		result = ptr2;
		ptr2 = ptr2->next;
	}
	else
	{
		if (strcmp(ptr1->data.Dep_Code, ptr2->data.Dep_Code) < 0)
		{
			result = ptr1;
			ptr1 = ptr1->next;
		}
		else if (strcmp(ptr1->data.Dep_Code, ptr2->data.Dep_Code) > 0)
		{
			result = ptr2;
			ptr2 = ptr2->next;
		}
		else
		{
			if (strcmp(ptr1->data.Roll_No, ptr2->data.Roll_No) < 0)
			{
				result = ptr1;
				ptr1 = ptr1->next;
			}
			else
			{
				result = ptr2;
				ptr2 = ptr2->next;
			}
		}
	}
	tail = result;
	while (ptr1 && ptr2)
	{
		if (ptr1->data.sem < ptr2->data.sem)
		{
			tail->next = ptr1;
			tail = tail->next;
			ptr1 = ptr1->next;
		}
		else if (ptr2->data.sem < ptr1->data.sem)
		{
			tail->next = ptr2;
			tail = tail->next;
			ptr2 = ptr2->next;
		}
		else
		{
			if (strcmp(ptr1->data.Dep_Code, ptr2->data.Dep_Code) < 0)
			{
				tail->next = ptr1;
				tail = tail->next;
				ptr1 = ptr1->next;
			}
			else if (strcmp(ptr1->data.Dep_Code, ptr2->data.Dep_Code) > 0)
			{
				tail->next = ptr2;
				tail = tail->next;
				ptr2 = ptr2->next;

			}
			else
			{
				if (strcmp(ptr1->data.Roll_No, ptr2->data.Roll_No) < 0)
				{
					tail->next = ptr1;
					tail = tail->next;
					ptr1 = ptr1->next;
				}
				else
				{
					tail->next = ptr2;
					tail = tail->next;
					ptr2 = ptr2->next;

				}
			}
		}
	}
	if (ptr1)
	{
		tail->next = ptr1;
	}
	else
	{
		tail->next = ptr2;
	}
	return result;
}

Node* Divide(Node* lptr)
{
	Node* nptr, * fast, * slow;
	slow = lptr;
	fast = lptr->next->next;
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
		if (fast != NULL)
		{
			fast = fast->next;
		}
	}
	nptr = slow->next;
	slow->next = NULL;
	return nptr;
}

Node* Mergesort(Node* list_ptr)
{
	Node* lptr, * nptr;
	lptr = list_ptr;
	if ((lptr != NULL) && (lptr->next != NULL))
	{
		nptr = Divide(lptr);
		lptr = Mergesort(lptr);
		nptr = Mergesort(nptr);
		lptr = merge(lptr, nptr);
	}
	return lptr;
}

// finding mcc
int find_max(int arr[], int n)
{
	int i;
	int max = arr[0];
	int retval = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
			retval = i;
		}
	}

	return retval;
}

Node* find_mcc(Node* head)
{
	Node* ptr;
	Node* ptr2;
	ptr = head;
	ptr2 = head;

	ptr->data.Sub[5] = find_max(ptr->data.Sub, 5);
	ptr2 = ptr2->next;
	while (ptr2 != NULL)
	{
		if ((strcmp(ptr->data.Dep_Code, ptr2->data.Dep_Code) == 0) && (ptr->data.sem == ptr2->data.sem))
		{
			ptr2->data.Sub[5] = ptr->data.Sub[5];
			//printf("%d \n", ptr->data.Sub[5]);
			ptr = ptr->next;
			//ptr2 = ptr2->next;
		}
		else
		{
			ptr = ptr->next;
			ptr->data.Sub[5] = find_max(ptr->data.Sub, 5);
			//printf("%d \n", ptr->data.Sub[5]);
			//ptr2 = ptr2->next;
		}
		ptr2 = ptr2->next;
	}
	return head;
}

Node* find_max_attd(Node* head)
{
	Node* ptr1;
	Node* ptr2;
	Node* ptr3;

	ptr1 = head;
	ptr2 = head;
	ptr3 = head;

	ptr3 = ptr3->next;

	int mcc = ptr2->data.Sub[5];
	int max = ptr2->data.attendance[mcc];
	if (ptr3 != NULL)
	{
		while (ptr3 != NULL)
		{
			if (strcmp(ptr2->data.Dep_Code, ptr3->data.Dep_Code) == 0 && ptr2->data.sem == ptr3->data.sem)
			{
				mcc = ptr3->data.Sub[5];
				if (max < ptr3->data.attendance[mcc])
				{
					max = ptr3->data.attendance[mcc];
				}
			}
			else
			{
				while (ptr1 != ptr3)
				{
					ptr1->data.attendance[5] = max;
					ptr1 = ptr1->next;
				}

				if (ptr3 != NULL)
				{
					mcc = ptr3->data.Sub[5];
					max = ptr3->data.attendance[mcc];
				}
			}

			ptr2 = ptr2->next;
			ptr3 = ptr3->next;

			if (ptr3 == NULL)
			{
				while (ptr1 != ptr3)
				{
					ptr1->data.attendance[5] = max;
					//printf("%d , this 1 loop runs", max);
					ptr1 = ptr1->next;
				}
			}
			//printf("this 2 loop runs");
		}
	}
	else
	{
		while (ptr1 != NULL)
		{
			ptr1->data.attendance[5] = max;
			ptr1 = ptr1->next;
		}
	}

	return head;
}

Node* find_per(Node* head)
{
	Node* ptr;
	ptr = head;
	int a = 0;
	int b = 0;
	int mcc;
	while (ptr != NULL)
	{
		mcc = ptr->data.Sub[5];
		a = ((ptr->data.attendance[mcc] * 100) / ptr->data.attendance[5]);
		ptr->data.attendance[6] = a;
		ptr = ptr->next;
	}

	return head;
}

//operation functions

void display_non_exam(Node* head)
{
	Node* ptr;
	ptr = head;

	while (ptr != NULL)
	{
		if (ptr->data.application != 1)
		{
			printf("Sem: %d\n", ptr->data.sem);
			printf("Dep: %s\n", ptr->data.Dep_Code);
			printf("Name: %s\n", ptr->data.Name);
		}
		ptr = ptr->next;
	}
}
//displays who havent applied for examination

Node* eligible(Node* head)
{
	Node* ptr;
	ptr = head;

	Node* nptr = NULL;

	while (ptr != NULL)
	{
		if ((ptr->data.attendance[6] > 74) && (ptr->data.application == 1) && (ptr->data.fee_status == 1))
		{
			nptr = create_node(nptr, ptr->data);
		}
		ptr = ptr->next;
	}

	return nptr;
}
//displays who are eligible for exam
Node* defaulter(Node* head)
{
	Node* ptr;
	ptr = head;
	int count[5] = { 0, 0, 0, 0, 0 };
	Node* nptr = NULL;
	//int x = 0;
	while (ptr != NULL)
	{
		if ((ptr->data.attendance[6] < 75) || (ptr->data.fee_status != 1))
		{
			nptr = create_node(nptr, ptr->data);

			if (strcmp("CSE", nptr->data.Dep_Code) == 0)
			{
				count[0]++;
			}
			else if (strcmp("ECE", nptr->data.Dep_Code) == 0)
			{
				count[1]++;
			}
			else if (strcmp("EEE", nptr->data.Dep_Code) == 0)
			{
				count[2]++;
			}
			else if (strcmp("MEC", nptr->data.Dep_Code) == 0)
			{
				count[3]++;
			}
			else if (strcmp("CIV", nptr->data.Dep_Code) == 0)
			{
				count[4]++;
			}
		}
		ptr = ptr->next;
	}
	int max = 0;
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
			j = i;
		}
	}

	if (j == 0)
	{
		printf("Max Defaulter is: CSE\n");
	}
	else if (j == 1)
	{
		printf("Max Defaulter is: ECE\n");
	}
	else if (j == 2)
	{
		printf("Max Defaulter is: EEE\n");
	}
	else if (j == 3)
	{
		printf("Max Defaulter is: MEC\n");
	}
	else if (j == 4)
	{
		printf("Max Defaulter is: CIV\n");
	}

	return nptr;
}

Node* attd(Node* head)
{
	Node* ptr;
	ptr = head;

	Node* nptr = NULL;

	while (ptr != NULL)
	{
		if (ptr->data.attendance[6] < 75)
		{
			nptr = create_node(nptr, ptr->data);
		}
		ptr = ptr->next;
	}

	return nptr;
}

Node* fee_pending(Node* head)
{
	Node* ptr;
	ptr = head;

	Node* nptr = NULL;

	while (ptr != NULL)
	{
		if ((ptr->data.attendance[6] > 74) && (ptr->data.fee_status != 1))
		{
			nptr = create_node(nptr, ptr->data);
		}
		ptr = ptr->next;
	}

	Node* gptr;
	gptr = nptr;

	while (gptr != NULL)
	{
		printf("Name of fee pending: %s\n", gptr->data.Name);
		gptr = gptr->next;
	}

	return nptr;
}

int main()
{
	Node* gen_ptr = NULL;

	gen_ptr = Create_List(gen_ptr);
	gen_ptr = Mergesort(gen_ptr);
	gen_ptr = find_mcc(gen_ptr);
	gen_ptr = find_max_attd(gen_ptr);
	gen_ptr = find_per(gen_ptr);

	//NodeA* attd_ptr;
	//attd_ptr = Create_attd_list(gen_ptr);

	//NodeF* fee_ptr;
	//fee_ptr = Create_fee_list(gen_ptr);

	//printf("\ndisplaying non Exam\n");
	//display_non_exam(gen_ptr);
	//printf("\n");
	//Node* ele = NULL;
	//ele = eligible(gen_ptr);

	//Node* atd = NULL;
	//atd = attd(gen_ptr);

	//Node* fee = NULL;
	//fee = fee_pending(gen_ptr);

	Node* def = NULL;
	def = defaulter(gen_ptr);

	//Delete_List(ele);
	
	//Delete_List(atd);
	//Delete_List(fee);
	Delete_List(def);

	//Delete_attd_list(attd_ptr);
	//Delete_fee_list(fee_ptr);

	printf("BreakPoint\n");
	Delete_List(gen_ptr);

	return 0;
}
