#include <weapon.h>
#include <ansi.h>
// QC By Swy 98/6/3
inherit UNARMED;

void create()
{
  seteuid(getuid());
  set_name(MAG + "魔星爪" + NOR,({"evil claws","evil","claws"}));
  set_weight(4500);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("unit", "副");
  set("long","這是一把傳說中接受魔星--天狼--之詛咒的爪子 ,.據說其威力足以開天闢地 !\n");
  set("value",12000);
  set("material","ironsteel");
  set("ski_type","unarmed");
  set("wield_msg",HIM + "$N將魔星爪套在手中 ,你感到有股邪氣正從爪中傳到$N身上 !\n" + NOR);
  set("unwield_msg",HIC + "$N將魔星爪拆了下來 ,身上的邪氣也已不復見 .\n" + NOR);
  }
  init_unarmed(50);
  setup();
}
