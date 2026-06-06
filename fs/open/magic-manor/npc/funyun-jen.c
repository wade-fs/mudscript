//取消心跳裡的玩家判定 與增加心跳裡環境的判斷 by blazakira 2011/8/17

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("封圓真",({"funyun jen","funyun","jen"}));
  set("long",@LONG
聚靈八傑之一，魔刀的後起之秀，自小就潛心練武，所才已將
刀法練至絕妙之境，自小孤苦無依的他，性格較為沉靜，甚是
得到莊主的青睞。
LONG);
  set("gender","男性");
  set("class","blademan");
  set("nickname",NOR+BLU"隱"HIB"刀"NOR+BLU"魂"HIB"絕"NOR);
  set("title",HIC"聚靈八傑"NOR);
  set("family/family_name","魔刀門");
  set("combat_exp",10000000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",20000);
  set("potential",50000);
  set("age",40);

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);

  set("env/魔性六斬","YES");
//  set("env/邪刀連擊","YES");
  set("env/get_mblade","YES");

  set("force",50000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("max_kee",50000);
  set("max_gin",50000);
  set("max_sen",50000);

  set_skill("blade",150);
  set_skill("dragon-blade",120);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",250);
  set_skill("fireforce",250);
  map_skill("parry","dragon-blade");
  map_skill("blade","dragon-blade");
  map_skill("force","fireforce");

  set("functions/mdragon-dest/level",100);
  set("functions/power-dest/level",100);
  set("functions/mk-blade/level",100);
  set("functions/busy/level",100);
  set("functions/powerup/level",100);
  set("functions/enforceup/level",100);
  set("functions/addbasic/level",100);
  set("functions/addblade/level",100);
  set("functions/badup/level",50);
  set("functions/hurtkee/level",100);
  set("functions/losehurt/level",100);
  set("functions/healup/level",100);
  set("functions/gold-fire/level",90);

  set("chat_chance_combat",50);
  set("chat_msg_combat", ({
    (: perform_action, "power-dest" :),
  }));

  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("mk-blade",1);
  set("m_blade",1);
  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set_temp("armor_vs_force",300);
  set_temp("no_die_soon",1);
  set_temp("rob",1); 
  set_temp("no-plan",1);
  set_temp("mount",1);
  set_temp("follow",1);
  set_temp("speed",1);
  set_temp("empty",1);
  set_temp("false",1);
  set_temp("lock-link",1);
  set_temp("six-hurt",1);

  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense",150);

  setup();

  add_money("cash",3);
  carry_object("/open/magic-manor/obj/evil-gwe-blade")->wield();
  carry_object("/daemon/class/blademan/obj/six-neck.c")->wear();
}

int accept_kill(object ob)
{
  object me=this_player();
  kill_ob(ob);
  command("wield all");
  command("wear all");
  command("perform blade.mdragon-dest");
  return 1;
}

void greeting(object ob)
{
  ob=this_player();
  if( ob->query_skill("coldpoison",1) && !wizardp(ob) )
  {
    command("say 學毒術之人，來討教幾招吧！！");
    kill_ob(ob);
    ob->start_busy(1);
  }
  set_heart_beat(1);
  return;
}

void heart_beat()
{
  object me=this_object();
  if(!me || !environment()) return ;

  if( !me->query_temp("secondary_weapon") )
  {
    command("wield all");
    command("wear all");
  }

  if( me->query("title") != "聚靈八傑" )
  {
    me->set("title",HIC"聚靈八傑"NOR);
  }

  if( !me->is_fighting() )
  {
    if( !me->query_temp("del") )
    {
      command("perform blade.mk-blade");
    }
    if( me->query("bellicosity") < 15000 )
    {
      me->add("bellicosity",5000);
    }
    if( !me->query_temp("addblade") )
    {
      command("addblade");
    }
//    if( !me->query_temp("powerup") )
//    {
//      command("powerup");
//    }
    if( !me->query_temp("addbasic") )
    {
      command("addbasic");
    }
    if( !me->query_temp("losehurt") )
    {
      command("losehurt");
    }
    if( !me->query_temp("addenforce") )
    {
      command("enfup");
    }
    if( !me->query_temp("focuskee") )
    {
      command("exert focuskee");
    }
  }

  if( me->is_fighting() )
  {
    if( !me->query_temp("badup") && !me->is_busy() )
    {
      command("badup");
    }
    if( !me->query_temp("hurtkee") && !me->is_busy() )
    {
      command("hurtkee");
    }
    if( !me->query_temp("addbusy") && !me->is_busy() )
    {
      command("busy");
    }
    if( !me->is_busy() )
    {
      command("perform blade.mdragon-dest");
    }
  }

  if( !is_fighting() ) 
  {
    if( query("force") < 39000 )
      command( "ex 300" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
      if( !me->query_temp("heal") )
      {
        command("healup");
      }
    }
    if( query("gin") < query("eff_gin") )
    {
      me->receive_curing("gin",350);
      me->receive_heal("gin",350);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
      me->receive_curing("sen",350);
      me->receive_heal("sen",350);
    }
  }

//  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object me,obj,winner;
  int j;
  me=this_object();
  winner=query_temp("last_damage_from");

  if(!winner)
  {
    ::die();
    return ;
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj12/lemon-doll")->move(environment(winner));
        message_vision(HIM"\n從封圓真的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/lemon_doll",sprintf("%s(%s) 讓封圓真掉下了檸檬娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj12/lemon-doll")->move(environment(winner));
        message_vision(HIM"\n從封圓真的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/lemon_doll",sprintf("%s(%s) 讓封圓真掉下了檸檬娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  if( random(6) == 3 )
  {
    obj=new("/open/magic-manor/obj/fire-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(9) == 5 )
  {
    obj=new("/open/magic-manor/obj/soil-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(12) == 7 )
  {
    obj=new("/open/magic-manor/obj/golden-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(15) == 9 )
  {
    obj=new("/open/magic-manor/obj/wood-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(18) == 11 )
  {
    obj=new("/open/magic-manor/obj/water-ball");
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
    obj->move(environment(winner));
  }
  ::die();
}
