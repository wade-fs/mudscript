// by roger
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","往魔界村小徑");
        set ("long","
  總算出了魔森林了，出現在眼前的是一條小徑，小徑的不遠處隱約有一座
村莊，村莊的四周似乎泛著隱隱和平的光芒。傳說中魔界村是個不受邪物侵
犯的地方，只有人類和低等魔物才可進入。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north"  : __DIR__"room60",
            "south" : __DIR__"room58",
      ]));

       

        setup();
}
