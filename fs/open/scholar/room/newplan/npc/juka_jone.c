//by sueplan 諸葛邑昭 最難打
//修改juka_jone.c 於 90 8/28 by sueplan
//將攻擊方式為add(kee) 調整為receive_damage() by blazakira 2011/9/28

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

int done=0;

void create() {
  set_name("諸葛邑昭",({"juka jone","juka","jone"}));
  set("class","scholar");
  set("nickname","$HIW$集天下計謀之大成$NOR$");
  set("title","智滿乾坤");
  set("long",
    "\n諸葛邑昭是諸葛孔明的孫子，諸葛孔明的所有技法他
都會，他可以算是諸葛一族中最為有聰明的一個人
然而他卻迷失了自己，利用計謀開起戰事，殘害生靈
成為諸葛一族中最敗名聲之人。\n");
  set("str",40);
  set("cor",40);
  set("cps",40);
  set("gender","男性");
  set("attitude","heroism");
  set("family/family_name","儒門");
  set("quest/gold-fire","1");
  set("max_gin",20000);
  set("max_kee",25000);
  set("max_sen",20000);
  set("max_force",20000);
  set("force",20000);
  set("age",93);
  set("force_factor",25);
  set("combat_exp",8000000);
  set("score",9000000);
  set_skill("stabber",130);
  set_skill("dodge",150);
  set_skill("move",120);
  set_skill("parry",120);
  set_skill("knowpen",120);
  set_skill("god-plan",100);
  set_skill("plan",120);
  set_skill("force",200);
  set_skill("fireforce",200);
  set_skill("winter-steps",100);
  map_skill("plan","god-plan");
  map_skill("dodge","winter-steps");
  map_skill("move","winter-steps");
  map_skill("stabber","knowpen");
  map_skill("parry","knowpen");
  map_skill("force","fireforce");
  set_temp("apply/armor",100);
  set_temp("apply/defense",100);
  set_temp("apply/damage",100);
  set_temp("apply/attack",100);

  set("functions/movedown/level",100);
  set("functions/finger/level",100);
  set("functions/gold-fire/level",90);
  set("chat_chance_combat", 100);
  set("chat_msg_combat",({
    (: perform_action("stabber.movedown") :),
    (: perform_action("stabber.finger") :),
  }));
  set("chat_chance",50);
  set("chat_msg",({
  }));
  setup();
  carry_object(START_OBJ"ten_pen")->wield();
  carry_object(START_OBJ"k_cloth")->wear();
  carry_object(PING_OBJ"neck0")->wear();
  carry_object("/open/scholar/room/newplan/obj/s-shield")->wear();
  add_money("diamond",10);
}

void init()
{
  add_action("do_action","",1);
  set_heart_beat(1);
}

int do_action(string str)
{
  object who=this_player();
  if(str)
  {
    if(strsrch(str,"plan.speed")!=-1)
    {
      command("say 愚蠢呀!!難到你不知道奇襲之計是我所創的嗎?!\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.hole")!=-1)
    {
      command("say 敢在我面前挖陷阱??少賣弄這種小聰明了!!\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.wait")!=-1)
    {
      command("say 想用伏兵玩我?!你以為我會笨到這種地步嗎??\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.rob")!=-1)
    {
      command("say 趁火打劫?!愚蠢!!難道你不知道此計為我所創嗎??\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.false")!=-1)
    {
      command("say 虛兵之計是最基本的計謀，我會有不懂之理??\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.mount")!=-1)
    {
      command("say 想趕我走??你想得太美了吧!\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"lock-link")!=-1)
    {
      command("say 鐵鎖連環我研究的方法可比你多著呢!!敢對我用?\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.ghost")!=-1)
    {
      command("say 欺敵??我可不會笨到這種地步喔!!\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
    if(strsrch(str,"plan.getweapon")!=-1)
    {
      command("say 六韜奇略??你真是笨的可以呀!!\n");
      write("\n你見諸葛邑昭神態自若，就破解了眼前的計謀!!!\n");
      kill_ob(who);
      command("perform stabber.finger");
      who->start_busy(5);
      return 1;
    }
  }
  return 0;
}

int accept_kill(object who,object me)
{
  who=this_player();
  me=this_object();
  command("wield pen");
  command("say 就讓你看看什麼是天下第一軍師的計謀吧!!受死!!");
  command("kill "+who->query("id"));
  command("perform stabber.movedown");
  return 1;
}

int accept_fight(object who)
{
  who=this_player();
  command("say 如果不敢和我較量，那就別來這邊送死!!");
  return 0;
}

void heart_beat()
{
  mixed all;
  object me,room,*target,victim,obj;
  int i,k,a,b;
  me=this_object();
  room=environment(me);
  if(!me || !room) return;
  a=random(100);
  all = all_inventory(room);
  target=me->query_enemy(room);
  if(i=sizeof(target))
  {
    if(a <= 10) {
      victim=target[random(i)];
      if(environment(me)==environment(victim)) {
        for(k=0;k<5;k++)
        {
          message_vision(HIR"諸葛邑昭取出諸葛孔明所創之連弩，向$N絕發而出!!\n"NOR,victim);
//          victim->add("kee",-800);
          victim->receive_damage("kee",800,me);
          COMBAT_D->report_status(victim);
        }
      }
    }
    if(a<=50&&a>=30) {
      message_vision(HIB"

諸葛邑昭取出自祖父所傳的道具 - 衝木流馬!!

邪惡的狂吼：看我的『轉兵逆況之計』 眼前的敵人一一倒下!!

"NOR,me);
      for(b=0;b<i;b++) {
        if(userp(target[b])) continue;
        target[b]->die();
        me->add("force",-b*5);
      }
    }
    if(a<85&&a>65) {
      message_vision(HIW"\n諸葛邑昭運起諸葛一門之護身內勁，一陣白煙從頭頂上冒出。\n"NOR,me);
      me->delete_busy();
      me->add("force",300);
      me->receive_curing("kee",500);
      me->receive_heal("kee",500);
      me->receive_heal("sen",100);
      me->receive_heal("gin",100);
    }
    if(a<30&&a>=20) {
      message_vision(HIW"\n諸葛邑昭拿起道具『六甲天書』，口中念出咒文，讓你身心受到極大的傷害!!!\n"NOR,me);
      for(b=0;b<i;b++) {
        target[b]->start_busy(1);
//      target->add("kee",-500);
        target[b]->receive_damage("kee",500,me);
      }
    }
    if(a >97  && me->is_fighting())
    {
      message_vision(HIY"
           諸葛邑昭將奇書六韜置掌上，身上氣勁蘊藏著諸葛家武學
           之巔，諸葛宏邑叱喝迴盪"HIR"『運籌帷幄 戰無不勝』"HIW"不斷向四周吸引氣勁。\n"NOR,me);
      for( i = 0 ; i < sizeof(all) ; i++)
      {
        obj = all[i];
        if( obj->is_character() && !obj->is_corpse() && living(obj) && obj->query("id")!="juka jone")
        {
          message_vision(HIR"結果所有人內力全受六韜吸引，洩向四周!!\n"NOR,obj);
          obj->add("force",-((obj->query("force")/5))*4);
          COMBAT_D->report_status(obj, 1);
        }
      }
    }
  }
  :: heart_beat();
}

void die()
{
  object winner = query_temp("last_damage_from");
  object item;
  item=new("/open/scholar/room/newplan/obj/qbook.c");
  item->move(winner);
  tell_room(environment(),sprintf("%s從諸葛邑昭身上搜到一本六韜奇略。\n",winner->name()));
  tell_object(users(),"
諸葛邑昭說道 : 
        想諸葛亮出師未捷身先死  常使英雄淚\～滿～襟～\n
                    "+winner->query("name")+"呀！！\n
           難道我天下第一軍師的計謀不及你嗎！？\n\n");
  winner->set_temp("ko_jone",1);
  :: die();
}
