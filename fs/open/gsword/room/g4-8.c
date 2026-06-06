// Room: /open/gsword/room/g4-8.c
inherit ROOM;

void create()
{
 set("short", "麗景軒");
	set( "build", 61 );
  set ("long", @LONG
這裡是鄭士欣跟至友下棋飲茶的地方 ,陣陣的花香飄來 ,令人精神格
外清爽, 鳥語嗤喳 ,更讓人覺得與世隔絕 .

LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"g4-13",
]) );

set("objects",([
  "/open/gsword/npc/lu.c" : 1,
]));
  setup();
}
