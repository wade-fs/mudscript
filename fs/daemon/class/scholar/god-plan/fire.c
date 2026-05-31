// By Swy 最後修正 QC 98/6/20
#include <ansi.h>
int perform(object me,object target)
{
    	int i, dam;
 	object *all = me->query_enemy();
    	if(!me->is_fighting())
		return notify_fail("火計只能在戰鬥中使用。\n");
	if( me->query("sen") < 30 )
		return notify_fail("你的精神力不夠﹐無法用計。\n");
	if( me->query_skill("plan") < 120 )
		return notify_fail("你的謀略能力不夠。\n");
	// 不是儒門
   	if( me->query("family/family_name") != "儒門")
    		return notify_fail("不是儒生，不給你用咧！！^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
    	me->add("sen",-20);

	me->start_busy(1);
	message_vision( HIR + @LONG
$N使用孔明兵法之中的火計﹗頓時現場一片的大火瀰漫著四周 .....
LONG + NOR , me , target );
	for( i = 0 ; i < sizeof(all) ; i ++ ) 
	{
if( 80 > random(100))
		{
			if( me->query("quest/gold-fire") && (me->query("combat_exp")>3000000))
			{
             dam=all[i]->query("max_kee")/3;
if(dam > 1000) dam=1000;
				message_vision( HIR + @LONG
$N大叫『極火一出，萬物具焚』，使出融合了焚天魔王極火功的儒門火計
只見陣陣火龍貫穿了$n周身大穴，造成了重創。
LONG + NOR , me , all[i] );
				all[i]->apply_condition("burn",30);  
all[i]->receive_wound( "kee" ,dam);
COMBAT_D->report_status( all[i] );
			}
			else
			{
        dam=all[i]->query("max_kee")/5;
        if(dam > 800) dam=800;
				message_vision( HIR + @LONG
$n來不及逃跑﹐因此被$N放出了火燄燒傷了﹗
LONG + NOR , me , all[i] );
				all[i]->apply_condition("burn",10);  
			all[i]->receive_wound( "kee" ,dam);
// 強力的攻擊不能再delay的人 by swy
// all[i]->start_busy(1);
			COMBAT_D->report_status( all[i] );
		}
			}
		else 
			message_vision( HIY + @LONG
$n見情勢不妙﹐跳了開來﹐逃過了一劫﹗
LONG + NOR , me ,all[i] );
	}
	return 1;
}
