inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY"不死鳥ソ塔休閒小站"NOR);
        set ("long", @LONG 
這裡是塔頂的一個小房間，微涼的陣風，彿去剛才
的炎熱感。

LONG);
        set("light", 1);
        set("no_auc", 1);
        set("no_quit", 1);
        set("no_scale",1);
        set("no_chome", 1);
        set("no_transmit",1);
  set("exits", ([ /* sizeof() == 8 */
      "out" : "/open/beggar/tower/top",
]));

        setup();
}

