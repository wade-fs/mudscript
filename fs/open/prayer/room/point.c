//check.c
#include <ansi.h>
inherit SSERVER;
int perform(object me,object target)
{
        string msg,opp;
        int a,b;
        if(!target) target=offensive_target(me);
        if((!target)
        ||(target==me)
        ||(!target->is_character())
        ||(target->is_corpse()))
                return notify_fail("探脈指只可用在其他人身上。\n");
        if (((string)me->query("class")!="healer")&&(me->query("force")<20))
                return notify_fail("你內力不足﹐無法使用探脈指。\n");
        if ((string)me->query("class")!="healer") me->add("force",-20);
        message_vision(HIC + "$N的手如風般快速地按在$n的脈門上 ....\n" + NOR,me,target);
        me->start_busy(1);
        if ((random(target->query("bellicosity"))>1200)&&(!environment(target)->query("no_fight"))) {
                tell_object(target,"你發現"+me->name()+"捉著你的手腕﹐你火氣爆漲﹗相當忿怒﹗\n");
                message_vision("$N叫道﹕你幹麼捉著我﹖我看你是活得不耐煩了﹗﹗\n",target);
                target->kill_ob(me);
        }
        opp=target->name();
        write("\n");
        if(random(10)>2) {
                if (target->query("combat_exp") > me->query("combat_exp")*10)
                msg=HIR + "你觸到"+opp+"的身體時﹐感到了一份前所未有的恐懼 ....\n" + NOR;
                else if (target->query("combat_exp") > me->query("combat_exp")*5)
                msg=HIM + ""+opp+"的力量比你強許多 ....\n" + NOR;
                else if (target->query("combat_exp")> me->query("combat_exp")*3/2)
                msg=HIG + ""+opp+"的力量比你強些許兒 ....\n" + NOR;
                else if(target->query("combat_exp")>me->query("combat_exp")*2/3)
                msg=HIY + ""+opp+"的鬥氣跟你相當的接近 ....\n" + NOR;
                else if(target->query("combat_exp")>me->query("combat_exp")/5)
                msg=HIB + ""+opp+"力量根本比不上你 ....\n" + NOR;
                else if(target->query("combat_exp")>me->query("combat_exp")/10)
                msg=MAG + "你差不多感覺不到"+opp+"的力量 ....\n" + NOR;
                else msg=CYN + "你根本感覺不到"+opp+"有任何的戰鬥力 ....\n" + NOR;
                if (target->query("max_force")>me->query("max_force")*3/2) {
                        msg+=HIB + ""+opp+"的內力看來比你高﹐";
                        if (target->query("force")>target->query("max_force")/2)
                        msg+="而且內力很充沛﹗\n" + NOR;
                        else msg+="但內力有一點不足 ....\n" + NOR;
                }
                else if (target->query("max_force")>me->query("max_force")/2) {
                        msg+=HIB + "你的內力跟對方不相伯仲﹐";
                        if (target->query("force")>target->query("max_force")/2)
                        msg+="但對方勝在內力充裕﹗\n" + NOR;
                        else msg+="但"+opp+"的內力好像不太足夠 ....\n" + NOR;
                }
                else {
                        msg+=HIB + "你的內力比"+opp+"強﹐";
                        if (target->query("force")>target->query("max_force")/2)
                        msg+="但對方充足的內力真的不容輕視﹗\n" + NOR;
                        else msg+="而且"+opp+"的內力嚴重不足 ....\n" + NOR;
                }
        write(msg);
        if (userp(target)) {
        a=(int)(target->query("learned_points")*(target->query_int()-1)
                +target->query("combat_exp"));
        b=(int)(me->query("learned_points")*(me->query_int()-1)
                +me->query("combat_exp"));
        if (a>b*3/2) write("從"+opp+"血脈的流動﹐你感到自己的技術比不上"+opp+" ....\n");
        else if (a>b/2) write(opp+"的氣息告訴你 - 你和"+opp+"的技倆其實相差不了多少 ....\n");
        else write ("你從對方的脈象看得出﹐"+opp+"的技術根本比不上你的 ....\n");
        }
        write("\n");
        return 1;
        }
        write("你的指勁點往"+opp+"的身上﹐卻觸不到穴道所在﹐無法使用探脈指 ....\n");
        return 1;
}
