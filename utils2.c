#include "parsing.h"

void	ft_freeing(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_cheking_ns(int n_s, char **vv)
{
	if (n_s != 2)
	{
		ft_freeing(vv);
		return (-1);
	}
	return (1);
}

int	ft_cheking_fc_utils(char **vv)
{
	int	i;
	int	n_s;

	i = 0;
	n_s = 0;
	while (vv[1][i])
	{
		if (vv[1][i] == ',')
			n_s++;
		i++;
	}
	if (ft_cheking_ns(n_s, vv) == -1)
		return (-1);
	return (1);
}

int	ft_cheking_fc(char **arr, int i)
{
	char	**vv;

	if (ft_count(arr[i], ' ') != 2)
		return (-1);
	vv = ft_split(arr[i], ' ');
	if (ft_cheking_fc_utils(vv) == -1)
		return (-1);
	ft_freeing(vv);
	return (1);
}

int	ft_checking_the_four(char **arr)
{
	char	*coor[4];
	int 	i;
	int 	flag;
	int 	j;
	int k;
	
	coor[0] = "NO";
	coor[1] = "SO";
	coor[2] = "WE";
	coor[3] = "EA";

	i = 0;
	flag = 0;
	while (i < 6)
	{
		k = 0;
		j = 0;
		while (arr[i][k] == 32 || (arr[i][k] >= 9 && arr[i][k] <= 13))
			k++;
		if(arr[i][k] == 'F' || arr[i][k] == 'C')
		{
			if (ft_cheking_fc(arr,i) == -1)
				return (-1);
			flag++;
		}
		else
		{
			while (j < 4)
			{
				if(!ft_strncmp(&arr[i][k],coor[j] ,2))
				{ 
					if (ft_cheking_nsew(arr,i) == -1)
						return (-1);
					else
					{
						flag++;
						j = 4;
					}
				}
				j++;
			}
		}
		i++;
	}
	if(flag != 6)
		return -1;
	return (1);
}
