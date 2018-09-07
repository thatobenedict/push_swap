#include "push.h"

// remember to add ft_abs and ft_absdiff to your library

int	ft_abs(int a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

int	ft_absdiff(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

int	rot_score(t_stack *stack)
{
	int score;
	int diff;

	score = 0;
	if (ret_index(who_min(stack), stack) > stack->top / 2)
		diff = stack->top - ret_index(who_min(stack), stack);
	else
		diff = ret_index(who_min(stack), stack) + 1;
	while (--diff >= 0)
	{
		if (ret_index(who_min(stack), stack) > stack->top / 2)
			score++;
		else
			score--;
	}
	return (score)
}
/*
 ** =This function seeks to find out the true number of rotations required to achieve the correct pb
 */
int	real_rot(int a, int b)
{
	if (a < 0 && b < 0)
		return (ft_absdiff(ft_abs(a),ft_abs(b)) + ft_ismin(ft_abs(a),ft_abs(b)));
	else if (a > 0 && b > 0)
		return (ft_absdiff(a, b) + ft_ismin(a, b));
	else
		return (ft_abs(a),ft_abs(b));
}

void	store_top(t_ps *ps)
{
	if (a < 0 && b < 0)
		return (ft_absdiff(ft_abs(a),ft_abs(b)) + ft_ismin(ft_abs(a),ft_abs(b)));
	else if (a > 0 && b > 0)
		return (ft_absdiff(a, b) + ft_ismin(a, b));
	else
		return (ft_abs(a),ft_abs(b));
}

//remember to send the first two then sort them biggest to smallest
void	dynamic_sort(t_ps *ps)
{
	int i;
	int j;
	int score;

	do_pb(ps);
	do_pb(ps);
	i = ps->b->top + 1;
	while (--i >= 0)
	{
		j = ps->a->top + 1;
		while (--j >= 0)
		{
			score = real_rot(rot_score(ps->a), rot_score(ps->b));
			if (score < ps->score->top)
			{

			}			
		}
	}	
}
