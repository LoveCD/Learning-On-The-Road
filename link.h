/* Copyright(p) 2020 dime $
 * $Author: dime $
 * $Date: 2020-3-28 $
 * $Instruction:This is the source code to implement the Linklist $
 *******************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//the struct for Link Node,user can define itself for their interest
typedef struct Link_node
{
	char element[128];
	char value;
	struct Link_node * next;
}link_node;

link_node * init_link();
int add_and_set_link_element(char *element, char value, link_node *op_link);
int delete_link_node(char *element, link_node *op_link);
char get_link_value_by_element(const char *element, link_node *op_link);