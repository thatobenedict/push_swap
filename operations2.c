/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:03:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/27 18:02:57 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	####ROTATE
 ** ra : rotate a - shift up all elements of stack a by 1.
 ** The first element becomes the last one.
 ** rb : rotate b - shift up all elements of stack b by 1.
 ** The first element becomes the last one.
 ** rr : ra and rb at the same time.
*/

void	ft_ra(t_ps	*stack)
{
	int i;
	int j;
	int temp;

	i = stack->a->top;
	j = 0;
	temp = stack->a->array[stack->a->top];
	while (i > 0)
	{
		stack->a->array[stack->a->top + j] =
			stack->a->array[stack->a->top + j - 1];
		i--;
		j++;
	}
	temp = stack->a->array[0];
}

/*
void	ft_rb(t_ps	*stack)
{
}

void	ft_rr(t_ps	*stack)
{
}



//####REVERSE ROTATE
// rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
//becomes the first one.
// rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
//becomes the first one.
// rrr : rra and rrb at the same time.
