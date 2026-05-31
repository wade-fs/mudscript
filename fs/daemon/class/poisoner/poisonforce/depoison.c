#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int exert(object me, object target)
{
        mapping poison_type = ([
                        "snake" : "snake_poison",
                   "firefinger" : "fire_poison",
                        "rose"  : "rose_poison",
                        "dark"  : "dark_poison",
                        "five"  : "five_poison" ,
                    "scorpion"  : "scorpion_poison",

                        ]);
 
        mapping poison_name = ([
                        "snake" : "蛇毒",
                   "firefinger" : "火雲邪毒",
                        "rose"  : "火玫瑰毒",
                        "dark"  : "深宮奇毒",
                        "five"  : "五毒" ,
                    "scorpion"  : "蠍毒",

                        ]);
 
        mapping need_lv = ([
                        "snake" : 1,
                   "firefinger" : 10,
                        "rose"  : 20,
                        "dark"  : 30,
                        "five"  : 40,
                    "scorpion"  : 35,

                        ]);
 
 
        mapping fp_cost = ([
                        "snake" : 1,
                   "firefinger" : 2,
                        "rose"  : 3,
                        "dark"  : 4,
                    "scorpion"  : 2,

                        "five"  : 5,
                        ]);
	string type;
        int my_lv = me->query_skill("poisonforce", 1);
        int factor, need, total, my_force = me->query("force");
        if(!type=me->query("env/cure_poison"))
                return notify_fail("請先設定欲解毒的種類。\n");
        if(undefinedp(poison_type[type]) || my_lv < need_lv[type])
                return notify_fail("你並不會解這種毒。\n");
        if(my_force < 20 )
                return notify_fail("你內力不夠，無法逼毒。\n");
        if( me->is_fighting() )
                return notify_fail("戰鬥中不能逼毒。\n");
   if(me->query("class")!="poisoner")
   return notify_fail("你不是魔教徒不能逼毒。\n");
        me == target ? factor = 3 : factor = 2 ;
        total = target->query_condition(poison_type[type]);
        if((need=total*fp_cost[type])!=0)
        {
                need = need / factor;
                if(my_force < need) {
                        message_vision(
HIG"$N運起冥蠱心法，費盡內力逼出一些"+poison_name[type]+"。\n");
                        me->set("force",0);
                        
target->apply_condition(poison_type[type],total-(int)my_force*factor/fp_cost[type]);
                        }
                else {
                    message_vision(
                    
HIW"$N運起冥蠱心法把"+poison_name[type]+"給逼了出來。\n"NOR, me);
                    me->add("force", -need);
		    target->apply_condition(poison_type[type], 0);
                    }
                return 1;
        }
    if(me==target)
        return notify_fail("你並沒有中這種毒。\n");
    else
	return notify_fail("他並沒有中這種毒。\n");
}
