#include <ansi.h>
#include <combat.h>
inherit NPC;
int i=random(4)+1,j=random(4)+1,k=random(4)+1;

void create()
{
        set("title","冥殿第七殿殿主");
        set_name("血掌蟠妖",({"goblin"}));
	set("gender","男性");
        set("age",750);

	set("attitude","aggressive");

	set("combat_exp",40000000);
        set("force_factor",23);
        set("bellicosity",9000);

	set("max_kee", 180000);
        set("kee", 180000);
	set("max_gin",90000);
        set("gin",90000);
        set("max_sen",90000);
        set("sen",90000);
        set("max_atman",25000);
        set("atman",25000);
        set("max_mana",20000);
        set("mana",20000);
        set("max_force",28000);
        set("force",28000);
        set("cor", 40);
        set("cps", 40);
        set("str", 60);
	set("per", 20);

	command("wield all");
        command("wear all");

	set_skill("hell-evil",120);
        set_skill("unarmed",150);
        set_skill("dodge",120);
        set_skill("fly-steps", 120);
	set_skill("force",200);
	set_skill("parry",120);
	set_skill("fiendforce",200);
        map_skill("force","fiendforce");
        map_skill("unarmed","hell-evil");
	map_skill("dodge","fly-steps");
        map_skill("dodge","fly-steps");
	map_skill("parry","hell-evil");

        set("functions/fight/level",120);

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
//	set_temp("roared",1);

	set_temp("apply/armor",150);
	set_temp("apply/attack",150);
	set_temp("apply/damage",150);
        set_temp("apply/defense",150);

	setup();

	carry_object("/open/tendo/room/tower/obj/ring")->wield();
        carry_object("/open/mogi/castle/obj/ninepill")->set_amount(i);
        carry_object("/open/tendo/room/tower/obj/fiend_pill")->set_amount(j);
        carry_object("/open/tendo/room/tower/obj/six_pill")->set_amount(k);
	add_money("gold",10);
}

int accept_kill(object ob)
{
        int i;
        object ob1,hu_fa;
        string place;
        ob1 = this_object();

        if( !present("hu-fa", environment(ob)) )
        {
        tell_room(environment(ob),HIW"\n突然！衝出兩位護法!!\n\n"NOR);
        for(i=0;i<2;i++)
         {
         hu_fa = new("/open/tendo/room/tower/npc/hu_fa");
         hu_fa->move(environment(ob));
         hu_fa->kill_ob(this_player());
         }
        }
        write("護法縱身飛撲過來叫道：大膽狂徒！殿主你也敢動！！\n");
        return 1;
}

void heart_beat()
{
	object me=this_object(), *enemy;
	int i, j, k, l, m, n;

	enemy = me->query_enemy();
	i = random(5);
	k = random(13);
	m = 4500;
	n = 0;

	   
	if( !me->query_temp("fight") )
	{
	me->delete_temp("is_busy");
	me->delete_busy();
	me->delete_temp("no_power_f");
	me->delete_temp("no_power_e");
	command("perform force.fight");
	me->delete_busy();
	}

	if( random(2) == 1 && me->is_fighting() )
	{
	  if( i == 0 && me->is_busy() )
	  {
	  message_vision(HIW"$N深吸了一口氣，衝破了所有的禁錮。\n"NOR,me);
	  me->delete_busy();
	  }

	  if( i == 1 )
	  {
	  message_vision(HIC"$N運起修羅心法之最高境界"HIW"「"HIM"修羅不滅身"HIW"」"HIC"與自身獨有靈氣融合，回復了部份的狀態。\n"NOR,me);
	  me->receive_curing("kee",random(m)+m);
	  me->receive_heal("kee",random(m)+m);
	  me->receive_curing("gin",random(m)+m);
	  me->receive_heal("gin",random(m)+m);
	  me->receive_curing("sen",random(m)+m);
	  me->receive_heal("sen",random(m)+m);
	  me->add("force",random(m*5));
	  }

	  if( i == 2 )
	  {
	  message_vision(HIC"$N運氣聚於身，大喝一聲，"HIW"「"HIM"修羅不滅身．幻滅定一瞬"HIW"」"HIC"，爆開的氣朝所有人四射飛去，中招者無一能動。\n"NOR,me);
	    for(j=0;j<sizeof(enemy);j++)
	    {
	      if(!enemy[j]) continue;
	      if(environment(me) == environment(enemy[j]))
	      {
	      enemy[j]->start_busy(1);
              COMBAT_D->report_status(enemy[j]);
	      }
	    }
	  }
 	}else{
	  if( me->is_fighting() )
	  {
	  j = random(sizeof(enemy));
	    if( environment(me) == environment(enemy[j]) )
	    {
	    message_vision(RED"\n$N"HIW"大喝道：拿出你的本事來接我冥殿絕學吧！！\n\n"NOR,me,enemy[j]);

	      switch(k)
              {
              case 0:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  一  式 －－"NOR"
                  "HIB"～『  "HIY"妖 魔 聚 鼎"HIB"  』～\n"NOR"
"HIW"$N身形倏而騰飛三丈,凌空劈出一"NOR+HIW"股掌勁,綿綿掌影,如江河缺堤似,暴瀉而下,掌風如激流"NOR+HIW"般地向$n隔空劈來!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",220);
              enemy[j]->receive_damage("sen",220);
              enemy[j]->receive_wound("kee",400);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 1:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  二  式 －－"NOR"
                  "HIB"～『  "HIR"魔 性 狂 發"HIB"  』～\n"NOR"
"HIW"$N滿頭銀髮迎風如濤,雙目吐光如炬,"HIW"忽然雙臂抖舞,幻化成千百條手臂,每一條手臂撲出一般渾"HIW"雄的掌風,慢天的掌影向$n捲劈而來!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",320);
              enemy[j]->receive_damage("sen",340);
              enemy[j]->receive_wound("kee",800);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 2:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  三  式 －－"NOR"
                  "HIB"～『  "HIW"鬼 氣 貫 腦"HIB"  』～\n"NOR"
"HIW"$N雙手暴長，臉部青絲暴露，濃烈的惡"HIW"臭從雙掌透出，只見$N雙手不停疾舞，勁氣中夾帶著"HIW"令人聞之欲嘔的毒氣,使得$n受到毒氣的影響，受到不輕的傷害!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",420);
              enemy[j]->receive_damage("sen",460);
              enemy[j]->receive_wound("kee",1200);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 3:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  四  式 －－"NOR"
                  "HIB"～『  "HIC"魑 魅 魍 魎"HIB"  』～\n"NOR"
"HIW"$N一聲龍吟般的長嘯,挫身飛騰,身形盪"HIW"空迴舞,一連串動作在同一石火電光之間完成,自不同的方向,"HIW"不同的角度,那宛如似厲鬼魔爪般的掌影,向$n詭異奇絕的飛劈而至!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/21);
              enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/21);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/21);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 4:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  五  式 －－"NOR"
                  "HIB"～『  "MAG"鬼 魅 拜 月"HIB"  』～\n"NOR"
"HIW"只見$N身形一躬，雙掌前劈，一道半月"HIW"形的勁氣猛然向前湧去，雄渾的勁氣，刮得地面如飛沙走石般"HIW"地向$n狂襲而去!!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/19);
              enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/19);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/19);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 5:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  六  式 －－"NOR"
                  "HIB"～『  "HIY"掌 不 刃 血"HIB"  』～\n"NOR"
"HIW"$N雙掌化成千百掌影,掌影又凝成一股驚"HIW"天動魄的勁氣,朝向破風聲來處劈去!!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/17);
              enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/17);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/17);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 6:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  七  式 －－"NOR"
                  "HIB"～『  "HIC"妖 鬼 莫 測"HIB"  』～\n"NOR"
"HIW"$N屈體弓身，雙掌緊貼地面，全身籠罩在"HIW"一片藍光中，地面宛如波濤般浮動，隨著蓄積的內勁，藍光不斷"HIW"增加，只見$N突然將雙掌一合，一道駭人藍箭向$n疾射而去!\n"NOR,me,enemy[j]);
	      enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/15);
              enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/15);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/15);
              COMBAT_D->report_status(enemy[j]);
              break;

              case 7:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  八  式 －－"NOR"
                  "HIB"～『  "HIR"風 魔 狂 轉"HIB"  』～\n"NOR"
"HIW"$N以氣貫入雙爪 ,雙爪閃出一陣耀目金光,"HIW"氣提十二成 ,勁注全身 ,蓄勢準備使出最強最霸道的一式,霎時"HIW"狂龍魔氣急速旋繞$N ,無儔魔氣因此驚動天地之氣 ,互抗暴出"HIW"數道紫電雷光 ,$N忽然現身於$n前 ,對$n使出了石破天驚的一擊!\n"NOR,me,enemy[j]);
		for(j=0;j<sizeof(enemy);j++)
		{
		  if(!enemy[j]) continue;
		  if(environment(me) == environment(enemy[j]))
		  {
		  enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/13);
		  enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/13);
		  enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/13);
		  COMBAT_D->report_status(enemy[j]);
		  }
		}
              break;

              case 8:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  九  式 －－"NOR"
                  "HIB"～『  "HIY"鬼 影 重 重"HIB"  』～\n"NOR"
"HIW"無窮無盡的勁力由四周湧入$N體內，只見冥"HIW"殿修羅雙掌不停做著細微的變化，彷彿如黑洞般，將萬物都吞食"HIW"淹滅,忽然雙掌擊向$n的全身!\n"NOR,me,enemy[j]);
		for(j=0;j<sizeof(enemy);j++)
		{
		  if(!enemy[j]) continue;
		  if(environment(me) == environment(enemy[j]))
		  {
		  enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/11);
		  enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/11);
		  enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/11);
		  COMBAT_D->report_status(enemy[j]);
		  }
		}
              break;

	      case 9:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  十  式 －－"NOR"
                  "HIB"～『  "HIW"鬼 氣 無 濤"HIB"  』～\n"NOR"
"HIW"$N狂吼一聲,上空平身挪後三寸,左手拍地,右"HIW"手股動內勁,破天而出,掌勁如山,激起無濤的氣勁,夾著雷霆萬駒"HIW"之勢朝$n而來!!\n"NOR,me,enemy[j]);
		for(j=0;j<sizeof(enemy);j++)
		{
		  if(!enemy[j]) continue;
		  if(environment(me) == environment(enemy[j]))
		  {
		  enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/9);
		  enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/9);
		  enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/9);
		  COMBAT_D->report_status(enemy[j]);
		  }
		}
              break;

              case 10:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  十  一  式 －－"NOR"
                  "HIB"～『  "HIC"鬼 焰 凌 厲"HIB"  』～\n"NOR"
"HIW"$N左足橫移,挫腰沈身,單袖一揚,瞬時狂風拂"HIW"起, 塵沙飛揚,$N趁飛沙走石之際,運起陽剛真氣,身形一旋,"HIW"雙掌內攏,催起一股凌厲的氣焰,朝$n的天靈蓋\連續拍出數掌!\n"NOR,me,enemy[j]);
		for(j=0;j<sizeof(enemy);j++)
		{
		  if(!enemy[j]) continue;
		  if(environment(me) == environment(enemy[j]))
		  {
		  enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/7);
		  enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/7);
		  enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/7);
		  COMBAT_D->report_status(enemy[j]);
		  }
		}
              break;

              case 11:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"第  十  二  式 －－"NOR"
                  "HIB"～『  "HIR"群 魔 亂 舞"HIB"  』～\n"NOR"
"HIW"$N閃身反掌擊出，一道青色光芒從掌中發出，"HIW"使$n分不清身在何方，只見$N身形一展，幻化成千萬身影,"HIW"身影中夾帶著沉重的掌勁向$n罩下,$n正在遲疑之際已被無數掌影所擊中!\n"NOR,me,enemy[j]);
		for(j=0;j<sizeof(enemy);j++)
		{
		  if(!enemy[j]) continue;
		  if(environment(me) == environment(enemy[j]))
		  {
		  enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/5);
		  enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/5);
		  enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/5);
		  COMBAT_D->report_status(enemy[j]);
		  }
		}
              break;
              case 12:
	      message_vision(HIB"          －－ "HIW"冥  殿  "HIR"絕  "HIY"學  "HIB"之  "HIC"終  "RED"極  "MAG"秘  "HIW"技 "HIB"－－"NOR"
                  "HIB"～『  "MAG"千  魂  滅  散"HIB"  』～\n"NOR"
"HIW"$N重重的掌,連疊的拳,萬鈞之力,渾雄之氣,煞"HIW"時天空彷彿突然黑暗下來,妖魔彷彿都從墓地爬了起來,推山倒海,"HIW"大地翻滾,縱橫上下空間,為掌風與掌影所佈,有如綿綿飛際的利刃擊向$n!!\n"+NOR,me,enemy[j]);
		for(j=0;j<sizeof(enemy);j++)
		{
		  if(!enemy[j]) continue;
		  if(environment(me) == environment(enemy[j]))
		  {
		  enemy[j]->receive_damage("gin",enemy[j]->query("max_gin")/3);
		  enemy[j]->receive_damage("sen",enemy[j]->query("max_sen")/3);
		  enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/3);
		  COMBAT_D->report_status(enemy[j]);
		  }
		}
              break;
	      }
	    }
	  }
	}

	if( !me->is_fighting() ) 
	{
	  if( query("force") < 40000 ) 
	  command( "ex 270" );
	  if( query("kee") < query("eff_kee") ) 
	  {
	  me->receive_curing("kee",1000);
	  me->receive_heal("kee",1000);
	  }
	  if( query("gin") < query("eff_gin") )
	  {
	  me->receive_curing("gin",1000);
	  me->receive_heal("gin",1000);
	  }
	  if( query("kee") < query("eff_kee") ) 
	  command( "5 exert recover" );
	  if( query("sen") < query("eff_sen") ) 
	  {
	  me->receive_curing("sen",1000);
	  me->receive_heal("sen",1000);
	  }
	}

	set_heart_beat(1);
	::heart_beat();
}
