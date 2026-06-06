// Room: /open/dancer/room/r12-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","花叢");
  set ("long", @LONG
你發現你的四周滿是花朵，恍如置身花海之中，有些甚至是你從
未看過之品種，有一簇花叢(flower)長得特別茂盛令你不禁想多看兩
眼，而眼前的景色更是讓你以為來到了世外桃園。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "flower" : "一簇美麗的花叢，香味撲鼻。\n",
]));

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/dancer/room/r13-2.c",
  "east" : "/open/dancer/room/r12-3.c",
]));

  set("search_desc", ([ /* sizeof() == 1 */
  "flower" : "你撥開花叢忽然發現叢內有個小洞恰可容人身通過(enter)，而外表\n卻看不出來。\n",
]));

  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_enter", "enter");
}

int do_enter(string arg)
{
  object who;
  who = this_player();

  if( !arg || arg!="flower" )
    return notify_fail("你要通過什麼？\n");
  tell_object(who,"你用手撥開花叢，向著小洞鑽了進去。\n");
  who->move("/open/dancer/room/dream");
  tell_room(this_object(),"你看到"+who->query("name")+"慢慢向花叢走去，忽然就不見蹤影了。\n");
  return 1;
}
