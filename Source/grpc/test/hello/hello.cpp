#include <stdio.h>
#include <grpc/grpc.h>

int main(int argc, char* argv[])
{
	printf("grpc version=%s\n", grpc_version_string());
	return 0;
}
