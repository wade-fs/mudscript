inherit ROOM;

void create ()
{
  set ("short", "廣場");
	set( "build", 1 );
  set ("long", @LONG
這裡正是段雲平時傳招練功的地方, 雖然這幾年在江湖上已經少
有敵手, 但段雲每天仍會抽空在此練功試招, 並親自指導弟子武技及
學問上的問題。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"np10",
  "south" : __DIR__"np4",
  "west" : __DIR__"np9",
  "east" : __DIR__"np8",
]));
  set("light_up", 1);

  setup();
  replace_program(ROOM);
}
