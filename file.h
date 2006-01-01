/* 
 * Copyright 2005 Timo Hirvonen
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef _FILE_H
#define _FILE_H

#include <unistd.h>
#include <sys/mman.h>

ssize_t read_all(int fd, void *buf, size_t count);
ssize_t write_all(int fd, const void *buf, size_t count);
char **bsplit(const char *buffer, unsigned int size, char ch, unsigned int limit);

char *mmap_file(const char *filename, int *size);
void buffer_for_each_line(const char *buf, int size,
		int (*cb)(void *data, const char *line),
		void *data);
void buffer_for_each_line_reverse(const char *buf, int size,
		int (*cb)(void *data, const char *line),
		void *data);
int file_for_each_line(const char *filename,
		int (*cb)(void *data, const char *line),
		void *data);

#endif