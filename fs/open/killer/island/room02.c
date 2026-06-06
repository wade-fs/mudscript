#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW + "走道" + NOR);
set("long",@LONG
地上到處都堆滿了武器、防具與....骨骸，看來這裡是放兵器的地方，你不由
得的懷疑起來，一艘普通的船怎麼可能會放置如此大量的武器呢？難道是做武器買
賣的商船嗎？但是由武器上磨損過的痕跡看來，似乎又不像是做買賣的，看來這裡
面一定大有文章。
LONG);
set("exits",([
"west":__DIR__"b_r04",
]));
setup();
}
