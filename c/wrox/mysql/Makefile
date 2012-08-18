all: app
app: app_mysql.c app_test.c app_mysql.h
	gcc -g -o app app_mysql.c app_test.c -L /usr/lib/mysql -lmysqlclient
