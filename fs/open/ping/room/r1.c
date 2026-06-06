// Room: /u/m/moner/open/room/r1.c 
inherit ROOM;
 
void create ()
{
  set ("short", "大廳");
	set( "build", 67 );
  set ("long", @LONG
這裡是雷霸所擁有的大廳, 整個大廳全是金黃色, 所有的裝飾品都
是黃金所製。雷霸為風行山寨的老大, 武功也為其最高, 他正在這
和他的心腹討論著事情, 看見你闖進來, 他惡狠狠的瞪著你, 似乎
隨時準備大開殺界。

LONG);

  set("exits", ([ /* sizeof() == 1 */
"west":"/open/scholar/room/wife.c",
  "south" : __DIR__"r2.c",
]));
set("objects",([
"/open/ping/npc/6.c":1,
]));

  setup();
  replace_program(ROOM);
}
