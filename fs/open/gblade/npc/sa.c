//增加心跳技能的目標判定 by blazakira 2011/4/7

#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;
int do_cmd(string str) ;

void create()
{
  set_name("獨孤嵊",({"degu sa","sa"}));
  set("long","此人是獨孤愁的師兄，和弟子獨孤莫愁一心想平魔刀。\n");
  set("gender","男性");
  set("combat_exp",15000000);
  set("score",9000000);
  set("sec_kee","god");
  set("max_s_kee",1000);
  set("s_kee",1000);
  set("age",60);
  set("class","fighter");
  set("family/family_name","雪蒼派");
  set("title","武天至聖");
  set("force",150000);
  set("max_gin",60000);
  set("max_kee",60000);
  set("max_sen",60000);
  set("bellicosity",30000);
  set("max_force",60000);
  set("max_atman",60000);
  set("max_mana",60000);
  set("atman",50000);
  set("mana",50000);
  set("force_factor",90);
  set("str",50);
  set("cor",50);
  set("cps",50);
  set("int",50);
  set("con",50);
  set("spi",50);
  set("kar",50);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set("env/衝穴","YES");
  set_skill("snow-martial", 100);
  set_skill("snowforce", 300);
  set_skill("literate",100);
  set_skill("black-steps",100);
  set_skill("unarmed",200);
  set_skill("dodge",120);
  set_skill("snow-kee",100);
  set_skill("parry",120);
  set_skill("force",400);
  map_skill("unarmed", "snow-martial");
  map_skill("parry","snow-kee");
  map_skill("force", "snowforce");
  map_skill("dodge", "black-steps");
  set_temp("armor_vs_force",1500);
  set_temp("no_die_soon",1);
  set_temp("no_badroar_max",1);
  set_temp("apply/armor",100);
  set_temp("apply/defense",100);
  set_temp("apply/damage",100);
  set_temp("apply/attack",100);
  set_temp("apply/dodge",50);
  set_temp("apply/parry",50);
  setup();
  carry_object("/open/snow/obj/figring")->wield();
  carry_object("/autoload/mblade/mring");
  add_money("cash", 10);
}
void init()
{
  add_action("do_cmd","cmd");
  add_action("do_cmd_do","");
  add_action("do_team","");
}

int do_team(string arg)
{
  object me,*all;
  int i;
  me=this_object();
  all=all_inventory(environment(me));
  if((string)query_verb()=="team" && arg) {
    for(i=0;i<sizeof(all);i++)
    {
      if(all[i]->query("id")=="degu sa") continue;
      if(!living(all[i])) continue;
      if(wizardp(all[i])) continue;
      kill_ob(all[i]);
    }
  }
}

int do_cmd_do(string arg)
{
  if((string)query_verb()=="do") {
    write(HIY + "獨孤嵊冷笑 :「用 do 我會 do run 喔」\n" + NOR);
    return 1;
  }
  if((string)query_verb() == "cm") {
    return do_cmd(arg);
  }
}

int do_cmd(string str) {
  string verb;
  object who=this_player();
  if(!str) return 1;
  verb = explode(str," ")[0];
  switch(verb)
  {
    case "throw":
      command("say 本武聖最厭惡背後用毒的人了，送死吧！\n");
      kill_ob(who);
      return 1;
      break;
    case "askgod":
      command("say 本武聖最厭惡使用占卜指令的人了，送死吧！\n");
      kill_ob(who);
      return 1;
      break;
    case "vet":
      command("say 本武聖最討厭蒙古大夫了！給我去死吧！\n");
      kill_ob(who);
      return 1;
      break;
    case "bak":
      command("say 本武聖一生光明最厭惡偷偷摸摸的人了，送死吧！\n");
      kill_ob(who);

      return 1;
      break;
    default:
  }
}

void heart_beat()
{
  object winner = query_temp("last_damage_from");  
  object me,*target,victim,*player;
  int i,j,k,a,b,c,d=0;
  a=random(100);
  me=this_object();
  if(me->is_fighting()||me->is_killing()) {
    target=me->query_enemy();
    player=me->query_enemy();
    if(i=sizeof(target)) {
      if(a>=6&&a<=35) {
        message_vision(HIC + "\n獨孤嵊突然眼露兇光，周圍聚集陰冷內勁\n\n" + NOR + "
            " + HIR + "獨孤嵊邪惡的狂吼：看我的『滅屍溶血掌』\n\n" + NOR + "
            " + HIB + "頓時一股強烈的屍臭味瀰天而生隴罩四周圍\n\n" + NOR,me);
        for(b=0;b<i;b++) {
          if(userp(target[b])) continue;
          target[b]->die();
        }
      }
      if(random(100)>40) {
        for(c=0;c<i;c++) {
//          if(!userp(target[c])) continue;
          if(target[c] && !userp(target[c])) continue; //增加判定為 如果目標存在 但是不能互動 by blazakira 2011/4/7
          player[d]=target[c];
          d=d+1;
        }
        victim=player[random(d)];
        if(!victim) { } else {
          if(a>=1&&a<=5) {
            if(environment(me)==environment(victim)) {
              for(k=0;k<7;k++) {
                message_vision(HIG + "獨孤嵊大喝一聲，融合雪蒼與瀧山絕學，向$N擊出『玄冰離火掌---毀天滅地式』\n" + NOR,victim);
                victim->receive_damage("kee",1000,me); 
                COMBAT_D->report_status(victim);
              }
              victim->set_temp("last_damage_from",me);
            }
          } else if(a>=36&&a<=45) {
            if(environment(me)==environment(victim))
              for(b=0;b<1;b++) {
                message_vision(HIR + "獨孤嵊大喝一聲，融合雪蒼絕學，向$N擊出『玄冰離火掌一式』\n" + NOR,victim);
                victim->receive_damage("kee",1000,me);
                COMBAT_D->report_status(victim);
              }
          } else if(a>=56&&a<=60) {
            if(environment(me)==environment(victim))
              for(b=0;b<2;b++) {
                message_vision(HIY + "獨孤嵊大喝一聲，融合雪蒼絕學，向$N擊出『玄冰離火掌二式』\n" + NOR,victim);
                victim->receive_damage("kee",1000,me);
                COMBAT_D->report_status(victim);
              }
          } else if(a>=71&&a<=75) {
            if(environment(me)==environment(victim))
              for(b=0;b<3;b++) {
                message_vision(HIM + "獨孤嵊大喝一聲，融合雪蒼絕學，向$N擊出『玄冰離火掌三式』\n" + NOR,victim);
                victim->receive_damage("kee",1000,me);
                COMBAT_D->report_status(victim);
              }
          } else if(a>=86&&a<=90) {
            if(environment(me)==environment(victim))
              for(b=0;b<4;b++) {
                message_vision(HIB + "獨孤嵊大喝一聲，融合瀧山絕學，向$N擊出『玄冰離火掌四式』\n" + NOR,victim);
                victim->receive_damage("kee",1000,me);
                COMBAT_D->report_status(victim);
              }
          } else if(a>=94&&a<=98) {
            if(environment(me)==environment(victim))
              for(b=0;b<5;b++) {
                message_vision(HIC + "獨孤嵊大喝一聲，融合瀧山絕學，向$N擊出『玄冰離火掌五式』\n" + NOR,victim);
                victim->receive_damage("kee",1000,me);
                COMBAT_D->report_status(victim);
              }
          } else if(a==99||a==66||a==0) {
            if(environment(me)==environment(victim))
              for(b=0;b<6;b++) {
                message_vision(HIW + "獨孤嵊大喝一聲，融合雪蒼和瀧山絕學，向$N擊出『玄冰離火掌---無涯式』\n" + NOR,victim);
                victim->receive_wound("kee",1200,me);
                COMBAT_D->report_status(victim);
              }
          } else { }
        }
      }
    }
    me=this_object();
    target=me->query_enemy();
    if(random(100)>50)
    {
      if(i=sizeof(target))
      {
        if(!me->query("change"))
        {
          if(random(10) >= 5)
          {
            message_vision(HIY + "獨孤嵊運起『離火掌』向你一擊，頓時你鮮血狂噴！\n" + NOR,me);
            for(j=0;j < i;j++) 
            {
              if ( !target[j] || environment(me) != environment(target[j]) ) continue;
              target[j]->add("kee",-2000);
              target[j]->apply_condition("hart",10);
              COMBAT_D->report_status(target[j]);
            }
          } else {
            message_vision(HIC + "獨孤嵊心感疲狽，運起『獨孤秘傳法咒』一道藍光從蒼天發出，頓時精神百倍。\n" + NOR,me);
            me->receive_curing("gin",5000);
            me->receive_heal("gin",5000);
            me->receive_curing("kee",9000);
            me->receive_heal("kee",9000);
            me->receive_curing("sen",5000);
            me->receive_heal("sen",5000);
            me->add("force",5000);
            me->delete_busy();
            me->clear_condition();
						me->delete_temp("five-1");
          }
        } else {
          if(random(10) >= 5) {
            message_vision(
                HIC + "\n獨孤嵊運起雪蒼寒勁，頓時只見獨孤嵊藍光護身，霎似天神！\n"
                HIY + "☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n\n"

                HIR + "獨孤嵊怒吼：看我的『綻藍光體術』！！！\n\n"

                HIY + "※※※※※※※※※※※※※※※※※※※\n"
                HIC + "頓時一陣強烈的藍光似猛虎似的把你吞沒在口中！\n\n"
                NOR,me);
            for(j=0;j < i;j++) 
            {
              if ( !target[j] || environment(me) != environment(target[j]) ) continue;
              target[j]->add("kee",-4000);
              target[j]->apply_condition("cold",10);
              //modify by whatup 降低命中率，這樣才不會有事沒事都中 2009/04/19
              if(random(400) > target[j]->query_skill("dodge"))
              {
                if(random(2) == 1)
                {
                  target[j]->set_temp("over/left",1);
                }
                else
                {
                  target[j]->set_temp("over/r-eyes",1);
                }
              }
              COMBAT_D->report_status(target[j]);
            }
          } else {
            message_vision(HIC + "獨孤嵊心感疲狽，運起『綻藍光體術』一道藍光從蒼天發出，頓時精神百倍。\n" + NOR,me);
            me->receive_curing("gin",8000);
            me->receive_heal("gin",8000);
            me->receive_curing("kee",15000);
            me->receive_heal("kee",15000);
            me->receive_curing("sen",8000);
            me->receive_heal("sen",8000);
            me->delete_busy();
            me->add("force",3000);
            me->clear_condition();
						me->delete_temp("five-1");
          }
        }
      }
    }
    if((me->query("eff_kee") < 4000 || me->query("kee") < 4000) && !me->query("change"))
    {
      tell_object(users(),"");
      tell_object(users(),HIW + "\n可惡呀！獨孤嵊怒道：老虎不發威，你當病貓！\n\n看來我只好使出百分之二百的力量了！\n\n可恨的"+winner->query("name")+"等死吧！\n\n" + NOR);
      tell_object(users(),"");
      me->set("force_factor",95);
      me->set("eff_kee",70000);
      me->set("kee",70000);
      me->set("eff_gin",70000);
      me->set("eff_sen",70000);
      me->set("gin",70000);
      me->set("sen",70000);
      me->set("force",150000);
      me->set("fire_strike",1);
      me->set("super_fire",1);
      me->set("family/family_name","瀧山派");
      me->set("env/瀧山連擊","YES");
      me->set("combat_exp",20000000);
      me->set_skill("lungshan", 100);
      me->set_skill("haoforce", 300);
      me->set_skill("fire-kee",100);
      me->set_temp("kang-power",1);
      map_skill("unarmed", "lungshan");
      map_skill("parry","fire-kee");
      map_skill("force", "haoforce");
      me->reset_action();
      me->set("change",1);
      me->delete_busy();
      me->clear_condition();
			me->delete_temp("five-1");
      me->set("title",HIC + "『綻藍聖光』"+HIW+"武天至聖" + NOR);

    }
  }
  me->clean_up_enemy();
	if(random(10) == 0 )
	{
		me->clear_condition();
		me->set("s_kee",1000);
	}
  ::heart_beat();
}

void die()
{
  object *enemy;
  int i,j;
  object winner = query_temp("last_damage_from");
  object head,me,ring;
  string name = winner->query("name");
  me=this_object();
  enemy=me->query_enemy();
  i=sizeof(enemy);
  ring=present("mdragon-ring",winner);
  if(userp(winner)) log_file("mblade/kill_sa", sprintf("%s(%s) 打敗 獨孤嵊 on %s\n",name,winner->query("id"), ctime(time()) ));
  head=new("/open/gblade/obj/sa-head");
  head->move(winner);
  if(!ring) {
    winner->set("meq/mring",1);
    head=new("/autoload/mblade/mring");
    head->move(winner);
  }
  if(userp(winner)) winner->add("snow-head",50);
  winner->set_temp("ko_sa",1);
  for(j=0;j<i;j++) {
    if(enemy[j]->query("class")!="blademan") continue;
    enemy[j]->set_temp("ko_sa",1);
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {      
        new("/open/sky/obj7/fox-order")->move(environment(winner));
        message_vision(HIM + "\n從獨孤嵊的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj7/fox_order",sprintf("%s(%s) 讓獨孤嵊掉下了九尾結令於 %s\n",
              winner->name(1),winner->query("id"),ctime(time())));
      }
    }else{
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {      
        new("/open/sky/obj7/fox-order")->move(environment(winner));
        message_vision(HIM + "\n從獨孤嵊的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj7/fox_order",sprintf("%s(%s) 讓獨孤嵊掉下了九尾結令於 %s\n",
              winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  /*
     if( winner->query("clan/id") && userp(winner) )
     CLAN_D->add_clanset( winner->query("clan/id"), "develop" ,  20 );
     */         
  tell_room(environment(),sprintf("%s從獨孤嵊身上切下一顆人頭。\n",winner->name()));
  tell_object(users(),HIW + "\n\n獨孤嵊奄奄一息道：\n\n\t可恨！可恨呀！沒想到我一代武聖！\n\n\t竟敗於"+winner->name()+"這無名小輩！可恨啊！\n\n" + NOR);
  :: die();
}

int accept_fight(object who)
{
  command("say 走開別煩我！\n");
  return 0;
}

int accept_kill(object who)
{
  who=this_player();
  command("wear all");
  command("kill "+who->query("id"));
  command("cmd god_kee");
  return 1;
}
