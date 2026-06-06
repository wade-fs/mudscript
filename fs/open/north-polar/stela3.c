inherit ROOM;
#include <ansi.h>
#include "icestorm.c"
void create()
{
        set("short",HIC + "洞庭湖" + HIY + "神殿" + NOR);
        set ("long", @LONG
這裡是洞庭湖神殿，洞庭湖為中土長江流域之中的第二大湖泊，
一根高聳入天的石柱佇立在此，看來就是調節洞庭湖水量的支柱了，
然而這石柱散發著神聖不可侵犯的氣息，使人難以靠近。
LONG);
        set("exits", ([
	"east"	: __DIR__"room17",
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	set("no_chome",1);
	set("no_quit",1);
	set("no_scale",1);
	set("objects", ([
           __DIR__"obj/stela3" : 1,
        ]));
        setup();
}
