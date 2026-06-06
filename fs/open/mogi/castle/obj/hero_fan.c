// made by roger

#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
     set_name( HIB + "半熟洋蔥" + NOR,({"onion"}) );
     set_weight(8000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
        set("long","上古魔界奇異武器,可以變換成刀劍鞭等來使用。魔界\n"
                  +"初開時半熟英雄單\槍\匹\馬\成\功\的\闖\入\了\魔\界，超級\n"
                  +"天神小嵐美眉特令魔界之王羅嚴塔爾為半熟英雄\n"
                  +"量身打造的神器。\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : unarmed sword blade whip dagger stabber )\n");
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        set("no_put",1);
        set("no_give",1);  
            set("unit", "件");
            set("value",10000000);
            set("material","steal");
           }
        init_stabber(65);
        setup();
}
void init()
{
    add_action("do_change","change");
}
int do_change(string str)
{
   switch(str)
   {
     case "unarmed":
           set("skill_type", "unarmed");
           set_name(HIB + "半熟洋蔥爪" + NOR,({"onion claws","claws"}));
           write("半熟洋蔥開始作奇異的變化.\n半熟洋蔥化成了一雙半熟洋蔥爪.\n");
           break;
     case "sword":
           set("skill_type", "sword");
           set_name( "半熟洋蔥劍",({"onion sword","sword"}));
           write("半熟洋蔥開始作奇異的變化.\n半熟洋蔥化成了半熟洋蔥劍.\n");
           break;
     case "blade":
           set("skill_type", "blade");
           set_name( "半熟洋蔥刀",({"onion blade","blade"}));
           write("半熟洋蔥開始作奇異的變化.\n半熟洋蔥化成了半熟洋蔥刀.\n");
           break;
     case "dagger":
           set("skill_type", "dagger");
           set_name( "半熟洋蔥",({"onion dagger","dagger"}));
           write("半熟洋蔥開始作奇異的變化.\n半熟洋蔥化成了半熟洋蔥匕首.\n");
           break;
     case "whip":
           set("skill_type", "whip");
           set_name( "半熟洋蔥鞭",({"onion whip","whip"}));
           write("半熟洋蔥開始作奇異的變化.\n半熟洋蔥化成了半熟洋蔥鞭.\n");
           break;
     case "stabber":
     case "fan":
           set("skill_type", "stabber");
           set_name( HIB + "半熟洋蔥" + NOR,({"onion device","device"}) );
           write("半熟洋蔥開始作奇異的變化.\n半熟洋蔥變回原來的形狀.\n");
           break;
     default:
           write("半熟洋蔥左變右變,就是無法變成你要的東西.\n");
   }
     return 1;
}
int query_autoload()
{
 return 1;
}
