# ueOS
This is a pseudo-operating system mimicking 8-bit style microcomputers mixed with MS-DOS. It's written entirely in Blueprint and as of now has no access to the hard drive.

## Variables
Variable types supported:
String - ${variable name}
Integer - %{variable name}
Float - !{valiable name}

## Available commands
### ver
Just prints out version

### cls
Clears screen

### exit
Quits game

### wait
Halts execution for a given amount of seconds
Usage: wait {seconds time}
Examples: 
wait 2
wait 0.5

### var
Usage: var {varname and type} {value}
Examples: 
var $a This is a test
var %b 12
var !c 3.14

### print
Prints whatever is inputted after, does support simple mathematical equations and variables

Examples:
print %b + 3
print Variable a contains $a
print !c / 7

### input
A way for the user to input the value of given variable
Usage: input {variable name and type} (optional: Input prompt)
Examples:
input $a
input %b Your age? 

### if
A conditional statement. 
Usage: if {a} ==/!=/</<=/>/>= {b} 
{code goes here}
end

Examples:
if %a == 0
print it's zero!
end

### for
A loop.
Usage: for {start range} to {end range}
{code here}
end

Examples:
for 0 to 5
print asdf
end

## Scripting
There's a rudimentary support for scripting using BASIC style linenumbering. If your inputted line starts with a number then it's treated as a part of a script and is not executed. If you want to change a line just write a new line with the same number as one you want to change.

### list
List command prints out a whole script

### run
Run command runs the script

Exaple script:
10 cls
20 input %a How old are you?
30 print You are %a years old.
