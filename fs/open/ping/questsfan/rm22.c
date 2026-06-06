// Room: /u/d/dhk/questsfan/rm22
inherit ROOM;

void create ()
{
  set ("short", "左林曲徑");
  set ("long", @LONG
這裡是約是嵩山山腰處，往西北走好像會通往〝石林〞。
此地依舊雲霧迷濛，氣氛神秘，奇聲隨侍左右。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"rm15",
  "southeast" : __DIR__"rm8",
]));
  set("outdoors", "/u/d");

  setup();
}
