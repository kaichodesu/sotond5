# sotond5
remake /lcdlib if updated
remake /mainsreq if updated

compilation
avr-gcc -mmcu=atmega644p -Llcdlib -o main.hex main.c -llcd

flashing
sudo avrdude -c usbasp -p m644p -U flash:w:main.hex
