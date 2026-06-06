// Room: /open/bonze/npc//room/s19.c
inherit ROOM;

void create ()
{
  set ("short", "$HIY$羅漢堂$NOR$");
  set ("long", @LONG

經過了一條長廊進入到這裡只看到頭上三個斗大的字-羅漢堂
原來這裡是少林寺中專門鍛鍊出身強體壯的羅漢堂.看到這裡
的少林弟子們,你心頭不禁一震.只因此處氣勢太甚

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"s18.c",
]));
  set("outdoors", "/open/bonze/npc//room");
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/konchin.c" : 1,
]));
  

  setup();
}
