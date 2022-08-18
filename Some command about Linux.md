# Something about Linux

> __Here is some command that new to me__

****

****

## 1. cal

> show **calendar** 

```bash
[epicr@EPIPHANY ~]$ cal
     August 2022    
Su Mo Tu We Th Fr Sa
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30 31    
```

****



## 2. passwd

> change the **password**, here I didn't want to change the password, so I input an error.

```bash
[epicr@EPIPHANY ~]$ passwd
Changing password for epicr.
Current password: 
New password: 
Retype new password: 
Sorry, passwords do not match.
passwd: Failed preliminary check by password service
passwd: password unchanged
```

****



## 3. whoami

> just look look. List the account name associated with the current login.

```bash
[epicr@EPIPHANY ~]$ whoami
epicr
```

****



## 4. users, who, w

> List all who is logged in to the computer at the same time.

```bash
[epicr@EPIPHANY ~]$ users
epicr
[epicr@EPIPHANY ~]$ who
epicr    tty2         2022-08-13 10:03 (tty2)
[epicr@EPIPHANY ~]$ w
 16:06:24 up  6:02,  1 user,  load average: 0.19, 0.29, 0.27
USER     TTY        LOGIN@   IDLE   JCPU   PCPU WHAT
epicr    tty2      10:03    6:02m  0.02s  0.00s /usr/lib/gdm-wayland-session /u
```

****



## 5. shutdown -h now	shutdown -r now

> This is useful so I list it here

****



## 6. cat -b filename

> command **cat** is in common usage, but while adding with "-b" option, it will show line number.

```bash
[epicr@EPIPHANY CSshell]$ cat -b s.md
     1	# Two usages about git rm
     2	***
     3	1. --cached keep files
     4	2. \-f remove the file forcely
```

****



## 7. wc filename

> Getting a count of the total number of lines, words and bytes.

```bash
[epicr@EPIPHANY CSshell]$ wc s.md
 4 17 84 s.md
```

> * **First Column** -- number of lines
> * **Second Column** -- number of words
> * **Third Column** -- total number of bytes in the file, ___This is the actual size of the file.___ 
> * **Fourth Column** -- file name

****



## 8. chmod

> **There are two ways to change the mode.** 
>
> 1. "object + operator + permissions"
>
>    **Object** --: user (**u**)	group(**g**)	others(**o**)
>
>    **Operator** --: "+"	"-"	"="
>
>    **Permissions** --: read(**r**)	write(**w**)	execute(**x**)

```bash
[epicr@EPIPHANY CSshell]$ ls -l s.md
-rwxrwxr-- 1 epicr epicr 84 Aug 13 17:36 s.md
[epicr@EPIPHANY CSshell]$ chmod u-x,g=rx,o+wx s.md		// separate by comma(,)
[epicr@EPIPHANY CSshell]$ ls -l s.md
-rw-r-xrwx 1 epicr epicr 84 Aug 13 17:36 s.md
```

> 2. **Absolute Permissions** 
>
>    7 represent "rwx", it's no more to say since it's familiar to me.

```bash
[epicr@EPIPHANY CSshell]$ chmod 764 s.md
[epicr@EPIPHANY CSshell]$ ls -l s.md
-rwxrw-r-- 1 epicr epicr 84 Aug 13 17:36 s.md
```

****



## 9. chown	chgrp

**Syntax** here. 

> chown user filename
>
> chgrp group filename

****



## 10. **PS1** and **PS2** Variables

> The characters that the shell displays as your command prompt are stored in the variable PS1. 

```bash
[epicr@EPIPHANY ~]$ PS1='=>'
=>echo 'the shell prompt has changed'
the shell prompt has changed
=>PS1="[\u@\h \w]\$ "
[epicr@EPIPHANY ~]$ ls
```

| **No** | **Escape Sequence** & **Description**                        |
| :----: | :----------------------------------------------------------- |
|   1    | **\t**                     Current time, HH:MM:SS            |
|   2    | **\d**                    Current date                       |
|   3    | **\n**                   New line                            |
|   4    | **\s**                   Current shell environment           |
|   5    | **\w**                 Working directory                     |
|   6    | **\u**                 Current user's name                   |
|   7    | **\h**                 Hostname of the current machine       |
|   8    | **\\#**                 Command number of the current command. Increases when a new command is entered. |
|   9    | **\\$**                 Show $ sign                          |

> __About \\#__ 

```bash
[epicr@EPIPHANY ~]$ PS1="[\u \w@ \#]=> "
[epicr ~@ 8]=> ls
Documents  Downloads  Music  Pictures  Public  Templates  user  Videos
[epicr ~@ 9]=> cd user
[epicr ~/user@ 10]=> 
```



> **PS2** is useful while changing lines
>
> and it's default to 	>

```bash
[epicr@EPIPHANY sublime]$ echo hello \
> liumiao, \
> Greetings
hello liumiao, Greetings
[epicr@EPIPHANY sublime]$ PS2="nextline: "
[epicr@EPIPHANY sublime]$ echo hello \
nextline: liumiao, \
nextline: Greetings
hello liumiao, Greetings
```

****



## 11. Other Environment Variables

 <table>
<tbody><tr>
<th style="text-align:center;">Sr.No.</th>
<th style="text-align:center;">Variable &amp; Description</th>
</tr>
<tr>
<td>1</td>
<td>
<p><b>DISPLAY</b></p>
<p>Contains the identifier for the display that <b>X11</b> programs should use by default.</p>
</td>
</tr>
<tr>
<td>2</td>
<td>
<p><b>HOME</b></p>
<p>Indicates the home directory of the current user: the default argument for the cd <b>built-in</b> command.</p>
</td>
</tr>
<tr>
<td class="ts">3</td>
<td>
<p><b>IFS</b></p>
<p>Indicates the <b>Internal Field Separator</b> that is used by the parser for word splitting after expansion.</p>
</td>
</tr>
<tr>
<td class="ts">4</td>
<td>
<p><b>LANG</b></p>
<p>LANG expands to the default system locale; LC_ALL can be used to override this. For example, if its value is <b>pt_BR</b>, then the language is set to (Brazilian) Portuguese and the locale to Brazil.</p>
</td>
</tr>
<tr>
<td class="ts">5</td>
<td>
<p><b>LD_LIBRARY_PATH</b></p>
<p>A Unix system with a dynamic linker, contains a colonseparated list of directories that the dynamic linker should search for shared objects when building a process image after exec, before searching in any other directories.</p>
</td>
</tr>
<tr>
<td class="ts">6</td>
<td>
<p><b>PATH</b></p>
<p>Indicates the search path for commands. It is a colon-separated list of directories in which the shell looks for commands.</p>
</td>
</tr>
<tr>
<td>7</td>
<td>
<p><b>PWD</b></p>
<p>Indicates the current working directory as set by the cd command.</p>
</td>
</tr>
<tr>
<td>8</td>
<td>
<p><b>RANDOM</b></p>
<p>Generates a random integer between 0 and 32,767 each time it is referenced.</p>
</td>
</tr>
<tr>
<td>9</td>
<td>
<p><b>SHLVL</b></p>
<p>Increments by one each time an instance of bash is started. This variable is useful for determining whether the built-in exit command ends the current session.</p>
</td>
</tr>
<tr>
<td>10</td>
<td>
<p><b>TERM</b></p>
<p>Refers to the display type.</p>
</td>
</tr>
<tr>
<td>11</td>
<td>
<p><b>TZ</b></p>
<p>Refers to Time zone. It can take values like GMT, AST, etc.</p>
</td>
</tr>
<tr>
<td>12</td>
<td>
<p><b>UID</b></p>
<p>Expands to the numeric user ID of the current user, initialized at the shell startup.</p>
</td>
</tr>
</tbody></table>
> **Original link** :	[Unix/Linux Tutorial](https://www.tutorialspoint.com/unix/unix-environment.htm) 

****



## 12. 

