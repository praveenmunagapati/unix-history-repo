/*
 * protos.h -- function prototypes for when the headers don't have them.
 */

/* 
 * Copyright (C) 1991, 1992, 1993 the Free Software Foundation, Inc.
 * 
 * This file is part of GAWK, the GNU implementation of the
 * AWK Progamming Language.
 * 
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GAWK; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifdef __STDC__
#define aptr_t void *	/* arbitrary pointer type */
#else
#define aptr_t char *
#endif
extern aptr_t malloc P((MALLOC_ARG_T));
extern aptr_t realloc P((aptr_t, MALLOC_ARG_T));
extern aptr_t calloc P((MALLOC_ARG_T, MALLOC_ARG_T));

#if !defined(sun) && !defined(__sun__)
extern void free P((aptr_t));
#endif
extern char *getenv P((const char *));

extern char *strcpy P((char *, const char *));
extern char *strcat P((char *, const char *));
extern int strcmp P((const char *, const char *));
extern char *strncpy P((char *, const char *, size_t));
extern int strncmp P((const char *, const char *, size_t));
#ifndef VMS
extern char *strerror P((int));
#else
extern char *strerror P((int,...));
#endif
extern char *strchr P((const char *, int));
extern char *strrchr P((const char *, int));
extern char *strstr P((const char *s1, const char *s2));
extern size_t strlen P((const char *));
extern long strtol P((const char *, char **, int));
#if !defined(_MSC_VER) && !defined(__GNU_LIBRARY__)
extern size_t strftime P((char *, size_t, const char *, const struct tm *));
#endif
#ifdef __STDC__
extern time_t time P((time_t *));
#else
extern long time();
#endif
extern aptr_t memset P((aptr_t, int, size_t));
extern aptr_t memcpy P((aptr_t, const aptr_t, size_t));
extern aptr_t memmove P((aptr_t, const aptr_t, size_t));
extern aptr_t memchr P((const aptr_t, int, size_t));
extern int memcmp P((const aptr_t, const aptr_t, size_t));

extern int fprintf P((FILE *, const char *, ...));
#if !defined(MSDOS) && !defined(__GNU_LIBRARY__)
#ifdef __STDC__
extern size_t fwrite P((const aptr_t, size_t, size_t, FILE *));
#else
extern int fwrite();
#endif
extern int fputs P((const char *, FILE *));
extern int unlink P((const char *));
#endif
extern int fflush P((FILE *));
extern int fclose P((FILE *));
extern FILE *popen P((const char *, const char *));
extern int pclose P((FILE *));
extern void abort P(());
extern int isatty P((int));
extern void exit P((int));
extern int system P((const char *));
extern int sscanf P((const char *, const char *, ...));
#ifndef toupper
extern int toupper P((int));
#endif
#ifndef tolower
extern int tolower P((int));
#endif

extern double pow P((double x, double y));
extern double atof P((const char *));
extern double strtod P((const char *, char **));
extern int fstat P((int, struct stat *));
extern int stat P((const char *, struct stat *));
extern off_t lseek P((int, off_t, int));
extern int fseek P((FILE *, long, int));
extern int close P((int));
extern int creat P((const char *, mode_t));
extern int open P((const char *, int, ...));
extern int pipe P((int *));
extern int dup P((int));
extern int dup2 P((int,int));
extern int fork P(());
extern int execl P((/* char *, char *, ... */));
#ifndef __STDC__
extern int read P((int, char *, int));
#endif
extern int wait P((int *));
extern void _exit P((int));

#ifdef NON_STD_SPRINTF
extern char *sprintf P((char *, const char*, ...));
#else
extern int sprintf P((char *, const char*, ...));
#endif /* SPRINTF_INT */

#undef aptr_t
