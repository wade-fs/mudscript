// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
        set_name(HIW"日輪碎星破"NOR,({"Sun shatter destoryer","destoryer"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
         set("long","傳說中一副以日輪石研磨而成的特殊手甲, 其威力足以碎星\n");

                set("value",10000);
                set("material", "steel");
                set("ski_level",40);
                set("ski_type","unarmed");
         set("wield_msg", "$N套上$n之後, 雙手發出耀眼金光. \n");
        set("unwield_msg", "$N將$n脫去後, 光芒隨之黯淡. \n");
        }
          init_unarmed(45);
        setup();
}
