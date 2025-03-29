#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return NULL;
	new_elem->data = data;
	new_elem->next = NULL;
	//new_elem->next = *begin_list;
	//*begin_list = new_elem;
	return (new_elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = new_elem;
		return ;
	}
	current = *begin_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_elem;
}

int	main()
{
	t_list	*head;
	char	*s1;
	char	*s2;
	t_list	*curr;

	head = NULL;
	s1 = "hello";
	s2 = "1234";
	ft_list_push_back(&head, s1);
	ft_list_push_back(&head, s2);
	curr = head;
	while (curr != NULL)
	{
		printf("%s ->", (char *)curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
	return (0);
}
