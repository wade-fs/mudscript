//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/7
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 by blazakira 2011/4/23

#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create()
{
  set("title",HIC"天弓"HIW"開霧"NOR);
	set_name("神秘箭客", ({"mystery shooter","shooter"}));
	set("age",75);
	set("long","謎一般的神秘男子。\n");
	set("gender","男性");
	set("str",30);
	set("con",30);
	set("kar",500);
	set("class","marksman");
	set("family/family_name","射日派");
	set("bellicosity",7000);
	set("get_sha_sp",1);
	set("no_hire",1);
	set("max_kee",150000);
//	set("kee",150000);
	set("max_gin",150000);
//	set("gin",150000);
	set("max_sen",150000);
//	set("sen",150000);
	set("combat_exp",10000000);
	set("max_force",300000);
	set("force",300000);
	set("force_factor",15);
	set("random_move",200);
	set_skill("dodge",120);
	set_skill("force",150);
	set_skill("rain-steps",100);
	set_skill("archery",120);
	set_skill("iceforce",100);
	map_skill("dodge","rain-steps");
	set_skill("parry",120);
	set_skill("god-shooting",120);
	map_skill("archery","god-shooting");
	map_skill("parry","god-shooting");
	map_skill("move","rain-steps");
	map_skill("force","iceforce");
	set("functions/super-shooting/level",100);
  set("functions/m-archery/level",100);
  set("chat_chance",100);
  set("chat_msg",({
       (: random_move :),
	}));
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
	"謎說: 無知的後生小輩，看來你是活膩了!!\n",
	"謎說: 哼!就讓你看看箭技之最高境界吧!!\n",
	"謎說: 殺殺殺殺!!!\n",
	}));
	set_temp("apply/armor",500);
	set_temp("apply/damage",80);
	set("dev_obj/fire",90000+random(1000));
	set("dev_obj/ice",90000+random(1000));
	set("dev_obj/water",90000+random(1000));
	set("dev_obj/ground",90000+random(1000));
	set("dev_obj/thunder",90000+random(1000));
	set("dev_obj/wind",90000+random(1000));
	set("dev_obj/dark",90000+random(1000));
	set("dev_obj/saint",90000+random(1000));
	set_temp("thunder_power",2500+random(2500));
	set("weapon/fire-full",1);
	set("weapon/ice-full",1);
	set("weapon/water-full",1);
	set("weapon/ground-full",1);
	set("weapon/wind-full",1);
	set("weapon/thunder-full",1);
	set("weapon/dark-full",1);
	set("weapon/saint-full",1);
	set("quest/gold-fire",1);
	set("mystery",1);
	set_temp("roared",1);//預設roar過，不然會有一點問題
	setup();
	carry_object("/autoload/sky/claw");
	carry_object("/open/marksman/obj/arrow-g");
//	add_money("cash",300);
//	set("default_actions", (: call_other, __FILE__,"query_action" :));
	  if(clonep())
    set_heart_beat(1);

//	reset_action();
}
void init()
{
  if(environment(this_object())->query("no_fight")) return ;

  call_out("greeting",3,this_player());
}
void greeting( object ob )
{   
  if( !ob || environment(ob) != environment() ) return;
  if(environment(this_object())->query("no_fight")) return ;

  if( !ob->query("mystery") )
  {
    if(ob->query("combat_exp")>2000000 )
    {
      if(ob->query("combat_exp") > 5000000) 
      {
      write( HIY"神秘箭客說道:死吧....漢人\n"NOR ); 
      command("follow "+ob->query("id"));
      set("class","fighter");
      command("exert roar");
      set("class","marksman");
      command("cmd mark "+ob->query("id"));
      }
    kill_ob(ob);
    }else{
    command("snort "+ob->query("id"));
    command("say 死嫩嫩，練強一點吧！");
    }
  }
}


void heart_beat()
{
        object *enemy,wp,me,victim;
        int i,j;
        if(!environment(this_object())) return ;
        me=this_object();
        if(!me->query_temp("weapon"))
        {
         command("change_attr archery");
         command("wield attribute-bow");
         command("cmd holdup arrow with attribute-bow");
        }
        if(!me->is_fighting() && me->query_temp("mark_goal"))
        {
          victim = me->query_temp("mark_goal");
          if(userp(victim))
          {
           command("perform archery.super-shooting");
           me->delete_busy();
           me->add("kee",10);
           me->add("force",400);
           victim->set_temp("be_shooted",1);
          }
        }
        j=random(100);
        if(!me) return ;
        if(!environment(me)) return ;
        enemy = me->query_enemy();
        for(i=0;i<sizeof(enemy);i++)
        {
           if(!enemy[i]) continue;
           if(enemy[i] && enemy[i]->query("combat_exp") > me->query("combat_exp"))
                 me->set("combat_exp",2*(enemy[i]->query("combat_exp")));  //因應變態級玩家,調整自身exp
        }
        if( j < 25 && is_fighting() )
          {
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
			message_vision(HIW"$N眼露兇光，隨著本身殺意的提升『"HIR"邪箭"HIC"無極"HIW"』之招頓然而出，剎時天地變色，血染塵埃。\n"+NOR,me,enemy[i]);
			enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/15,me);
            enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/20,me);
//            enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/20,me);
            COMBAT_D->report_status(enemy[i], 1);
            }
			me->delete_busy();
			me->clear_condition();
          }
		  }
          if( j > 25 && j < 45 && is_fighting() )
          {
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW"天地間忽然竄起陣陣火光，$N唸道『"HIG"天"HIW"、"HIM"離火"HIW"、"HIY"一字"HIR"血"HIY"箭"HIW"』化成一道強烈的箭芒貫穿$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", enemy[i]->query("max_kee",1)/20,me);
              enemy[i]->receive_damage("sen", enemy[i]->query("max_sen",1)/20,me);
              enemy[i]->receive_damage("gin", enemy[i]->query("max_gin",1)/20,me);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 45 && j < 65&& is_fighting()  )
          {
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
message_vision(HIW"$N全身內力不斷的注入箭中，使出一招『"HIB"箭霸四方"HIW"』，箭氣中挾帶十成功\力奮力射向$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", 2500,me);
//             enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/15,me);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/15,me);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 65 && j < 80 && is_fighting() )
          {
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
message_vision(HIW"$N弓朝天指，『"HIY"無極"HIG"箭氣"HIW"』吸收天地靈氣齊聚自身，宏大的箭勁配合凌厲的箭氣迅速射中$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", enemy[i]->query("max_kee",1)/10,me);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/15,me);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/15,me);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 80 && j < 92 && is_fighting()  )
          {
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIR"血"HIY"披天色"HIW"，"HIR"魂"HIG"散四方"HIW"，$N體內『"HIR"血箭"HIB"魔"HIY"氣"HIW"』破體而出造成大地崩裂，江河逆流，$n瞬間遭血氣掩沒。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/15,me);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10,me);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10,me);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
		  if( j> 95 && is_fighting() )
          {
            i=random(sizeof(enemy));
              if(enemy[i])
              if(environment(me) == environment(enemy[i]))
              {
		message_vision(HIR"$N高喊:該死的漢人...看我的無極箭招連擊。\n"+NOR,me,enemy[i]);
		message_vision(HIW"$N眼露兇光，隨著本身殺意的提升『"HIR"邪箭"HIC"無極"HIW"』之招頓然而出，剎時天地變色，血染塵埃。\n"+NOR,me,enemy[i]);
		message_vision(HIW"天地間忽然竄起陣陣火光，$N唸道『"HIG"天"HIW"、"HIM"離火"HIW"、"HIY"一字"HIR"血"HIY"箭"HIW"』化成一道強烈的劍氣貫穿$n。\n"+NOR,me,enemy[i]);
		message_vision(HIW"$N全身內力不斷的注入箭中，使出一招『"HIB"箭霸四方"HIW"』，箭氣中挾帶十成功\力奮力射向$n。\n"+NOR,me,enemy[i]);
		message_vision(HIW"$N弓朝天指，『"HIY"無極"HIG"箭氣"HIW"』吸收天地靈氣齊聚自身，宏大的箭勁配合凌厲的箭氣迅速射中$n。\n"+NOR,me,enemy[i]);
		message_vision(HIR"血"HIY"披天色"HIW"，"HIR"魂"HIG"散四方"HIW"，$N體內『"HIR"血箭"HIB"魔"HIY"氣"HIW"』破體而出造成大地崩裂，江河逆流，$n瞬間遭血氣掩沒。\n"+NOR,me,enemy[i]);
		enemy[i]->receive_damage("kee", 3000,me);
		enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10,me);
		enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10,me);
		enemy[i]->start_busy(1);
		COMBAT_D->report_status(enemy[i], 1);
              }
            }
        
	if( !is_fighting() )
	{
		
	  if( query("eff_kee") < query("max_kee") ) 
	  me->receive_curing("kee",1000);
	  if( query("eff_gin") < query("max_gin") )
	  me->receive_curing("gin",1000);
	  if( query("eff_sen") < query("max_sen") )
	  me->receive_curing("sen",1000);
	  if( query("gin") < query("eff_gin") ) 
	  me->receive_heal("gin",1000);
	  if( query("kee") < query("eff_kee") )
	  me->receive_heal("kee",1000);
	  if( query("sen") < query("eff_sen") ) 
	  me->receive_heal("sen",1000);
	}

	if( me->query("combat_exp") > 300000000 )
	me->set("combat_exp",300000000);

        :: heart_beat();

        set_heart_beat(1);
}

void die()
{
	object ob,winner = query_temp("last_damage_from");
	int j;
	j=random(3);
        if(!winner)
	{
	::die();
	return ;
        }

  if(winner && !winner->query_temp("not_robot") && random(500)==0) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","奎");
    ob->move(winner);
    message_vision(YEL"\n從神秘箭客的身上掉下了一塊靈魂碎片!!\n"NOR,winner);
  }
  else if(winner && winner->query_temp("not_robot") && random(1000)<125) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","奎");
    ob->move(winner);
    message_vision(YEL"\n從神秘箭客的身上掉下了一塊靈魂碎片!!\n"NOR,winner);
  }

	if(j==0)
	{
	  new("/open/dancer/obj/dragon_gem")->move(winner);
	  message_vision(HIM"\n從神秘箭客的身上掉下了一塊玉佩!!\n"NOR,winner);
          write_file("/log/get_feq",sprintf("%s(%s) 拿到force gem於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	 }
	  tell_object(users(),HIC"\n\n神秘箭客吼道：\n\n\t"HIW"想不到我流亡邊疆苦練多年依然不是"+winner->name()+"的對手！\n\n\t看來中原的能人不少，不過我們不會就此罷休的！\n\n"NOR);
	  message_vision(HIY"\n"+winner->name()+"打死神秘箭客得到一百一十一點戰功\!!\n"NOR,winner);
	write_file("/log/get_war/shooter",sprintf("%s(%s)	得到一百一十一點戰功\於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  winner->add("war_score",111);

	::die();
}
