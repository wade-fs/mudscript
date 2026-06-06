//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "恆古之路");
  set ("long", @LONG
這是一條恆久古遠的道路，一般的平凡人很難到達這裏，除非有
得道的高人相助，開啟一條結界之路才能抵達，路的周圍充滿了不可
思議的神奇力量，神聖而不可侵犯，經由這條恆古之路各可以通往不
同的神秘天界。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 4 */
    "west"  : __DIR__"water",
//    "east"  : __DIR__"fire", //目前沒開放火封印的裝備 避免有人insert造成浪費 因而造成wiz困擾 暫時關閉之 by blazakira
    "north" : __DIR__"road03",
    "south" : __DIR__"road01",
  ]));
  set("light_up", 1);
  setup();
}
