//tainaka_ritsu.c的簡化版2 作為忍者的宣傳 by blazakira
//作為新手quest的過場npc 因為不打算給玩家打 避免洗戰功的情況出現 所以不給予戰功的版本 by blazakira

#include <ansi.h>
inherit NPC;
string per1();
string per2();
string per3();
string per4();
string per5();
object follow;

void create()
{
  object ob;
  set("title",HIW + "暗殺組首席" + NOR);
  set("nickname",MAG + "任務執行中" + NOR);
  set_name("謎樣忍者",({"assassination ninja","assassination","ninja","n"}));
  set("long","來自海外島嶼上的某個組織，其目的不明。\n");
  set("gender","男性");
  set("combat_exp",20000001);
  set("no_exp",1);
  set("attitude","heroism");
  set("age", 75);
  set("str",60);
  set("con",30);
  set("kar",500);
  set("class","killer");
  set("score",1000000);
  set("bellicosity",70000);
  set("atman",150000);
  set("max_atman",150000);
  set("mana",150000);
  set("max_mana",150000);
  set("force",200000);
  set("max_force",200000);
  set("max_kee",200000);
  set("max_sen",200000);
  set("max_gin",200000);
  set("s_kee",500);
  set("max_s_kee",300);
  set("force_factor",20);
  set_skill("dagger",150);
  set_skill("throwing",50);
  set_skill("move",100);
  set_skill("dodge",150);
  set_skill("parry",100);
  set_skill("force",200);
  set_skill("blackforce",150);
  set_skill("shade-steps",100);
  set_skill("rain-throwing",100);
  set_skill("dark-steps",100);
  set("dark-steps/shadow/enable",1);
  set("dark-steps/share/enable",1);
  set("functions/manakee/level",150);
  set("functions/wind-steps/level",100);
  set("monkey_lv",100);
  set_temp("mob_def",1000);
  set("env/auto_back","YES");
  set("env/cmd_perform","darkforce.evilkee");
  if (random(2)) {
    set("env/cmd_cast","missible");
  } else {
    set("env/cmd_cast","feeblebolt");
  }
  set("quest/rain",1);
  set("quest/memory",1);
  set("upkee",1);
  set("quest/head-kill",1);
  set("sec_kee","mkill");
  set("quest/island",3);
  set("quest/worldpill",1);
  set("ninja/firstpart",1);
  set("earth-kill/killsword/exp",500);
  set("quest/be_pker",1);
  set("quest/add_bak",1);
  set("earth-kill/twoblade/exp",1);
  set("PKS",200);
  set_skill("darkforce",150);
  set_skill("earth-kill",100);
  set("functions/earthkill/level",100);
  set("functions/evil-body/level",100);
  set("functions/evilkee/level",100);
  set("functions/make-dagger/level",100);
  set("darkforce/make-ken/exp",0);
  set("darkforce/make_dag/exp",100);
  map_skill("force","darkforce");
  map_skill("parry","earth-kill");
  map_skill("dodge","dark-steps");
  map_skill("move","dark-steps");
  map_skill("dagger","earth-kill");
  map_skill("throwing","rain-throwing");
  set("spells/feeblebolt/level",150);
  set("spells/missible/level",100);
  set("can_use_mobkee",1);
  set("no_learn",1);
  set("family/family_name","黑牙聯");
  delete("family/privs");
  set("chat_chance_combat", 200);
  set("chat_msg_combat", ({
  "謎樣忍者說道﹕………………\n",
  "謎樣忍者說道﹕…………\n",
  "謎樣忍者說道﹕殺殺殺殺!!!\n",
    (: per1 :),
    (: per2 :),
    (: per3 :),
    (: per4 :),
    (: per5 :),
    (: perform_action("dark-steps.wind-steps") :),
    (: perform_action("darkforce.evilkee") :),
    (: perform_action("rain-throwing.manakee") :),
    (: perform_action("rain-throwing.rain") :),
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
  set_temp("roared",1);
  set("bellup",1);
  set("assassin",query("id"));
  setup();
  set("ninjaeq/getshield",1);
  set("ninjaeq/getboots",1);
  set("ninjaeq/getarmband",1);
  set("ninjaeq/getcloth",1);
  set("ninjaeq/gethands",1);
  set("ninjaeq/gethelmet",1);
  set("ninjaeq/getleggings",1);
  set("ninjaeq/getneck",1);
  set("ninjaeq/getpants",1);
  set("ninjaeq/getring",1);
  set("ninjaeq/getsurcoat",1);
  set("ninjaeq/getwaist",1);
  set("ninjaeq/getwrists",1);
  set_temp("secondary_weapon","/open/killer/obj/dag1.c");
  carry_object("/daemon/class/killer/obj/ninja-eq.c");
  carry_object("/open/ping/obj/poison_pill.c")->set_amount(random(20)+10);
  carry_object("/autoload/sky/claw");
  ob=carry_object("/open/killer/obj/hate_knife");
  ob->set("name",NOR + "東瀛"+HIM+"仿製的"+NOR+"瑕疵"+HIR+"千古恨" + NOR);
  ob->set_amount(200);
  carry_object("/autoload/killer/pet2");
  carry_object("/open/japan/obj/war_item.c");
  all_inventory(this_object())->set("no_get",1); //作為die()裡 刪除裝備的mark
}

void init()
{
  if(environment(this_object())->query("no_fight")) return ;
  if ( !query_temp("ninjaeq/open") )
  {
    command("open ninja");
    command("wear all");
    this_object()->delete_busy();
  }
  if ( !is_fighting() && !objectp(present( "evil dagger", this_object() )) ) {
    command("perform darkforce.make-dagger");
    this_object()->delete_busy();
  }
  if ( this_player()->query_temp("m_kill") ) {
    this_player()->delete_temp("m_kill");
  }

  add_action("do_use","use");

  set_heart_beat(1);
  ::init();
  call_out("greeting", 3, this_player());
}

void greeting( object ob )
{
  object weapon=query_temp("secondary_weapon"),me=this_object();
  if( !ob || environment(ob) != environment() ) return;

  if( !ob->query_condition("mkill_out") && ob->query_temp("m_kill") ==1 && !is_fighting() )
    ob->delete_temp("m_kill");
/*
  if( !ob->query_temp("blaz/kon") && ob->query("id") != "blazakira" )
  {
    if(ob->query("combat_exp")>3750000 )
    {
      if(ob->query("combat_exp") > 8000000) 
      {
        if (weapon && weapon->query("id")=="dagger" && !is_fighting()) {
          call_out("do_kill", 1, me, ob);
        }
        else {
          write( HIY + "謎樣忍者說道﹕………\n" + NOR );
          command("follow "+ob->query("id"));
          set("class","fighter");
          command("exert roar");
          set("class","killer");
          kill_ob(ob);
        }
      }
    }else{
      command("snort "+ob->query("id"));
      command("say 死嫩嫩，練強一點吧！");
    }
  }
*/
  call_out("greeting2", 4, this_player());
}

void greeting2()
{
  object ob=this_object();
  if ( !query_temp("weapon") ) {
    if ( !objectp(present("hate knife", ob)) && objectp(present("evil dagger", ob))) {
      command("wield evil dagger");
      ob->delete_busy();
      ob->clear_condition();
    }
    else if ( random(2) ) {
      command("wield evil dagger");
    }
    else {
      command("wield hate knife");
    }
  }
  if ( !is_fighting() && !query_temp ("evil-body") ) {
    message_vision (HIW + "$N使出真˙黑牙神功\中的" + HIC + "「天魔附身」" + NOR + "\n" + HIG + "一道綠光注入$N身體。\n" + NOR,ob);
    ob->set_temp ("evil-body", 1);
    this_object()->delete_busy();
    call_out("per1", 3, this_player());
  }
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
      message_vision(HIY + "\n唵、嘛、呢、叭、彌、哞……$n受到東瀛密宗的密咒影響，竟對$N倒戈相向！\n" + NOR,me,mob);
      mob->set_leader(me);
      mob->kill_ob(me);
    }
  }
}

int accept_kill(object who)
{
  who=this_player();
  if ( !query_temp("weapon") ) {
    command("change_attr dagger");
    command("wield attribute-dagger");
    command("wield attribute-dagger");
  }
  call_out("kee_out", 0, this_object(), who);
  kill_ob(who);
  return 1;
}

int accept_fight(object who)
{
  who=this_player();
  if ( !query_temp("weapon") ) {
    command("change_attr dagger");
    command("wield attribute-dagger");
    command("wield attribute-dagger");
  }
  call_out("kee_out", 0, this_object(), who);
  fight_ob(who);
  return 1;
}

int accept_object(object who, object ob)
{
  string object_name;
  object_name=ob->query("name");
  switch(object_name) {
    case HIR + "千古恨" + NOR:
      command("say 好東西，我正覺得不夠用呢，為了答謝你，你的生命就借我用一下吧:)");
      command("say 東西還你？想太多了，喔～呵呵呵呵～～:D");
      return 1;
      break;
    case HIW + "鑽石" + NOR:
    case "萬兩銀票":
    case "黃金":
    case "銀子":
      command("say 還有沒有？再多給我一點咩～");
      command("cat "+who->query("id"));
      return 1;
      break;
    default : break;
  }
  command("say 這是啥麼東西，口亨～");
  message_vision("$N順手往後一扔，"+ob->query("name")+"消失在天際——\n" + NOR,this_object());
  destruct(ob);
  return 1;
}

void heart_beat()
{
  object ob=this_object();
  object env,*enemy;
  mapping exit;
  string *exit_name,msg;
  int i,j,damage,exp1,exp2,maxkee,pow;
  if(!ob || !environment(ob)) return;
  if(ob->query_temp("unconcious") > 0 ) {
    set_heart_beat(0);
  }
  env = environment(ob);
  enemy=ob->query_enemy();
  if ( !is_fighting() && ob->query_temp("m_kill") ) {
    ob->delete_temp("m_kill");
    remove_all_killer();
    ob->set("combat_exp",20000001);
    command("eat flower pill");
  }
  if(ob->is_fighting()) {
    i=sizeof(enemy);
    for(j=0;j<i;j++) {
      exp1=ob->query("combat_exp");
      if(!enemy[j]) continue;
      exp2=enemy[j]->query("combat_exp");
      if(exp2>exp1) {
        ob->set("combat_exp",exp2+random(16888));
      }
      exp1=ob->query("max_kee",1);
      if(!enemy[j]) continue;
      exp2=enemy[j]->query("max_kee",1);
      if(exp2>exp1) {
        maxkee=ob->query("max_kee",1);
      }
    }
  }
  j=random(100);
  pow=ob->query("combat_exp")/200000;
  if( 90< j && j <100 && is_fighting() ) {
    message_vision(BLINK+HIM"\n「東瀛密宗忍術奧義　七色之紫　※哞※形※」\n"NOR+HIW"$N大暍一聲﹐放出身上的殺氣﹐眼神由溫和轉變成恐怖，威攝著在場的所有人。\n\n" + NOR,ob);
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("boss") == ob->query("id")) continue;
      if(environment(ob) == environment(enemy[i]) ) {
        enemy[i]->start_busy(1);
      }
    }
  }

  if( 80< j && j <90 && is_fighting() && query("force_factor") < 20) {
    message_vision(BLINK+BLU"\n「東瀛密宗忍術奧義　七色之靛　※剛※力※招※來※」\n"NOR+HIW"$N大暍一聲﹐放出身上的殺氣﹐舉手投足挾著實質血煞旋風。\n\n" + NOR,ob);
    set("force_factor",200);
  }

  if( 70< j && j <80 && is_fighting() && query("force")*1.2 < query("bellicosity") ) {
    message_vision(BLINK+HIB"\n「東瀛密宗忍術奧義　七色之藍　※月※之※淚\※」\n"NOR+HIW"$N身上的殺氣宛如實體般在身後形成了月影融入體內成了一股暖流。\n\n" + NOR,ob);
    add("force",random(5000)+2000);
  }

  if( 40< j && j <50 && is_fighting() ) {
    enemy=ob->query_enemy();
    message_vision(BLINK+HIR"\n「東瀛密宗忍術奧義　七色之紅\n\t\t" + HBCYN + "ˍ忍▂殺▄亂▆舞▇　◆紅◆孔◆雀◆　▇忍▆殺▄亂▂舞ˍ"NOR+BLINK+HIR"」\n"NOR+HIW"磅礡的殺氣從$N的身上傳來，實質的殺意化作一隻鮮紅的孔雀襲來。\n\n" + NOR,ob);
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("boss") == ob->query("id")) continue;
      if( environment(ob) == environment(enemy[i]) && enemy[i]->is_fighting() ) {
          damage = random(400)+200;
          if(damage > 300) {
            damage=damage+pow*3;
            enemy[i]->apply_condition("bleeding",random(20)+10);
            enemy[i]->receive_damage("kee", damage, ob);
            COMBAT_D->report_status(enemy[i]);
            if( wizardp(enemy[i]) )
            {
              tell_object(enemy[i],BGRN+HIC"強攻範圍技！額外傷害為〈"+HIG+pow+HIC"〉總傷害為〈"+HIG+damage+HIC"〉(npc專用)\n" + NOR);
            }
          }
          else {
            message_vision("(" + WHT + "$n不急不徐身影左右晃動將此招一一閃過。" + NOR + ")\n",ob,enemy[i]);
          }
      }
    }
  }

  if( j <40 && is_fighting() ) {
    enemy=ob->query_enemy();
    message_vision(BLINK+HIY"\n「東瀛密宗忍術奧義　七色之黃　※螺※轟※」\n"NOR+HIW"瞬間$N以滿天花雨擲金針手法將袖中暗器射出！\n\n" + NOR,ob);
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("boss") == ob->query("id")) continue;
      if( environment(ob) == environment(enemy[i]) && enemy[i]->is_fighting() ) {
          damage = random(300)+100;
          if(damage > 200) {
            damage=damage+pow;
            enemy[i]->apply_condition("power-down",random(5)+6);
            enemy[i]->receive_damage("kee", damage, ob);
            COMBAT_D->report_status(enemy[i]);
            if( wizardp(enemy[i]) )
            {
              tell_object(enemy[i],BBLU+HIR"降攻範圍技！額外傷害為〈"+HIG+pow+HIR"〉總傷害為〈"+HIG+damage+HIR"〉(npc專用)\n" + NOR);
            }
          }
          else {
            message_vision("(" + WHT + "$n不急不徐身影左右晃動將此招一一閃過。" + NOR + ")\n",ob,enemy[i]);
          }
      }
    }
  }

  if( 60< j && j <70 && is_fighting() ) {
    enemy=ob->query_enemy();
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("boss") == ob->query("id")) continue;
      if(environment(ob) == environment(enemy[i]) && !enemy[i]->query_temp("mkill")  && enemy[i]->query_temp("m_kill") && enemy[i]->is_fighting() ) {
        tell_object(enemy[i],HIM + "  殺      意      魔      氣\n\n" + NOR);
        tell_object(enemy[i],HIG + "頂級威力          *綠*級*魔*氣*   \n\n" + NOR);
        tell_object(enemy[i],HIG + "謎樣忍者由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR);
        tell_object(enemy[i],HIG + "謎樣忍者地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR);
        if( wizardp(enemy[i]) )
        {
          tell_object(enemy[i],BBLU+HIM"殺意魔氣範圍技！(npc專用)\n" + NOR);
        }
        enemy[i]->apply_condition("mkill_out",random(6)+2);
        enemy[i]->receive_damage("gin", 500+random(300), ob);
        enemy[i]->receive_damage("sen", 500+random(300), ob);
        enemy[i]->start_busy(2);
        enemy[i]->set_temp("mkill",1);
      }
    }
  }

  if( 50< j && j <60 && is_fighting() ) {
    enemy=ob->query_enemy();
    message_vision(BLINK+HIW"\n「東瀛密宗忍術奧義　七色之白　※弧※月※」\n"NOR+HIW"一陣狂風挾著樹葉籠罩著$N，化作一根木頭出現在眾人面前。\n\n" + NOR,ob);
    ob->delete_busy();
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("boss") == ob->query("id")) continue;
      if( environment(ob) == environment(enemy[i]) && enemy[i]->is_fighting() ) {
          if(random(1000) < 500) {
            message_vision(HIW + "在$n訝異眼前的敵人怎麼突然變成木頭的當下卻受到來自$N背後的暗算！)\n" + NOR,ob,enemy[i]);
            COMBAT_D->do_attack(ob, enemy[i], ob->query_temp("weapon"), 2);
          }
          else {
            message_vision("(" + WHT + "$n發現了$N的真身將此招閃過。" + NOR + ")\n",ob,enemy[i]);
          }
      }
    }
  }

  if (ob->query("kee") < maxkee*0.50 && ob->query_temp("unconcious") != 1 && (random(100) < 45))
  {
    if (is_fighting()) {
      ob->receive_curing("kee",(int)(maxkee/100*2));
      ob->receive_heal("kee",(int)(maxkee/100*3));
      ob->receive_curing("sen",(int)(maxkee/100*1));
      ob->receive_heal("sen",(int)(maxkee/100*2));
      ob->receive_curing("gin",(int)(maxkee/100*1));
      ob->receive_heal("gin",(int)(maxkee/100*2));
      if (random(100) < 50) {
        if (random(100) < 50)
          ob->delete_busy();
        else ob->clear_condition();
      }
      message_vision(BLINK+BLU"\n「東瀛密宗忍術奧義　七色之綠　※菖※蒲※之※歌※」\n"NOR+HIW"$N凝神調息﹐口中暗誦著忍者一脈的禱文，身上的傷口以可見的速度恢復了！\n\n" + NOR,ob);
      COMBAT_D->report_status(ob);
    }
    else {
      if( query("kee") < query("eff_kee") && (random(100) < 40) ) {
        command("exert recover"); }
      if( query("eff_kee") < query("max_kee") && (random(100) < 50) ) {
        command("exert heal"); }
    }
  }

  if ( is_fighting() && !objectp(present("evil dagger", ob)) && !query_temp("weapon")
       && !objectp(present("hate knife", ob)) && objectp(present("attribute-mine", ob)) ) {
    command("change_attr dagger");
    command("wield attribute-dagger");
    command("wield attribute-dagger");
    ob->delete_busy();
    ob->clear_condition();
  }
  else if ( is_fighting() && !objectp(present("evil dagger", ob)) && !query_temp("weapon")
            && !objectp(present("hate knife", ob)) && !objectp(present("attribute-mine", ob)) ) {
    tell_room(environment(), name()+"大喝﹕太小看我了！\n("+name()+"從懷裡拿出一把匕首。)\n" + NOR);
    new("/autoload/sky/claw")->move(ob);
    command("change_attr dagger");
    command("wield attribute-dagger");
    command("wield attribute-dagger");
    ob->delete_busy();
    ob->clear_condition();
  }
  else if ( is_fighting() && !query_temp("weapon") ) {
    command("wield all");
    ob->delete_busy();
    ob->clear_condition();
  }
  i=random(3)+1;
  if ( is_fighting() && objectp(present("nija fighter", ob)) && ob->query_temp("sub")!="USED" && query("kee")*i < query("max_kee") ) {
    call_out("do_sub", 0, ob);
  }
  if( this_object()->query("combat_exp") > 300000000 )
    this_object()->set("combat_exp",300000000);

  if (!is_fighting() && query_temp("target")) { //戰鬥完就消失
    command("say ………………………");
    message_vision(HIY+"\n$N片刻不遲疑地扔下了一顆煙霧彈，消失在眾人的面前。\n"+NOR,ob);
    destruct(ob);
  }
  ::heart_beat();
}

string per1()
{
  message_vision(HIC + "$N運起分功\化影之清風術, 身形步伐頓時變得輕快起來!!\n" + NOR,this_object());
  this_object()->set_temp("wind",1);
  return "\n";
}

string per2()
{
  command("perform darkforce.evilkee");
  return "\n";
}

string per3()
{
  command("perform rain-throwing.mobkee");
  return "\n";
}

string per4()
{
  command("perform rain-throwing.rain");
  return "\n";
}

string per5()
{
  command("perform earth-kill.earthkill");
  return "\n";
}

void do_kill(object me,object target)
{
  object env, weapon;
  object *inv;
  int i;
  if( !me || !target ) return;
  if( environment(target) != environment() ) return;
  if( !me->is_fighting() && target->query("kee") > 0 && !me->query_temp("do_cmd_bak/"+target->query("id")) && target->query("boss") != me->query("id") ) {
    if(target !=me ) {
      message_vision(HIC+"$N" + HIC + "偷偷摸摸地走到$n" + HIC + "背後。\n"+NOR,me,target);
      if(random(10) > 2) {
        switch(random(3)) {
          case 0:
            message_vision(HIW+"\n$N" + HIW + "以極快的速度﹐瞄準$n" + HIW + "用力一刺﹐使$n" + HIW + "受到極大的傷害。\n"+NOR,me,target);
            target->receive_wound("kee", (int)target->query("max_kee")*20/100,me);
            break;
          case 1:
            message_vision(HIW+"\n$N" + HIW + "對著$n" + HIW + "的背部狠狠一捅﹐使$n" + HIW + "血流不止。\n"+NOR,me,target);
            target->receive_wound("kee", (int)target->query("max_kee")*15/100,me);
            break;
          case 2:
            message_vision(HIW+"\n$N" + HIW + "無聲無息的以暗器手法﹐把匕首往$n" + HIW + "身上一扔﹐使$n" + HIW + "受到極大的打擊。\n"+NOR,me,target);
            target->receive_wound("kee", (int)target->query("max_kee")*25/100,me);
            break;
        }
        message_vision(HIR+"\n$n" + HIR + "見身上插著$N" + HIR + "的匕首﹐忿怒地想殺死$N" + HIR + "。\n"+NOR,me,target);
        me->set_temp("do_cmd_bak/"+target->query("id"),1);

        //雙手武器  以副為先
        if (weapon=me->query_temp("secondary_weapon")) {
          weapon=me->query_temp("secondary_weapon"); }
        else {
          weapon=me->query_temp("weapon"); }

        weapon->unequip();

        //改變名字
        if ( weapon->query("BAK")!="USED" ) {
          weapon->set("name","染血的"+weapon->name()+""); }

        //武器變壞
        weapon->set("value", 0 );
        weapon->set("no_sell",1);
        weapon->set("no_save",1);
        weapon->set("weapon_prop/damage", 0);
        weapon->set("BAK","USED");
        weapon->move(target);
        me->reset_action();
        me->kill_ob(target);
        target->kill_ob(me);
        target->apply_condition("bleeding",random(10)+1);
      }
      else if(!userp(target)) { //不是玩家時就不用跑了 就直接打吧
        me->do_command("kill "+target->query("id"));
      }
      else {
        message_vision(HIW+"\n$n突然發現了$N的存在﹐使$N找不到下手的機會。\n"+NOR,me,target);
        command("kill "+me->query_temp("target"));
      }
    }
  }
//  return; //void 不用特地設return
}

void do_flee()
{
  object me=this_object(),env;
  mapping exit; 
  string *exit_name;
  int i;
  env = environment(me);
  exit = env->query("exits");
  exit_name = keys(exit);
  i = random(sizeof(exit_name));
  command(exit_name[i]);
  i = random(sizeof(exit_name));
  command(exit_name[i]);
//  return;
}

int kee_out(object me,object target)
{
  if ( target && !target->query_temp("mkill")  && !me->query_temp("m_kill") ) { //既然是戰鬥中了就不要持續放魔氣殺吧 //作為正式的npc時 須開啟此判斷
    message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
    if (random(3)==0 && me->query("max_s_kee") > 0)
    {
      message_vision(HIM + "超頂級威力        **紫**級**魔**氣**      \n\n" + NOR,me);
      message_vision(HIM + "超精純的殺意魔氣化成真元由$N體內射出，這是具有無比威力的魔氣\n" + NOR,me);
      message_vision(HIM + "$N的魔氣真元在瞬間射入$n體內，無比的威力在其體內爆發！\n" + NOR,me,target);
      me->add("max_s_kee",-30); //所需花去的靈氣等級
      target->apply_condition("mkill_out",random(15)+1);
    }
    else {
      message_vision(HIG + "頂級威力          *綠*級*魔*氣*   \n\n" + NOR,me);
      message_vision(HIG + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
      message_vision(HIG + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
      target->apply_condition("mkill_out",random(10)+1);
    }
    target->start_busy(2);
    target->receive_damage("gin",random(1400),me);
    target->receive_damage("sen",random(1200),me); //膽識30*40=1200 一般是一擊必殺，重要NPC不會有問題
    target->set_temp("mkill",1);
    target->set_temp("m_kill",1); //額外的判斷 為了啟動心跳攻擊中的殺意魔氣
    me->set_temp("m_kill",1); //額外的判斷 為了使npc於戰鬥中了就不要持續放魔氣殺
  }
}

int do_sub(object ob)
{
  object sub;
//  ob = this_object();
  ob->set("monkey_lv",100); //影武者等級
  ob->set_temp("mob_def",1000); //影武者的防禦力
  if ( ob && ob->is_fighting() && ob->query_temp("sub")!="USED" )
  {
    if( present("nija fighter",ob) )
      destruct(present("nija fighter",ob));
    message_vision(HIC + "$N向$N的 " + NOR + "影武者 " + HIC + "求救,突然間$N的 " + NOR + "影武者 " + HIC + "變成人加入這場戰鬥。\n" + NOR,ob);
    sub=new("/open/killer/obj/two.c");
    sub->set("sub_id",""+ob->query("id")+"");
    sub->set("old_name","影武者");
    if ( ob->query_temp("pk_fight") ) {
      sub->set_temp("pk_fight",1);
    } else { ob->set_temp("sub","USED"); }
    sub->move( environment(ob) );
    sub->set("boss",ob->query("id"));
    sub->set("mystery",1);
    sub->set_temp("roared",1);
    sub->invocation(ob); //先執行天賦設定後重新設名字
  }
  return 1;
}

void die()
{
  object winner = query_temp("last_damage_from"),*obj,me=this_object();
  int j,i;
  j=random(6);
  if(!winner)
  {
    ::die();
    return ;
  }

  obj=all_inventory(me);
  if(obj) {
    for(i=0;i<sizeof(obj);i++){
      if(!obj[i]->query("no_get")) continue; //如果不是預設不能拿得就忽略
      if( present(obj[i]->query("id"),me) )
        destruct(present(obj[i]->query("id"),me)); //不能拿就刪除
    }
  }
  add_money("gold",1);
  carry_object("/open/killer/obj/s_pill")->set_amount(random(5)); //殺手密藥(Killer pill)
  carry_object("/open/ping/obj/poison_pill.c")->set_amount(random(20)+10); //殺手密藥(Killer pill)

  tell_object(winner,HIG + "\n\n謎樣忍者：\n\n\t" + HIY + "…………\n\n\t哼！這次"HIW+winner->name()+HIY+"阻止了我，但我會再回來的。\n\n" + NOR);

  ::die();
}
