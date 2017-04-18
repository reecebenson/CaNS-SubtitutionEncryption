// Reece Benson © 2017
// Computer and Network Systems - Subtitution Encryption
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct nchar {
	char orig;
	char upd;
};

// > Variables
nchar ochar[32];

void init_chars()
{
	ochar[0].orig = 'A'; ochar[0].upd = 'K';
	ochar[1].orig = 'B'; ochar[1].upd = 'P';
	ochar[2].orig = 'C'; ochar[2].upd = 'Z';
	ochar[3].orig = 'D'; ochar[3].upd = 'F';
	ochar[4].orig = 'E'; ochar[4].upd = 'A';
	ochar[5].orig = 'F'; ochar[5].upd = 'Y';
	ochar[6].orig = 'G'; ochar[6].upd = 'S';
	ochar[7].orig = 'H'; ochar[7].upd = '-';
	ochar[8].orig = 'I'; ochar[8].upd = 'N';
	ochar[9].orig = 'J'; ochar[9].upd = '!';
	ochar[10].orig = 'K'; ochar[10].upd = 'V';
	ochar[11].orig = 'L'; ochar[11].upd = 'B';
	ochar[12].orig = 'M'; ochar[12].upd = 'X';
	ochar[13].orig = 'N'; ochar[13].upd = 'J';
	ochar[14].orig = 'O'; ochar[14].upd = 'G';
	ochar[15].orig = 'P'; ochar[15].upd = 'E';
	ochar[16].orig = 'Q'; ochar[16].upd = 'W';
	ochar[17].orig = 'R'; ochar[17].upd = 'Q';
	ochar[18].orig = 'S'; ochar[18].upd = '?';
	ochar[19].orig = 'T'; ochar[19].upd = 'T';
	ochar[20].orig = 'U'; ochar[20].upd = 'M';
	ochar[21].orig = 'V'; ochar[21].upd = 'R';
	ochar[22].orig = 'W'; ochar[22].upd = 'U';
	ochar[23].orig = 'X'; ochar[23].upd = 'H';
	ochar[24].orig = 'Y'; ochar[24].upd = ',';
	ochar[25].orig = 'Z'; ochar[25].upd = 'D';
	ochar[26].orig = ' '; ochar[26].upd = '.';
	ochar[27].orig = '.'; ochar[27].upd = ' ';
	ochar[28].orig = ','; ochar[28].upd = 'O';
	ochar[29].orig = '-'; ochar[29].upd = 'I';
	ochar[30].orig = '?'; ochar[30].upd = 'L';
	ochar[31].orig = '!'; ochar[31].upd = 'C';
}

void encrypt_message(string msg)
{
	// > Variables
	int i, c;
	char new_msg[32];

	// > Update new_msg
	for (i = 0; i < msg.length(); i++)
	{
		new_msg[i] = msg.at(i);
	}
	new_msg[i] = '\0';

	// > Debug
	printf("[ENCRYPT]: orig_msg: %s | len: %d\n", new_msg, msg.length());

	// > Update new_msg values
	for (i = 0; i < msg.length(); i++)
	{
		for (c = 0; c < 32; c++)
		{
			if (new_msg[i] == ochar[c].orig)
			{
				new_msg[i] = ochar[c].upd;
				break;
			}
		}
	}

	// > Debug
	printf("[ENCRYPT]: new_msg: %s | len: %d\n", new_msg, msg.length());
}

void decrypt_message(string msg)
{
	// > Variables
	int i, c;
	char new_msg[32];

	// > Update new_msg
	for (i = 0; i < msg.length(); i++)
	{
		new_msg[i] = msg.at(i);
	}
	new_msg[i] = '\0';

	// > Debug
	printf("[DECRYPT]: orig_msg: %s | len: %d\n", new_msg, msg.length());

	// > Update new_msg values
	for (i = 0; i < msg.length(); i++)
	{
		for (c = 0; c < 32; c++)
		{
			if (new_msg[i] == ochar[c].upd)
			{
				new_msg[i] = ochar[c].orig;
				break;
			}
		}
	}

	// > Debug
	printf("[DECRYPT]: new_msg: %s | len: %d\n", new_msg, msg.length());
}

int main()
{
	// > Variables
	string msg;
	printf("Please enter the decrypted message: ");
	getline(cin, msg);

	// > Initialise
	init_chars();

	// > Encrypt message
	encrypt_message(msg);

	// > Debug
	printf("\n");

	// > Decrypt message
	decrypt_message(msg);

	// > Repeat
	printf("\n\n\n");
	main();

	return 0;
}