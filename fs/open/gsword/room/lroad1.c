#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "仙劍派前山");
	set("long", "          
你的眼前盡是垂直的峭壁，光滑的連一根草也無法在上面著根，維獨在峭壁(cliff)的
左側，顏色較趨暗色，好奇心使你想看的清楚些，不過那高度實在太高你再怎麼努
力，也無法瞧個仔細。        

");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lroad2",
  "east" : __DIR__"road1",
]) );

  set("outdoors", "/open/gsword/room" );

  setup();
}
