// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.
//排版 by blazakira 2011/10/20

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

object user;
int cor;

void create()
{
  set_name( HIB"狂想新人指戒"NOR ,({"newbie ring", "ring"}));
  set_weight(2500);
  if( clonep() ) 
    set_default_object(__FILE__);
  else {
    set("long","狂想空間新人專用戒指，有神奇的功\效\!!\n");
    set("unit", "件");
    set("value",5000);
    set("material","steal");
    set("no_sell", 1); //不然就得多攔 action sell
    set("no_give",1);
    set("no_get",1);
    set("no_drop",1);
    set("no_auc",1);
    set("light_up",-1);
    set("armor_type","finger");            
    set("armor_prop/armor",7);

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
    message_vision("$N戴上了"+this_object()->name()+"，全身有著"+this_object()->name()+"的保護罩保護著。\n",user);
    set_heart_beat(1);
  }
}

int unequip()
{
  if( query("equipped") )
  {
    message_vision("$N脫下了"+this_object()->name()+",防護罩似乎消失了.\n",user);
    set_heart_beat(0);
  }
  ::unequip();
}

void heart_beat()
{
  if( !objectp(user)  || !environment(this_object())) 
  {
    set_heart_beat(0);
    return;
  }
  if( user->is_fighting() && query("equipped") )
  {
    if( random(100) > 30)
    {
      cor = user->query_cor();
      cor = cor *5;

      user->receive_curing("kee",cor);
      user->receive_heal("kee",cor);
      message_vision(HIM+this_object()->name()+HIM"發出一片治癒之光籠罩著$N"HIM"，$N"HIM"的傷口好了\許\多。\n"+NOR,user);   
    }
  }
  return;
}
