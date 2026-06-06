// Room: /u/f/fire/room/room1-11.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
喧嚷的人聲，也較為平息了。突然間，你聞到一股濃冽的藥香，
不斷的朝你飄過來。你仔細的分辨一下方位，似乎是從北邊的店舖傳
出來的，應該是一間藥店。
LONG);

  set("outdoors", "/open/marksman");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room1-9",
  "north" : __DIR__"room1-12.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/oldman" : 1,
]));

  setup();
}
