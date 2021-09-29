#include<linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

while ( true )
       {
           int x;

	   lock(mutex);
	   if ( nItems == 0 )
	      WAIT (BLOCK); // When BLOCKED, we need some
                            // OTHER process to unblock it !

	   x = buf[readPtr++];         // Get x from buffer
	   readPtr = (readPtr+1) % N;
	   nItems--;

	   if ( writer is BLOCKED )
	      UNBLOCK writer;

	   unlock(mutex);

	   consume_value(x);
       }