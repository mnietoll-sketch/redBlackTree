#include "rbTree.h"

int main(){
	Tree t;

	for(int i = -10; i < 10; i++)
		insertKey(&t, i*2);
	return 0;
}
