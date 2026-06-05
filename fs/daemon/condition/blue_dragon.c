#include <ansi.h>
int i,j,k;

int update_condition(object me,int duration)
{
	if( duration >= 1 )
	{
		int i = (int)me->query("combat_exp");

		tell_object(me,HIG + "\n龍滅之魂，遊走於你腦中，啃食著你的記憶與經驗!!\n" + NOR);

		if( me->query("/open/forest/clear_blue_dragon") )
		{
			me->delete("/open/forest/clear_blue_dragon");
			me->clear_condition("blue_dragon");
			k = (int)me->query("/open/forest/combat_exp");
			(int)me->set("combat_exp", k );
			me->delete("/open/forest/combat_exp");
			tell_object(me,HIC + "藏於體內的封魄水晶，發現龍滅之魂，霎時將其困住!你回覆了所有記憶與經驗!!\n\n" + NOR);
		}
			
		else 
		{
			if( !me->query("/open/forest/combat_exp") )
			{
				tell_object(me,HIG + "你眼神呆滯...頓時遺失一部份功\力!!\n\n" + NOR);
				(int)me->set("/open/forest/combat_exp", i );
				(int)me->add("combat_exp", -i/2);
			}
			else
			{
				j = (int)me->query("/open/forest/combat_exp");
				if ( i > j/10 )
				{
					tell_object(me,HIG + "你的功\力減退了不少...\n\n" + NOR);
					(int)me->add("combat_exp", -j/20);
				}
				else
				{
					tell_object(me,HIW + "你漸漸遺忘了一些招式...\n\n" + NOR);
					(int)me->set("combat_exp",j/10);
				}
			}
		}
	}

		if( duration < 1 )
			return 0;
	return 1;
}
