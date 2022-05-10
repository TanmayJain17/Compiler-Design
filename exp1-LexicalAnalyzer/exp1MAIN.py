"""
AIM: To write a program for lexical analyser which takes a C file as the input file and converts the content as tokens.

ALGORITHM:
-Read the C program file
-Create lists of key, identifiers, format specifiers and io keywords
-Read each line in the file, split the words in each line
-If the word is in any of the above lists, append it to a separate list and repeat this step till the last line of the C program
-Print the identifiers/tokens and their respective counts in the C program.

RESULT-
The given program has been successfully executed.

"""

f=open(r"C:\Users\Tanmay'PC\OneDrive\Desktop\file1.txt")
key=['int','float','string','include','stdio.h','char','break','if','else','switch','return','void'
,'while','struct','for']
iden=[]
sp={"(",")","{","}",";","&","#","$","\n",'"',","}
spec=["%d","%f","%c","%s"]
num="012345678910"
n=[]
k=[]
o=[]
l=[]
io=['scanf','printf','cin','cout']
op="+-%*=/^><"
dl=[]
F=[]
for lines in f:
 words=lines.split(" ")
 for i in range(len(words)):
    if words[i] in key:
        k.append(words[i])
    elif words[i] in io:
        l.append(words[i])
    elif words[i] in op:
        o.append(words[i])
    elif words[i] in sp:
        dl.append(words[i])
    elif words[i] in spec:
        F.append(words[i])
    elif words[i] in num:
        n.append(words[i])
    else:
        iden.append(words[i])
print("Keywords are: ")
print(set(k))
print("input/output are: ")
print(set(l))
 
print("Operators are: ")
print(set(o))
print("Special Symbols are: ")
print(set(dl))
print("Identifiers are: " )
print(set(iden))
print("Format Specifier are:")
print(set(F))
print("Constants are:")
print(set(n))