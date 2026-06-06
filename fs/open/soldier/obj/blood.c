
#include <weapon.h>
#include <ansi.h>

inherit LANCE;
  void create()
  {
        seteuid(getuid());
        set_name( HIR + "『血燕』" + NOR ,({"blood swallow","blood","swallow"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
   set("long","
    這把利器是一雙的,自古到今它的身世仍然是一個謎,它混身
充滿了血腥味,現在武林沒人知道它是誰所製造的。。。
   ");
                set("value",100000);
                set("material", "crimsonsteel");
        set("wield_msg", "$N從背後抽出$n,忽然覺的" + HIR + "殺意四起,$N充滿了暴戾之氣。\n" + NOR);
        set("unwield_msg", "$N理性的把$n小心的收回到背後。\n");
      }
        init_lance(100);
        setup();
}

