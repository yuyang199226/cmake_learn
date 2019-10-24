#include "human.h"

int main(int argc, char** argv)
{
	int a,b,c;
	a = 10;
	b = 20;
	c = add(a,b);
	if(argc < 2){
		std::cout << "Usage: human <file_path>" << std::endl;
		return 1;
	}
	int file_size;
	file_size = getFileSize(argv[1]);
	std::cout << file_size << std::endl;
	std::cout << "max number: " << max(a, b) << std::endl;
	std::cout << c << std::endl;

}
