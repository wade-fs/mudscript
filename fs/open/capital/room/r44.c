// Room: /open/capital/room/r44.c

inherit ROOM;

void create ()
{
  set ("short", "日升馳道");
  set ("long", @LONG
城東的車馬大道。看見東面高聳堅固的城牆，看見特為軍隊而設的
大道，不禁感嘆一國不可一日無兵。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"h16.c",
  "south" : __DIR__"r43",
  "north" : __DIR__"r45",
]));
  set("gopath", "south");

  setup();
}
