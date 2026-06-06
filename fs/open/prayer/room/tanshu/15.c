// Room: /open/prayer/room/tanshu/15.c

inherit ROOM;

void create()
{
	set("short", "偏廳");
	set("long", @LONG

    一些門生在此來來往往，看起來好像很忙碌的樣子，為的只是把
總壇交附下來的任務完成，萬一有什麼閃失，個人可擔當不起，往北
走就是後院了。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"7.c",
  "north" : __DIR__"17.c",
]));
	set("light_up", 1);
	set("no_clean_up", 0);

	setup();
	}
