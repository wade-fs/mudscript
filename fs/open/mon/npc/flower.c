//執行時段錯誤: *F_DAMAGE: 恢復值為負值。 所以補正之 且補上receive_wound的攻擊方參數 by blazakira 2011/6/25

#include <ansi.h>
inherit NPC;
void do_call();

void create()
{
  set("long","
處在長白山的花海中，靜靜的在山中千年，外表極其嬌美可人，帶著
一顆善良的心，和千年樹妖的同修之誼非常深厚。所以在平時修行的
空餘，她會獨自下山，去接觸長白山外的世界，所以對於人間的一切
事物，有些微的了解，會被人世的情所影響，所以道行一直追不上樹
妖。一次一位誤闖巨木的人，若非花精求情，也許\他們的傳說就不會
流傳在人間。
");
  set("gender","女性");
  set("class","fighter");
  set("nickname",HIM + "雲霧縹緲中" + HIW + "–" + HIM + "花香不知處" + NOR);
  set("title",HIY + "千年花精" + NOR);
  set_name("淡情悠",({"tzan yuo","yuo"}));
  set("combat_exp",16000000);
  set("attitude","god");
  set("score",10000000);
  set("bellicosity",10000);
  set("age",1000);
  set("max_force",15000);
  set("force",150000);
  set("max_kee",160000);
  set("kee",160000);
  set("max_mana",50000);
  set("mana",50000);
  set("max_atman",50000);
  set("atman",50000);
  set("max_gin",160000);
  set("gin",160000);
  set("max_sen",160000);
  set("sen",160000);

  set("s_kee",5000);
  set("max_s_kee",5000);
  set("sec_kee","god");

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("per", 99);
  set("int", 35);
  set("force_factor",15);
  set_skill("dodge",350);
  set_skill("force",300);
  set_skill("move",200);
  set_skill("parry",350);
  set_skill("mogi-steps",300);
  set_skill("dance-wind",150);
  set_skill("unarmed",300);
  set_skill("literate",200);
  set_skill("fiendforce",250);
  set_temp("armor_vs_force",5000);
  map_skill("force","fiendforce");
  map_skill("dodge","mogi-steps");
  map_skill("move","mogi-steps");
  map_skill("parry","dance-wind");
  map_skill("unarmed","dance-wind");

  set("functions/fight/level",120);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);

  set("clan_kill",1);
  set("no_mount",1);
  set("no_plan_follow",1);
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
  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense", 250);
  set_temp("absorb",3);
  set("chat_chance_combat",50);
  set("chat_msg_combat",({
    (: do_call :)
  }));

  setup();
  carry_object("/open/mon/obj/flower-claw");
  carry_object("/open/mon/obj/thousand-nectar")->set_amount(1);
  carry_object("/autoload/open-area/ghost-heart")->wear();
  add_money("cash",10);
}

void init()
{
  ::init();
  this_object()->set_temp("ok_wield",1);
  add_action("block_cmd", "" );
  add_action("do_cmd","cmd");
}

int block_cmd( string arg )
{
  if( (string)query_verb() == "do" ) 
  {
    write( HIY + "淡情悠說：「在我們千年的道行面前，你這一點技倆又算什麼....」\n" + NOR );
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
	write(HIY + "淡情悠說：「在我千年的道行面前，你這一點技倆又算什麼....」\n" + NOR);
	wind->kill_ob(who);
	who->start_busy(1);
	return 1;
  }
  if(str=="askgod wind" || str=="askgod dance wind")
  {
	write(HIY + "淡情悠說：「在我千年的道行面前，你這一點技倆又算什麼....」\n" + NOR);
	wind->kill_ob(who);
	who->start_busy(1);
	return 1;
  }
  if(str=="bak wind" || str=="bak dance wind")
  {
	write(HIY + "淡情悠說：「在我千年的道行面前，你這一點技倆又算什麼....」\n" + NOR);
	wind->kill_ob(who);
	who->start_busy(1);
    return 1;
  }
}

void greeting(object me)
{
  write(HIC + "淡情悠說：「你是誰？怎知來到此地？」\n" + NOR); 
}

int accept_fight(object who)
{
  write(HIY + "淡情悠說：「不、不、不，我不喜歡打打殺殺的！\n" + NOR);
  return 0;
}

int accept_kill(object who)
{
  who = this_player();
  write(HIY + "淡情悠身旁飄起無數的花雨，落滿了整個空間!!\n" + NOR);
  command("say 你們人類真是太可惡了！");
  command("cmd god_kee");
  kill_ob(who);
  return 1;
}

void heart_beat()
{
  object *enemy,me,who;
  int i,j,m,mk,kee;

  me=this_object();
  who=this_player();
  if(!me || !environment(me)) return ;
  mk = me->query("max_kee");
  kee =me->query("kee");
  m = (mk-kee)/16;
  if( m < 0 ) m = 0;
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

  if( me->is_fighting() && random(100) > random(70) )
  {
    if( environment(me) == environment(enemy[j]) )
    {
      for(j=0; j<i ;j++)
      {
	    message_vision(HIY + "$N" + HIY + "張手一揚，散出無數花粉朝$n" + HIY + "灑了過去!!\n"+NOR,me,enemy[j]);
        if( !enemy[j] ) continue;
        {
          if( random(10) > 5 )
          {
            message_vision(HIY + "$n" + HIY + "避無可避被帶著妖精靈力的花粉灑中了!!\n"+NOR,me,enemy[j]);
            enemy[j]->receive_wound("kee", random(enemy[j]->query("max_kee")/30)+300,me);
            enemy[j]->receive_wound("sen", random(enemy[j]->query("max_sen")/30)+100,me);
            enemy[j]->receive_wound("gin", random(enemy[j]->query("max_gin")/30)+100,me);
            COMBAT_D->report_status(enemy[j], 1);
          }else{
            message_vision(YEL + "危急一刻中，$N" + YEL + "身子一閃，避開了花粉的攻擊!!\n" + NOR,enemy[j]);
          }
        }
      }
    }
  }

  if( random(10) == 5 )
  {
    if( is_fighting() )
    {
      if( query("kee") < query("eff_kee") )
      {
	    message_vision(HIY + "\n$N的身上飄出一股奇異的幽香，隱隱繚繞在$N的周身!!\n" + NOR,me);
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

  if( !is_fighting() ) 
  {
    if( query("force") < 50000 ) 
	  command( "ex 270" );
    if( query("eff_kee") < query("max_kee") )
    {
	  command( "10 exert heal" );
	  command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") )
    {
	  me->receive_curing("gin",500);
	  me->receive_heal("gin",500);
    }
    if( query("kee") < query("eff_kee") )
	  command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
	  me->receive_curing("sen",500);
	  me->receive_heal("sen",500);
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void do_call()
{
  object *enemy,me,who,mob;
  int i,j,pd,nd;
  me=this_object();
  who=this_player();
  pd=who->query_skill("dodge");
  nd=me->query_skill("dodge");
  enemy = me->query_enemy();
  i = sizeof(enemy);

  if( me->is_fighting() )
  {
    if( (random(nd)+10 > random(pd)+1 ) && random(2) == 1 )
    {
      if(environment(me) == environment(enemy[j]))
      {
        message_vision(HIY + "
                      .-~~-. --." + HIY + "
                     (          )" + HIR + "
               . ~~ -.\\ " + HIY + "～" + HIC + "悠" + HIY + "～" + HIR + " /.- ~~ ." + HIR + "
               >       `.    .'       <" + HIR + "
              (   " + HIY + "～" + HIC + "花  " + MAG + ".-  -.  " + HIC + "落" + HIY + "～" + HIR + "   )" + HIM + "
               `- -.-~  " + MAG + "`-  -'" + HIM + "  ~-.- -'" + HIM + "
                 (   " + HIY + "～" + HIC + "情" + HIM + "  :  " + HIC + "淡" + HIY + "～" + HIM + "   )" + HIG + "         _ _ .-:" + HIM + "
                  ~--.     :     .--~" + HIG + "      .-~  .-~  }" + HIM + "
                      ~-.-^-.-~ " + HIG + "\\_      .~  .-~   .~" + HIG + "
                               \\ \\'     \\ '_ _ -~" + HIG + "
                                `.`.    //" + HIB + "
                       . - ~ ~-.__`.`-.//" + HIB + "
                   .-~   . - ~  }~ ~ ~-.~-." + HIB + "
                 .' .-~      .-~       :/~-.~-./:" + HIW + "
                /_~_ _ . - ~                 ~-.~-._" + HIW + "
                                                 ~-.<
        \n" + NOR,me);
        for( j=0;j < i;j++ )
        {
          if( !enemy[j] ) continue;
          {
            message_vision(HIY + "漫天的花辦夾帶著風刃之威，$N" + HIY + "被片片的花辦割的遍體鱗傷!!\n" + NOR,enemy[j]);
            enemy[j]->receive_wound("kee", random(500)+500,me);
            enemy[j]->receive_wound("sen", random(200)+100,me);
            enemy[j]->receive_wound("gin", random(200)+100,me);
            enemy[j]->apply_condition("flower",enemy[j]->query_condition("flower")+5);
            enemy[j]->start_busy(1);
            COMBAT_D->report_status(enemy[j], 1);
          }
        }
      }
    }else{
      if( random(10) > 2 )
      {
	    message_vision(HIY + "$N說道：「我的好朋友們，快來幫幫我呀！！\n" + NOR,me);
        switch(random(5))
        {
          case 0:
            mob=new("/open/mon/npc/sparrow");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/bee");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/butterfly");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/cicada");
            mob->move(environment(me));
            mob->invocation(me);
            break;
          case 1:
            mob=new("/open/mon/npc/bee");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/butterfly");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/cicada");
            mob->move(environment(me));
            mob->invocation(me);
            break;
          case 2:
            mob=new("/open/mon/npc/sparrow");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/butterfly");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/cicada");
            mob->move(environment(me));
            mob->invocation(me);
            break;
          case 3:
            mob=new("/open/mon/npc/bee");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/cicada");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/sparrow");
            mob->move(environment(me));
            mob->invocation(me);
            break;
	      case 4:
            mob=new("/open/mon/npc/bee");
            mob->move(environment(me));
            mob->invocation(me);
            mob=new("/open/mon/npc/butterfly");
            mob->move(environment(me));
            mob->invocation(me);
            break;
        }
      }
    }
  }
}

void die()
{
  object *enemy;
  int i,j;
  object winner = query_temp("last_damage_from");
  string class1 = winner->query("family/family_name");
  string name = winner->query("name");
//  log_file("log/open-area/kill_yuo", sprintf("%s(%s) 打死淡情悠 on %s\n",name,winner->query("id"), ctime(time()) ));
  enemy = query_enemy();
  i=sizeof(enemy);
  tell_object(users(),HIC + "\n\t啊 ～～\n\n\t淡情悠說道：「舞風揚姐姐，咱們來世再做姐妹吧!!」\n\n\t" + HIG + "只聞淡情悠發出一聲慘叫後，被" + HIM+name+HIG + "打回原花精原形了!!\n\n" + NOR);

  if( winner->query("combat_exp") > 30000000 )
  {
	destruct( present("ghost heart",this_object()) );
	tell_object(winner,HIY + "\n你已變的太強，吸取淡情悠的精元也得不到什麼助益了!!\n" + NOR);
  }else{
	destruct( present("ghost heart",this_object()) );
	tell_object(winner,HIY + "\n你吸取到了殘存的淡情悠精元，精驗值和潛能迅速提升不少!!\n" + NOR);
	winner->add("combat_exp",1000);
	winner->add("potential",200);
  }
  :: die();
}
