//bonze boots//
#include <ansi.h>
inherit EQUIP;
object me=this_player();
void create()
{
        set_name(YEL "草鞋" NOR,({"boots"}) );
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("long","
這是一雙一般的僧侶會穿的草鞋，穿習慣的僧侶還會覺得更為輕快。\n");
                set("unit","雙");
                set("value",20000);
                set("armor_prop/armor",20);
               set("armor_prop/dodge",8);
//                set("armor_prop/move",8);
				set("no_save",1);
                set("material","grass");
                set("armor_type","boots");
				set("gender_only","男性");
                         
        }
		   setup();
}

