#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
你走到這裡，船身突然搖晃了一下，底板發出的響聲也變大了，看來這裡沒多
久可能就會垮掉了，也許你應該再加緊腳步離開才對。
LONG);
set("exits",([
"north":__DIR__"b_r02",
"south":__DIR__"b_r04",
]));
setup();
}
