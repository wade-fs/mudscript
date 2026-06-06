#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        seteuid(getuid());
        set_name("紅炘劍",({"red-sword","sword"}));
        set_weight(35000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	開陽門主秦憶詩的佩劍，一把以紅鐵打製的短劍，劍的兩側加上
	細細的鋸齒，藉以提高殺傷力．同時這把劍也是玉女派掌門人的
	佩劍, 與天女散花劍法配合使用後, 威力倍增!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);

        set("material", "iron");
        set("wield_msg", "$N從劍鞘一拔出$n，紅光四射。\n");
        set("unwield_msg", "$N用衣服將$n包了起來，其紅色的豪光被布包給遮蔽了。\n");
        }
        init_sword(100);
        setup();
}                            
