// 新增南蠻war 凌雪飛
//將receive_xxx()補上攻擊方參數 與補上紀錄戰功時 npc的名字 by blazakira 2011/10/19

#include <ansi.h>
inherit NPC;

string magic1();
string magic2();
string magic3();

void create()
{
  set_name("凌雪飛",({"fly dancer","fly","dancer"}) );
  set("long","她是月牙兒的師姐，擅長媚術，據說她已經領悟出夜夢天舞的終極殺\n"+
    "招，當年因為心術不正而被逐出師門，但是她的修為似乎比月牙兒更\n高，以舞媚之術稱霸南蠻數年無人能敵。\n");
  set("gender","女性");
  set("class","dancer");
  set("nickname",HIM + "舞" + HIW + "之" + HIG + "傳人" + NOR);
  set("combat_exp",7000000);
  set("attitude","heroism");
  set("age",26);
  set("str", 99);
  set("cor", 99);
  set("int", 99);
  set("spi", 99);
  set("cps", 99);
  set("per", 99);
  set("con", 99);
  set("kar", 99);
  set("kee",150000);
  set("gin",40000);
  set("sen",40000);
  set("atman",40000);
  set("mana",40000);
  set("force",150000);
  set("max_kee",150000);
  set("max_gin",40000);
  set("max_sen",40000);
  set("max_mana",40000);
  set("max_atman",70000);
  set("max_force",200000);
  set_skill("parry",120);
  set_skill("unarmed",160);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("magic",160);
  set_skill("spells",160);
  set_skill("force",250);
  set_skill("paull-steps",130);
  set_skill("dremagic",100);
  set_skill("dreamdance",100);
  set_skill("necromancy",100);
  set_skill("dreamforce",200);
  map_skill("unarmed","dreamdance");
  map_skill("parry","dreamdance");
  map_skill("dodge","paull-steps");
  map_skill("move","paull-steps");
  map_skill("force","dreamforce");
  map_skill("spells","necromancy");
  map_skill("magic","dremagic");
  set_temp("apply/armor",100);
  set_temp("ref_shield",1);
  set("spells/reflection/level",100);
  set("spells/fdragon/level",100);
  set("spells/fireball/level",100);
  set("spells/confuse/level",100);
  set("spells/thunder/level",100);
  set("spells/firedance/level",100);
  set("spells/hellfire/level",100);
  set("spells/dreamwings/level",100);
  set("spells/dreamcure/level",100);
  set("spells/meteor/level",100);
  set("get_dan_sp",1);
  set("allow_meteor",1);
  set("adv_dancer",1);
  set("allow_fdragon",1);
  set("allow_hellfire",1);
  set("force_factor",15);
  set("mystery",1);
  set("random_move",200);
  set_temp("ref_shield",1);
  set_temp("roared", 1 );
  setup();
  set("chat_chance",100);
  set("family/family_name","夜夢小築");
  set("chat_msg",({
    (: random_move :),
  }));
  carry_object("/open/dancer/obj/linrboots.c")->wear();
  carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
  carry_object("/open/dancer/obj/yuawaist.c")->wear();
  set("chat_chance_combat",60);
  set("inquiry", ([
  ]));
  set("chat_msg_combat",({
    (: magic1 :),
    (: magic2 :),
    (: magic3 :),
  }));
}
           
int accept_kill(object who)
{
//  who=this_player();
  command("con reflection");
  kill_ob(who);
  message_vision(sprintf("\n\t\t" + HIC + "    " + HIW + "～　" + HIM + "憶紅塵" + HIW + "，" + HIG + "血染霓裳" + HIW + "，" + HIY + "天地無痕各一方\n\n\n"
    HIC + "\t\t\t無奈何" + HIW + "，" + HIB + "恨遺飛霜" + HIW + "，" + HIR + "孤獨人間恨兩行　" + HIW + "～\n\n\n"
    HIR + "\t ╭═╮  ╭╗      " + HIG + "╠╦╦╦╦╯    " + HIC + "═╗╭══╮    " + HIM + "◆╭═╮╭═╮\n"
    HIR + "\t ╠═╣╰═╝      " + HIG + "╰╬╬╬╬╯    " + HIC + "╰╯║╭╮║    " + HIM + "◆╠─╣╠─╣\n"
    HIR + "\t ╰╦╯  ╭╗      " + HIG + "╰╬╩╩╩╯     " + HIC + "● ║║║║    " + HIM + "╗╠═╯╰═║\n"
    HIR + "\t ╦╩╦╰═╯        " + HIG + "╠═╦╬╯     " + HIC + "╗ ║║║║    " + HIM + "║║ ╦╬╦ ║\n"
    HIR + "\t ╰╦╯  ╭╗        " + HIG + "║●╬╬╯     " + HIC + "║ ║╰╯║    " + HIM + "║║ ╰︾╯ ║\n"
    HIR + "\t ●║●╰═╯        " + HIG + "╯  ║║       " + HIC + "╯ ╰══╯  " + HIM + "╰╝║ ╭╬╮ ║\n\n\n"),who);
  who->start_busy(1);
  return 1;
}

void heart_beat()
{
  object env,mob,*enemy;
  int i,j,k,exp1,exp2;
  j=random(100);
  mob = this_object();
  if(!mob) return ;
  if(!environment(mob)) return ;
  env = environment(mob);
  if( is_fighting())
  {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    for(j=0;j<i;j++)
    {
      exp1=mob->query("combat_exp");
      if(!enemy[j]) continue;
      exp2=enemy[j]->query("combat_exp");
      if(exp2>exp1)
        mob->set("combat_exp",exp2+random(16888));
    }
  }
  if( j < 40 && is_fighting())
  {
    message_vision(HIW + "\n\n\t\t----- " + HIY + "媚 " + HIW + "＊ " + HIG + "影 " + HIW + "＊ " + HIR + "舞 " + HIW + "＊ " + HIC + "豔" + HIW + " -----\n\n"
      HIM + "$N" + HIM + "眼露媚光，隨著夜色迷濛翩翩起舞，朱唇嬌豔，舞姿輕盈，此招正是\n"
      HIM + "$N" + HIM + "傾國傾城，迷惑天下的妖媚之術，你受到媚術所迷惑，看的入迷三分\n
不知不覺逐漸被媚術迷惑失神，攻防之值瞬間大降！\n\n" + NOR, mob );
    for( k=0 ; k < i ; k++)
    {
      if( !enemy[k] ) continue;
      if( enemy[k]->is_character() && !enemy[k]->is_corpse() && living(enemy[k]) && enemy[k] != mob && !wizardp(enemy[k]) )
      {
        message_vision(HIR + "妖媚之術如天仙下凡，看得你如癡如醉，目瞪口呆！！\n" + NOR,enemy[k]);
        enemy[k]->receive_wound("kee",300,mob);
        enemy[k]->apply_condition("power-down",enemy[k]->query_condition("power-down")+5);
        COMBAT_D->report_status(enemy[k],1);
      }
    }
  }
  if( 40 < j && j < 70 && is_fighting() )
  {
    enemy=mob->query_enemy();
    for(i=0;i<sizeof(enemy);i++) {
      if(!enemy[i]) continue;
      if(environment(mob) == environment(enemy[i]))
      {
        message_vision(HIR + "\n\n$N運起鳳凰靈氣，靈氣灌頂游走全身，鳳凰靈氣配合夢玄法鑑，空氣瞬間凝結成冰！\n\n"
          HIC + "\t\t\t◎ " + HBBLU+HIR + "鳳 " + HIW + "～ " + HIR + "凰 " + HIW + "～ " + HIY + "展 " + HIW + "～ " + HIY + "翅" + NOR+HIC + " ◎\n\n"
          HIB + "\t\t● " + HIR + "血 " + HIW + "、 " + HIR + "染 " + HIW + "、 " + HIM + "紅 " + HIW + "、 " + HIM + "塵 " + HIW + "、 " + HIG + "舞 " + HIW + "、 " + HIG + "秋 " + HIW + "、 " + HIG + "風 " + HIB + "●\n\n\n"
          HIY + "只見$N" + HIY + "身上散放出一股強大的氣勁，靈氣頓時浮現衝天而去，化成八道不同的靈光疾射\n"
          HIY + "你胸前八大要穴，只見你" + HIY + "受靈氣所限制，頓時全身內力不斷流失，身體虛弱無力，無法使勁。\n\n" + NOR, mob );
        enemy[i]->apply_condition("no_power_e",random(10)+5);
        enemy[i]->receive_damage("kee",1200,mob);
        enemy[i]->receive_damage("gin",500,mob);
        enemy[i]->receive_damage("sen",500,mob);
        COMBAT_D->report_status(enemy[i]);
      }
    }
  }
  if( 70 < j )
  {
    mob->delete_busy();
    if(mob -> query("kee") < mob->query("max_kee")*0.6)
    {
      message_vision( HIG + "\n$N" + HIG + "使出夢玄法鑑治療術，瞬間身上的傷口漸漸癒合。\n" + NOR, mob);
      mob->clear_condition();
      mob->receive_heal("kee",700);
      mob->receive_curing("kee",700);
      mob->receive_heal("gin",500);
      mob->receive_curing("gin",500);
      mob->receive_heal("sen",500);
      mob->receive_curing("sen",500);
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

string magic1()
{
  if(random(2)<1)
    command("con firedance");
  else command("con confuse");
  return "\n";
}

string magic2()
{
  if(random(2)<1)
    command("con hellfire");
  else command("con thunder");
  return "\n";
}

string magic3()
{
  if(random(3)<2)
    command("con fdragon");
  else command("con fireball");
  return "\n";
}

void die()
{
  object winner = query_temp("last_damage_from");
  string name = winner->query("name");
  string class1 = winner->query("family/family_name");
  set("combat_exp",7000000);
  if(!winner)
  {
    ::die();
    return ;
  }
  tell_object(users(),HIW + "\n\n\n    ～ " + HIR + "媚  舞  迷  離    " + HIY + "一 夕 成 名    " + HIC + "敗 盡 多 少 英 雄 豪 傑\n\n"
    HIG + "\t\t夜 夢 天 舞    " + HIB + "無 數 寒 霜    " + HIM + "成 就 一 代 雲 舞 幻 姬 "
    HIW + "～\n\n\n" + HIR + "沒想到我一代舞之傳人，竟然會敗在"+HIG+class1+HIW + "弟子"+HIY+name+HIR+"之手。\n難道這真的是上天的安排嗎？我不甘心啊！！\n我的傳人必會為我血洗天下的！！！\n\n\n" + NOR);
  message_vision(HIY + "\n"+winner->name()+"打死凌雲飛得到四百點戰功\!!\n" + NOR,winner);
  write_file("/log/get_warp",sprintf("%s(%s) 打敗凌雲飛得到四百點戰功\於 %s\n",
    winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",400);
  ::die();
}
