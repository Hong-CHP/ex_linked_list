#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return(elem);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	t_list	*elem;
	int	i;
	
	i = 0;
	head = NULL;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = head;
		head = elem;
		elem++;
		i++;
	}
	return (head);
}

int	main()
{
	char *strs[] = {"gugu", "hello", "peggy", "coffee"};
	t_list *curr;

	curr = ft_list_push_strs(4, strs);
	while (curr != NULL)
	{
		printf("%s ->", (char *)curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
	return (0);
}
	
