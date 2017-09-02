#include "../ch12/StrBlob.h"
#include "../ch12/StrBlobPtr.h"

int exec13_07_main()
{
	StrBlob sb1({ "copy-assignment" });
	StrBlob sb2 = sb1;

	StrBlobPtr sbp1(sb1);
	StrBlobPtr sbp2 = sbp1;
	// just copy the members' value
	return 0;
}