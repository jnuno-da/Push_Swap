#include "push_swap.h"

static void	push_base(t_info *info, int i)
{
	while (i >= 0)
	{
		reverse_rotate_a(info, 0);
		i--;
	}
	push_b(info);
}

static void	push_top(t_info *info, int i)
{
	while (i-- > 0)
		rotate_a(info, 0);
	push_b(info);
}

static void	get_pivot_1(t_info *info)
{
	g_list	*temp;
	int		min;
	int		max;

	temp = info->stack_a;
	while (temp)
	{
		if (temp->prev == NULL)
		{
			min = temp->index;
			max = temp->index;
		}
		else
		{
			if (temp->index < min)
				min = temp->index;
			else if (temp->index > max)
				max = temp->index;
		}
		temp = temp->next;
	}
	info->pivo = (min + max) / 2;
}

static void	get_pivot(t_info *info)
{
	static int	blocks;
	static int	i;
	static int	div = 1;

	if (i == 0)
	{
		if (info->size_a >= 100 && info->size_a < 500)
			blocks = 5;
		else if (info->size_a >= 500)
			blocks = 11;
		else
			blocks = 1;
	}
	if (blocks != 1 && i < info->size_a)
	{
		if (i >= (info->size_a / blocks) * div)
			div++;
		info->pivo = (info->size_a / blocks) * div;
	}
	else
		get_pivot_1(info);
	i++;
}

void	bigger_stacks(t_info *info)
{
	g_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	get_pivot(info);
	temp = info->stack_a;
	while (temp->index > info->pivo)
	{
		temp = temp->next;
		i++;
	}
	temp = info->top_a;
	while (temp->index > info->pivo)
	{
		temp = temp->prev;
		j++;
	}
	if (j <= i || (j - 1) <= i)
		push_top(info, (j));
	else
		push_base(info, (i));
}