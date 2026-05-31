/*
和evil-dragon同步調降過高的temp增加值 by frequency
*/
#include <ansi.h>
#include <mudlib.h>
inherit NPC;
inherit SSERVER;
mapping *action = ({
  ([ "action" : "$N搖晃著尾巴，突然對著$n狂衝而去，屁股對著$n，往$n臉上踢了過去\n",
                "dodge"      :   -40,
                "parry"      :   -35,
                "damage"     :    70,
                "damage_type":   "踢傷",
  ]),
  ([ "action" : "$N突然從背後拿出許\多道具，瘋狂往$n上丟去，砸得$n滿頭包\n",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    180,
                "force"      :    180,
                "damage_type":   "凍傷",
  ]),
  });

void create()
{
  set_name(HIY"純情小綿羊"NOR,({"sheep"}));  
  set("title", HIY"『"HIW"網聚附屬品"HIY"』"NOR);
  set("long", "可愛的小綿羊,請好好愛惜牠,使用方法如下：
              ride       ： 騎牠
              dismount　 ： 下牠
              free_sheep ： 叫牠滾！
              att        ： 衝鋒術
              feed       ： 使用方法 <feed head>    
           \n");
  set("str",50);
  set("cor",50);
  set("cps",50);
  set("horse",1);
  set("force",10000);
  set("max_force",10000);
  set("max_gin",10000);
  set("max_kee",10000);
  set("max_sen",10000);   
  set("age", 30);
  set("race","野獸");
  set("gender", "雄性");
  set("attitude", "peaceful");
  set("score",10000000);
  set("gold", 100);
  set("limbs",({"羊頭","羊腳","羊腿","羊背","羊腹"}));
  set("verbs",({"bite","claw"}));
  set_temp("apply/armor",100);
  set_temp("apply/defense",100);
  set_temp("apply/damage",100);
  set_temp("apply/attack",100);
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  reset_action();
  setup();
}

void init()
{
  add_action("do_ride","ride");
  add_action("do_dismount","dismount");
  add_action("do_freesheep", "free_sheep");
  add_action("do_full","addforce");
  add_action("do_charge", "att");
  add_action("do_feed", "feed");
}

mapping query_action()
{
  return action[random(sizeof(action))];
}

void horsekee()  //kee 30000 exp 10000000
{
  object me,horse;
  int i,funlv;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  funlv = me->query("functions/feed_horse/level");
  horse->set("functions/feed_horse/level",funlv);
  if (!(horse->query_temp("horsekee")) && (environment(me) == environment(horse)))
  {
   horse->set("eff_kee",funlv*200 + 10000);
   horse->set("kee",funlv*200 + 10000);
   horse->set("eff_gin",funlv*200 + 10000);
   horse->set("gin",funlv*200 + 10000);
   horse->set("eff_sen",funlv*200 + 10000);
   horse->set("sen",funlv*200 + 10000);
   set("combat_exp", 2000000+funlv*80000); 
   set_skill("parry",  50+funlv);
   set_skill("move",   50+funlv);
   set_skill("dodge",  50+funlv);
   set_skill("move",   50+funlv);
   set_skill("unarmed",50+funlv);
   set_temp("apply/armor",  30+funlv/2);
   set_temp("apply/defense",30+funlv/2);
   set_temp("apply/damage", 30+funlv/2);
   set_temp("apply/attack", 30+funlv/2);
   horse->set_temp("horsekee",1);
   tell_object(me,HIR"你的羊兒目前等級為"HIW""+funlv+""HIR"！！\n"NOR);
   write("測試完畢\n");
  }
  if ((int)horse->query("functions/feed_horse/level") <60 &&
      (int)horse->query("functions/feed_horse/level") >30)
  { horse->set("title",HIY"『"HIW"可愛娃娃工"HIY"』"NOR); }
  else if ((int)horse->query("functions/feed_horse/level") >59 &&
           (int)horse->query("functions/feed_horse/level") < 100)
  { horse->set("title",HIY"『"HIW"略胖娃娃工"HIY"』"NOR); }
  else if ((int)horse->query("functions/feed_horse/level")==100)
  horse->set("title",HIY"『"HIR"酷斯拉娃娃工"HIY"』"NOR);
}
  
int do_feed(string arg)
{
  object me,horse,ob;
  int funlv;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  ob = present("head",me);
  funlv = me->query("functions/feed_horse/level");
  if (arg == "head")
  {
   if ( me != this_player())
     return notify_fail("你不是牠的主人，亂叫什麼？\n");
   if ( !ob)
     return notify_fail("你身上沒有人頭可餵羊兒\n");
   if ( horse->query_temp("havefeed"))
     return notify_fail("羊兒還沒消化完畢，你想撐死牠呀？\n");

   if ( !ob->query("feed"))
     return notify_fail("這不是羊兒喜歡吃的頭！！\n");
   if ( me->is_fighting())
     return notify_fail("你在戰鬥中，塞不準了．．\n");
   if (funlv == 100)
     return notify_fail("羊兒已經肥滋滋了，不用再餵了!!\n");
   
   message_vision("$N拿了人頭餵食羊兒，$n咕嚕咕嚕地一下子就吃完了\n",me,horse);
   tell_object(me,horse->query("name")+"感覺更加強大了\n");
  horse->set_temp("havefeed",1);
  call_out("delfeed",180);
   destruct(ob);
   if(funlv<100) { function_improved("feed_horse",150+random(funlv/2)); }
  }
  else
  {
   tell_object(me,"不要拿了東西就想往羊兒嘴裡塞\n");
  }
  return 1;
}

void delfeed()
{
  object horse,me;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  message_vision("$N摩蹭著主人，似乎在告訴$n牠已經肚子餓了。\n",horse,me);
  horse->delete_temp("havefeed");
}

int do_charge() //最高傷害1000
{
  object me,horse,*enemy;
  int i,j,funlv;
  me = find_living((string)this_object()->query_temp("my_boss"));
  horse = this_object();
  enemy = me->query_enemy();
  i = random(sizeof(enemy));
  funlv = horse->query("functions/feed_horse/level");
  if (me != this_player())
    return notify_fail("你不是牠的主人，亂叫什麼？\n");
  if (!me->is_fighting())
    return notify_fail("衝鋒術只能在戰鬥中使用！\n");
  if (horse->query("kee") < 500)
    return notify_fail("羊兒已經軟趴趴了！！請餵牠雞精吧！！\n");
  if (horse->query_temp("haveatt"))
    return notify_fail("羊兒正在衝了啦，你是要叫牠衝去哪？\n");
  if (me ->is_fighting() && environment(horse) == environment(me))
  {
   message_vision("$N狠狠往$n的耳朵咬了一下，$n痛的往前衝！\n",me,horse);
   message_vision("$N發狂似地往敵人衝去，強大的衝力，把$n衝倒在地！\n",horse,enemy[i]);
   enemy[i]->receive_damage("kee",funlv*10);
   horse->add("kee",-50);
   horse->set_temp("haveatt",1);
   call_out("delatt",10);  //覺得變成了癈物!!
   COMBAT_D->report_status(enemy[i]);
  }
  return 1;
}

void delatt()
{
  object horse,me;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  horse->delete_temp("haveatt");
  tell_object(me,"你的羊兒已經蓄勢待發，準備下一次的衝鋒\n");
}

int do_ride(string str)
{
  object me,horse;
  int fun;
  me = this_player();
  horse = this_object();
  fun = horse->query("functions/feed_horse/level");
  if((str != "horse") && (str != horse->query("id")))
    return notify_fail("你想騎什麼？\n");
  if(horse->query("horse")!=1)
    return notify_fail("這不是羊兒不能騎唷！\n"); 
  if(me->query_temp("marks/ascend"))
    return notify_fail("有騎羊了還想騎，想被 K 呀。\n");
  if(me->query("id")!="jackylove")
    return notify_fail("這不是你的座騎，不要隨便亂騎喔!!\n");
  if(me->query_temp("is_riding"))
    return notify_fail("你已經騎在羊上了。\n");
  message_vision("$N帶著臃腫的身體，緩慢地爬上了"+horse->query("name")+"的背上，"+horse->query("name")+"慘叫了一聲，似乎覺得$N太重了！\n",me);
  command ("defend jackylove");
  me->set_temp("is_riding", 1);
        me->add_temp("apply/attack", 5+fun/10);
        me->add_temp("apply/parry",  5+fun/10);
        me->add_temp("apply/defense",5+fun/10);
        me->add_temp("apply/damage", 5+fun/10);
        me->add_temp("apply/armor",  5+fun/10);
        me->add_temp("apply/dodge",  5+fun/10);
        me->add_temp("apply/move",   5+fun/10);
  me->set_temp("ride_name",me->name()+"正騎著"+horse->name());
  set_heart_beat(1);
  return 1;
}

int do_dismount()
{
  object me,horse;
  int fun;
  me = this_player();
  horse = this_object();
  fun = horse->query("functions/feed_horse/level");
  if(!me->query_temp("is_riding"))
    return notify_fail("你現在並沒有騎羊！\n");
  if(me->query("id")!="jackylove")
    return notify_fail("這匹羊不是你的座騎！\n");
  me->delete_temp("is_riding");
        me->add_temp("apply/attack", -(5+fun/10));
        me->add_temp("apply/parry",  -(5+fun/10));
        me->add_temp("apply/damage", -(5+fun/10));
        me->add_temp("apply/armor",  -(5+fun/10));
        me->add_temp("apply/defense",-(5+fun/10));
        me->add_temp("apply/dodge",  -(5+fun/10));
        me->add_temp("apply/move",   -(5+fun/10));
  me->delete_temp("ride_name");
  message_vision(HIW"$N一個不小心，從羊身上摔了下來！\n"NOR,me);
  me->delete_temp("ride_name");
  set_heart_beat(0);
  return 1;
}

int do_freesheep()
{
  object me,horse;
  int fun;
  me = find_living((string)this_object()->query_temp("my_boss"));
  horse = this_object();
  fun = horse->query("functions/feed_horse/level");
  if (me != this_player())
    return notify_fail("你不是牠的主人，亂叫什麼？\n"); 
   if ( horse->query_temp("havefeed"))
     return notify_fail("羊兒還在消化食物，不要害牠胃下垂了。\n");

  if (me->is_fighting() )
    return notify_fail("等你沒有性命之憂再來吧\n");
  message_vision(HIM"$N用力地往$n屁股上踼了一腳，$n痛的 "HIY"該該叫"HIM" ，往主人臉上吐了一口啖跑掉了\n"NOR,me,this_object());
  if(me->query_temp("is_riding"))
  {
          me->add_temp("apply/attack", -(5+fun/10));
          me->add_temp("apply/parry",  -(5+fun/10));
          me->add_temp("apply/damage", -(5+fun/10));
          me->add_temp("apply/armor",  -(5+fun/10));
          me->add_temp("apply/defense",-(5+fun/10));
          me->add_temp("apply/dodge",  -(5+fun/10));
          me->add_temp("apply/move",   -(5+fun/10));
  }
  me->delete_temp("ride_name");
  me->delete_temp("horse");
  me->delete_temp("is_riding");
  me->delete_temp("have_horse");
  destruct(this_object());
  return 1;
}

void die()
{
  object me,horse;
  int fun;
  me = find_living((string)this_object()->query_temp("my_boss"));
  horse = this_object();
  fun = horse->query("functions/feed_horse/level");
  if(me->query_temp("is_riding"))
  {
          me->add_temp("apply/attack", -(5+fun/10));
          me->add_temp("apply/parry",  -(5+fun/10));
          me->add_temp("apply/damage", -(5+fun/10));
          me->add_temp("apply/armor",  -(5+fun/10));
          me->add_temp("apply/defense",-(5+fun/10));
          me->add_temp("apply/dodge",  -(5+fun/10));
          me->add_temp("apply/move",   -(5+fun/10));
  }
  me->delete_temp("ride_name");
  me->delete_temp("horse");
  me->delete_temp("is_riding");
  me->delete_temp("have_horse");
  destruct(this_object());
  ::die();
}

int accept_fight(object me)
{
  return notify_fail("想殺牠？先問問Pana!!\n");
}

int accept_kill(object me)
{
  return notify_fail("想殺牠？先問問Pana!!\n");
}

void heart_beat()
{
  object horse,me,*enemy;
  int i,j,k;
  horse = this_object();
if(!(string)horse->query_temp("my_boss")) return ;
  me = find_living((string)horse->query_temp("my_boss"));
  enemy = horse->query_enemy();
  i = sizeof(enemy);
  j = random(i);
  if ( horse->query("kee") < 500 && random(3)==1)
  {
   message_vision("$N"HIY"突然化身為釋迦頭，口中唸唸有辭．．\n"NOR,horse);
   command ("buddha2");
   message_vision(HIC"一道昊光灑了下來，將$N"HIC"身上的傷治好了大半！\n"NOR,horse);
   command ("fear " + enemy[j]->query("id"));
   horse->receive_heal("kee",1000);
   COMBAT_D->report_status(horse);
  }
  if (horse->is_fighting() && me->is_busy() && random(10)>7)
  {
   message_vision(horse->query("name")+"見主人陷入苦戰，奮不顧身地往全場敵人．．．\n
                   \t"HIW"吐　"HIY"～　"HIW"口　"HIY"～　"HIW"水"NOR" \n
　                 \t"HIR"．．"HIC"呸"HIR"．．"HIC"呸"HIR"．．"HIC"呸．．\n"NOR,me);
   for (k=0;k<i;k++)
   {
    if (random(10)>7) //出現率為70%
    {
     if (random(5)>2)
     {
      message_vision(enemy[k]->query("name")+"被"+horse->query("name")+"的口水噴中，臉上已經留下一塊可怕的浮水印了。\n",me);
      enemy[k]->receive_wound("kee",200);
      COMBAT_D->report_status(enemy[k]);
     }
     else
     {
      message_vision(enemy[k]->query("name")+"指著"+horse->query("name")+"的鼻子大笑，你這沒用的傢伙！\n",me);
     }
    }
    else  //出現率為30%
    {
     if (random(5)>2)
     {
      message_vision(enemy[k]->query("name")+"雖躲過了攻擊，但仍被"+horse->query("name")+"噁心的口水噴得滿臉都是，連忙擦去！\n",me);
      enemy[k]->start_busy(1);
     }
     else 
     {
      message_vision(enemy[k]->query("name")+"指著"+horse->query("name")+"的鼻子大笑，你這沒用的傢伙！\n",me);
     }     
    }
   }
  }

  set_heart_beat(1);
  :: heart_beat();
}

int do_full() {
        object me;
        me = this_player();
        if(!me->query_temp("is_riding"))
           return notify_fail("你現在並沒有騎著羊！！\n");
        if(me->query("max_force") == 0)
          return notify_fail("您並沒有內力, 羊兒也無法為你效力！\n");
        if(me->query("force") >= me->query("max_force"))
          return notify_fail("您的內力以到極限, 羊兒是無法幫您再增加的！\n");
        me->add("force", me->query("max_force")/4);
          return notify_fail("您的內力漸漸提昇當中！\n");
}
