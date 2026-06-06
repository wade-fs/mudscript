#include <ansi.h>
inherit EQUIP;
void create()
{
set_name("幽冥魔氣戰袍",({"ghost cloth","cloth"}) );
set_weight(5000);
if( clonep() )
set_default_object(__FILE__);
else{
set("meterial","silk");
set("unit","件");
set("value", 20000);
set("armor_type","cloth");
set("armor_prop/armor", 20);
set("armor_prop/dodge", 10);
set("armor_prop/parry", 5);
set("armor_prop/throwing", 20);
set("long","此乃煉妖壺中的壺底密藏妖怪--壺中仙。所有的超級戰袍
相傳當年因折服於葉秀殺的蓋世武功，而贈衣給予葉秀殺\n");
}
setup();
}
