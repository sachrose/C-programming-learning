#include <stdio.h>
#include <stdlib.h>

struct node_
{
	int data;
	struct node_* next;
};
typedef struct node_ node;

void print_linked_list(node* head);

node* create_node(int d);

void insert_at_head(node** head, node* node_to_insert);

void insert_after(node* node_to_insert_after, node* new_node);

node* find_node_by_value(node* head, int data);

void remove_node(node** head, node* node_to_remove);

void delete_linked_list(node* head);

void linked_list_example();

int find_loop(node* head, node** loop_begin);

node* detect_loop(node* head);

int get_loop_size(node* node_in_loop);

node* find_loop_start(node* head, node* node_in_loop);


int main()
{
	#if 0
	
	linked_list_example();

	#else
	node *head = NULL;
		
	for(int i = 0; i < 25; i++)
	{
		insert_at_head(&head, create_node(i));
	}
	print_linked_list(head);

	node* n1 = find_node_by_value(head, 5);
	node* n2 = find_node_by_value(head, 17);
	n1->next = n2; // цель: указать на NULL
	
	node* loop_begin;
	int len = find_loop(head, &loop_begin);
	printf("%d\n", len);
	printf("%d\n", loop_begin->data);
	//print_linked_list(head);
	#endif

	return 0;
}

void print_linked_list(node* head)
{
	node* ptr = head;
	while(ptr != NULL)
	{
		const char* format_str = ptr->next == NULL ? "%d " : "%d --> ";
		printf(format_str, ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

node* create_node(int d)
{
	node* res = malloc(sizeof(node));
	res->data = d;
	res->next = NULL;
	return res;
}

void insert_at_head(node** head, node* node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
}

void insert_after(node* node_to_insert_after, node* new_node)
{
	new_node->next = node_to_insert_after->next;
	node_to_insert_after->next = new_node;
}

node* find_node_by_value(node* head, int data)
{
	node* ptr = head;
	while(ptr != NULL)
	{
		if(ptr->data == data)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void remove_node(node** head, node* node_to_remove)
{
	if(*head == node_to_remove)
	{
		*head = node_to_remove->next;
		free(node_to_remove);
		return;
	}
	
	node* ptr = *head;
	while(ptr != NULL && ptr->next != node_to_remove)
	{
		ptr = ptr->next;
	}
	
	if(ptr == NULL)
	{
		return;
	}
	ptr->next = node_to_remove->next;
	free(node_to_remove);
}

void delete_linked_list(node* head)
{
	node* ptr = head;
	while(ptr != NULL)
	{
		node *next = ptr->next;
		free(ptr);
		ptr = next;
	}
}

void linked_list_example()
{
	node *head = NULL, *tmp = NULL;
		
	for(int i = 0; i < 25; i++)
	{
		insert_at_head(&head, create_node(i));
	}
	
	tmp = find_node_by_value(head, 5);
	insert_after(tmp, create_node(42));
	
	remove_node(&head, tmp);
	remove_node(&head, head);
			
	print_linked_list(head);
	
	delete_linked_list(head);
}

int find_loop(node* head, node** loop_begin)
{
	node* node_in_loop = detect_loop(head);
	if(node_in_loop == NULL)
	{
		return 0;
	}
	*loop_begin = find_loop_start(head, node_in_loop);
	return get_loop_size(node_in_loop);
}

node* detect_loop(node* head)
{
	node* slow_ptr = head;
	node* fast_ptr = head;
	while(slow_ptr != NULL && fast_ptr != NULL)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
		if(fast_ptr != NULL)
		{
		fast_ptr = fast_ptr->next;	
		}
		if(slow_ptr == fast_ptr)
		{
			return fast_ptr;
		}
	}
	return NULL;
}

int get_loop_size(node* node_in_loop)
{
	node* ptr = node_in_loop->next;
	int size = 1;
	while(ptr != node_in_loop)
	{
		ptr = ptr->next;
		size++;
	}
	return size;
}

node* find_loop_start(node* head, node* node_in_loop)
{
	node* ptr1 = head;
	node* ptr2 = node_in_loop;
	while(ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr1;
}