Synopsis
This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executables found in the environmental variable PATH, with or without their full paths. Our shell does NOT handle piping, redirection, or aliases.

Builtins
exit exits shell (Usage: exit [status])
env prints environmental variables (Usage: env)
setenv creates or modifies an environmental variable (Usage: setenv name value)
unsetenv removes an envrionmental variable (Usage: unsetenv name value)
cd changes directories (Usage: cd [path])

Description of what each file shows:
man_1_simple_shell ------------------------ custom manpage for our simple shell
main.c ----------------------------- holds entrance into program
shell.h ---------------------------- holds prototypes of functions spread across all files

built_in.c --------------------------- runBuiltIn, hey_exit, hey_env
error_cases_2.c ------------------ error_cd, error_syn, error_126, error_127
error_cases.c ------------------------- create_error, error_env, error_1, error_exit
error_elephant.c -------------------------- errorHand
freedom.c -------------------------- free_tokens, free_path, free_env, free_alias_list
help_fun.c -------------------------- get_input, yoinkline, num_len, _itoa, forktime
moar_strstuff.c -------------------------- _strncmp, _strspn
pathfinder.c -------------------------- path_locate, path_tok, print_paths, check_paths
string_support.c ------------------------- _strcat, dupstr, _strcpy, _strcmp, _strlen
tokenizer.c ------------------------- tok_num, tokstr, substrLen
Environment
Language: C
OS: Ubuntu 14.04 LTS
Compiler: gcc 4.8.4
Style guidelines: Betty style
How To Install, Compile, and Use
Install and Compile

(your_terminal)$ git clone https://github.com/Julia-5534/holbertonschool-simple_shell.git
(your_terminal)$ cd holbertonschool-simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Non-Interactive Mode

echo "ls -l" | ./hsh

Interactive Mode* Activate the shell

(your_terminal)$ ./hsh
$
Sample Usage

$ ls
$ echo "This is a pretty cool!"
This is pretty cool!
$ man ./man_1_simple_shell (opens our manpage for more information)
Stop and return to your original shell

$ exit
(your_terminal)$
To Do
More functionality can still be added (e.g. handle aliases, pipelines, and redirections)
Authors
Julia Bullard & Chris Stamper
