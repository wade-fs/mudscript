#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(HIY "龍飛鞋" NOR,({"boots"}) );
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("long","
這是葉秀殺專用的神奇鞋子，相傳為諸岡渡所贈的八頭大蛇皮所製，內含草雉劍的靈氣
相傳更有不可思議之效。\n");
                set("unit","雙");
                set("value",20000);
                set("armor_prop/armor",5);
                set("armor_prop/dodge",10);
                set("armor_prop/throwing",10);
                set("material","leather");
                set("armor_type","boots");
            set("wear_msg", "$N穿上$n忽然感到身子輕盈了起來，好似要飛一般。\n");
            set("remove_msg", "$N將$n脫了下來，感到身體一沉，又恢復原狀了。\n");
                setup();
        }
}
