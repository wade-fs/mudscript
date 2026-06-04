//2004/3/1修改 by Guetenr
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
        int bone_lv,evil_lv;
        int j;
        string msg;
        object weapon;
        string *name;
        bone_lv=(int)me->query("functions/melt-bone/level");
        evil_lv=(int)me->query("functions/evil-poison/level");
        j=random(100);
        if( !target ) target = offensive_target(me);
        if(!target) return notify_fail("可能是精神錯亂的關係,你竟然找不到敵人在那??\n");
        //不可以攻擊自己by bss
        if(target==me) return notify_fail("攻擊自己???找死嗎?\n");
        if(!me->is_fighting(target))
        return notify_fail("化骨綿掌只能在戰鬥中使用。\n");
        if(me->query("family/family_name")!="冥蠱魔教")
        return notify_fail("不是毒教教徒，不給你用\n");
        //取消當敵人busy時不可連放的限制, 但如果對方busy時再放敵人不busy,
        //僅有傷害的損傷
        //if(target->is_busy())
        //return notify_fail("敵人busy中，快攻擊吧！\n");
        if ( me->query("force") < 310 )
        return notify_fail("你的內力不夠\n");
        message_vision(HIC + "$N左手一收 ,一股腥臭之氣在$N手中凝聚 ,剎那間 ,天地變色 ,鬼哭神嚎!!\n" + NOR,me,target);
        message_vision(HIC + "\n$N左手微拍 ,低呼" + HIR + "『  化骨綿掌!! 』 " + HIC + "$N陰毒掌風悄然向$n飄去!! \n" + NOR,me,target);
        if(80>random(100)) {
        if( j >= 95 && bone_lv>=90 && target->query_temp("no_die_soon")!=1)
            {
            me->add("force",-300);
            target->receive_damage("kee",1,me);

            message_vision(HIY + "$N的將真氣凝灌雙掌 ,砰的一聲 ,$n化為血水!!\n" + NOR,me,target);
            message_vision(HIY + "哇哇....眼看著$n化為一攤血水 ,真是噁心死了......\n" + NOR,me,target);  
            target->die();          
            }
        else if( bone_lv <= 40)
            {
            me->add("force",-200);

            target->receive_damage("kee",(200+(bone_lv*3)+(evil_lv*3)));
            if(!target->is_busy()) target->start_busy(1);
            message_vision(HIG + "只見$N掌風悄巧的朝敵人飄去 ,$n雖已有所警覺 ,但仍被掌風掃中!!\n" + NOR,me,target);
            message_vision(HIY + "$n被$N所發出的掌風掃中 ,受到不小的傷害!\n" + NOR,me,target);
            COMBAT_D->report_status(target);
            }
        else  if( bone_lv >= 41 && bone_lv <= 80)
            {
            me->add("force",-250);
            target->receive_damage("kee",(250+(bone_lv*4)+(evil_lv*4)));
            if(!target->is_busy()) target->start_busy(2);
            message_vision(RED + "只見$N掌風似有似無般飄向$n ,$n閃避不及 ,已中掌風!!\n" + NOR,me,target);
            message_vision(HIY + "煞那間 ,$n身上多出一道掌印 ,顯然受傷不輕!!\n" + NOR,me,target);
            COMBAT_D->report_status(target);
            }
        else if( bone_lv >= 81) {
            me->add("force",-300);
            target->receive_damage("kee",(300+(bone_lv*5)+(evil_lv)*3));
            if(!target->is_busy()) target->start_busy(3);
            message_vision(HIC + "只見$N掌風似一陣薄暮輕煙般飄向$n ,$n在渾然不覺下 ,已慘遭毒手!!\n" + NOR,me,target);
            message_vision(HIY + "不知怎麼的 ,$n鮮血狂噴 ,已頹然倒下!!\n" + NOR,me,target);
            COMBAT_D->report_status(target);
        }
        } else {
            message_vision(HIW + "天哪 ,掌風竟朝$N自己飄來 ,啊啊!!真是遜斃了!!!\n" + NOR,me,target);
            message_vision(HIY + "只見$N左手一陣亂搖 ,而$n毫髮無傷地站在原地\n" + NOR,me,target);
        }
            me->start_busy(1);
        if( bone_lv < 100) function_improved ("melt-bone",random(700));
            return 1;
}
        
