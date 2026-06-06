// Room: /open/capital/room/r07.c

inherit ROOM;

void create ()
{
  set ("short", "環宮大道");
	set( "build", 24 );
  set ("long", @LONG
你現在越來越接近京城皇宮的大門口了, 你可以看到前方的宮門上
裝飾著七排拳頭大的銅環。從這裡可以遠遠地望見東西兩方的城門, 沿
著宮牆的大理基石路往兩邊延伸出去。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r05",
  "east" : __DIR__"r08",
]));
  set("gopath", "east");

  setup();
}
