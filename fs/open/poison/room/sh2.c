// Room: /u/r/ranko/room/sh2.c
inherit ROOM;

void create ()
{
  set ("short", "雜貨店");
  set ("long", @LONG
一間賣著日常生活必需品的雜貨店。裡面陳列著各種五金、什
物，村民們常常來此處購買日常所需，由於是村裡僅有的一間雜貨
店，所以生意雖非十分興隆，倒也還過的去。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"v2-3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/mer2.c" : 1,
]));
  set("light_up", 1);

  setup();
}
