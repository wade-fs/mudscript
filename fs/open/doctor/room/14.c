#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG

    學醫本是為救人，銀針門對於魔教使毒暗算他人的下流手段更是
恨之入骨，如果你是魔教弟子，最好不要久留於此。

LONG
        );

        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"12",           
        "west":__DIR__"15",      

        ]) );

  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是無法進入副門主的辦公房的 !\n");

   return 1;
}

