inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","聖光之扉");
set("long",@LONG
空中滿佈各型各色的魑魅魍魎，但是卻無一敢進身，此乃拜舞風揚的
妖魂顯靈所致，這些鬼怪不但奉你為天神，甚至在你身旁列隊送行，彷彿
帝皇出巡，只不過，你清楚的知道，一個在北方等待已久的四絕高手絕對
比你更有資格稱皇。
LONG);
        set("no_auc", 1);
    
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "north"   : __DIR__"room34",
      ]));
        setup();
}
