#include <weapon.h>
#include <ansi.h>
inherit THROWING;
object me;
void create()
{
     set_name(HIG + "殺意魔錐" + NOR,({"bell_star","star"}));
     set_weight(10);
     if( clonep() )
         set_default_object(__FILE__);
     else {
       set("unit","支");
       set("base_unit","支");
       set("long","這是殺手才能拿的暗器，可以吸收被擊中者的殺氣");
       set("value",1000);
       set("no_sell",1);
       set("no_hands",1);
       set("weapon_prop/throwing",20);
       set("weapon_prop/dodge",10);
       set("weapon_prop/parry",10);
       set("material", "silver");
       set("wield_msg","$N拿起$n,感覺起來很不錯。\n");
       set("unwield_msg", "$N將$n放了下來\n");
     }
      init_throwing(100);
      set_amount(1);
      setup();
}

mixed hit_ob(object victim)
{//這裡的victim是指被害者
 int i,a,b,cor,vcor,mklv=0; 
 int keecost=0;
 object *enemy;
 object me;

 if( !living(victim)) return;
 enemy=victim->query_enemy();
if(sizeof(enemy) < 1 ) return ;
 me=enemy[random(sizeof(enemy))]; 
 cor=me->query_cor();
 cor=(random(cor)+1)*5;

 vcor=victim->query("bellicosity");
 if (vcor < cor)
	cor= vcor;
  if(random(cor) > 50)
  {  
   message_vision("" + HIM + "$N被$n的殺意魔錐刺出傷口,殺氣由傷口流失被$n所吸收" + NOR + "\n",victim,me);
   if (me->query("sec_kee") == "mkill")
	mklv= me->query("max_s_kee"); //至少要lv 150才可以配合發出紅級 
   keecost=20;
   if(me->query("s_kee")< 20)
	keecost= me->query("s_kee");

   if ( me->query("quest/worldpill") && (keecost > 10))
   {
    if ((mklv >150) && (random(100) > 50))
    {
     message_vision(HIC + "======  " + HIW + "$N 使 出 霸 雨 螫 魂 奧 義 " + HIR + "絕 魔 殺 錐 " + HIC + " ====== \n\n" + NOR,me);
     message_vision(HIR + "$N由爆出強烈的殺氣，這是一種帶有魔力的殺氣,融合著絕世幻氣爆出.\n" + NOR,me);
     message_vision(HIR + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,victim);
     message_vision(HIR + "$N所發出帶有魔氣的魔錐,刺傷$n造成身上留下無數的傷痕！\n" + NOR,me,victim);
     victim->start_busy(2);
     victim->receive_damage("gin",random(cor+180));
     victim->receive_damage("sen",random(cor+180));
     victim->set_temp("mkill",1);
     //附加兩回合
     victim->apply_condition("mkill_out",2);
     me->add("s_kee",-keecost);
     if (me->query("force") < 200)
	me->set("force",0);
     else
     	me->add("force",-100);
    }
   }
   COMBAT_D->report_status(victim,1);
   victim->receive_damage("kee",cor);
   victim->add("bellicosity",-cor);
   me->add("bellicosity",10);  // 因為提高了bellstar的取得 故減少殺氣吸取量
  } 
}

int wield()
{
 if(this_player()->query_skill_mapped("throwing") != "rain-throwing")
    return notify_fail("這是殺手專用的東西\n");
 if(this_player()->query_skill("throwing") < 80 )
     return notify_fail("小朋友，暗器手法練好一點，再用吧！\n");
 else 
 {
::wield();
  }
  return 1;
}

