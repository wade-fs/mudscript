//排版 by blazakira 2011/10/11

inherit ROOM;

void create ()
{
  set ("short", "盜草屋");
  set ("long", @LONG
這裡就是盜賊頭子蔣風的居所。由稻草搭成的房子，樸素的擺
設，絕對令人意想不到當初名震京城的”百技神學”現在竟落魄地
躲在這個簡陋的小屋。眼前這個坐在床緣的蓄鬍男子，應該就是蔣
風了吧？

LONG);

  set("objects", ([ /* sizeof() == 1 */
    "/daemon/class/bandit/bandit_master.c" : 1,
  ]));
  set("light",1);
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"b12",
  ]));
  setup();
}
