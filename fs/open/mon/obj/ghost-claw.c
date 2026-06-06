//改變使用者的判定為me = environment(this_object()) 與 wear形式為int wear() (參考殺意魔戒) by blazakira 2011/8/22

#include <weapon.h>
#include <ansi.h>
inherit UNARMED;

void create()
{
  set_name(HIY + "幻紋妖爪" + NOR, ({ "ghost claw" ,"claw" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "千年樹妖–舞風揚妖力所幻化，帶有些微的妖力和強大的殺傷力。\n");
    set("unit", "把");
    set("value", 300000);
    set("material", "blacksteel");
    set("sharp",9);
    set("type", 1);
    set("no_steal",1);
    set("no_give",1);
  }
  init_unarmed(150);
  set("wield_msg",HIY + "$N" + HIY + "運起內力，緩緩將內力灌入$n" + HIY + "，$n" + HIY + "感受到$N" + HIY + "的能力而放出熾熱光茫!!\n" + NOR);
  set("unwield_msg",HIY + "$N" + HIY + "緩緩收回內力，$n" + HIY + "也漸漸變回一般不起眼的武器。\n" + NOR);
  setup();
}
int wear()
{
  int result = ::wear();
  if( query("equipped"))
  {
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  int result = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return result;
}

/*
void init()
{
  add_action("do_drop","drop");
  add_action("do_auc","auc");
  add_action("do_wield","wield");
  add_action("do_unwield","unwield");
}

int do_wield(string str)
{
//  ::wield();
  if(str=="ghost claw" || str=="claw" || str=="all")
  if( !query("equipped") )
  {
    user = this_player();
//    message_vision(HIY + "$N" + HIY + "運起內力，緩緩將內力灌入$n" + HIY + "，$n" + HIY + "感受到$N" + HIY + "的能力而放出熾熱光茫!!\n" + NOR,user,ob);
    set_heart_beat(1);
  }
}

int do_drop(string str)
{
  if(str=="ghost claw" || str=="claw" || str=="all")
  if( query("equipped") )
  {
    message_vision(HIY + "$N" + HIY + "緩緩收回內力，$n" + HIY + "也漸漸變回一般不起眼的武器。\n" + NOR,user,ob);
    set_heart_beat(0);
  }
}

int do_unwield(string str)
{
  if(str=="ghost claw" || str=="claw" || str=="all")
  if( query("equipped") )
  {
//    message_vision(HIY + "$N" + HIY + "緩緩收回內力，$n" + HIY + "也漸漸變回一般不起眼的武器。\n" + NOR,user,ob);
    set_heart_beat(0);
  }
}

int do_auc(string str)
{
  if(str=="ghost claw" || str=="claw" || str=="all")
  if( query("equipped") )
  {
    message_vision(HIY + "$N" + HIY + "緩緩收回內力，$n" + HIY + "也漸漸變回一般不起眼的武器。\n" + NOR,user,ob);
    set_heart_beat(0);
  }
}
*/
void heart_beat()
{
  object *enemy;
  object user=environment(),ob=this_object();
  int be,bb,k,sp,qq,co,st,i;
  if ( !ob || !user || !objectp(user) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }

  if( !user->query_skill("unarmed") )
  {
    be = random(120);
  } else {
    be = user->query_skill("unarmed",1);
  }

  k = user->query_int(1);
  sp = user->query_spi(1);
  co = user->query_cor(1);
  st = user->query_str(1);
  qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);

  if( user->is_fighting() && query("equipped") )
  {
    if( be > random(500) )
    {
      enemy=user->query_enemy();
      if(!sizeof(enemy)) return ;
      i=random(sizeof(enemy));
      if(!enemy[i]) i=0;
      if(!enemy[i]) return ;
      if( environment(user) == environment(enemy[i]) )
        if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
        {
          message_vision(HIY + "一道妖氣由$n" + HIY + "急速竄出，化為數道的電氣直攻$N" + HIY + "的周身要害!!\n" + NOR,enemy[i],ob);
          enemy[i]->receive_wound("kee",(int)(qq+be),user);
          COMBAT_D->report_status(enemy[i], 1);
        } else
          message_vision(HIW + "一道妖氣由$n" + HIW + "急速竄出，但被$N" + HIW + "機警的閃過!!\n" + NOR,enemy[i],ob);
    }
  }
  return;
}
