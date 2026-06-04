#include <ansi.h>
inherit NPC;
inherit SSERVER;
string *dev = ({ "fire","water","ice","ground","thunder","wind","dark","saint",});

void create()
{
//	set("title","神秘劍客");
	set_name("神秘劍客", ({"swordsman"}));
	set("age",75);
	set("long","謎一般的神秘男子。\n");
	set("gender","男姓");
	set("str",30);
	set("con",30);
	set("class","fighter");
	set("family/family_name","仙劍派");
	set("bellicosity",1500);
	set("get_sha_sp",1);
	set("no_hire",1);
	set("max_kee",150000);
//	set("attitude","aggressive");
	set("kee",150000);
	set("max_gin",150000);
	set("gin",150000);
	set("max_sen",150000);
	set("sen",150000);
	set("combat_exp",10000000);
	set("max_force",300000);
	set("force",300000);
	set("force_factor",10);
	set("random_move",200);
	set_skill("dodge",120);
	set_skill("force",150);
	set_skill("linpo-steps",100);
	set_skill("unarmed",120);
	set_skill("haoforce",100);
	map_skill("dodge","linpo-steps");
	set_skill("sword",120);
	set_skill("shasword",120);
	map_skill("sword","shasword");
	map_skill("force","haoforce");
	set("chat_chance",100);
	set("chat_msg",({
	(: random_move :),
	}));
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
	"神秘劍客說道: 無知的後生小輩，看來你是活膩了!!\n",
	"神秘劍客說道: 哼!就讓你看看劍道之最高境界吧!!\n",
	"神秘劍客說道: 殺殺殺殺!!!\n",
	}));
	set_temp("apply/armor",500);
	set_temp("apply/damage",80);
	set("dev_obj/"+dev[random(sizeof(dev))],101+random(34650));
        set("quest/gold-fire",1);
	set_temp("roared",1);
	setup();
	carry_object("/autoload/sky/claw");
//	add_money("cash",300);
//	set("default_actions", (: call_other, __FILE__,"query_action" :));
	
//	reset_action();
}
void greeting( object ob )
{   
    if( !ob || environment(ob) != environment() ) return;
	if(ob->query("combat_exp")>1000000)
	{    
     write( HIY + "神秘劍客說道:死吧....漢人\n" + NOR ); 
     command("follow "+ob->query("id"));
	 kill_ob(ob);
	 command("exert roar");
	}
}
void heart_beat()
{
        object *enemy,*all,me;
        int i,j;
        me=this_object();
        if(!me->query_temp("weapon"))
        {
         command("change_attr sword");
         command("wield attribute-sword");
         command("wield attribute-sword");
        }
        j=random(100);
        if(!me) return ;
        if(!environment(me)) return ;
		all=all_inventory(environment(me));
/*		for( i=0 ; i<sizeof(all); i++ )
		    if( living(all[i]) && !is_fighting(all[i]) && all[i]->query("id")!="swordsman" )
		   	kill_ob(all[i]);
        
*/	  enemy = me->query_enemy();	
          for(i=0;i<sizeof(enemy);i++)
          {
             if(!enemy[i]) continue;
             if(enemy[i] && enemy[i]->query("combat_exp") > me->query("combat_exp"))
                   me->set("combat_exp",enemy[i]->query("combat_exp")+random(44444));  
          }
          if( j < 25 && is_fighting() )
          {  
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
			message_vision(HIW + "$N眼露兇光，隨著本身殺意的提升『" + HIR + "邪劍" + HIC + "無極" + HIW + "』之招頓然而出，剎時天地變色，血染塵埃。\n"+NOR,me,enemy[i]);
			enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/15);
            enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/20);
//            enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/20);
            COMBAT_D->report_status(enemy[i], 1);
            }
			me->delete_busy();
			me->clear_condition();
          }
		  }
          if( j > 25 && j < 45 && is_fighting() )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW + "天地間忽然竄起陣陣火光，$N唸道『" + HIG + "天" + HIW + "、" + HIM + "離火" + HIW + "、" + HIY + "一字" + HIR + "血" + HIY + "劍" + HIW + "』化成一道強烈的劍氣貫穿$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", enemy[i]->query("max_kee",1)/20);
              enemy[i]->receive_damage("sen", enemy[i]->query("max_sen",1)/20);
              enemy[i]->receive_damage("gin", enemy[i]->query("max_gin",1)/20);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 45 && j < 65&& is_fighting()  )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW + "$N全身內力不斷的注入劍中，使出一招『" + HIB + "劍霸四方" + HIW + "』，劍氣中挾帶十成功\力奮力砍向$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", 2500);
//             enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/15);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/15);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 65 && j < 80 && is_fighting() )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW + "$N劍朝天指，『" + HIY + "無極" + HIG + "劍氣" + HIW + "』吸收天地靈氣齊聚劍身，宏大的劍勁配合凌厲的劍氣迅速刺中$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", enemy[i]->query("max_kee",1)/10);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/15);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/15);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 80 && j < 92 && is_fighting()  )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIR + "血" + HIY + "披天色" + HIW + "，" + HIR + "魂" + HIG + "散四方" + HIW + "，$N體內『" + HIR + "血劍" + HIB + "魔" + HIY + "氣" + HIW + "』破體而出造成大地崩裂，江河逆流，$n瞬間遭血氣掩沒。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/15);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
		  if( j> 95 && is_fighting() )
          {
          enemy = me->query_enemy();
            i=random(sizeof(enemy));
              if(enemy[i])
              if(environment(me) == environment(enemy[i]))
              {
			  message_vision(HIR + "$N高喊:該死的漢人...看我的無極劍招連擊。\n"+NOR,me,enemy[i]);
			  message_vision(HIW + "$N眼露兇光，隨著本身殺意的提升『" + HIR + "邪劍" + HIC + "無極" + HIW + "』之招頓然而出，剎時天地變色，血染塵埃。\n"+NOR,me,enemy[i]);
              message_vision(HIW + "天地間忽然竄起陣陣火光，$N唸道『" + HIG + "天" + HIW + "、" + HIM + "離火" + HIW + "、" + HIY + "一字" + HIR + "血" + HIY + "劍" + HIW + "』化成一道強烈的劍氣貫穿$n。\n"+NOR,me,enemy[i]);
			  message_vision(HIW + "$N全身內力不斷的注入劍中，使出一招『" + HIB + "劍霸四方" + HIW + "』，劍氣中挾帶十成功\力奮力砍向$n。\n"+NOR,me,enemy[i]);
			  message_vision(HIW + "$N劍朝天指，『" + HIY + "無極" + HIG + "劍氣" + HIW + "』吸收天地靈氣齊聚劍身，宏大的劍勁配合凌厲的劍氣迅速刺中$n。\n"+NOR,me,enemy[i]);
			  message_vision(HIR + "血" + HIY + "披天色" + HIW + "，" + HIR + "魂" + HIG + "散四方" + HIW + "，$N體內『" + HIR + "血劍" + HIB + "魔" + HIY + "氣" + HIW + "』破體而出造成大地崩裂，江河逆流，$n瞬間遭血氣掩沒。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_damage("kee", 3000);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10);
			  enemy[i]->start_busy(1);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
        
  	if( !is_fighting() ) {
		
		if( query("eff_kee") < query("max_kee") ) 
			me->receive_curing("kee",100);
		if( query("eff_gin") < query("max_gin") )
		    me->receive_curing("gin",100);
		if( query("eff_sen") < query("max_sen") )
		    me->receive_curing("sen",100);
		if( query("gin") < query("eff_gin") ) 
			me->receive_heal("gin",100);
		if( query("kee") < query("eff_kee") )
			me->receive_heal("kee",100);
		if( query("sen") < query("eff_sen") ) 
			me->receive_heal("sen",100);
		}
        set_heart_beat(1);
        :: heart_beat();
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;
	j=random(3);
        set("combat_exp",10000000);
        if(!winner)
	{
	::die();
	return ;
        }

	
	if(j==0)
	{
	  new("/open/dancer/obj/dragon_gem")->move(winner);
	  message_vision(HIM + "\n從神秘劍客的身上掉下了一塊玉佩!!\n" + NOR,winner);
          write_file("/log/get_feq",sprintf("%s(%s) 拿到force gem於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	 }
	  tell_object(users(),HIC + "\n\n神秘劍客吼道：\n\n\t" + HIW + "想不到我流亡邊疆苦練多年依然不是"+winner->name()+"的對手！\n\n\t看來中原的能人不少不過我們不會就此罷休的！\n\n" + NOR);
	  message_vision(HIY + "\n"+winner->name()+"打死神秘劍客得到一百點戰功\!!\n" + NOR,winner);
      write_file("/log/get_warp",sprintf("%s(%s) 得到一百點戰功\於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  winner->add("war_score",100);
	  
	::die();                                                           
}
