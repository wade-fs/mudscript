// Room: /open/badman/room/t1.c

inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
你身處在一個陰暗的地道中，幾乎伸手不見五指，凹凸不平的
地面使你不得不扶著牆壁才能慢慢移動。前頭是一片漆黑，不知道
這條地道會通往何處....

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/main/room/F12",
  "north" : "/open/badman/room/t2",
]));

  setup();
}
