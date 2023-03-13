# sotond5

# compilation
avr-gcc -Og -mmcu=atmega1284p -Lliblcd  -Llibio -Llibadc -Lmainsreq -Llibalg -o main.hex main.c -llcd -lio -ladc -lmainsreq -lalg


# flashing
sudo avrdude -c c232hm -p m1284p -U flash:w:main.hex
