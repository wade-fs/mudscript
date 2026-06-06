// cloth.c
// by airke
#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name( MAG + "紫綬仙衣" + NOR ,({"silk cloth","cloth"}));
	set("long","以紫色絲綢製成，上面還繡了幅老君太極圖\n");
	set_weight(1500);
        set("armor_type","cloth");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("value",60000);
                set("material","cloth");
		set("armor_prop/armor",30);
set("no_get",1);
set("no_give",1);
                set("armor_prop/spell", 10);
		set("wear_msg","$N裝備上$n，四周極光籠罩，$N只覺得體力充沛，說不出的受用。\n" + NOR);
                set("remove_msg",HIW + "$N脫下$n" + HIW + "，身旁的光芒慢慢地黯淡下來。\n" + NOR);
	}
        setup();
}



int wear(){

  int val=this_player()->query_kar()*10;
  object me = this_player();
  // 這if 很重要.....否則wear all 會出現沒穿這cloth卻加max_kee的情形
  if( !me->query_temp("armor/cloth") ) {
  	me->add("max_kee",val);
  	me->set_temp("silk_cloth",val);
//	me->add_temp("apply/name",({me->name()+HIW + "(仙綬之衣)" + NOR}));
  }
  return ::wear();
}



int unequip(){

  object me=this_player();
int valu = me->query_temp("silk_cloth");

me->add("max_kee",-valu);
me->add("eff_kee",-valu);
  me->delete_temp("silk_cloth");
// me->delete_temp("apply/name");
  return ::unequip();
}





