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
                        "five"  : "five_poison",
                    "scorpion"  : "scorpion_poison",
                        "lyssa" : "lyssa",
                        ]);
        mapping poison_name = ([
                        "snake" : "蛇毒",
                   "firefinger" : "火雲邪毒",
                        "rose"  : "火玫瑰毒",
                        "dark"  : "深宮奇毒",
                        "five"  : "五毒神掌",
                    "scorpion"  : "蠍毒",
     
                        "lyssa" : "狂犬病",
                        ]);
        mapping need_lv = ([
                        "snake" : 10,
                   "firefinger" : 20,
                        "rose"  : 30,
                        "dark"  : 50,
                        "five"  : 60,
                    "scorpion"  : 55,
                        "lyssa" : 60,
                        ]);
        mapping fp_cost = ([
                        "snake" : 1,
                   "firefinger" : 1,
                        "rose"  : 3,
                        "dark"  : 4,
                        "five"  : 6,
                    "scorpion"  : 2,
                        "lyssa" : 6,
                        ]);
        string type;
        int my_lv = me->query_skill("shinnoforce", 1);
        int factor, need, total, my_force = me->query("force");
        if(!type=me->query("env/cure_poison"))
        return notify_fail("請先設定欲解何種毒素(set sure_poison +poisoname)。\n");
        if(undefinedp(poison_type[type]) || my_lv < need_lv[type])
        return notify_fail("你並不會解這種毒。\n");
        if(my_force < 50 )
        return notify_fail("你內力不夠，無法逼毒。\n");
        if( me->is_fighting() )
        return notify_fail("戰鬥中不能逼毒。\n");
        me == target ? factor = 3 : factor = 2 ;
        total = target->query_condition(poison_type[type]);
        if((need=total*fp_cost[type])!=0)
{
need = need / factor;
if(my_force < need) {
message_vision(HIW + "$N運起" + HIY + "琉璃心訣" + HIW + "，費盡內力幫$n逼出一些"+poison_name[type]+"。\n",me,target);
me->set("force",0);
target->apply_condition(poison_type[type],total-(int)my_force*factor/fp_cost[type]);
                        }
                else {
message_vision(HIW + "$N席地盤腿而坐,運起心法中的奧義" + HIY + "琉璃心訣" + HIW + "把"+poison_name[type]+"給逼出體外。\n" + NOR, me);
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


