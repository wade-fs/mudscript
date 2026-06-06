// Room: /open/killer/room/r14u.c
inherit ROOM;

void create ()
{
  set ("short", "訓練室");
  set ("long", @LONG
如果，想成為獨當一面的殺手就好好的在這裡向前輩們討教吧！！
他們有許多經驗，可以成為你們的參考對象。好好加油吧！
如果是新進殺手，還是乖乖的到樓下練習吧。
有一對聯：
      暗器對敵用，快速又方便。
      背刺太取巧，基礎不穩固。
LONG);

  set("exits", ([ /* sizeof() == 1 */
   "down" : __DIR__"r14.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/train_s.c" : 2,
]));
  set("light_up", 10);

  setup();
}
