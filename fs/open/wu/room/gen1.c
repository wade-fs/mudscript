// Room: /open/wu/room/gen1.c
// 瀧山禁地入口
inherit ROOM;
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是說要加這一行嗎?
        set("short",RED + "-迷宮入口-" + NOR);
        set("long", @LONG
這是傳說瀧山派地下迷官的入口處，房間的環境陰暗潮溼仔細一看，發
現四周牆上，刻有青龍、白虎、朱崔、玄武等四種古代的神獸。北邊的
就應該是傳說中的瀧山迷宮了吧。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "up" : "/open/wu/room/luroom23",
  "north" : "/open/wu/room/gen2.c",
]));
  set("no_transmit",1);
  set("no_auc",1);
  setup();
}
