#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/stat.h> 

int httpparse (char *request, int s) {
	
	char *requestCopy = malloc(sizeof(char)* strlen(request));
	char *method, *requestURI, *version;
	int bytes = 1024;
	requestCopy = strcpy(requestCopy, request);
	method = strtok (requestCopy, " \n");
	requestURI = strtok (NULL, " \n");
	version = strtok (NULL, " \n");

	if (strncmp (version, "HTTP/1.1", 8) != 0) {
		write (s, "HTTP/1.1 400 Bad Request\n", 25);
		return -1;
	}
	
	if (strcmp (requestURI, "/") == 0) {
		requestURI = "/index.html";
		printf("%s\n", requestURI);
	}

	if (strcmp (method, "GET") == 0) {
		write (s, "HTTP/1.1 200 OK\n", 16);
		char bytesArray[bytes];
		char str[100];
		str[0] = '.';
		str[1] = '\0';
		strcat (str, requestURI);

		printf("%s", str);
		printf("\n");
		
		int file = open(str, O_RDWR);
		read (file, bytesArray, bytes);
		write (s, bytesArray, 1);
		
		/*int moreBytes;
		while ((moreBytes = read (file, bytesArray, bytes)) > 0) {
			write (s, bytesArray, 1);
		}*/
		
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
	}
	return -1;
}

