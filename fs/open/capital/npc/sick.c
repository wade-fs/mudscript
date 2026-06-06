//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/7

#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;

string magic1();
string magic2();
string magic3();
string magic4();
string magic5();

void create()
{
  set("title",HIY"『魔界金典』"+HIW+"傳人"NOR);
  set_name("黃帝病",({"Empire sick","sick"}));
  set("long","
身負三百年前天下無敵的超級武學──魔界金典，
具有操縱天地間魔能的恐怖實力。\n");
 
  set("class","poisoner");
  set("poison",99999999);
  set("attitude", "heroism");
  set("class","taoist");
  set("family/family_name","冥蠱魔教");
  set("force_factor",80);
  set("no_get",1);
  set("max_kee",200000);
  set("eff_kee",200000);
  set("kee",200000);
  set("max_gin",90000);
  set("eff_gin",90000);
  set("max_sen",90000);
  set("eff_sen",90000);
  set("gin",90000);
  set("sen",90000);
  set("force",999999);
  set("max_force",99999);
  set("max_mana",90000);
  set("mana",200000);
  set("fire_strike",1);
  set("super_fire",1);
  set("allow_icestorm",1);
  set("combat_exp",12000000);
  set("bellicosity",99999);
  set_temp("kang-power",1);
  set("str",35);
  set("cor",35);
  set("cps",50);
  set("int",30);
  set("con",35);
  set("per",20);
  set("spi",20);
  set("kar",10);
  set_skill("spells",120);
  set_skill("magic",120);
  set_skill("forever-love", 100);
  set_skill("gmagic",100);
  set_skill("poisonforce", 100);
  set_skill("gforce", 100);
  set_skill("gold-magic", 100);
  set_skill("necromancy", 100);
  set_skill("literate",120);
  set_skill("nine-steps",120);
  set_skill("coldpoison",100);
  set_skill("poison",120);
  set_skill("whip",180);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",400);
  map_skill("poison","coldpoison");
  map_skill("parry","gwhip");
  map_skill("whip","forever-love");
  map_skill("force", "gforce");
  map_skill("dodge", "nine-steps");
  map_skill("magic","gold-magic");
  map_skill("spells","necromancy");
  set("spells/manabody/level",100);
  set("spells/hardshell/level",100);
  set("spells/icestorm/level",100);
  set("functions/snake-steps/level",100);
  set("functions/melt-bone/level",100);
  set("functions/five/level",100);
  set("functions/firefinger/level",100);
  set("functions/suck/level",100);
  set("functions/evil-poison/level",100);
  set("marks/evil-poison",1);
  set("chat_chance_combat",99);
  set("chat_msg_combat",({
    (: magic1 :),
    (: magic2 :),
    (: magic3 :),
    (: magic4 :),
    (: magic5 :),
  }) );

  setup();
  carry_object("/autoload/open-area/silver_dragon_whip")->wield();
  carry_object("/autoload/open-area/super_hands")->wear();
}

void init()
{
  add_action("do_use","use");
  ::init();
}

int do_use(string arg)
{
  object ppl = this_player();
  if(arg == "lotch")
  {
    message_vision(HIR"\n$N冷冷的說道：「什麼軒轅劍俠刀神的，在我手下全都不堪一擊。」\n"NOR,this_object());
    ppl->unconcious();
    return 1;
  }
}

int accept_fight(object ob)
{
  int exp1,exp2;
  object me = this_object();
  exp1=me->query("combat_exp");
  exp2=ob->query("combat_exp");
  if( present("xstrike-hands",ob) ) {
    exp2=exp2+exp2/2;
    if(exp2>exp1)
      me->set("combat_exp",exp2+random(16888));
  }
  else {
    if(exp2>exp1)
      me->set("combat_exp",exp2+random(16888));
  }
  if( !query_temp("last_damage_from") )
    set_temp("last_damage_from",ob); //實在搞不懂玩家怎攻擊才造成last_damage_from不存在 大部分有想到的地方都補上這參數了還會出錯 只好補這參數了 by blazakira
  return 1;
}

int accept_kill(object ob)
{
  int exp1,exp2;
  object me = this_object();
  exp1=me->query("combat_exp");
  exp2=ob->query("combat_exp");
  if( present("xstrike-hands",ob) ) {
    exp2=exp2+exp2/2;
    if(exp2>exp1)
      me->set("combat_exp",exp2+random(16888));
  }
  else {
    if(exp2>exp1)
      me->set("combat_exp",exp2+random(16888));
  }
  if( !query_temp("last_damage_from") )
    set_temp("last_damage_from",ob);
  return 1;
}

void greeting()
{
  int exp1,exp2;
  object me=this_object();
  object ppl = this_player();
  command("fusion");
  command("wear hands");
  if(ppl->query_temp("kill_hero"))
  {
    exp1=me->query("combat_exp");
    exp2=ppl->query("combat_exp");
    if(present( "xstrike-hands",ppl)) {
      exp2=exp2+exp2/2;
      if(exp2>exp1)
      me->set("combat_exp",exp2+random(16888));
    }
    else {
      if(exp2>exp1)
      me->set("combat_exp",exp2+random(16888));
    }
    kill_ob(ppl);
    me->set("family/family_name","天道派");
    me->set("class","taoist");
    me->map_skill("magic","gmagic");
    me->map_skill("force","gforce");
    command("conjure icestorm");
    me->map_skill("force","poisonforce");
    me->map_skill("magic","gold-magic");
    me->set("class","poisoner");
    me->set("family/family_name","冥蠱魔教");
  }
  if( !query_temp("last_damage_from") )
    set_temp("last_damage_from",ppl);
}

void heart_beat()
{
  object me;
  int chance;
  chance=random(5);
  me=this_object();
  if(!me || !environment()) return ;

  if(me->is_fighting() || me->is_killing())
  {
    if(!me->query_temp("unconcious"))
    {
      if(chance == 2 && !me->is_busy())
      {
        if(random(2)==1)
        {
          command("dream");
          command("perform coldpoison.melt-bone");
        } else {
          this_object()->set("family/family_name","天道派");
          command("star");
          this_object()->set("family/family_name","冥蠱魔教");
        }
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
//  object *enemy;
  int i,j;
  object ob,winner = query_temp("last_damage_from");
  object me;
  string name = winner->query("name");
  string clan = winner->query("clan/name");
  me=this_object();
//  enemy=me->query_enemy();
  set("combat_exp",12000000);
  if(clan==0) clan="獨闖江湖";
//  i=sizeof(enemy);

  if( winner->query("clan/id") && userp(winner) )
    CLAN_D->add_clanset( winner->query("clan/id"), "develop" ,  5 );
  tell_object(users(),HIY"\n\n黃帝病悲嘆道："HIW"
        善哉!!善哉!!中原覆滅在即，貧僧身負曠世絕學，意欲引渡天下蒼生，
        孰料今日竟敗於未曾修習∮"HIC+BBLU"英雄真經"NOR""HIW"∮的"HIG""+clan+""HIR""+winner->name()+""HIW"手下，
        貧僧死不瞑目啊!!\n\n"NOR);

  if(winner && !winner->query_temp("not_robot") && random(400)==0) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","井");
    ob->move(winner);
    message_vision(MAG"\n從黃帝病的身上掉下了一塊靈魂碎片!!\n"NOR,winner);
  }
  else if(winner && winner->query_temp("not_robot") && random(400)<133) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","井");
    ob->move(winner);
    message_vision(MAG"\n從黃帝病的身上掉下了一塊靈魂碎片!!\n"NOR,winner);
  }

  message_vision(HIY"\n"+winner->name()+"打敗黃帝病得到一百三十點戰功\!!\n"NOR,winner);
  write_file("/log/get_warp",sprintf("%s(%s) 打敗黃帝病得到一百三十點戰功\於 %s\n",
    winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",130);
  winner->add_temp("kill_hero",1);

  :: die();
}

string magic1()
{
  command("conjure magic-crazy");
  return "\n";
}

string magic2()
{
  command("conjure magic-wind");
  return "\n";
}

string magic3()
{
  command("conjure magic-thunder");
  return "\n";
}

string magic4()
{
  command("conjure magic-rain");
  return "\n";
}

string magic5()
{
  command("conjure magic-blood");
  return "\n";
}
