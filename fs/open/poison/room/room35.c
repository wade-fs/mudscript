#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "瀑布上游");
  set ("long", @LONG
費盡千辛萬苦 ,終於憑著過人的輕功和敏捷的思緒登上了瀑布的
上游 ,眼看著那小屋就近在眼前了 ,快進去吧 !

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room36",
  "southdown" : __DIR__"room27",
]));
  create_door("enter", "木雕門", "out", DOOR_CLOSED);
  setup();
}


