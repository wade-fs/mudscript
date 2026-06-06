// Room: /open/scholar/room/wife.c 
inherit ROOM;
 
void create ()
{
  set ("short", "臥房");
	set( "build", 135 );
  set ("long", @LONG
這裡是雷霸與他老婆茵茵居住的臥房, 臥房中只見茵茵一人獨自在
臥房內坐著, 只見她正一邊刺著繡, 一邊哭著, 一看你闖進來便朝
你殺了過去。

LONG);

  set("exits", ([ /* sizeof() == 1 */
"east":"/open/ping/room/r1",
]));
set("objects",([
"/open/scholar/npc/ra_wife.c":1,
]));

  setup();
  replace_program(ROOM);
}
