#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIR"鳳"HIM"凰"HIB"頭"HIW"冠"NOR, ({"phoenix cap", "cap"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("long",HIW"傳說中，由不死鳥－鳳凰的頭骨所作成的，不但能助長氣力，更能增強防禦。\n"NOR);
		set("wear_msg", HIW"$N將$n"HIW"帶上，突然彷彿不死的鳳凰，內力與防禦似乎都增進了許\多。\n"NOR);
		set("unequip_msg", HIY"$N將$n"HIY"拿下，$N身後一股鳳凰之氣隨之淡化..\n"NOR);
		set("armor_prop/armor",5);
		set("armor_prop/force",5);
		set("unit", "頂");
		set("value", 100000);
		set("material", "steel");
        }
        setup();
}
