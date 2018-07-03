all:
	gcc createShell.c -o createShell
clean:
	rm -f ./createShell
install:
	gcc createShell.c -o createShell
	install createShell /bin/createShell

uninstall:
	rm -f /bin/createShell

