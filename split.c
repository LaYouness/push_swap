#include <stdlib.h>
#include <stdio.h>

int count_w(const char *str)
{
	int status;
	int cw;

	cw = 0;
	status = 0;
	while (*str)
	{
		if(*str == ' ')
			status = 0;
		else if(status == 0)
		{
			status = 1;
			cw += 1;
		}
		str++;
	}
	return (cw);
}
void	free_all(char **words, int w_ind)
{
	while (--w_ind >= 0)
		free(words[w_ind]);
}
int	create_word(char **words, char *str, int w_ind)
{
	int wl;
	int i;

	wl = 0;
	while (str[wl] && str[wl] != ' ')
		wl++;
	words[w_ind] = malloc(sizeof(char) * (wl + 1));
	if (!words[w_ind])
		return(-1);
	i = 0;
	while (*str && *str != ' ')
		words[w_ind][i++] = *str++;
	words[w_ind][i] = 0;
	w_ind++;
	return (0);
}

char	**split(char *str)
{
	int w_ind;	
	int status;
	char **words;

	w_ind = 0;
	status = 0;
	words = malloc(sizeof(char *) * (count_w(str) + 1));
	if(!words)
		return(free_all(words, w_ind), NULL);
	while (*str)
	{
		if(*str == ' ')
			status = 0;
		else if(status == 0)
		{
			status = 1;
			if(create_word(words, str, w_ind) < 0)
				return(free_all(words, w_ind), NULL);
			w_ind++;
		}
		str++;
	}
	words[w_ind] = NULL;
	return(words);
}
