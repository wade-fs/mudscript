// Room: /open/capital/room/h16.c

inherit ROOM;

void create ()
{
  set ("short", "蘿蔔胡同");
	set( "build", 12 );
  set ("long", @LONG
	北面有座大屋，大門上貼著一副對聯，上頭寫著：

	             奇珍異寶我照收；

  	             破銅爛鐵亦不拒。

	門上的橫聯寫著：「今日有人，典當請內洽。」

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/vendor" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"h15",
  "north" : __DIR__"caphock",
  "east" : __DIR__"r44",
]));

  setup();
}
