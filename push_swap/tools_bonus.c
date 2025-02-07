#include "push_swap_bonus.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		i;
	size_t		len_s;

	i = 0;
	len_s = ft_strlen(s1);
	str = (char *)malloc ((len_s + 1));
	if (!str)
		return (NULL);
	while (i < len_s)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize <= 0)
		return (len);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}