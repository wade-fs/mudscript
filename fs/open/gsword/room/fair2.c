#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "林中空地");
	set("long", "不知為什麼在茂密的樹林中，這兒竟然寸草不生，使勁的朝地上踏去,發現
這兒的土地堅硬的很，也難怪植物難以在這生根了。
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"plain9",
  "west" : __DIR__"plain7",
  "east" : __DIR__"fair3",
]) );

  set("outdoors", "/open/gsword/room" );


  setup();
}
