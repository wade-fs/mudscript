#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
      set_name("拐杖",({"crutch"}) );
      set_weight(1000);
      if( clonep() )
            set_default_object(__FILE__);
      else {
            set("value",30);
            set("unit","支");
            set("material","wood");
            set("long","一支不甚起眼的拐杖。\n");     
            set("wield_msg","$N握起了原先放在腰際邊的$n。\n");
            set("unwield_msg","$N將手中的$n插回腰際間。\n");                        
      }
      init_staff(5);
      setup();
}     
