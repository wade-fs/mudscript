#include <room.h>
#include "/open/open.h"
inherit ROOM;
void do_west();
void create()
{
          set("short","雪泉洞內");
        set("long",@LONG
這裡是雪泉洞內﹐兩旁是潮溼的石壁﹐在這聽到的是流水聲
及聖獸的狂叫聲﹐傳說聖水就在洞內﹐但有聖獸保護﹐令人
不禁害怕。
LONG);
        set("exits", ([
		"south":__DIR__"water4",
		"west":__DIR__"water6",
      ]));
	set("objects",([SNOW_NPC"sec_anm2":1]));
        setup();
}
