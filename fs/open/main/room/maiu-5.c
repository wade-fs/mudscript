// Room: /open/main/room/maiu-5.c
inherit ROOM;

void create()
{
  set ("short", "竹屋");
	set( "build", 12 );
  set ("long", @LONG
你走進一間小竹屋,這裡顯然比一般苗人的居所來的潔淨,然而
還是一般的簡陋,一張小木桌,幾張小椅子,就這樣隨地擺放.
LONG);
  set("objects",([
  "open/ping/npc/maiu-king" : 1,
  ]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"maiu-4",
]));
  setup();
}
