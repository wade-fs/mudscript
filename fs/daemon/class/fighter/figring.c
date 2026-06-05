#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
	set_name(HIY + "狂龍翔天破" + NOR,({"crazy dragon","crazy","dragon"}));  
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","這是一把傳說中由神打造的武器，其威力無從得知!!\n");
                set("value",10000);
                set("material", "steel");
                set("sharp",8);
        set("wield_msg", "$N戴上$n，狂龍的鬥氣從$N身上散發出來。\n");
        set("unwield_msg", "$N將手上的$n卸了下來後，龍的鬥氣隨之消逝。 \n");
        }
        init_unarmed(45);
set("weapon_prop/unarmed", 10);
set("weapon_prop/force",10);
set("need_exp",500000);    // by frequency
        setup();
}
int wield()  //fix by frequency
{
 if(!this_player()) return 1;
            if( this_player()->query_str() < 20 )
            return notify_fail("你的力量還未夠班，無法操控升龍之勢。\n");
            if( this_player()->query("combat_exp") < 500000 )
            return notify_fail("哈！鬼才相信你轟得下任正晴。\n");
  ::wield();
 return 1;
}
