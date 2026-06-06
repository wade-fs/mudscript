//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/7
//增加auto kill的動作 模式為心跳判斷時 kill_ob(target[j]) 為範圍型kill by blazakira 2011/11/7
//增加被打倒時 反饋當場存在的人物以debug last_damage_from抓不到的問題 by blazakira 2011/11/23

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("姥無艷",({"poison god","poison","god"}));
  set("long",@LONG
精通各種毒術、武功獨樹一格，自我心防甚強，深知紅顏禍水
之害，遂以醜陋面具掩飾美貌、離群索居，但隱藏在堅強的外
表下，卻是極為容易受傷的美人心。
LONG);

  set("gender","女性");
  set("class","poisoner");
  set("nickname",HBBLU+HIG"天外毒仙" + NOR);
  set("title",HIC + "十二天靈狩" + NOR);
  set("family/family_name","冥蠱魔教");
  set("combat_exp",20000000);
  set("attitude","friendly");
  set("attribute","saint");
  set("score",1000000);
  set("bellicosity",20000);
  set("potential",50000);
  set("age",45);

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);

  set("env/fan_auto_shoot","YES");
  set("env/飄陽扇連擊","YES");
  set("env/六絕劍","YES");
  set("env/魔性六斬","YES");
  set("env/邪刀連擊","YES");
  set("env/get_mblade","YES");
  set("env/天驚地動",5);
  set("env/superforce","green");
  set("env/連擊","YES");

  set("force",500000);
  set("max_force",50000);
  set("mana",50000);
  set("max_mana",50000);
  set("atman",50000);
  set("max_atman",50000);
  set("force_factor", 35);

  set("s_kee",5000);
  set("max_s_kee",5000);
  set("sec_kee","god");

  set("max_kee",250000);
  set("max_gin",250000);
  set("max_sen",250000);

//基本技能
  set_skill("sword",150);
  set_skill("move",350);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("force",350);
  set_skill("literate",120);
  set_skill("throwing",150);
  set_skill("unarmed",150);
  set_skill("dagger",150);
  set_skill("magic",100);
  set_skill("blade",150);
  set_skill("stabber",150);
  set_skill("poison",120);

//特殊技能
  set_skill("coldpoison",100);
  set_skill("shasword",150);
  set_skill("sun_fire_sword",150);
  set_skill("rain-throwing",150);
  set_skill("dreamdance",100);
  set_skill("dremagic",100);
  set_skill("dragon-blade",150);
  set_skill("shadow-kill",150);
  set_skill("canon",100);
  set_skill("universe",150);
  set_skill("counter",150);
  set_skill("badstrike",150);
  set_skill("fast-blade",150);
  set_skill("gold-blade",150);
  set_skill("six-fingers",150);
  set_skill("forever-love",150);

//閃躲技能
  set_skill("sha-steps",250);
  set_skill("shade-steps",250);
  set_skill("paull-steps",250);
  set_skill("shift-steps",250);
  set_skill("ghost-steps",250);
  set_skill("linpo-steps",250);
  set_skill("nine-steps",250);

//通用技能
  set_skill("fireforce",300);
  set_skill("fiendforce",300);

//內功心法
  set_skill("blackforce", 300);
  set_skill("dreamforce",300);
  set_skill("superforce", 300);
  set_skill("badforce",300);
  set_skill("poisonforce",300);
  set_skill("sunforce", 300);
  set_skill("sixforce",300);

  map_skill("dodge","nine-steps");
  map_skill("move","paull-steps");
  map_skill("force","poisonforce");
  map_skill("parry","gold-blade");

  map_skill("blade","fast-blade");
  map_skill("sword","sun_fire_sword");
  map_skill("throwing","rain-throwing");
  map_skill("dagger","shadow-kill");
  map_skill("magic","dremagic");
  map_skill("unarmed","universe");
  map_skill("poison","coldpoison");
  map_skill("whip","forever-love");

  set("functions/addbasic/level",100);
  set("functions/addblade/level",100);
  set("functions/badup/level",50);
  set("functions/badroar/level",100);
  set("functions/black/level",150);
  set("functions/blood/level",150);
  set("functions/bluesea/level",150);
  set("functions/busy/level",100);
  set("functions/enforceup/level",100);
  set("functions/evil-blade/level",100);
  set("functions/evil-poison/level",120);
  set("functions/fan-finger/level",120);
  set("functions/fast-dest/level",100);
  set("functions/fight/level",120);
  set("functions/firefinger/level",120);
  set("functions/five/level",120);
  set("functions/gen/level",150);
  set("functions/gold-dest/level",100);
  set("functions/gold-fire/level",100);
  set("functions/goldsun/level",150);
  set("functions/green/level",150);
  set("functions/gwe_jen/level",150);
  set("functions/handwriting/level",100);
  set("functions/healup/level",100);
  set("functions/hurtkee/level",100);
  set("functions/hwa_je/level",150);
  set("functions/ice/level",150);
  set("functions/losehurt/level",100);
  set("functions/manakee/level",150);
  set("functions/mdragon-dest/level",100);
  set("functions/melt-bone/level",120);
  set("functions/mk-blade/level",100);
  set("functions/mobkee/level",150);
  set("functions/nine/level",150);
  set("functions/power-dest/level",100);
  set("functions/powerup/level",100);
  set("functions/purple/level",150);
  set("functions/rainbow-steps/level",100);
  set("functions/sha_kee/level",100);
  set("functions/snake-steps/level",120);
  set("functions/suck/level",120);
  set("functions/swordkee/level",100);
  set("functions/sunswordkee/level",100);
  set("functions/tengin/level",100);
  set("functions/white/level",150);
  set("functions/leaf-blade/level",100);
  set("functions/young/level",100);

  set("/spells/reflection/level",100);
  set("/spells/confuse/level",100);
  set("/spells/fireball/level",100);
  set("/spells/thunder/level",100);
  set("/spells/fdragon/level",100);
  set("/spells/firedance/level",100);
  set("/spells/dreamwings/level",100);
  set("/spells/hellfire/level",100);
  set("/spells/dreamcure/level",100);

  set("quests/sunfire",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("quest/sun_fire_sword",1);
  set("bounds", 40000);
  set("poison",99999);
  set("get_sha_sp", 1);
  set("quest/gold-fire",1);
  set("quest/island",3);
  set("can_use_mobkee",1);
  set("quest/rain",1);
  set("quest/worldpill",1);
  set("quest/gold-fire",1);
  set("mk-blade",1);
  set("m_blade",1);
  set("marks/tengin",1);
  set("marks/evil-poison",1);
  set("quests/badroar",1);
  set("marks/kar",1);
  set("marks/sun-finger",1);
  set("marks/six_sp",3);
  set("mark/love",1);
  set("six_spsp",1);
  set("allow_fdragon",1);
  set("can_use_cloud",1);
  set("mystery",1);

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
  set("weapon/fire-full",1);
  set("weapon/ice-full",1);
  set("weapon/water-full",1);
  set("weapon/ground-full",1);
  set("weapon/wind-full",1);
  set("weapon/thunder-full",1);
  set("weapon/dark-full",1);
  set("weapon/saint-full",1);

  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set("cs",2);
  set_temp("fan-finger",5000);
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
  set_temp("five-ball",6);

  set_temp("magic-manor/goldmagic",1);
  set_temp("magic-manor/woodmagic",1);
  set_temp("magic-manor/watermagic",1);
  set_temp("magic-manor/firemagic",1);
  set_temp("magic-manor/soilmagic",1);

  set_temp("apply/armor",150);
  set_temp("apply/attack",150);
  set_temp("apply/damage",150);
  set_temp("apply/defense",150);

  setup();

  add_money("cash",30);
  carry_object("/autoload/sky/claw");
  carry_object("/autoload/open-area/five-turn");
//  carry_object("/autoload/sky/peace_neck");
  carry_object("/autoload/sky/night-legging")->wear();
  carry_object("/autoload/sky/light_cloak")->wear();;
  carry_object("/autoload/sky/color_ring")->wear();
  carry_object("/obj/poison/rose_poison")->set_amount(999);
  carry_object("/obj/poison/five_poison")->set_amount(999);
  carry_object("/obj/poison/dark_poison")->set_amount(999);
  carry_object("/obj/poison/faint_poison")->set_amount(999);
  carry_object("/obj/poison/scorpion_poison")->set_amount(999);
}

void init()
{
  if( !present("attribute-chain",this_object()) )
  {
    command("change_attr whip");
    command("wield attribute-chain");
  }

  add_action("do_use","use");
  ::init();
}

void greeting(object ob)
{
  object npc=this_object();
//  ob=this_player();

  if(!npc || !ob ) return;
  command("wear all");
  set_heart_beat(1);
  return;
}

int do_use(string str)
{
  object me,mob;
  me = this_player();
  mob = present("shan yun");
  if(present("lotch",me) && str == "lotch" && random(5)!=2)
  {
    if(mob)
    {
      message_vision(HIY + "\n$n受到天地靈界的靈氣影響，竟倒戈向$N出手。\n" + NOR,me,mob);
      mob->set_leader(me);
      mob->kill_ob(me);
    }
  }
}

int accept_kill(object ob)
{
  object me=this_object();
  kill_ob(ob);
  command("cmd god_kee");
  command("perform coldpoison.melt-bone");
  return 1;
}

void heart_beat()
{
  object *enemy,who=this_player(),me=this_object(),eq,*target;
  int i,j,k,l,m,n,mk,kee;

  if(!me || !environment(me)) return ;

  if( me->query("kee") < 0 || me->query("eff_kee") < 0 )
  {
    set_heart_beat(0);
    ::heart_beat();
    return ;
  }

  k = random(10);
  l = random(100);
  eq = me->query("equipped");
  mk = me->query("max_kee");
  kee =me->query("kee");
  m = (mk-kee)/25;

  target = all_inventory( environment(me) );
  i = sizeof(target);
  for (j=0 ; j < i ; j++)
  {
    if(!target[j] || !query_temp("armor") || !query_temp("weapon")) continue;
    else
    {
      if(!target[j]->is_fighting() && target[j]->is_character() && !target[j]->is_corpse() 
          && living(target[j]) && !target[j]->query("mystery") && !target[j]->query_temp("blaz/kon")) {
        me->kill_ob(target[j]);
        if( !query_temp("last_damage_from") )
          set_temp("last_damage_from",target[j]); //npc主動攻擊 要抓玩家攻擊的last_damage_from不容易 所以另設此行 by blazakira
      }
    }
  }

  enemy = me->query_enemy();
  i = sizeof(enemy);

  if( !present("attribute-chain",me) )
  {
    command("change_attr whip");
    command("wield attribute-chain");
  }

  if( me->query("bellicosity") < 15000 )
  {
    me->add("bellicosity",5000);
  }
  if( me->query_condition("no_power") )
  {
    me->clear_condition("no_power");
  }
  if( me->query("force_factor") < 30 )
  {
    me->set("force_factor",30);
  }
  if( me->query_temp("magic-manor/goldmagic") == 1 )
  {
    command("suck soul");
    command("turn five");
    command("wear all");
  }
//自動回氣部份
  if( !me->is_fighting() )
  {
    map_skill("force","fireforce");
    if( query("force") < 50000 )
      command( "ex 500" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") )
    {
      me->receive_curing("gin",750);
      me->receive_heal("gin",750);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
      me->receive_curing("sen",750);
      me->receive_heal("sen",750);
    }

//修羅鬥氣
    if( !me->query_temp("ashura_fight") )
    {
      map_skill("force", "fiendforce");
      me->delete_temp("is_busy");
      me->delete_busy();
      me->delete_temp("no_power_f");
      me->delete_temp("no_power_e");
      command("perform force.fight");
      me->delete_temp("is_busy");
      me->delete_busy();
      map_skill("force", "poisonforce");
    }

    if( !me->query_temp("snake-steps") )
    {
      command("perform dodge.snake-steps");
    }
    if( !me->query_condition("poison") )
    {
      command("cmd suck five");
    }
  }

  if( k == 15 && me->query("kee") > 0 )
  {
    message_vision(HIW + "\n$N周身散發出天靈地界的靈氣，緩和了$N的傷勢。\n" + NOR,me);
    me->receive_curing("kee",m);
    me->receive_heal("kee",m);
    me->receive_curing("gin",m);
    me->receive_heal("gin",m);
    me->receive_curing("sen",m);
    me->receive_heal("sen",m);
    me->add("force",m*5);
  }
//技能攻擊部份
  if( me->is_fighting() )
  {
    if( k == 3 || k == 13 )
      command("perform poison.firefinger");

    if( k == 5 || k == 15 )
      command("perform coldpoison.melt-bone");

    if( k == 1 || k == 11 )
      command("perform poison.five");

//    if( who->query_temp("throw-poison") < 3 )
//    {
//      command("throw five to "+who->query("id"));
//      command("say 看毒！");
//    }
  }

  if( me->query("title") != "十二天靈狩" )
  {
    me->set("title",HIC + "十二天靈狩" + NOR);
  }

//  set_heart_beat(1);
  ::heart_beat();
}

void unconcious()
{
  object winner = query_temp("last_damage_from");

  object me=this_object();

  if( present("five turn",me) )
  {
    destruct(present("five turn",me));
  }
  if( present("water-light-cloak",me))
  {
    destruct(present("water-light-cloak",me) );
  }
  if( present("night-legging",me))
  {
    destruct(present("night-legging",me) );
  }
//  if( present("peace-heart-neck",me));
//  {
//    destruct(present("peace-heart-neck",me) );
//  }
  if( present("attribute-chain",me))
  {
    destruct(present("attribute-chain",me) );
  }
  if( present("color-ring",me))
  {
    destruct(present("color-ring",me) );
  }
  if(!winner)
  {
    :: unconcious();
    return ;
  }

  :: unconcious();
}

string *filter_items = ({
  "light-emblem.c",
  "light_emblem.c",
  "emperor-stone.c",
  "emperor_stone.c",
  "fire-feather.c",
  "fire_feather.c",
  "free-shells.c",
  "free_shells.c",
  "kai-jade.c",
  "kai_jade.c",
  "forest-diamond.c",
  "forest_diamond.c",
  "fox-order.c",
  "fox_order.c",
  "plum-wind.c",
  "plum_wind.c",
  "tender-charm.c",
  "tender_charm.c",
  "surname-yin.c",
  "surname_yin.c",
  "sakura-yin.c",
  "huai-yin.c",
  "black-crystal.c",
  "black_crystal.c",
  "banana-doll.c",
  "banana_doll.c",
});

string get_file_item()
{
  string *files,file,dir;
  dir = "/open/sky/obj10/";
  files = get_dir(dir);
  file = files[random(sizeof(files))];
  if(file[0] == '.') return get_file_item();
  if(member_array(file,filter_items) != -1 )
    return get_file_item();
  return dir+file;
}

void die()
{
  object ob,ob1,me,winner,ppl;
  mixed enemy;
  string name;
//  int a,b,i,j,k,sb,sw;
  int i,k,j;

  me=this_object();
  enemy = all_inventory( environment(me) );
  winner = me->query_temp("last_damage_from");

  if(winner && !winner->query_temp("not_robot") && random(300)==0) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","星");
    ob->move(winner);
    message_vision(CYN + "\n從"+me->query("name")+"的身上掉下了一塊靈魂碎片!!\n" + NOR,winner);
  }
  else if(winner && winner->query_temp("not_robot") && random(300)<150) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","星");
    ob->move(winner);
    message_vision(CYN + "\n從"+me->query("name")+"的身上掉下了一塊靈魂碎片!!\n" + NOR,winner);
  }

//  a=0;
  k=sizeof(enemy);

  i=random(50);
  ppl=find_player("blazakira");
  if( ppl )
    tell_object(ppl,HBGRN+query("name")+"被打倒在 "+environment(me)->short()+"  -- "+file_name(environment(me))+BGRN+" 裡。\n"+NOR);
  for( j=0 ; j<k ; j++ )
  {
    if( ppl && enemy[j] && !query_temp("enemy_damage/"+enemy[j]->query("id")) &&
        enemy[j] != me && enemy[j]->is_character() && !enemy[j]->is_corpse() )
      tell_object(ppl,BGRN+query("name")+"被打倒時，圍觀群眾或攻擊方有 "+enemy[j]->query("name")+"("+enemy[j]->query("id")+")\n"+NOR);
    add_temp("enemy_damage/"+enemy[j]->query("id"),1); //避免重複反饋情報
  }

  if( !me->query("have_item") )
  {
    if( i == 25 )
    {
      ob1=new("/open/sky/obj10/surname-yin.c");
      ob1->move(environment(me));
    }
    if( i == 35 )
    {
      ob1=new("/open/sky/obj10/sakura-yin.c");
      ob1->move(environment(me));
    }
    if( i == 15 )
    {
      ob1=new("/open/sky/obj10/huai-yin.c");
      ob1->move(environment(me));
    } else {
      string file = get_file_item();
      ob1=new(file);
      ob1->move(environment(me));
    }
    me->set("have_item",1);

    name = winner->query("name");
    message_vision(HIM + "\n從"+me->name(1)+"的身上掉下了一個「"+ob1->query("name")+HIM"」!!\n" + NOR,winner,me);
    write_file("/log/sky/god/obj-god10",sprintf("%s(%s)  讓%s掉下了%s於 %s\n",winner->name(1),winner->query("id"),me->query("name"),ob1->query("name"),ctime(time())));
  }

  tell_object(users(),HIW + "\n天靈地界的"HIR+me->query("name")+HIW"被"HIR+winner->query("name")+HIW"打敗，化為一股靈氣消散於大地了。\n" + NOR);

  message_vision(HIY + "\n恭喜"+winner->name()+"打死"+me->query("name")+"得到五百點戰功\!!\n" + NOR,winner);
  write_file("/log/sky/war/obj-god10",sprintf("%s(%s)  殺死%s得到五百點戰功\於 %s\n",winner->name(1),winner->query("id"),me->query("name"),ctime(time())));
  winner->add("war_score",500);

  :: die();
}
