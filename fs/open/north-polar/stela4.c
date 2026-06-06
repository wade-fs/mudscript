inherit ROOM;
#include <ansi.h>
#include "icestorm.c"
void create()
{
        set("short",HIC"太平洋"HIY"神殿"NOR);
        set ("long", @LONG
這裡是太平洋神殿，太平洋是世界第一大洋，深邃、寬廣、神秘
一根高聳入天的石柱佇立在此，看來就是調節太平洋水量的支柱了，
然而這石柱散發著神聖不可侵犯的氣息，使人難以靠近。
LONG);
        set("exits", ([
	"northeast"	: __DIR__"room27",
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	set("no_chome",1);
	set("no_quit",1);
	set("no_scale",1);
	set("objects", ([
           __DIR__"obj/stela4" : 1,
        ]));
        setup();
}
