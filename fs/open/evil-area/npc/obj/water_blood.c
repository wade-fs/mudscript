inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB"水血"NOR,({"water blood","blood"}));
        set_weight(10);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
        set("value",10000);
        set("unit","瓶");
        set("base_unit","滴");
        set("long",
"一個無臭無味的液體，卻有著血一般的稠密度，是某個特殊邪靈的
血才會有的現象，傳說中，若將此水血置放於(puton)某處，再搖晃
(move)，使其產生波紋，則會產生一些不可思議的現象。\n");
        }
	set_amount(1);
        setup();
}

void init()
{
add_action("do_puton","puton");
}

int do_puton(string arg)
{
object me,env;
        me=this_player();
        env=environment(me);
        if(!arg || arg!="凹巢")
                return 0;
        if(!env->query("water-area") || !env->query("evil-area") || !me->query_temp("evil/king/water_search"))
        {
                message_vision("$N找不到可以放置水血的地方。\n",me);
                return notify_fail("你突然覺得自己好像傻瓜。\n");
        }
        message_vision("$N將$n放置於凹巢內。\n",me,this_object());
        env->set_temp("can_move",1);
	add_amount(-1);
        return 1;
}
