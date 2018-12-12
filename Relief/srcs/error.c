#include "libft.h"
#include "error.h"

int error(int num)
{
	if (num>1)
	{
		ft_putnbr_fd(num, 2);
		return (E_ERROR);
	}
	return (num);
}
