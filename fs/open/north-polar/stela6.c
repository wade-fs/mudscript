inherit ROOM;
#include <ansi.h>
#include "icestorm.c"
void create()
{
        set("short",HIC + "東海" + HIY + "神殿" + NOR);
        set ("long", @LONG
這裡是東海神殿，東海，是中土與鄰國往來必經的重要水域，
一根高聳入天的石柱佇立在此，看來就是調節東海水量的支柱了，
然而這石柱散發著神聖不可侵犯的氣息，使人難以靠近。
LONG);
        set("exits", ([
	"southwest"	: __DIR__"room30",
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	set("no_chome",1);
	set("no_quit",1);
	set("no_scale",1);
	set("objects", ([
           __DIR__"obj/stela6" : 1,
        ]));
        setup();
}
