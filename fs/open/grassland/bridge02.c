#include <room.h>
inherit ROOM;
void create()
{
        set("short","漢水大橋");
        set("long", @LONG
襄陽的地理位置在中國的版圖上實屬少見。它從東到北再
到西北，緊緊被浩瀚的漢水包圍著，樊城在北岸與其隔江相望
，成了理想的橋頭堡，這座大橋橫跨漢水兩側，是襄陽城北門
通往大漠地區的軍事要道，自古以來皆有重兵把守。
LONG);
        set("outdoors", 1);
		set("no_auc", 1);
        set("no_transmit", 1);
        set("no_scale",1);
        set("no_chome",1);
        set("exits", ([ 
        "southeast":__DIR__"bridge03",
        "northwest":__DIR__"bridge01", 		
        ]) );
  setup();
}


