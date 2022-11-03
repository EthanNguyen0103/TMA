#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <netdb.h>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 4096
#define PATH_MAX 1024
#define SERVER_PORT 7068
#define SERVER_BACKLOG 4


