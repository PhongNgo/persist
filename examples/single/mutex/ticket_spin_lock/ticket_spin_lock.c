volatile int x = 0, y = 0, tkt1 = 0, tkt2 = 0;

void * thr1(void * arg)
{
  while (1) {
        __CPROVER_atomic_begin();
        tkt1 = y;
        y = tkt1 + 1;
        __asm volatile ("mfence":::"memory");
	__CPROVER_atomic_begin();

        while (x != tkt1) {;}

	x = x + 1;
  }
}

void * thr2(void * arg)
{
  while (1) {
        __CPROVER_atomic_begin();
        tkt2 = y;
        y = tkt2 + 1;
        __asm volatile ("mfence":::"memory");
	__CPROVER_atomic_begin();

        while (x != tkt2) {;}

	x = x + 1;
  }
}


int main()
{
  __CPROVER_ASYNC_0: thr1(0);
  __CPROVER_ASYNC_1: thr2(0);
//thr2(0);

return 0;
}

