//設計者 by enisx, code by blazakira 2011/8/29

#include <ansi.h>
#include <armor.h>
//inherit EQUIP; //改用#include <armor.h>來設限
inherit WRISTS;

void create()
{
  set_name("〥淒幽赤玉環〥",({"sad jade wrists","wrists"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","瀧山派掌門任正晴於玄天聖谷修練靈氣，偶遇三大絕世高手之\n"+
      "陳蝶衣所贈。此環遍體通紅，溫潤如羊脂，外刻有龍紋，內鑲\n"+
      "以白鑽，為拳腳修練者配戴防身之用。\n" + NOR);
    set("unit","對");
    set("value",50000);
    set("material","gold");
    set("armor_type","wrists");
    set("armor_prop/armor",4);
    set("armor_prop/unarmed",3);
    set("armor_prop/force",3);
    set("armor_prop/dodge",2);
    set("need_class","fighter");
    set("wear_msg","$N""把$n配戴起來""，一陣憂傷心緒突然襲來，$N""本能地運起自家內功\壓制，內力提升\n"+
      "數倍之後，只感全身有說不出來的快感！\n" + NOR);
    set("unequip_msg","$N""脫下$n""，哀戚的感覺也跟著消失了!!\n" + NOR);
  }
  setup();
}

void init()
{
  add_action("do_help","help");
}

int do_help(string str)
{
  if (str!="sad jade wrists") return 0;

  write(@Help
    裝備構思協助者：藍焰紫羽(enisx)。
Help
  );
  return 1;
}
