// Room: /open/capital/room/r47.c

inherit ROOM;

void create ()
{
  set ("short", "日升馳道");
	set( "build", 27 );
  set ("long", @LONG
城東的車馬大道。西邊有幾間木造的兩層木屋，幾個衛兵在前面巡
邏，看起來似乎是個很重要的地方，你想靠近去看看，衛兵卻擋著你，
不讓你靠近。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/capital/room/guardh.c",
  "south" : "/open/capital/room/r46",
  "north" : "/open/capital/room/r48",
]));
set("objects", ([ /* sizeof() == 1 */
  "/open/magic_palace/npc/sky_baby.c" : 1,
      ]));

  set("gopath", "south");

  setup();
}
