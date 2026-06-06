#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "房間");
  set ("long", @LONG
在一陣的錯愕之下，你不小心踏破了底板，跌出了這艘船之外，緊接著又有許
多的殘骸跟著掉了下來，『碰』的一聲，你的頭上被某種金屬重物打到，看來這艘
船真的差不多快塌掉了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"is15",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/box" : 1,
]));
  set("outdoors", 1);

  setup();
}
