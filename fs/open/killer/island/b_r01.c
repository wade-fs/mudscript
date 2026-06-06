#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
你慢步的行走，底板卻因為受重而發出"吱吱"的響聲，看來這裡結構似乎已經
快要腐朽掉了，你似乎得小心一點囉。
LONG);
set("exits",([
"north":__DIR__"b_s",
"south":__DIR__"b_r02",
]));
setup();
}
