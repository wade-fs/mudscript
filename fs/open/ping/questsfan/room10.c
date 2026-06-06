// Room: /u/d/dhk/questsfan/room10
inherit ROOM;

#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "晶谷入口");
  set ("long", @LONG
你定神一看，嚇了一跳。剛剛在木柵外看此地外觀像
足一座小山嶺，豈知一通過木柵後，映入眼簾的竟是一座
山谷而呈旋渦狀向下。由此地整個鳥瞰下，所見之奇景，
四周閃爍著各色的光華，各色似水晶的珍礦實所生平未見
。
LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room11",
  "out" : __DIR__"qroom/room5",
]));

set("need_key/out",1);
create_door("out",HIY + "大木柵柵門" + NOR,"enter",DOOR_LOCKED);
  setup();
}
