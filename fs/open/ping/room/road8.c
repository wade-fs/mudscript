// Room: /open/ping/room/road8
inherit ROOM;

void create ()
{
  set ("short", "石板拱橋");
	set( "build", 12 );
  set ("long", @LONG
這裡是一座石板拱橋,跨越了一條淙淙的小溪,小溪雖小,卻
是深不見底,當初為了建這石板大橋,可是費盡苦心呢!!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road9",
  "north" : __DIR__"road4",
]));
  set("outdoors", "/open/ping");

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
