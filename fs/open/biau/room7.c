// Room: /u/j/jcder/room/room3.c

inherit ROOM;

void create()
{
	set("short", "北廂通道");
	set("long", @LONG
一陣陣涼風吹習而來，你正走在北廂的通道上，向東看去，可以見到後廂
房的情景，庭中有一口井，井旁種著一些奇花異草，似乎有些不倫不類，北邊
有一排房間，隱約有人在談論甚麼，風聲沙沙，院裏還有些不知名的草，正隨
風搖曳著．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"son_room0",
  "south" : __DIR__"room6",
]));

	setup();
}
