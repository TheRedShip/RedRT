/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:42:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 14:42:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

char* load_file(char const* path)
{
	char* buffer = 0;
	long length = 0;
	FILE * f = fopen (path, "rb");

	if (f)
	{
	  fseek (f, 0, SEEK_END);
	  length = ftell (f);
	  fseek (f, 0, SEEK_SET);
	  buffer = (char*)malloc ((length+1)*sizeof(char));
	  if (buffer)
	  {
		fread (buffer, sizeof(char), length, f);
	  }
	  fclose (f);
	}
	else
		return (NULL);
	buffer[length] = '\0';

	return buffer;
}