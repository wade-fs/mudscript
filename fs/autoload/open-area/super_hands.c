//更改使用者的判定為me = this_player()>>me = environment(this_object()) 與增加心跳判斷 by blazakira 2011/4/14
//改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/4/14

#include <ansi.h>
#include <combat.h>
#include <armor.h>
inherit SSERVER;
inherit HANDS;
object me;

void create()
{
  set_name("皆傳之證",({"Xstrike-Hands","hands","xstrike"}) );
  set_weight(1000);
  if( clonep() ) 
    set_default_object(__FILE__);
  else {
    set("long","神話時代後即消失的上古神器。\n");
    set("unit", "副");     
    set("value",0);
    set("no_sell",1);
    set("no_steal",1);
    set("no_save", 1);
    set("no_give", 1);
    set("no_put", 1);
    set("no_auc", 1);
    set("no_drop", 1);
    set("no_get", 1);
    set("material","crimsonsteel");
    set("armor_prop/dodge",5);
    set("armor_prop/parry",10);
    set("armor_prop/attack",10);
    set("wear_msg",HIW + "$N" + HIW + "配戴上$n" + HIW + "，雙手異常靈巧起來。\n" + NOR);
  }
  setup();
}

/*
void init()
{
//  add_action("do_wear","wear");
}

int do_wear(string str)
{ 
  if( str == "hands" || str == "xstrike-hands")
  {
    if( query("equipped"))
    {
      me = environment(this_object());
      message_vision(HIW + "$N配戴上" + RED + "皆傳之證" + HIW + "，雙手異常靈巧起來。\n" + NOR,me);
      set_name( RED + "皆傳之證" + NOR,({"Xstrike-Hands","hands","xstrike-hands"}) );
      if(!query_heart_beat()) { //避免重複穿戴導致心跳有問題而增加 by blazakira
        set_heart_beat(1);
      }
      return 1;
    }else{
      return notify_fail("請先戴上皆傳之證吧!!\n");
    }
  }
}
*/
int wear()
{
  int result = ::wear();
  if( query("equipped"))
  {
    me = environment(this_object());
//    message_vision(HIW + "$N配戴上" + RED + "皆傳之證" + HIW + "，雙手異常靈巧起來。\n" + NOR,me);
    set_name( RED + "皆傳之證" + NOR,({"Xstrike-Hands","hands","xstrike-hands"}) );
    if(!query_heart_beat()) { //避免重複穿戴導致心跳有問題而增加 by blazakira
      set_heart_beat(1);
    }
  }
  return result;
}

void heart_beat()
{
  object *enemy,obj,wp;
  int i,j,k,h;
  obj = this_object();
  if(!obj || !me || !objectp(me))
  {
    set_heart_beat(0);
    return;
  }
  if(!query("equipped"))
  {
    set_name("皆傳之證",({"Xstrike-Hands","hands"}) );
    set_heart_beat(0);
    return;
  }

  wp = me->query_temp("weapon");
  if(!me->is_fighting())
  {
    me->delete_temp("devast");
    me->delete_temp("devast2");
    me->delete_temp("berserk");
    me->delete_temp("conti");
    return;
  }

  if(me->is_busy()) //  為了防止在busy空檔出招而設，請勿更動
  {
    me->set_temp("hands_idle",1);
    return;
  }
  if((wp && wp->query("no_hands")==1) || me->query_temp("devast")==1 || me->query_temp("devast2")==1) return;
  k = 1;
  if(me->query("max_force") > 8400)
    k = k + 1;
  if(me->query("bellicosity") > 7000)
    k = k + 1;
  if(me->query_skill("dodge",1) > 120)
    k = k + 1;
  if(me->query("combat_exp") > 15000000)
    k = k + 1;
  h = random(k);
/*//看起來可以與前面的判斷合併 by blazakira
  if( !objectp(me) )
  {
    set_heart_beat(0);
    return;
  }
*/
  if(me->query_temp("no_hands") || me->query_temp("devast") || me->query_temp("devast2")) return;
  if( me->is_fighting() && query("equipped") && !me->query_temp("hands_idle") && me->query("force") > 800 && me->query("bellicosity") > 500 && !me->query_temp("unconcious"))
  {
    enemy=me->query_enemy();
    if(sizeof(enemy) == 0 ) return;
    i=random(sizeof(enemy));
    me->add("force",-200);
    message_vision(HIB + "\n攻擊過後，$N迅速回氣，狂風暴雨般展開連環攻勢。\n" + NOR,me);
    me->set_temp("devast",1);
    me->set_temp("devast2",1);
    me->set_temp("berserk",1);
    me->set_temp("conti",1);
    for(j=0;j<=h;j++)
    {
      if(undefinedp(enemy[i]) || !enemy[i] || environment(me) != environment(enemy[i])) continue;
      if(me->query_busy()) break;
      COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 1);
    }
    me->delete_temp("devast");
    me->delete_temp("devast2");
    me->delete_temp("berserk");
    me->delete_temp("conti");
  }
  if(!me->is_busy())
  {
    me->delete_temp("hands_idle");
  }
  return;
}

int query_autoload()
{
  return 1;
}
