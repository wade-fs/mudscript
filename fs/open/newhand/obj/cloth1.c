// Qc by Anmy 98/7/6
//排版與調整使用者的判斷 by blazakira 2011/10/20

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

object user;

void create()
{
  set_name( HIW + "狂想新人寶衣" + NOR ,({"newbie cloth","cloth"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value",1000);
    set("material","gem");
    set("armor_prop/armor",15);
    set("armor_prop/dodge",3);
    set("no_sell", 1); //不然就得多攔 action sell
    set("no_give",1);
    set("no_get",1);
    set("no_drop",1);
    set("no_auc",1);
    set("armor_prop/move",3);
  }
  setup();
}

int query_autoload() { return 0; }

int wear()
{
  ::wear();
  if( query("equipped") )
  {
    user = environment(this_object());//this_player(); // 取得使用者
    message_vision(HIW + "$N" + HIW + "暗運內勁，在$N四周升起淡淡的白色光罩。\n" + NOR,user);
    set_heart_beat(1);
  }
}

int unequip()
{
  ::unequip();
  if( query("equipped") )
  {
    set_heart_beat(0);
  }
}

void heart_beat()
{
  if( !environment(this_object()) ||!user || !objectp(user) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  if( user->is_fighting())
  {
    if( random(100) > 50)
    {
      user->receive_curing("kee",30);
      user->receive_heal("kee",30);
      message_vision(query("name")+HIW + "發散出一道白光護住$N" + HIW + "的全身，$N" + HIW + "的傷勢緩慢復原中。\n" + NOR,user);
    }
  }
}
