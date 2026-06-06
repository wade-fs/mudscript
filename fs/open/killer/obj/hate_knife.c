#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit THROWING;

void create()
{
        set_name(HIR "千古恨" NOR,({"hate knife","knife"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("base_unit","把");
                set("no_give",1);
                set("no_drop",1);
                set("no_put",1);
                set("no_hands",1);
                set("base_value",1000);
                set("value",10000);
                set("material", "steel");
                set("weapon_prop/throwing",15);
                set("weapon_prop/dodge",7);
                set("weapon_prop/parry",7);       
        }
        init_throwing(100);
        set_amount(1);
        setup();
}

int wield()
{
 if(!this_player()) return 1;
 if(this_player()->query_skill_mapped("throwing") != "rain-throwing")
    return notify_fail("這是殺手專用的東西\n");
 if(this_player()->query_skill("throwing") < 140 )
     return notify_fail("小朋友，暗器手法練好一點，再用吧！\n");
 else 
 {
::wield();
  }
  return 1;
}
