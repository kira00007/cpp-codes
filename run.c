#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct FormattedFileName {
	const char *fileNameWithoutExtension;
	const char *fileExtension;
} FormattedFileName;

FormattedFileName* getFormattedFileName(const char *fileName) {
	FormattedFileName *name = (FormattedFileName*) malloc(sizeof(FormattedFileName));
	int iter0 = 0, iter1 = 0, iter2 = 0;
	char foundTheDot = 0;
	char *fileNameWithoutExtension = (char*) malloc(100 * sizeof(char));
	char *fileExtension = (char*) malloc(100 * sizeof(char));
	while(fileName[iter0]) {
		if(foundTheDot)
			fileExtension[iter1++] = fileName[iter0];
		else if(fileName[iter0] == '.')
			foundTheDot = 1;
		else
			fileNameWithoutExtension[iter2++] = fileName[iter0];
		iter0++;
	}
	fileExtension[iter1] = '\0';
	fileNameWithoutExtension[iter2] = '\0';
	name->fileExtension = fileExtension;
	name->fileNameWithoutExtension = fileNameWithoutExtension;
	return name;
}

int main(int argc, char** argv) {
	if(strcmp(argv[1],"-m")){
		char files[100] = {0};
		FormattedFileName *name = getFormattedFileName(argv[1]);
		const char* fileNameWithoutExtension = name->fileNameWithoutExtension;
		const char* extension = name->fileExtension;
		char command[120] = {0};
		for(int i = 1; i < argc; i++) {
			strcat(files, argv[i]);
			if(i != argc-1) strcat(files, " ");
		}
		// printf("files: %s\n", files);
		if(!strcmp(extension,"c")) {
			strcpy(command, "gcc -Wall ");
			strcat(command, files);
			strcat(command, " -o ");
			strcat(command, fileNameWithoutExtension);
			strcat(command, " && ");
			strcat(command, fileNameWithoutExtension);
			system(command);
		}
		else if(!strcmp(extension,"cpp")) {
			strcpy(command, "g++ -Wall -std=c++17 -pthread -O3 ");
			strcat(command, files);
			strcat(command, " -o ");
			strcat(command, fileNameWithoutExtension);
			strcat(command, " && ");
			strcat(command, fileNameWithoutExtension);
			system(command);
		}
		else if(!strcmp(extension,"java")) {
			strcpy(command, "javac ");
			strcat(command, files);
			strcat(command, " && java ");
			strcat(command, fileNameWithoutExtension);
			system(command);
		}
		else if(!strcmp(extension,"py")) {
			strcpy(command, "python ");
			strcat(command, files);
			system(command);
		}
		else if(!strcmp(extension,"exe")) {
			char executables[100];
			strcpy(executables, "");
			for(int i = 1; i < argc; i++) {
				strcat(executables, argv[i]);
				if(i != argc-1) strcat(executables, " && ");
			}
			system(executables);
		}
		free(name);
		// printf("\ncommand: %s", command);
	}
	else for(int i = 2; i < argc; i++) {
		char command[120] = {0};
		FormattedFileName *name = getFormattedFileName(argv[i]);
		const char* fileNameWithoutExtension = name->fileNameWithoutExtension;
		const char* extension = name->fileExtension;
		if(!strcmp(extension,"c")) {
			strcpy(command, "gcc -Wall ");
			strcat(command, argv[i]);
			strcat(command, " -o ");
			strcat(command, fileNameWithoutExtension);
			strcat(command, " && ");
			strcat(command, fileNameWithoutExtension);
			system(command);
		}
		else if(!strcmp(extension,"cpp")) {
			strcpy(command, "g++ -Wall -std=c++17 -pthread -O3 ");
			strcat(command, argv[i]);
			strcat(command, " -o ");
			strcat(command, fileNameWithoutExtension);
			strcat(command, " && ");
			strcat(command, fileNameWithoutExtension);
			system(command);
		}
		else if(!strcmp(extension,"java")) {
			strcpy(command, "javac ");
			strcat(command, argv[i]);
			strcat(command, " && java ");
			strcat(command, fileNameWithoutExtension);
			system(command);
		}
		else if(!strcmp(extension,"py")) {
			strcpy(command, "python ");
			strcat(command, argv[i]);
			system(command);
		}
		else if(!strcmp(extension,"exe")) {
			strcpy(command, argv[i]);
			system(command);
		}
		free(name);
	}
}