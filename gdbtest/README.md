Do this:
g++ -g gdbexample.cpp
gdb a.out
list
break 5
r
p str1
p &str1
x/7tb <address of str1> (to see value of "UDACITY" in binary)
x/7xb <address of str1> (to see value of "UDACITY" in hex)