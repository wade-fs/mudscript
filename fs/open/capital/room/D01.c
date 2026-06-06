// Room: /open/capital/room/D01.c
#include "/open/capital/capital.h"

inherit ROOM;

void create ()
{
  set ("short", "威西門");
  set ("long", @LONG
這裡是京城的三個出入口之一，由於這裡乃是王朝的中心, 聖上的
住所所在，所以守衛的盤查也特別嚴格，如果隨便讓身份不明的人進城
鬧事，那可是吃不玩兜著走了。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/gate_soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/main/room/r15",
  "east" : __DIR__"r01",
]));

  setup();
}

int valid_leave(object me , string dir)
{
        object guard;
        guard=present("gate soldier",this_object());
        if( dir=="east" && objectp(guard) && !me->query_temp("有向城門守衛報告") )
         if(!guard->query_temp("unconcious"))
          if(!wizardp(me))
          return notify_fail("城門衛軍伸手攔著你說：完成身份確認才可以進城。\n");
        return ::valid_leave(me,dir);
}
