// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short", "妖魔古堡大殿");
        set ("long","你好不容易可以定下來看看四周的狀況了。環顧四周，你發現到處充滿了強烈
的殺氣,剛才慘酷的戰鬥使你心有餘悸。更不時傳來陣陣妖魔的奸笑聲，但是既
已來此想回頭也來不及了，還是先到處看看再作打算......。\n
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 3 */
            "east"  : __DIR__"room2",
            "west"  : __DIR__"room12",
            
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/mob1" : 6,
      ]));

        setup();
}
