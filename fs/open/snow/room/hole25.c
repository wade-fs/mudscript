#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
           set("short","洞穴");
          set("long","這是一間密室,你覺得這裡殺氣騰騰,,讓你有說不出來的壓迫感,覺得好像有什麼不對勁,希望趕快離開這裡。\n");
        set("exits", ([
                "out":__DIR__"hole13",
        ]) );
	set("objects",([
        SNOW_NPC"killer":1,
	]));
        setup();
}
