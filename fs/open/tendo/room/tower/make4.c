inherit ROOM;
void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一條林間的小路上，小路往前似乎通往一處茅廬，林
子到了這裡變得靜悄悄的，小路兩旁的松樹也比西邊的矮小，看起來有
點營養不良的樣子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/tendo/room/tower/make3",
  "west" : "/open/tendo/room/tower/make5",
]));
     set("outdoors",1);
	setup();
}


