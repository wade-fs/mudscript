// Room: /open/capital/room/r33.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
北邊便是是京城裡的衙門, 門口的兩尊石獅子放在兩旁, 顯的十分
的雄壯威武。路邊有個告示牌，一群人圍在那看著，多半是看些江洋大
盜的緝捕令，有時候也有些犯人斬首示眾的消息，一些閒得發慌的人們
最喜歡聚在此地指東道西，高談闊論。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/capital/obj/board" : 1,
  "/open/capital/npc/walker2" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r31",
  "north" : "/open/hall/halldoor",
  "east" : __DIR__"r34",
]));
  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
