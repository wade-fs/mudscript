#include <weapon.h>
#include <ansi.h>

inherit DAGGER;
void create()
{
        seteuid(getuid());
        set_name(HIR + "朱雀匕首" + NOR,({"juchi"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
       {
                set("unit", "把");
                set("long","匕首上刻有朱雀之圖騰，彷彿要飛出來似的感覺．\n");
                set("value",10000);
                set("material", "steel");
                set("no_sell",1);
                set("no_auc",1);
                set("no_hands",1);
                set("wield_msg",HIR + "$N將$n握在手上，全身已被炎氣籠罩。\n" + NOR);
                set("unwield_msg",HIR + "$N畫出一道銀花，將$n放回身邊小袋中。\n" + NOR);
       }
        init_dagger(54);
        setup();
}

mixed hit_ob(object me)
{
  object user=this_player();
    object *enemy=user->query_enemy();
  object victim=enemy[random(sizeof(enemy))];
  int be = (user->query("bellicosity"))/10;
  int inn = user->query_skill("shadow-kill",1);
  int sp = user->query_skill("magic",1);
  int bb = user->query_skill("dodge",1);

  if (this_player()->query("class") != "killer")
	return 0;

  if( user->is_fighting() && query("equipped") )
  {//下一行是檢查有多少機會驅動特攻，約50％
   //因為使以自己的亂數，如自己的殺氣是1000點
   //亂數介於 0-1000點之間，所以一定不大於 1000
   //所以把亂數出來的值*2，造成如果亂數出來的值大於500，就可以大於1000
    if( random(100) > 40 )
    {
     if( random(bb*2.5)  > victim->query_skill("dodge",1) )
     {//注意，為了要強調dodge的效用，（現在FS根本不重視）
      //所以，故意以dodge來決定命中度，如果你的dodge大於對方一倍，命中度幾乎100％
      //相對的，如果對方的dodge大於你兩倍的話，命中度幾乎就是0％
      message_vision(HBRED + "\n朱雀圖騰化成朱雀,衝向$N瞬間陷入一片火海!!!\n" + NOR,victim);
      victim->add("kee",-250);
      COMBAT_D->report_status(victim);
     }else
      message_vision(HIW + "火焰由朱雀匕首激發,但被$N巧妙的躲開\n" + NOR,victim);
     }
  }
}
