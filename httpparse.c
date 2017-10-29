#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define buffer 1024

int httpparse (char *request, int s) {

	/*char *requestCopy = malloc(sizeof(char)* strlen(request));
	printf("XD\n");
	char *method, *requestURI, *version;
	int bytes = 1024;
	int moreBytes;
	printf("lol\n");
	requestCopy = strcpy(requestCopy, request);
	method = strtok (requestCopy, " ");
	requestURI = strtok (NULL, " ");
	version = strtok (NULL, "\n");
	printf("ouch\n");

	if (strncmp (version, "HTTP/1.1", 8) != 0) {
		printf("ouchies\n");
		write (s, "HTTP/1.1 400 Bad Request\n", 25);
		return -1;
		printf("RIP\n");
	}

	printf("feelsbadman\n");

	if (strcmp (requestURI, "/\n") == 0) {
		requestURI = "/index.html";
	}
	printf("ouchies\n");

	if (strcmp (method, "GET") == 0) {
		write (s, "HTTP/1.1 200 OK\n", 16);
		char *str;
		char bytesArray[bytes];
		str = ".";
		str = strcat (str, "/index.html");
		int file = open(requestURI, O_WRONLY | O_APPEND);
		
		while ((moreBytes = read (file, bytesArray, bytes)) > 0) {
			write (s, bytesArray, 1);
		}
		return 0;

	}else if (strcmp (method, "HEAD") == 0) {
		return 0;
	}else if (strcmp (method, "POST") == 0) {
		return 0;
	}else if (strcmp (method, "PUT") == 0) {
		return 0;
	}else if (strcmp (method, "DELETE") == 0) {
		return 0;
	}else if (strcmp (method, "TRACE") == 0) {
		return 0;
	}else if (strcmp (method, "CONNECT") == 0) {
		return 0;
	}else if (strcmp (method, "OPTIONS") == 0) {
		return 0;
	}else {
		write (s, "HTTP/1.1 400 Bad Request\n", 16);
		return -1;
	}*/
	return -1;
}

