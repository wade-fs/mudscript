// Room: /open/prayer/room/tanshu/18.c

inherit ROOM;

void create()
{
	set("short", "後院");
	set("long", @LONG

    陣陣花香朝你撲鼻而來，美麗的花蝴蝶在花叢中，舞出曼麗的舞
姿，黃鶯在枝頭上唱著清脆嘹亮的歌聲，正是鳥語花香的淨地，令你
想不到一代莽夫也能有此雅興，往北是間茅廁，東邊是柴房。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"19.c",
  "west" : __DIR__"17.c",
  "east" : __DIR__"20.c",
]));
	set("no_clean_up", 0);

	setup();
	}
