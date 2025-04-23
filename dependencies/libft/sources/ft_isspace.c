/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:03:06 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/25 13:08:22 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	int		i;
	char	*spaces;

	i = 0;
	spaces = " \f\n\r\t\v";
	while (spaces[i])
	{
		if (c == spaces[i])
			return (c);
		else
			i++;
	}
	return (0);
}
