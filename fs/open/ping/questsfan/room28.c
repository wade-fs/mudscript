// Room: /u/d/dhk/questsfan/room28
inherit ROOM;

void create ()
{
  set ("short", "虹晶橋前段");
  set ("long", @LONG
你見到三座豪光奪目，華麗不凡的晶橋。橋全長約百
步之遠、寬僅可供一人通行而已。橋上全無纜繩之類的扶
手，均需靠自身的平衡感及千斤墜造詣來通行。在右前方
處有一石碑，碑上記載著密密麻麻的甲骨文字，深奧難懂
，似是有關此橋的由來。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "godown" : __DIR__"room7",
  "run" : __DIR__"room29",
]));
  set("outdoors", "/u/d");

  setup();
}
