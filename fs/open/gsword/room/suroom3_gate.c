// Room: /open/gsword/room/suroom3_gate.c

inherit ROOM;

void create ()
{
  set ("short", "林家大邸入口");
  set ("long", @LONG
這裡是蜀中富商林萬金的住宅,鮮紅的巨門前座立著兩隻貌
形兇猛的石獅﹐金艷四色的雕銅門把緊鑲在門前﹐這一看就知道
是個豪邸，也只有林家這種富豪，才敢把住宅蓋在將軍府旁.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"su12",
]));
  set("light_up", 1);

  setup();
}
