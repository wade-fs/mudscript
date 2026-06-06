// Room: /u/g/guetenr/beggar/room/beg1/room4.c
inherit ROOM;

void create ()
{
  set ("short", "平原小徑");
  set ("long", @LONG
空曠的平野彷彿終年寂靜，蔓生的野草叢中隱約有著一條小路向西及南
綿延而去，漸行漸覺地勢隨腳步而升，遠眺西邊依雲山色朦朧；迢迢山泉成
一支清流向南奔竄，幾株杜梨楊柳恣意雜生著，梨花淡白柳色青，襯著雨絲
細細柳絮翻飛，雨中嬌韻靚豔寒香，無人尋訪自芳如故。

LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room3.c",
  "west" : __DIR__"room5.c",
]));

  setup();
}
