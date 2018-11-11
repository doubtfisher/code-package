#include <stdio.h>
#include "CommentConvert.h"

void CommentConvert(FILE* pfRead, FILE* pfWrite)
{
	State state = NUL_STATE;
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
			DoNulState(pfRead, pfWrite, &state);
			break;
		case C_STATE:
			DoCState(pfRead, pfWrite, &state);
			break;
		case CPP_STATE:
			DoCppState(pfRead, pfWrite, &state);
			break;
		default:
			break;
		}
	}

}

void DoNulState(FILE* pfRead, FILE* pfWrite, State* ps)//Õý³£×´Ì¬
{
	int  first = fgetc(pfRead);
	switch (first)
	{
	case '/':
	{
				int second = fgetc(pfRead);
				switch (second)
				{
				case '*':
				{
							*ps = C_STATE;
							fputc('/', pfWrite);
							fputc('/', pfWrite);
							
				}
					break;
				case '/':
				{
							*ps = CPP_STATE;
							fputc(first, pfWrite);
							fputc(second, pfWrite);
				}
					break;
				default:
				{
						   fputc(first, pfWrite);
						   fputc(second, pfWrite);
				}
					break;

				}
	}
		break;
	case EOF:
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfWrite);
		break;
	}

}

void DoCState(FILE* pfRead, FILE* pfWrite, State* ps)//c×¢ÊÍ×´Ì¬
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '*':
	{
				int second = fgetc(pfRead);
				if (second == '/')
				{
					int third = fgetc(pfRead);
					*ps = NUL_STATE;
					if (third != '\n')
					{
						fputc('\n', pfWrite);
						ungetc(third, pfRead);
					}
					if (third == '\n')
					{
						fputc(third, pfWrite);
					}
				}
				else
				{
					fputc(first, pfWrite);
					ungetc(second, pfRead);
				}
	}
				
		break;
			
	case '\n':
	{
				 fputc(first, pfWrite);
				 fputc('/', pfWrite);
				 fputc('/', pfWrite);
	}
		break;
	default:
	{
			   fputc(first, pfWrite);
	}
		break;
	}

}



void DoCppState(FILE* pfRead, FILE* pfWrite, State* ps)//c++×´Ì¬
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '\n':
	{
				 *ps = NUL_STATE;
				 fputc(first, pfWrite);

	}
		break;
	case EOF:
	{
				*ps = END_STATE;
	}
		break;
	default:
	{
			   fputc(first, pfWrite);
	}
		break;
	}
}
