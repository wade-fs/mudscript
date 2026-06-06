inherit ROOM;

void create ()
{
set("short","殺手宿舍");
  set ("long", @LONG
這裡是極為平凡的地方，一眼望去，似乎沒有一點像睡覺的地方。
這是屬於殺手的特殊設計，為了怕睡覺時被暗殺，所以你一般是看不到睡覺的人。
必定隨時都有人在守衛著，所以你想趁機殺了熟睡中的人是不可能的。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"east" : __DIR__"sr2.c",
"south" : __DIR__"sr0.c",
]));
  setup();
}
