#include <weapon.h>
#include <command.h>
#include <combat.h>
#include <skill.h>
#include <ansi.h>
inherit STABBER;
object user;
int cor;
void create()
{
        set_name(HIW + "七彩" + HIY + "鳳凰筆" + NOR,({ "seven_bird pen","pen" }) );
        set_weight(1000);
        set("no_sell",1);
        set("no_get",1);
        set("no_put",1);
        //set("no_save",1);
        set("no_drop",1);
        set("na_auc",1);
        set("no_sac",1);
        set("no_give",1);
        set("no_steal",1);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long", "此筆為女媧補天時用七彩神鳥的羽毛所做的筆，聽說有神秘的力量，只有儒尊才能使用的一支筆。\n");
        set("value", 0);
        set("material", "crimsonsteel");
        set("wield_msg","$N神態自若，從腰際取出" + HIW + "七彩" + HIY + "鳳凰筆" + NOR + "，$N全身上下散發出一股金光!!!\n");
        set("unwield_msg", "$N將手中$n收回腰際。\n");
        }
        //set("weapon_prop/damage",120);
        set("weapon_prop/stabber",10);
        set("weapon_prop/dodge",5);
        set("weapon_prop/dodge",5);
        init_stabber(110,SECONDARY);
        setup();
}
void init()
{
        object ob;
        add_action("do_wield","wield");
        add_action("do_unwield","unwield");
        user = this_player();
        if(userp(user) && present("seven_bird pen 2",user) && !wizardp(user))
        {
          call_out("do_clean",1,this_object());
        }
        if(user->query_temp("check_birdpen") && !wizardp(user) &&userp(user))
        {
         ob=this_object();
//         if(ob) call_out("do_clean",1,ob);
        }
        else
        {
         if(userp(user)) user->set_temp("check_birdpen",1);
        }
}
void do_clean(object ob)
{
 destruct(ob);
}
int do_wield(string str)
{
        user = this_player();
        if(!user->query_temp("wield_bird_pen"))
        {
         ::wield();
         if( query("equipped") )
         {
         if(str=="all" || str=="pen" || str=="seven_bird pen")
         {
         user->set_temp("wield_bird_pen",1);
         cor = user->query_cor();
         cor = cor *2;
         message_vision("$N神態自若，從腰際取出" + HIW + "七彩" + HIY + "鳳凰筆" + NOR + "，$N全身上下散發出一股金光!!!\n",user);
         set_heart_beat(1);
         }
         }
        }
}
int do_unwield(string str)
{
        if(str=="pen" || str=="seven_bird pen" || str=="all")
        {
        if(user->query_temp("wield_bird_pen"))
        {
          user->delete_temp("wield_bird_pen");
        }
        set_heart_beat(0);
        }
}
void heart_beat()
{
        object *enemy,who;
        int i,j,kar;
        if(user->query("family/family_name")=="儒門"){
        kar=user->query_kar();
        kar=kar+random(10);
        if(kar>45) kar=45;
        }
        else
        {
         set_heart_beat(0);
        }
  if( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
  if(kar > random(50))
  {
  if( user->is_fighting() && user->query_temp("wield_bird_pen") &&   query("equipped") )
  {
      enemy=user->query_enemy();
      i=sizeof(enemy);
      j=i;
      for(i=0;i<j;i++)
      {
      message_vision("$N" + HIW + "手中七彩鳳凰筆化作七彩神鳥，$N" + HIY + "命令神鳥直擊$n!!!\n"+NOR,this_object(),enemy[i]);
    if(80 > random(100))
    {
    message_vision(HIY + "只見神鳥利爪抓向$N，只間$N身上皮開肉綻，鮮血染紅了$N的全身，危在旦夕!!!\n\n" + NOR,enemy[i]);
    enemy[i]->receive_damage("kee",(100*random(5)),user);
    enemy[i]->apply_condition("burn", random(4));
    enemy[i]->apply_condition("hart", random(4));
    enemy[i]->start_busy(1);
    COMBAT_D->report_status(enemy[i]);
    }
    else
    {
    message_vision(HIC + "只見$N身手不凡，一下躲過了神鳥的追擊。\n" + NOR,enemy[i]);
    }
    }
  }
  }
  return;
}



