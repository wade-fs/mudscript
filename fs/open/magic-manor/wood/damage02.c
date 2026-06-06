#include <ansi.h>
int up(object me);

void init()
{
	object me,ob,obj,mob,room;
	int kee1,j;
	me=this_player();
	j=random(2);

	if( me->query_temp("magic-manor/kill-wood02") >= 20 )
	{
	remove_call_out("up");
	call_out("up",1,me);
	}else{
	  if( !me->query("wood-monster") && !me->is_corpse() && me->is_character() && living(me) )
	  {
	  kee1=me->query("eff_kee");
	    if( random(200) > me->query_skill("dodge") )
	    {
	    message_vision(HIR"$N"HIR"一時閃躲不及，被突來的蔓藤給刺中了!!\n"NOR,me);
	    me->receive_wound("kee",kee1/50);
	    COMBAT_D->report_status(me,1); 
	    }else{
	    message_vision(HIW"$N"HIW"及時一閃，躲過了蔓藤的攻擊!!\n"NOR,me);
	    }   
	  }

	  if( !present("wood monster",environment(me)) && !present("wood beast",environment(me)) )
	  {
	    switch(j)
	    {
	    case 0:
	    mob = new(__DIR__"npc/wood-monster02");
	    mob->move(environment(me));
	    break;

	    case 1:
	    mob = new(__DIR__"npc/wood-monster02");
	    mob->move(environment(me));
	    mob = new(__DIR__"npc/wood-monster02");
	    mob->move(environment(me));
	    break;
	    }
	  }
	}
	return ;
}

int up(object me)
{
	me=this_player();
	message_vision(HIG"綠色的靈氣包圍漸漸褪去，一個向上的樓梯漸漸成形在$N眼前。\n"NOR,me);
	me->move("/open/magic-manor/wood/up02");
}
