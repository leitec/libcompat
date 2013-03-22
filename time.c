#include "libcompat.h"

int has_offset = 0;
UInt32 unix_epoch;
long offset;

time_t __time(time_t *timep)
{
	UInt32 mactime;
	DateTimeRec dtr;
	MachineLocation loc;
	
	time_t res;
	
	if(!has_offset) {
		dtr.second = 0;
		dtr.minute = 0;
		dtr.hour = 0;
		dtr.day = 1;
		dtr.month = 1;
		dtr.year = 1970;
		
		DateToSeconds(&dtr, &unix_epoch);
		
		ReadLocation(&loc);
		offset = loc.u.gmtDelta & 0x00FFFFFF;
		if((offset & 0x00800000) != 0)
			offset = offset | 0xff000000;
		
		has_offset = 1;
	}
	
	GetDateTime(&mactime);
	res = (time_t) mactime-unix_epoch-offset;
	
	if(timep != NULL)
		*timep = res;
	
	return res;
}
