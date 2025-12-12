#include "push_swap.h"

int main(int  arc, char **arv)
{
	int		*values;
	int		i;
	t_stack	a;
	t_stack	b;

	if (arc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	int len = arc -1;
	values = parse_params(&arv[1], &len);
	initialize_stack(&a, len);
	initialize_stack(&b, len);
	i = len;
	while (i--)
		push_on_stack(&a, values[i]);

    free(a.array);
    free(b.array);
	free(values);
	return (EXIT_SUCCESS);
}
