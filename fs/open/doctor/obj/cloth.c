// made by ccat
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"冰霜寒絲袍"NOR, ({ "cold cloth","cloth"}) );
        set("long",
                   "此為傳說中歷經冰霜而成的的神袍，\n"
                   "如此罕見的奇物輕如天羽、堅如星煌，同時不斷地散\n"
                   "發蒼色之光輝，照耀人間。\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","件");
                set("material","crimsonsteel");
                set("value",100000);
                  set("armor_prop/armor",30);
                set("armor_prop/dodge",7);
                set("armor_prop/unarmed",5);
                set("armor/type","cloth");
              }

        setup();
}
// 以下是穿著時會發光，脫卸時便黯淡的程式
/*
void init()
{
        add_action("do_wear","wear");
        add_action("do_remove","remove");
}
int do_wear(string str)
{
        this_player()->set_temp("light_up",1);
        wear();
        set("wear_msg","$N穿起$n時，散發出陣陣的寒光！\n");
        return 1;
}
int do_remove(string str)
{
        this_player()->delete_temp("light_up");
        unequip();
        set("unequip_msg","$N脫下$n之後，$n的寒光逐漸消失。\n");
        return 1;
} 


*/
