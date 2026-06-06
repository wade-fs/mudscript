// Room: /open/main/room/r3.c

inherit ROOM;

void create()
{
	set("short", "道路");
    set("long", "這裡是從驛站通往絕情門的重要道路，東邊的沼澤地一不小心會把
人整個吞進去，西方有一大塊平地，道路在此呈南北向和東北方，
是個三叉路段。
");

set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"r2",
  "south" : __DIR__"r5",
  "west" : __DIR__"L3",
  "east" : __DIR__"p1",
]));



  setup();
}
