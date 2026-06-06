inherit ROOM;
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是說要加這一行嗎?
        set("short",HIC + "-四象迷宮-" + NOR);
        set("long", @LONG
虛幻漂渺你不知身在何方，眼前竟是各種古代神獸，有青龍、朱崔、神龜
、白虎。且不時發出陣陣的吼聲、使你不知如何是好。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "青龍" : "/open/wu/room/gen6",
  "白虎" : "/open/wu/room/gen3",
  "朱雀" : "/open/wu/room/gen5",
  "玄武" : "/open/wu/room/gen4",
]));
  set("no_transmit",1);
  set("no_auc",1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/corpse" : 4,
]));
  setup();
}
