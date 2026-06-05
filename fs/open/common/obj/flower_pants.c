//設計者 by enisx, code by blazakira 2011/8/29

#include <ansi.h>
#include <armor.h>
//inherit EQUIP; //改用#include <armor.h>來設限
inherit PANTS;

void create()
{
  set_name("《煙色》花羅幅褌",({"flower pants","pants"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","江南織造局為習武之人所特製的腰下裝備，花紋空隙處用四個\n"+
      "鳥紋小團花相連，色彩協調，織工精細，花羅之上以朱紅、棕\n"+
      "紅、深綠、深藍與金黃等色絲線，繡出流雲、卷枝花草。著裝\n"+
      "後猶如宋代詩人陸游詞句所言「舉之若無，裁以為衣，真若煙\n"+
      "霧!!」\n"NOR);
    set("unit","件");
    set("value",30000);
    set("material","cloth");
    set("armor_type","pants");
    set("armor_prop/armor",9);
//    set("armor_prop/dodge",1); //太重就會覆蓋dodge的設定值
    set("armor_prop/unarmed",4);
    set("need_class","fighter");
    set("wear_msg","$N""穿上了$n""，一身桔黃色的光四散，如同沐浴著和煦的春陽。\n"NOR);
    set("unequip_msg","$N""解下$n""，身體慢慢地變的遲鈍了。\n"NOR);
  }
  setup();
}

void init()
{
  add_action("do_help","help");
}

int do_help(string str)
{
  if (str!="flower pants") return 0;

  write(@Help
    裝備構思協助者：藍焰紫羽(enisx)。
Help
  );
  return 1;
}
