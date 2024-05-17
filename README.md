# ft_strjoinでmallocの中身をエラーハンドリングした方がいいかも

char	*ft_strjoin(char *leftover, char *buf)
{
	char	*result;
	size_t	leftover_len;
	size_t	buf_len;
	size_t	total_len;

	if (leftover == NULL && buf == NULL)
		return (NULL);
	leftover_len = ft_strlen(leftover);
	buf_len = ft_strlen(buf);
	total_len = leftover_len + buf_len;
	if (total_len < leftover_len
		|| total_len < buf_len || total_len > SIZE_MAX || total_len > INT_MAX)
		return (NULL);
	//result = (char *)malloc((leftover_len + buf_len + 1));
	result = malloc(total_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, leftover);
	ft_strcpy(result + leftover_len, buf);
	return (result);
}
