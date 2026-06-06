// room1.c by roger

inherit ROOM;
#include <ansi.h>
#include "mountain.msg"
void create () {
set ("short",HIC"冰蟾洞內"NOR);
   set ("long","
這裡就是千年冰蟾所住的洞穴。出乎意料的，這大毒物所住的洞穴卻是出
其的乾淨，沒有一絲惡臭，地上更是乾乾淨淨的。洞內倒是挺寬敞的，壁
上凝結著一閃一閃的結晶物，搞不好還是天然的水晶呢。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"entrance",
      ]));

       set("objects",([ /* sizeof() == 1 */
       __DIR__"npc/ice-frog" : 1,
                      ]));

        setup();
}
