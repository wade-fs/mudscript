//木訣心法(woodforce.c) - 捻花指訣 by sueplan
//根據新force名稱而重新調整 by blazakira

#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,force,saulinforce,temp;
        force=me->query("max_force"); 
        saulinforce=me->query_skill("saulinforce",1);
        if (me->query("class") != "bonze")
        return notify_fail("你的職業體會不到佛法。\n");
        if( !me->query("bonze/force/kingforce",1) )
        return notify_fail("要用捻花指訣得先學會金剛伏魔神通才行。\n");
        if( (string)me->query_skill_mapped("force")!= "saulinforce" )
        return notify_fail("捻花指訣要以少林內功\總綱做基礎。\n");
        if( me->query("env/force") != "金剛伏魔神通" && me->query("env/force") != "kingforce")
        return notify_fail("捻花指訣要用金剛伏魔神通來啟動。\n");
        if (me->query("force") < force/10)
        return notify_fail("你的內力不夠，無法聚神使出捻花指訣。\n");
        if (me->query("s_kee") < 100) //因為等級最高為100 且 限制並非指最大值
        return notify_fail("你的佛法領悟不足，無法聚神使出捻花指訣。\n");
        if(me->query_temp("beg_ok")==1) 
        return notify_fail("你已經在用了。\n");
//        if( me->query("family/family_name") != "少林派")
        if(me->query("class")!="bonze")
        return notify_fail("閣下不是少林中人，不可使用！\n");
        temp=me->query("functions/bergamon/level","bergamon");
        skill = (temp+temp)/2;
//最多add attack 100+apply/damage 20
        if( skill >= saulinforce ) skill = saulinforce; //若技能等級超過內功心法則以心法為準
        if (skill > 100) skill = 100; //直接鎖死數值
        me->add("force",-force/10); //降低內力消耗
		me->add("s_kee",-skill); //增加與佛法的相關性
        me->set_temp("beg_ok",1);

//因為是初級fun 效果不高 所以不延長fun時間 讓玩家刷fun 增加一點成就感
//第一層

        if (skill < 10)
        {
        message_vision(HIB + "$N氣沉於心運起金剛伏魔神通中的「明」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
        }

//第二層

        if (skill >=10 && skill < 20)
      
        {
        message_vision(HIB + "$N氣沉於心運起金剛伏魔神通中的「心」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
        }

//第三層

        if (skill >= 20 && skill < 30)
        {
        message_vision(HIR + "$N氣沉於心運起金剛伏魔神通中的「見」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
        }

//第四層

        if (skill >=30 && skill < 40)
        {
        message_vision(HIR + "$N氣沉於心運起金剛伏魔神通中的「性」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
        }

//第五層

        if (skill >=40 && skill < 50)
        {
        message_vision(HIG + "$N氣沉於心運起金剛伏魔神通中的「空」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
        }

//第六層

        if (skill >=50&& skill < 60)
        {
        message_vision(HIG + "$N氣沉於心運起金剛伏魔神通中的「徹」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
        }

//第七層

        if (skill >=60 && skill < 70)
        {
        message_vision(HIC + "$N氣沉於心運起金剛伏魔神通中的「通」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
        }

//第八層

        if (skill >=70 && skill < 80)
        {
        message_vision(HIC + "$N氣沉於心運起金剛伏魔神通中的「悟」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
        }

//第九層

        if (skill >=80 && skill < 90)
        {
        message_vision(HIW + "$N氣沉於心運起金剛伏魔神通中的「佛」字訣，手拈蓮花凝氣成針！。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/damage",skill-80); //damage額外增加
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
        }

//第十層

        if (skill >=90 && skill <= 100)
        {
        message_vision(
HIC + "                $N明瞭金剛伏魔神通捻花指訣中萬事萬物皆有萬象的佛理\n
                        " + HIY + "「明心見性    空徹通悟  」\n  
"+HIC+"               $N身上散發無限光輝，此其為捻花指訣中最高深的境界。\n" + NOR,me);
        me->add_temp("apply/attack",skill);
        me->add_temp("apply/damage",skill-80); //damage額外增加
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
        }
}
 
void remove_effect(object me, int skill)
{
     int saulinforce=me->query_skill("saulinforce",1);
        message_vision("$N全身佛意散去，身上佛光漸漸化為一般光線射出。\n",me);
        me->delete_temp("beg_ok");
        me->add_temp("apply/attack",-skill);
        if(skill >=80 ) //刪除當技能從lv80起增加的apply/damage
        me->add_temp("apply/damage",-skill+80);
        if(skill < 100 && skill < saulinforce ) //當技能不到lv100 且不超過內功心法時 才有經驗
        function_improved("bergamon",(skill*5+random(skill*5)));
}
