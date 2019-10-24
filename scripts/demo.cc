#include <human.h>
#include <iostream>

int main(int argc, char** argv){

	std::cout << getFileSize(argv[1]) << std::endl;
	return 0;

}
