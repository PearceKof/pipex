/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:41:56 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/20 15:41:56 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (1 + ft_lstsize(lst->next));
	else
		return (0);
}

// int main() {
//   char str1[6] = "test1";
//   char str2[6] = "test2";
//   t_list **alst[13];
//   size_t *lst1 = ft_lstnew(str1);
//   size_t *lst2 = ft_lstnew(str2);
//   *alst = lst1;
//   ft_lstadd_front(alst, lst2);
//   printf("%d", ft_lstsize(lst1));
// }