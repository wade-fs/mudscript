#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name("羅剎女飾" , ({"gem"}) );
     set_weight(500);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", 
		"羅剎女隨身攜帶的寶物，由十二顆魔力寶石製成\n");
            set("unit", "條");
            set("armor_type", "neck");
            set("value", 50000);
            set("armor_prop/force",10);
            set("armor_prop/armor",6);
            set("wear_msg", HIY + "$N把$n戴在脖子上 ,臉上頓時罩了一層寒霜。\n");
     }
}

