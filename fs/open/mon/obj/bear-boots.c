#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
  set_name(HIW + "白熊皮靴" + NOR,({"bear boots","boots"}));
  set_weight(9500);
  if( clonep() )
  set_default_object(__FILE__);
  else {
  set("long","長白山白熊皮所製成的皮靴, 能提昇佩帶者的防禦, 而且某些職業穿起來更是顯得雄壯威武。\n");
  set("unit", "雙");
  set("material","steal");
  set("no_auc",1);
  set("no_sell",1);
  set("no_put",1);
  set("no_drop",1);
  set("no_give",1);
  set("no_steal",1);
  set("armor_prop/armor", 50);
  }
  setup();
}

