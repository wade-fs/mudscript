inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG + "結界蟲" + NOR,({"worm"}));
        set_weight(10);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
        set("value",100);
        set("unit","堆");
        set("base_unit","隻");
        set("long",
"一隻閃爍著七彩顏色的蟲子，相傳此蟲能自由的遊走於任何一個空間，
是存在於空間與空間交會處的蟲子，如果有人不小心迷失於空間的交會
處，只要跟隨著(accompany)它就能順利的離開，但是....卻不曉得會從那
出來...
\n");
        }
        set_amount(1);
        setup();
}

void init()
{
add_action("do_accompany","accompany");
}

int do_accompany(string arg)
{
object me,ob,env;
int i;
        me = this_player();
        env = environment(me);
        if( !arg )
                return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
                return 0;
        if( ob != this_object() )
                return 0;
        if( !env->query_temp("evil-place") )
                return notify_fail(HIG + "結界蟲躲在你的胸口處不敢出來。\n" + NOR);
        message_vision(HIG + "
$N跟隨著$n" + HIG + "，只見$n" + HIG + "不斷的啃食著七彩通道～

沒多久，$N被吸入了$n" + HIG + "所咬破的地方。\n" + NOR,me,ob);
        message_vision(HIY + "\n$N突然來到了這裡。\n" + NOR,me);
        add_amount(-1);
return 1;
}
