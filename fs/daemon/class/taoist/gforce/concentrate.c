// concentrate.c
// by airke
#include <ansi.h>

int exert(object me, object target)
{
  int mana_gain,forcelost;
  int max_m;
  if( target!=me)
       return notify_fail("「靈神訣」只能用來恢復自己的法力。\n");
  if( me->query("force") < 30 )
       return notify_fail("你的內力不夠。\n");

	
  mana_gain =me->query_skill("force");

  if(me->query("class") == "taoist")
    max_m = 5;
  else
    max_m = 4;
  mana_gain *= max_m ; 
//  if( mana_gain + me->query("mana") > me->query("max_mana") )
//       me->set("mana", me->query("max_mana"));
//  else
       me->add("mana", mana_gain);
  
  me->add("force", -30);
  me->receive_damage("sen", 10);

  message_vision(
	HIY + "$N閉目凝神﹐用紫星河心法運轉了一次「靈神訣」...\n" + HIG + "一股青氣從$N身上散出﹐匯聚在$P的頂心﹐然後緩緩淡去。\n" + NOR, me);
  if( (int)me->query("mana") > (int)me->query("max_mana") * max_m) {
   if( (int)me->query("max_mana") >= (int)me->query_skill("spells")*10 ) {
     write("當你的法力增加的瞬間你忽然覺得腦中一片混亂，似乎法力的提昇已經到了瓶頸。\n");
   } else {
     write("你的魔力提高了﹗\n");
     me->add("max_mana", 1);
   }
   if(me->query("class") != "taoist")
  me->set("mana", me->query("max_mana"));
   else
     me->set("mana",(int)me->query("max_mana") * max_m);
  }
  if( me->is_fighting() ) me->start_busy(3);

 return 1;
}

