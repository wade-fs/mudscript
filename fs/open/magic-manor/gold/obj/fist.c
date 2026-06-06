#include <weapon.h>
#include <combat.h>
#include <ansi.h>
inherit BLADE;
object ob=this_object();
void create()
{
        set_name(HIY"魚龍寶刀"NOR,({"fish blade","blade"}));
        set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit","把");
          
set("long","『 "HIY"魚龍寶刀"NOR" 』,此刀相傳乃是東瀛黑流派的鎮派寶刀。\n");
          set("value", 10000);
          set("material","blacksteel");
        }
        set("wield_msg", "$N從背後的刀囊中拿出魚龍刀\n");
        set("unwield_msg", "$N把"HIY"魚龍刀"NOR"放回背後的刀囊\n");
        init_blade(90);
        setup();
}
void init()
{
  set_heart_beat(1);
}
void heart_beat()
{
        int i,exp;
        object me=(environment(this_object()));
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" )
        {
          enemy=me->query_enemy();
          i=random(sizeof(enemy));
          exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
          if(exp<=0)    exp=5000;
          else          exp=5000+exp/10;
          if( random(exp) > random(20000) && random(5)==0 && me->query_kar()>random(30) )
          {
           if( me->query("force") > 25)
           {          
             message_vision("$N大喝一聲，運起全身真氣灌入"HIY"魚龍刀"NOR"中，"HIY"魚龍刀"NOR"亮出閃閃的刀芒。\n"
                            "$N順式使出使出狂龍傲天武訣中的祕技"HIM"【"HIC"橫"HIB"∞"HIC"掃"HIB"∞"HIC"天"HIB"∞"HIC"下"HIM"】"NOR"!!\n",me,enemy[i]);
              message_vision("$n被$N的橫掃天下的刀氣砍個重傷\n",me,enemy[i]);
              COMBAT_D->report_status(enemy[i]);
              enemy[i]->receive_wound("kee",80);
              me->add("force",-25); 
           }
          }
        }
}       


