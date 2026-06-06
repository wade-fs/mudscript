// Room: /open/main/room/M15.c

inherit ROOM;

void create ()
{
  set ("short", "少林寺山門");
  set ("long", @LONG
	爬到這石階的頂端，可以看到有一座山門，
	門上題著兩個字「少林」，字跡入木三分，
	似乎並不是用器具刻上去的。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southdown" : "/open/main/room/M19",
"enter":"/open/bonze/room/r5",
  "eastdown" : "/open/main/room/M16",
]));

  setup();
}
