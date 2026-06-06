// Room: /u/r/ranko/room/v2.c
inherit ROOM;

void create ()
{
  set ("short", "隔世村中");
  set ("long", @LONG
你正踏在隔世村的路上，村裡的村民不時投以好奇的眼光，似
乎對於外來的訪客並不太適應。兩旁是供給村民居住的尋常農舍，
往遠方望去則可看到一片片綠油油的稻田及臨近的晒穀場。

LONG);

  set("light_up", 1);
  set("outdoors", "/u/r/ranko/room");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"v4.c",
  "west" : __DIR__"v2-3.c",
  "east" : __DIR__"v2-1.c",
]));

  setup();
}
