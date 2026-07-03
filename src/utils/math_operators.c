int	int_sqrt_ceil(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}