// Room: /u/d/dhk/questsfan/rm6
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林"HIG"麒"NOR"路");
  set ("long", @LONG
勞過許多彎彎曲曲、崎嶇不平的山路。總覺得好像路都
走不完似的，但是總算一路平安。這時你又發現一塊快腐爛
的木牌，上面的字還好依舊可以辨識。你仔細一看才知那原
是一快警示牌：『 附近有一頭上古水晶麒麟，此地乃其地盤
，勿逗留…………神鑑奇俠留。』

LONG);

  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"rm7",
  "eastdown" : __DIR__"rm5",
]));

  setup();
}
