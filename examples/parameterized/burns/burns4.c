volatile int flag0 = 0, flag1 = 0, flag2 = 0, flag3 = 0;

void * thr0(void * arg)
{
  while (1) {
        flag0 = 0;
  	flag0 = 1;	
        while (flag1 == 1 || flag2 == 1 || flag3 ==1 ) {;}
	// critical section here
        flag0 = 0;
  }
}

void * thr1(void * arg)
{
  while (1) {
        flag1 = 0;
        if (flag0 != 1) {
  		flag1 = 1;
		if (flag0 != 1) {
			while (flag2 == 1 || flag3 ==1) {;}
			// critical section here
            		flag1 = 0;
		}
        }
 }
}


void * thr2(void * arg)
{
  while (1) {
        flag2 = 0;
        if (flag0 != 1 && flag1 != 1) {
  		flag2 = 1;
		if (flag0 != 1 && flag1 != 1) {
			while (flag3 ==1 ) {;}
			// critical section here
            		flag2 = 0;
		}
        }
 }
}


void * thr3(void * arg)
{
  while (1) {
        flag3 = 0;
        if (flag0 != 1 && flag1 != 1 && flag2 != 1) {
  		flag3 = 1;
		if (flag0 != 1 && flag1 != 1 && flag2 != 1) {
			// critical section here
            		flag3 = 0;
		}
        }
 }
}

int main()
{
  __CPROVER_ASYNC_0: thr0(0);
  __CPROVER_ASYNC_1: thr1(0);
  __CPROVER_ASYNC_2: thr2(0);
  __CPROVER_ASYNC_3: thr3(0);
  

return 0;
}

