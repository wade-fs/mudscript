#include <weapon.h>
#include <ansi.h>
inherit THROWING;
object me;

void create()
{
     set_name("流星錐",({"lu star","star"}));
     set_weight(10);
     if( clonep() )
         set_default_object(__FILE__);
     else {
       set("unit","支");
       set("base_unit","支");
       set("long","這是殺手才能拿的暗器");
       set("value",1000);
       set("no_hands",1);
       set("material", "silver");
       set("wield_msg","$N拿起$n,感覺起來很不錯。\n");
       set("unwield_msg", "$N將$n放了下來\n");
     }
      init_throwing(60);
      set_amount(1);
      setup();
}
int wield()
{
  if(!this_player()) return 0;
 if(this_player()->query_skill_mapped("throwing")!="rain-throwing")
    return notify_fail("這是殺手專用的東西\n");
      else{
      ::wield();
            }
        return 1;
}
