// Room: /open/main/room/r29.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 25 );
  set ("long", @LONG
	道路從這開始轉向北方延伸，遙遠的北方似乎是座森林，
	南方是高低起伏的丘陵地，東方則是一片無垠的草原，傳
	說在西北方的高地上有座雪蒼山，是武者的發源地，但這
	裡沒有路可以上去。


LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"m18",
  "west" : __DIR__"r28",
  "north" : __DIR__"r20",
  "east" : __DIR__"s19",
]));

  setup();
}
