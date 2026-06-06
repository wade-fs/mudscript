inherit ITEM;
#include <ansi.h>
        
void create()
{
    set_name("骨骸",({"skeleton"}));
    set("long","
一具披著道袍的骨骸，看來死去的年代已經相當久遠了，你心思道：
說不定這就是小蝶她師父－靈韻師太的骨骸...你發覺道袍上似乎有
些奇特...
        \n");
    set("unit","具");
    set("value",100);
    set("no_get",1);
    set("no_sac",1);
    set("no_auc",1);
    set_weight(500000);
    setup();
}

void init()
{
        add_action("sea_ske","search");
}

int sea_ske(string arg)
{
        object me = this_player();
        object ob = this_object();
        object book = new("/autoload/tendo/book");
        object letter = new("/open/mon/obj/letter");
        
        if(me->query_temp("icestorm/ice_spell")==6)
        {
        if(!arg) return 0;
        if(arg!="道袍")
        {
                write("你仔細的反覆查看了"+arg+"好幾次，但就是沒有任何的發現...\n");
                return 1;
        }
                write("你仔細的反覆查看了"+arg+"...\n忽然從"+arg+"內掉出了一本古書及一封信箋...\n\n
你順手便檢了起來...\n");
                book->move(me);
                letter->move(me);
                me->set_temp("icestorm/ice_spell",7);
                return 1;
        }
}

