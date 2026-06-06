#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIY + "絕情樓" + NOR);
  set ("long", @LONG
這裡就是有名的「絕情樓」，你可以看到這的擺宮設可比皇宮，
你抬頭一看看到林楓坐在骷髏椅上，面帶殺氣的看著你，他旁邊
站著一位身形矮小猥瑣的人，正在商量怎麼對付你，要命的話就
趕快跑吧。
LONG);

  set("objects", ([ /* sizeof() == 4 */
"/open/love/npc/1.c":1,
  ]));
  set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"room1-3.c",
  ]));
  set("light_up", 1);

  setup();
}

