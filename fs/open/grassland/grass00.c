#include <room.h>
inherit ROOM;
#include "grass_msg.c"

void create()
{
        set("short","蒙古草原");
        set("long", (: printf_msg :) );
        set("outdoors", 1);
        set("exits", ([
        "north":__DIR__"grass01", 
        ]) );
  setup();
}


void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)

{
  object        me;
  if (!str || 
      (str != "mount" && str != "mountain" && str != "山"
       ))
    return notify_fail("你爬呀爬呀......你爬了半天還是不敢下去.....\n");

  me = this_player();
  message_vision("$N展開絕世輕功\，依附著岩石，輕輕鬆鬆的爬下山壁。\n", me);
  me->move(__DIR__"entrance3.c");


  tell_room(environment(me), sprintf ("%s左足一點，右足一蹬，氣定神閒的爬下了山壁。\n",
        me->short()), me);
  return 1;
  }
