
inherit ITEM;
#include <ansi.h>
void create ()
{
set_name("生命之水",({"living-water","water"}));
set("long","幽冥界稀有的產物之一, 傳說中只有掌管著幽冥界所有生物的
冥王才知道得取的方法!!");
        set_weight(30);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
set("value",1);
set("unit","滴");
set("base_unit","瓶");
}
setup();
}


void init()
{
object me=this_player();
object ob=this_object();
if(me->query_temp("ghost-hole/wis-man/know-living-water"))
{
ob->set("long","幽冥界稀有的產物之一, 傳說中只有掌管著幽冥界所有生物的
冥王才知道得取的方法!!
使用方法[cover xxx]!!
");
add_action("do_cover","cover");
}
}

int do_cover(string arg)
{
object me=this_player();
object ob,ob1,ob2;
ob=this_object();
ob2=new(__DIR__"butterfly");
ob1=present("death-butterfly",me);
if(!arg)
return 0;
if(!me->query_temp("ghost-hole/wis-man/know-living-water"))
return notify_fail("你不曉得如何使用生命之水!!\n");
if(arg!="butterfly")
return notify_fail("此生物無法利用生命之水復活!!\n");
if(!present("death-butterfly",me))
return notify_fail("你並沒有死蝶可供復活!!\n");
message_vision(HIY + "$N把生命之水滴向死蝶, 突然間, 一道光線直射入蝴蝶體內, 蝴蝶復活了!!\n" + NOR,me);
ob2->move(me);
destruct(ob1);
destruct(ob);
return 1;
}
