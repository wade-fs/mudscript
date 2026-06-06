// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.
//調整使用者的判斷參數且改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/29

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
  set_name( "紅寶石指戒" ,({"ruby_ring", "ring"}));
  set_weight(2500);
  if( clonep() ) 
    set_default_object(__FILE__);
  else {
    set("long","一只產於南蠻的神奇紅寶石指戒，閃爍著奇異的紅色光芒，\n其成分似乎非常神秘，指戒本身一直隱隱發亮....\n");
    set("unit", "件");             
    set("value",5000);
    set("material","steal");
    set("no_sell", 1);         //不然就得多攔 action sell
    set("armor_type","finger");            
    set("armor_prop/armor",7);
    set("wear_msg","$N戴上了$n，四周亮起了淡淡紅光。\n");
    set("unequip_msg","$N脫下了$n，紅寶石奇異的紅光也隨之消逝。\n");
  }
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
  add_action("do_wear","wear");
  add_action("do_give","give");
  add_action("do_remove","remove");
}

int do_wear(string str)
{ 
  ::wear(); 
  if( query("equipped") ) 
  {
    user = this_player();     // 取得使用者
    cor = user->query_cor();
    cor = cor *2;
    message_vision("$N戴上了紅寶石指戒,四周亮起了淡淡紅光.\n",user);
    set_heart_beat(1);
  } 
}

int do_drop(string str)
{  
  if(str=="ruby_ring" || str=="all")
    if( query("equipped") )
    {
      message_vision("$N脫下了紅寶石指戒,紅寶石奇異的紅光也隨之消逝.\n",user);
      set_heart_beat(0);
    }
}

int do_give(string str)
{  
  if(str=="ruby_ring" || str=="all") 
     if( query("equipped") )
     { 
        message_vision("$N脫下了紅寶石指戒,紅寶石奇異的紅光也隨之消逝.\n",user); 
        set_heart_beat(0);
     }
}
int do_remove(string str)
{
   if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        if(user)
        message_vision("$N脫下了紅寶石指戒,紅寶石奇異的紅光也隨之消逝.\n",user);
        set_heart_beat(0);
     }   
}
int do_auc(string str)
{
  if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     { 
        message_vision("$N脫下了紅寶石指戒,紅寶石奇異的紅光也隨之消逝.\n",user);
        set_heart_beat(0);
     } 
}
*/
void heart_beat()
{
  object me=environment();
  int cor;

  if( !me || !objectp(me) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  cor=me->query_cor()*2;
  if( me->is_fighting() )
  {
    if( random(100) > 80)
    {
      me->receive_curing("kee",cor);
      me->receive_heal("kee",cor);
      message_vision(HIM+"紅寶石指戒發出一道紅光籠罩著$N，$N的傷口癒合了。\n"+NOR,me);   
    }
  }
  return;
}
