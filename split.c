#include "push_swap.h"

int	count_args_split(char **argv)
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}
int	*parse_split(char **argv, int argc)
{
	char	**split;
	int 	*input;
	int			i;

	i = 1;
	printf("argv[1]: %s\n", argv[1]);
	split = ft_split(argv[1], ' ');
	argc = count_args_split(split);
	input = malloc(sizeof(int) * argc);
	if (!input)
	{
		return(free_split(split), NULL);
	}
	int j = 0;
	while(split[i])
	{
		 printf("split[%d]: %s\n", j, split[j]);
			input[i] = ft_atol(split[i]);
			i++;
		j++;
	}
	free_split(split);
	return (input);
}
