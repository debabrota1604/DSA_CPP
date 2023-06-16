// Client side
#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
#define PORT 8080
#define WAITTIME 1

int talkToServer(int sockFd);

int main(int argc, char const *argv[])
{
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	int sock = 0, valread, client_fd, clientPid = getpid();
	char buffer[1024] = {0};
	string hello = "Hello from client with pid " + to_string(clientPid);

	// Create socket file descriptor
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	cout << "Client (pid " << clientPid << ") started." << endl;

	// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	if ((client_fd = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	// initial message exchange
	send(sock, hello.c_str(), hello.size(), 0);
	printf("Hello message sent\n");

	sleep(WAITTIME);
	valread = read(sock, buffer, 1024);
	cout << "Server says: " << buffer << endl;

	while (talkToServer(sock) != -1)
		;

	// closing the connected socket
	close(client_fd);
	return 0;
}

int talkToServer(int sockFd)
{
	char buffer[1024] = {0}, resp[1024] = {0};
	string inp, arr = "6 41 3 99 75 30 28 5 65 75";

	// Operation Choice
	cin >> inp;
	send(sockFd, inp.c_str(), inp.size(), 0);
	cout << "Choice sent to server\n";

	// Input Data send
	sleep(WAITTIME);
	read(sockFd, buffer, 1024);
	cout << "Server says: " << string(buffer) << endl;

	if (!strcmp("Exiting...\0", buffer)){
		cout << "Exit Signal received from server" << endl;
		return -1;
	}
	if (!strcmp("Enter correct option:\0", buffer)){
		return 1;
	}

	send(sockFd, arr.c_str(), arr.size(), 0);
	cout << "Input numbers sent to server\n";

	// Receive output data
	sleep(WAITTIME);
	read(sockFd, resp, 1024);
	cout << "Server Response: " << resp << endl;

	return 1;
}
