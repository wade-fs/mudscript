// Room: /open/killer/room/r14.c
inherit ROOM;

void create ()
{
  set ("short", "訓練室");
  set ("long", @LONG
這裏是要晉升成好的殺手的地方,有許多練習生會陪你們的。
在這個地方二級殺手們可以，好好的練習自己的匕首技。
有一對聯：
      多多用匕首，技術可提昇。
      太早用暗器，基礎不穩固。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r12.c",
    "up" : __DIR__"r14u.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/train_b.c" : 3,
]));
  set("light_up", 10);

  setup();
}
