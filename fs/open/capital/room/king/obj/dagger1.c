//moon dagger by bss (皇室女性用)
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC + "沉璧" + NOR,({"moon dagger","dagger"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是皇室的祖傳兵器，能夠完完全全的配合皇室絕學\n
                「飛亂」，是一件不可多得的好兵器。\n");
                set("value",1000);
                set("material", "steel");
        }
        init_dagger(110);
        set("wield_msg", HIY + "$N雙手忽然一抖，$n就像變魔術般的出現在$N手上。\n" + NOR);
        set("unwield_msg",HIY + "$N將手一抖，$n便消失了。\n" + NOR);
        setup();
}

