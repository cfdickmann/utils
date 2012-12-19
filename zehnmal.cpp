/*
 * zehnmal.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: cfdickmann
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;


int main( int argc,char** args)
{
	char str[1000];
	strcpy(str," ");
	for(int i=1;i<argc;++i){
		strcat (str,args[i]);
		strcat (str," ");
	}

	for(int k=0;k<10;++k)
		system(str);

	return 0;
}
