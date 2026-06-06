// Room: /u/m/moner/open/room/r9.c 
inherit ROOM;
 
void create ()
{
  set ("short", "大廳");
	set( "build", 153 );
  set ("long", @LONG

    這裡是張繼所擁有的大廳, 整個大廳全是古銅色的, 所有的裝飾品
也都是銅製品。目前張繼是管裡風行山寨內瑣碎雜務的三頭目, 他正在
這裡和他的心腹討論著事情, 看見你闖進來, 他惡狠狠的瞪著你, 似乎
隨時準備大開殺界。


LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room14.c",
]));
set("objects",([
"/open/ping/npc/4.c":1,
]));

  setup();
  replace_program(ROOM);
}
