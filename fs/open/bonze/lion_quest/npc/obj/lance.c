//lance by bss
#include <weapon.h>
#include <ansi.h>
inherit LANCE;

void create()
{
        set_name(HIR "丈二紅槍" NOR,({"red lance","lance"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是邪靈厲若海賴以成名的絕代兵器\n
以之配合使出「燎原百擊」的話將更具威力。\n");
                set("value",1000);
                set("material", "steel");
        }
        init_lance(50);
        set("wield_msg", "$N將原本收在背後，分成兩截的$n取出，將兩截$n接在一起，拿在手上。\n"NOR);
        set("unwield_msg","$N將$n拆成兩截，收回背後的袋子裡。\n"NOR);
        set("weapon_pron/lance",100);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_auc",1);
        set("no_give",1);
        set("no_steal",1);
        set("no_save",1);
        setup();
}

