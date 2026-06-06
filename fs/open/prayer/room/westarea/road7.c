//open/prayer/room/westarea/road7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 西邊是通往飄
	渺四宮的"白虎宮". 舞者的武學好像與聖火教的武學素養相差
	不多, 或許這是造成兩派一山不容二虎的原因吧!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 1 */
        	"south":__DIR__"road5",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
