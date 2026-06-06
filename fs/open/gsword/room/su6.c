// Room: /open/gsword/room/su6.c

inherit ROOM;

void create()
{
	set("short", "青石小徑");
	set("long", @LONG
走在青石小徑上,這裡已不是蜀中鬧區,高大的建築漸漸減少,取代
的是一般平房,人潮,也漸漸的消失了.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"su7",
  "west" : __DIR__"suroom1",
  "east" : __DIR__"su5",
]));

        set("outdoors","/open/gsword");
	setup();
}
