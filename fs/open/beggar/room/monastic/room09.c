#include <ansi.h>
inherit ROOM;

void create()
{
 set("short","" + HIC + "降龍堂" + NOR + "");
 set("long",@LONG
  偌大的房間裡，一尊數尺高的降龍羅漢象聳立在前方，
  一條龍磐踞在降龍羅漢的身上，纏住降龍羅漢的十二大
  要穴，彷彿在用性命保護著降龍羅漢。堂中擺了一張椅
  子，兩旁的扶手雕刻成龍頭，像是坐在龍上，看來這應
  該是幫主坐的「降龍椅」了，房間的兩旁左右各擺了幾
  張桌椅，這些應該是丐幫分舵舵主所坐的位置了。

LONG);
 set("exits",([
 "east" : __DIR__"room10.c",
 "west" : __DIR__"room08.c",
 "eastup" : __DIR__"room03.c",
 "westup" : __DIR__"room02.c",
 "south" : __DIR__"room18.c"
 ]));
 setup();
}
