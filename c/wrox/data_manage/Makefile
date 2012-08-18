all : application
INCLUDE=/usr/include/gdbm
LIBS=gdbm
CFLAGS=

app_ui.o: app_ui.c cd_data.h
	gcc $(CFLAGS) -g -c app_ui.c

cd_access.o: cd_access.c cd_data.h
	gcc $(CFLAGS) -I$(INCLUDE) -g -c cd_access.c

application: app_ui.o cd_access.o
	gcc $(CFLAGS) -g -o application app_ui.o cd_access.o -l$(LIBS)

clean:
	rm -f application *.o

nodbmfiles:
	rm -f *.dir *.pag
