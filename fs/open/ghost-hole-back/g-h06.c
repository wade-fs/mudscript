#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU + "死靈幽谷" + NOR);
set("long",@LONG
岩壁不斷的向下延伸, 往黑且深不見底的地底
延續, 如果老人說的話是真的, 那底下應該就是死
靈骨魔的大本營了, 一想到這一點, 你似乎躊躇了
一下....
LONG);
set("exits",([
"east":__DIR__"g-h04",
"down":__DIR__"g-h11",
]));
set("no_transmit",1);
setup();
}

int valid_leave(object me,string dir)
{
me=this_player();
if(dir!="down")
{
me->delete_temp("ghost-hole/down");
return 1;
}
if(me->query_temp("ghost-hole/down"))
{
tell_object(me,HIY + "又一到千里傳音隔空而來:哎哎...既然你意志堅定, 
那我也不在多說了, 希望你真的能打敗死靈骨魔...\n" + NOR);
me->delete_temp("ghost-hole/down");
return 1;
}
{
tell_object(me,HIR + "一道千里傳音隔空而來:小心啊, 一但進入死靈骨魔
的地盤, 沒有強大的力量, 只會害了自己!!\n" + NOR);
me->set_temp("ghost-hole/down",1);
return 0;
}
}
