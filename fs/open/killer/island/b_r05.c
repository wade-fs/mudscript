#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW + "走道" + NOR);
set("long",@LONG
船身的搖晃加大了，彷彿在警告入侵者趕快離開，底板則大多已經腐朽，看樣
子，這艘船真的快要崩潰掉了。
LONG);
set("exits",([
"north":__DIR__"b_r04",
"south":__DIR__"b_r06",
]));
setup();
}
