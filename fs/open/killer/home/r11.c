// Room: /open/killer/room/r11.c
inherit ROOM;

void create ()
{
  set ("short", "訓練室");
  set ("long", @LONG
這裏是要當一個好的殺手的起點,有許多練習生會陪你們的。
在這個地方新任殺手們可以，好好的練習自己的身手。
有一對聯：
      多多用雞腿，激發出潛力。
      太早用暗器，基礎不穩固。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r13.c",
  "west" : __DIR__"r0.c",
    "up" : __DIR__"r11u.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/train_c.c" : 3,
]));
  set("light_up", 10);

  setup();
}
