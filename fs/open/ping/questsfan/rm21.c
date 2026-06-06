// Room: /u/d/dhk/questsfan/rm21
inherit ROOM;

void create ()
{
  set ("short", "樹林左翼");
  set ("long", @LONG
這裡是約是嵩山山腰處，往西南走好像會通往〝藏仙谷〞
，不過那只是傳聞，也不知道是不是真有那地方。此地依舊雲
霧迷濛，氣氛神秘，奇聲隨侍左右。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"rm27",
  "northeast" : __DIR__"rm8",
]));

  setup();
}
