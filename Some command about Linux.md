# Some command about Linux

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



## 8. 

