//增加心跳裡環境的判斷 by blazakira 2011/8/18

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("香靈吟",({"shion yin","shion","yin"}));
  set("long",@LONG
聚靈八傑之一，個性較為暴燥，但論功夫卻是不輸一般男性，
起刀來，卻是不巾幗不讓鬚眉，殺遍天下無敵手，卻只是美人
難過情字這一關。
LONG);
  set("gender","女性");
  set("class","blademan");
  set("nickname",NOR+GRN"香"HIG"刀"NOR+GRN"魂"HIG"斷"NOR);
  set("title",HIC"聚靈八傑"NOR);
  set("family/family_name","金刀門");
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

  set("env/連擊","YES");

  set("force",200000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("max_kee",100000);
  set("max_gin",100000);
  set("max_sen",100000);

  set_skill("blade",150);
  set_skill("fast-blade",150);
  set_skill("gold-blade",150);
  set_skill("move",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("force",250);
  set_skill("fireforce",250);
  map_skill("parry","gold-blade");
  map_skill("blade","fast-blade");
  map_skill("force","fireforce");

  set("functions/gold-dest/level",100);
  set("functions/fast-dest/level",100);
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
  set("functions/leaf-blade/level",100);
/*
  set("chat_chance_combat",50);
  set("chat_msg_combat", ({
  }));
*/
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("mk-blade",1);
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

  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense",150);

  setup();

  add_money("cash",3);
  carry_object("/open/magic-manor/obj/maun-shadow-blade")->wield();
}

int accept_kill(object ob)
{
  object me=this_object();
  kill_ob(ob);
  me->delete_temp("is_busy");
  command("wield all");
  command("perform blade.fast-dest");
  return 1;
}

void greeting(object ob)
{
  ob=this_player();
  if(ob->query_temp("know_blade"))
  {
    ob->add_temp("know_blade",1);
    message_vision(HIW"香靈吟說道:「原來大師兄已將我的身世告訴你了，看來他很信
       任你，不過先祖留下的傳家之寶我還是不能如此
       輕易的交出來，無論如何，先擊敗我再說吧!!」\n\n"NOR,ob);
             kill_ob(ob);
    command("wield all");
    command("perform blade.fast-dest");
  }
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
  if( !me->query_temp("weapon") )
  {
  command("wield all");
  command("wear all");
  }
/*
  if( me->is_fighting() )
  {
    int i=me->query_busy();
    message_vision(HIC"$N目前busy指數「"HIM+i+HIC"」\n"NOR,me);
  }
*/
  if( !me->is_fighting() && !me->query_temp("del") )
  {
    command("perform blade.mk-blade");
    if( me->query("bellicosity") < 15000 )
    {
      me->add("bellicosity",5000);
    }
  }

  if( !me->query_temp("secondary_weapon") )
  {
    command("wield all");
  }

  if( !me->is_fighting() && !me->query_temp("addblade") )
  {
    command("addblade");
  }

//  if( !me->is_fighting() && !me->query_temp("powerup") )
//  {
//    command("powerup");
//  }

  if( !me->is_fighting() && !me->query_temp("addbasic") )
  {
    command("addbasic");
  }

  if( !me->is_fighting() && !me->query_temp("losehurt") )
  {
    command("losehurt");
  }

  if( !me->is_fighting() && !me->query_temp("addenforce") )
  {
    command("enfup");
  }

  if( !me->is_fighting() && !me->query_temp("focuskee") )
  {
    command("exert focuskee");
  }

  if( me->is_fighting() && !me->query_temp("badup") && !me->is_busy() )
  {
    command("badup");
  }

  if( me->is_fighting() && !me->query_temp("hurtkee") && !me->is_busy() )
  {
    command("hurtkee");
  }

  if( me->is_fighting() && !me->query_temp("addbusy") && !me->is_busy() )
  {
    command("busy");
  }

  if( me->is_fighting() && !me->is_busy() )
  {
    if( !me->query_temp("fast-dest") )
    {
      map_skill("blade", "fast-blade");
      command("perform blade.fast-dest");
    } else {
      map_skill("blade", "gold-blade");
      command("perform blade.gold-dest");
    }
  }

  if( me->query("title") != "聚靈八傑" )
  {
    me->set("title",HIC"聚靈八傑"NOR);
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

  if(winner->query_temp("know_blade") >= 2)
  {
    message_vision(HIG"香靈吟說道:「大俠果然武功\高強，妾身心甘情願交出祕笈，望大俠早日為武林除害。」\n"NOR,winner);
    message_vision(HIR"" + winner->query("name") + "得到了柳葉霸刀奧義。\n"NOR,winner);
    obj=new("/open/capital/obj/blade_book");
    obj->move(winner);
  }

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
        new("/open/sky/obj12/muskmelon-doll")->move(environment(winner));
        message_vision(HIM"\n從香靈吟的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/muskmelon_doll",sprintf("%s(%s) 讓香靈吟掉下了香瓜娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj12/muskmelon-doll")->move(environment(winner));
        message_vision(HIM"\n從香靈吟的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/muskmelon_doll",sprintf("%s(%s) 讓香靈吟掉下了香瓜娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  if( random(6) == 3 )
  {
    obj=new("/open/magic-manor/obj/golden-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(9) == 5 )
  {
    obj=new("/open/magic-manor/obj/wood-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(12) == 7 )
  {
    obj=new("/open/magic-manor/obj/water-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(15) == 9 )
  {
    obj=new("/open/magic-manor/obj/fire-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(18) == 11 )
  {
    obj=new("/open/magic-manor/obj/soil-ball");
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
    obj->move(environment(winner));
  }
  ::die();
}
