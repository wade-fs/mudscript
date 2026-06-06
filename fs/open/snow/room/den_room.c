#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
           set("short","精武閣");
          set("long",@LONG
這裡是雪蒼派眾弟子平時練功時的練功房﹐平時師兄弟們過招習武
都在這裡﹐這裡是雪蒼派弟子每天都要來的地方﹐每天一早﹐授技長老
的會來此清點弟子及指導武功。
LONG);
        set("exits", ([
          "east": __DIR__"room6",
        ]) );
         set("objects",([
/*
	SNOW_NPC"li_lin":1,
*/
	SNOW_NPC"snow_trainee":3,
         ]));
	set("light_up",1);
      setup();
}
