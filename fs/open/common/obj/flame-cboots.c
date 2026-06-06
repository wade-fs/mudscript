//設計者 by enisx, code by blazakira 2011/8/19

#include <ansi.h>
#include <armor.h>
//inherit EQUIP; //改用#include <armor.h>來設限
inherit BOOTS;

void create()
{
  set_name("ζ踏燄破雲履ζ",({"flame cloud boots","boots"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","這是一雙從天界傳下來的寶鞋，渾身金光熾盛，如烈焰燃燒，\n"
      "若不是擁有武者堅忍無畏的膽勢，你可能無法穿上它!!\n" + NOR);
    set("unit","雙");
    set("value",40000);
    set("material","fur");
    set("armor_type","boots");
    set("armor_prop/armor",3);
//    set("armor_prop/dodge",1); //太重就會覆蓋dodge的設定值
    set("armor_prop/unarmed",5);
    set("armor_prop/move",3);
    set("need_exp",5000000);
    set("need_class","fighter");
    set("wear_msg","$N""穿上$n""，一股暖風圍繞在身邊久久不散，$N""感到身體輕飄飄的，行動更加快速。\n" + NOR);
    set("unequip_msg","$N""脫下$n""，渾身氣力消散，履上之燄消失得無影無蹤。\n" + NOR);
  }
  setup();
}

void init()
{
  add_action("do_help","help");
}

int do_help(string str)
{
  if (str!="flame cloud boots") return 0;

  write(@Help
    裝備構思協助者：藍焰紫羽(enisx)。
Help
  );
  return 1;
}

int wear()
{
  object me=environment();
  int ret = ::wear();
  if(me->query_cor(1) < 20) return notify_fail("你的技能或屬性不足以使用這樣裝備。\n");
  return ret;
}
