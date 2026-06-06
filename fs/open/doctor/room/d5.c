// room:open/doctor/room/d5.c made by adam..

inherit ROOM;

void create ()
{
	set("short","一號栽種區");
  set ("long", @LONG

   這裡有著整齊的花圃，正是銀針門的栽種區..

LONG);

  set("light_up", 1);
  set("outdoors", "/open/doctor");	
	set("objects",([
 	]));
  set("exits", ([ /* sizeof() == 3 */
//      "north" : __DIR__"d4",    
      "south" : __DIR__"d8",
      "east" : __DIR__"d6",
      ]));
  setup();
}
