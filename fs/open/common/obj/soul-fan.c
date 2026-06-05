//設計者 by enisx, code by blazakira 2011/8/19

#include <weapon.h>
#include <ansi.h>
inherit STABBER;

void create()
{
  set_name("三魂綾扇",({"soul fan","soul","fan"}));
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","此扇相傳是玄天上帝擷取天魂、地魂、人魂之元靈鍛造而成，扇面潔白薄而透光，上下嵌金\n"
      "星玻璃銅鍍金護，頂上鑲有蝙蝠紋。對於已臻化境的武者來可說是一把奇門兵器！\n"NOR);
    set("unit","把");
    set("value",20000);
    set("material","steel");
//    set("cor","20");
//    set("armor_prop/dodge",1); //太重就會覆蓋dodge的設定值
    set("armor_prop/unarmed",5);
    set("armor_prop/parry",2);
    set("need_class","fighter");
    set("wield_msg","$N把$n緊握於手，三道異能直衝體內各大穴位，\n"
      "只覺一股幽香沁人心脾，不禁翩翩起舞，驅使$N自身的武功\套路發揮的更加順手！\n"NOR);
    set("unequip_msg","$N""脫下$n""，只見淡淡靈光自$N""身上淡出。\n"NOR);
  }
  init_stabber(60);
  setup();
}

void init()
{
  add_action("do_help","help");
}

int do_help(string str)
{
  if (str!="soul knuckles") return 0;

  write(@Help
    裝備構思協助者：藍焰紫羽(enisx)。
Help
  );
  return 1;
}
