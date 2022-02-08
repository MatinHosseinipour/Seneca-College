/* DIGITAL SIGNATURE(S): MATIN_HP
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Matin Hosseini Pour	smmhosseini-pour@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   |  !!!      DO NOT ALTER THE CONTENTS BELOW         !!!  |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include "file_helper.h"

/********************************************************/
/* Read from the opened file the time (HH:MM) parts of  */
/* the record and return the time as decimal hours      */
/********************************************************/
double readTime(FILE* fp)
{
	int hour, min;

	fscanf(fp, "%d%*c", &hour);
	fscanf(fp, "%d", &min);

	return hour + (min / 60.0);
}

/********************************************************/
/* Read all the information on one skier from the valid */
/* (pre-opened) file and store it in the struct.        */
/* Return true when end of file has been reached.       */
/********************************************************/
int readFileRecord(FILE* fp, struct SkierInfo* info)
{
	int result = 1, ch;

	if (!feof(fp))
	{
		result = 0;
		
		// read from file and assign to data structure
		fscanf(fp, "%[^,]%*c", info->name);
		fscanf(fp, "%d", &info->age);
		fscanf(fp, " %c", &info->section);
		info->Time_Started = readTime(fp);
		info->Time_MidWay = readTime(fp);
		info->Time_Finished = readTime(fp);
		
		// Last Field (withdrawn: may not be present)
		ch = fgetc(fp);
		info->withdrawn = 0;

		if (ch == ' ') 
		{
			ch = fgetc(fp);
			info->withdrawn = ch == 'W';
			ch = fgetc(fp);
		}
		
		// clear input file buffer until end of line (record):
		while (!feof(fp) && ch != '\n')
		{
			ch = fgetc(fp);
		}
	}

	return result;
}