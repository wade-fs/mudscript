// by sueplan 六韜勁水計修改 2000.7.26
// 計謀類型  輔助型
//減低的force值已經調好了(我是以目前儒門最高的force做基準)

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
c.取消all[i]->query("no_water")>2的限制
*************************************************************************************/

#include <ansi.h>
int perform(object me,object target)
{
    int i, k, j;
    object *all = me->query_enemy();
    object who = this_player();
    j = random(100);
    k = me->query_skill("force",1)*3;
	if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
    if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
	if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
	if(!me->is_fighting())
		return notify_fail("水計只能在戰鬥中使用。\n");
    if( me->query("sen") < 30 )
		return notify_fail("你的精神力不夠﹐無法用計。\n");
    if( me->query_skill("plan") < 70 )
		return notify_fail("你的謀略能力不夠。\n");
    // 不是儒門
    if( me->query("family/family_name") != "儒門")
		return notify_fail("不是儒生，不給你用咧！！^_^\n");
    me->add("sen",-20);
    message_vision( HIB + @LONG
$N使用六韜奇略中的勁水計，只見大水似猛虎出閘般淹到$n的面前!!
LONG + NOR , me , all[i] );
    for( i = 0 ; i < sizeof(all) ; i ++ ) 
    {
         //if(all[i]->query("no_water")>2)         
			 //message_vision( HIR "$n已看破$N的詭計，一個轉身躲過了濤濤洪水。\n"NOR,me,all[i]);
         //if(all[i]->query("no_water")>2)  continue;
      //all[i]->add("no_water",1);
      if(random(100)<80)
      {
        if( j<61&&j>40)
        {
			message_vision( HIR"$N大水似浪潮般地打向$n！！\n"HIW"$n驟時發覺身上毫無力氣，竟然是傳說中水淹五萬大軍的"HIG"『"HIC"猛  水  計"HIG"』"HIW"!\n"NOR , me , all[i] );
            all[i]->add( "force" ,-k*2);
            me->add("force",k*2/5);
            COMBAT_D->report_status( all[i] );
        }
        if( j<81&&j>60)
        {
			message_vision( HIR"$N大水似浪潮般地打向$n！！\n"HIW"$n驟時發覺身上毫無力氣，竟然是傳說中水淹十萬大軍的"HIG"『"HIC"困  水  計"HIG"』"HIW"!\n"NOR , me , all[i] );
            all[i]->add( "force" ,-k*3);
            me->add("force",k*3/5);
            COMBAT_D->report_status( all[i] );
        }
        if( j<91&&j>80)
        {
			message_vision( HIR"$N大水似浪潮般地打向$n！！\n"HIW"$n驟時發覺身上毫無力氣，竟然是傳說中水淹三十萬大軍的"HIG"『"HIC"惡  水  計"HIG"』"HIW"!\n"NOR , me , all[i] );
            all[i]->add( "force" ,-k*4);
            me->add("force",k*4/5);
			COMBAT_D->report_status( all[i] );
        }
        if( j>90)
        {
			message_vision( HIR"$N大水似浪潮般地打向$n！！\n"HIW"$n驟時發覺身上毫無力氣，竟然是傳說中水淹五十萬大軍的"HIG"『"HIC"水淹荊州城"HIG"』"HIW"!\n"NOR , me , all[i] );
            me->add("force",k*5/5);
			all[i]->add( "force" ,-k*5);
			COMBAT_D->report_status( all[i] );
        }
        if( j<41)
        {
			message_vision( HIR"$N大水似浪潮般地打向$n！！\n"HIW"$n驟時發覺身上毫無力氣，竟然是傳說中水淹一萬大軍的"HIG"『"HIC"臨  水  計"HIG"』"HIW"!\n"NOR , me , all[i] );
            me->add("force",k/5);
            all[i]->add( "force" ,-k);
            COMBAT_D->report_status( all[i] );
		}
	}
    else 
    message_vision( HIC + @LONG$n見情勢不妙﹐跑到了高處﹐逃過了一劫﹗
LONG + NOR , me ,all[i] );
  }
  return 1;
}
