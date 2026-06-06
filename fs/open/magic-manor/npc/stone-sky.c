//from mechoufen by frequency
//將receive_xxx補上攻擊方參數 by blazakira 2011/10/12

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);
void skyfire(object me, object victim, object weapon, int damage);

mapping *action = ({
  (["action"     : HIW"太玄經："NOR"『"HIC"十步殺一人，"HIB"千裡不留行"NOR"』，$N以驚世身法帶動刁鑽劍招，從詭異角度刺向$n。\n",
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 200,
    "damage"     : 200,
    "weapon"     : "劍氣",
    "damage_type": "割傷",
     ]),
  (["action"     : HIW"太玄經："NOR"『"HIW"銀鞍照白馬，"HIC"瘋沓如流星"NOR"』$N劍指發出一道劍芒劃破長空，直刺$n。",
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 180,
    "damage"     : 180,
    "weapon"     : "劍芒",
    "damage_type": "割傷",
     ]),
  (["action"     : HIW"太玄經："NOR"『"HIY"救趙揮金錘，"HIR"邯鄲先震驚"NOR"』。$N奮不顧身直刺$n，逼得$n撤招回防。"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 200,
    "damage"     : 200,
    "weapon"     : "劍指",
    "damage_type": "刺傷",
  ]),
  (["action"     : HIW"太玄經："NOR"『"HIG"閑過信陵飲，脫劍膝前橫"NOR"』，$N氣灌劍指，鋒銳劍氣在$n身旁縱橫交錯。"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 250,
    "damage"     : 250,
    "weapon"     : "劍氣",
    "damage_type": "割傷",
  ]),
  (["action"     : HIW"太玄經："NOR"『"HIM"三杯吐然諾，"YEL"五岳倒為輕"NOR"』，$N雄渾內勁爆發，驚天一掌當胸重擊$n。"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 300,
    "damage"     : 300,
    "weapon"     : "重掌",
    "damage_type": "震傷",
  ]),                  
  (["action"     : HIW"太玄經："NOR"『"HIG"誰能書閣下，白首太玄經"NOR"』，$N仰天一聲清嘯，頓時山河震動，飛獸走避。"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 350,
    "damage"     : 350,
    "weapon"     : "嘯生",
    "damage_type": "耳鳴",
  ]),    
  (["action"     : HIW"太玄經："NOR"『"HIC"縱死俠骨香，不慚世上英"NOR"』$N步法變換，頃刻間發出八八六十四掌擊向$n"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 400,
    "damage"     : 400,
    "weapon"     : "重掌",
    "damage_type": "震傷",
  ]),    
  (["action"     : HIW"太玄經："NOR"『"HIR"千秋二壯士，亙赫大梁城"NOR"』$N招式大開大闔，以無比霸氣強壓向$n。"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 450,
    "damage"     : 450,
    "weapon"     : "巨拳",
    "post_action": (: skyfire :),
    "damage_type": "震傷",
  ]),
  (["action"     : HIW"太玄經："NOR"『"HIR"趙客縵胡纓，"HIW"吳鉤霜雪明"NOR"』，$N刀意、劍招、掌法、輕功\、內功\融為一體，源源不絕。"NOR,
    "dodge"      : -100,
    "parry"      : -100,
    "force"      : 500,
    "damage"     : 500,
    "weapon"     : "太玄真勁",
    "post_action": (: berserk :),
    "damage_type": "抓傷",
  ])
});

void create()
{
  set("title",YEL"長樂幫"HIR"總舵主"NOR);
  set_name("石破天", ({"stone-sky","stone","sky"}));
  set("class","fighter");
  set("age",27);
  set("long","本性純樸卻莫名其妙當上長樂幫主的謎般善良男子。\n");
  set("gender","男性");
  set("family/family_name","俠客島");
  set("str",55);
  set("con",40);
  set("cps",30);
  set("cor",40);
  set("kar",65);
  set("spi",40);
  set("int",1);
  set("per",45);
  set("max_kee", 40000);
//  set("kee", 50000);
  set("max_gin", 40000);
//  set("gin", 40000);
  set("max_sen", 40000);
//  set("sen", 40000);
  set("force", 90000);
  set("max_force", 40000);
  set("bellicosity", 9000);
  set("force_factor",75);
  set("s_kee",9999);
  set("max_s_kee",9999);
  set("sec_kee","tiger");
  set_skill("dodge",130);
  set_skill("force",300);
  set_skill("parry",130);
  set_skill("iceforce",200);
  set_skill("firestrike",150);
  set_skill("nine-steps",150);
  set_skill("unarmed",120);
  set_temp("apply/damage", 130);
  set_temp("apply/armor", 50);
  set_temp("apply/defense",50);
  set_temp("apply/dodge", 50);
  set_temp("apply/parry", 50);
  set_temp("mount",1);
  set_temp("no_plan_follow",1);
  set("no_speed",1);
  set("no_exp",1);
  map_skill("parry","firestrike");
  map_skill("force","iceforce");
  map_skill("dodge","nine-steps");
  set("chat_chance_combat",30);
  set("chat_msg_combat",({
    "石破天說：你知道我爸爸媽媽在那邊嗎？還有阿黃，我好想念他們哪...\n",
    "石破天說：貝海石大哥說我是幫主，我怎一直想不起來是怎當上的？\n",
    "石破天說：阿琇跑哪去了，我想見見她。\n",
  }));
  set_temp("apply/armor",100);
  set_temp("apply/damage",100);
//  set("ann_die",1);
  setup();
  carry_object("/autoload/mblade/mring");
  carry_object("/autoload/sky/peace_neck");
  carry_object("/autoload/open-area/shawk");
  carry_object("/autoload/open-area/turtle-shield");
  carry_object("/autoload/north-polar/bear-fur");
  carry_object("open/center/obj/clan-master-head");
  add_money("cash",2);
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  reset_action();
}

mapping query_action()
{
  if(random(4)==1) return action[8];
  else return action[random(sizeof(action))];
}

void init()
{
  add_action("do_team","team");
  add_action("do_steal","steal");
  add_action("do_use","use");
  add_action("do_cmd","cmd");
  ::init();
}

void greeting(object me)
{
  object ob = this_object();
  if(!ob->query_temp("equipment"))
  {
    command("wear mdragon-ring");
    command("wear shield");
    command("wear silver-hawk");
    command("wear fur");
    command("wear neck");
    command("wear neck");
    ob->set_temp("equipment",1);
  }
}

void heart_beat()
{
  object env,mob,*enemy,target;
  int i,kee;
  mapping exit;
  string *exit_name;

  mob = this_object();
  env = environment(mob);
  if(!mob || !env ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    mob->die();
    return ;
  }
  else if( mob->query_temp("unconcious") == 1 ) return ;
  enemy=mob->query_enemy();
  for(i=0;i<sizeof(enemy);i++)
  {
    if(enemy[i] && enemy[i]->query("combat_exp") > mob->query("combat_exp")/3)
      mob->set("combat_exp",3*(enemy[i]->query("combat_exp")) - 1000);
    else if(!enemy[i]) continue;
  }

  if( random(100) < 30 && mob->is_fighting())
  {
    i=sizeof(enemy);
    target=offensive_target(mob);
    if(target)
    {
      kee = target->query("max_kee") * 0.4;
      if( env == environment(target) )
      {
        message_vision(HIC"\n$N手腕輕顫，"HIY"雪山劍法"HIC"之"HIR"『"HIW"雪花六出"HIR"』"HIC"一出，$n只見自己胸口已整整齊齊的被刺了六點，鮮血從衣衫中滲將出來!!\n"NOR,mob,target);
        target->receive_wound("kee",300,mob);
        target->apply_condition("bleeding",random(5));
        COMBAT_D->report_status(target,1);
      }
    }
  }

  if(((mob->query("kee")<mob->query("max_kee")*0.5)||
      (mob->query("gin")<mob->query("max_gin")*0.5)||
      (mob->query("sen")<mob->query("max_sen")*0.5))&& (random(100) < 10) )
  {
    message_vision(HIW"\n$N內息洶湧澎湃，太玄神功\內勁瘋狂激盪，頃刻間沖破了七八個窒滯之處，\n如大川般急速流動起來，自丹田而至頭頂，自頭頂又至丹田，越流越快。\n$N只覺四肢百骸之中都是無可發洩的力氣。\n"NOR,mob);
    mob->receive_curing("kee",2000);
    mob->receive_heal("kee",2000);
    mob->receive_curing("sen",2000);
    mob->receive_heal("sen",2000);
    mob->receive_curing("gin",2000);
    mob->receive_heal("gin",2000);
    COMBAT_D->report_status(mob);
  }

  if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 20) && mob->is_fighting() )
  {
    exit = env->query("exits");
    exit_name = keys(exit);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
  }
  set_heart_beat(1);
  ::heart_beat();
}

void skyfire(object me, object victim, object weapon, int damage)
{
  message_vision(HIC"\n$N融合體內"HIR"炎炎功\"HIC"及"HIW"太玄真氣"HIC"，打出密招"HIY"『"HIG"碧針清掌"HIY"』"HIC"。\n"NOR, me, victim);
  if( !me->query_temp("berserk") && 70>random(100) )
  {
    message_vision(HIM"$n胸前被重掌印上，冰炎兩道氣勁湧入丹田，$n直覺不妙。\n"NOR, me, victim);
    victim->receive_wound("kee",500,me);
    victim->apply_condition("skyfire",random(7));
    victim->start_busy(random(3));
    COMBAT_D->report_status(victim,1);
  } else message_vision(HIB"$n以自身護體罡\氣勉強抵擋了這股氣勁。\n"NOR, me, victim);
}

void berserk(object me, object victim, object weapon, int damage)
{
  int i;
  mapping do_action;
  string actionn;
  object wp;
  if( !me->query_temp("berserk") && 70>random(100) )
  {
    message_vision(HIR"\n『"HIW"吳鉤霜雪明"HIR"』"HIY"尚未使完，$N心念陡轉，再使"HIR"『"HIC"十步殺一人"HIR"』"HIY"的劍法，無窮殺招跌不停蹄遞出。\n\n"NOR,me);
    for(i=0;i<8;i++)
    {
      do_action = action[i];
      actionn = "\n";
      actionn += do_action["action"];
      if( wp=me->query_temp("weapon") )
        actionn = replace_string(actionn, "$w", wp->name());
      message_vision(actionn, me, victim);
      if(random(victim->query("functions/young/level"))<70 )
      {
        message_vision(HIR"\n$n粹不及防之下，狠狠中招，頓時氣血翻湧。\n"NOR,me,victim);
        victim->receive_wound("kee",victim->query("max_kee")/15,me);
        COMBAT_D->report_status(victim,1);
      } else {
        message_vision(HIG"\n$n驚險地閃過這浪猛攻，嚇得汗流浹背。\n"NOR,me,victim);
        victim->receive_damage("gin",victim->query("max_kee")/50,me);
        victim->receive_damage("gin",victim->query("max_sen")/50,me);
        COMBAT_D->report_status(victim);
      }
    }
  }
}

void die()
{
  object ob;
  ob = this_object();
  destruct(present("mdragon-ring",ob));
  destruct(present("silver-hawk",ob));
  destruct(present("peace-heart-neck",ob));
  destruct(present("bear-fur",ob));
  destruct(present("fire-turtle shield",ob));
  ::die();
}

int accept_fight(object me)
{
  object room,ob;
  ob = this_object();
  ob->command("say 貝先生說我貴為幫主不能隨便跟人打架，送你回家好了。");
  this_player()->move("/open/wiz/courthouse");
  return 1;
}

int accept_kill(object me)
{
  object room,ob;
  ob = this_object();
  ob->delete("no_exp");
  ob->set("s_kee",9999);
  command("exert roar");
  command("cmd usekee "+this_player()->query("id"));
  command("say 小心了！！");
  return 1;
}

int do_team(object me)
{
  object room,ob;
  ob = this_object();
  command("say 貝先生說：打架要一對一單挑才是好漢。所以你回去反省反省吧。");
  this_player()->unconcious();
  this_player()->move("/open/wiz/courthouse");
  return 1;
}

int do_steal(object me)
{
  object room,ob;
  ob = this_object();
  command("say 貝先生說：打架要照規矩來，別搞些有的沒有的花樣。回去算數學吧。");
  this_player()->unconcious();
  this_player()->move("/open/wiz/courthouse");
  return 1;
}

int do_use(object me,string str)
{
  object room,ob;
  ob = this_object();
  if(str == "lotch")
  {
    command("say 貝先生說：打架要一對一單挑才是好漢，這樣是算兩個人吧。回去練習數學吧。");
    this_player()->unconcious();
    this_player()->move("/open/wiz/courthouse");
  }
  return 1;
}

int do_cmd(object me,string str)
{
  object room,ob;
  ob = this_object();
  if(str == "bak")
  {
    command("say 貝先生說：打架要照規矩來，別搞些有的沒有的花樣。回去算數學吧。");
    this_player()->add("sen",-1);
    this_player()->unconcious();
    this_player()->move("/open/wiz/courthouse");
  }
  return 1;
}
