// This C code contains all the functionalities of the Linux based UI that we have developed

#include "Memfree.h" // including the .h file for memfree() function call

/* memfree() - Function to free the allocated memory space */

void memfree(void)
{
	if(mem_ptr)
	{
		free(mem_ptr);
		printf("\nThe allocated memory has been successfully freed...\n");
		printf("\nThanks for freeing the allocated memory...\n");
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory was freed...\n");
	}
}
#include "Memread.h" // including the .h file for memread() function call

/* memread() - Function required to read a specified memory location within the allocated memory space on the user's request */

uint32_t *mem_ptr2, mem_i;

void memread(void)
{
	if(mem_ptr)
	{
		if(relative_address)
		{
			value1 = (value1 * 4) + (uint64_t)mem_ptr;
		}
		mem_ptr2 = (uint32_t *) value1;
		if(mem_ptr2)
		{
			Boundary_Check();
			if((boundary_error == 1) && (b_proceed == 0))
			{
				printf("\nProcess Terminated\n");
			}
			else
			{
				Detailed_Output();
				if(print)
				{
					printf("\nThe allocated addresses are as below:\n");
					for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
					{
						printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
					}
				}
				mem_ptr = mem_original;
				printf("\nThe hex data at the specified location %p is %x\n", mem_ptr2, *mem_ptr2);
				printf("\nThanks for reading from an allocated memory location...\n");
			}
		}
		else
		{
			Null_Ptr();
		}
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory can be read...\n");
	}
}
#include "Memalloc.h" // including the .h file for memalloc() function call

uint32_t *mem_ptr, mac_i, mem_max, *mem_original;

void mem_clear(void) // Intrinsic function to clear the pointer data values in order for smooth transition in the later part of the code
{
	for(mac_i = 0; mac_i < value1; mac_i ++)
	{
		*mem_ptr = 0x00000000;
	}
}

/* memalloc() - Function required to request for memory allocation as per the user's specifications  */

void memalloc(void)
{
	mem_max = value1;
	mem_ptr = (uint32_t *) malloc (value1);
	mem_original = mem_ptr;
	mem_clear();
	Detailed_Output();
	if(print)
	{
		printf("\nThe allocated addresses are as below:\n");
		for(mac_i = 0; mac_i < mem_max; mac_i ++, mem_ptr ++)
		{
			printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mac_i, mem_ptr, *mem_ptr);
		}
	}
	mem_ptr = mem_original;
	printf("\n\nThanks for executing the memory allocation operation...\n");	
}
#include "Help.h" // inclusion of the help.h file which contains code on the execution of help terminal instruction in the execution on the Linux platform

const char h[] = "help";
const char hd[] = "\n\nDirections to use help command:\nPut a whitespace after help and then type the command\nTo get information on using that command\nFor example - type: help exit\n\nList of valid Commands:\n";
const char h1[] = "exit";
const char h2[] = "memalloc";
const char h3[] = "memfree";
const char h4[] = "memwrite";
const char h5[] = "memread";
const char h6[] = "meminv";
const char h7[] = "patterngen";
const char h8[] = "patternverify";
const char hre[] = "\nCommand not recognized\n";
const char hr1[] = "\nexit: \nType exit to close the program\n";
const char hr2[] = "\nMemory Allocation:\n\nType memalloc and then enter the\nnumber of memory locations that you want\nto use and have access to.\n\nAlternatively, type memalloc <number> without <> for value\n";
const char hr3[] = "\nMemory Free:\nType memfree to release the \npreviously allocated memory locations\n";
const char hr4[] = "\nMemory Write:\nType memwrite and then enter the address and data\nto write 32bit data at memory location of your choice.\n\nAlternatively, type memwrite <address> <data> without <> for values\n";
const char hr5[] = "\nMemory Read:\nType memread to read 32bit data in hex\nat memory location of your choice.\n\nAlternatively, type memread <address> without <> for value\n";
const char hr6[] = "\nMemory Inverse:\nType meminv to invert all bits of a\n32bit memory block at location of your choice\n";
const char hr7[] = "\nPsuedo Random Pattern Generation:\nType patterngen and then enter maximum value,\nseed, number of 32bits words that you wish to generate,\nand starting memory location to store the pattern\nto generate multiple psuedo random numbers.\n\nAlternatively, type patterngen <starting memory address> <length of pattern> <seed> <maxvalue>\nwithout <> for values\n";
const char hr8[] = "\nPsuedo Random Pattern Verification:\nType patternverify and then enter maximum value,\nseed, number of 32bits words that you wish to verify,\nand starting memory location pointing to the stored pattern\nto verify multiple psuedo random numbers.\n\nAlternatively, type patternverify <starting memory address> <length of pattern> <seed> <maxvalue>\nwithout <> for values\n";


char help_print[500], help_array[500];
uint8_t help_i, help_j, help_k;

void (*Help_Func_Ptr[8]) (void) = 
								{
									Help_Response1,
									Help_Response2,
									Help_Response3,
									Help_Response4,
									Help_Response5,
									Help_Response6,
									Help_Response7,
									Help_Response8
								};

void Help_Response1(void)
{
	printf("%s",hr1);
}

void Help_Response2(void)
{
	printf("%s",hr2);
}

void Help_Response3(void)
{
	printf("%s",hr3);
}

void Help_Response4(void)
{
	printf("%s",hr4);
}

void Help_Response5(void)
{
	printf("%s",hr5);
}
void Help_Response6(void)
{
	printf("%s",hr6);
}

void Help_Response7(void)
{
	printf("%s",hr7);
}

void Help_Response8(void)
{
	printf("%s",hr8);
}

void Help_Init(void)
{
	help_j = 0;
	help_k = 0;
	while(h1[help_k] != 0)
	{
		help_array[help_j] = h1[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h2[help_k] != 0)
	{
		help_array[help_j] = h2[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h3[help_k] != 0)
	{
		help_array[help_j] = h3[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h4[help_k] != 0)
	{
		help_array[help_j] = h4[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h5[help_k] != 0)
	{
		help_array[help_j] = h5[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h6[help_k] != 0)
	{
		help_array[help_j] = h6[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h7[help_k] != 0)
	{
		help_array[help_j] = h7[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
	help_j += 1;
	help_k = 0;
	while(h8[help_k] != 0)
	{
		help_array[help_j] = h8[help_k];
		help_j += 1;
		help_k += 1;
	}
	help_array[help_j] = 0;
}

void Help_Display(void)
{
	printf("%s",hd);
	printf("\n\t%s",h);
	printf("\n\t%s",h1);
	printf("\n\t%s",h2);
	printf("\n\t%s",h3);
	printf("\n\t%s",h4);
	printf("\n\t%s",h5);
	printf("\n\t%s",h6);
	printf("\n\t%s",h7);
	printf("\n\t%s",h8);
	printf("\n");
}

void Help_Lookup(void)
{
	help_i = 0;
	for(help_k = 0; help_k < Number_of_Help_Functions; help_k ++)//Number_of_Help_Functions
	{
		help_j = 0;
		while((help_array[help_i] != 0) && (input2[help_j] != 0))
		{
			if(help_array[help_i] == input2[help_j])
			{
				help_j += 1;
				help_i += 1;
			}
			else
			{
				break;
			}
		}
		if((help_array[help_i] == 0) && (input2[help_j] == 0))
		{
			(*Help_Func_Ptr[help_k])();
			break;
		}
		else
		{
			while(help_array[help_i] != 0)
			{
				help_i += 1;
			}
			if(help_k == (Number_of_Help_Functions - 1))	
			{
				printf("%s",hre);
			}
		}
		help_i += 1;
	}
}



#include "Meminv.h" // including the .h file for meminv() function call

uint32_t *mem_ptr2, mem_i;

clock_t t; // starting the clock for calculating the time taken by the system for the execution of the XORing function

/* meminv() - Function required to invert (XOR) the existing/stored data at a user specified memory location */

void meminv(void)
{
	if(mem_ptr)
	{
		mem_ptr = mem_original;
		if(relative_address)
		{
			value1 = (value1 * 4) + (uint64_t)mem_ptr;
		}
		mem_ptr2 = (uint32_t *) value1;
		if(mem_ptr2)
		{
			Boundary_Check();
			if((boundary_error == 1) && (b_proceed == 0))
			{
				printf("\nProcess Terminated\n");
			}
			else
			{
				Detailed_Output();
				if(print)
				{
					printf("\nInformation BEFORE Inverting operation\n\n");
					printf("\nThe allocated addresses are as below:\n");
					for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
					{
						printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
					}
				}
				mem_ptr = mem_original;
				if(print == 0)
				{
					printf("\nThe data in hex at the specified memory location BEFORE Inverting is %x\n", *mem_ptr2);
				}
				clkbegin();
				*mem_ptr2 ^= 0xFFFFFFFF;
				clkend();
				if(print == 0)
				{
					printf("\nThe data in hex at the specified memory location AFTER Inverting is %x\n", *mem_ptr2);
				}
				else
				{
					printf("\nInformation AFTER Inverting operation\n\n");
					printf("\nThe allocated addresses are as below:\n");
					for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
					{
						printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
					}
				}
				mem_ptr = mem_original;
				printf("\nThanks for performing an XOR operation at an allocated memory location...\n");
			}
		}
		else
		{
			Null_Ptr();
		}
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so XORing is not possible at this moment...\n");
	}
}
#include "Memwrite.h" // c

uint32_t *mem_ptr2, mem_i;

/* memwrite() - Function required to write user specified data at a user specified location within the allocated memory space */

void memwrite(void)
{
	if(mem_ptr)
	{
		if(relative_address)
		{
			value1 = (value1 * 4) + (uint64_t)mem_ptr;
		}
		mem_ptr2 = (uint32_t *) value1;
		if(mem_ptr2)
		{
			Boundary_Check();
			if((boundary_error == 1) && (b_proceed == 0))
			{
				printf("\nProcess Terminated\n");
			}
			else
			{
				Detailed_Output();
				if(print)
				{
					printf("\nInformation BEFORE write operation\n\n");
					printf("\nThe allocated addresses are as below:\n");
					for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
					{
						printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
					}
				}
				mem_ptr = mem_original;
				if(print == 0)
				{
					printf("\nThe hex data at the specified location BEFORE writing %p is %x\n", mem_ptr2, *mem_ptr2);
				}
				*mem_ptr2 = value2;
				if(print == 0)
				{
					printf("\nThe hex data at the specified location AFTER writing %p is %x\n", mem_ptr2, *mem_ptr2);
				}
				else
				{
					printf("\nInformation AFTER write operation\n\n");
					printf("\nThe allocated addresses are as below:\n");
					for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
					{
						printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
					}
				}
				mem_ptr = mem_original;
				printf("\nThanks for writing to an allocated memory location...\n");
			}
		}
		else
		{
			Null_Ptr();
		}
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory write cannot be done...\n");
	}
}
#include "Main.h" // including the .h file containing the Main program
#include "Help.h" // including the .h file containing the Help interface code
#include "Input.h" // including the .h file that contains the valid inputs for testing the system

char input[250], input1[50], input2[50], input3[50], input4[50], input5[50];
uint8_t main_i, main_j, exit_flag, space_flag, relative_address;

char m_print[50];
uint8_t print = 0;

clock_t t;

char b_input[50];
uint8_t b_proceed = 0;
uint8_t boundary_error = 0;

/* clkbegin() - Function required to begin the clock for counting the time taken thereafter for all the processes that take place before ending the clock */

void clkbegin(void)
{ 
    t = clock(); 
}

/* clkend() - Function required to end the clock for counting the time taken by the code to execute the part of the execution code between this function and the clkbegin function */

void clkend(void)
{
	t = clock() - t; 
    double time_taken = (((double)t)/CLOCKS_PER_SEC) * 1000; // in milli seconds 
	printf("\nThe process took %f milli seconds to execute\n", time_taken); 
}

/* Boundary_Check() - Intrinsic function to check the boundary  */

void Boundary_Check(void)
{
	if((mem_ptr2 >= mem_original) && (mem_ptr2 <= (mem_original + (mem_max - 1))))
	{
		boundary_error = 0;
	}
	else
	{
		boundary_error = 1;
		while(1)
		{
			printf("\nProvided memory location is outside of allocated space\n\nProceeding anyway can be dangerous\n");
			printf("\nMemory address that you're trying to access: %p\n",mem_ptr2);
			printf("\nHighest memory address that is allocated: %p\n",(mem_original + (mem_max - 1)));
			printf("\n Type Y or y to avoid the warning and proceed,\nor type N or n to abort the operation: ");
			fgets(b_input, 50, stdin);
			printf("\n");
			if((b_input[0] == 'Y') || (b_input[0] == 'y'))
			{
				b_proceed = 1;
				break;
			}
			else if((b_input[0] == 'N') || (b_input[0] == 'n'))
			{
				b_proceed = 0;
				break;
			}
			else
			{
				printf("\nInvalid Input, Try again\n");
			}
		}
	}
}

void Detailed_Output(void)
{
	while(1)
	{
		printf("\nDo you want to use Detailed information?\n");
		printf("\n Type Y or y to accept, type N or n to reject: ");
		fgets(m_print, 50, stdin);
		printf("\n");
		if((m_print[0] == 'Y') || (m_print[0] == 'y'))
		{
			print = 1;
			break;
		}
		else if((m_print[0] == 'N') || (m_print[0] == 'n'))
		{
			print = 0;
			break;
		}
		else
		{
			printf("\nInvalid Input, Try again\n");
		}
	}
}

void Array_Cleanup(char *clean_ptr)
{
	if(clean_ptr)
	{
		while(*clean_ptr != 0)
		{
			*clean_ptr = 0;
			clean_ptr += 1;
		}
	}
	else
	{
		Null_Ptr();
	}
}

int main(void)	
{
	relative_address = 1;
	Array_Cleanup(input);
	Array_Cleanup(input1);
	Array_Cleanup(input2);
	Array_Cleanup(input3);
	Array_Cleanup(input4);
	Array_Cleanup(input5);
	Help_Init();
	Input_Init();
	char address_type[50];
	while(1)
	{
		printf("Do you want to use Relative/Easy Addressing?\n");
		printf("\n Type Y or y to accept, type N or n to reject\nand use absolute/direct addressing: ");
		fgets(address_type, 50, stdin);
		if((address_type[0] == 'Y') || (address_type[0] == 'y'))
		{
			relative_address = 1;
			break;
		}
		else if((address_type[0] == 'N') || (address_type[0] == 'n'))
		{
			relative_address = 0;
			break;
		}
		else
		{
			printf("\nInvalid Input, Try again\n");
		}
	}
	printf("\nRelative Addressing Value set to: %d\n", relative_address);
	while(1)
	{
		exit_flag = 0;
		space_flag = 0;
		printf("\nEnter Command: ");
		fgets(input, 250, stdin);
		main_i = 0;
		while(input[main_i] != '\n')
		{
			main_i += 1;
		}
		input[main_i] = 0;
		main_i = 0;
		while((input[main_i] != 0) && (input[main_i] != ' '))
		{
			input1[main_i] = input[main_i];
			main_i += 1;
		}
		main_j = 0;
		while(input[main_i] != 0)
		{
			if(input[main_i] == ' ')
			{
				space_flag += 1;
				main_i += 1;
				while((input[main_i] != ' ') && (input[main_i] != 0))
				{
					input2[main_j] = input[main_i];
					main_i += 1;
					main_j += 1;
				}
				if(input[main_i] == ' ')
				{
					space_flag += 1;
					main_j = 0;
					main_i += 1;
					while((input[main_i] != ' ') && (input[main_i] != 0))
					{
						input3[main_j] = input[main_i];
						main_i += 1;
						main_j += 1;
					}
					if(input[main_i] == ' ')
					{
						space_flag += 1;
						main_j = 0;
						main_i += 1;
						while((input[main_i] != ' ') && (input[main_i] != 0))
						{
							input4[main_j] = input[main_i];
							main_i += 1;
							main_j += 1;
						}
						if(input[main_i] == ' ')
						{
							space_flag += 1;
							main_j = 0;
							main_i += 1;
							while((input[main_i] != ' ') && (input[main_i] != 0))
							{
								input5[main_j] = input[main_i];
								main_i += 1;
								main_j += 1;
							}	
						}			
					}
				}
			}
			main_i += 1;
		}
		main_i = 0;
		main_j = 0;
		if(input[main_i] != 0)
		{
			Input_Lookup();
			if(exit_flag)
			{
				return 0;
			}	
		}
		Array_Cleanup(input);
		Array_Cleanup(input1);
		Array_Cleanup(input2);
		Array_Cleanup(input3);
		Array_Cleanup(input4);
		Array_Cleanup(input5);
	}
}
#include "Patterngen.h"

//add, len, seed, max

uint32_t *mem_ptr2, mem_i;
float random_number, seed;
uint32_t max, range, random_value, *pattern_original;
clock_t t;

void generator(void)
{
	random_number = ((0.4353491074*seed) + 0.8173946121);
	while(random_number > 1)
	{
		random_number /= 10;
	}
	random_number *= max;
	random_value = (uint32_t)random_number;
	printf("\n%x", random_value);
	*mem_ptr2 = random_value;
	seed = random_number;
}

void patterngen(void)
{
	if(mem_ptr)
	{
		range = value2;
		seed = (float) value3;
		max = value4;
		if(relative_address)
		{
			value1 = (value1 * 4) + (uint64_t)mem_ptr;
		}
		mem_ptr2 = (uint32_t *) value1;
		if(mem_ptr2)
		{
			pattern_original = mem_ptr2;
			Boundary_Check();
			if((boundary_error == 1) && (b_proceed == 0))
			{
				printf("\nProcess Terminated\n");
			}
			else
			{
				value2 -= 1;
				value2 = (value2 * 4) + (uint64_t)pattern_original;
				mem_ptr2 = (uint32_t *) value2;
				Boundary_Check();
				if((boundary_error == 1) && (b_proceed == 0))
				{
					printf("\nProcess Terminated\n");
				}
				else
				{
					mem_ptr2 = pattern_original;
					Detailed_Output();
					clkbegin();
					if(print)
					{
						printf("\nInformation BEFORE pattern generate operation\n\n");
						printf("\nThe allocated addresses are as below:\n");
						for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
						{
							printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
						}
					}
					mem_ptr = mem_original;
					while(seed > 1)
					{
						seed /= 10;
					}
					printf("\nGenerated Psuedo Random Numbers: \n");
					uint8_t counter;
					for(counter = 0; counter < range; counter ++, mem_ptr2 ++)
					{
						generator();
					}
					mem_ptr2 = pattern_original;
					if(print)
					{
						printf("\nInformation AFTER pattern generate operation\n\n");
							printf("\nThe allocated addresses are as below:\n");
						for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
						{
							printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
						}
					}
					mem_ptr = mem_original;
					clkend();
					printf("\nThanks for generating a pattern with psuedo random numbers...\n");
				}
			}
		}
		else
		{
			Null_Ptr();
		}
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory write cannot be done...\n");
	}
}
#include "Patternverify.h"

//add, len, seed, max

uint32_t *mem_ptr2, mem_i;
float random_number, seed;
uint32_t max, range, random_value, *pattern_original;
uint8_t verification_flag, verification_counter;
clock_t t;

void gen_verify(void)
{
	random_number = ((0.4353491074*seed) + 0.8173946121);
	while(random_number > 1)
	{
		random_number /= 10;
	}
	random_number *= max;
	random_value = (uint32_t)random_number;
	printf("\n%x", random_value);
	if(*mem_ptr2 == random_value)
	{
		verification_counter += 1;
	}
	seed = random_number;
}

void patternverify(void)
{
	verification_flag = 0;
	verification_counter = 0;
	if(mem_ptr)
	{
		range = value2;
		seed = (float) value3;
		max = value4;
		if(relative_address)
		{
			value1 = (value1 * 4) + (uint64_t)mem_ptr;
		}
		mem_ptr2 = (uint32_t *) value1;
		if(mem_ptr2)
		{
			pattern_original = mem_ptr2;
			Boundary_Check();
			if((boundary_error == 1) && (b_proceed == 0))
			{
				printf("\nProcess Terminated\n");
			}
			else
			{
				value2 -= 1;
				value2 = (value2 * 4) + (uint64_t)pattern_original;
				mem_ptr2 = (uint32_t *) value2;
				Boundary_Check();
				if((boundary_error == 1) && (b_proceed == 0))
				{
					printf("\nProcess Terminated\n");
				}
				else
				{
					mem_ptr2 = pattern_original;
					Detailed_Output();
					clkbegin();
					if(print)
					{
						printf("\nThe allocated addresses are as below:\n");
						for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
						{
							printf("\nRelative address: %d \t\t Actual address: %p \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
						}
					}
					mem_ptr = mem_original;
					while(seed > 1)
					{
						seed /= 10;
					}
					printf("\nGenerated Psuedo Random Numbers: \n");
					uint8_t counter;
					for(counter = 0; counter < range; counter ++, mem_ptr2 ++)
					{
						gen_verify();
					}
					mem_ptr2 = pattern_original;
					if(verification_counter != range)
					{
						printf("\nPattern Verification Failed\n");
					}
					else
					{
						printf("\nPattern Verified Successfully\n");
					}
					clkend();
					printf("\nThanks for verifying pattern...\n");
				}
			}
		}
		else
		{
			Null_Ptr();
		}
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory write cannot be done...\n");
	}
}
#include "Input.h"

const char ire[] = "\nCommand not recognized\n";
const char i1[] = "help";
const char i2[] = "exit";
const char i3[] = "memalloc";
const char i4[] = "memfree";
const char i5[] = "memwrite";
const char i6[] = "memread";
const char i7[] = "meminv";
const char i8[] = "patterngen";
const char i9[] = "patternverify";

char input_array[500], error_flag, hex_flag;
char input[250], input1[50], input2[50], input3[50], input4[50], input5[50];
uint8_t input_i, input_j, input_k, exit_flag, power;
uint64_t value, value1, value2, value3, value4;

void (*Input_Func_Pointer[9]) (void) = 
											{
												Help_Display,
												Exit_Func,
												Memalloc_Func,
												Memfree_Func,
												Memwrite_Func,
												Memread_Func,
												Meminv_Func,
												Patterngen_Func,
												Patternverify_Func
											};

void (*Input_Space_Func_Pointer[9]) (void) = 
													{
														Help_Lookup,
														Command_Error,
														Space_Memalloc_Func,
														Command_Error,
														Space_Memwrite_Func,
														Space_Memread_Func,
														Space_Meminv_Func,
														Space_Patterngen_Func,
														Space_Patternverify_Func
													};

void Command_Error(void)
{
	printf("%s",ire);
}

void Exit_Func(void)
{
	exit_flag = 1;
}

void Memalloc_Func(void)
{
	printf("\nEnter number of 32bit words for malloc: ");
	hex_flag = 0;
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		memalloc();
	}
	else
	{
		value1 = 0;
	}
	printf("\n%ld Blocks have been allocated\n", value1);	
}

void Space_Memalloc_Func(void)
{
	if(space_flag == 1)
	{
		String_to_Decimal(input2);
		if(error_flag == 0)
		{
			value1 = value;
			memalloc();
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
	printf("\n%ld Blocks have been allocated\n", value);
}

void Memfree_Func(void)
{
	memfree();
}

void Memwrite_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		printf("\nEnter 32bit Data in Hex: ");
		hex_flag = 1;
		Valid_Integer_Input();
		if(error_flag == 0)
		{
			value2 = 0x00000000;
			value2 += value;
			memwrite();
		}
	}
}

void Space_Memwrite_Func(void)
{
	if(space_flag == 2)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			String_to_Hex(input3);
			if(error_flag == 0)
			{
				value2 = value;
				memwrite();
			}
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Memread_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		memread();
	}
}

void Space_Memread_Func(void)
{
	if(space_flag == 1)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			memread();
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Meminv_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		meminv();
	}
}
void Space_Meminv_Func(void)
{
	if(space_flag == 1)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			meminv();
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Patterngen_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative starting address of the memory location in decimal: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute starting address of the memory location in hex: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		printf("\nEnter the number of 32bit numbers that you wish to generate in decimal: ");
		hex_flag = 0;
		Valid_Integer_Input();
		if(error_flag == 0)
		{
			value2 = value;
			printf("\nEnter the Seed value of your choice in decimal: ");
			hex_flag = 0;
			Valid_Integer_Input();
			if(error_flag == 0)
			{
				value3 = value;
				printf("\nEnter the Maximum value of generated psuedo random number(s) in decimal: ");
				hex_flag = 0;
				Valid_Integer_Input();
				if(error_flag == 0)
				{
					value4 = value;
					patterngen();
				}
			}
		}
	}
}

void Space_Patterngen_Func(void)
{
	if(space_flag == 4)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			String_to_Decimal(input3);
			if(error_flag == 0)
			{
				value2 = value;
				String_to_Decimal(input4);
				if(error_flag == 0)
				{
					value3 = value;
					String_to_Decimal(input5);
					if(error_flag == 0)
					{
						value4 = value;
						patterngen();
					}
				}
			}
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Patternverify_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative starting address of the memory location in decimal: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute starting address of the memory location in hex: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		printf("\nEnter the number of 32bit numbers that you wish to verify in decimal: ");
		hex_flag = 0;
		Valid_Integer_Input();
		if(error_flag == 0)
		{
			value2 = value;
			printf("\nEnter the original Seed value in decimal: ");
			hex_flag = 0;
			Valid_Integer_Input();
			if(error_flag == 0)
			{
				value3 = value;
				printf("\nEnter the Maximum value of generated psuedo random number(s) in decimal: ");
				hex_flag = 0;
				Valid_Integer_Input();
				if(error_flag == 0)
				{
					value4 = value;
					patternverify();
				}
			}
		}
	}
}

void Space_Patternverify_Func(void)
{
	if(space_flag == 4)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			String_to_Decimal(input3);
			if(error_flag == 0)
			{
				value2 = value;
				String_to_Decimal(input4);
				if(error_flag == 0)
				{
					value3 = value;
					String_to_Decimal(input5);
					if(error_flag == 0)
					{
						value4 = value;
						patternverify();
					}
				}
			}
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void String_to_Decimal(char *stod_ptr)
{
	if(stod_ptr)
	{
		char *stod_i;
		stod_i = stod_ptr;
		for(; *stod_ptr != 0; stod_ptr ++)
		{
			if(isdigit(*stod_ptr) == 0)
			{
				printf("\nNon Integer Value Entered\n");
				error_flag = 1;
				value = 0;
				break;
			}
		}
		if(*stod_ptr == 0)
		{
			error_flag = 0;
			value = atoi(stod_i);
		}
	}
	else
	{
		Null_Ptr();
		error_flag = 1;
		value = 0;
	}
}

void String_to_Hex(char *stox_ptr)
{
	if(stox_ptr)
	{
		char *stox_i;
		stox_i = stox_ptr;
		while(*stox_ptr != 0)
		{
			if(((*stox_ptr >= '0') && (*stox_ptr <= '9')) || ((*stox_ptr >= 'a') && (*stox_ptr <= 'f')) || ((*stox_ptr >= 'A') && (*stox_ptr <= 'F')))
			{
				stox_ptr += 1;
			}
			else
			{
				break;
			}
		}
		if(*stox_ptr == 0)
		{
			error_flag = 0;
			value = (uint32_t) strtol(stox_i, NULL, 16);
		}
		else
		{
			printf("\nNon Hex Value Entered\n");
			error_flag = 1;
			value = 0;
			Command_Error();
		}
	}
	else
	{
		Null_Ptr();
		error_flag = 1;
		value = 0;
	}
}

void Valid_Integer_Input(void)
{
	char test[50];
	fgets(test, 50, stdin);
	input_j = 0;
	while(test[input_j] != '\n')
	{
		input_j += 1;
	}
	test[input_j] = 0;
	if(hex_flag == 0)
	{
		String_to_Decimal(test);
	}
	else
	{
		String_to_Hex(test);
	}
}

void Input_Init(void)
{
	input_j = 0;
	input_k = 0;
	while(i1[input_k] != 0)
	{
		input_array[input_j] = i1[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i2[input_k] != 0)
	{
		input_array[input_j] = i2[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i3[input_k] != 0)
	{
		input_array[input_j] = i3[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i4[input_k] != 0)
	{
		input_array[input_j] = i4[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i5[input_k] != 0)
	{
		input_array[input_j] = i5[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i6[input_k] != 0)
	{
		input_array[input_j] = i6[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i7[input_k] != 0)
	{
		input_array[input_j] = i7[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i8[input_k] != 0)
	{
		input_array[input_j] = i8[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
	input_j += 1;
	input_k = 0;
	while(i9[input_k] != 0)
	{
		input_array[input_j] = i9[input_k];
		input_j += 1;
		input_k += 1;
	}
	input_array[input_j] = 0;
}

void Input_Cleanup(void)
{
	hex_flag = 0;
	error_flag = 0;
	value = 0;
	value1 = 0;
	value2 = 0;
	value3 = 0;
	value4 = 0;
	input_j = 0;
}

void Input_Lookup(void)
{
	Input_Cleanup();
	input_i = 0;
	//In the input, entering space after command as a mistake is acceptable, but entering anything after that space is not
	if((space_flag != 0) && (input2[0] != 0))
	{
		for(input_k = 0; input_k < Number_of_Input_Functions; input_k ++)
		{
			input_j = 0;
			while((input_array[input_i] != 0) && (input1[input_j] != 0))
			{
				if(input_array[input_i] == input1[input_j])
				{
					input_j += 1;
					input_i += 1;
				}
				else
				{
					break;
				}
			}
			if((input_array[input_i] == 0) && (input1[input_j] == 0))
			{
				(*Input_Space_Func_Pointer[input_k])();
				break;
			}
			else
			{
				while(input_array[input_i] != 0)
				{
					input_i += 1;
				}
				if(input_k == (Number_of_Help_Functions - 1))	
				{
					printf("%s",ire);
				}
			}
			input_i += 1;
		}
	}
	else
	{
		for(input_k = 0; input_k < Number_of_Input_Functions; input_k ++)
		{
			input_j = 0;
			while((input_array[input_i] != 0) && (input1[input_j] != 0))
			{
				if(input_array[input_i] == input1[input_j])
				{
					input_j += 1;
					input_i += 1;
				}
				else
				{
					break;
				}
			}
			if((input_array[input_i] == 0) && (input1[input_j] == 0))
			{
				(*Input_Func_Pointer[input_k])();
				break;
			}
			else
			{
				while(input_array[input_i] != 0)
				{
					input_i += 1;
				}
				if(input_k == Number_of_Help_Functions)	
				{
					printf("%s",ire);
				}
			}
			input_i += 1;
		}
	}
}
