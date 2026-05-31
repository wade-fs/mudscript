#include <ansi.h>
#include "/u/c/cage/lib/cage.h"

inherit NPC;
/*

inherit F_CLEAN_UP;
*/

string usr="";
int time=5000,reboot=0,nosave=0;

void create()
{
  set_name("慎村香",({"lady kawali","lady","kawali"}));
  set("long","她是阿獠的搭擋，與阿獠並稱『城市獵人』。雖然沒有精準的槍法，但是一手\n"+
  "精湛的槌法卻是連阿獠都躲不過。可別看她兩手空空喔，她有個超級絕活就是\n"+
  "隨時可以變出一把大槌子把人打到千里之外！\n");
  set("gender","女性");
  set("nickname","城市獵人");
  set("combat_exp",400000);
  set("attitude","heroism");
  set("age",22);
  set("str",26);
  set("cor",15);
  set("cps",28);
  set("per",23);
  set("int",35);
  set("kar",40);
  set("spi",14);
  set("con",24);
  set("force",450000);
  set("max_force",450000);
  set("force_factor",10);
  set("max_kee",80000);
  set_skill("array",100);
  set_skill("hammer",120);
  set_skill("parry",100);
  set_skill("cure",100);
  set_skill("literate",100);
  set_skill("dodge",80);
  set_skill("force",70);
  set_skill("move",100);
  set_skill("unarmed",100);
  setup();
  set_temp("channels",({"chat*","shout","sys","wiz"}));
  carry_object(_OBJ"hammer.c")->wield();
  carry_object(_OBJ"bullet.c");
/*
  command("wear amulet");
*/
}

void init()
{
  add_action("do_reboot", "reboot");
  add_action("do_report", "report");
}

int do_report()
{
 if (!(this_player()->query("id")=="cage")) return 0;
 command("say 內部變數:usr:"+usr+" ,time:"+time+" reboot:"+reboot+" nosave:"+nosave+"\n");
 return 1;
}

private void do_shutdown()
{
  object        *ob, link;
  int           i;
  message("system",
          "\n\n中央驛站傳來慎村香的聲音喊道﹕\n\n"+
          "\t\t可惡的阿獠！你給我記住 ～～～～ ﹗\n\n"+
          HIW+"聲音一畢﹐阿香高舉巨槌"+HIR+"**天誅**"+HIW+"打向地面，大地開始崩裂...\n\n"+
          NOR+BLU+"\t當你正因眼前的山崩地裂驚愕不己時，你腳下的地面突然裂開\n\n"+NOR+
          "\t\t你踩了個空，整個人一下子跌入無盡的深淵......\n"+
          "\t\t最後你的眼前一片黑暗....無止盡的黑暗..再難尋一絲光芒...\n\n",
          ob = users() );
  for (i=0; (i<sizeof(ob) && !(nosave)); i++) 
  {
    ob[i]->save();
    if( objectp(link=ob[i]->query_temp("link_ob")) ) link->save();
  }
  shutdown(0);
}

private void start_shutdown()
{
  do_command("chat* angry");
  command("shout 阿獠你這個混蛋昨天又沒回來，跑哪去了！");
  message("system",
          "\n你聽到從中央驛站傳來一陣咆哮 ....\n\n"
          "阿香用震耳欲聾的聲音喊道﹕\n\n"
          "\t\t全 天 下 的 眾 生 給 我 仔 細 聽 著 ﹗\n\n"
          "\t\t限你們"+HIY+chinese_number(time)+NOR
          "分鐘內把阿獠給我找回來 ﹗\n\n"
          "\t\t不 然 的 話 ....就等著吃我的槌子吧 ﹗\n\n" NOR,users() );
  call_out("countdown", 60);
}

int do_reboot()
{
  int i;
  string wiz_status,nos="";

    reboot=1;
    i = 5;
    command("say 好吧！開始倒數計時reboot了。");
    command("go ent");
    command("go down");
    command("go down");
    set("startroom",REBOOT_PLACE);
    time = i;
    start_shutdown();
    return 1;                              
//}
}

                                        
private void countdown()
{
  time--;
  if (time > 3000) return ;
  if (time > 15) call_out("countdown", 60);
  else
  { 
    if( time ) 
    {
      message("system",
              "\n中央驛站傳來阿香的聲音喊道﹕\n\n"
              "\t\t"+HIY +chinese_number(time)+NOR "分鐘內把阿獠給我找出來﹗\n\n"
              "\t\t你  們  再  混  就  給  我  試  試  看  ﹗\n\n" NOR,users() );
      call_out("countdown", 60);
    } 
    else 
    {
      message("system",
              "\n中央驛站傳來阿香的聲音喊道﹕\n\n"
              HIB"\t\t可惡啊，你們給我混！\n\n"
              "\t\t你們要倒大楣了！\n\n" NOR,users() );
       call_out("do_shutdown", 3);
    }
  }
}
                                                                            
int accept_fight(object ob)
{
  if ((int)ob->query("max_kee") < 250)
    return notify_fail("阿香對你說道：你還太弱還是不要跟我比武比較好！\n");
  return 1;
}
int accept_kill(object ob)
{
  if ((int)ob->query("max_kee") < 350)
  {
    tell_object(ob,"阿香對你說道：你連我一槌都擋不了還想殺我？\n");
    return 0;
  }
  return 1;
}

void heart_beat()
{
 object obj,target,*list;
 int ppl,i,j;
 :: heart_beat();
 if(!is_fighting()) return;
 if(5 < random(15)) return;
 obj=select_opponent();
 list = users();
 ppl = sizeof(list);
 j=5;
 do
 {
   j--;
   i = random(ppl);
   target = list[i];
 }
 while((obj == target || wizardp(target)) && j);
 i = obj->query("max_kee") * 0.5;
 if (i < 100) i = 100;
 if (!j)
 {
   message_vision("阿香使出慎村流巨槌奧義==破殺留聲==$N被打到九天之外！\n",obj);
   message_vision("$N被打到半空中又掉了下來，受了極大的傷害\n",obj);
   obj->receive_wound("kee",i,this_object());
   return;
 }
 obj->remove_all_enemy();
 obj->receive_wound("kee",i,this_object());
 message_vision("阿香使出慎村流巨槌奧義==破殺留聲==$N被打到九天之外！\n",obj);
 tell_room(environment(target),"咦？天上那是什麼東西？\n"+
             "哇！~~碰的一聲!"+(string)obj->query("name")+"從天上掉下來。\n");
 obj->move(environment(target));
 tell_room(environment(target),obj->query("name")+"重重地摔在"+
                            target->query("name")+"身上！\n",({ obj,target}));
 tell_object(obj,"你重重地壓在"+target->query("name")+"身上！\n哇~~痛死了！\n");
 tell_object(target,obj->query("name")+"正好摔在你身上！\n喔~~~好痛，真倒楣！\n");
}

                                                

void die()
{
 object ob;
 if (!reboot) 
 {
   :: die();
   return;
 }
 else
 {
   if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
   if( !ob ) return;
   message("system",ob->name(1)+"給阿香致命的一擊！"+
           HIG+"\n\n嗚~~~對不起各位，我錯了。\n\n"+
           HIW+"阿香沮喪地回去了，你鬆了一口氣！\n\n"+NOR,users() );
   this_object()->remove_all_enemy();
   this_object()->move(_HOME);
   set("startroom",_HOME);
   reboot=0;
   time=5000;
 }
}

int return_home(object home)
{
 if (!reboot) :: return_home(home);
 return 1;
}
