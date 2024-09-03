/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:52:37 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/03 15:08:27 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_SIZE 2048
#define ERROR -1
#define TRUE 1
#define FALSE 0

char	*get_numbers(char *str, char *buffer)
{
	int	i;
	int	buf_idx;

	i = 0;
	buf_idx = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\t'
				|| str[i] == '+' || str[i] == '-'))
			break ;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			buffer[buf_idx++] = str[i++];
		else
			break ;
	}
	buffer[buf_idx] = '\0';
	return (buffer);
}

char	*get_signs(char *str, char *buffer)
{
	int	i;
	int	buf_idx;

	i = 0;
	buf_idx = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\t'))
			break ;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] <= '-')
			buffer[buf_idx++] = str[i++];
		else
			break ;
	}
	buffer[buf_idx] = '\0';
	return (buffer);
}

int	evaluate_signs(char *signs)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = 0;
	while (signs[i])
	{
		if (signs[i] == '-')
			s_len++;
		i++;
	}
	if (s_len % 2 == 1)
		return (TRUE);
	return (FALSE);
}

int	convert_str_nbr(char *numbers, int is_negative)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (numbers[i] != '\0')
	{
		result *= 10;
		result += numbers[i] - '0';
		i++;
	}
	if (is_negative == TRUE)
		result *= -1;
	return (result);
}

int	ft_atoi(char *str)
{
	int		result;
	int		is_negative;
	char	signs[MAX_SIZE];
	char	numbers[MAX_SIZE];

	result = 10;
	is_negative = 0;
	if (get_numbers(str, numbers)[0] == '\0')
		return (FALSE);
	get_signs(str, signs);
	is_negative = evaluate_signs(signs);
	if (is_negative == ERROR)
		return (FALSE);
	result = convert_str_nbr(numbers, is_negative);
	return (result);
}
