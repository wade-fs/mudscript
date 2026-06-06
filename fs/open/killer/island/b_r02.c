#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
在西邊有一間房間，門檻上面寫著一些你看不懂的字，由此可推得，這艘船的
所有者一定不是中原人士，但這種歪七扭八的字型，你似乎又曾經在哪裡看過，一
時之間，你也回想不出來。
LONG);
set("exits",([
"north":__DIR__"b_r01",
"south":__DIR__"b_r03",
"west":__DIR__"room01",
]));
setup();
}
