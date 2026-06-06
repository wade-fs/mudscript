// Room: /open/soulin/room/r2.c

inherit ROOM;

void create ()
{
	set("short", "林間小徑");
	set("long", "	再過去有個亭子不知是做什麼的，過了亭子
	有間大寺廟應該就是少林寺了。


");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r5",
  "west" : "/open/bonze/lion_quest/q01",
  "north" : __DIR__"r8",
]) );

  set("outdoors", "/open/soulin" );


  setup();
}
