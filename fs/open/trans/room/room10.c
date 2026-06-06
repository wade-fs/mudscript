#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","楓林港驛站");
    set("long",@LONG
這裡是楓林港驛站, 因為這裡是以漁產為主, 所以你經常可以看到
漁夫們把剛捕上來的魚一袋袋的運來, 拜託驛站老闆幫他們把漁產運往
各地銷售.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/port/room/r1-3",
]));

    setup();
}
