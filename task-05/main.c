#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "shell.h"
#include "shell_commands.h"

int led(int argc, char **argv)
{
	if (atoi(argv[1]) == 0) {
		LED0_TOGGLE;
	}
	else if (atoi(argv[1]) == 1) {
		LED1_TOGGLE;
	}
	else if (atoi(argv[1]) == 2) {
		LED2_TOGGLE;
	}
	else {
		return -1;
	}

	return 0;
}

static const shell_command_t shell_cmds[] = {
	{ "led", "toggle with led <num>", led },
	{ NULL, NULL, NULL}
};

int main(void)
{
	puts("Welcome to RIOT");

	char line_buf[SHELL_DEFAULT_BUFSIZE];
	shell_run(shell_cmds, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
