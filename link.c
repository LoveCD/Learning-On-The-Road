/* Copyright(p) 2020 dime $
 * $Author: dime $
 * $Date: 2020-3-28 $
 * $Instruction:This is the source code to implement the Linklist $
 *******************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

/*************************************************************************
* Method:init_link
* Fuction:Initial a linklist with the Head Node
*************************************************************************/
link_node * init_link()
{
	link_node *head = (link_node*)malloc(sizeof(link_node));
	strncpy(head->element,"head",127);
	head->value = 0;
	head->next = NULL;
	PR_DEBUG("initLink success! \n");
	return head;
}

/*************************************************************************
* Method:add_and_set_link_element
* Fuction:Add new element in linklist or set the value in exist element struct
*************************************************************************/
int add_and_set_link_element(char *element, char value, link_node *op_link)
{
	link_node *temp = op_link;
	if(element == NULL || 0 == strcasecmp(element,"") || op_link == NULL)
	{
		return 0;
	}

	while(temp->next != NULL)
	{
		if(0 == strcasecmp(temp->next->dev_id,dev_id))
		{
			temp->value = value;
			return 2;
		}
		temp = temp->next;
	}
	link_node *new_node = (link_node*)malloc(sizeof(link_node));
	new_node->next = NULL;
	new_node->status = value;
	strncpy(new_node->element,element,127);
	temp->next = new_node;
	
	return 1;
}

/*************************************************************************
* Method:delete_link_node
* Fuction:Delete the Link Node by paired element
*************************************************************************/
int delete_link_node(char *element, link_node *op_link)
{
	link_node *temp = op_link;
	link_node *del_node = NULL;
	if(element == NULL || 0 == strcasecmp(element,"") || op_link == NULL)
	{
		return 0;
	}
	while(temp->next != NULL)
	{
		if(0 == strcasecmp(temp->next->value,element))
		{
			del_node = temp->next;
			if(temp->next->next != NULL)
			{
				temp->next = temp->next->next;
			}
			else
			{
				temp->next = NULL;
			}
			free(del_node);
			del_node = NULL;
			return 0;
		}
		temp = temp->next;
	}
	return 0;
}

/*************************************************************************
* Method:get_link_value_by_element
* Fuction:Get the value by element in Link Node
*************************************************************************/
char get_link_value_by_element(const char *element, link_node *op_link)
{
	link_node *temp = op_link;
	char value = 0;

	PR_DEBUG("getLinkStatus start ! \n");
	if(element == NULL || 0 == strcasecmp(element,"") || op_link == NULL)
	{
		return 0;
	}
	while(temp->next != NULL)
	{
		if(0 == strcasecmp(temp->next->element,element))
		{
			value = temp->next->value;
			return value;
		}
		temp = temp->next;
	}
	return value;
}