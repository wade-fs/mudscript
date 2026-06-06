inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>


string do_special_fight();

void create()
{
	set_name("火飛笙", ({ "fire king","fire","king" }) );
	set("long","火靈塔的鎮塔之王，能力比小火妖和火靈獸不知強上幾倍。\n");
	set("title",HIR + "(紅色靈氣)" + NOR + "火靈塔王" + NOR);
	set("class","scholar");
	set("family/family_name","段家");
	set("gender","女性");
	set("age", 60);
	set("max_gin", 80000);
	set("max_kee", 80000);
	set("max_sen", 80000);
	set("max_force", 20000);
	set("force",200000);
	set("max_atman",50000);
	set("max_mana",50000);
	set("atman",50000);
	set("mana",50000);
	set("force_factor",20);
	set("attitude","aggressive");
	set("str", 35);
	set("cor", 35);
	set("spi", 35);
	set("int", 35);
	set_temp("apply/armor", 150);
	set_temp("apply/defense", 250);
	set("bellicosity",10000);
	set("functions/handwriting/level",100);
        set_skill("dodge", 100);
        set_skill("force",100);
        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("stabber",120);
        set_skill("unarmed",100);
        set_skill("literate",120);
        set_skill("sunforce",100);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");

	set("combat_exp", 8000000);
	set("fire-monster",1);
	set("marks/sun-finger",1);
	set("marks/six_sp",3);
	set("six_spsp",1);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({ (: perform_action("stabber.handwriting") :), }) );
	setup();

	add_money("cash",3);
	carry_object("/open/magic-manor/fire/obj/fire-fan")->wield();
}

void heart_beat()
{
	object mob,me,obj;
	mixed enemy;
	int i,j=0,k=random(2);
	mob = this_object();
	me = this_player();
	enemy = all_inventory( environment(mob) );
	i = sizeof(enemy);

	if( !mob->is_fighting() || mob->is_fighting() )
	{
	  for (j=0 ; j < i ; j++)
	  {
	    if( !enemy[j] ) continue;
	    {
	      if(!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
	      && living(enemy[j]) && !enemy[j]->query("fire-monster") ) 
	      mob->kill_ob(enemy[j]);
	    }
	  }
	}

	if(random(10) > 6 && mob->is_fighting() )
	{
	message_vision(HIM + "火捲漫天，雲淡風輕，輕煙漫舞於天際，$N別有感觸翩然起舞飄然喚出

            " + HIW + "----===≡◎ 火捲風雲式 ◎≡===----
                 " + NOR+RED + "  『" + HIR + "火雲鳳舞．翔風飛" + NOR+RED + "』\n\n" + NOR,mob);

      for (j=0 ; j < i ; j++)
      {
        if( !enemy[j] ) continue;
        {
          if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
          && !enemy[j]->query("fire-monster") )
          {
            if( !enemy[j]->query_temp("magic-manor/water-shield") )
            {
            message_vision(HIR + "$N" + HIR + "只感渾身灼熱，還不時傳出陣陣燒焦的臭味!!\n" + NOR,(enemy[j]));
            enemy[j]->receive_wound("kee",600);
            enemy[j]->start_busy(1);
            COMBAT_D->report_status(enemy[j]);
            }else{
            message_vision(HIC + "$N" + HIC + "身上的水靈之氣緩和了部份的火焰衝擊!!\n" + NOR,(enemy[j]));
            enemy[j]->receive_wound("kee",300);
            enemy[j]->start_busy(k);
            COMBAT_D->report_status(enemy[j]);
            }
          }
        }
      }
    }   
    set_heart_beat(1);
    ::heart_beat();
   
}

int accept_kill(object who)
{
        who=this_player();

        command("unwield all");
        command("wield fan");
        command("kill "+who->query("id"));
        command("exert sun-finger");
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}

int accept_fight(object who)
{
        who=this_player();

        command("unwield all");
        command("wield fan");
        command("exert sun-finger");
        fight_ob(who);
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}

void die()
{
	object me=query_temp("last_damage_from");
	int j;
    if(userp(me) && me->query_temp("not_robot") > time() )
    {
	if ( me->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {      
	  new("/open/sky/obj12/strawberry-doll")->move(environment(me));
	  message_vision(HIM + "\n從火飛笙的身上掉下了一件奇怪的東西!!\n" + NOR,me,me);
          write_file("/log/sky/obj12/strawberry_doll",sprintf("%s(%s) 讓火飛笙掉下了草莓娃娃於 %s\n",
	  me->name(1),me->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj12/strawberry-doll")->move(environment(me));
	  message_vision(HIM + "\n從火飛笙的身上掉下了一件奇怪的東西!!\n" + NOR,me,me);
          write_file("/log/sky/obj12/strawberry_doll",sprintf("%s(%s) 讓火飛笙掉下了草莓娃娃於 %s\n",
	  me->name(1),me->query("id"),ctime(time())));
	  }
	}
	}
	if( !me->query_temp("magic-manor/firemagic") )
	{
	message_vision(HIR + "火飛笙死後的靈魂忽然化為一道紅色靈光，灌入了$N" + HIR + "的身體之中!!\n" + NOR,me);
	me->set_temp("magic-manor/firemagic",1);
	  if( !me->query("magic-manor/kill-fire") )
	  {
	  me->set("magic-manor/kill-fire",1);
	  }else{
	  me->add("magic-manor/kill-fire",1);
	  }
	}else{
	  if( !me->query("magic-manor/kill-fire") )
	  {
	  me->set("magic-manor/kill-fire",1);
	  }else{
	  me->add("magic-manor/kill-fire",1);
	  }
	}
	me->delete_temp("magic-manor/breakfire",1);
	message_vision("\n\n塔身因為火靈王的滅亡而慢慢的出現了一些裂痕.....\n",me);

	:: die();
}
