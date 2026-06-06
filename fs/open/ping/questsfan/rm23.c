// Room: /u/d/dhk/questsfan/rm23
inherit ROOM;

void create ()
{
  set ("short", "右林曲徑");
  set ("long", @LONG
這裡是約是嵩山山腰處，往東北走好像會通往〝日日甘霖〞
。此地依舊雲霧迷濛，氣氛神秘，奇聲隨侍左右。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"rm8",
  "eastup" : __DIR__"rm11",
]));
  set("outdoors", "/u/d");

  setup();
}
