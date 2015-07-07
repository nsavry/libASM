/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 15:01:52 by mmeillan          #+#    #+#             */
/*   Updated: 2015/05/08 17:55:18 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

char	random_char()
{
	int		rad;
	int		rmd;

	rad = 1 + (int)(25.0 * rand() / (RAND_MAX + 1.0));
	rmd = ! + (int)(2.0 * rand() / (RAND_MAX + 1.0));
	rad += (rmd == 1) ? 'a' : 'A';
	if (isalpha(rad) == 0)
		rad = 'a';
	return (rad);
}

char	random_print_char()
{
	int		rad;

	rad = 0;
	while (isprint(rad) == 0)
	{
		rad = 1 + (int)(127.0 * rand() / (RAND_MAX + 1.0));
	}
	return (rad);
}

char	random_ascii()
{
	int		rad;

	rad = 0;
	while (isascii(rad) == 0)
	{
		rad = 1 + (int)(127.0 * rand() / (RAND_MAX + 1.0));
	}
	return (rad);
}

int		random_null()
{
	int		rad;
	int		ras;

	rad = 1 + (int)(26.0 * rand() / (RAND_MAX + 1.0));
	ras = 1 + (int)(26.0 * rand() / (RAND_MAX + 1.0));
	if (rad == ras)
		return (1);
	return (0);
}

int		random_num(float range)
{
	int		rad;

	rad = 1 + (int)(range * rand() / (RAND_MAX + 1.0));
	rad -= 1;
	return (rad);
}

int		make_num(float range)
{
	int		size;
	int		num;

	size = random_num(range + 1);
	if (size == 0)
		size = 1;
	num = 0;
	while (size)
	{
		num *= 10;
		num += random_num(10);
		size--;
	}
	return (num);
}

char	*random_string(int Dnull)
{
	char	*s;
	int		size;
	int		i;

	size = random_num(30.0) + 2;
	if (size <= 0)
		size = 2;
	s = malloc(sizeof(char) * (size * 3) );
	memset(s, 0, size * 3);
	s[size] = '\0';
	size--;
	if (Dnull == 1)
	{
		if (random_null() == 1)
			return (NULL);
	}
	i = 0;
	while (i < size)
	{
		s[i] = random_char();
		i++;
	}
	return (s);
}

int		main()
{
	char		*str1;
	char		*str2;
	char		*str3;
	char		*str4;
	char		*bak1;
	char		*bak2;
	char		*tstr;
	char		c;
	int			i;
	int			j;
	int			test;
	int			t1;
	int			t2;
	int			error;

	/*
	 * Reading STDOUT Variables
	*/
	int			out;
	int			p[2];
	int			len;
	char		*buf1;
	char		*buf2;

	srand (time(NULL));
	/*
	 * Begining test
	*/
	printf("### BEGINING TESTING ###\n");
	/*
	 * BZERO
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING BZERO ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		str1 = random_string(0);
		str2 = strdup(str1);
		bak1 = strdup(str1);
		i = random_num(10.0);
		ft_bzero(str1, i);
		bzero(str2, i);
		if (strcmp(str1, str2) != 0)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> bzero(\"%s\", %d) returned : \"%s\"\n",bak1, i, str2);
			printf("  -> ft_bzero(\"%s\", %d) returned : \"%s\"\n",bak1, i, str1);
		}
		free(str1);
		free(str2);
		free(bak1);
		j++;
	}
	if (error <= 0)
		printf("   # BZERO :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # BZERO :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * STRCAT
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING STRCAT ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		tstr = random_string(0);
		str1 = malloc(sizeof(char) * 1000);
		memset(str1, 0, 1000);
		str1 = strcpy(str1, tstr);
		str2 = random_string(0);
		str3 = malloc(sizeof(char) * 1000);
		memset(str3, 0, 1000);
		str3 = strcpy(str3, tstr);
		str4 = strdup(str2);
		bak1 = malloc(sizeof(char) * 1000);
		memset(bak1, 0, 1000);
		bak1 = strcpy(bak1, tstr);
		bak2 = strdup(str2);
		str1 = ft_strcat(str1, str2);
		str3 = strcat(str3, str4);
		if (strcmp(str1, str3) != 0)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> strcat(\"%s\", \"%s\") returned : \"%s\"\n",bak1, bak2, str3);
			printf("  -> ft_strcat(\"%s\", \"%s\") returned : \"%s\"\n",bak1, bak2, str1);
		}
		free(str1);
		free(str2);
		free(str3);
		free(str4);
		free(bak1);
		free(bak2);
		free(tstr);
		j++;
	}
	if (error <= 0)
		printf("   # STRCAT :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # STRCAT :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * ISALPHA
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING ISALPHA ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (isalpha(c) != ft_isalpha(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> isalpha(\"%c\") returned : \"%d\"\n", c, isalpha(c));
			printf("  -> ft_isalpha(\"%c\") returned : \"%d\"\n", c, ft_isalpha(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # ISALPHA :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # ISALPHA :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * ISDIGIT
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;

	printf("   -> TESTING ISDIGIT ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (isdigit(c) != ft_isdigit(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> isdigit(\"%c\") returned : \"%d\"\n", c, isdigit(c));
			printf("  -> ft_isdigit(\"%c\") returned : \"%d\"\n", c, ft_isdigit(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # ISDIGIT :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # ISDIGIT :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * ISALNUM
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING ISALNUM ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (isalnum(c) != ft_isalnum(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> isalnum(\"%c\") returned : \"%d\"\n", c, isalnum(c));
			printf("  -> ft_isalnum(\"%c\") returned : \"%d\"\n", c, ft_isalnum(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # ISALNUM :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # ISALNUM :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * ISASCII
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING ISASCII ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (isascii(c) != ft_isascii(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> isascii(\"%c\") returned : \"%d\"\n", c, isascii(c));
			printf("  -> ft_isascii(\"%c\") returned : \"%d\"\n", c, ft_isascii(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # ISASCII :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # ISASCII :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * ISPRINT
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING ISPRINT ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (isprint(c) != ft_isprint(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> isprint(\"%c\") returned : \"%d\"\n", c, isprint(c));
			printf("  -> ft_isprint(\"%c\") returned : \"%d\"\n", c, ft_isprint(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # ISPRINT :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # ISPRINT :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * TOUPPER
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING TOUPPER ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (toupper(c) != ft_toupper(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> toupper(\"%c\") returned : \"%d\"\n", c, toupper(c));
			printf("  -> ft_toupper(\"%c\") returned : \"%d\"\n", c, ft_toupper(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # TOUPPER :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # TOUPPER :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * TOLOWER
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING TOLOWER ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		c = make_num(3.0);
		if (tolower(c) != ft_tolower(c))
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> tolower(\"%c\") returned : \"%d\"\n", c, tolower(c));
			printf("  -> ft_tolower(\"%c\") returned : \"%d\"\n", c, ft_tolower(c));
		}
		j++;
	}
	if (error <= 0)
		printf("   # TOLOWER :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # TOLOWER :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * PUTS
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING PUTS ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		str1 = random_string(1);
		if (str1)
			len = strlen(str1);
		else
			len = 100;
		buf1 = malloc(sizeof(char) * (len * 2));
		buf2 = malloc(sizeof(char) * (len * 2));
		memset(buf1, 0, len * 2);
		memset(buf2, 0, len * 2);
		out = dup(1);
		pipe(p);
		dup2(p[1], 1);
		t1 = ft_puts(str1);
		dup2(out, 1);
		read(p[0], buf1, len * 2);
		buf1[len] = '\0';
		close(p[0]);
		close(p[1]);
		close(out);

		out = dup(1);
		pipe(p);
		dup2(p[1], 1);
		t2 = puts(str1);
		dup2(out, 1);
		read(p[0], buf2, len * 2);
		buf2[len] = '\0';
		close(p[0]);
		close(p[1]);
		close(out);

		str2 = strdup(buf1);
		str3 = strdup(buf2);

		free(buf2);
		free(buf1);

		if (t1 != t2 || strcmp(str2, str3) != 0)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> puts(\"%s\") returned : \"%d\"\n", str1, t2);
			printf("  -> and printed : '%s'\n", str3);
			printf("  -> ft_puts(\"%s\") returned : \"%d\"\n", str1, t1);
			printf("  -> and printed : '%s'\n", str2);
		}
		free(str1);
		j++;
	}
	if (error <= 0)
		printf("   # PUTS :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # PUTS :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	/*
	 * STRLEN
	*/
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING STRLEN ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		str1 = random_string(0);
		t1 = strlen(str1);
		t2 = ft_strlen(str1);
		if (t1 != t2)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> strlen(\"%s\") returned : \"%d\"\n", str1, t1);
			printf("  -> ft_strlen(\"%s\") returned : \"%d\"\n", str1, t2);
		}
		j++;
	}
	if (error <= 0)
		printf("   # STRLEN :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # STRLEN :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING MEMSET ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		str1 = random_string(0);
		str2 = malloc(sizeof(char) * 1000);
		str2 = strcpy(str2, str1);
		bak1 = strdup(str1);
		len = ft_strlen(str1);
		c = random_char();
		i = random_num(len);
		ft_memset(str1, c, i);
		memset(str2, c, i);
		if (strcmp(str1, str2) != 0)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> memset(\"%s\", %c, %d) returned : \"%s\"\n",bak1, c, i, str2);
			printf("  -> ft_memset(\"%s\", %c, %d) returned : \"%s\"\n",bak1, c, i, str1);
		}
		free(str1);
		free(str2);
		free(bak1);
		j++;
	}
	if (error <= 0)
		printf("   # MEMSET :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # MEMSET :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING MEMCPY ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		str1 = random_string(0);
		str2 = malloc(sizeof(char) * 1000);
		memset(str2, 0, 1000);
		str3 = malloc(sizeof(char) * 1000);
		memset(str3, 0, 1000);
		len = ft_strlen(str1);
		i = random_num(len);
		ft_memcpy(str2, str1, i);
		memcpy(str3, str1, i);
		if (strcmp(str2, str3) != 0)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> memcpy(\"\", %s, %d) returned : \"%s\"\n", str1, i, str3);
			printf("  -> ft_memcpy(\"\", %s, %d) returned : \"%s\"\n", str1, i, str2);
		}
		free(str1);
		free(str2);
		free(str3);
		j++;
	}
	if (error <= 0)
		printf("   # MEMCPY :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # MEMCPY :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	

	i = 10;
	j = 0;
	error = 0;
	test = 0;
	printf("   -> TESTING STRDUP ");
	while (i > 0)
	{
		(void)make_num(10.0);
		i--;
	}
	while (test < 100 || test > 800)
	{
		test = make_num(3.0);
	}
	printf("(%d tests)\n", test);
	while (j < test)
	{
		str1 = random_string(0);
		str2 = ft_strdup(str1);
		str3 = strdup(str1);
		if (strcmp(str2, str3) != 0)
		{
			error++;
			printf(" -ERROR ON TEST-\n");
			printf("  -> strdup(%s) returned : \"%s\"\n", str1, str3);
			printf("  -> ft_strdup(%s) returned : \"%s\"\n", str1, str2);
		}
		free(str1);
		free(str2);
		free(str3);
		j++;
	}
	if (error <= 0)
		printf("   # STRDUP :\t\033[32;01mSUCCESS\033[00m\n");
	else
	{
		printf("   # STRDUP :\t\033[31;01mFAILL\033[00m\n");
		printf("     -> %d fail(s) over %d tests\n", error, test);
	}
	return (0);
}
