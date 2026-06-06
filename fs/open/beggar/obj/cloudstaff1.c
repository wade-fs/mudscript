//調整使用者的判斷與補上receive_wound攻擊方的參數 by blazakira 2011/7/23

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit SSERVER;

void create()
{
  seteuid(getuid());
  set_name(HIC"流雲杖"NOR,({"cloud staff","staff"}) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","杖身籠罩著消消藍氣，散發出陣陣神秘的感覺。\n");
    set("unit", "把");
    set("value",100000);
    set("material","blacksteal");
    set("weapon_prop/staff",10);
    set("weapon_prop/move",-20);
    set("weapon_prop/dodge",-20);
    set("weapon_prop/parry",10);
    set("weapon_prop/force",9);
    set("no_give", 1);
    set("no_get", 1);
    set("no_sell", 1);         
    set("no_auc", 1);
    set("no_drop", 1);
    set("no_auc", 1);
    set("no_put", 1);
    set("no_save", 1);
    set("no_secure", 1);
    set("wield_msg",HIW"$N"HIW"將內力貫入杖身，"HIC"流雲杖"HIW"感應到$N"HIW"的感召，發出一陣清嘯，劃破天際。\n"NOR);
    set("unwield_msg",HIR"$N"HIR"將內力收回，"HIC"流雲杖"HIR"立刻沉靜了下來，萬丈的光芒立刻消失無蹤。\n"NOR);
  }
  init_staff(200);
  setup();
}

int query_autoload()
{ 
  if(environment(this_object())->query("family/family_name")=="丐幫")
    return 1;
  return 0;
}

int wield()
{
  object user=environment(this_object());
  if(user->query_skill("staff",1) < 120) return notify_fail("你的棍法還不夠純熟，無法使用這兵器。\n");
  ::wield();
  if( query("equipped") )
  {
//    message_vision(HIW"$N將內力貫入杖身，"HIC"流雲杖"HIW"感應到$N"HIW"的感召，發出一陣清嘯，劃破天際。\n"NOR,user);
    user->set_temp("wielded",1);
    set_heart_beat(1);
  }
  return 1;
}

int unequip()
{
  object user=environment(this_object());
  if( query("equipped") && user->query_temp("wielded"))
  {
    ::unequip();
//    message_vision(HIR"$N將內力收回，"HIC"流雲杖"HIR"立刻沉靜了下來，萬丈的光芒立刻消失無蹤。\n"NOR,user);
    user->delete_temp("wielded");
    set_heart_beat(0);
    return 1;
  }
}

void heart_beat()
{
  object *enemy,user=environment(this_object());
  int i,kee,staff;
  if (!query("equipped") || !user)
  {
    set_heart_beat(0);
    return;
  }
  staff = user->query_skill("staff");
  if (userp(user))
    kee=user->query("max_kee",1)/40;
  else
    kee=user->query("max_kee",1)/10;

  if(!user->query("beggar/got_phoenix")) return;
  if( user->is_fighting() && user->query_temp("wielded")==1 )
  {
    if((int)user->query("kee") < (int)(user->query("max_kee")/3) && random(staff) > 105)
    {
      message_vision(BLINK+HIC"流雲杖感覺到$N的危勢，急忙釋放出大量能量為主人解危。\n"NOR,user);
      user->receive_curing("kee",kee);
      user->receive_heal("kee",kee);
      COMBAT_D->report_status(user);
    }
    else if( random(staff) > 100)
    {
      enemy=user->query_enemy();
      i=random(sizeof(enemy));
      if( environment(user) == environment(enemy[i]) &&
          random(300) > enemy[i]->query_skill("dodge") )
      {
        message_vision(HIC"流雲杖"HIM"突然幻化成數千身影，將$N"HIM"團團圍住。\n"NOR,enemy[i]);
        enemy[i]->receive_wound("kee",staff+random(100),user);
        COMBAT_D->report_status(enemy[i]);
      } else {
        message_vision(HIC"$N"HIC"奮力一蹤，雖然逃過此擊受到些擦傷，但仍心有餘悸。\n"NOR,enemy[i]);
        enemy[i]->receive_wound("gin",random(staff),user);
        COMBAT_D->report_status(enemy[i]); //既然有隱藏傷害就要回報玩家狀態 不要出現死的不明白情況 by blazakira
      }
    }
  }
  return ;
}

void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
    set_name (me->name(1)+"的"HIC"流雲杖"NOR, ({ "cloud staff","staff" }));
  else
    set_name (HIR"一把普通的木杖"NOR, ({ "staff" }));
}
