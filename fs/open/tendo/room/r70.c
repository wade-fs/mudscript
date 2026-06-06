// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","掌門人休息室");
        set("long", @LONG
這裡是掌門人 陸清風 的休息室，向北的方向有兩扇窗，往西則
放著一張百年的龍骨大床，大門則是向南而開，門口還站了兩名看門
弟子。
LONG);
  set("light_up",1);
set("objects", ([ /* sizeof() == 1 */
  "/open/tendo/npc/boy2":2,
]));
set("exits", ([
        "south":__DIR__"r61",
]));
  setup();
}
