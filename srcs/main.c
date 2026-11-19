#include "push_swap.h"

int	main(int arc, char **arv)
{
	int		*values;
	int		i;
	t_stack	a;
	t_stack	b;
	int		len;

	if (arc < 2)
		exit(EXIT_FAILURE);
	len = arc - 1;
	values = parse_params(&arv[1], &len);
	initialize_stack(&a, len);
	initialize_stack(&b, len);
	i = len;
	while (i--)
		push_on_stack(&a, values[i]);
	if (special_case(&a, &b))
		return (free(a.array), free(b.array), free(values), EXIT_SUCCESS);
	sort_a_stack(&a, &b);
	replace_value_in_stack(&a, &b);
	min_to_top(&a);
	free(a.array);
	return (free(values), free(b.array), EXIT_SUCCESS);
}
