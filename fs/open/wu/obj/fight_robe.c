
// fighter_robe.c

#include <armor.h>
 
inherit CLOTH;
 
void create()
{
        set_name( "武鬥服", ({ "fighter robe","robe"}) );
        set("long",
                     "這是一件造型特殊的衣服，於肩部及胸部特別做加強\n"
                       "，以適戰鬥所需，護肩上還有一個""鬥""字，是一般武\n"
                       "鬥家十分喜愛的服裝\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit"              , "件");
                set("material"          , "cloth");
                set("armor_prop/armor"  ,  5);
                set("armor_prop/unarmed",  2);
        }

        setup();
}
