// Server side
#include <bits/stdc++.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

#define PORT 8080
#define MAXSIZE 1024
#define WAITTIME 1
#define BACKLOG 3 // Max number of simultaneous clients

int serveClient(int, string);
string vectorToString(vector<int> vec);
vector<int> stringToVector(string inp);

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	int server_fd, new_socket, valread, opt = 1, addrlen = sizeof(address);
	char buffer[1024] = {0};
	string serverPid = to_string(getpid());
	string services = "\nChoose any service to perform:\n1.Sort an array\n2.Search in array\n3.Find avg in array\n4.Close Connection\nChoice: ";
	string hello = "Hello from server at pid " + serverPid + services;

	// Creating socket file descriptor
	// int sockfd = socket(domain, type, protocol)
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Error in socket creation");
		exit(EXIT_FAILURE);
	}

	// Set socket option to reuse port 8080
	// int setsockopt(int sockfd, int level, int optname,  const void *optval, socklen_t optlen);
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("Error setting socket options.");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	// int listen(int sockfd, int backlog);
	if (listen(server_fd, BACKLOG) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	cout << "Server (pid " << serverPid << ") listening at " << PORT << endl;

	// int new_socket= accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("Server Accept failed!");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Server accepted the client." << endl;
	}

	// initial message exchange
	sleep(WAITTIME);
	read(new_socket, buffer, 1024);
	cout << "Client says: " << buffer << endl;

	sleep(WAITTIME);
	send(new_socket, hello.c_str(), hello.size(), 0);
	cout << "Sending hello message from server...\n";

	int res=0;

	while((res = serveClient(new_socket, services)) != -1);

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}

int serveClient(int sockFd, string services)
{
	char resp[MAXSIZE]={0};
	string msg;
	vector<int> vec;
	read(sockFd, resp, 1024);
	sleep(WAITTIME);
	int choice = atoi(resp), key;
	cout << "Client choose: " << choice << "\n";
	if (choice == 1)
	{
		msg = "Enter a space-seperated integer array";
		send(sockFd, msg.c_str(), msg.size(), 0);
		sleep(1);
		read(sockFd, resp, 1024);
		vec = stringToVector(string(resp));
		
		sort(vec.begin(), vec.end());
		msg = "The sorted array is: " + vectorToString(vec);
		
		msg += services;
		send(sockFd, msg.c_str(), msg.size(), 0);
	}
	else if (choice == 2)
	{
		msg = "Enter a space-seperated integer array with search key at the end";
		send(sockFd, msg.c_str(), msg.size(), 0);
		sleep(1);
		read(sockFd, resp, 1024);
		vec = stringToVector(string(resp));
		
		key = vec.back();vec.pop_back();
		auto it = find(vec.begin(), vec.end(), key);
		if (it == vec.end())
			msg = "The key " + to_string(key) + " is not present in the array";
		else
			msg = "The key " + to_string(key) + " is found at position " + to_string(it - vec.begin());
		
		msg += services;
		send(sockFd, msg.c_str(), msg.size(), 0);
	}
	else if (choice == 3)
	{
		msg = "Enter an integer array seperated by spaces and add search key at the end";
		send(sockFd, msg.c_str(), msg.size(), 0);
		sleep(1);
		read(sockFd, resp, 1024);
		vec = stringToVector(string(resp));
		
		float sum = accumulate(vec.begin(), vec.end(), 0);
		sum /= vec.size();
		msg = "The mean of the input array is " + to_string(sum);
		
		msg += services;
		send(sockFd, msg.c_str(), msg.size(), 0);
	}
	else if (choice == 4)
	{
		msg = "Exiting...";
		send(sockFd, msg.c_str(), msg.size(), 0);
		cout << "Client choose to exit." << endl;
		return -1;
	}
	else
	{
		msg = "Enter correct option:";
		send(sockFd, msg.c_str(), msg.size(), 0);
	}
	cout << "Response sent to client" << endl;

	return 1;
}

vector<int> stringToVector(string inp)
{
	int lo = 0, iter = 0;
	string numStr;
	vector<int> res;
	while (iter != inp.size())
	{
		if (inp[iter] == ' ' || iter == inp.size() - 1)
		{
			if (iter != inp.size() - 1)
				numStr = inp.substr(lo, iter - lo);
			else
				numStr = inp.substr(lo, iter - lo + 1);
			res.emplace_back(stoi(numStr));
			lo = iter + 1;
		}
		iter++;
	}
	return res;
}

string vectorToString(vector<int> vec)
{
	string resStr = "";
	for (auto num : vec)
	{
		resStr += to_string(num) + " ";
	}
	return resStr;
}

