avr-gcc -Og -mmcu=atmega1284p -Lliblcd  -Llibio -Llibadc -Lmainsreq -Llibalg -o main.hex main.c -llcd -lio -ladc -lmainsreq -lalg

