

static char *sort_lv1(t_cursor *head, char *order)
{
	int	big_idx;

	big_idx = stack_circle(&head->cur_a);
	if (head->cur_a->idx == big_idx)
		return (ra(head, order));
	if (head->cur_a->priv->idx == 0)
		return (rra(head, order));
	if (head->cur_a->priv->idx == big_idx)
		return (sa(head, order));
	return (order);
}

static char *sort_lv2(t_cursor *head, char *order)
{
	int	big_idx;

	big_idx = stack_circle(&head->cur_a);
	if (head->cur_a->priv->idx == 1)
		return (rra(head, order));
	if (head->cur_a->idx == big_idx)
		return (ra(head, order));
	else
		return (sa(head, order));
	return (order);
}

static char *sort_lv3(t_cursor *head, char *order)
{
	int	big_idx;

	big_idx = stack_circle(&head->cur_a);
	if (head->cur_a->priv->idx == 1)
		return (rra(head, order));
	if (head->cur_a->idx == big_idx)
		return (ra(head, order));
	else
		return (sa(head, order));
	return (order);
}
