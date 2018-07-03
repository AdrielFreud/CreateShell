all:
	gcc createShell.c -o createShell
clean:
	rm -f ./createShell
install:
	install createShell /bin/createShell

uninstall:
	rm -f /bin/createShell

