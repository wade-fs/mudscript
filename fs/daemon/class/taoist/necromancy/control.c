#include <ansi.h>
inherit F_SPELL;
object control(object me,object base_mob,object);

int cast(object me,object target)
{   
  object base_mob , * all_control_mob ;
  int mkee=me->query("max_kee");
  seteuid(getuid());
  if(sizeof(me->query_temp("control_z")))
    all_control_mob = me->query_temp("control_z") - ({ 0 });
  if(me->query("class") != "taoist")
    return notify_fail("這法術只有道士用的出來！！\n");
  if(me->is_fighting(target))
    return notify_fail("控屍術只能在非戰鬥中使用。\n");
  if( !me->query("spells/control/level") )
    return 0;
  if(me->query("atman") < 300)
    return notify_fail("你的靈力不足。\n");
  if(me->query("mana") < 300)
    return notify_fail("你的法力不足。\n");
  if(me->query("id") != target->query("kill_id"))
      return notify_fail("這不是你所能控制的屍體！\n");
  if(!target->query("base_file") && target->query("base_file") != "/obj/user")
    return notify_fail("殭屍只能是生物和非人類的屍體。\n");
  // check 可以操作的最大數目
  if(sizeof(all_control_mob)+1 > me->query_skill("necromancy",1) / 20)
    return notify_fail("你的功\力不足以操控這麼多的殭屍\n");
  base_mob = new(target->query("base_file"));
  if(!base_mob)
    return notify_fail("找不到可以作為殭屍的屍體。\n");
  me->start_busy(1);
  me->add("atman",-300);
  me->add("mana",-300);   
  
  control(me,base_mob,target);

  return 1;
}
object control(object me,object base_mob,object target)
{
  object  * all_control_mob ;

  object mob;
  if(me->query_temp("control_z"))
     all_control_mob = me->query_temp("control_z") - ({ 0 });

  seteuid(getuid());
  mob = new ("/daemon/class/taoist/necromancy/npc/mob.c");
  if(sizeof(base_mob->query_skills() ))
  {
    foreach(string skill,int level in base_mob->query_skills() )
    {
      mob->set_skill(skill,level);
    }
  }
  if(sizeof(base_mob->query_skill_map() ))
  {
    foreach(string skill,string level in base_mob->query_skill_map() )
    {
      mob->map_skill(skill,level);
    }
  }
  foreach(string key,mixed value in base_mob->query_entire_dbase())
  {
    mob->set(key,value);
  }
  mob->delete("chat_msg_combat");
  mob->delete("family/privs");
  if(!sizeof(all_control_mob))
    all_control_mob = allocate(0);
  
  all_control_mob += ({ mob });
  me->set_temp("control_z",all_control_mob);
  
  mob->set_name(mob->query("name")+ "的屍體",({me->query("id") + "'s vampire","vampire"}));
  mob->setup();
  mob->move(environment(me));
  all_inventory(target)->move(mob);
  all_inventory(mob)->wield();
  all_inventory(mob)->wear();
  mob->set("long",mob->query("long") + "\n但現在卻變成由"+me->query("name")+"所操控的殭屍。\n");
  mob->delete("chat_msg");
  mob->delete("inquiry");
  mob->set("horse",1);
  mob->set("no_recruit",1);
  mob->set_leader(me);
  mob->set("master",me);
  mob->set("env/sid",1);
  destruct(target);
  // 看是不是要限制 npc 最多能控制多久，可以說屍體爛掉了，否則fireking來人間，真的超強。
  message_vision(HIY"\t$N從身上拿出空白的符，龍飛鳳舞的在符上畫上咒語。\n"+
                   "\t接著將符貼到$n頭上，並且大聲的喝道：\n"+
				   "\n\t\t\t"HIR"起！"HIY"\n\n\t接著屍體就悠然的站起。\n"NOR,me,mob);
  return mob;
}
