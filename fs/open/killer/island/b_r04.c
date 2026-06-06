#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
東邊有一間房間，門檻上一樣寫著一些字，但多了幾個你看的懂得漢字，你突
然回想起掌廚的魯仝所給的護身符，上面的字體跟你眼前所見的型態類似，難道這
艘船是東瀛人所建造的？
LONG);
set("exits",([
"north":__DIR__"b_r03",
"south":__DIR__"b_r05",
"east":__DIR__"room02",
]));
setup();
}
