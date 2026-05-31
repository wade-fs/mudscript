// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 雪亭鎮街道");
  set ("long", @LONG
這裡是雪亭鎮的大街﹐東邊有一棟陳舊的建築﹐看起來像是什麼店
鋪﹐但是並沒有任何招牌﹐只有一扇門(door)上面寫著一個大大的「當
」字﹐往西是一間藥鋪﹐大街往南北兩個方向延伸。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"herbshop",
  "north" : __DIR__"mstreet4",
  "south" : __DIR__"mstreet2",
  "east" : __DIR__"hockshop",
]));
  set("outdoors", "snow");

  setup();
}
