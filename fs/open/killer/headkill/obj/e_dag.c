#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
int be,bb,inn,sp,qq;
void create()
{
        seteuid(getuid());
        set_name(HIY + "玄武匕首" + NOR,({"sawu"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
 	{
 		set("unit", "把");
	        set("long","匕首上刻有玄武之圖騰，令人有種沈穩的感覺．\n");
                set("value",10000);
	        set("material", "steel");
                set("no_sell",1);
                set("no_hands",1);
		set("no_auc",1);
	       set("wield_msg",HIY + "$N將$n握在手上，感到一種沈穩的感覺。\n" + NOR);
	       set("unwield_msg",HIY + "$N畫出一道銀花，將$n放回身邊小袋中。\n" + NOR);
	}
        init_dagger(60);
        setup();
}

mixed hit_ob(object me)
{
  object user=this_player();
  object *enemy=user->query_enemy();
  object victim=enemy[random(sizeof(enemy))];
  be = user->query("bellicosity");
  inn = user->query_skill("shadow-kill",1);
  sp = user->query_skill("magic",1);
  bb = user->query_skill("dodge",1);

 if (this_player()->query("class") != "killer")
	return 0;
 if( user->is_fighting() && query("equipped") )
  {//下一行是檢查有多少機會驅動特攻，約50％
   //因為使以自己的亂數，如自己的殺氣是1000點
   //亂數介於 0-1000點之間，所以一定不大於 1000
   //所以把亂數出來的值*2，造成如果亂數出來的值大於500，就可以大於1000
    if( random(100) > 40)
    {
     if( random(bb*2.5)  > victim->query_skill("dodge",1) )
     {//注意，為了要強調dodge的效用，（現在FS根本不重視）
      //所以，故意以dodge來決定命中度，如果你的dodge大於對方一倍，命中度幾乎100％
      //相對的，如果對方的dodge大於你兩倍的話，命中度幾乎就是0％
      message_vision(HIY + "\n匕首揚起一陣重壓的感覺，令$N感到陣陣的壓力\n" + NOR,victim);
      victim->add("sen",-200);
      victim->add("gin",-200);
      COMBAT_D->report_status(victim);
     }
     else
     	 message_vision(HIW + "玄武匕首揚起的壓力被$N巧妙的躲開\n" + NOR,victim);
     }
  }
  return;
}
