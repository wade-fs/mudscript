// Room: /u/r/ranko/room/v2.c
inherit ROOM;

void create ()
{
  set ("short", "隔世村中");
  set ("long", @LONG
你正踏在隔世村的路上，村裡的村民不時投以好奇的眼光，似
乎對於外來的訪客並不太適應。兩旁是供給村民居住的尋常農舍，
往遠方望去則可看到一片片綠油油的稻田及臨近的晒穀場。
    往北是村長的家，村長是個樂於助人的人，你若有困難的話，
不妨去拜訪村長一下，也許他能幫忙。
 
LONG);

  set("light_up", 1);
  set("outdoors", "/u/r/ranko/room");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"v5.c",
  "west" : __DIR__"v2-7.c",
  "east" : __DIR__"v2-5.c",
]));

  setup();
}
