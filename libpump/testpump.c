#include <u.h>
#include <libc.h>
#include <pcall.h>
#include <rcall.h>

#include <stdlib.h>
#include <assert.h>

int
main(int argc, char **argv)
{
	fmtinstall('C', Pcallfmt);

	uint8 pkt[] = {
		0x50, 0x00, 0x07, 0x18, 0xde, 0xad, 0xbe, 0xef, 0x01, 0x03, 0x03, 0x00,
		0xb8, 0x1f, 0x0c, 0x38, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x1f, 0x00,
		0x00, 0x01, 0xb0, 0xff, 0x00, 0x30, 0x04, 0x00, 0x2f, 0xfd, 0x9c, 0x9f,
		0x19, 0xc5, 0x50, 0x6f, 0xa7, 0x00, 0x00, 0x00, 0x08, 0x34, 0x22, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	Pcall c;

	assert(convP2C(pkt, &c) == 0);
	assert(c.type == Rstatus);

	assert(c.status.month == 12);
	assert(c.status.day == 31);
	assert(c.status.hour == 12);
	assert(c.status.minute == 56);
	
	assert(c.status.basal == 250);
	assert(c.status.insulin == 31);
	assert(c.status.temp == -80);
	assert(c.status.temptime = 192);
	assert(c.status.temptotal == 240);
	
	dprint("%C\n", &c);

	print("ok\n");
  exit(0);
}

int
rcall(Rcall *tx, Rcall *rx)
{
	werrstr("not implemented");
	return -1;
}

int
radioreset()
{
	werrstr("not implemneted");
	return -1;
}
