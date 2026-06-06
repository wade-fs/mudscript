// Room: /open/main/room/f22.c

inherit ROOM;

void create ()
{
	set("short","道路");
	set( "build", 72 );
  set ("long", @LONG
這條路貫穿了森林 , 兩旁是高大的樹木 , 晚上一個人行
走在此 , 亂可怕的 , 不過還好 , 由於道路銜接著南方大港
楓林港 , 這裡不管是白天或夜晚 , 總是熙熙攘攘的 , 與兩
旁寂靜的森林 , 相映成趣 .

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/squirt" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"r35",
  "south" : __DIR__"s27",
  "west" : __DIR__"f21",
  "east" : __DIR__"f23",
]));

  setup();
}
