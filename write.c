#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/semafore.h>



int MAX;
      int nItems = 0;     // Number of items in buffer
      int buf[MAX];



   Writer:

       while ( true )
       {
           int x;

           x = produce_next_value();

	   lock(mutex);
	   if ( nItems == N )
	      WAIT (BLOCK); // When BLOCKED, we need some
                            // OTHER process to unblock it !

	   buf[writePtr] = x;           // Put x in buffer       
	   writePtr = (writePtr+1) % N;    
	   nItems++;

	   if ( reader is BLOCKED )
	      UNBLOCK reader;

	   unlock(mutex);
       }
