#include <room.h>

inherit ROOM;

void create()
{
	set("short","內室");
          set("long",@LONG
這裡是雪蒼派掌門平時休息的地方﹐裡面的擺設極整齊且清樸﹐只見牆上掛了對刀劍
﹐顯得極具氣派﹐相傳這對刀劍乃是雪蒼派開山祖師從一位異人手中得來的﹐只是可惜雪蒼
派開山祖師鬼影老人不會刀劍﹐否則必能以此刀劍揚名立萬。
 
 
LONG);
        set("exits", ([
	"west":__DIR__"room8",
        ]) );
     set("objects",([
     "/open/snow/npc/kai.c": 1,
]));
	set("light_up",1);
        setup();
}
