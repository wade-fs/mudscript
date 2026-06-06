#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "岩穴");
        set("long", @LONG
一個黑戚戚的洞穴，裡頭有著各式各樣千奇百怪的的奇岩，無數的蝙蝠倒掛在
岩石上，構成一幅令人畏懼的景象。仔細的觀察一下四周，除了一些野鳥在此
築巢外，赫然發現岩壁上，似乎有幾個拳印，但年代已久，並不是很清楚。
LONG
        );

       set("objects",([
	"/open/gsword/mob/bat.c": 3,
       ]));
        set("exits", ([
"down":__DIR__"rroad2",
"west":__DIR__"whole",
"east":__DIR__"ehole",
"north":__DIR__"nhole"
        ]) );
setup();

}
