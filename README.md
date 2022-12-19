<h2>Synopsis</h2>
<p>
This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executables found in the environmental variable PATH, with or without their full paths. Our shell does NOT handle aliases, directory changes, or many other features presently.
</p>

<h2>How Does it Work?</h2>
<p>

![](https://github.com/Julia-5534/holbertonschool-simple_shell/blob/master/shellPFD.jpg)

</p>
<h2>File & Function Descriptions</h2>
<p>

| Files              | Descriptions                                                                         |
| ------------       | ------------------------------------------------------------------------------------ |
| built_in.c         | handles and contains built in shell functions                                        |
| error_elephant.c   | file containing error processing and writing directives                              |
| freedom.c          | various functions associated with preventing memory leaks                            |
| man_1_simple_shell | Manual page                                                                          |
| help_fun.c         | misc. functions that serve aux purposes                                              |
| main.c             | entry point for simple shell program                                                 |
| pathfinder.c       | has functions associated with tokenizing PATH and checking pathArr against command   |
| shell.h            | header file for the simple shell program that includes protos librars and structs    |
| string_support.c   | this file consists of string manipulation functions called in various support roles  |
| tokenizer.c        | contains tokstr as well as its associated support subfunctions                       |

| built_in.c Functions                        | Descriptions                             |
| ------------------------------------------- | ---------------------------------------- |
| int runBuiltIn(char **command, char *line)  |  check for then calls built in functions |
| int hey_exit(char **command)                |  executes built in shell exit            |
| int hey_env(char **command)                 |  prints user's current env to SO         |

| error_elephant.c                                 | Descriptions                             |
| ------------------------------------------------ | ---------------------------------------- |
| void errorHand(int lNum, char *arg, char *pName) | writes error msgs to stderr              |

| freedom.c                                  | Descriptions                             |
| ------------------------------------------ | ---------------------------------------- |
| void free_tokens(char **tokens)            | frees command array and its components   |
| void free_path(char **paths)               | frees path array and its components      |
| void free_env(void)                        | frees environment (used for testing)     |
| void free_exit(char *line)                 | prepares for program exit                |
| void sig_stop(int sNum)                    | traps SIGINT and taunts user             |

| help_fun.c                                   | Descriptions                             |
| -------------------------------------------- | ---------------------------------------- |
| char **get_input(char *input)                | supplies tokstr with delims for command  |
| char *_itoa(int num)                         | converts int to str for err msgs         |
| int forktime(char **command, char *thePath)  | forks process and executes commands      |
| int cleanstr(char *line)                     | removes new lines from line str          |
| int num_len(int num)                         | counts digits in num for err msgs        |

| pathfinder.c                                 | Descriptions                             |
| -------------------------------------------- | ---------------------------------------- |
| char **path_locate(char *envvar)             | find PATH env var and supplies to tokstr |
| char **path_tok(char *path)                  | supplies delims for path tokenization    |
| char *check_paths(char *command)             | checks and cats command and pathArr      |

| string_support.c                             | Descriptions                             |
| -------------------------------------------- | ---------------------------------------- |
| char *_strcat(char *dest, char *src)         | concats src str onto dest str            |
| char *_strcpy(char *dest, char *src)         | copies src str into dest str             |
| int _strlen(char *s)                         | calc length of str                       |
| int _strncmp(char *s1, char *s2, int n)      | compares first n bytes of two strs       |
| int _strcmp(char *s1, char *s2)              | finds first dif char in two strs         |

| tokenizer.c                                  | Descriptions                             |
| -------------------------------------------- | ---------------------------------------- |
| int tok_num(char *str, char *delims)         | computes num of toks in str w/ delims    |
| int substrLen(char *str, char *delims)       | calculates length of substring           |
| char **tokstr(char *line, char *delims)      | tokenizes str into arr of substrs        |

</p>

<h2>Examples</h2>
Intended to be compiled with the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Once compiled, this shell program can be run in interactive mode by running:

```
./hsh
```

Or non-interactive mode, with commands such as:

```
echo -e "ls -a\npwd\n" | ./hsh
```

Alternative, if a known desired command sequence exists, it can be indirectly run from file with:

```
cat {{file_name_here}} | ./hsh
```

Attempting bad magic, or otherwise making an inoperable command, should cause an error message
to be printed to the user's standard error, typically in one of the following forms:

Following a command that both doesn't exist as part of the PATH and doesn't point to an existing file.
Take for example, supplying /not/a/path/to/a/executable at line 1 (first entered command in session),
when the program is named hsh during compilation would be expected to produce the following error

```
./hsh: 1: /not/a/path/to/a/executable: not found
```

to be printed to the user's standard error, however; should a file exist in such a location and
the user simply not have permission to execute (run) it, the following would be anticipated to display

```
./hsh: 1: /not/a/path/to/a/executable: Permission denied
```

In either case the program's global exit value will be changed to the associated error number.
Upon program termination, the exit status of the last executed command should be available to the user.

The program will continue awaiting and executing user inputs (provided they're valid) until
one of the following conditions is satisfied or otherwise occurs, breaking the infinite loop:

<h2>Exit Conditions</h2>
<ul>
<li>1. It receives a SIGTERM (Ctrl + D) EOF signal, causing a controlled shutdown</li>
<li>2. It receives a SIGKILL signal, whereafter undefined behavior may transpire</li>
<li>3. The built in exit command is triggered, also causing a controlled exit</li>
<li>4. A fatal program error occurs, and is most likely printed to stderr</li>
</ul>

Builtins  
exit exits shell (Usage: exit [status])  
env prints environmental variables (Usage: env)  
  
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
