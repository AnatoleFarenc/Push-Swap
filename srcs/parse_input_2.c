#include "push_swap.h"

int	*parse_params(char **params, int *len)
{
	char	**params_arr;
	char	*params_str;
	int		*params_int;

	params_str = join_params(params, *len);
	params_arr = ft_split(params_str, ' ');
	free(params_str);
	check_params(params_arr);
	*len = ft_str_array_len(params_arr);
	params_int = convert_num(params_arr);
	check_duplicate(params_arr, params_int, *len);
	free_arrays(params_arr);
	return (params_int);
}
