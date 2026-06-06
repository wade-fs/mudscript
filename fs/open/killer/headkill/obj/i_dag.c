#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        seteuid(getuid());
        set_name(HIC + "白虎匕首" + NOR,({"bihu"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "把");
               set("long","匕首上刻有白虎之圖騰，彷彿要吃了人似的感覺．\n");
                set("value",10000);
                set("material", "steel");
                set("no_sell",1);
                set("no_auc",1);
                set("no_hands",1);
                set("wield_msg",HIC + "$N將$n握在手上，感到全身似乎充滿勁道。\n" + NOR);
                set("unwield_msg",HIC + "$N畫出一道銀花，將$n放回身邊小袋中。\n" + NOR);
        }
        init_dagger(63);
        setup();
}

mixed hit_ob(object me)
{
  object user=this_player();
  object *enemy=user->query_enemy();
  int i=random(sizeof(enemy));
  int be = user->query("bellicosity")/10;
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
    if( random(100) > 50 )
    {
       if( random(bb*2)  > enemy[i]->query_skill("dodge",1) )
     {//注意，為了要強調dodge的效用，（現在FS根本不重視）
      //所以，故意以dodge來決定命中度，如果你的dodge大於對方一倍，命中度幾乎100％
      //相對的，如果對方的dodge大於你兩倍的話，命中度幾乎就是0％
      message_vision(HIC + "白虎圖騰化成白虎幻影,包圍$N令其動作遲緩!!" + NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }
      else
      	message_vision(HIW + "由白虎匕首喚出的幻影，被$N識破根本無效\n" + NOR,enemy[i]);
    }
  }
  return;
}
