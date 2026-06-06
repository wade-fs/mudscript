#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","西域驛站");
    set("long",@LONG
這裡是西域的驛站, 這裡地處偏辟, 人民的穿著與中土大不相同, 令你
大開眼界
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/prayer/room/westarea/road9",
]));

    setup();
}
