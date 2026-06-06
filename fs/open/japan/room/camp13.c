inherit ROOM;

void create()
{
  set ("short", "副隊長室");
  set ("long", @LONG
一對武士刀，正穩妥的放在刀架上。旁邊的武士盔甲存放整齊。
房間中央的矮桌上放著打粉棒、丁子油等等保養刀的工具，足可見此
人愛刀成痴。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"camp10.c",
  ]));
  setup();
}
