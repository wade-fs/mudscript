//新增進階返老還童術，等級由100提升到200級。 by neverend
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;
int perform(object me, object target)
{
	int skil,skil2,new_age,young_time;
	int oldage,mud_age,pot,exp,tage;

//	一歲在mud_age為86400
	me = this_player();
	pot = me->query("potential");
	exp = me->query("combat_exp");
	tage = me->query("mud_age");

	if(me->query("force") < 1000 )
	return notify_fail("你的內力不夠﹐不能使用返老返童術。 \n");

	me->add("force",-1000);

//	if( me->query("mud_age" ) < 36*86400)
//	return notify_fail("你還年輕,還用不著使用返老返童術。\n");

	if(!me->query("functions/young"))
	return notify_fail("你並沒有學過這項技能.\n");

	if(me->query("age_young") == 1)
	return notify_fail("你已經在用了。\n");

	skil = (int)me->query("functions/young/level");

	if( skil < 20 ) young_time = 1;
	if( skil < 40 ) young_time = 2;
	if( skil < 60 ) young_time = 3;
	if( skil < 80 ) young_time = 4;
	if( skil < 101 ) young_time = 5;
	if( skil < 120 ) young_time = 7;
	if( skil < 140 ) young_time = 9;
	if( skil < 160 ) young_time = 11;
	if( skil < 180 ) young_time = 13;
	if( skil <= 200 ) young_time = 15;

	if( !me->query("quests/young") && skil > 0 && skil <= 100 )
	{

	new_age = skil*86400;

	message_vision(HIC
	"\n\t$N閉目接著口中念著咒語,$N的面容及體力發生了化學變化,就像抹了歐雷一樣."
	"\n\t                     $N變年輕了!!           \n"NOR,me);

	me->add("mud_age",-new_age);
	me->set("new_age",new_age);
	me->set("age_young",1);
	me->apply_condition("young",young_time);

	  if( me->is_fighting() ) me->start_busy(1);
//	  if(me->query("mud_age") < 0 ) me->set("mud_age",0);

	  if( skil < 100 && (int)me->query("mud_age")/86400 > skil ) 
	  {
	  function_improved("young",random(500)); 
	  }
	  me->start_busy(1);

	  return 1;
	}

	if( me->query("quests/young") == 1 )
	{
	  if( skil >= 100 && skil < 200 && (int)me->query("mud_age")/86400 > 100 )
	  {
	  skil2 = (((tage/86400)/(201-skil))-86);
//	  message_vision("skil2="+skil2+"  young_time="+young_time+"\n",me);
	    if( skil2 > skil )
	    {
	    new_age = skil2*86400;
	    }else{
	    new_age = skil*86400;
	    }

	  message_vision(HIC
	  "\n\t$N閉目接著口中念著咒語，$N的面容透晰著純淨的靈光，就像用了SKII一樣。"
	  "\n\t                     $N變年輕了!!           \n"NOR,me);

	  me->add("mud_age",-new_age);
	  me->set("new_age",new_age);
	  me->set("age_young",1);
	  me->apply_condition("young",young_time);

	    if( me->is_fighting() ) me->start_busy(1);

	    if( me->query("env/倍升") == "YES" )
	    {
	      if( exp > 30000000 )
	      {
	        if( pot < skil*2+5000 )
		{
	        function_improved("young",random(500));
	        message_vision(HIW"\t$N潛能不夠，無法激發潛能與經驗來倍升熟練度。\n"NOR,me);
		}else{
	        me->add("potential",-skil*8);
	        me->add("combat_exp",-skil*8);
	        function_improved("young",random(500)*8); 
	        message_vision(HIW"\t$N激發了本身潛能與經驗來換取熟練度之倍升。\n"NOR,me);
	        }
	      }else{
	      function_improved("young",random(500));
	      message_vision(HIW"\t$N經驗值不夠，無法激發潛能與經驗來倍升熟練度。\n"NOR,me);
	      }
	    }else{
	      {
	      function_improved("young",random(500)); 
	      }
	    }
	  }
	  
	  if( skil == 200 )
	  {

	  skil2 = (((tage/86400)/(201-skil))-86);

//	  message_vision("skil2="+skil2+"  young_time="+young_time+"\n",me);
	  new_age = skil2*86400;

	  message_vision(HIC
	  "\n\t$N閉目接著口中念著咒語，$N的面容透晰著純淨的靈光，就像用了SKII一樣。"
	  "\n\t                     $N變年輕了!!           \n"NOR,me);

	  me->add("mud_age",-new_age);
	  me->set("new_age",new_age);
	  me->set("age_young",1);
	  me->apply_condition("young",young_time);
	  }
	}else{
	  if( skil > 100 )
	  {
	  message_vision(HIR"$N未解謎完成無法使用進階的返老還童術，技能值恢復為100等級。\n"NOR,me);
	  me->set("functions/young/level",100);
	  me->set("functions/young/learned",108161);
	  }
	}


  return 1;
}

