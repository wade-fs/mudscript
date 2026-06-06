// Room: /open/capital/room/h10.c

inherit ROOM;

void create ()
{
  set ("short", "芝麻胡同");
	set( "build", 48 );
  set ("long", @LONG
你可以看到兩旁的民宿屋頂上不時冒出陣陣的炊煙，引的你肚子咕
嚕咕嚕的叫了起來，在你的北方有一家全國知名的食堂叫做王安食堂，
不過勸你身上錢不夠千萬別進去。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"h09",
  "north" : __DIR__"food",
  "east" : __DIR__"h11",
]));
  set("outdoors", "/open/capital");

  setup();
}
