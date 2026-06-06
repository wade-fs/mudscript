//edit by neverend   2000/11/09
//將receive_wound補上攻擊方之參數 by blazakira 2011/7/24

#include <ansi.h>
#include <killed.fun>       // 7.21.93 by Firedancer
#include <count-time.fun>   // 7.21.93 by Firedancer
inherit NPC;

void do_special();

void create()
{
  seteuid(getuid());
  set("long","
舞風揚，躲在這盤天巨木中修練，歷經千年的修行，已然化身成人形，髮絲隨風
飄逸，雖然歷經千年卻也藏不住他嬌柔百媚的身段，平常不輕易離開巨木，所以
也鮮少與凡人接觸，一個人獨自在這洞中過著她單調而無聊的修行。");
  set("gender","女性");
  set("class","fighter");
  set("nickname",HIC"千風任起舞"HIW"–"HIC"萬風雲飄揚"NOR);
  set("title",HIG"千年樹妖"NOR);
  set_name("舞風揚",({"dance wind","wind"}));
  set("combat_exp",16500000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",10000);
  set("age",1000);
  set("max_force",15000);
  set("force",150000);
  set("max_kee",165000);
//  set("kee",165000);
  set("max_mana",15000);
  set("mana",15000);
  set("max_atman",15000);
  set("atman",15000);
  set("max_gin",100000);
//  set("gin",100000);
  set("max_sen",100000);
//  set("sen",100000);
  set("str", 35);
  set("cor", 35);
  set("cps", 30);
  set("per", 99);
  set("int", 35);
  set("force_factor",15);
  set_skill("dodge",350);
  set_skill("force",250);
  set("clan_kill",1);
  set("no_mount",1);
  set("no_plan_follow",1);
  set_skill("move",300);
  set_skill("parry",350);
  set_skill("mogi-steps",350);
  set_skill("unarmed",150);
  set_skill("literate",100);
  set_skill("fiendforce",250);
  set_skill("dance-wind",120);
  set_temp("armor_vs_force",1000);
  map_skill("force","fiendforce");
  map_skill("dodge","mogi-steps");
  map_skill("move","mogi-steps");
  map_skill("parry","dance-wind");
  map_skill("unarmed","dance-wind");
  set("functions/fight/level",120);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set_temp("mount",1);
  set_temp("follow",1);
  set_temp("speed",1);
  set_temp("empty",1);
  set_temp("false",1);
  set_temp("lock-link",1);
  set_temp("ghost",1);
  set_temp("rob",1);  
  set_temp("no-plan",1);
  set_temp("no_die_soon",1);
  set_temp("apply/armor",120);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense", 200);
  set("chat_chance_combat",35);
  set("chat_msg_combat",({
    (: do_special :)
  }));

  setup();
  carry_object("/open/mon/obj/ghost-helmet")->wear();
  carry_object("/open/mon/obj/ghost-cloak")->wear();
  carry_object("/open/mon/obj/ghost-legging")->wear();
  carry_object("/open/mon/obj/ghost-claw");
  carry_object("/autoload/open-area/ghost-heart")->wear();
  add_money("cash",20);
}

void init()
{
  ::init();
  this_object()->set_temp("ok_wield",1);
  add_action( "block_cmd", "" );
  add_action( "do_cmd","cmd" );
}

//修正來自Acky的fire king擋do的功能

int block_cmd( string arg )
{
  if( (string)query_verb() == "do" )
  {
    write( HIY"舞風揚輕笑說：「想要投機嗎？我最恨投機的人了，納命來吧!!」\n"NOR );
    if( is_fighting() )
      this_player()->start_busy(1);
    return 1;
  }
}

int do_cmd(string str)
{
  object who=this_player();
  object ob,wind;
  ob=this_object();
  wind=present( "wind",environment(ob) );
  if(str=="throw wind" || str=="throw dance wind")
  {
    write(HIY"舞風揚輕笑說：「用這種下三爛的方法就想殺我!去死吧!!」\n"NOR);
    command("perform fireforce.gold-fire");
    wind->kill_ob(who);
    who->start_busy(1);
    return 1;                                                 
  }
  else if(str=="askgod wind" || str=="askgod dance wind")
  {
    write(HIY"舞風揚輕笑說：「等你的道行比我高時再來替我算命吧。」呵呵呵!!\n"NOR);
    command("perform fireforce.gold-fire");
    wind->kill_ob(who);
    who->start_busy(1);
    return 1;                                                 
  }
  else if(str=="bak wind" || str=="bak dance wind")
  {
    write(HIY"舞風揚輕笑說：「你們這些凡人，想暗殺我，實在是太可笑了!!\n"NOR);
    command("perform fireforce.gold-fire");
    wind->kill_ob(who);
    who->start_busy(1);
    return 1;
  }
}

void greeting(object me)
{
  write(HIC"
	舞風揚說：「是誰這麼大膽，竟然闖入我了練功\
	修行的地方，擾我修行的人真是太可惡了！！」\n\n"NOR); 
  if( !wizardp(me) )
  {
    kill_ob(me);
  }
  set_heart_beat(1);
  return;
}

int accept_fight(object who)
{
  write(HIY"舞風揚冷冷的說：「先打量你是否能活著離開吧！哼哼！！」\n"NOR);
  return 0;
}

int accept_kill(object who)
{
  who = this_player();
  write(HIY"舞風揚騰空躍起，身形懸浮在平空中。\n"NOR);
  command("say 無知的平凡人類呀！休怪我了，納命來吧！");
  command("wield all");
  command("perform force.fight");
  kill_ob(who);
  return 1;
}

void heart_beat()
{
  object me,*enemy;
  int i,j,count,m,mk,kee;
  me = this_object();
  if(!me || !environment()) return ;
  count = random(20);
  mk = me->query("max_kee");
  kee =me->query("kee");
  m = (mk-kee)/16;
  enemy = me->query_enemy();
  i = sizeof(enemy);

  if( me->query("force_factor") < 15 )
  {
    me->set("force_factor",15);
  }

  if( !me->query_temp("weapon") && me->query_temp("ok_wield") )
  {
    command( "wield all" );
    command( "wear all" );
  }

  if( !me->query_temp("ashura_fight") )
  {
    me->delete_temp("is_busy");
    me->delete_busy();
    me->delete_temp("no_power_f");
    me->delete_temp("no_power_e");
    command("perform force.fight");
    me->delete_busy();
  }

  if(count == 17 && me->is_fighting())
  {
    message_vision(HIW"
	舞風揚輕手一揚，"HIM"『"HIB"電光游走–雷電奔騰"HIM"』"HIW"只見無數道閃電由天
	而降，剎時間天色大變，觸及閃電者非死即傷！！\n"NOR,me);
    for( j=0 ; j < i ; j++ )
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"$N被這威力無比的狂雷所電傷，幾乎快撐不住而暈眩！！\n"NOR,enemy[j]);
        enemy[j]->receive_wound("kee",750,me);
        enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
        COMBAT_D->report_status(enemy[j]);
      }
    }
  }

  if(count == 5 && me->is_fighting())
  {
    message_vision(HIW"
	上空突然飄下陣陣落葉，無數的落葉化為片片殺人的"HIM"「"HIG"葉"HIM"」"HIW"若有
	似無，隱隱若現，眨眼之間，無數的落葉急速聚集，瞬間轉化為
	一式"HIM"『"HIG"葉落秋舞–葉殺片片"HIM"』"HIW"，急速的飛奔狂殺！！\n"NOR,me);
    for( j=0 ; j < i ; j++ )
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"為了躲避漫天的葉殺，耗損了$N不少的內力！！\n"NOR,enemy[j]);
        enemy[j]->add("force",-((enemy[j]->query("force")/150))*8);
        enemy[j]->apply_condition("star-stial",enemy[j]->query_condition("star-stial")+5);
        COMBAT_D->report_status(enemy[j]);
      }
    }
    }

  if(count == 7 && me->is_fighting())
  {
    message_vision(HIW"
	舞風揚一陣怒意橫生，將其化為一式"HIM"『"HIR"怒意橫生–烈火無限"HIM"』"HIW"，
	無限的烈火恣意橫生，誓將一切燒盡的烈火訊速的蔓沿著！！\n"NOR,me);
    for( j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"$N被無情的烈火渾身沿燒著，正痛苦的嘶吼著！！\n"NOR,enemy[j]);
        enemy[j]->receive_wound("kee",500,me);
        enemy[j]->apply_condition("hellfire",enemy[j]->query_condition("hellfire")+5);
        COMBAT_D->report_status(enemy[j]);
      }
    }
  }

  if(count == 10 && me->is_fighting())
  {
    message_vision(HIW"
	舞風揚輕柔百轉的身形，游走於你身旁尋找最佳的攻擊時機，就
	在你分神的那一瞬間，使出"HIM"『"HIY"分身百轉–勁隨身吐"HIM"』"HIW"，無數道猛
	烈的氣勁任意的飛奔游竄！！\n"NOR,me);
    for( j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"$N被猛烈的氣勁所傷，痛苦的不能自己而跪地呻吟！！\n"NOR,enemy[j]);
        enemy[j]->receive_wound("kee",500,me);
        enemy[j]->apply_condition("hart",enemy[j]->query_condition("hart")+5);
        COMBAT_D->report_status(enemy[j]);
      }
    }
  }

  if(count == 15 && me->is_fighting())
  {
    message_vision(HIW"
	舞風揚一個妖身幻化，轉化成絕世驚豔的美女子，集嬌柔嫵媚於
	一身，並藉由靈力散發"HIM"『"NOR+MAG"媚豔四射–無限迷惑"HIM"』"HIW"，有如炫目的劍
	光讓人無法逼視！！\n"NOR,me);
    for( j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"$N與舞風揚四目交接之下，顯得春心盪漾全無反擊能力！！\n"NOR,enemy[j]);
        enemy[j]->receive_wound("kee",400,me);
        enemy[j]->apply_condition("flower",enemy[j]->query_condition("flower")+3);
        COMBAT_D->report_status(enemy[j]);
      }
    }
  }

  if(count == 3 && me->is_fighting())
  {
    message_vision(HIW"
	舞風揚身形幻化，無數分身迴盪在四周，急速迴旋的氣流在四周
	激盪不已，產生的無比氣流令人無法呼吸，而瞬時間隨著一聲輕
	喝"HIM"『"HIC"千風起舞–萬風雲揚"HIM"』"HIW"，刀風化冷氣瘋狂的侵襲著一切！！\n"NOR,me);
    for( j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"$N被片片的刀風所刮傷，哀嚎慘叫不已！！\n"NOR,enemy[j]);
        enemy[j]->receive_wound("kee",500,me);
        enemy[j]->apply_condition("cold",enemy[j]->query_condition("cold")+5);
        COMBAT_D->report_status(enemy[j]);
      }
    }
  }

  if( random(10) == 5 )
  {
    if( me->is_fighting() )
    {
      if( query("kee") < query("eff_kee") )
      {
        message_vision(HIW"\n舞風揚的身上旋繞著"HIR"『"HIM"七"HIY"色"HIC"光"HIG"茫"HIB"』"HIW"，光茫過後，舞風揚精神為之振奮！\n"NOR,me);
        me->delete_temp("is_busy");
        me->delete_busy();
        me->delete_temp("no_power_f");
        me->delete_temp("no_power_e");
        me->clear_condition();
      }
      if( random(5) == 2 && me->query("kee") > 0 )
      {
        me->receive_curing("kee",m);
        me->receive_heal("kee",m);
        me->receive_curing("gin",m);
        me->receive_heal("gin",m);
        me->receive_curing("sen",m);
        me->receive_heal("sen",m);
        me->add("force",m*5);
      }
    }
  }

  if( !me->is_fighting() ) 
  {
    if( query("force") < 15000 ) 
      command( "ex 270" );
    if( query("eff_kee") < query("max_kee") )
    {
      command( "10 exert heal" );
      command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") ) {
      me->receive_curing("gin",500);
      me->receive_heal("gin",500);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") ) {
      me->receive_curing("sen",500);
      me->receive_heal("sen",500);
    }
  }

//  set_heart_beat(1);
  ::heart_beat();
}

void do_special()
{
  object me,*enemy;
  int kee,i,j;

  me = this_object();
  enemy = me->query_enemy();
  i = sizeof(enemy);

  if(me->is_fighting())
  {
    message_vision(HIY"
	舞風揚一聲輕喝，一個金黃色光球將舞風揚緊緊的包圍，金黃色
	光球慢慢的向外擴大，一瞬間，黃金光球散發出一陣耀眼光茫，
	同一時間，舞風揚發出他最強的一招絕學"HBRED"『金˙光˙萬˙丈』"NOR+HIY"！\n"NOR,me);
    for( j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j] != me && !wizardp(enemy[j]) )
      {
        message_vision(HIR"黃金光球暴發無限威力，$N被震飛老遠，內息翻滾不定！！\n"NOR,enemy[j]);
        enemy[j]->receive_wound("kee",600,me);
        enemy[j]->apply_condition("power-down",enemy[j]->query_condition("power-down")+5);
        if(enemy[j]->query("class")=="fighter")
        {
          enemy[j]->set_temp("power-down",20);
        }else{
          enemy[j]->set_temp("power-down",10);
        }
        enemy[j]->start_busy(1);
        COMBAT_D->report_status(enemy[j]);
      }
    }
  }
}

void die()
{
  int i,j;
  object *enemy;
  
  object winner = query_temp("last_damage_from");
  string class1 = winner->query("family/family_name");
  string name = winner->query("name");

  if(userp(winner)) log_file("kill_dance", sprintf("%s(%s) 打死舞風揚 on %s\n",name,winner->query("id"), ctime(time()) ));
  enemy = query_enemy();
  i=sizeof(enemy);

  if( class1 == 0 ) class1="無門無派";

  tell_object(users(),HIY"
舞風揚輕聲嘆道：

"HIM"『"HIC" 世 間 繁 華 ～ 如 夢 似 幻

     愛 恨 情 仇 ～ 煙 消 雲 散

       回 首 陌 路 ～ 凌 亂 不 堪

         遙 望 青 峰 ～ 紅 塵 糾 纏"HIM"』"HIY"


沒想到我千年的道行竟然毀在"+HIC+class1+HIY"的"+HIC+name+HIY"手上！！

天意啊！！      可嘆啊！！

        算了吧！！      罷了吧！！\n"NOR);
  if ( kill_jobs(5,winner,this_object(),"area/hole_stone") ) finish_time(winner,"area/hole_stone");
  else start_time(winner,"area/hole_stone"); // 7.21.93 by Firedancer

  if( !present( "ghost heart", winner ) )
  {
    if ( random(3) == 1 && userp(winner) )
    {
      if( winner->query_temp("quests/magic-manor-02") == 4 )
      {
        new("/open/magic-manor/obj/leaf")->move(winner);
        tell_room(environment(),sprintf(HIY"\n一片葉子慢慢飄落，慢慢的落在%s的手上。\n"NOR,winner->name()));
        winner->set_temp("quests/kill-dance",1);
        log_file("open-area/get_heart", sprintf("%s(%s) 得到妖幻之心於 %s\n",name,winner->query("id"), ctime(time()) ));
        new("/autoload/open-area/ghost-heart")->move(winner);
        tell_room(environment(),sprintf(HIY"\n舞風揚臨死前發出陣陣的強光，光茫過後，妖幻之心飛向%s便深深的印絡在心中。\n"NOR,winner->name()));
      }else{
        log_file("open-area/get_heart", sprintf("%s(%s) 得到妖幻之心於 %s\n",name,winner->query("id"), ctime(time()) ));
        new("/autoload/open-area/ghost-heart")->move(winner);
        tell_room(environment(),sprintf(HIY"\n舞風揚臨死前發出陣陣的強光，光茫過後，妖幻之心飛向%s便深深的印絡在心中。\n"NOR,winner->name()));
      }
    }else{
      if( winner->query_temp("quests/magic-manor-02") == 4 )
      {
        new("/open/magic-manor/obj/leaf")->move(winner);
        tell_room(environment(),sprintf(HIY"\n一片葉子慢慢飄落，慢慢的落在%s的手上。\n"NOR,winner->name()));
        winner->set_temp("quests/kill-dance",1);
        destruct( present("ghost heart",this_object()) );
        tell_room(environment(),sprintf(HIY"\n舞風揚因為承受過多的重擊，身上的妖幻之心被擊的粉碎了。\n"NOR));
      }else{
        destruct( present("ghost heart",this_object()) );
        tell_room(environment(),sprintf(HIY"\n舞風揚因為承受過多的重擊，身上的妖幻之心被擊的粉碎了。\n"NOR));
      }
    }
  }else{
    if( winner->query_temp("quests/magic-manor-02") == 4 )
    {
      new("/open/magic-manor/obj/leaf")->move(winner);
      tell_room(environment(),sprintf(HIY"\n一片葉子慢慢飄落，慢慢的落在%s的手上。\n"NOR,winner->name()));
      winner->set_temp("quests/kill-dance",1);
      destruct( present("ghost heart",this_object()) );
      tell_object(winner,HIY"\n妖幻之心再度印入心中，一股力量激發了你的最大經驗和潛能!!\n"NOR);
      winner->add("combat_exp",1000);
      winner->add("potential",200);
    }else{
      if( winner->query("combat_exp") > 30000000 )
      {
        destruct( present("ghost heart",this_object()) );
        tell_object(winner,HIY"\n妖幻之心再度印入心中，你已變的太強，再也無法激發你的經驗和潛能了!!\n"NOR);
      }else{
        destruct( present("ghost heart",this_object()) );
        tell_object(winner,HIY"\n妖幻之心再度印入心中，一股力量激發了你的最大經驗和潛能!!\n"NOR);
        winner->add("combat_exp",1000);
        winner->add("potential",200);
      }
    }
  }

  winner->set_temp("kill_wind",1);
//  if( winner->query("clan/id") ) //目前沒開放幫派 暫時關閉此功能 by blazakira
//    CLAN_D->add_clanset( winner->query("clan/id"), "develop" , 20 );

  :: die();
}
