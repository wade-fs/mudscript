
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
 set_name(HIW"羊毛衣"NOR,({"cloth"}));
 set_weight(50);
 if ( clonep() )
 set_default_object(__FILE__);
 else {
       set("long", "一件多麼輕巧又溫暖的羊毛衣呀！");
       set("unit", "件");
//     set("armor_type", "cloth");
       set("material", "fur");
       set("value", 5000);
       //set("armor_prop/", );
       set("no_auc",1);
       set("no_sell",1);
       set("no_give",1);
       set("no_put",1);
       set("no_drop",1);
       set("no_get",1);
       set("no_steal",1);
       set("no_save",1);
       set("wear_msg","$N緩緩地穿上羊毛衣，臉上露出幸福的微笑。\n");
       set("unequip_msg","$N將羊毛衣脫下後，不自覺地打了個冷顫。\n");
     }
       setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
        set_name (me->name(1)+ "的"HIW"羊毛衣"NOR, ({"cloth"}));
  else
        set_name (HIW"羊毛衣"NOR, ({"cloth"}));

}
