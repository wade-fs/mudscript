// force.c

#include <ansi.h>

inherit SKILL;

string exert_function_file(string func)
{
//這裡是fighter 的特攻, 請lys 看一下//	
// 這裡幹嘛寫這樣?? exert.c 裡已經有設定了啊?? 應該是可以消掉這幾行..Onion(96/5/9)
        if((string)this_player()->query("class") == "fighter") {
	   if(func == "enforceup")
	      return CLASS_D("fighter") + "/snowforce/" + func;
           return "/daemon/exert/" + func;
	}

	return "/daemon/exert/" + func;
}

void skill_improved( object me )
{
	int s;

    if(me->is_ghost()) return ;
	s = me->query_skill( "force", 1 );
    if( s > 60 && s%10==9 && (int)me->query_con() < 34 ) {
		tell_object( me, HIW "由於你的內功\修煉有成﹐你的體質改善了。\n" NOR );
		me->add( "con", 2 );
        if(me->query_con() > 35)
          me->set("con",35);
	}
}

int practice_skill(object me)
{
	notify_fail("
內功\心法只能用學的，或是從運用(exert)中增加熟練度。\n");
	return 0;
}

