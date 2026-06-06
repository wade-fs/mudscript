#include <ansi.h>
int up(object me);

void init()
{
	object me,ob,obj,mob,room;
	int kee1,j;
	me=this_player();
	j=random(5);

	if( me->query_temp("magic-manor/kill-water06") >= 20 )
	{
	remove_call_out("up");
	call_out("up",1,me);
	}else{
	  if( !me->query("water-monster") && !me->is_corpse() && me->is_character() && living(me) )
	  {
	  kee1=me->query("eff_kee");
	    if( random(600) > me->query_skill("force") )
	    {
	    message_vision(HIR"$N"HIR"一時運功\不足，寒冰之氣凍體而過，周身留下了寒霜片片!!\n"NOR,me);
	    me->receive_wound("kee",kee1/50);
	    COMBAT_D->report_status(me,1); 
	    }else{
	    message_vision(HIW"$N"HIW"運起了內功\心法，絲絲的熱氣透體而出，抵禦了寒冰之氣的襲擊!!\n"NOR,me);
	    }   
	  }

	  if( !present("water monster",environment(me)) && !present("water beast",environment(me)) )
	  {
	    switch(j)
	    {
	    case 0:
	    mob = new(__DIR__"npc/water-beast03");
	    mob->move(environment(me));
	    break;

	    case 1:
	    mob = new(__DIR__"npc/water-monster06");
	    mob->move(environment(me));
	    mob = new(__DIR__"npc/water-monster06");
	    mob->move(environment(me));
	    break;

	    case 2:
	    mob = new(__DIR__"npc/water-monster06");
	    mob->move(environment(me));
	    mob = new(__DIR__"npc/water-monster06");
	    mob->move(environment(me));
	    break;

	    case 3:
	    mob = new(__DIR__"npc/water-beast03");
	    mob->move(environment(me));
	    mob = new(__DIR__"npc/water-monster06");
	    mob->move(environment(me));
	    break;

	    case 4:
	    mob = new(__DIR__"npc/water-beast03");
	    mob->move(environment(me));
	    mob = new(__DIR__"npc/water-monster06");
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
	message_vision(HIC"水色的靈氣包圍漸漸褪去，一個向上的樓梯漸漸成形在$N眼前。\n"NOR,me);
	me->move("/open/magic-manor/water/up06");
}
