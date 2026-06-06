// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡內部");
        set ("long","只見四周充滿了濃濃的綠色妖氣，令你有點喘不過氣來。茫茫中只見
黃色妖怪的身影若隱若現,彷彿隨時會跳出來吃人似的。你的手心不
禁已冒出了冷汗...。

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room3",
            "west"  : __DIR__"room1",
            
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/mob2" : 5,
      ]));

        setup();
}
