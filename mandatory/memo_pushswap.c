
sa 1 0 2 3

	6 - 4
	2
	0/12345
	6
	01/23/45
	7
	01/23/456
	8
	01/234/567

	5 = 0/0/5
	---------
	6 = 0/1/5	: pv1 = 1 / pv2 = 1
	7 = 1/1/5	: pv1 = 1 / pv2 = 2
	8 = 1/2/5	: pv1 = 2 / pv2 = 3
	9 = 2/2/5	: pv1 = 2 / pv2 = 4
	10 = 2/3/5	:
	11 = 3/3/5
	12 = 3/4/5
	13 = 4/4/5
	14 = 4/5/5 12 2
	15 = 5/5/5
	==========
	16 = 5/5/6
	17 = 6/5/6
	18 = 6/6/6

	7 - 5 = 2    /2 =1
	6 - 5 = 1	/2 = 0

limit == 3
	5 = 1/1/3
	6 = 1/2/3	: pv1 = 1 / pv2 = 1
	7 = 1/1/5	: pv1 = 1 / pv2 = 2
	8 = 1/2/5	: pv1 = 2 / pv2 = 3
	9 = 2/2/5	: pv1 = 2 / pv2 = 4
	10 = 2/3/5	:
	11 = 3/3/5
	12 = 3/4/5
	13 = 4/4/5
	14 = 4/5/5 12 2
	15 = 5/5/5





2022.07.20
	20		21		22
	pv1				pv2

	3 -> 5
	cnt_b == 21
	19


		23 24 25 26



/* void ft_info() */
/* { */
	/* ft_printf("-----------------------"); */
	/* ft_printf("< push swap simulator >"); */
	/* ft_printf("-----------------------"); */
	/* ft_printf("push swap 명령어 : ra, rb, pa, pb, sa, sb, ss, rra, rrb, rrr\n"); */
/* } */

/* char	*ft_charjoin(char *s, char c) */
/* { */
	/* char	*pt; */
	/* int		len; */

	/* if (!s || !c) */
		/* return (NULL); */
	/* len = ft_strlen(s) + 1; */
	/* pt = (char *)malloc(sizeof(char) * (len + 1)); */
	/* if (!pt) */
		/* return (NULL); */
	/* pt[len] = '\0'; */
	/* ft_strlcpy(pt, s, len + 1); */
	/* pt[len - 1] = c; */
	/* free(s); */
	/* return (pt); */
/* } */
