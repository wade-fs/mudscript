// Room: /open/dancer/room/roome1.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set( "build", 12 );
  set ("long", @LONG
夜夢小築的走廊，一路向東接連，北面的牆上有著美麗的雕塑，
走到這裡你聞到陣陣花香，原來你已經接近夜夢小築的花園了，西邊
是夜夢大殿。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"start",
  "east" : __DIR__"roome2",
  "north" :__DIR__"roomen1",
]));

  set("light_up", 1);

  setup();
}
