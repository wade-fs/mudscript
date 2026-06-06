#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG

    一股臭藥味撲鼻而來，但是這種味道對行醫之人來說，可以使他
們更為振奮，而銀針門的弟子們也都以行醫救世為目標，牆上貼了一
些人體的穴位圖。

LONG
        );
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"17",            
        "south":__DIR__"23",          

        ]) );

  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="south"&&me->query("gender")=="男性")
        return notify_fail("男人是無法進入總管書房的 ?\n");

   return 1;
}


