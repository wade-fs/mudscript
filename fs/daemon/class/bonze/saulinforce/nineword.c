//木訣心法(woodforce.c) - 捻花指訣 by sueplan
//根據新force名稱而重新調整 by blazakira
//改為九字真言作為相反功能 by blazakira

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
        if( !me->query("bonze/force/ponaforce",1) )
        return notify_fail("要用九字真言得先學會破衲功\才行。\n");
        if( (string)me->query_skill_mapped("force")!= "saulinforce" )
        return notify_fail("九字真言要以少林內功\做基礎。\n");
        if( me->query("env/force") != "破衲功\" && me->query("env/force") != "ponaforce")
        return notify_fail("九字真言要用破衲功\來啟動。\n");
        if (me->query("force") < force/10)
        return notify_fail("你的內力不夠，無法聚神使出九字真言。\n");
        if (me->query("s_kee") < 100) //因為等級最高為100 且 限制並非指最大值
        return notify_fail("你的佛法領悟不足，無法聚神使出九字真言。\n");
        if(me->query_temp("nineword")==1) 
        return notify_fail("你已經在用了。\n");
//        if( me->query("family/family_name") != "少林派")
        if(me->query("class")!="bonze")
        return notify_fail("閣下不是少林中人，不可使用！\n");
        temp=me->query("functions/nineword/level","nineword");
        skill = (temp+temp)/2;
//因為是初級fun 效果不高 所以不延長fun時間 讓玩家刷fun 增加一點成就感
	if ( skill < 11 ) {
		message_vision(HIB + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一橫劃便結不動明王手印「臨」。\n" + NOR,me);
		}
	else if ( skill < 21 ) {
		message_vision(HIB + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一縱劃便結不動明王手印「兵」。\n" + NOR,me);
		}
	else if ( skill < 31 ) {
		message_vision(HIR + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一橫劃便結不動明王手印「鬥」。\n" + NOR,me);
		}
	else if ( skill < 41 ) {
		message_vision(HIR + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一縱劃便結不動明王手印「者」。\n" + NOR,me);
		}
	else if ( skill < 51 ) {
		message_vision(HIG + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一橫劃便結不動明王手印「皆」。\n" + NOR,me);
		}
	else if ( skill < 61 ) {
		message_vision(HIG + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一縱劃便結不動明王手印「陣」。\n" + NOR,me);
		}
	else if ( skill < 71 ) {
		message_vision(HIC + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一橫劃便結不動明王手印「列」。\n" + NOR,me);
		}
	else if ( skill < 81 ) {
		message_vision(HIC + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一縱劃便結不動明王手印「在」。\n" + NOR,me);
		}
	else if ( skill < 91 ) {
		message_vision(HIW + "$N氣沉於心運起破衲功\，激發身體內的浩瀚佛法，手一橫劃便結不動明王手印「前」。\n" + NOR,me);
		}
	else {//skill >=91~max
        message_vision(HIW + "\t一股浩然佛力灌頂觀想，$N瞬間明暸不動明王手印之真義，迅速劃出四縱五橫印\n"+
		                        HIY + "\t\t「臨˙兵˙鬥˙者˙皆˙陣˙列˙在˙前」\n"+
		                        HIW + "\t$N身上散發無限光輝，此其為不動明王九字真言中最高深的境界。\n" + NOR,me);
		}
//最多add 50
        if( skill >= saulinforce ) skill = saulinforce; //若技能等級超過內功心法則以心法為準
        if (skill > 100) skill = 100; //直接鎖死數值
        me->add("force",-force/10); //降低內力消耗
		me->add("s_kee",-skill); //增加與佛法的相關性
        me->set_temp("nineword",1);
        me->add_temp("apply/defense",skill/2);
        me->add_temp("apply/dodge",skill/2);
        me->add_temp("apply/parry",skill/2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}
 
void remove_effect(object me, int skill)
{
     int saulinforce=me->query_skill("saulinforce",1);
        message_vision("$N全身佛意散去，身上佛光漸漸化為一般光線射出。\n",me);
        me->delete_temp("nineword");
        me->add_temp("apply/defense",-skill/2);
        me->add_temp("apply/dodge",-skill/2);
        me->add_temp("apply/parry",-skill/2);
        if(skill < 100 && skill < saulinforce ) //當技能不到lv100 且不超過內功心法時 才有經驗
        function_improved("nineword",(skill*5+random(skill*5)));
}
