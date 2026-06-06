//設計者 by enisx, code by blazakira 2011/8/29

#include <ansi.h>
#include <armor.h>
//inherit EQUIP; //改用#include <armor.h>來設限
inherit SHIELD;

void create()
{
  set_name("戚家藤牌",({"rattan shield","shield"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","明代抗倭名將戚繼光將南蠻藤甲兵慣用盾牌進行改良，為堅藤\n"+
      "所製呈反荷葉形，因其堅固又有伸縮性，所以抵禦刀劍棍斧及\n"+
      "矢鏃彈丸，頗為有效，時至今日，行走江湖常用拳腳的武者也\n"+
      "紛紛採用，對於近戰時可提供一定的保護與攻擊力。\n" + NOR);
    set("unit","面");
    set("value",35000);
    set("material","wood");
    set("armor_type","shield");
    set("armor_prop/armor",10);
    set("armor_prop/unarmed",4);
    set("armor_prop/parry",2);
    set("need_class","fighter");
    set("wear_msg","$N""舉起$n""，領悟了「盾牌如壁，閃牌如電，遮蔽活潑，起伏得宜」的近戰心得，感覺眾莫能當。\n" + NOR);
    set("unequip_msg","$N""放下了$n""，安全感頓時減少一大半。\n" + NOR);
  }
  setup();
}

void init()
{
  add_action("do_help","help");
}

int do_help(string str)
{
  if (str!="rattan shield") return 0;

  write(@Help
    裝備構思協助者：藍焰紫羽(enisx)。
Help
  );
  return 1;
}
