// Room: /open/poison/room/v10.c
inherit ROOM;

void create ()
{
  set ("short", "小木屋內");
  set ("long", @LONG
這是一間以木頭蓋的簡陋的木屋，是村長號召村裡的壯丁合力
替將軍蓋的，而將軍為了感謝村人的幫忙，亦留在此地協助維護村
裡的安寧，免受外來的侵害。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"pa4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/general.c" : 1,
]));
  set("light_up", 1);

  setup();
}
