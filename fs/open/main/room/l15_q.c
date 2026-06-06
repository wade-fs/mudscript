// Room: /open/main/room/L15.c
#include "/open/open.h"

inherit ROOM;

void create()
{
	set("short", "哭風坡");
	set("long", @LONG
你看到路邊有個亭子，有不少人正圍著哈杯茶休息呢。你仔細
瞧來瞧去，唯有賣茶的老頭是你唯一感覺上認識的人。有問題的話
不妨去問問他，看他的樣子，應該知道不少事吧。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r42",
  "west" : __DIR__"L14",
  "north" : __DIR__"s25",
  "east" : __DIR__"r39",
]) );

  set("objects", ([
      MAIN_NPC"vendor"  :       1,
  ]) );
  set("outdoors", "/open/main" );

  setup();
}
