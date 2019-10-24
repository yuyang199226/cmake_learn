#include "fileHandler.h"
int getFileSize(char* fileName){
	return boost::filesystem::file_size(fileName);


}
